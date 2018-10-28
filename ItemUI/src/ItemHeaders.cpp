#include "../include/ItemHeaders.h"

std::ostream& operator << (std::ostream &outStream, const InputData &outData)
{
	outStream << "Diameter " << outData.D_User << "\n";
	outStream << "Tank Height _H " << outData.H << "\n";
	outStream << "H_td_user " << outData.H_td_user << "\n";
	outStream << "H_tt_user " << outData.H_tt_user << "\n";
	outStream << "H_Norm_user " << outData.H_Norm_user << "\n";
	outStream << "H_Seis_user " << outData.H_Seis_user << "\n";
	outStream << "G " << outData.G << "\n";
	outStream << "Gw" << outData.Gw << "\n";
	outStream << " T " << outData.T << "\n";
	outStream << "MDMTeter " << outData.MDMT << "\n";
	outStream << "P " << outData.P << "\n";
	outStream << "Fp" << outData.Fp << "\n";
	outStream << "Po_user " << outData.Po_user << "\n";
	outStream << "Pe " << outData.Pe << "\n";
	outStream << "Fpe " << outData.Fpe << "\n";
	outStream << "CA_Bot " << outData.CA_Bot << "\n";
	outStream << "CA_Roof " << outData.CA_Roof << "\n";
	outStream << "JE_userr " << outData.JE_user << "\n";
	outStream << "CA_FR " << outData.CA_FR << "\n";
	outStream << "kz_user " << outData.kz_user << "\n";
	outStream << "kzt_user " << outData.kzt_user << "\n";
	outStream << "kd_user " << outData.kd_user << "\n";
	outStream << "basic_v_user " << outData.basic_v_user << "\n";
	outStream << "imp_factorW_user " << outData.imp_factorW_user << "\n";
	outStream << "gust_factor_user " << outData.gust_factor_user << "\n";
	outStream << "V_user " << outData.V_user << "\n";
	outStream << "S0_user " << outData.S0_user << "\n";
	outStream << "Ss_user " << outData.Ss_user << "\n";
	outStream << "S1_user " << outData.S1_user << "\n";
	outStream << "Fa_user " << outData.Fa_user << "\n";
	outStream << "Fv_user " << outData.Fv_user << "\n";
	outStream << "Factor_Q " << outData.Factor_Q << "\n";
	outStream << "TL_user " << outData.TL_user << "\n";
	outStream << "K_user " << outData.K_user << "\n";

	outStream << "firstCourse_UTS " << outData.firstCourse_UTS << "\n";
	outStream << "firstCourse_width " << outData.firstCourse_width << "\n";

	outStream << "Spacing_Top_WG_User " << outData.Spacing_Top_WG_User << "\n";
	outStream << "PWG_width_min_user " << outData.PWG_width_min_user << "\n";
	outStream << "Spacing_Top_WG " << outData.Spacing_Top_WG << "\n";
	outStream << "PWG_width_min " << outData.PWG_width_min << "\n";
	outStream << "Option_PWG " << outData.Option_PWG << "\n";
	//PWG
	outStream << " PWG_Width_Web " << outData.PWG_Width_Web << "\n";
	outStream << "PWG_Width_Web_User" << outData.PWG_Width_Web_User << "\n";
	outStream << "PWG_Thick_Web" << outData.PWG_Thick_Web << "\n";
	outStream << "PWG_Height_Flange" << outData.PWG_Height_Flange << "\n";
	outStream << " PWG_Thick_Flange " << outData.PWG_Thick_Flange << "\n";


	outStream << "roof_slope_user " << outData.roof_slope_user << "\n";
	outStream << "dome_radius_user " << outData.dome_radius_user << "\n";

	outStream << "JE_roof_user " << outData.JE_roof_user << "\n";
	outStream << "Roof_Thk_user " << outData.Roof_Thk_user << "\n";

	outStream << "D_Type" << outData.D_Type << "\n";
	outStream << "Option_P " << outData.Option_P << "\n";
	outStream << "Shell_Appendx_No_user" << outData.Shell_Appendx_No_user << "\n";
	outStream << "Roof_Type_No_user " << outData.Roof_Type_No_user << "\n";
	outStream << " Roof_Type_N " << outData.Roof_Type_No << "\n";
	outStream << "Shell_Des_Method_No" << outData.Shell_Des_Method_No << "\n";
	outStream << "RoundUP_to " << outData.RoundUP_to << "\n";
	outStream << "option_Stfr  " << outData.option_Stfr << "\n";
	outStream << "wind_design_code" << outData.wind_design_code << "\n";
	outStream << "out  wind_exp_cat " << outData.wind_exp_cat << "\n";
	outStream << "Seismic_design_code " << outData.Seismic_design_code << "\n";
	outStream << "Zone_Number" << outData.Zone_Number << "\n";
	outStream << "Zone_Number " << outData.Zone_Number << "\n";
	outStream << "ASCE_rule " << outData.ASCE_rule << "\n";
	outStream << "SUGser " << outData.SUG << "\n";
	outStream << "option_Av " << outData.option_Av << "\n";

	outStream << "Option_walkway " << outData.Option_walkway << "\n";
	outStream << "curb_angle_No_user" << outData.curb_angle_No_user << "\n";
	outStream << "No_of_ShellCourses " << outData.No_of_ShellCourses << "\n";
	outStream << "No_of_Stiffeners_R " << outData.No_of_Stiffeners_R << "\n";
	outStream << "Shell_Appendx_No " << outData.Shell_Appendx_No << "\n";

	outStream << "weight_stair_user " << outData.weight_stair_user << "\n";
	outStream << "weight_adder_user " << outData.weight_adder_user << "\n";

	outStream << " imp_factorS " << outData.imp_factorS << "\n";
	outStream << "Sds " << outData.Sds << "\n";
	outStream << "Sd1" << outData.Sd1 << "\n";
	outStream << "Av " << outData.Av << "\n";

	outStream << "R_Roof_user " << outData.R_Roof_user << "\n";
	outStream << "live_load_user " << outData.live_load_user << "\n";
	outStream << "option_frangible_roof " << outData.option_frangible_roof << "\n";
	outStream << "FR_Type_No " << outData.FR_Type_No << "\n";
	outStream << "Roof_Material_No " << outData.Roof_Material_No << "\n";
	outStream << "snow_load_bal " << outData.snow_load_bal << "\n";
	outStream << "snow_load_unbal " << outData.snow_load_unbal << "\n";
	outStream << "Rafter_spacing " << outData.Rafter_spacing << "\n";
	outStream << " Rafter_spacing_cent " << outData.Rafter_spacing_cent << "\n";
	outStream << "Weight_FR " << outData.Weight_FR << "\n";
	outStream << "WeightAdder_roof_default " << outData.WeightAdder_roof_default << "\n";
	outStream << "WeightAdder_roof_user " << outData.WeightAdder_roof_user << "\n";
	outStream << "WeightAdder_roof " << outData.WeightAdder_roof << "\n";
	outStream << " weight_platform_default" << outData.weight_platform_default << "\n";
	outStream << "weight_platform_user " << outData.weight_platform_user << "\n";
	outStream << "weight_platform " << outData.weight_platform << "\n";
	outStream << "roof_slope_user_numerator " << outData.roof_slope_user_numerator << "\n";
	outStream << "roof_slope_user_denominator " << outData.roof_slope_user_denominator << "\n";
	outStream << "Wt_Roof_Str_defaut " << outData.Wt_Roof_Str_defaut << "\n";
	outStream << "Wt_Roof_Str_user " << outData.Wt_Roof_Str_user << "\n";
	outStream << " Wt_Roof_Str " << outData.Wt_Roof_Str << "\n";

	outStream << "type_compression_ring " << outData.type_compression_ring << "\n";
	outStream << "CR_Type_No[0] " << outData.CR_Type_No[0] << "\n";
	outStream << "CR_Type_No[1] " << outData.CR_Type_No[1] << "\n";
	outStream << "CR_Material_No[0] " << outData.CR_Material_No[0] << "\n";
	outStream << "CR_Material_No[1]" << outData.CR_Material_No[1] << "\n";
	outStream << "CR_Material_No[2] " << outData.CR_Material_No[2] << "\n";

	outStream << "H_Ts " << outData.H_Ts << "\n";
	outStream << "t_uniform " << outData.t_uniform << "\n";
	outStream << "H_Max_W " << outData.H_Max_W << "\n";
	outStream << "H_Max_Ps " << outData.H_Max_Ps << "\n";

	//defined by Raghav
	outStream << "kz_default  " << outData.kz_default << "\n";
	outStream << " V_default  " << outData.V_default << "\n";
	outStream << "Fa_default " << outData.Fa_default << "\n";
	outStream << " Fv_default " << outData.Fv_default << "\n";
	outStream << "D " << outData.D << "\n";
	outStream << "Gd " << outData.Gd << "\n";
	outStream << "JE " << outData.JE << "\n";
	outStream << "Spacing_Min" << outData.Spacing_Min << "\n";

	//defined by Abhishek
	outStream << "H_Remaining " << outData.H_Remaining << "\n";


	//in new design file
	outStream << "JE_roof " << outData.JE_roof << "\n";
	outStream << "live_load " << outData.live_load << "\n";
	outStream << " R_Roof " << outData.R_Roof << "\n";

//	outStream << " CR_Size[3]  " << outData.CR_Size[3] << "\n";
//	outStream << "t_bar[3] " << outData.t_bar[3] << "\n";
//	outStream << " w_bar[3]  " << outData.w_bar[3] << "\n";
//	outStream << "l_bar[3] " << outData.l_bar[3] << "\n";
//	outStream << " t_shell[3]  " << outData.t_shell[3] << "\n";
//	outStream << "w_shell[3] " << outData.w_shell[3] << "\n";

// outStream << " shell_detail[15][30] "<<outData. shell_detail[15][30] <<"\n";
//	outStream << "shell_detail_user[15][5] " << outData.shell_detail_user[15][5 << "\n";
//	outStream << "Shell_Material_No[15][4] " << outData. Shell_Material_No[15][4] << "\n";

//	outStream << "stfr_detail[45][80]" << outData. << outData.stfr_detail[45][80] << "\n";
//	outStream << " stfr_detail_user[45][2] " << outData.stfr_detail_user[45][2] << "\n";
//	outStream << "stfr_Sec_No[45][2]  " << outData. stfr_Sec_No[45][2] << "\n";
//	outStream << "user_EL_detail[45][11] " << outData. user_EL_detail[45][11] << "\n";
//	outStream << "stfr_Prop_user[45][4]  " << outData.stfr_Prop_user[45][4] << "\n";

//	outStream << "PWG_details[20] " << outData.PWG_details[20] << "\n";
//	outStream << "stfr_Mat_No[45] " << outData.stfr_Mat_No[45] << "\n";



	for (int i = 0; i <= 2; i++)

	{

		outStream << " CR_Size[i]  " << outData.CR_Size[i] << "\n";
		outStream << "t_bar[i] " << outData.t_bar[i] << "\n";
		outStream << " w_bar[i]  " << outData.w_bar[i] << "\n";
		outStream << "l_bar[i] " << outData.l_bar[i] << "\n";
		outStream << " t_shell[i]  " << outData.t_shell[i] << "\n";
		outStream << "w_shell[i] " << outData.w_shell[i] << "\n";

	}






	for (int i = 0; i <= (outData.No_of_ShellCourses-1); i++)

	{
		for (int j = 0; j <= 29; j++)

		{

			outStream << " shell_detail[i][j] " << outData.shell_detail[i][j] << "\n";

		}

	}




	for (int i = 0; i <= (outData.No_of_ShellCourses-1); i++)

	{
		for (int j = 0; j <= 4; j++)

		{

			outStream << "shell_detail_user[i][j] " << outData.shell_detail_user[i][j] << "\n";

		}

	}


	for (int i = 0; i <= (outData.No_of_ShellCourses-1); i++)

	{
		for (int j = 0; j <= 3; j++)

		{

			outStream << "Shell_Material_No[i][j] " << outData.Shell_Material_No[i][j] << "\n";

		}

	}

	for (int i = 0; i <= (outData.No_of_Stiffeners_R-1); i++)

	{
		for (int j = 0; j <= 79; j++)

		{

			outStream << "stfr_detail[i][j]" << outData.stfr_detail[i][j] << "\n";

		}

	}








	for (int i = 0; i <= (outData.No_of_Stiffeners_R-1); i++)

	{
		for (int j = 0; j <= 1; j++)

		{

			outStream << "stfr_Sec_No[i][j]" << outData.stfr_Sec_No[i][j] << "\n";
			outStream << " stfr_detail_user[ i][j] " << outData.stfr_detail_user[i][j] << "\n";

		}

	}





	for (int i = 0; i <= (outData.No_of_Stiffeners_R-1); i++)

	{
		for (int j = 0; j <= 10; j++)

		{

			outStream << "user_EL_detail[i][j]" << outData.user_EL_detail[i][j] << "\n";

		}

	}



	for (int i = 0; i <= (outData.No_of_Stiffeners_R-1); i++)

	{
		for (int j = 0; j <= 1; j++)

		{

			outStream << " stfr_detail_user[i][j] " << outData.stfr_detail_user[i][j] << "\n";

		}

	}



	for (int i = 0; i <= (outData.No_of_Stiffeners_R-1); i++)

	{
		for (int j = 0; j <= 3; j++)

		{
			outStream << "stfr_Prop_user[i][j]" << outData.stfr_Prop_user[i][j]<<" ";
		}
		outStream<<"\n";
	}




	for (int i = 0; i <= (outData.No_of_Stiffeners_R-1); i++)

	{

		outStream << "stfr_Mat_No[i] " << outData.stfr_Mat_No[i] << "\n";
	}




	for (int i = 0; i <= 19; i++)

	{

		outStream << "PWG_details[i] " << outData.PWG_details[i] << "\n";
	}
}
