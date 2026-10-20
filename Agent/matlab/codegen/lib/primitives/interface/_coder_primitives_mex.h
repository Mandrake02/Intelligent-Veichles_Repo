/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_primitives_mex.h
 *
 * MATLAB Coder version            : 26.2
 * C/C++ source code generated on  : 20-Oct-2026 17:25:28
 */

#ifndef _CODER_PRIMITIVES_MEX_H
#define _CODER_PRIMITIVES_MEX_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void unsafe_a_opt_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                              const mxArray *prhs[7]);

void unsafe_coef_list_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                  const mxArray *prhs[6]);

void unsafe_j_opt_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                              const mxArray *prhs[7]);

void unsafe_s_opt_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                              const mxArray *prhs[7]);

void unsafe_student_pass_primitive_j0_mexFunction(int32_T nlhs,
                                                  mxArray *plhs[3],
                                                  int32_T nrhs,
                                                  const mxArray *prhs[5]);

void unsafe_student_pass_primitive_mexFunction(int32_T nlhs, mxArray *plhs[6],
                                               int32_T nrhs,
                                               const mxArray *prhs[7]);

void unsafe_student_stop_primitive_j0_mexFunction(int32_T nlhs,
                                                  mxArray *plhs[3],
                                                  int32_T nrhs,
                                                  const mxArray *prhs[2]);

void unsafe_student_stop_primitive_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                               int32_T nrhs,
                                               const mxArray *prhs[3]);

void unsafe_total_cost_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                   const mxArray *prhs[6]);

void unsafe_v_opt_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                              const mxArray *prhs[7]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_primitives_mex.h
 *
 * [EOF]
 */
