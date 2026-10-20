/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 26.2
 * C/C++ source code generated on  : 20-Oct-2026 11:52:32
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "primitives.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static double argInit_real_T(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* Initialize the application.
You do not need to do this more than one time. */
  primitives_initialize();
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_student_pass_primitive();
  main_student_stop_primitive();
  main_v_opt();
  main_s_opt();
  main_a_opt();
  main_j_opt();
  main_total_cost();
  main_coef_list();
  main_student_stop_primitive_j0();
  main_student_pass_primitive_j0();
  /* Terminate the application.
You do not need to do this more than one time. */
  primitives_terminate();
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_a_opt(void)
{
  double t_tmp;
  /* Initialize function 'a_opt' input arguments. */
  t_tmp = argInit_real_T();
  /* Call the entry-point 'a_opt'. */
  t_tmp = a_opt(t_tmp, t_tmp, t_tmp, t_tmp, t_tmp, t_tmp, t_tmp);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_coef_list(void)
{
  double coef_list_var[6];
  double v0_tmp;
  /* Initialize function 'coef_list' input arguments. */
  v0_tmp = argInit_real_T();
  /* Call the entry-point 'coef_list'. */
  coef_list(v0_tmp, v0_tmp, v0_tmp, v0_tmp, v0_tmp, v0_tmp, coef_list_var);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_j_opt(void)
{
  double t_tmp;
  /* Initialize function 'j_opt' input arguments. */
  t_tmp = argInit_real_T();
  /* Call the entry-point 'j_opt'. */
  t_tmp = j_opt(t_tmp, t_tmp, t_tmp, t_tmp, t_tmp, t_tmp, t_tmp);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_s_opt(void)
{
  double t_tmp;
  /* Initialize function 's_opt' input arguments. */
  t_tmp = argInit_real_T();
  /* Call the entry-point 's_opt'. */
  t_tmp = s_opt(t_tmp, t_tmp, t_tmp, t_tmp, t_tmp, t_tmp, t_tmp);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_student_pass_primitive(void)
{
  double coeffsT1[6];
  double coeffsT2[6];
  double T1;
  double T2;
  double v0_tmp;
  double v1;
  double v2;
  /* Initialize function 'student_pass_primitive' input arguments. */
  v0_tmp = argInit_real_T();
  /* Call the entry-point 'student_pass_primitive'. */
  student_pass_primitive(v0_tmp, v0_tmp, v0_tmp, v0_tmp, v0_tmp, v0_tmp, v0_tmp,
                         coeffsT2, &v2, &T2, coeffsT1, &v1, &T1);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_student_pass_primitive_j0(void)
{
  double coefsj0[6];
  double tfj0;
  double v0_tmp;
  double vfj0;
  /* Initialize function 'student_pass_primitive_j0' input arguments. */
  v0_tmp = argInit_real_T();
  /* Call the entry-point 'student_pass_primitive_j0'. */
  student_pass_primitive_j0(v0_tmp, v0_tmp, v0_tmp, v0_tmp, v0_tmp, coefsj0,
                            &vfj0, &tfj0);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_student_stop_primitive(void)
{
  double coefs[6];
  double maxsf;
  double tf;
  double v0_tmp;
  /* Initialize function 'student_stop_primitive' input arguments. */
  v0_tmp = argInit_real_T();
  /* Call the entry-point 'student_stop_primitive'. */
  student_stop_primitive(v0_tmp, v0_tmp, v0_tmp, coefs, &maxsf, &tf);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_student_stop_primitive_j0(void)
{
  double coefsj0[6];
  double sfj0;
  double tfj0;
  double v0_tmp;
  /* Initialize function 'student_stop_primitive_j0' input arguments. */
  v0_tmp = argInit_real_T();
  /* Call the entry-point 'student_stop_primitive_j0'. */
  student_stop_primitive_j0(v0_tmp, v0_tmp, coefsj0, &sfj0, &tfj0);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_total_cost(void)
{
  double v0_tmp;
  /* Initialize function 'total_cost' input arguments. */
  v0_tmp = argInit_real_T();
  /* Call the entry-point 'total_cost'. */
  v0_tmp = total_cost(v0_tmp, v0_tmp, v0_tmp, v0_tmp, v0_tmp, v0_tmp);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_v_opt(void)
{
  double t_tmp;
  /* Initialize function 'v_opt' input arguments. */
  t_tmp = argInit_real_T();
  /* Call the entry-point 'v_opt'. */
  t_tmp = v_opt(t_tmp, t_tmp, t_tmp, t_tmp, t_tmp, t_tmp, t_tmp);
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
