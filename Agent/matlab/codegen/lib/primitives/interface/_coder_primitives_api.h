/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_primitives_api.h
 *
 * MATLAB Coder version            : 26.2
 * C/C++ source code generated on  : 20-Oct-2026 11:52:32
 */

#ifndef _CODER_PRIMITIVES_API_H
#define _CODER_PRIMITIVES_API_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */

#ifdef __cplusplus
extern "C" {
#endif

extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
real_T a_opt(real_T t, real_T v0, real_T a0, real_T sf, real_T vf, real_T af,
             real_T tf);

void a_opt_api(const mxArray *const prhs[7], const mxArray **plhs);

void coef_list(real_T v0, real_T a0, real_T sf, real_T vf, real_T af, real_T tf,
               real_T coef_list_var[6]);

void coef_list_api(const mxArray *const prhs[6], const mxArray **plhs);

real_T j_opt(real_T t, real_T v0, real_T a0, real_T sf, real_T vf, real_T af,
             real_T tf);

void j_opt_api(const mxArray *const prhs[7], const mxArray **plhs);

void primitives_atexit(void);

void primitives_initialize(void);

void primitives_terminate(void);

void primitives_xil_shutdown(void);

void primitives_xil_terminate(void);

real_T s_opt(real_T t, real_T v0, real_T a0, real_T sf, real_T vf, real_T af,
             real_T tf);

void s_opt_api(const mxArray *const prhs[7], const mxArray **plhs);

void student_pass_primitive(real_T v0, real_T a0, real_T sf, real_T vfmin,
                            real_T vfmax, real_T Tmin, real_T Tmax,
                            real_T coeffsT2[6], real_T *v2, real_T *T2,
                            real_T coeffsT1[6], real_T *v1, real_T *T1);

void student_pass_primitive_api(const mxArray *const prhs[7], int32_T nlhs,
                                const mxArray *plhs[6]);

void student_pass_primitive_j0(real_T v0, real_T a0, real_T sf, real_T vfmin,
                               real_T vfmax, real_T coefsj0[6], real_T *vfj0,
                               real_T *tfj0);

void student_pass_primitive_j0_api(const mxArray *const prhs[5], int32_T nlhs,
                                   const mxArray *plhs[3]);

void student_stop_primitive(real_T v0, real_T a0, real_T sf, real_T coefs[6],
                            real_T *maxsf, real_T *tf);

void student_stop_primitive_api(const mxArray *const prhs[3], int32_T nlhs,
                                const mxArray *plhs[3]);

void student_stop_primitive_j0(real_T v0, real_T a0, real_T coefsj0[6],
                               real_T *sfj0, real_T *tfj0);

void student_stop_primitive_j0_api(const mxArray *const prhs[2], int32_T nlhs,
                                   const mxArray *plhs[3]);

real_T total_cost(real_T v0, real_T a0, real_T sf, real_T vf, real_T af,
                  real_T tf);

void total_cost_api(const mxArray *const prhs[6], const mxArray **plhs);

real_T v_opt(real_T t, real_T v0, real_T a0, real_T sf, real_T vf, real_T af,
             real_T tf);

void v_opt_api(const mxArray *const prhs[7], const mxArray **plhs);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_primitives_api.h
 *
 * [EOF]
 */
