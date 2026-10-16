%%
%           Agent Logic
%         Pass Primitive
%              2025
%
%
%% Determine the optimal final velocity to pass
syms v0 a0 sf vf tf; % We create this variable for more stable solution of the equations

final_opt_vel_pass_var = solve(diff(total_cost(v0, a0, sf, vf, 0, tf),vf) == 0, vf);
final_opt_vel_pass_fun = matlabFunction(final_opt_vel_pass_var,'Vars',[v0,a0,sf,tf],'File','final_opt_vel_pass.m');
% - Use functions 'solve', 'diff', 'subs', and 'matlabFunction'

%% Determine the optimal time to reach to final velocity
syms z; % We create this variable for more stable solution of the equations

final_opt_time_pass_var = 1./solve(subs(final_opt_vel_pass_var,tf,1/z)==vf,z);
final_opt_time_pass_var = final_opt_time_pass_var(2);
final_opt_time_pass_fun = matlabFunction(final_opt_time_pass_var,'Vars',[v0,a0,sf,vf],'File','final_opt_time_pass.m');
% - Use the function solve 
%   Use 'subs' function to solve the system using the frequency instead of the time

%% Determine the time to reach the minimum velocity
assume(a0 < 0)
assume(sf > 0)
time_min_vel_var = solve(diff(final_opt_vel_pass_var, tf) == 0, tf);
time_min_vel_var = time_min_vel_var(1);
vel_min_vel_var = simplify(subs(final_opt_vel_pass_var, tf, time_min_vel_var));
assume(a0, 'clear');
assume(sf, 'clear');
time_min_vel_fun = matlabFunction(time_min_vel_var,'Vars',[a0,sf],'File','time_min_vel.m');
vel_min_vel_fun = matlabFunction(vel_min_vel_var,'Vars',[v0,a0,sf],'File','vel_min_vel.m');
% - Use functions 'solve', 'diff', 'subs', and 'matlabFunction'
