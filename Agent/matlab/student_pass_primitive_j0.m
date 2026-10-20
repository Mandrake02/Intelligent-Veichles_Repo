%#codegen
%%
%          Agent Logic
%         Pass Primitive J0
%              2025
%
%
%%

function [coefsj0, vfj0, tfj0] = student_pass_primitive_j0( v0, a0, sf, vfmin, vfmax)
    T = final_opt_time_j0_pass(v0, a0, sf);
    T1 = T(1);
    v1 = final_opt_vel_j0_pass(v0, a0, sf, T1);
    if vfmin < v1 && v1 < vfmax 
        tfj0 = T1;
        vfj0 = v1;
        coefsj0 = coef_list(v0, a0, sf, vfj0, 0, tfj0);
    else
        T2 = T(2);
        v2 = final_opt_vel_j0_pass(v0, a0, sf, T2);
        if vfmin < v2 && v2 < vfmax
            tfj0 = T2;
            vfj0 = v2;
            coefsj0 = coef_list(v0, a0, sf, vfj0, 0, tfj0);
        else 
            tfj0 = 0;
            vfj0 = 0;
            coefsj0 = coef_list(0, 0, 0, 0, 0, 0);
        end
    end
end