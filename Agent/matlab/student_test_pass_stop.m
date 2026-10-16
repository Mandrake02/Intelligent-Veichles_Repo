%% Test pass primitive
[coefsT2, v2, T2, coefsT1, v1, T1] = student_pass_primitive(1., 1., 10., 10., 12., 1., 100.);

%% Test stop primitive
[coefs, xf, tf] = student_stop_primitive(5., 10., 10.);