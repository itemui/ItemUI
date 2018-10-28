#include <iostream>
using namespace std;
// data from user

extern double D_User, H, H_td_user, H_tt_user, H_Norm_user, H_Seis_user, G, Gw, T, MDMT, P, Po_user,
Pe, Fp, Fpe, CA_Bot, CA_Roof, JE_user, CA_FR, Wt_Roof_Str_user,
kz_user, kzt_user, kd_user, basic_v_user, imp_factorW_user, gust_factor_user, V_user,
S0_user, Ss_user, S1_user, Fa_user, Fv_user, Factor_Q, TL_user, K_user,
shell_detail_user[15][5],
stfr_detail_user[45][2],
Spacing_Top_WG_User, PWG_width_min_user,
R_Roof_user, live_load_user, snow_load_bal, snow_load_unbal, roof_slope_user, dome_radius_user, JE_roof_user, Roof_Thk_user;

extern int D_Type, Option_P, Shell_Appendx_No_user, Roof_Type_No_user, FR_Type_No, Shell_Des_Method_No, RoundUP_to, option_Stfr,
wind_design_code, wind_exp_cat, Seismic_design_code, Zone_Number, site_class, ASCE_rule, SUG, option_Av, Shell_Material_No[15][3],
Option_walkway, curb_angle_No_user, Option_PWG, stfr_Mat_No[45], stfr_Sec_No[45][2], No_of_Stiffeners_Max_user, option_frangible_roof, Roof_Material_No, option_annularPlate;


extern string File_name;



// other variables used

extern double	D_Previous, D, Min_Nom_Thk, Min_Nom_Thk_1, t_uniform, tu_min_W, tu_min_Pe, tu_min, H_Max_W, H_Max_Ps, H_Max, Fy_Shell, H_Top, Spacing_Min, N_Sqr,
Spacing_Top_WG_Tr, kz, kzt, kd, basic_v, imp_factorW, gust_factor, wind_pressure, V, live_load, roof_slope, dome_radius,
roof_thk_user, roof_thk, JE_roof, R_Roof, Roof_Material_YS, Roof_Material_SA, Roof_Material_Y_mod, Roof_Material_Y_mod_Atm, Wt_FR, Wt_Roof_Str_defaut,
Wt_Roof_Str, Roof_thk_reqd, weight_Roof_Plate, weight_Roof_Plate_cor, theeta, Roof_Thk[10], Rafter_spacing, Rafter_spacing_cent,
dead_load, dead_load_cor, ext_load, ext_load_bal, ext_load_unbal, total_load_bal, total_load_unbal, H_td_default, H_td, H_tt_default, H_tt, H_Norm_default,
H_Norm, H_Seis_default, H_Seis, JE, Po_default, Po, S0, Ss, S1, imp_factorS, Fa_default, Fa, Fv_default, Fv, TL, K, Sds, Sd1, Av, Spacing_Top_WG, PWG_width_min,
PWG_width, YS, YS_Atm, UTS, Sd, Sd_Atm, St, Group_No, Psi, W, Ps, H_Ts, H_Avg, H_High, H_Low, New_Spacing, Y_Mod, Y_Mod_Atm, Y_mod, Y_mod_Atm,
Factor_M, Factor_M1, ring_area, ring_CG, ring_MOI, stfr_area, stfr_MOI, stfr_Sec_Mod, web_width, web_thk, flng_width, flng_thk,
Weight_FR, weight[20], density_steel, cg_shell, Thk_AnnPlate[4];

extern string Roof_Type, Roof_Type_user, FR_Type, Shell_Appendx, Shell_Appendx_user, Shell_Des_Method, MOC;

extern int  Shell_Appendx_No, Roof_Type_No, No_of_ShellCourses, Apndx_C_MOC, Print_x, Option_walkwayG, No_of_Stiffeners, No_of_Stiffeners_R,
No_of_Stiffeners_P, No_of_Stiffeners_Max, stfr_location[45][5], AnnPlate_req[3], edit_option;

extern double shell_detail[15][30], Y_Mod_X[15][3], user_EL_detail[45][11], stfr_Prop_user[45][4], stfr_detail[45][80], PWG_details[20], comp_ring_detail[10];

extern double PI;


extern string Roof_Material_Name, Shell_Material_Name[15][2], Stfnr_Material_Name[45], Stfnr_Section[45][3], Type_Stfr[45][3], Curb_angle_default, Curb_angle_user, ring_Name;
extern string Shell_appendx[8];
extern string Curb_angle;

// global variables of function CompRing_Data() & CompRing_Design()


extern double  CR_Material_YS[7], CR_Material_Y_mod[7], CR_Material_SA[7], CR_Area_rqd_SRR, CR_Area_rqd_P, CR_Area_rqd_V, CR_MOI_rqd, CR_fc;

extern int apndx_F, CR_Type_No[3], CR_Material_No[7], CR_Size[3];
extern string CompRing_Type[3], CompRing_size[3], CR_Material_Name[7];




extern double Rc_AB, Rc_COR, t_shell_AB, t_shell_COR, Wc_COR, Wc_AB, Wh_COR, Wh_AB, t_roof_AB, t_roof_COR, R2_COR, R2_AB;

extern double v_Leg_ht_AB, v_Leg_ht_COR, h_Leg_w_AB, h_Leg_w_COR, v_Leg_thk_AB, v_Leg_thk_COR, h_Leg_thk_AB, h_Leg_thk_COR, CR_Area_Available_AB, CR_Area_Available_COR;
extern string tempFileName;

extern double PWG_Width_Web, PWG_Width_Web_User, PWG_Thick_Web;
extern double PWG_Height_Flange;
extern double PWG_Thick_Flange;