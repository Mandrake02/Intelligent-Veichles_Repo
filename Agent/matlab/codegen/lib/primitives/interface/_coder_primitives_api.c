/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_primitives_api.c
 *
 * MATLAB Coder version            : 26.2
 * C/C++ source code generated on  : 21-Oct-2026 13:01:53
 */

/* Include Files */
#include "_coder_primitives_api.h"
#include "_coder_primitives_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131691U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "primitives",                                         /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *b_emlrt_marshallOut(const real_T u);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void emlrtExitTimeCleanupDtorFcn(void *r);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier);

static const mxArray *emlrt_marshallOut(real_T u[6]);

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : void *r
 * Return Type  : void
 */
static void emlrtExitTimeCleanupDtorFcn(void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : real_T u[6]
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(real_T u[6])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {1, 6};
  const mxArray *m;
  const mxArray *y;
  void *existingData;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  existingData = emlrtMxGetData((mxArray *)m);
  if (existingData != (void *)&u[0]) {
    emlrtFreeMex(existingData);
  }
  emlrtMxSetData((mxArray *)m, &u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const mxArray * const prhs[7]
 *                const mxArray **plhs
 * Return Type  : void
 */
void a_opt_api(const mxArray *const prhs[7], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T a0;
  real_T af;
  real_T sf;
  real_T t;
  real_T tf;
  real_T v0;
  real_T vf;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  t = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "t");
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "v0");
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "a0");
  sf = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "sf");
  vf = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "vf");
  af = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "af");
  tf = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "tf");
  /* Invoke the target function */
  t = a_opt(t, v0, a0, sf, vf, af, tf);
  /* Marshall function outputs */
  *plhs = b_emlrt_marshallOut(t);
}

/*
 * Arguments    : const mxArray * const prhs[6]
 *                const mxArray **plhs
 * Return Type  : void
 */
void coef_list_api(const mxArray *const prhs[6], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*coef_list_var)[6];
  real_T a0;
  real_T af;
  real_T sf;
  real_T tf;
  real_T v0;
  real_T vf;
  st.tls = emlrtRootTLSGlobal;
  coef_list_var = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  /* Marshall function inputs */
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "v0");
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "a0");
  sf = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "sf");
  vf = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "vf");
  af = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "af");
  tf = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "tf");
  /* Invoke the target function */
  coef_list(v0, a0, sf, vf, af, tf, *coef_list_var);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(*coef_list_var);
}

/*
 * Arguments    : const mxArray * const prhs[7]
 *                const mxArray **plhs
 * Return Type  : void
 */
void j_opt_api(const mxArray *const prhs[7], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T a0;
  real_T af;
  real_T sf;
  real_T t;
  real_T tf;
  real_T v0;
  real_T vf;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  t = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "t");
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "v0");
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "a0");
  sf = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "sf");
  vf = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "vf");
  af = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "af");
  tf = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "tf");
  /* Invoke the target function */
  t = j_opt(t, v0, a0, sf, vf, af, tf);
  /* Marshall function outputs */
  *plhs = b_emlrt_marshallOut(t);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void primitives_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtPushHeapReferenceStackR2021a(
      &st, false, NULL, (void *)&emlrtExitTimeCleanupDtorFcn, NULL, NULL, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  primitives_xil_terminate();
  primitives_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void primitives_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void primitives_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * Arguments    : const mxArray * const prhs[7]
 *                const mxArray **plhs
 * Return Type  : void
 */
void s_opt_api(const mxArray *const prhs[7], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T a0;
  real_T af;
  real_T sf;
  real_T t;
  real_T tf;
  real_T v0;
  real_T vf;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  t = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "t");
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "v0");
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "a0");
  sf = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "sf");
  vf = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "vf");
  af = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "af");
  tf = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "tf");
  /* Invoke the target function */
  t = s_opt(t, v0, a0, sf, vf, af, tf);
  /* Marshall function outputs */
  *plhs = b_emlrt_marshallOut(t);
}

/*
 * Arguments    : const mxArray * const prhs[7]
 *                int32_T nlhs
 *                const mxArray *plhs[6]
 * Return Type  : void
 */
