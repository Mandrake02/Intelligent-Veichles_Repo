%%
%           Agent Logic
%         Stop Primitive J0
%              2025
%
%
%% Stop primitive with j0 = 0 %%

%% Determine the optimal final position imposing j0 %%
syms v0 a0 sf tf;
final_opt_pos_j0_var = solve(j_opt(0, v0, a0, sf, 0, 0, tf) == 0, sf);
final_opt_pos_j0_fun = matlabFunction(final_opt_pos_j0_var,'Vars',[v0,a0,tf],'File','final_opt_pos_j0.m');
% - Use functions 'solve', 'diff', 'subs', and 'matlabFunction'

%% Determine the optimal time to stop with j0 = 0 %%
final_opt_time_stop_j0_var = solve(final_opt_time_stop(v0, a0, final_opt_pos_j0_var) == tf, tf);
final_opt_time_stop_j0_var = final_opt_time_stop_j0_var(2);
final_opt_time_stop_j0_fun = matlabFunction(final_opt_time_stop_j0_var,'Vars',[v0,a0],'File','final_opt_time_stop_j0.m');
% - Use the function solve  
%   Use the function final_opt_time_stop_fun 
%   Use 'subs' function to solve the system using the frequency instead of the time

