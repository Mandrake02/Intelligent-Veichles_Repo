%%
%           Agent Logic
%          Pass Primitive J0
%               2025
%
%
%% Pass primitive with j0 = 0 %%

%% Determine the optimal final velocity to pass function of j0 = 0 %%
syms v0 a0 sf vf tf z;
final_opt_vel_j0_pass_var = solve(j_opt(0, v0, a0, sf, vf, 0, tf) == 0, vf);
final_opt_vel_j0_pass_fun = matlabFunction(final_opt_vel_j0_pass_var,'Vars',[v0,a0,sf,tf],'File','final_opt_vel_j0_pass.m');
% - Use functions 'solve', 'diff', 'subs', and 'matlabFunction'

%% Determine the optimal time to reach to final velocity with j0 = 0 %%
final_opt_time_j0_pass_var = 1./solve(final_opt_time_pass(v0, a0, sf, subs(final_opt_vel_j0_pass_var, tf, 1/z)) == 1/z, z);
final_opt_time_j0_pass_fun = matlabFunction(final_opt_time_j0_pass_var,'Vars',[v0,a0,sf],'File','final_opt_time_j0_pass.m');
% - Use the function solve 
%   use the function final_opt_time_pass_fun
%   Use 'subs' function to solve the system using the frequency instead of the time
