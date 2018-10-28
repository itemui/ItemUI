#ifndef ITEM_HEADERS_H
#define ITEM_HEADERS_H

#include <iostream>
#include <string.h>

extern int diameterMappingFromUI[2];
extern int diameterMappingToUI[3];

extern int shellAppendixNoMappingFromUI[6];
extern int shellAppendixNoMappingToUI[8];

extern int shellCalcMethodMappingFromUI[2];
extern int shellCalcMethodMappingToUI[3];

extern int fixedRoofTypeMappingFromUI[8];
extern int fixedRoofTypeMappingToUI[9];

extern double windDataImpFactorMappingFromUI[2];

enum WindDataDesignCode {WND_DATA_DESIGN_CODE_ASCE_7_05 = 0, WND_DATA_DESIGN_CODE_ASCE_7_10, WND_DATA_DESIGN_CODE_USER_DEF};

struct InputData
{
    double D_User;
	double H;
	double H_td_user;
	double H_tt_user;
	double H_Norm_user;
	double H_Seis_user;
	double G;
	double Gw;
	double T;
	double MDMT;
	double P;
	double Fp;
	double Po_user;
	double Pe;
	double Fpe;
	double CA_Bot;
	double CA_Roof;
	double JE_user;
	double CA_FR;
	double kz_user;
	double kzt_user;
	double kd_user;
	double basic_v_user;
	double imp_factorW_user;
	double gust_factor_user;
	double V_user;
	double S0_user;
	double Ss_user;
	double S1_user;
	double Fa_user;
	double Fv_user;
	double Factor_Q;
	double TL_user;
	double K_user;
	double shell_detail_user[15][5];
	double stfr_detail_user[45][2];
	double firstCourse_UTS;
	double firstCourse_width;
//	double firstCourse_CA;
//	double firstCourse_Thk;

	double Spacing_Top_WG_User;
	double PWG_width_min_user;
	double Spacing_Top_WG;
	double PWG_width_min;
	int Option_PWG;
	//PWG
	double PWG_Width_Web;
	double PWG_Width_Web_User;
	double PWG_Thick_Web;
	double PWG_Height_Flange;
	double PWG_Thick_Flange;
	double PWG_details[20];

	double roof_slope_user;
	double dome_radius_user;
	double JE_roof_user;
	double Roof_Thk_user;
	double Roof_Thk[10];

	int D_Type;
	int Option_P;
	int Shell_Appendx_No_user;
	int Roof_Type_No_user;
	int Roof_Type_No;
	int Shell_Des_Method_No;
	int RoundUP_to;
	int option_Stfr ;
	int wind_design_code;
	int wind_exp_cat;
	int Seismic_design_code;
	int Zone_Number;
	int site_class;
	int ASCE_rule;
	int SUG;
	int option_Av;
	int Shell_Material_No[15][4];
	int Option_walkway;
	int curb_angle_No_user;
	
	int stfr_Mat_No[45];
	int stfr_Sec_No[45][3];


	int No_of_ShellCourses;
	int No_of_Stiffeners_R;
	int Shell_Appendx_No;

	double weight_stair_user;
	double weight_adder_user;

	double imp_factorS;
	double Sds;
	double Sd1;
	double Av;


	//Roof Data
	double R_Roof_user;
	double live_load_user;
	int option_frangible_roof;
	int FR_Type_No;
	int Roof_Material_No;
	double snow_load_bal;
	double snow_load_unbal;
	double Rafter_spacing;
	double Rafter_spacing_cent;
	double Weight_FR;
	double WeightAdder_roof_default;
	double WeightAdder_roof_user;
	double WeightAdder_roof;
	double weight_platform_default;
	double weight_platform_user;
	double weight_platform;
	int roof_slope_user_numerator;
	int roof_slope_user_denominator;
	double Wt_Roof_Str_defaut;
	double Wt_Roof_Str_user;
	double Wt_Roof_Str;

	//Roof to Shell
	int type_compression_ring;
	int CR_Type_No[2];
	int CR_Material_No[3];
	int CR_Size[3];
	double t_bar[3];
	double w_bar[3];
	double l_bar[3];
	double t_shell[3];
	double w_shell[3];

	//Stiffener Elevation
	int No_of_Stiffeners_Max_user;
	double H_Ts;
	double t_uniform;
	double H_Max_W;
	double H_Max_Ps;
	double user_EL_detail[45][11];
	double stfr_detail[45][80];

	
	//defined by Raghav
	double kz_default;
	double V_default;
	double Fa_default;
	double Fv_default;
	double D;
	double Gd;
	double JE;
	double Spacing_Min;

	//defined by Abhishek
	double H_Remaining;
	double stfr_Prop_user[45][4];

	//in new design file
	double JE_roof;
	double live_load;
	double R_Roof;
	double shell_detail[15][30];
	double Wt_Roof_Str_cor;
	double fraction_roof_weight;
	double Weight_FR_user;

	//int rowNum;

};

std::ostream& operator << (std::ostream &outStream, const InputData &outData);

#endif 

// ITEM_HEADERS_H

//D_User =
//H =
//H_td_user =
//H_tt_user =
//H_Norm_user =
//H_Seis_user =
//G =
//Gw =
//T =
//MDMT =
//P =
//Po_user =
//Pe =
//CA_Bot =
//CA_Roof =
//JE_user =
//CA_FR =
//Wt_Roof_Str_defau
//Wt_Roof_Str_user =
//Wt_Roof_Str =
//kz_user =
//kzt_user =
//kd_user =
//basic_v_user =
//imp_factorW_user =
//gust_factor_user =
//V_user =
//S0_user =
//Ss_user =
//S1_user =
//Fa_user =
//Fv_user =
//Factor_Q =
//TL_user =
//K_user =
//shell_detail_user
//stfr_detail_user
//Spacing_Top_WG_Us
//PWG_width_min_use
//R_Roof_user =
//live_load_user =
//snow_load_bal =
//snow_load_unbal =
//roof_slope_user =
//JE_roof_user =
//Roof_Thk_user =
