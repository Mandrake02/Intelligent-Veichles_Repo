%#codegen
%%
%          Agent Logic
%         Stop Primitive
%              2025
%
%
%%

function [coefs,maxsf,tf] = student_stop_primitive(v0,a0,sf)
 if v0 <= 0 || sf == 0
     maxsf = 0;
     tf = 0;
     coefs = zeros(1, 6);
     return;
 end
 if 4*v0^2 + 5*a0*sf < 0
    maxsf = (-4 * v0^2)/(5 * a0);
    tf = (10 * maxsf)/(2*v0);
 else 
     maxsf = sf;
     tf = final_opt_time_stop(v0, a0, maxsf);
 end
 coefs = coef_list(v0, a0, maxsf, 0, 0, tf);
end