/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: primitives.h
 *
 * MATLAB Coder version            : 26.2
 * C/C++ source code generated on  : 16-Oct-2026 21:31:16
 */

#ifndef PRIMITIVES_H
#define PRIMITIVES_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern double a_opt(double t, double v0, double a0, double sf, double vf,
                    double af, double tf);

extern void coef_list(double v0, double a0, double sf, double vf, double af,
                      double tf, double coef_list_var[6]);

extern double j_opt(double t, double v0, double a0, double sf, double vf,
                    double af, double tf);

extern void primitives_initialize(void);

extern void primitives_terminate(void);

extern double s_opt(double t, double v0, double a0, double sf, double vf,
                    double af, double tf);

extern void student_pass_primitive(double v0, double a0, double sf,
                                   double vfmin, double vfmax, double Tmin,
                                   double Tmax, double coeffsT2[6], double *v2,
                                   double *T2, double coeffsT1[6], double *v1,
                                   double *T1);

extern void student_stop_primitive(double v0, double a0, double sf,
                                   double coefs[6], double *maxsf, double *tf);

extern double total_cost(double v0, double a0, double sf, double vf, double af,
                         double tf);

extern double v_opt(double t, double v0, double a0, double sf, double vf,
                    double af, double tf);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for primitives.h
 *
 * [EOF]
 */
