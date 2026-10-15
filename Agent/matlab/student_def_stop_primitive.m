%%
%           Agent Logic
%         Stop Primitive
%              2025
%
%
%% Determine the optimal time to stop %%
syms z; % We create this variable for more stable solution of the equations
syms v0 a0 sf;

%% Symbolic definition of the optimal time to stop
%pretty(1./solve(diff(total_cost(v0, a0, sf, 0, 0, 1/z), z) == 0, z))
final_opt_time_stop_var = 1./solve(diff(total_cost(v0, a0, sf, 0, 0, 1/z), z) == 0, z);
final_opt_time_stop_var = final_opt_time_stop_var(1);
% - Use the function solve 
%   Use 'subs' function to solve the system using the frequency instead of the time

%% Export the solution in a matlab function
final_opt_time_stop_fun =  matlabFunction(final_opt_time_stop_var,'Vars',[v0,a0,sf],'File','final_opt_time_stop.m');