#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/bit2/0603_project/tang_ws/src/planning/dependent_package/unique_id"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/bit2/0603_project/tang_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/bit2/0603_project/tang_ws/install/lib/python2.7/dist-packages:/home/bit2/0603_project/tang_ws/build/unique_id/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/bit2/0603_project/tang_ws/build/unique_id" \
    "/usr/bin/python2" \
    "/home/bit2/0603_project/tang_ws/src/planning/dependent_package/unique_id/setup.py" \
    build --build-base "/home/bit2/0603_project/tang_ws/build/unique_id" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/bit2/0603_project/tang_ws/install" --install-scripts="/home/bit2/0603_project/tang_ws/install/bin"
