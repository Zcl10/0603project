#!/usr/bin/env python
from math import *
import matplotlib.pyplot as plt
import pandas as pd
import sys
from PyQt4.QtGui  import *
from PyQt4.QtCore import *

class SimplePyQtGUIKit:
    def QuitApp(self):
        QApplication.quit()

    @classmethod
    def GetFilePath(self,caption="Open File",filefilter="",isApp=False):
        u"""
            "Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)"
        """

        if not isApp:
          app = QApplication(sys.argv)
        files=QFileDialog.getOpenFileNames(caption=caption,filter=filefilter)

        strlist=[]
        for file in files:
            strlist.append(str(file))

        return strlist


    @classmethod
    def GetCheckButtonSelect(self, selectList, title="Select", msg="",app=None):
        """
        Get selected check button options

        title: Window name
        mag: Label of the check button
        return selected dictionary
            {'sample b': False, 'sample c': False, 'sample a': False}
        """

        if app is None:
          app = QApplication(sys.argv)
        win = QWidget()
        scrollArea = QScrollArea()
        scrollArea.setWidgetResizable(True)
        scrollAreaWidgetContents = QWidget(scrollArea)
        scrollAreaWidgetContents.setGeometry(QRect(0, 0, 380, 247))
        scrollArea.setWidget(scrollAreaWidgetContents)
        layout=QGridLayout()
        verticalLayoutScroll = QVBoxLayout(scrollAreaWidgetContents)
        layoutIndex=0

        if msg is not "":
            label = QLabel(msg)
            layout.addWidget(label,layoutIndex,0)
            layoutIndex=layoutIndex+1

        checkboxs=[]
        for select in selectList:
            checkbox=QCheckBox(select)
            verticalLayoutScroll.addWidget(checkbox)
            layoutIndex=layoutIndex+1
            checkboxs.append(checkbox)

        layout.addWidget(scrollArea)
        btn=QPushButton("OK")
        btn.clicked.connect(app.quit)
        layout.addWidget(btn,layoutIndex,0)
        layoutIndex=layoutIndex+1


        win.setLayout(layout)
        win.setWindowTitle(title)
        win.show()
        app.exec_()

        result={}
        for (checkbox, select) in zip(checkboxs, selectList):
            result[select]=checkbox.isChecked()

        return result

e0 = 0
n0 = 0

def positionGPStoMeters(longitude, latitude):
    WGS84_ECCENTRICITY = 0.0818192
    WGS84_EQUATORIAL_RADIUS = 6378.137
    k0 = 0.9996

    Zone = (int) (longitude / 6) + 1
    lonBase = Zone * 6 - 3

    vPhi = (float) (1 / sqrt(1 - pow(WGS84_ECCENTRICITY * sin(latitude * pi / 180.0), 2)))
    A = (float) ((longitude - lonBase) * pi / 180.0 * cos(latitude * pi / 180.0))
    sPhi = (float) ((1 - pow(WGS84_ECCENTRICITY, 2) / 4.0 - 3 * pow(WGS84_ECCENTRICITY, 4) / 64.0
        - 5 * pow(WGS84_ECCENTRICITY, 6) / 256.0) * latitude * pi / 180.0
        - (3 * pow(WGS84_ECCENTRICITY, 2) / 8.0 + 3 * pow(WGS84_ECCENTRICITY, 4) / 32.0
            + 45 * pow(WGS84_ECCENTRICITY, 6) / 1024.0) * sin(2 * latitude * pi / 180.0)
        + (15 * pow(WGS84_ECCENTRICITY, 4) / 256.0 + 45 * pow(WGS84_ECCENTRICITY, 6) / 256.0)
            * sin(4 * latitude * pi / 180.0)
        - (35 * pow(WGS84_ECCENTRICITY, 6) / 3072.0) * sin(6 * latitude * pi / 180.0))
    T = (float) (pow(tan(latitude * pi / 180.0), 2))
    C = (float) ((pow(WGS84_ECCENTRICITY, 2) / (1 - pow(WGS84_ECCENTRICITY, 2)))
        * pow(cos(latitude * pi / 180.0), 2))

    pose_x = (float) ((k0 * WGS84_EQUATORIAL_RADIUS * vPhi * (A + (1 - T + C) * pow(A, 3) / 6.0
        + (5 - 18 * T + pow(T, 2)) * pow(A, 5) / 120.0)) * 1000)
    pose_y = (float) ((k0 * WGS84_EQUATORIAL_RADIUS * (sPhi + vPhi * tan(latitude * pi / 180.0) * (pow(A, 2) / 2
            + (5 - T + 9 * C + 4 * C * C) * pow(A, 4) / 24.0 + (61 - 58 * T + T * T) * pow(A, 6) / 720.0))) * 1000)
    global e0, n0
    if (0 == e0 and 0 == n0):
        e0 = int(pose_x)
        n0 = int(pose_y)

    pose_x -= e0
    pose_y -= n0

    return pose_x, pose_y

if __name__ == '__main__':
    app = QApplication(sys.argv)
    #GetFilePath
    py_qt = SimplePyQtGUIKit()
    files=py_qt.GetFilePath(isApp=True,caption="Select csv file",filefilter="*csv")
    if len(files)<1:
        print("Error:Please select a csv file")
        sys.exit()

    plot_type = ['line', 'scatter']
    selected=SimplePyQtGUIKit.GetCheckButtonSelect(plot_type,app=app,msg="Select plot type")
    type_names=[]
    for k,v in selected.items():
        if v:
            type_names.append(k)
    if len(type_names)==0:
        print("Error:Please select type")
        sys.exit()

    for j in range(len(files)):
        gps = pd.read_csv(files[j])
        x1 = gps["longitude"]
        y1 = gps["latitude"]
        x3 = []
        y3 = []
        for i in range(len(x1)):
    	    a, b = positionGPStoMeters(x1[i], y1[i])
    	    x3.append(a)
    	    y3.append(b)
        label = files[j][files[j].rfind('/')+1:files[j].rfind('.')]
        for type in type_names:
            if type=='line':
                plt.plot(x3, y3, label=label)
            elif type=='scatter':
                plt.scatter(x3, y3, s=3, alpha=0.5, label=label)

    plt.legend()
    plt.xlabel('East / meter')
    plt.ylabel('North / meter')
    plt.axis('equal')
    plt.show()
