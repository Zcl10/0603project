/* Copyright (c) 2016, Yu Zhang, Beijing Institute of Technology
 * All rights reserved.
 *        Files: SE2ConstraintsConstraints.cpp
 *   Created on: Aug, 02, 2016
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */
#include "opt_solver/se2_constraints.hpp"
#include <cmath>

/**
 * These functions can calculate function values, gradient and hessian of final
 * state
 * in terms of knot parameters.
 */

/*!
 * X position of final state
 * @param param [in] knot parameters
 * @return  double x value
 */

namespace hmpl {

double SE2Constraints::fxf(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    double t1;
    double t2;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    t1 = 2;
    t2 = 4;
    f = p4 *
        (t2 * (cos((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                    0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                   p4) +
               cos((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                    0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                   p4) +
               cos((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                    0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                   p4) +
               cos((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                    0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                   p4)) +
         t1 * (cos((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                    0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                   p4) +
               cos((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 + p3 / 128 -
                    0.3e1 / 0.128e3 * p2) *
                   p4) +
               cos((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                    0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                   p4)) +
         1 + cos(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2))) /
        24;
    return (f);
}

/*!
 * y position of final state of the vehicle.
 * @param param [in] knot parameter
 * @return double y value.
 */
double SE2Constraints::fyf(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    double t1;
    double t2;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    t1 = 2;
    t2 = 4;
    f = p4 *
        (t1 * (sin((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 + p3 / 128 -
                    0.3e1 / 0.128e3 * p2) *
                   p4) +
               sin((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                    0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                   p4) +
               sin((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                    0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                   p4)) +
         t2 * (sin((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                    0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                   p4) +
               sin((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                    0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                   p4) +
               sin((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                    0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                   p4) +
               sin((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                    0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                   p4)) +
         sin(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2))) /
        24;
    return (f);
}

/*!
 * Heading of final state
 * @param param [in] knot parameter
 * @return double heading of the car.
 */
double SE2Constraints::ftf(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2);
    return (f);
}

double SE2Constraints::dxdp1(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = p4 * p4 *
        (-0.1851e4 / 0.8192e4 *
                 sin((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                      0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                     p4) -
         0.363e3 / 0.1024e4 *
                 sin((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                      0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                     p4) -
         0.9963e4 / 0.8192e4 *
                 sin((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                      0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                     p4) -
         0.51e2 / 0.64e2 * sin((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 +
                                p3 / 128 - 0.3e1 / 0.128e3 * p2) *
                               p4) -
         0.14475e5 / 0.8192e4 *
                 sin((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                      0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                     p4) -
         0.891e3 / 0.1024e4 *
                 sin((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                      0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                     p4) -
         0.13083e5 / 0.8192e4 *
                 sin((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                      0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                     p4) -
         0.3e1 / 0.8e1 *
                 sin(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2))) /
        24;
    return (f);
}

double SE2Constraints::dxdp2(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = p4 * p4 *
        (0.795e3 / 0.8192e4 *
                 sin((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                      0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                     p4) +
         0.123e3 / 0.1024e4 *
                 sin((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                      0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                     p4) +
         0.2187e4 / 0.8192e4 *
                 sin((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                      0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                     p4) +
         0.3e1 / 0.64e2 * sin((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 +
                               p3 / 128 - 0.3e1 / 0.128e3 * p2) *
                              p4) -
         0.2325e4 / 0.8192e4 *
                 sin((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                      0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                     p4) -
         0.405e3 / 0.1024e4 *
                 sin((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                      0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                     p4) -
         0.10437e5 / 0.8192e4 *
                 sin((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                      0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                     p4) -
         0.3e1 / 0.8e1 *
                 sin(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2))) /
        24;
    return (f);
}

double SE2Constraints::dxdp3(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = p4 * p4 *
        (-0.169e3 / 0.8192e4 *
                 sin((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                      0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                     p4) -
         0.25e2 / 0.1024e4 *
                 sin((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                      0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                     p4) -
         0.441e3 / 0.8192e4 *
                 sin((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                      0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                     p4) -
         sin((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 + p3 / 128 -
              0.3e1 / 0.128e3 * p2) *
             p4) /
                 64 -
         0.25e2 / 0.8192e4 *
                 sin((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                      0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                     p4) -
         0.9e1 / 0.1024e4 *
                 sin((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                      0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                     p4) -
         0.1225e4 / 0.8192e4 *
                 sin((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                      0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                     p4) -
         sin(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2)) / 8) /
        24;
    return (f);
}

double SE2Constraints::dxdp4(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    double t1;
    double t10;
    double t11;
    double t12;
    double t13;
    double t14;
    double t15;
    double t16;
    double t17;
    double t18;
    double t19;
    double t2;
    double t20;
    double t21;
    double t22;
    double t23;
    double t24;
    double t25;
    double t26;
    double t27;
    double t28;
    double t29;
    double t3;
    double t30;
    double t31;
    double t32;
    double t33;
    double t34;
    double t35;
    double t36;
    double t37;
    double t38;
    double t39;
    double t4;
    double t40;
    double t41;
    double t42;
    double t43;
    double t5;
    double t6;
    double t7;
    double t8;
    double t9;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    t1 = 0.1851e4 / 0.32768e5 * p1;
    t2 = 0.2871e4 / 0.32768e5 * p0;
    t3 = 0.169e3 / 0.32768e5 * p3;
    t4 = -0.795e3 / 0.32768e5 * p2;
    t5 = (t4 + t3 + t2 + t1) * p4;
    t6 = 0.247e3 / 0.2048e4 * p0;
    t7 = 0.363e3 / 0.2048e4 * p1;
    t8 = 0.25e2 / 0.2048e4 * p3;
    t9 = -0.123e3 / 0.2048e4 * p2;
    t10 = (t9 + t8 + t6 + t7) * p4;
    t11 = 0.9963e4 / 0.32768e5 * p1;
    t12 = 0.4071e4 / 0.32768e5 * p0;
    t13 = 0.441e3 / 0.32768e5 * p3;
    t14 = -0.2187e4 / 0.32768e5 * p2;
    t15 = (t14 + t13 + t12 + t11) * p4;
    t16 = 0.51e2 / 0.128e3 * p1;
    t17 = 0.15e2 / 0.128e3 * p0;
    t18 = p3 / 128;
    t19 = -0.3e1 / 0.128e3 * p2;
    t20 = (t19 + t17 + t18 + t16) * p4;
    t21 = 0.14475e5 / 0.32768e5 * p1;
    t22 = 0.3655e4 / 0.32768e5 * p0;
    t23 = 0.2325e4 / 0.32768e5 * p2;
    t24 = 0.25e2 / 0.32768e5 * p3;
    t25 = (t24 + t23 + t22 + t21) * p4;
    t26 = 0.891e3 / 0.2048e4 * p1;
    t27 = 0.405e3 / 0.2048e4 * p2;
    t28 = 0.231e3 / 0.2048e4 * p0;
    t29 = 0.9e1 / 0.2048e4 * p3;
    t30 = (t29 + t28 + t27 + t26) * p4;
    t31 = 0.10437e5 / 0.32768e5 * p2;
    t32 = 0.13083e5 / 0.32768e5 * p1;
    t33 = 0.3927e4 / 0.32768e5 * p0;
    t34 = 0.1225e4 / 0.32768e5 * p3;
    t35 = (t34 + t31 + t32 + t33) * p4;
    t36 = p0 + p3;
    t37 = p1 + p2;
    t38 = 0.3e1 / 0.8e1 * p4 * t37 + p4 * t36 / 8;
    t39 = -4;
    t40 = -2;
    t41 = 0.1e1 / 0.6e1;
    t42 = 0.1e1 / 0.12e2;
    t43 = 0.1e1 / 0.24e2;
    f = t43 * (p4 * (-(0.3e1 / 0.8e1 * t37 + t36 / 8) * sin(t38) +
                     t39 * ((t4 + t3 + t2 + t1) * sin(t5) +
                            (t14 + t13 + t12 + t11) * sin(t15) +
                            (t24 + t23 + t22 + t21) * sin(t25) +
                            (t34 + t31 + t32 + t33) * sin(t35)) +
                     t40 * ((t9 + t8 + t6 + t7) * sin(t10) +
                            (t19 + t17 + t18 + t16) * sin(t20) +
                            (t29 + t28 + t27 + t26) * sin(t30))) +
               cos(t38) + 1) +
        t41 * (cos(t5) + cos(t15) + cos(t25) + cos(t35)) +
        t42 * (cos(t10) + cos(t20) + cos(t30));
    return (f);
}

double SE2Constraints::dydp1(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = p4 * p4 *
        (0.1851e4 / 0.8192e4 *
                 cos((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                      0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                     p4) +
         0.363e3 / 0.1024e4 *
                 cos((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                      0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                     p4) +
         0.9963e4 / 0.8192e4 *
                 cos((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                      0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                     p4) +
         0.51e2 / 0.64e2 * cos((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 +
                                p3 / 128 - 0.3e1 / 0.128e3 * p2) *
                               p4) +
         0.14475e5 / 0.8192e4 *
                 cos((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                      0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                     p4) +
         0.891e3 / 0.1024e4 *
                 cos((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                      0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                     p4) +
         0.13083e5 / 0.8192e4 *
                 cos((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                      0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                     p4) +
         0.3e1 / 0.8e1 *
                 cos(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2))) /
        24;
    return (f);
}

double SE2Constraints::dydp2(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = p4 * p4 *
        (-0.795e3 / 0.8192e4 *
                 cos((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                      0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                     p4) -
         0.123e3 / 0.1024e4 *
                 cos((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                      0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                     p4) -
         0.2187e4 / 0.8192e4 *
                 cos((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                      0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                     p4) -
         0.3e1 / 0.64e2 * cos((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 +
                               p3 / 128 - 0.3e1 / 0.128e3 * p2) *
                              p4) +
         0.2325e4 / 0.8192e4 *
                 cos((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                      0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                     p4) +
         0.405e3 / 0.1024e4 *
                 cos((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                      0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                     p4) +
         0.10437e5 / 0.8192e4 *
                 cos((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                      0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                     p4) +
         0.3e1 / 0.8e1 *
                 cos(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2))) /
        24;
    return (f);
}

double SE2Constraints::dydp3(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = p4 * p4 *
        (0.169e3 / 0.8192e4 *
                 cos((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                      0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                     p4) +
         0.25e2 / 0.1024e4 *
                 cos((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                      0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                     p4) +
         0.441e3 / 0.8192e4 *
                 cos((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                      0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                     p4) +
         cos((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 + p3 / 128 -
              0.3e1 / 0.128e3 * p2) *
             p4) /
                 64 +
         0.25e2 / 0.8192e4 *
                 cos((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                      0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                     p4) +
         0.9e1 / 0.1024e4 *
                 cos((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                      0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                     p4) +
         0.1225e4 / 0.8192e4 *
                 cos((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                      0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                     p4) +
         cos(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2)) / 8) /
        24;
    return (f);
}

double SE2Constraints::dydp4(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    double t1;
    double t10;
    double t11;
    double t12;
    double t13;
    double t14;
    double t15;
    double t16;
    double t17;
    double t18;
    double t19;
    double t2;
    double t20;
    double t21;
    double t22;
    double t23;
    double t24;
    double t25;
    double t26;
    double t27;
    double t28;
    double t29;
    double t3;
    double t30;
    double t31;
    double t32;
    double t33;
    double t34;
    double t35;
    double t36;
    double t37;
    double t38;
    double t39;
    double t4;
    double t40;
    double t41;
    double t42;
    double t43;
    double t5;
    double t6;
    double t7;
    double t8;
    double t9;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    t1 = 0.1851e4 / 0.32768e5 * p1;
    t2 = 0.2871e4 / 0.32768e5 * p0;
    t3 = 0.169e3 / 0.32768e5 * p3;
    t4 = -0.795e3 / 0.32768e5 * p2;
    t5 = (t4 + t3 + t1 + t2) * p4;
    t6 = 0.247e3 / 0.2048e4 * p0;
    t7 = 0.363e3 / 0.2048e4 * p1;
    t8 = 0.25e2 / 0.2048e4 * p3;
    t9 = -0.123e3 / 0.2048e4 * p2;
    t10 = (t9 + t8 + t7 + t6) * p4;
    t11 = 0.9963e4 / 0.32768e5 * p1;
    t12 = 0.4071e4 / 0.32768e5 * p0;
    t13 = 0.441e3 / 0.32768e5 * p3;
    t14 = -0.2187e4 / 0.32768e5 * p2;
    t15 = (t14 + t13 + t12 + t11) * p4;
    t16 = 0.51e2 / 0.128e3 * p1;
    t17 = 0.15e2 / 0.128e3 * p0;
    t18 = p3 / 128;
    t19 = -0.3e1 / 0.128e3 * p2;
    t20 = (t19 + t18 + t17 + t16) * p4;
    t21 = 0.14475e5 / 0.32768e5 * p1;
    t22 = 0.3655e4 / 0.32768e5 * p0;
    t23 = 0.2325e4 / 0.32768e5 * p2;
    t24 = 0.25e2 / 0.32768e5 * p3;
    t25 = (t24 + t23 + t22 + t21) * p4;
    t26 = 0.891e3 / 0.2048e4 * p1;
    t27 = 0.405e3 / 0.2048e4 * p2;
    t28 = 0.231e3 / 0.2048e4 * p0;
    t29 = 0.9e1 / 0.2048e4 * p3;
    t30 = (t29 + t28 + t27 + t26) * p4;
    t31 = 0.10437e5 / 0.32768e5 * p2;
    t32 = 0.13083e5 / 0.32768e5 * p1;
    t33 = 0.3927e4 / 0.32768e5 * p0;
    t34 = 0.1225e4 / 0.32768e5 * p3;
    t35 = (t34 + t32 + t33 + t31) * p4;
    t36 = p0 + p3;
    t37 = p1 + p2;
    t38 = 0.3e1 / 0.8e1 * p4 * t37 + p4 * t36 / 8;
    t39 = 2;
    t40 = 4;
    t41 = 0.1e1 / 0.6e1;
    t42 = 0.1e1 / 0.12e2;
    t43 = 0.1e1 / 0.24e2;
    f = t43 * (p4 * ((0.3e1 / 0.8e1 * t37 + t36 / 8) * cos(t38) +
                     t40 * ((t4 + t3 + t1 + t2) * cos(t5) +
                            (t14 + t13 + t12 + t11) * cos(t15) +
                            (t24 + t23 + t22 + t21) * cos(t25) +
                            (t34 + t32 + t33 + t31) * cos(t35)) +
                     t39 * ((t9 + t8 + t7 + t6) * cos(t10) +
                            (t19 + t18 + t17 + t16) * cos(t20) +
                            (t29 + t28 + t27 + t26) * cos(t30))) +
               sin(t38)) +
        t41 * (sin(t5) + sin(t15) + sin(t25) + sin(t35)) +
        t42 * (sin(t10) + sin(t20) + sin(t30));
    return (f);
}

double SE2Constraints::dtdp1(ParamKnot param) {
    double f;
    double p4;
    p4 = param.sf;
    f = 0.3e1 / 0.8e1 * p4;
    return (f);
}

double SE2Constraints::dtdp2(ParamKnot param) {
    double f;
    double p4;
    p4 = param.sf;
    f = 0.3e1 / 0.8e1 * p4;
    return (f);
}

double SE2Constraints::dtdp3(ParamKnot param) {
    double f;
    double p4;

    p4 = param.sf;
    f = p4 / 8;
    return (f);
}

double SE2Constraints::dtdp4(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double t1;
    double t2;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    t1 = 0.1e1 / 0.8e1;
    t2 = 0.3e1 / 0.8e1;
    f = t1 * (p0 + p3) + t2 * (p1 + p2);
    return (f);
}

double SE2Constraints::dxd11(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = pow(p4, 3) *
        (-0.3426201e7 / 0.268435456e9 *
                 cos((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                      0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                     p4) -
         0.131769e6 / 0.2097152e7 *
                 cos((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                      0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                     p4) -
         0.99261369e8 / 0.268435456e9 *
                 cos((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                      0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                     p4) -
         0.2601e4 / 0.8192e4 *
                 cos((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 + p3 / 128 -
                      0.3e1 / 0.128e3 * p2) *
                     p4) -
         0.209525625e9 / 0.268435456e9 *
                 cos((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                      0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                     p4) -
         0.793881e6 / 0.2097152e7 *
                 cos((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                      0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                     p4) -
         0.171164889e9 / 0.268435456e9 *
                 cos((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                      0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                     p4) -
         0.9e1 / 0.64e2 *
                 cos(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2))) /
        24;
    return (f);
}

double SE2Constraints::dxd21(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = pow(p4, 3) *
        (0.1471545e7 / 0.268435456e9 *
                 cos((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                      0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                     p4) +
         0.44649e5 / 0.2097152e7 *
                 cos((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                      0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                     p4) +
         0.21789081e8 / 0.268435456e9 *
                 cos((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                      0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                     p4) +
         0.153e3 / 0.8192e4 *
                 cos((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 + p3 / 128 -
                      0.3e1 / 0.128e3 * p2) *
                     p4) -
         0.33654375e8 / 0.268435456e9 *
                 cos((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                      0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                     p4) -
         0.360855e6 / 0.2097152e7 *
                 cos((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                      0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                     p4) -
         0.136547271e9 / 0.268435456e9 *
                 cos((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                      0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                     p4) -
         0.9e1 / 0.64e2 *
                 cos(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2))) /
        24;
    return (f);
}

double SE2Constraints::dxd22(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = pow(p4, 3) *
        (-0.632025e6 / 0.268435456e9 *
                 cos((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                      0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                     p4) -
         0.15129e5 / 0.2097152e7 *
                 cos((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                      0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                     p4) -
         0.4782969e7 / 0.268435456e9 *
                 cos((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                      0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                     p4) -
         0.9e1 / 0.8192e4 * cos((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 +
                                 p3 / 128 - 0.3e1 / 0.128e3 * p2) *
                                p4) -
         0.5405625e7 / 0.268435456e9 *
                 cos((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                      0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                     p4) -
         0.164025e6 / 0.2097152e7 *
                 cos((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                      0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                     p4) -
         0.108930969e9 / 0.268435456e9 *
                 cos((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                      0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                     p4) -
         0.9e1 / 0.64e2 *
                 cos(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2))) /
        24;
    return (f);
}

double SE2Constraints::dxd31(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = pow(p4, 3) *
        (-0.312819e6 / 0.268435456e9 *
                 cos((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                      0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                     p4) -
         0.9075e4 / 0.2097152e7 *
                 cos((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                      0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                     p4) -
         0.4393683e7 / 0.268435456e9 *
                 cos((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                      0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                     p4) -
         0.51e2 / 0.8192e4 *
                 cos((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 + p3 / 128 -
                      0.3e1 / 0.128e3 * p2) *
                     p4) -
         0.361875e6 / 0.268435456e9 *
                 cos((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                      0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                     p4) -
         0.8019e4 / 0.2097152e7 *
                 cos((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                      0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                     p4) -
         0.16026675e8 / 0.268435456e9 *
                 cos((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                      0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                     p4) -
         0.3e1 / 0.64e2 *
                 cos(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2))) /
        24;
    return (f);
}

double SE2Constraints::dxd32(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = pow(p4, 3) *
        (0.134355e6 / 0.268435456e9 *
                 cos((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                      0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                     p4) +
         0.3075e4 / 0.2097152e7 *
                 cos((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                      0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                     p4) +
         0.964467e6 / 0.268435456e9 *
                 cos((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                      0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                     p4) +
         0.3e1 / 0.8192e4 * cos((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 +
                                 p3 / 128 - 0.3e1 / 0.128e3 * p2) *
                                p4) -
         0.58125e5 / 0.268435456e9 *
                 cos((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                      0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                     p4) -
         0.3645e4 / 0.2097152e7 *
                 cos((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                      0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                     p4) -
         0.12785325e8 / 0.268435456e9 *
                 cos((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                      0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                     p4) -
         0.3e1 / 0.64e2 *
                 cos(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2))) /
        24;
    return (f);
}

double SE2Constraints::dxd33(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = pow(p4, 3) *
        (-0.28561e5 / 0.268435456e9 *
                 cos((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                      0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                     p4) -
         0.625e3 / 0.2097152e7 *
                 cos((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                      0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                     p4) -
         0.194481e6 / 0.268435456e9 *
                 cos((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                      0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                     p4) -
         cos((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 + p3 / 128 -
              0.3e1 / 0.128e3 * p2) *
             p4) /
                 8192 -
         0.625e3 / 0.268435456e9 *
                 cos((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                      0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                     p4) -
         0.81e2 / 0.2097152e7 *
                 cos((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                      0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                     p4) -
         0.1500625e7 / 0.268435456e9 *
                 cos((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                      0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                     p4) -
         cos(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2)) / 64) /
        24;
    return (f);
}

double SE2Constraints::dxd41(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    double t1;
    double t10;
    double t11;
    double t12;
    double t13;
    double t14;
    double t15;
    double t16;
    double t17;
    double t18;
    double t19;
    double t2;
    double t20;
    double t21;
    double t22;
    double t23;
    double t24;
    double t25;
    double t26;
    double t27;
    double t28;
    double t29;
    double t3;
    double t30;
    double t31;
    double t32;
    double t33;
    double t34;
    double t35;
    double t36;
    double t37;
    double t38;
    double t39;
    double t4;
    double t40;
    double t41;
    double t42;
    double t43;
    double t44;
    double t45;
    double t46;
    double t47;
    double t48;
    double t49;
    double t5;
    double t50;
    double t51;
    double t52;
    double t53;
    double t54;
    double t6;
    double t7;
    double t8;
    double t9;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    t1 = -0.795e3 / 0.32768e5 * p2;
    t2 = 0.169e3 / 0.32768e5 * p3;
    t3 = 0.1851e4 / 0.32768e5 * p1;
    t4 = 0.2871e4 / 0.32768e5 * p0;
    t5 = (t1 + t4 + t3 + t2) * p4;
    t6 = sin(t5);
    t7 = -0.123e3 / 0.2048e4 * p2;
    t8 = 0.25e2 / 0.2048e4 * p3;
    t9 = 0.247e3 / 0.2048e4 * p0;
    t10 = 0.363e3 / 0.2048e4 * p1;
    t11 = (t7 + t9 + t10 + t8) * p4;
    t12 = sin(t11);
    t13 = 0.441e3 / 0.32768e5 * p3;
    t14 = 0.4071e4 / 0.32768e5 * p0;
    t15 = 0.9963e4 / 0.32768e5 * p1;
    t16 = -0.2187e4 / 0.32768e5 * p2;
    t17 = (t16 + t14 + t15 + t13) * p4;
    t18 = sin(t17);
    t19 = -0.3e1 / 0.128e3 * p2;
    t20 = p3 / 128;
    t21 = 0.15e2 / 0.128e3 * p0;
    t22 = 0.51e2 / 0.128e3 * p1;
    t23 = (t19 + t20 + t22 + t21) * p4;
    t24 = sin(t23);
    t25 = 0.25e2 / 0.32768e5 * p3;
    t26 = 0.2325e4 / 0.32768e5 * p2;
    t27 = 0.3655e4 / 0.32768e5 * p0;
    t28 = 0.14475e5 / 0.32768e5 * p1;
    t29 = (t28 + t26 + t27 + t25) * p4;
    t30 = sin(t29);
    t31 = 0.9e1 / 0.2048e4 * p3;
    t32 = 0.231e3 / 0.2048e4 * p0;
    t33 = 0.405e3 / 0.2048e4 * p2;
    t34 = 0.891e3 / 0.2048e4 * p1;
    t35 = (t34 + t33 + t32 + t31) * p4;
    t36 = sin(t35);
    t37 = 0.1225e4 / 0.32768e5 * p3;
    t38 = 0.3927e4 / 0.32768e5 * p0;
    t39 = 0.10437e5 / 0.32768e5 * p2;
    t40 = 0.13083e5 / 0.32768e5 * p1;
    t41 = (t39 + t40 + t38 + t37) * p4;
    t42 = sin(t41);
    t43 = p0 + p3;
    t44 = p1 + p2;
    t45 = p4 * t43 / 8 + 0.3e1 / 0.8e1 * p4 * t44;
    t46 = sin(t45);
    t47 = -0.14475e5 / 0.8192e4;
    t48 = -0.13083e5 / 0.8192e4;
    t49 = -0.9963e4 / 0.8192e4;
    t50 = -0.1851e4 / 0.8192e4;
    t51 = -0.891e3 / 0.1024e4;
    t52 = -0.363e3 / 0.1024e4;
    t53 = -0.51e2 / 0.64e2;
    t54 = 0.1e1 / 0.24e2;
    f = (-0.121e3 / 0.8192e4 * t12 - 0.3321e4 / 0.65536e5 * t18 -
         0.17e2 / 0.512e3 * t24 - 0.4825e4 / 0.65536e5 * t30 -
         0.297e3 / 0.8192e4 * t36 - 0.4361e4 / 0.65536e5 * t42 - t46 / 64 -
         0.617e3 / 0.65536e5 * t6 +
         (t50 * ((t1 + t4 + t3 + t2) * p4 * cos(t5) + t6) +
          t52 * ((t7 + t9 + t10 + t8) * p4 * cos(t11) + t12) +
          t49 * ((t16 + t14 + t15 + t13) * p4 * cos(t17) + t18) +
          t53 * ((t19 + t20 + t22 + t21) * p4 * cos(t23) + t24) +
          t47 * ((t28 + t26 + t27 + t25) * p4 * cos(t29) + t30) +
          t51 * ((t34 + t33 + t32 + t31) * p4 * cos(t35) + t36) +
          t48 * ((t39 + t40 + t38 + t37) * p4 * cos(t41) + t42) -
          0.3e1 / 0.8e1 * p4 * (t43 / 8 + 0.3e1 / 0.8e1 * t44) * cos(t45) -
          0.3e1 / 0.8e1 * t46) *
                 t54) *
        p4;
    return (f);
}

double SE2Constraints::dxd42(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    double t1;
    double t10;
    double t11;
    double t12;
    double t13;
    double t14;
    double t15;
    double t16;
    double t17;
    double t18;
    double t19;
    double t2;
    double t20;
    double t21;
    double t22;
    double t23;
    double t24;
    double t25;
    double t26;
    double t27;
    double t28;
    double t29;
    double t3;
    double t30;
    double t31;
    double t32;
    double t33;
    double t34;
    double t35;
    double t36;
    double t37;
    double t38;
    double t39;
    double t4;
    double t40;
    double t41;
    double t42;
    double t43;
    double t44;
    double t45;
    double t46;
    double t47;
    double t48;
    double t49;
    double t5;
    double t50;
    double t51;
    double t52;
    double t53;
    double t54;
    double t6;
    double t7;
    double t8;
    double t9;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    t1 = 0.169e3 / 0.32768e5 * p3;
    t2 = 0.2871e4 / 0.32768e5 * p0;
    t3 = 0.1851e4 / 0.32768e5 * p1;
    t4 = -0.795e3 / 0.32768e5 * p2;
    t5 = (t1 + t2 + t3 + t4) * p4;
    t6 = sin(t5);
    t7 = 0.25e2 / 0.2048e4 * p3;
    t8 = -0.123e3 / 0.2048e4 * p2;
    t9 = 0.247e3 / 0.2048e4 * p0;
    t10 = 0.363e3 / 0.2048e4 * p1;
    t11 = (t7 + t10 + t8 + t9) * p4;
    t12 = sin(t11);
    t13 = 0.9963e4 / 0.32768e5 * p1;
    t14 = 0.4071e4 / 0.32768e5 * p0;
    t15 = 0.441e3 / 0.32768e5 * p3;
    t16 = -0.2187e4 / 0.32768e5 * p2;
    t17 = (t13 + t14 + t16 + t15) * p4;
    t18 = sin(t17);
    t19 = 0.15e2 / 0.128e3 * p0;
    t20 = 0.51e2 / 0.128e3 * p1;
    t21 = -0.3e1 / 0.128e3 * p2;
    t22 = p3 / 128;
    t23 = (t20 + t19 + t22 + t21) * p4;
    t24 = sin(t23);
    t25 = 0.25e2 / 0.32768e5 * p3;
    t26 = 0.14475e5 / 0.32768e5 * p1;
    t27 = 0.2325e4 / 0.32768e5 * p2;
    t28 = 0.3655e4 / 0.32768e5 * p0;
    t29 = (t25 + t27 + t28 + t26) * p4;
    t30 = sin(t29);
    t31 = 0.9e1 / 0.2048e4 * p3;
    t32 = 0.231e3 / 0.2048e4 * p0;
    t33 = 0.405e3 / 0.2048e4 * p2;
    t34 = 0.891e3 / 0.2048e4 * p1;
    t35 = (t32 + t31 + t34 + t33) * p4;
    t36 = sin(t35);
    t37 = 0.10437e5 / 0.32768e5 * p2;
    t38 = 0.13083e5 / 0.32768e5 * p1;
    t39 = 0.3927e4 / 0.32768e5 * p0;
    t40 = 0.1225e4 / 0.32768e5 * p3;
    t41 = (t37 + t38 + t39 + t40) * p4;
    t42 = sin(t41);
    t43 = p0 + p3;
    t44 = p1 + p2;
    t45 = p4 * t43 / 8 + 0.3e1 / 0.8e1 * p4 * t44;
    t46 = sin(t45);
    t47 = -0.10437e5 / 0.8192e4;
    t48 = -0.2325e4 / 0.8192e4;
    t49 = -0.405e3 / 0.1024e4;
    t50 = 0.3e1 / 0.64e2;
    t51 = 0.123e3 / 0.1024e4;
    t52 = 0.795e3 / 0.8192e4;
    t53 = 0.2187e4 / 0.8192e4;
    t54 = 0.1e1 / 0.24e2;
    f = (0.41e2 / 0.8192e4 * t12 + 0.729e3 / 0.65536e5 * t18 + t24 / 512 -
         0.775e3 / 0.65536e5 * t30 - 0.135e3 / 0.8192e4 * t36 -
         0.3479e4 / 0.65536e5 * t42 - t46 / 64 + 0.265e3 / 0.65536e5 * t6 +
         (t49 * ((t32 + t31 + t34 + t33) * p4 * cos(t35) + t36) +
          t47 * ((t37 + t38 + t39 + t40) * p4 * cos(t41) + t42) +
          t52 * ((t1 + t2 + t3 + t4) * p4 * cos(t5) + t6) +
          t51 * ((t7 + t10 + t8 + t9) * p4 * cos(t11) + t12) +
          t53 * ((t13 + t14 + t16 + t15) * p4 * cos(t17) + t18) +
          t50 * ((t20 + t19 + t22 + t21) * p4 * cos(t23) + t24) +
          t48 * ((t25 + t27 + t28 + t26) * p4 * cos(t29) + t30) -
          0.3e1 / 0.8e1 * p4 * (t43 / 8 + 0.3e1 / 0.8e1 * t44) * cos(t45) -
          0.3e1 / 0.8e1 * t46) *
                 t54) *
        p4;
    return (f);
}

double SE2Constraints::dxd43(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    double t1;
    double t10;
    double t11;
    double t12;
    double t13;
    double t14;
    double t15;
    double t16;
    double t17;
    double t18;
    double t19;
    double t2;
    double t20;
    double t21;
    double t22;
    double t23;
    double t24;
    double t25;
    double t26;
    double t27;
    double t28;
    double t29;
    double t3;
    double t30;
    double t31;
    double t32;
    double t33;
    double t34;
    double t35;
    double t36;
    double t37;
    double t38;
    double t39;
    double t4;
    double t40;
    double t41;
    double t42;
    double t43;
    double t44;
    double t45;
    double t46;
    double t47;
    double t48;
    double t49;
    double t5;
    double t50;
    double t51;
    double t52;
    double t53;
    double t54;
    double t6;
    double t7;
    double t8;
    double t9;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    t1 = 0.2871e4 / 0.32768e5 * p0;
    t2 = 0.169e3 / 0.32768e5 * p3;
    t3 = 0.1851e4 / 0.32768e5 * p1;
    t4 = -0.795e3 / 0.32768e5 * p2;
    t5 = (t2 + t4 + t1 + t3) * p4;
    t6 = sin(t5);
    t7 = 0.247e3 / 0.2048e4 * p0;
    t8 = 0.363e3 / 0.2048e4 * p1;
    t9 = 0.25e2 / 0.2048e4 * p3;
    t10 = -0.123e3 / 0.2048e4 * p2;
    t11 = (t10 + t7 + t8 + t9) * p4;
    t12 = sin(t11);
    t13 = 0.441e3 / 0.32768e5 * p3;
    t14 = -0.2187e4 / 0.32768e5 * p2;
    t15 = 0.4071e4 / 0.32768e5 * p0;
    t16 = 0.9963e4 / 0.32768e5 * p1;
    t17 = (t15 + t14 + t13 + t16) * p4;
    t18 = sin(t17);
    t19 = 0.51e2 / 0.128e3 * p1;
    t20 = 0.15e2 / 0.128e3 * p0;
    t21 = p3 / 128;
    t22 = -0.3e1 / 0.128e3 * p2;
    t23 = (t19 + t20 + t21 + t22) * p4;
    t24 = sin(t23);
    t25 = 0.3655e4 / 0.32768e5 * p0;
    t26 = 0.25e2 / 0.32768e5 * p3;
    t27 = 0.2325e4 / 0.32768e5 * p2;
    t28 = 0.14475e5 / 0.32768e5 * p1;
    t29 = (t28 + t25 + t26 + t27) * p4;
    t30 = sin(t29);
    t31 = 0.405e3 / 0.2048e4 * p2;
    t32 = 0.891e3 / 0.2048e4 * p1;
    t33 = 0.231e3 / 0.2048e4 * p0;
    t34 = 0.9e1 / 0.2048e4 * p3;
    t35 = (t34 + t31 + t32 + t33) * p4;
    t36 = sin(t35);
    t37 = 0.3927e4 / 0.32768e5 * p0;
    t38 = 0.1225e4 / 0.32768e5 * p3;
    t39 = 0.13083e5 / 0.32768e5 * p1;
    t40 = 0.10437e5 / 0.32768e5 * p2;
    t41 = (t39 + t37 + t40 + t38) * p4;
    t42 = sin(t41);
    t43 = p0 + p3;
    t44 = p1 + p2;
    t45 = 0.3e1 / 0.8e1 * p4 * t44 + p4 * t43 / 8;
    t46 = sin(t45);
    t47 = -0.1225e4 / 0.8192e4;
    t48 = -0.441e3 / 0.8192e4;
    t49 = -0.169e3 / 0.8192e4;
    t50 = -0.25e2 / 0.1024e4;
    t51 = -0.25e2 / 0.8192e4;
    t52 = -0.9e1 / 0.1024e4;
    t53 = -0.1e1 / 0.64e2;
    t54 = 0.1e1 / 0.24e2;
    f = (-0.25e2 / 0.24576e5 * t12 - 0.147e3 / 0.65536e5 * t18 - t24 / 1536 -
         0.25e2 / 0.196608e6 * t30 - 0.3e1 / 0.8192e4 * t36 -
         0.1225e4 / 0.196608e6 * t42 - t46 / 192 - 0.169e3 / 0.196608e6 * t6 +
         (t49 * (t6 + (t2 + t4 + t1 + t3) * p4 * cos(t5)) +
          t50 * (t12 + (t10 + t7 + t8 + t9) * p4 * cos(t11)) +
          t48 * (t18 + (t15 + t14 + t13 + t16) * p4 * cos(t17)) +
          t53 * (t24 + (t19 + t20 + t21 + t22) * p4 * cos(t23)) +
          t51 * ((t28 + t25 + t26 + t27) * p4 * cos(t29) + t30) +
          t52 * ((t34 + t31 + t32 + t33) * p4 * cos(t35) + t36) +
          t47 * ((t39 + t37 + t40 + t38) * p4 * cos(t41) + t42) -
          p4 * (0.3e1 / 0.8e1 * t44 + t43 / 8) * cos(t45) / 8 - t46 / 8) *
                 t54) *
        p4;
    return (f);
}

double SE2Constraints::dxd44(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    double t1;
    double t10;
    double t11;
    double t12;
    double t13;
    double t14;
    double t15;
    double t16;
    double t17;
    double t18;
    double t19;
    double t2;
    double t20;
    double t3;
    double t4;
    double t5;
    double t6;
    double t7;
    double t8;
    double t9;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    t1 = 0.2871e4 / 0.32768e5 * p0;
    t2 = 0.1851e4 / 0.32768e5 * p1;
    t3 = -0.795e3 / 0.32768e5 * p2;
    t4 = 0.169e3 / 0.32768e5 * p3;
    t5 = t2 + t1 + t3 + t4;
    t1 = (t2 + t1 + t3 + t4) * p4;
    t2 = 0.247e3 / 0.2048e4 * p0;
    t3 = 0.363e3 / 0.2048e4 * p1;
    t4 = -0.123e3 / 0.2048e4 * p2;
    t6 = 0.25e2 / 0.2048e4 * p3;
    t7 = t2 + t3 + t4 + t6;
    t2 = (t2 + t3 + t4 + t6) * p4;
    t3 = 0.4071e4 / 0.32768e5 * p0;
    t4 = 0.9963e4 / 0.32768e5 * p1;
    t6 = 0.441e3 / 0.32768e5 * p3;
    t8 = -0.2187e4 / 0.32768e5 * p2;
    t9 = t6 + t3 + t4 + t8;
    t3 = (t6 + t3 + t4 + t8) * p4;
    t4 = -0.3e1 / 0.128e3 * p2;
    t6 = p3 / 128;
    t8 = 0.15e2 / 0.128e3 * p0;
    t10 = 0.51e2 / 0.128e3 * p1;
    t11 = t4 + t6 + t8 + t10;
    t4 = (t4 + t6 + t8 + t10) * p4;
    t6 = 0.14475e5 / 0.32768e5 * p1;
    t8 = 0.3655e4 / 0.32768e5 * p0;
    t10 = 0.2325e4 / 0.32768e5 * p2;
    t12 = 0.25e2 / 0.32768e5 * p3;
    t13 = t10 + t8 + t6 + t12;
    t6 = (t10 + t8 + t6 + t12) * p4;
    t8 = 0.405e3 / 0.2048e4 * p2;
    t10 = 0.891e3 / 0.2048e4 * p1;
    t12 = 0.231e3 / 0.2048e4 * p0;
    t14 = 0.9e1 / 0.2048e4 * p3;
    t15 = t8 + t10 + t12 + t14;
    t8 = (t8 + t10 + t12 + t14) * p4;
    t10 = 0.13083e5 / 0.32768e5 * p1;
    t12 = 0.10437e5 / 0.32768e5 * p2;
    t14 = 0.3927e4 / 0.32768e5 * p0;
    t16 = 0.1225e4 / 0.32768e5 * p3;
    t17 = t16 + t12 + t14 + t10;
    t10 = (t16 + t12 + t14 + t10) * p4;
    t12 = p0 + p3;
    t14 = p1 + p2;
    t16 = 0.3e1 / 0.8e1 * t14 + t12 / 8;
    t12 = 0.3e1 / 0.8e1 * p4 * t14 + p4 * t12 / 8;
    t14 = -4;
    t18 = -2;
    t19 = -0.1e1 / 0.3e1;
    t20 = -0.1e1 / 0.6e1;
    f = t19 * (t5 * sin(t1) + t9 * sin(t3) + t13 * sin(t6) + t17 * sin(t10)) +
        t20 * (t7 * sin(t2) + t11 * sin(t4) + t15 * sin(t8)) +
        p4 * (-pow(t16, 2) * cos(t12) +
              t14 * (pow(t5, 2) * cos(t1) + pow(t9, 2) * cos(t3) +
                     pow(t13, 2) * cos(t6) + pow(t17, 2) * cos(t10)) +
              t18 * (pow(t7, 2) * cos(t2) + pow(t11, 2) * cos(t4) +
                     pow(t15, 2) * cos(t8))) /
                24 -
        t16 * sin(t12) / 12;
    return (f);
}

double SE2Constraints::dyd11(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = pow(p4, 3) *
        (-0.3426201e7 / 0.268435456e9 *
                 sin((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                      0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                     p4) -
         0.131769e6 / 0.2097152e7 *
                 sin((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                      0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                     p4) -
         0.99261369e8 / 0.268435456e9 *
                 sin((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                      0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                     p4) -
         0.2601e4 / 0.8192e4 *
                 sin((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 + p3 / 128 -
                      0.3e1 / 0.128e3 * p2) *
                     p4) -
         0.209525625e9 / 0.268435456e9 *
                 sin((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                      0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                     p4) -
         0.793881e6 / 0.2097152e7 *
                 sin((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                      0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                     p4) -
         0.171164889e9 / 0.268435456e9 *
                 sin((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                      0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                     p4) -
         0.9e1 / 0.64e2 *
                 sin(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2))) /
        24;
    return (f);
}

double SE2Constraints::dyd21(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = pow(p4, 3) *
        (0.1471545e7 / 0.268435456e9 *
                 sin((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                      0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                     p4) +
         0.44649e5 / 0.2097152e7 *
                 sin((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                      0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                     p4) +
         0.21789081e8 / 0.268435456e9 *
                 sin((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                      0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                     p4) +
         0.153e3 / 0.8192e4 *
                 sin((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 + p3 / 128 -
                      0.3e1 / 0.128e3 * p2) *
                     p4) -
         0.33654375e8 / 0.268435456e9 *
                 sin((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                      0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                     p4) -
         0.360855e6 / 0.2097152e7 *
                 sin((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                      0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                     p4) -
         0.136547271e9 / 0.268435456e9 *
                 sin((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                      0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                     p4) -
         0.9e1 / 0.64e2 *
                 sin(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2))) /
        24;
    return (f);
}

double SE2Constraints::dyd22(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = pow(p4, 3) *
        (-0.632025e6 / 0.268435456e9 *
                 sin((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                      0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                     p4) -
         0.15129e5 / 0.2097152e7 *
                 sin((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                      0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                     p4) -
         0.4782969e7 / 0.268435456e9 *
                 sin((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                      0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                     p4) -
         0.9e1 / 0.8192e4 * sin((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 +
                                 p3 / 128 - 0.3e1 / 0.128e3 * p2) *
                                p4) -
         0.5405625e7 / 0.268435456e9 *
                 sin((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                      0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                     p4) -
         0.164025e6 / 0.2097152e7 *
                 sin((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                      0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                     p4) -
         0.108930969e9 / 0.268435456e9 *
                 sin((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                      0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                     p4) -
         0.9e1 / 0.64e2 *
                 sin(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2))) /
        24;
    return (f);
}

double SE2Constraints::dyd31(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = pow(p4, 3) *
        (-0.312819e6 / 0.268435456e9 *
                 sin((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                      0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                     p4) -
         0.9075e4 / 0.2097152e7 *
                 sin((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                      0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                     p4) -
         0.4393683e7 / 0.268435456e9 *
                 sin((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                      0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                     p4) -
         0.51e2 / 0.8192e4 *
                 sin((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 + p3 / 128 -
                      0.3e1 / 0.128e3 * p2) *
                     p4) -
         0.361875e6 / 0.268435456e9 *
                 sin((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                      0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                     p4) -
         0.8019e4 / 0.2097152e7 *
                 sin((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                      0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                     p4) -
         0.16026675e8 / 0.268435456e9 *
                 sin((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                      0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                     p4) -
         0.3e1 / 0.64e2 *
                 sin(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2))) /
        24;
    return (f);
}

double SE2Constraints::dyd32(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = pow(p4, 3) *
        (0.134355e6 / 0.268435456e9 *
                 sin((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                      0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                     p4) +
         0.3075e4 / 0.2097152e7 *
                 sin((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                      0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                     p4) +
         0.964467e6 / 0.268435456e9 *
                 sin((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                      0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                     p4) +
         0.3e1 / 0.8192e4 * sin((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 +
                                 p3 / 128 - 0.3e1 / 0.128e3 * p2) *
                                p4) -
         0.58125e5 / 0.268435456e9 *
                 sin((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                      0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                     p4) -
         0.3645e4 / 0.2097152e7 *
                 sin((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                      0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                     p4) -
         0.12785325e8 / 0.268435456e9 *
                 sin((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                      0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                     p4) -
         0.3e1 / 0.64e2 *
                 sin(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2))) /
        24;
    return (f);
}

double SE2Constraints::dyd33(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    f = pow(p4, 3) *
        (-0.28561e5 / 0.268435456e9 *
                 sin((0.2871e4 / 0.32768e5 * p0 + 0.1851e4 / 0.32768e5 * p1 +
                      0.169e3 / 0.32768e5 * p3 - 0.795e3 / 0.32768e5 * p2) *
                     p4) -
         0.625e3 / 0.2097152e7 *
                 sin((0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
                      0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2) *
                     p4) -
         0.194481e6 / 0.268435456e9 *
                 sin((0.4071e4 / 0.32768e5 * p0 + 0.9963e4 / 0.32768e5 * p1 +
                      0.441e3 / 0.32768e5 * p3 - 0.2187e4 / 0.32768e5 * p2) *
                     p4) -
         sin((0.15e2 / 0.128e3 * p0 + 0.51e2 / 0.128e3 * p1 + p3 / 128 -
              0.3e1 / 0.128e3 * p2) *
             p4) /
                 8192 -
         0.625e3 / 0.268435456e9 *
                 sin((0.3655e4 / 0.32768e5 * p0 + 0.14475e5 / 0.32768e5 * p1 +
                      0.2325e4 / 0.32768e5 * p2 + 0.25e2 / 0.32768e5 * p3) *
                     p4) -
         0.81e2 / 0.2097152e7 *
                 sin((0.231e3 / 0.2048e4 * p0 + 0.891e3 / 0.2048e4 * p1 +
                      0.405e3 / 0.2048e4 * p2 + 0.9e1 / 0.2048e4 * p3) *
                     p4) -
         0.1500625e7 / 0.268435456e9 *
                 sin((0.3927e4 / 0.32768e5 * p0 + 0.13083e5 / 0.32768e5 * p1 +
                      0.10437e5 / 0.32768e5 * p2 + 0.1225e4 / 0.32768e5 * p3) *
                     p4) -
         sin(p4 * (p0 + p3) / 8 + 0.3e1 / 0.8e1 * p4 * (p1 + p2)) / 64) /
        24;
    return (f);
}

double SE2Constraints::dyd41(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    double t1;
    double t10;
    double t11;
    double t12;
    double t13;
    double t14;
    double t15;
    double t16;
    double t17;
    double t18;
    double t19;
    double t2;
    double t20;
    double t21;
    double t22;
    double t23;
    double t24;
    double t25;
    double t26;
    double t27;
    double t28;
    double t29;
    double t3;
    double t30;
    double t31;
    double t32;
    double t33;
    double t34;
    double t35;
    double t36;
    double t37;
    double t38;
    double t39;
    double t4;
    double t40;
    double t41;
    double t42;
    double t43;
    double t44;
    double t45;
    double t46;
    double t47;
    double t48;
    double t49;
    double t5;
    double t50;
    double t51;
    double t6;
    double t7;
    double t8;
    double t9;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    t1 = -0.795e3 / 0.32768e5 * p2;
    t2 = 0.169e3 / 0.32768e5 * p3;
    t3 = 0.1851e4 / 0.32768e5 * p1;
    t4 = 0.2871e4 / 0.32768e5 * p0;
    t5 = (t1 + t2 + t3 + t4) * p4;
    t6 = cos(t5);
    t7 = 0.247e3 / 0.2048e4 * p0 + 0.363e3 / 0.2048e4 * p1 +
         0.25e2 / 0.2048e4 * p3 - 0.123e3 / 0.2048e4 * p2;
    t8 = t7 * p4;
    t9 = cos(t8);
    t10 = -0.2187e4 / 0.32768e5 * p2;
    t11 = 0.441e3 / 0.32768e5 * p3;
    t12 = 0.4071e4 / 0.32768e5 * p0;
    t13 = 0.9963e4 / 0.32768e5 * p1;
    t14 = (t10 + t12 + t13 + t11) * p4;
    t15 = cos(t14);
    t16 = 0.51e2 / 0.128e3 * p1;
    t17 = 0.15e2 / 0.128e3 * p0;
    t18 = p3 / 128;
    t19 = -0.3e1 / 0.128e3 * p2;
    t20 = (t16 + t17 + t18 + t19) * p4;
    t21 = cos(t20);
    t22 = 0.25e2 / 0.32768e5 * p3;
    t23 = 0.2325e4 / 0.32768e5 * p2;
    t24 = 0.3655e4 / 0.32768e5 * p0;
    t25 = 0.14475e5 / 0.32768e5 * p1;
    t26 = (t22 + t25 + t23 + t24) * p4;
    t27 = cos(t26);
    t28 = 0.9e1 / 0.2048e4 * p3;
    t29 = 0.891e3 / 0.2048e4 * p1;
    t30 = 0.405e3 / 0.2048e4 * p2;
    t31 = 0.231e3 / 0.2048e4 * p0;
    t32 = (t28 + t29 + t30 + t31) * p4;
    t33 = cos(t32);
    t34 = 0.1225e4 / 0.32768e5 * p3;
    t35 = 0.3927e4 / 0.32768e5 * p0;
    t36 = 0.13083e5 / 0.32768e5 * p1;
    t37 = 0.10437e5 / 0.32768e5 * p2;
    t38 = (t35 + t36 + t37 + t34) * p4;
    t39 = cos(t38);
    t40 = p0 + p3;
    t41 = p1 + p2;
    t42 = 0.3e1 / 0.8e1 * p4 * t41 + p4 * t40 / 8;
    t43 = cos(t42);
    t44 = 0.51e2 / 0.64e2;
    t45 = 0.363e3 / 0.1024e4;
    t46 = 0.891e3 / 0.1024e4;
    t47 = 0.1851e4 / 0.8192e4;
    t48 = 0.9963e4 / 0.8192e4;
    t49 = 0.13083e5 / 0.8192e4;
    t50 = 0.14475e5 / 0.8192e4;
    t51 = 0.1e1 / 0.24e2;
    f = (0.3321e4 / 0.65536e5 * t15 + 0.17e2 / 0.512e3 * t21 +
         0.4825e4 / 0.65536e5 * t27 + 0.297e3 / 0.8192e4 * t33 +
         0.4361e4 / 0.65536e5 * t39 + t43 / 64 + 0.617e3 / 0.65536e5 * t6 +
         0.121e3 / 0.8192e4 * t9 +
         (t47 * (t6 - (t1 + t2 + t3 + t4) * p4 * sin(t5)) +
          t45 * (-t7 * p4 * sin(t8) + t9) +
          t48 * (t15 - (t10 + t12 + t13 + t11) * p4 * sin(t14)) +
          t44 * (t21 - (t16 + t17 + t18 + t19) * p4 * sin(t20)) +
          t50 * (t27 - (t22 + t25 + t23 + t24) * p4 * sin(t26)) +
          t46 * (-(t28 + t29 + t30 + t31) * p4 * sin(t32) + t33) +
          t49 * (-(t35 + t36 + t37 + t34) * p4 * sin(t38) + t39) +
          0.3e1 / 0.8e1 * t43 -
          0.3e1 / 0.8e1 * p4 * (0.3e1 / 0.8e1 * t41 + t40 / 8) * sin(t42)) *
                 t51) *
        p4;
    return (f);
}

double SE2Constraints::dyd42(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    double t1;
    double t10;
    double t11;
    double t12;
    double t13;
    double t14;
    double t15;
    double t16;
    double t17;
    double t18;
    double t19;
    double t2;
    double t20;
    double t21;
    double t22;
    double t23;
    double t24;
    double t25;
    double t26;
    double t27;
    double t28;
    double t29;
    double t3;
    double t30;
    double t31;
    double t32;
    double t33;
    double t34;
    double t35;
    double t36;
    double t37;
    double t38;
    double t39;
    double t4;
    double t40;
    double t41;
    double t42;
    double t43;
    double t44;
    double t45;
    double t46;
    double t47;
    double t48;
    double t49;
    double t5;
    double t50;
    double t51;
    double t52;
    double t53;
    double t54;
    double t6;
    double t7;
    double t8;
    double t9;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    t1 = -0.795e3 / 0.32768e5 * p2;
    t2 = 0.169e3 / 0.32768e5 * p3;
    t3 = 0.1851e4 / 0.32768e5 * p1;
    t4 = 0.2871e4 / 0.32768e5 * p0;
    t5 = (t1 + t3 + t4 + t2) * p4;
    t6 = cos(t5);
    t7 = -0.123e3 / 0.2048e4 * p2;
    t8 = 0.25e2 / 0.2048e4 * p3;
    t9 = 0.247e3 / 0.2048e4 * p0;
    t10 = 0.363e3 / 0.2048e4 * p1;
    t11 = (t7 + t9 + t10 + t8) * p4;
    t12 = cos(t11);
    t13 = -0.2187e4 / 0.32768e5 * p2;
    t14 = 0.441e3 / 0.32768e5 * p3;
    t15 = 0.4071e4 / 0.32768e5 * p0;
    t16 = 0.9963e4 / 0.32768e5 * p1;
    t17 = (t13 + t16 + t15 + t14) * p4;
    t18 = cos(t17);
    t19 = 0.51e2 / 0.128e3 * p1;
    t20 = -0.3e1 / 0.128e3 * p2;
    t21 = p3 / 128;
    t22 = 0.15e2 / 0.128e3 * p0;
    t23 = (t20 + t21 + t22 + t19) * p4;
    t24 = cos(t23);
    t25 = 0.25e2 / 0.32768e5 * p3;
    t26 = 0.2325e4 / 0.32768e5 * p2;
    t27 = 0.3655e4 / 0.32768e5 * p0;
    t28 = 0.14475e5 / 0.32768e5 * p1;
    t29 = (t28 + t27 + t26 + t25) * p4;
    t30 = cos(t29);
    t31 = 0.231e3 / 0.2048e4 * p0;
    t32 = 0.405e3 / 0.2048e4 * p2;
    t33 = 0.891e3 / 0.2048e4 * p1;
    t34 = 0.9e1 / 0.2048e4 * p3;
    t35 = (t34 + t32 + t33 + t31) * p4;
    t36 = cos(t35);
    t37 = 0.1225e4 / 0.32768e5 * p3;
    t38 = 0.3927e4 / 0.32768e5 * p0;
    t39 = 0.13083e5 / 0.32768e5 * p1;
    t40 = 0.10437e5 / 0.32768e5 * p2;
    t41 = (t40 + t38 + t39 + t37) * p4;
    t42 = cos(t41);
    t43 = p0 + p3;
    t44 = p1 + p2;
    t45 = 0.3e1 / 0.8e1 * p4 * t44 + p4 * t43 / 8;
    t46 = cos(t45);
    t47 = -0.2187e4 / 0.8192e4;
    t48 = -0.795e3 / 0.8192e4;
    t49 = -0.123e3 / 0.1024e4;
    t50 = -0.3e1 / 0.64e2;
    t51 = 0.405e3 / 0.1024e4;
    t52 = 0.2325e4 / 0.8192e4;
    t53 = 0.10437e5 / 0.8192e4;
    t54 = 0.1e1 / 0.24e2;
    f = (-0.41e2 / 0.8192e4 * t12 - 0.729e3 / 0.65536e5 * t18 - t24 / 512 +
         0.775e3 / 0.65536e5 * t30 + 0.135e3 / 0.8192e4 * t36 +
         0.3479e4 / 0.65536e5 * t42 + t46 / 64 - 0.265e3 / 0.65536e5 * t6 +
         (t52 * (t30 - (t28 + t27 + t26 + t25) * p4 * sin(t29)) +
          t51 * (t36 - (t34 + t32 + t33 + t31) * p4 * sin(t35)) +
          t53 * (t42 - (t40 + t38 + t39 + t37) * p4 * sin(t41)) +
          t48 * (-(t1 + t3 + t4 + t2) * p4 * sin(t5) + t6) +
          t49 * (-(t7 + t9 + t10 + t8) * p4 * sin(t11) + t12) +
          t47 * (t18 - (t13 + t16 + t15 + t14) * p4 * sin(t17)) +
          t50 * (t24 - (t20 + t21 + t22 + t19) * p4 * sin(t23)) +
          0.3e1 / 0.8e1 * t46 -
          0.3e1 / 0.8e1 * p4 * (0.3e1 / 0.8e1 * t44 + t43 / 8) * sin(t45)) *
                 t54) *
        p4;
    return (f);
}

double SE2Constraints::dyd43(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    double t1;
    double t10;
    double t11;
    double t12;
    double t13;
    double t14;
    double t15;
    double t16;
    double t17;
    double t18;
    double t19;
    double t2;
    double t20;
    double t21;
    double t22;
    double t23;
    double t24;
    double t25;
    double t26;
    double t27;
    double t28;
    double t29;
    double t3;
    double t30;
    double t31;
    double t32;
    double t33;
    double t34;
    double t35;
    double t36;
    double t37;
    double t38;
    double t39;
    double t4;
    double t40;
    double t41;
    double t42;
    double t43;
    double t44;
    double t45;
    double t46;
    double t47;
    double t48;
    double t49;
    double t5;
    double t50;
    double t51;
    double t52;
    double t53;
    double t54;
    double t6;
    double t7;
    double t8;
    double t9;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    t1 = 0.169e3 / 0.32768e5 * p3;
    t2 = -0.795e3 / 0.32768e5 * p2;
    t3 = 0.2871e4 / 0.32768e5 * p0;
    t4 = 0.1851e4 / 0.32768e5 * p1;
    t5 = (t2 + t1 + t3 + t4) * p4;
    t6 = cos(t5);
    t7 = 0.247e3 / 0.2048e4 * p0;
    t8 = 0.363e3 / 0.2048e4 * p1;
    t9 = -0.123e3 / 0.2048e4 * p2;
    t10 = 0.25e2 / 0.2048e4 * p3;
    t11 = (t9 + t7 + t8 + t10) * p4;
    t12 = cos(t11);
    t13 = 0.441e3 / 0.32768e5 * p3;
    t14 = 0.4071e4 / 0.32768e5 * p0;
    t15 = 0.9963e4 / 0.32768e5 * p1;
    t16 = -0.2187e4 / 0.32768e5 * p2;
    t17 = (t16 + t13 + t14 + t15) * p4;
    t18 = cos(t17);
    t19 = 0.51e2 / 0.128e3 * p1;
    t20 = 0.15e2 / 0.128e3 * p0;
    t21 = p3 / 128;
    t22 = -0.3e1 / 0.128e3 * p2;
    t23 = (t22 + t21 + t19 + t20) * p4;
    t24 = cos(t23);
    t25 = 0.14475e5 / 0.32768e5 * p1;
    t26 = 0.2325e4 / 0.32768e5 * p2;
    t27 = 0.3655e4 / 0.32768e5 * p0;
    t28 = 0.25e2 / 0.32768e5 * p3;
    t29 = (t28 + t27 + t25 + t26) * p4;
    t30 = cos(t29);
    t31 = 0.405e3 / 0.2048e4 * p2;
    t32 = 0.891e3 / 0.2048e4 * p1;
    t33 = 0.231e3 / 0.2048e4 * p0;
    t34 = 0.9e1 / 0.2048e4 * p3;
    t35 = (t31 + t32 + t33 + t34) * p4;
    t36 = cos(t35);
    t37 = 0.3927e4 / 0.32768e5 * p0;
    t38 = 0.10437e5 / 0.32768e5 * p2;
    t39 = 0.13083e5 / 0.32768e5 * p1;
    t40 = 0.1225e4 / 0.32768e5 * p3;
    t41 = (t38 + t37 + t40 + t39) * p4;
    t42 = cos(t41);
    t43 = p0 + p3;
    t44 = p1 + p2;
    t45 = 0.3e1 / 0.8e1 * p4 * t44 + p4 * t43 / 8;
    t46 = cos(t45);
    t47 = -0.1225e4 / 0.8192e4;
    t48 = -0.441e3 / 0.8192e4;
    t49 = -0.169e3 / 0.8192e4;
    t50 = -0.25e2 / 0.1024e4;
    t51 = -0.25e2 / 0.8192e4;
    t52 = -0.9e1 / 0.1024e4;
    t53 = -0.1e1 / 0.64e2;
    t54 = 0.1e1 / 0.24e2;
    f = (0.25e2 / 0.24576e5 * t12 + 0.147e3 / 0.65536e5 * t18 + t24 / 1536 +
         0.25e2 / 0.196608e6 * t30 + 0.3e1 / 0.8192e4 * t36 +
         0.1225e4 / 0.196608e6 * t42 + t46 / 192 + 0.169e3 / 0.196608e6 * t6 +
         (t49 * ((t2 + t1 + t3 + t4) * p4 * sin(t5) - t6) +
          t50 * ((t9 + t7 + t8 + t10) * p4 * sin(t11) - t12) +
          t48 * ((t16 + t13 + t14 + t15) * p4 * sin(t17) - t18) +
          t53 * ((t22 + t21 + t19 + t20) * p4 * sin(t23) - t24) +
          t51 * ((t28 + t27 + t25 + t26) * p4 * sin(t29) - t30) +
          t52 * ((t31 + t32 + t33 + t34) * p4 * sin(t35) - t36) +
          t47 * ((t38 + t37 + t40 + t39) * p4 * sin(t41) - t42) -
          p4 * (0.3e1 / 0.8e1 * t44 + t43 / 8) * sin(t45) / 8 + t46 / 8) *
                 t54) *
        p4;
    return (f);
}

double SE2Constraints::dyd44(ParamKnot param) {
    double f;
    double p0;
    double p1;
    double p2;
    double p3;
    double p4;
    double t1;
    double t10;
    double t11;
    double t12;
    double t13;
    double t14;
    double t15;
    double t16;
    double t17;
    double t18;
    double t19;
    double t2;
    double t20;
    double t3;
    double t4;
    double t5;
    double t6;
    double t7;
    double t8;
    double t9;
    p0 = param.p0;
    p1 = param.p1;
    p2 = param.p2;
    p3 = param.p3;
    p4 = param.sf;
    t1 = 0.169e3 / 0.32768e5 * p3;
    t2 = -0.795e3 / 0.32768e5 * p2;
    t3 = 0.2871e4 / 0.32768e5 * p0;
    t4 = 0.1851e4 / 0.32768e5 * p1;
    t5 = t4 + t3 + t2 + t1;
    t1 = (t4 + t3 + t2 + t1) * p4;
    t2 = 0.247e3 / 0.2048e4 * p0;
    t3 = 0.25e2 / 0.2048e4 * p3;
    t4 = -0.123e3 / 0.2048e4 * p2;
    t6 = 0.363e3 / 0.2048e4 * p1;
    t7 = t6 + t4 + t2 + t3;
    t2 = (t6 + t4 + t2 + t3) * p4;
    t3 = -0.2187e4 / 0.32768e5 * p2;
    t4 = 0.4071e4 / 0.32768e5 * p0;
    t6 = 0.9963e4 / 0.32768e5 * p1;
    t8 = 0.441e3 / 0.32768e5 * p3;
    t9 = t8 + t6 + t3 + t4;
    t3 = (t8 + t6 + t3 + t4) * p4;
    t4 = p3 / 128;
    t6 = 0.51e2 / 0.128e3 * p1;
    t8 = -0.3e1 / 0.128e3 * p2;
    t10 = 0.15e2 / 0.128e3 * p0;
    t11 = t6 + t8 + t10 + t4;
    t4 = (t6 + t8 + t10 + t4) * p4;
    t6 = 0.25e2 / 0.32768e5 * p3;
    t8 = 0.14475e5 / 0.32768e5 * p1;
    t10 = 0.2325e4 / 0.32768e5 * p2;
    t12 = 0.3655e4 / 0.32768e5 * p0;
    t13 = t10 + t12 + t6 + t8;
    t6 = (t10 + t12 + t6 + t8) * p4;
    t8 = 0.231e3 / 0.2048e4 * p0;
    t10 = 0.9e1 / 0.2048e4 * p3;
    t12 = 0.891e3 / 0.2048e4 * p1;
    t14 = 0.405e3 / 0.2048e4 * p2;
    t15 = t12 + t14 + t10 + t8;
    t8 = (t12 + t14 + t10 + t8) * p4;
    t10 = 0.10437e5 / 0.32768e5 * p2;
    t12 = 0.13083e5 / 0.32768e5 * p1;
    t14 = 0.3927e4 / 0.32768e5 * p0;
    t16 = 0.1225e4 / 0.32768e5 * p3;
    t17 = t16 + t10 + t12 + t14;
    t10 = (t16 + t10 + t12 + t14) * p4;
    t12 = p0 + p3;
    t14 = p1 + p2;
    t16 = 0.3e1 / 0.8e1 * t14 + t12 / 8;
    t12 = 0.3e1 / 0.8e1 * p4 * t14 + p4 * t12 / 8;
    t14 = -4;
    t18 = -2;
    t19 = 0.1e1 / 0.3e1;
    t20 = 0.1e1 / 0.6e1;
    f = t19 * (t5 * cos(t1) + t9 * cos(t3) + t13 * cos(t6) + t17 * cos(t10)) +
        t20 * (t7 * cos(t2) + t11 * cos(t4) + t15 * cos(t8)) +
        p4 * (-pow(t16, 2) * sin(t12) +
              t14 * (pow(t5, 2) * sin(t1) + pow(t9, 2) * sin(t3) +
                     pow(t13, 2) * sin(t6) + pow(t17, 2) * sin(t10)) +
              t18 * (pow(t7, 2) * sin(t2) + pow(t11, 2) * sin(t4) +
                     pow(t15, 2) * sin(t8))) /
                24 +
        t16 * cos(t12) / 12;
    return (f);
}

double SE2Constraints::dtd11(ParamKnot param) {
    // Don't use param here, but provided for consistency
    (void)param;
    return (0.0);
}

double SE2Constraints::dtd21(ParamKnot param) {
    // Don't use param here, but provided for consistency
    (void)param;
    return (0.0);
}

double SE2Constraints::dtd22(ParamKnot param) {
    // Don't use param here, but provided for consistency
    (void)param;
    return (0.0);
}

double SE2Constraints::dtd31(ParamKnot param) {
    // Don't use param here, but provided for consistency
    (void)param;
    return (0.0);
}

double SE2Constraints::dtd32(ParamKnot param) {
    // Don't use param here, but provided for consistency
    (void)param;
    return (0.0);
}

double SE2Constraints::dtd33(ParamKnot param) {
    // Don't use param here, but provided for consistency
    (void)param;
    return (0.0);
}

double SE2Constraints::dtd41(ParamKnot param) {
    // Don't use param here, but provided for consistency
    (void)param;
    return (0.3e1 / 0.8e1);
}

double SE2Constraints::dtd42(ParamKnot param) {
    // Don't use param here, but provided for consistency
    (void)param;
    return (0.3e1 / 0.8e1);
}

double SE2Constraints::dtd43(ParamKnot param) {
    // Don't use param here, but provided for consistency
    (void)param;
    return (0.1e1 / 0.8e1);
}

double SE2Constraints::dtd44(ParamKnot param) {
    // Don't use param here, but provided for consistency
    (void)param;
    return (0.0);
}
}  // namespace hmpl