void student_pass_primitive_api(const mxArray *const prhs[7], int32_T nlhs,
                                const mxArray *plhs[6])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*coeffsT1)[6];
  real_T(*coeffsT2)[6];
  real_T T1;
  real_T T2;
  real_T Tmax;
  real_T Tmin;
  real_T a0;
  real_T sf;
  real_T v0;
  real_T v1;
  real_T v2;
  real_T vfmax;
  real_T vfmin;
  st.tls = emlrtRootTLSGlobal;
  coeffsT2 = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  coeffsT1 = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  /* Marshall function inputs */
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "v0");
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "a0");
  sf = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "sf");
  vfmin = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "vfmin");
  vfmax = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "vfmax");
  Tmin = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "Tmin");
  Tmax = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "Tmax");
  /* Invoke the target function */
  student_pass_primitive(v0, a0, sf, vfmin, vfmax, Tmin, Tmax, *coeffsT2, &v2,
                         &T2, *coeffsT1, &v1, &T1);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*coeffsT2);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(v2);
  }
  if (nlhs > 2) {
    plhs[2] = b_emlrt_marshallOut(T2);
  }
  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(*coeffsT1);
  }
  if (nlhs > 4) {
    plhs[4] = b_emlrt_marshallOut(v1);
  }
  if (nlhs > 5) {
    plhs[5] = b_emlrt_marshallOut(T1);
  }
}

/*
 * Arguments    : const mxArray * const prhs[5]
 *                int32_T nlhs
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void student_pass_primitive_j0_api(const mxArray *const prhs[5], int32_T nlhs,
                                   const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*coefsj0)[6];
  real_T a0;
  real_T sf;
  real_T tfj0;
  real_T v0;
  real_T vfj0;
  real_T vfmax;
  real_T vfmin;
  st.tls = emlrtRootTLSGlobal;
  coefsj0 = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  /* Marshall function inputs */
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "v0");
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "a0");
  sf = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "sf");
  vfmin = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "vfmin");
  vfmax = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "vfmax");
  /* Invoke the target function */
  student_pass_primitive_j0(v0, a0, sf, vfmin, vfmax, *coefsj0, &vfj0, &tfj0);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*coefsj0);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(vfj0);
  }
  if (nlhs > 2) {
    plhs[2] = b_emlrt_marshallOut(tfj0);
  }
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                int32_T nlhs
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void student_stop_primitive_api(const mxArray *const prhs[3], int32_T nlhs,
                                const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*coefs)[6];
  real_T a0;
  real_T maxsf;
  real_T sf;
  real_T tf;
  real_T v0;
  st.tls = emlrtRootTLSGlobal;
  coefs = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  /* Marshall function inputs */
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "v0");
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "a0");
  sf = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "sf");
  /* Invoke the target function */
  student_stop_primitive(v0, a0, sf, *coefs, &maxsf, &tf);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*coefs);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(maxsf);
  }
  if (nlhs > 2) {
    plhs[2] = b_emlrt_marshallOut(tf);
  }
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                int32_T nlhs
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void student_stop_primitive_j0_api(const mxArray *const prhs[2], int32_T nlhs,
                                   const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*coefsj0)[6];
  real_T a0;
  real_T sfj0;
  real_T tfj0;
  real_T v0;
  st.tls = emlrtRootTLSGlobal;
  coefsj0 = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  /* Marshall function inputs */
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "v0");
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "a0");
  /* Invoke the target function */
  student_stop_primitive_j0(v0, a0, *coefsj0, &sfj0, &tfj0);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*coefsj0);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(sfj0);
  }
  if (nlhs > 2) {
    plhs[2] = b_emlrt_marshallOut(tfj0);
  }
}

/*
 * Arguments    : const mxArray * const prhs[6]
 *                const mxArray **plhs
 * Return Type  : void
 */
void total_cost_api(const mxArray *const prhs[6], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T a0;
  real_T af;
  real_T sf;
  real_T tf;
  real_T v0;
  real_T vf;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "v0");
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "a0");
  sf = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "sf");
  vf = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "vf");
  af = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "af");
  tf = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "tf");
  /* Invoke the target function */
  v0 = total_cost(v0, a0, sf, vf, af, tf);
  /* Marshall function outputs */
  *plhs = b_emlrt_marshallOut(v0);
}

/*
 * Arguments    : const mxArray * const prhs[7]
 *                const mxArray **plhs
 * Return Type  : void
 */
void v_opt_api(const mxArray *const prhs[7], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T a0;
  real_T af;
  real_T sf;
  real_T t;
  real_T tf;
  real_T v0;
  real_T vf;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  t = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "t");
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "v0");
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "a0");
  sf = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "sf");
  vf = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "vf");
  af = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "af");
  tf = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "tf");
  /* Invoke the target function */
  t = v_opt(t, v0, a0, sf, vf, af, tf);
  /* Marshall function outputs */
  *plhs = b_emlrt_marshallOut(t);
}

/*
 * File trailer for _coder_primitives_api.c
 *
 * [EOF]
 */
