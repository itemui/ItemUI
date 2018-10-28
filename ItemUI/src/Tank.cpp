#include <iostream>
#include <iomanip> // for set precission
#include <math.h>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include "../include/ItemHeaders.h"
using namespace std;

//using namespace System; // This is to be struckout in Cold Blocks



// data from user

double D_User, H, H_td_user, H_tt_user, H_Norm_user, H_Seis_user, G, Gw, T, MDMT, P, Po_user,
Pe, Fp, Fpe, CA_Bot, CA_Roof, JE_user, CA_FR, Wt_Roof_Str_user,
kz_user, kzt_user, kd_user, basic_v_user, imp_factorW_user, gust_factor_user, V_user,
S0_user, Ss_user, S1_user, Fa_user, Fv_user, Factor_Q, TL_user, K_user,
shell_detail_user[15][5], weight_stair_user, weight_adder_user,
stfr_detail_user[45][2],
Spacing_Top_WG_User, PWG_width_min_user,
R_Roof_user, live_load_user, snow_load_bal, snow_load_unbal, roof_slope_user, dome_radius_user, JE_roof_user, Roof_Thk_user;

int D_Type, Option_P, Shell_Appendx_No_user, Roof_Type_No_user, FR_Type_No, Shell_Des_Method_No, RoundUP_to, option_Stfr,
wind_design_code, wind_exp_cat, Seismic_design_code, Zone_Number, site_class, ASCE_rule, SUG, option_Av, Shell_Material_No[15][3],
Option_walkway, curb_angle_No_user, Option_PWG, stfr_Mat_No[45], stfr_Sec_No[45][3], No_of_Stiffeners_Max_user, option_frangible_roof, Roof_Material_No, option_annularPlate;


string File_name;



// other variables used

double	D_Previous, D, Min_Nom_Thk, Min_Nom_Thk_1, t_uniform, tu_min_W, tu_min_Pe, tu_min, H_Max_W, H_Max_Ps, H_Max, Fy_Shell, H_Top, Spacing_Min, N_Sqr,
Spacing_Top_WG_Tr, kz, kzt, kd, basic_v, imp_factorW, gust_factor, wind_pressure, V, live_load, roof_slope, dome_radius,
roof_thk_user, roof_thk, JE_roof, R_Roof, Roof_Material_YS, Roof_Material_SA, Roof_Material_Y_mod, Roof_Material_Y_mod_Atm, Wt_FR, Wt_Roof_Str_defaut,
Wt_Roof_Str, Roof_thk_reqd, weight_Roof_Plate, weight_Roof_Plate_cor, theeta, Roof_Thk[10], Rafter_spacing, Rafter_spacing_cent,
dead_load, dead_load_cor, ext_load, ext_load_bal, ext_load_unbal, total_load_bal, total_load_unbal, H_td_default, H_td, H_tt_default, H_tt, H_Norm_default,
H_Norm, H_Seis_default, H_Seis, JE, Po_default, Po, S0, Ss, S1, imp_factorS, Fa_default, Fa, Fv_default, Fv, TL, K, Sds, Sd1, Av, Spacing_Top_WG, PWG_width_min,
PWG_width, YS, YS_Atm, UTS, Sd, Sd_Atm, St, Group_No, Psi, W, Ps, H_Ts, H_Avg, H_High, H_Low, New_Spacing, Y_Mod, Y_Mod_Atm, Y_mod, Y_mod_Atm,
Factor_M, Factor_M1, ring_area, ring_CG, ring_MOI, stfr_area, stfr_MOI, stfr_Sec_Mod,
Weight_FR, weight[20], density_steel, cg_shell, Thk_AnnPlate[4];

double web_width, web_thk, flng_width, flng_thk;

string Roof_Type, Roof_Type_user, FR_Type, Shell_Appendx, Shell_Appendx_user, Shell_Des_Method, MOC;

int  Shell_Appendx_No, Roof_Type_No, No_of_ShellCourses, Apndx_C_MOC, Print_x, Option_walkwayG, No_of_Stiffeners, No_of_Stiffeners_R,
No_of_Stiffeners_P, No_of_Stiffeners_Max, stfr_location[45][5], AnnPlate_req[4], edit_option=1;

double shell_detail[15][30], Y_Mod_X[15][3], user_EL_detail[45][11], stfr_Prop_user[45][4], stfr_detail[45][80], PWG_details[20], comp_ring_detail[10];

double PI = 3.14159;


string Roof_Material_Name, Shell_Material_Name[15][2], Stfnr_Material_Name[45], Stfnr_Section[45][3], Type_Stfr[45][3], Curb_angle_default, Curb_angle_user, ring_Name;
string Shell_appendx[] = { " Design Procedure", "Appendix - A", "Appendix - J", "Appendix - S", "Appendix - SC", "Appendix - X", "Appendix - AL", "None" };
string Curb_angle;

// global variables of function CompRing_Data() & CompRing_Design()


double  CR_Material_YS[7], CR_Material_Y_mod[7], CR_Material_SA[7], CR_Area_rqd_SRR, CR_Area_rqd_P, CR_Area_rqd_V, CR_MOI_rqd, CR_fc; // None of these are used yet


int apndx_F, CR_Type_No[3], CR_Material_No[7];
string CompRing_Type[3], CompRing_size[3], CR_Material_Name[7];




double Rc_AB, Rc_COR, t_shell_AB, t_shell_COR, Wc_COR, Wc_AB, Wh_COR, Wh_AB, t_roof_AB, t_roof_COR, R2_COR, R2_AB;

double v_Leg_ht_AB, v_Leg_ht_COR, h_Leg_w_AB, h_Leg_w_COR, v_Leg_thk_AB, v_Leg_thk_COR, h_Leg_thk_AB, h_Leg_thk_COR, CR_Area_Available_AB, CR_Area_Available_COR;

// Additional variables initialized by abhishek / Raghav


double WeightAdder_roof_default;
double WeightAdder_roof_user;
double WeightAdder_roof;
double weight_platform_default;
double weight_platform_user;
double weight_platform;
int roof_slope_user_numerator;
int roof_slope_user_denominator;

int type_compression_ring;
int CR_Size[3];
double t_bar[3];
double w_bar[3];
double l_bar[3];
double t_shell[3];
double w_shell[3];

// double H_Max_V;
double PWG_Width_Web;
double PWG_Width_Web_User;
double PWG_Thick_Web;
double PWG_Height_Flange;
double PWG_Thick_Flange;

double kz_default;
double V_default;
double Gd, H_Remaining;


// end of additional variables


// New Variable added by Ashok

double compRing_detail[3];
double PWG_shell_thk;
double PWG_shell_width;

// New Variable added by Ashok on 21/08/2018: requires to be initialized.

double thk_bottom;
double thk_annular;
double width_annular;
int option_annular;


double weight_bottom;
double acln_gravity = 9.80665;
double weight_shell_AB;
double weight_shell_cor;
double weight_stfr;
double weight_PWG;
double weight_W1;
double weight_W2;
double weight_W3;
double weight_multiplier;
double Wt_Roof_Str_cor;
double fraction_roof_weight;
double Wt_Roof_Nozzles;
double wind_moment_Mws;
double wind_moment_Mw;
double weight_Comp_ring_AB;
double weight_Comp_ring_cor;

double YS_AnnPlate;
double width_AnnPlate;


int check_anchorage1; // wind clause 5.11.2 .1 Eqn 1
int check_anchorage2; // wind clause 5.11.2 .1 Eqn 3
int check_anchorage3; // wind clause 5.11.2 .1 Eqn 2
int check_anchorage4; //  Appendix F Clause F.4.2
int check_anchorage5; //
int check_anchorage6;
int check_anchorage7;
int option_ReEdit;







void Input_Screen_1();
void Material_Selection(int, double);

void Wind_Data();
void Seismic_Data();
void shell_Details();
void PWG_Data();
void shell_Stfr_User_EL_Data();
void Stiffener_Prop_User_Data();
void Roof_Data();
void CompRing_Data();
void Calculate_Fa_FV();

void shell_Design();
void shell_Design_VDP_td(int);
void shell_Design_VDP_tt(int);
void PWG_Properties();
void PWG_Properties_User();
void PWG_MOI(double, double, double, double, double, double);
void shell_Stiffener_Location();
void H_Ts_Calculation();
void shell_Stfr_Min_EL();
void shell_Stfr_Avg_EL();
void shell_Stfr_User_EL();
void Roof_Design();
void weight_cal();
void CompRing_Design();
void CompRing_Angle_Properties(int, int);

void shell_Stiffener_Properties();
void Stiffener_Prop_User();
void stability_check();
void bottom_and_anchor_chair_Data();

void Section_Modulus_Angle(int, int);
void Section_Modulus_Builtup(int, double, double, double, double);

double roundup(double, int);
double rounddown(double, int);
double max(double x1, double x2, double x3, double x4, double x5, double x6, int n);
double min(double x1, double x2, double x3, double x4, double x5, double x6, int n);
double Transposed_To_Actual(double);
double Actual_To_Transposed(double);
int Shell_Course_No_Actual(double);
int Shell_Course_No_Transposed(double);
void print(std::string);

void PopulateVariables(InputData& inputData);
void ReadVariables(InputData& inputData);
void InitVariables();


bool exists(const std::string& name);

/*
Details of Variables Used are listed below:

Diamter of Tank in M as entered by user					=	D_User;
Nominal Diameter of Tank in M							=	D;
Tank height in M										=	H;
Product Level used for calculating td in M				=	H_td;
Product Level used for calculating tdin M				=	H_tt;
Normal Liquid Level-
used for calculating operating weight in M.				=	H_Norm;
Liquid Level used for calculating Sesimic Laod in M.	=	H_Seis;
Design Specific Gravity of the stored Product			=	G;
Design Specific Gravity of Hydrotest Water				=	Gw;
Design temperature in Deg. C							=	T;
Minimum Design Metal Temperature in Deg. C				=	MDMT;
Design Internal Pressure in KPa							=	P;
Operating Pressure in KPa								=	Po;
Design External Pressure in KPa							=	Pe;
CA of Bottom Plate in mm								=	CA_Bot;
CA of Roof Plate in mm									=	CA_Roof;
Joint Efficiency for Shell								=	JE
CA of Floating Roof in mm								=	CA_FR;
Minimum Reqd Nom. Thickness of 1st Shell course			=	Min_Nom_Thk_1
Minimum Reqd.Nom. Thickness of Upper Shell course		=	Min_Nom_Thk
Design Wind Velocity									=	V
Squire of the Number of waves of buckling (shell)		=	N_Sqr


Properties of material extracted by the function-
"Material Selection" for transfering the material-
properties to the function caller
Yield Strength at design Temperature					=	Ys;
Lowest  Y/S of all shell courses						=	Fy
Yield Strength at Atmospheric Temperature				=	Ys_Atm;
Minimum Specified Tensile Strengthe						=	UTS;
Allowable Stress at design Temperature					=	Sd;
Allowable Stress at Atmospheric Temperature				=	Sd_Atm;
Allowable Stress for Hydro-Test							=	St;
Youngs Modulus at Design Temperature					=	Y_Mod;
Youngs Modulus at Atmospheric Temperature				=	Y_Mod_Atm;
Factor_M												=	Factor_M;
Ratio of Y.Modulus_Design / Y. Modulus_Design			=	Factor_M1;
Group Number of material selected						=	group_No
User option to decide if Design pressure is to be-
added to Static Head in calculating the-
required thicknesses Td & Tt. (Y / N)				=	Option_P
User option to decide if Corroded thickness of shell
to be used for design of wind / vacuum stiffener	=	Option_Stfr
Maxinum unstiffened height against wind					=	H_Max_W
Maxinum unstiffened height against external Pressure	=	H_Max_Ps
Maxinum unstiffened height of shell						=	H_Max
Number of Decimals to which Rounding up to be done		=	RoundUP_to
Apndx for Shell Designed  (User)						=	Shell_Appendx_User;
AApndx for Shell Designed  (adopted)					=	Shell_Appendx
Number Identifying Shell_Appendx;						=	Shell_Appendx_No;
Option for selecting between CS (1) & SS (2)
for parts of tank governed by Apndx_C.				=	Apndx_C_MOC;
Control for printing:									=	Print_x;
Type of Fixed roof										=	Roof_Type;
Type of Floating roof									=	FR_Type;
Method to be used for calculating Shell Thk.
(1 for One Foot / 2 for Variable design point)		=	Shell_Des_Method_No
Spacing Required between stfr & shell joint				=	Spacing_Min

Shell_Material_No[i][0]									=	Material serial No  selected by user.
Shell_Material_No[i][1]									=	Material serial No  adopted.
AnnPlate_req[0]											=   for conditions vide clause 5.5.1 (= 1 if required, 0 if not)
AnnPlate_req[1]											=   for conditions vide clause  M.4.1 (= 1 if required, 0 if not)
AnnPlate_req[2]											=	User defined

shell_detail[course number-1]							=	shell_detail[15][30]
[(0)course width,
(1)UTS
(2)YS_Design,
(3)Sd_Design,
(4)St,
(5)YS_Atm,
(6)Sd_Atm,
(7)Hd
(8)Ht,
(9)CA
(10)td,
(11)tt,
(12)td_Vartable_Des_Point,
(13)tt_Vartable_Des_Point,
(14)t_Hydro_Dynamic,
(15)t_Compressive,
(16)t_Required,
(17)Factor_M
(18)t_Adopted,
(19)t_Corroded]
(20)Joint Efficiency
(21)Transposed height of shell course
(22)Bottom elevation of shell course on transposed shell
(23)Top elevation of shell course on transposed shell
(24)bottom elevation of shell course on actual shell
(25)Top elevation of of shell course on actaul shell
(26)Minimum spacing reqd for stfr on transposed shell
(27) Group No. (10 for I, 20 for II, 30 for III, 35 for IIIA ....
(28) Maximum permitted thickness for the material selected
(29) Thickness above which impact tesing is required.

shell_detail_user[i]
[0] User defined UTS of High UTS Material
[1] User defined Course.Width
[2] User defined CA
[3] User defined thickness
[4] Blank.

Material Sl. Number (By user) to each shell course		=	Shell_Material_No[15][0]
Material Sl. Number (adopted)to each shell course		=	Shell_Material_No[15][1]

stfr_detail[stiffener No]
[0] Minimum Possible Elevation (on Transposed shell)
[1] Spacing of un-stiffened shell above the stiffener (Transposed).
[2] Minimum Possible Elevation (on Actual shell)
[3] Spacing of un-stiffened shell above the stiffener (actual shell).
[4] Not Used.
[5] Spacing to shell joint above the stiffener (actual shell).
[6] Spacing to shell joint below the stiffener (actual shell).

[7] Int_Elevation (on Transposed shell)
[8] Spacing of un-stiffened shell above the stiffener (Transposed).
[9] Int_Elevation (on Actual shell)
[10] Spacing of un-stiffened shell above the stiffener (actual shell).
[11] Not Used
[12] Spacing to shell joint above the stiffener (actual shell).
[13] Spacing to shell joint below the stiffener (actual shell).

[14] Final_Elevation (on Transposed shell)
[15] Spacing of un-stiffened shell above the stiffener (Transposed).
[16] Final Elevation (on Actual shell)
[17] Spacing of un-stiffened shell above the stiffener (actual shell).
[18] Not Used
[19] Spacing to shell joint above the stiffener (actual shell).
[20] Spacing to shell joint below the stiffener (actual shell).

[21] final_Elevation (on Transposed shell)
[22] Spacing of un-stiffened shell above the stiffener (actual shell).
[23] Section Modulus Required
[24] Ls (Half actual height of unstiffened shell above & below stiffener)
[25] Yield Strength of material for stiffener
[26] Adopted yield strength for stiffener design; smaller Ys of material for shell and stiffener
[27] Allowable compressive stress for stiffener design = 0.4* Ys, not less than 103;
[28] Q
[29] Required MOI
[30] Required area (total)
[31] design shell thickness in Cm. ( = t)
[32] Total participating width of shell (above and below the stiffener = w_shell_top + w_shell_bot)
[33] Participating area of shell
[34] Required area of ring alone

DETAIL OF DEFAULT STIFFENER RING (+15 applies for user defined; + 30 applies for adopted)
[34] Type of stiffener ( 0.0 for angle;1.0 for built-up) float, used as intiger
[35]
[36] Distance to center of gravity of stiffener ring from shell (if section is angle)
[37] MOI of stiffener ring. (if section is angle)
[38]
[39] Area of stiffener ring alone (common for angle / built-up)

[40] Web width
[41] web thickness
[42] flange width
[43] flange thickness
[44]
[45] Combined area of stiffener assembly
[46] MOI of stiffener assembly
[47] section modulus of stiffener assembly.

[45] Total area of stifffener assembly (including area of shell)
[46] MOI of stiffener assembly
[47] Section Moduldu of stiffener assembly

PWG_details
[0]	Required Section Modulus CM^3
[1] Web Width (mm)
[2] Web Thk (mm)
[3] Flange Width (mm)
[4] Flange Thk (mm)
[5] Available section Modulus (Deafult)

[6] Web Width User (mm)
[7] Web Thk User (mm)
[8] Flange Width User  (mm)
[9] Flange Thk (mm)
[10] Available section Modulus (Deafult)

[11] Web Width User (mm)
[12] Web Thk User (mm)
[13] Flange Width User  (mm)
[14] Flange Thk (mm)
[15] Available section Modulus (Deafult)



[16] Required MOI
[17] Available MOI (deafault)
[18] Available MOI (User)
[19] Available MOI (Adopted)


Stfnr_Section[i][0]	= ring_Name of default section
Stfnr_Section[i][1] = ring_Name of user deined  section
Stfnr_Section[i][0]	= ring_Name of adopted section

stfr_location[n][0] = serial number of shell on which stiffener [n] is located when the stiffeners are place using H_Max (Minmum Elevation)
stfr_location[n][1] = serial number of shell on which stiffener [n] is located when the stiffeners are place using H_Avg (Average Elevation)
stfr_location[n][2] = serial number of shell on which stiffener [n] is located when the stiffeners are place as per user specified elevation


wind_design_code:	(int) Number representing design code: 1 for ASCE 7-05, 2 for ASCE 7-10, 3 for user defined wind velocity.

wind_exp_cat	:	(int) Number representing Exposure Category: 1,2 & 3 represents B, C & D respectively.
kz:
Kzt
Kd
basic_v			:	Basic wind velocity
imp_factorW		:	Importance Factor
gust_factor		:	Gust Factor
wind_pressure	:	Wind Pressure (kpa)
V				:	Design Wind velocity


details of local variable user_EL_detail[n][10]
n corresponds to stiffener serial number; 0 is the top stiffener
[1]		Minimum possible elevation on transposed shell
[2]		Minimum possible elevation on actual shell
[3]		Maximum possible elevation on transposed shell
[4]		Maximum possible elevation on actual shell
[5]		Proposed elevation on transposed shell;
[6]		Proposed elevation on actual shell;
[7]		user defined elevation on transposed shell (converted from [8]
[8]		user defined elevation on actual shell
[9]		spacing on actual shell between stiffener and top joint
[10]	spacing on actual shell between stiffener and bottom joint

Roof_Thk[1]		= Required thickness of roof for internal pressure
Roof_Thk[2]		= Required thickness of self supporting roof for uniform (ice) load
Roof_Thk[3]		= Required thickness of self supporting roof fonon-uniform (ice) load
Roof_Thk[4]		= Required thickness of self supporting roof As per appendix V
Roof_Thk[5]		= Minimum required thickness
Roof_Thk[6]		= Minimum required thickness rounded up
Roof_Thk[7]		= User defined thickness
Roof_Thk[8]		= Adopted thickness
Roof_Thk[9]		= Corroded thickness
deadload		=	weight per unit area of roof plate (asbuilt)
deadload_cor	=	weight per unit area of roof plate (corroded)
ext_load(bal),
ext_load(unbal) = design loads on roof roof excluding dead_load for balanced and unbalanced ice load
ext_load		= maximum of bal & unbal ext loads
total_load_bal,
total_load_unbal = deadload + ext_load

CR_Type_No[0] = default type
CR_Type_No[1] = user defined type
CR_Type_No[2] = adopted type

CompRing_Material_No
[0] = material added for comp ring (angle / bar)
[1] = Material of top shell for compression ring type h
[2] = Material of roof for compression ring type i


AnnPlate_req
[1]				=	1 if AP is required due to MOC group No. of of first shell course is IV and above and  design stress / Hydro stress in first shell course is higher than 160 /171
[2]				=	1 if Annular plate is required by appendix M
[3]				=	1 if user specifies Annular plate

*/


int maintest()

{
	struct InputData inputData;
	memset(&inputData, 0, sizeof(InputData));

	InitVariables();

	ofstream outf;
	cout << "Enter the file name For Result File ";
	cin >> File_name;
	Print_x = 0;
	tu_min = 0;
	string fileName = File_name + "data.bin";


	if (exists(fileName))
	{
		edit_option = 1;


		fstream data_file(fileName.c_str(), ios::in | ios::binary);
		data_file.read(reinterpret_cast<char *>(&inputData), sizeof(InputData));

		ReadVariables(inputData);

		data_file.close();

	}

	else
	{
		edit_option = 0;

	}


	Input_Screen_1();
	Wind_Data();
	Seismic_Data();
	shell_Details();
	if (Roof_Type_No > 6)
	{
		PWG_Data();

	}
	else
		shell_Stiffener_Location();

	shell_Stfr_User_EL_Data();
	shell_Stfr_User_EL();
	shell_Stiffener_Properties();
	Stiffener_Prop_User_Data();
	weight_cal();
	if (Roof_Type_No != 8)
		Roof_Data();

	// CompRing_Data();
	//CompRing_Design();

	weight_cal();
	PopulateVariables(inputData);

	fstream data_file(fileName.c_str(), ios::out | ios::binary);
	data_file.write(reinterpret_cast<char *>(&inputData), sizeof(InputData));
	data_file.flush();
	data_file.close();

	print(File_name);
	outf.close();


}

// New function to read variables from the cpp file itseld, so as to bypass the edit option.


bool exists(const std::string& name) {
	ifstream f(name.c_str());
	if (f.good()) {
		f.close();
		return true;
	}
	else {
		f.close();
		return false;
	}
}




void Input_Screen_1()

{


	// temporary variables
	string Roof_type[9] = { "Fixed Roof type", "SELF SUPPORTING CONE ROOF", "SELF SUPPORTING DOME / UMBRELLA ROOF", "SUPPORTED CONE ROOF", "SUPPORTED DOME / UMBRELLA ROOF", "STIFFENED CONE ROOF", "STIFFENED DOME ROOF", "GEODESIC ROOF", "No Fixed Roof" };
	string FR_type[5] = { "Floating Roof type", "SINGLE DECK FLOATING ROOF", "DOUBLE DECK FLOATING ROOF", "ALUMINUM FLOATING ROOF", "NO FLOATING ROOF" };
	string Shell_appendx[] = { " Design Procedure", "Appendix - A", "Appendix - J", "Appendix - S", "Appendix - SC", "Appendix - X", "Appendix - AL", "None" };

	double temp1, temp2, Gd;


	if (edit_option == 0)
	{
		cout << endl << "Tank Dia in M						=	"; 		cin >> D_User;

		//		cout << endl << "Enter 1 for Nominal Dia; 2 for ID:			=	"; 		cin >> D_Type;
		D_Type = 2;

		cout << endl << "Tank Height H in M					=	"; 		cin >> H;
		// H = 20;

		H_td_default = H;
		//		cout << endl << "H for Calculation of td: (Enter 0 if same as:    " << H << ")		=	"; 		cin >> H_td_user;

		if (H_td_user == 0)
			H_td = H_td_user = H_td_default;
		else
			H_td = H_td_user;

		H_tt_default = H_td;
		//		cout << endl << "H for Calculation of tt; (Enter 0 if same as:   " << H << ")		=	";      cin >> H_tt_user;

		if (H_tt_user == 0)
			H_tt = H_tt_user = H_tt_default;
		else
			H_tt = H_tt_user;

		H_Norm_default = (H_td - 0.5);

		//		cout << endl << "Normal Product Level Hn (Enter 0 if equal to:	" << H_Norm_default << ")	=	"; 		cin >> H_Norm_user;

		if (H_Norm_user == 0)
			H_Norm = H_Norm_user = H_Norm_default;
		else
			H_Norm = H_Norm_user;

		H_Seis_default = H_Norm;

		//		cout << endl << "H for Seismic Design; (Enter 0 if equal to:	" << H_Seis_default << ")	=	"; 		cin >> H_Seis_user;

		if (H_Seis_user == 0)
			H_Seis = H_Seis_user = H_Seis_default;
		else
			H_Seis = H_Seis_user;

		//		cout << endl << "Design Specific Gravity of Stored product		=	"; 		cin >> G;

		if (G == 0)
			G = 0.85;

		//		cout << endl << "Specific Gravity of Test water				=	";		cin >> Gw;
		if (Gw < 1.0)
			Gw = 1.0;

		//		cout << endl << "Design Temperature	in Deg. C			=	";		cin >> T;

		T = 84;

		if (T > 260)
		{
			cout << endl << "Max. Permitted Design Temperature is 260 Deg C." << endl;
			cout << endl << "Enter Design Temperature				=	";			cin >> T;
			if (T > 260) T = 260;
		}

		//		cout << endl << "Minimum Design Metal Temperature	in Deg. C	=	"; 		cin >> MDMT;
		MDMT = 0;

		//		cout << endl << "Design Internal Pressure in KPa :			=	"; 		cin >> P;
		P = 1.0;

		if (P > 18)
		{
			cout << endl << "Max. Permitted Design Pressure is 18 KPa." << endl;
			cout << endl << "Enter Design Pressure in KPa:				=	";			cin >> P;
			if (P > 18) P = 18;
		}

		if ((P > 0) && (P < 1))
		{
			//			cout << endl << "Add (P/9.8G) to design liquid head? (1 for Y; 0 for N)	:	 "; 			cin >> Option_P;

		}
		if ((P > 0) && (P < 1)) Option_P = 1;

		//	cout << endl << "Pressure Combination Factor (Enter 0 if equal to  0.4:	)	=	";		cin >> Fp;

		if (Fp < 0.4)
			Fp = 0.4;

		Po = Fp * P;



		//cout << endl << "Design External Pressure in KPa:			=	"; 		cin >> Pe;

		//		if (Pe < 0.050)
		Pe = 0.8;

		if (Pe > 6.9)
		{
			cout << endl << "Max. Permitted External Pressure is 6.9 KPa." << endl;
			cout << endl << "Enter Design External Pressure in KPa:			=	"; 			cin >> Pe;
			if (Pe > 6.9) Pe = 6.9;
		}

		//	cout << endl << "External Pr. Combination Factor (Enter 0 if equal to  0.4:	)	=	";		cin >> Fpe;

		if (Fpe < 0.4)
			Fpe = 0.4;



		/*
		cout << endl << "Applicable Appendix For Shell Design: (Enter: " << endl << endl <<
		"1 For Appendix - A " << endl << endl <<
		"2 For Appendix - J" << endl << endl <<
		"3 For Appendix - S " << endl << endl <<
		"4 For Appendix - SC " << endl << endl <<
		"5 For Appendix - X " << endl << endl <<
		//	"6 For Appendix - AL " << endl << endl <<
		"7 For None )" << endl;

		cout << endl << "Applicable Appendix For Shell Design			=	"; 		cin >> Shell_Appendx_No_user;
		*/
		if (Shell_Appendx_No_user == 0)
			Shell_Appendx_No_user = 1;
		Shell_Appendx_No = Shell_Appendx_No_user;
		Shell_Appendx = Shell_Appendx_user = Shell_appendx[Shell_Appendx_No_user];

		//		cout << endl << "Width of First shell course in Meter			=	"; 		cin >> shell_detail_user[0][1];
		if (shell_detail_user[0][1] == 0)
			shell_detail_user[0][1] = 2.5;

		shell_detail[0][0] = shell_detail_user[0][1];


		//		cout << endl << "CA for First shell course (mm)					=	"; 		cin >> shell_detail_user[0][2];
		shell_detail_user[0][2] = 2.5;

		shell_detail[0][9] = shell_detail_user[0][2];




		//		if (Shell_Appendx_No != 7)
		if ((Shell_Appendx_No != 7) || ((Shell_Appendx_No == 3) && (D_User <= 60.0)))
		{
			cout << endl << "Joint Efficiency to be considered for shell design		=	";			cin >> JE_user;
		}

		if (JE_user <0.7)
			JE_user = 0.7;

		//		cout << endl << "Corrosion Allowance of Bottom Plate (mm):		=	"; 		cin >> CA_Bot;
		CA_Bot = 2.0;


		cout << endl << "Type of Fixed roof: (Enter: " << endl << endl <<
			"1 For SELF SUPPORTING CONE ROOF " << endl << endl <<
			"2 For SELF SUPPORTING DOME/UMBRELLA ROOF" << endl << endl <<
			"3 For SUPPORTED CONE ROOF" << endl << endl <<
			"4 For SUPPORTED DOME/UMBRELLA ROOF" << endl << endl <<
			"5 For STIFFENED CONE ROOF" << endl << endl <<
			"6 For STIFFENED DOME ROOF" << endl << endl <<
			"7 For GEODESIC ROOF" << endl << endl <<
			"8 For No Fixed Roof " << endl << endl;

		cout << endl << "Type of Fixed roof:					=	"; 		cin >> Roof_Type_No_user;


		//	if (Roof_Type_No_user == 0) Roof_Type_No_user = 7;

		Roof_Type_No = Roof_Type_No_user;

		Roof_Type_user = Roof_type[Roof_Type_No_user];


		if (Roof_Type_No <= 6)
		{
			cout << endl << "Corrosion Allowance of Roof Plate (mm):			=	"; 			cin >> CA_Roof;
		}
		//CA_Roof = 1.0;
		/*

		cout << endl << "Type of Floating Roof:  (Enter" << endl << endl <<
		"1 For SINGLE DECK FLOATING ROOF " << endl << endl <<
		"2 For DOUBLE DECK FLOATING ROOF" << endl << endl <<
		"3 For ALUMINUM FLOATING ROOF" << endl << endl <<
		"4 For NO FLOATING ROOF )" << endl;

		cout << endl << "Type of Floating  roof:					=	"; 		cin >> FR_Type_No;

		*/

		if (FR_Type_No == 0) FR_Type_No = 4;

		FR_Type = FR_type[FR_Type_No];
		cout << endl << "Type of Floating roof   " << FR_Type << endl << endl;

		if ((FR_Type_No == 1) || (FR_Type_No == 2))
		{
			cout << endl << "Corrosion Allowance of Floating Roof (mm):		=	"; 			cin >> CA_FR;
		}

		/*
		cout << endl << "Shell Design Method: (Enter: " << endl << endl <<
		"1 For One-Foot Method " << endl << endl <<
		"2 For Variable Design Point Method" << endl;
		cout << endl << "Shell Design Method					=	 "; 		cin >> Shell_Des_Method_No;
		*/

		Shell_Des_Method_No = 1;

		if ((Shell_Appendx_No < 3) || (Shell_Appendx_No_user == 4)) // The second (||) part of the if statement is added on 10th Sept. 2018)
			Shell_Des_Method_No = 1;

		else if (D_User >= 61)
			Shell_Des_Method_No = 2;

		//		cout << endl << "Rounding-up of thickness: mm" << endl
		//			<< "(Enter 0 for round-up to 1 mm; 1 for 0.1 mm ):		=	 "; 		cin >> RoundUP_to;

		RoundUP_to = 1;

		//		cout << endl << "Use Corroded thickness for stiffener design \n"
		//			<< " ( 1 for Yes; 0 for No) ? :				=	             "; 		cin >> option_Stfr;

		option_Stfr = 1;

		// Check for Appendix A

		if (Shell_Appendx_No < 3)

		{
			if (D_Type == 1)
				D = D_User;
			else
				D = D_User + 0.013;
			if (G < Gw)
				Gd = Gw;
			else
				Gd = G;

			if (shell_detail[0][17] == 0)
				shell_detail[0][17] = 1;
			temp1 = (4.9 * D * ((H_td + ((P*Option_P) / (9.8*Gd))) - 0.3) * Gd / (0.85 * 145 * shell_detail[0][17])) + shell_detail[0][9];
			temp2 = (4.9 * D * ((H_td + ((P*Option_P) / (9.8*Gd))) - 0.3) * Gd / (JE_user * 145 * shell_detail[0][17])) + shell_detail[0][9];

			temp1 = roundup(temp1, RoundUP_to);
			temp2 = roundup(temp2, RoundUP_to);




			if (temp1 > 13.0)
			{

				Shell_Appendx_No = 7;
				JE = 1.0;

			}
			else
				if (temp2 > 13.0)
					JE = 0.85;

			cout << endl << "thickness for (JE = 0.85)			  =	" << temp1 << endl << endl;
			cout << endl << "thickness for	(JE = 0.7)			  =	" << temp2 << endl << endl;
			cout << endl << "JE Adopted							  =	" << JE << endl << endl;
		}

		if (Shell_Appendx_No == 7)
			JE = 1.0;

		Spacing_Min = 0.160;

		// The folowing added on 29/06/2018 to make it compatible with Ui


		//	cout << endl << "Weight of Spiral Stairway (Kg)				=	"; 		cin >> weight_stair_user;
		if (weight_stair_user == 0) weight_stair_user = (50 * H);


		//	cout << endl << "% increase in weight For Misc Items 		=	"; 		cin >> weight_adder_user;
		if (weight_adder_user == 0) weight_adder_user = 5.0;





	} // end of edit option

	else
	{

		cout << endl << "Do You Want to Revise The User Data ?	" << endl;

		cout << endl << "(Enter 1 if Yes, 0 for NO)					=	";

		//cin >> option_ReEdit;
		option_ReEdit = 0;

		if (option_ReEdit == 1)

		{



			// temporary variables
			double temp3, temp4, temp5;

			temp3 = temp4 = 0;

			string Roof_type[9] = { "Fixed Roof type", "SELF SUPPORTING CONE ROOF", "SELF SUPPORTING DOME / UMBRELLA ROOF", "SUPPORTED CONE ROOF", "SUPPORTED DOME / UMBRELLA ROOF", "STIFFENED CONE ROOF", "STIFFENED DOME ROOF", "GEODESIC ROOF", "No Fixed Roof" };
			string FR_type[5] = { "Floating Roof type", "SINGLE DECK FLOATING ROOF", "DOUBLE DECK FLOATING ROOF", "ALUMINUM FLOATING ROOF", "NO FLOATING ROOF" };
			string Shell_appendx[] = { " Design Procedure", "Appendix - A", "Appendix - J", "Appendix - S", "Appendix - SC", "Appendix - X", "Appendix - AL", "None" };

			// double temp1, temp2, Gd;




			cout << endl << "Diameter of Tank Considered in Design is   =	" << fixed << setprecision(3) << D_User << "	M" << endl;
			cout << endl << "Enter Revised Diameter		" << endl;
			cout << endl << "Enter zero for no change :	";
			cin >> temp3;
			if (temp3 > 0.05) D_User = temp3;


			cout << endl << "Height of Tank Considered in Design is   =	" << fixed << setprecision(3) << H << "	M" << endl;
			cout << endl << "Enter Revised Height		" << endl;
			cout << endl << "Enter zero for no change :	";
			cin >> temp4;
			if (temp4 > 0.05) H = temp4;

			cout << endl << "Design External Pressure Considered in Design is   =	" << fixed << setprecision(3) << Pe << "	M" << endl;
			cout << endl << "Enter Revised External Pressure		" << endl;
			cout << endl << "Enter zero for no change :	";
			cin >> temp5;
			if (temp5 > 0.249) Pe = temp5;

			if (Pe > 6.9) Pe = 6.9;

			cout << endl << "Use Corroded thickness for stiffener design \n"
				<< " ( 1 for Yes; 0 for No) ? :				=	             "; 		cin >> option_Stfr;






		} // end of ReEdit





		//cout << endl << "Tank Dia in M						=	"; 		cin >> D_User;


		if (H_td_user == 0)
			H_td = H;
		else
			H_td = H_td_user;

		if (H_tt_user == 0)
			H_tt = H;
		else
			H_tt = H_tt_user;

		if (H_Norm_user == 0)
			H_Norm = (H_td - 0.5);
		else
			H_Norm = H_Norm_user;

		if (H_Seis_user == 0)
			H_Seis = H_Norm;
		else
			H_Seis = H_Seis_user;



		if (H_td_user == 0)
			H_td = H;
		else
			H_td = H_td_user;

		if (H_tt_user == 0)
			H_tt = H;
		else
			H_td = H_tt_user;

		if (H_Norm_user == 0)
			H_Norm = (H_td - 0.5);
		else
			H_Norm = H_Norm_user;

		if (H_Seis_user == 0)
			H_Seis = H_Norm;
		else
			H_Seis = H_Seis_user;

		if (G == 0)
			G = 0.85;
		if (Gw < 1.0)
			Gw = 1.0;

		if (T > 260)
			T = 260;

		if (P > 18) P = 18;

		if (Fp < 0.4)
			Po = 0.4*P;

		else if (Fp > 1)
			Po = P;
		else
			Po = Fp*P;

		if (Pe > 6.9)
			Pe = 6.9;

		if (Shell_Appendx_No_user == 0)
			Shell_Appendx_No_user = 1;
		//		Shell_Appendx_No = Shell_Appendx_No_user;

		if ((Shell_Appendx_No < 3) || (Shell_Appendx_No == 4)) // The second (||) part of the if statement is added on 10th Sept. 2018)
			Shell_Des_Method_No = 1;

		else if (D_User >= 61)
			Shell_Des_Method_No = 2;
		if (Shell_Appendx_No < 3)
		{
			if (D_Type == 1)
				D = D_User;
			else
				D = D_User + 0.013;
			if (G < Gw)
				Gd = Gw;
			else
				Gd = G;

			//			if (JE_user == 0)
			//				JE_user = 0.7;

			if (shell_detail[0][17] == 0)
				shell_detail[0][17] = 1;

			temp1 = (4.9 * D * ((H_td + ((P*Option_P) / (9.8*Gd))) - 0.3) * Gd / (0.85 * 145 * shell_detail[0][17])) + shell_detail[0][9];
			temp2 = (4.9 * D * ((H_td + ((P*Option_P) / (9.8*Gd))) - 0.3) * Gd / (JE * 145 * shell_detail[0][17])) + shell_detail[0][9];

			temp1 = roundup(temp1, RoundUP_to);
			temp2 = roundup(temp2, RoundUP_to);


			if (temp1 > 13.0)
			{

				Shell_Appendx_No = 7;
				JE = 1.0;

			}
			else
				if (temp2 > 13.0)
					JE = 0.85;

		}

		else
		{
			if (Shell_Appendx_No == 7)
				JE = 1.0;
			//			else
			//				JE = JE_user;

		}

		Shell_Appendx = Shell_appendx[Shell_Appendx_No];
		Shell_Appendx_user = Shell_appendx[Shell_Appendx_No_user];
		if (Shell_Appendx_No < 3)
		{
			int i;
			cout << endl << "Thickness of Fiest shell course			  =	" << temp2 << endl << endl;
			cout << endl << "User defined Design Appendix			  =	" << Shell_Appendx_user << endl << endl;
			cout << endl << "Adopted Design Appendix			  =	" << Shell_Appendx << endl << endl;
			cin >> i;
		}
		shell_detail[0][0] = shell_detail_user[0][1];
		shell_detail[0][9] = shell_detail_user[0][2];

		Roof_Type_No = Roof_Type_No_user;

		Roof_Type_user = Roof_type[Roof_Type_No];



		FR_Type = FR_type[FR_Type_No];

		Spacing_Min = 0.160;


	}

	Roof_Type_user = Roof_type[Roof_Type_No_user], FR_Type = FR_type[FR_Type_No], Shell_Appendx = Shell_Appendx_user = Shell_appendx[Shell_Appendx_No];

	if (No_of_Stiffeners_Max_user == 0)
		No_of_Stiffeners_Max = 20;
	else
		No_of_Stiffeners_Max = No_of_Stiffeners_Max_user;

	Roof_Type_No = Roof_Type_No_user;



	if (Shell_Des_Method_No == 1)
		Shell_Des_Method = "One-Foot Method";
	else
		Shell_Des_Method = "Variable Design Point Method";

	if (weight_stair_user == 0) weight_stair_user = (50 * H);
	if (weight_adder_user == 0) weight_adder_user = 5.0;

	cout << endl << "Input Screen-1" << endl << endl;
	cout << endl << "User defined CA for first shell course			  =	" << fixed << setprecision(1) << shell_detail_user[0][2] << endl << endl;
	cout << endl << "Adopted CA for first shell course			  =	" << fixed << setprecision(1) << shell_detail[0][9] << endl << endl;

} // end of function Input_Screen_1()




void bottom_and_anchor_chair_Data()

{
	double thk_bottom_user, temp1, temp2, temp3, temp4, temp5, temp6;
	int temp7;
	string name_AnnPlate_material;

	temp1 = temp2 = temp3 = temp4 = temp5 = temp6 = 0;

	thk_bottom = roundup((6 + CA_Bot), RoundUP_to);

	cout << endl << "Required Thickness of bottom plate =	" << fixed << setprecision(1) << thk_bottom << endl << endl;
	cout << endl << "Enter Revised Thickness for Bottom Plate";
	cout << endl << "(Enter 0 for no change)					=	";

	cin >> thk_bottom_user;
	if (thk_bottom_user > thk_bottom) thk_bottom = thk_bottom_user;

	if (AnnPlate_req[2] == 0)
	{
		cout << endl << "Annular plate is not a requirement for this tank as per code	" << endl;

		cout << endl << "(Enter 1 if Required by user, 0 for no change)					=	";

		cin >> AnnPlate_req[2];

	}

	if (AnnPlate_req[2] == 1)
	{
		cout << endl << "Required Thickness of Annular plate =	" << fixed << setprecision(1) << Thk_AnnPlate[2] << endl << endl;
		cout << endl << "Enter Revised Thickness for Annular Plate";
		cout << endl << "(Enter 0 for no change)					=	";
		cin >> temp1;

		if (temp1 > Thk_AnnPlate[2]) Thk_AnnPlate[2] = temp1;
		Thk_AnnPlate[3] = Thk_AnnPlate[2] - CA_Bot;

	}

	else
		Thk_AnnPlate[2] = thk_bottom;

	if (AnnPlate_req[2] == 1)
		cout << endl << " Enter Serial Number of Material for Annular Plate			=	";
	else
		cout << endl << " Enter Serial Number of Material for Bottom Plate			=	";

	cin >> temp7;

	Material_Selection(temp7, 515);

	name_AnnPlate_material = MOC;
	YS_AnnPlate = YS;

	if (AnnPlate_req[2] == 1)
	{
		temp3 = (YS_AnnPlate / (2 * 0.00981* G * H));

		width_AnnPlate = 2 * Thk_AnnPlate[2] * (pow(temp3, 0.5));
		if (width_AnnPlate < 600) width_AnnPlate = 600;

		cout << endl << "Required Internal Projection of Annular plate (mm) =	" << fixed << setprecision(0) << width_AnnPlate << endl << endl;
		cout << endl << "Enter Revised Internal Projection for Annular Plate";
		cout << endl << "(Enter 0 for no change)					=	";
		cin >> temp4;

		if (temp4 > width_AnnPlate) width_AnnPlate = temp4;


	}


	weight_cal();
	stability_check();














} //end of function bottom_and_anchor_chair_Data


void Wind_Data()

{
	/*

	Beginning of function Wind_Data();
	Purpose of this function is to take inputs related to wind load from user using form "Input Screen
	For Wind Data" and calculate design wind velocity
	The entire listing may be taken to the form "Input Screen For Wind Data" so that this function can be
	replaced with the form, which will return the following global variables to the console program:
	*/







	double kz_default, kzt_default, kd_default, basic_v_default, imp_factorW_default, gust_factor_default, V_default, wind_pressure;

	if (edit_option == 0)

	{

		/*
		cout << endl << "Wind Design Code: (Enter: " << endl << endl <<
		"1 ASCE 7-05 " << endl << endl <<
		"2 ASCE 7-10 " << endl << endl <<
		"3 User Defined Design Wind Velocity			:	";

		cin >> wind_design_code;
		*/
		if (wind_design_code == 0) wind_design_code = 1;

		if (wind_design_code == 3)

		{

			V_default = 190;

			cout << endl << "Enter Design Wind Velocity in Km/h			=	";
			cin >> V_user;



			if (V_user > 0.01)
				V = V_user;
			else
				V = V_user = V_default;

		}

		else
		{

			basic_v_default = 53.6182;
			/*

			cout << endl << "Three Second Gust Design Wind Speed (V) at 10 M above ground =	" << fixed << setprecision(3) << basic_v_default << endl << endl;
			cout << endl << "Enter Three Second Gust Design Wind Speed ";
			cout << endl << "(Enter 0 for no change)					=	";

			cin >> basic_v_user;
			*/

			if (basic_v_user > 0.01)
				basic_v = basic_v_user;
			else
				basic_v = basic_v_user = basic_v_default;

			/*
			cout << endl << "Exposure Category:  Enter: " << endl << endl <<
			"1 Category B " << endl << endl <<
			"2 Category C " << endl << endl <<
			"3 Category D" << endl << endl << endl;
			cout << endl << "Exposure Category:					=	";
			cin >> wind_exp_cat;

			*/
			wind_exp_cat = 1;
			if (wind_exp_cat == 1)

				kz_default = 0.76;
			else
				if (wind_exp_cat == 2)
					kz_default = 1.04;
				else
					kz_default = 1.22;

			/*
			cout << endl << "Velocity Pressure Exposure Coefficient Kz		=	" << kz_default << endl << endl;
			cout << endl << "Enter Velocity Pressure Exposure Coefficient Kz ";
			cout << endl << "(Enter 0 for no change)					=	";

			cin >> kz_user;
			*/


			if (kz_user > 0.01)
				kz = kz_user;
			else
				kz = kz_user = kz_default;


			kzt_default = 1.0;
			/*
			cout << endl << "Topgraphic Factor Kzt =	" << fixed << setprecision(2) << kzt_default << endl << endl;
			cout << endl << "Enter Topgraphic Factor Kzt ";
			cout << endl << "(Enter 0 for no change)					=	";

			cin >> kzt_user;

			*/
			if (kzt_user > 0.01)
				kzt = kzt_user;
			else
				kzt = kzt_user = kzt_default;

			kd_default = 0.95;

			/*
			cout << endl << "Directionality Factor Kd =	" << fixed << setprecision(2) << kzt_default << endl << endl;
			cout << endl << "Enter Directionality Factor kd ";
			cout << endl << "(Enter 0 for no change)					=	";

			cin >> kd_user;
			*/

			if (kd_user > 0.01)
				kd = kd_user;
			else
				kd = kd_user = kd_default;




			imp_factorW_default = 1.0;

			/*
			cout << endl << "Importance Facor (I) =	" << fixed << setprecision(2) << imp_factorW_default << endl << endl;
			cout << endl << "Enter Importance Facor (I)";
			cout << endl << "(Enter 0 for no change)					=	";

			cin >> imp_factorW_user;

			*/

			if (imp_factorW_user < 0.1)
				imp_factorW = imp_factorW_user = imp_factorW_default;
			else
				imp_factorW = imp_factorW_user;


			gust_factor_default = 0.85;

			/*
			cout << endl << "Gust Factor (G) =	" << fixed << setprecision(2) << gust_factor_default << endl << endl;
			cout << endl << "Enter Gust Factor (G)";
			cout << endl << "(Enter 0 for no change)					=	";

			cin >> gust_factor_user;

			*/
			if (gust_factor_user > 0.01)
				gust_factor = gust_factor_user;
			else
				gust_factor = gust_factor_user = gust_factor_default;


			wind_pressure = ((0.613  * kz * kzt * kd * gust_factor * imp_factorW * (pow(basic_v, 2))) / 1000) + 0.24;
			V_default = 190 * pow((wind_pressure / 1.72), 0.5);

			/*
			cout << endl << "Design Wind Velocity =	" << fixed << setprecision(3) << V_default << endl << endl;
			cout << endl << "Enter Design Wind Velocity";
			cout << endl << "(Enter 0 for no change)					=	";

			cin >> V_user;
			*/

			if (V_user > 0.01)
				V = V_user;
			else
				V = V_user = V_default;


			cout << endl << " Kz adopted      =	" << fixed << setprecision(3) << kz << endl << endl;
			cout << endl << " Kzt adopted      =	" << fixed << setprecision(3) << kzt << endl << endl;
			cout << endl << " Kd adopted      =	" << fixed << setprecision(3) << kd << endl << endl;
			cout << endl << " Vb  adopted      =	" << fixed << setprecision(3) << basic_v << endl << endl;
			cout << endl << " I adopted      =	" << fixed << setprecision(3) << imp_factorW << endl << endl;
			cout << endl << " G adopted      =	" << fixed << setprecision(3) << gust_factor << endl << endl;

			cout << endl << " Wind Pressure adopted =	" << fixed << setprecision(3) << wind_pressure << endl << endl;

			cout << endl << " Wind Velocity adopted =	" << fixed << setprecision(3) << V << endl << endl;

		} // end of if logic for ASCE design



	}

	else
	{


		if (wind_design_code == 3)

		{

			V_default = 190;

			if (V_user > 0.01)
				V = V_user;
			else
				V = V_default;

		}

		else
		{

			basic_v_default = 53.6182;

			if (basic_v_user > 0.01)
				basic_v = basic_v_user;
			else
				basic_v = basic_v_default;


			if (wind_exp_cat == 1)

				kz_default = 0.76;
			else
				if (wind_exp_cat == 2)
					kz_default = 1.04;
				else
					kz_default = 1.22;


			if (kz_user > 0.01)
				kz = kz_user;
			else
				kz = kz_default;


			kzt_default = 1.0;

			if (kzt_user > 0.01)
				kzt = kzt_user;
			else
				kzt = kzt_default;

			kd_default = 0.95;

			if (kd_user > 0.01)
				kd = kd_user;
			else
				kd = kd_default;

			imp_factorW_default = 1.0;


			if (imp_factorW_user < 0.1)
				imp_factorW = imp_factorW_default;
			else
				imp_factorW = imp_factorW_user;

			gust_factor_default = 0.85;


			if (gust_factor_user > 0.01)
				gust_factor = gust_factor_user;
			else
				gust_factor = gust_factor_default;


			wind_pressure = ((0.613  * kz * kzt * kd * gust_factor * imp_factorW * (pow(basic_v, 2))) / 1000) + 0.24;
			V_default = 190 * pow((wind_pressure / 1.72), 0.5);

			if (V_user > 0.01)
				V = V_user;
			else
				V = V_default;


		} // end of if logic for ASCE design



	}// end of else logic for Edit option


} // end of function Wind_Data();







void Seismic_Data()

{



	// Beginning of function Seismic_Data();
	// Purpose of this function is to take inputs related to seismic load from user, using form "Input Screen For Seismic Data" and calculate Seismic design parameters
	// The entire listing may be taken to the form "Input Screen For Seismic Data" so that this function can be replaced with the form, which will return the following global variables to the console program:
	// int Seismic_design_code, Zone_Number, SUG, site_class, ASCE_rule, option_Av;
	// double S0_user, Ss_user, S1_user, Fa_user, Fv_user, Factor_Q, TL_user, K_user;
	// double S0, Ss, S1, imp_factorS, Fa_default, Fa, Fv_default, Fv, TL, K, Sds, Sd1;
	// whenever the values of Ss or S1 is changed due to user changing any of the related parametes like "Seismic_design_code", S0_user, Zone_Number, or Ss / S1 itself, the function "Calculate_Fa_FV()" should automatically be called by the form.


	// Local Variables

	double TL_default = 0.4;
	double K_default = 1.50;


	if (edit_option == 0)

	{


		/*
		cout << endl << "Seismic Design Code: (Enter: " << endl << endl <<
		"1 for ASCE 7 " << endl << endl <<
		"2 for UBC 97 " << endl << endl <<
		"3 for Peak Ground Acceleration			:	";

		cin >> Seismic_design_code;

		*/
		Seismic_design_code = 1;

		if (Seismic_design_code == 3)
		{

			cout << endl << "Enter Peak Ground Acceleration S0			=	";
			//	cin >> S0_user;

			if (S0_user > 0.01)
				S0 = S0_user;
			else
				S0 = S0_user = 0.075;

			Ss = 2.5*S0;
			S1 = Ss * 0.5;


		}

		else if (Seismic_design_code == 2)

		{

			cout << endl << "UBC Zone Number: (Enter: " << endl << endl <<
				"1 For Zone 1 " << endl << endl <<
				"2 For Zone 2A " << endl << endl <<
				"3 For Zone 2B " << endl << endl <<
				"4 For Zone 3 " << endl << endl <<
				"5 For Zone 4				 		:	";
			cin >> Zone_Number;

			if (Zone_Number == 1)
				S0 = 0.075;
			else
				if (Zone_Number == 2)
					S0 = 0.15;
				else
					if (Zone_Number == 3)
						S0 = 0.20;
					else
						if (Zone_Number == 4)
							S0 = 0.30;
						else
							S0 = 0.4;

			Ss = 2.5*S0;
			S1 = Ss * 0.5;

		}

		else
		{
			/*
			cout << endl << "Spectral Resp. Accln. Parameter (Ss) for short period 		=	";
			cin >> Ss_user;
			cout << endl << "Spectral Resp. Accln. Parameter (S1) for One Second 		=	";
			cin >> S1_user;
			*/

			Ss_user = 0.2;
			S1_user = 0.1;

			Ss = Ss_user;
			S1 = S1_user;

		} // end of else if logic for ASCE method

		/*
		cout << endl << "Seismic Site Class: (Enter: " << endl << endl <<
		"1 Site Class A" << endl << endl <<
		"2 Site Class B" << endl << endl <<
		"3 Site Class C" << endl << endl <<
		"4 Site Class D" << endl << endl <<
		"5 Site Class E							:	";
		cin >> site_class;
		*/
		site_class = 3;

		Calculate_Fa_FV();

		cout << endl << endl << endl << " Value of Ss								" << Ss_user << endl;
		cout << endl << " Value of Fa for the specified site class =		 " << Fa_default << endl;
		cout << endl << " Value of S1 								" << S1_user << endl;
		cout << endl << " Value of Fv for the specified site class =		" << Fv_default << endl << endl;


		/*
		cout << endl << "Is the site governed by ASCE rules?: (Enter: " << endl << endl <<
		"1 for YES" << endl << endl <<
		"0 for NO							:	";
		cin >> ASCE_rule;
		*/
		ASCE_rule = 1;

		if (ASCE_rule == 1)
			Factor_Q = 0.667;
		else
			Factor_Q = 1.0;


		/*
		cout << endl << "Seismic User Group: (Enter: " << endl << endl <<
		"1 for SUG-1" << endl << endl <<
		"2 for SUG-2" << endl << endl <<
		"3 for SUG-3							:	";
		cin >> SUG;
		*/
		SUG = 2;


		if (SUG == 1)
			imp_factorS = 1.0;
		else
			if (SUG == 2)
				imp_factorS = 1.25;

			else
				imp_factorS = 1.5;



		/*
		cout << endl << "Acceleration based site coefficient (Fa)=	" << Fa_default << endl << endl;
		cout << endl << "Enter Acceleration based site coefficient (Fa)";
		cout << endl << "(Enter 0 for no change)					=	";

		cin >> Fa_user;
		*/


		if (Fa_user == 0)
			Fa = Fa_user = Fa_default;
		else
			Fa = Fa_user;

		Sds = Factor_Q * Fa * Ss;

		/*
		cout << endl << "Velocity based site coefficient (Fv)=	" << Fv_default << endl << endl;
		cout << endl << "Enter GAcceleration based site coefficient (Fv)";
		cout << endl << "(Enter 0 for no change)					=	";

		cin >> Fv_user;
		*/
		if (Fv_user == 0)
			Fv = Fv_user = Fv_default;
		else
			Fv = Fv_user;

		Sd1 = Factor_Q * Fv * S1;

		/*
		cout << endl << "Transition Period For Longer Period Ground Motion (TL)  =	" << TL_default << endl << endl;
		cout << endl << "Transition Period For Longer Period Ground Motion (TL)";
		cout << endl << "(Enter 0 for no change)					=	";

		cin >> TL_user;
		*/
		if (TL_user == 0)
			TL = TL_user = TL_default;
		else
			TL = TL_user;


		/*
		cout << endl << "Coefficient to adjust 5% damping value \n" << " to 0.5% Damping value (K)=	" << K_default << endl << endl;
		//cout << endl << "Enter Coefficient to adjust 5% damping value to 0.5% Damping value (K)Transition Period For Longer Period Ground Motion (TL)";
		cout << endl << "(Enter 0 for no change)					=	";

		cin >> K_user;
		*/

		if (K_user == 0)
			K = K_user = K_default;
		else
			K = K_user;

		/*
		cout << endl << "Is Vertical Seismic Effect to be applied ?: (Enter: " << endl << endl <<
		"1 for YES" << endl << endl <<
		"0 for NO							:	";
		cin >> option_Av;
		*/
		if (option_Av == 1)
			Av = 0.47 * Sds;
		else
			Av = 0;

	}

	else   // if Edit_option == 1
	{



		if (Seismic_design_code == 3)
		{

			if (S0_user > 0.01)
				S0 = S0_user;
			else
				S0 = S0_user = 0.075;

			Ss = S0;
			S1 = Ss * 0.5;

		}

		else if (Seismic_design_code == 2)

		{

			if (Zone_Number == 1)
				S0 = 0.075;
			else
				if (Zone_Number == 2)
					S0 = 0.15;
				else
					if (Zone_Number == 3)
						S0 = 0.20;
					else
						if (Zone_Number == 4)
							S0 = 0.30;
						else
							S0 = 0.4;

			Ss = 2.5*S0;
			S1 = Ss * 0.5;

		}

		else
		{
			Ss = Ss_user;
			S1 = S1_user;

		} // end of else if logic for seismic design method



		Calculate_Fa_FV();



		if (ASCE_rule == 1)
			Factor_Q = 0.667;
		else
			Factor_Q = 1.0;


		if (SUG == 1)
			imp_factorS = 1.0;
		else
			if (SUG == 2)
				imp_factorS = 1.25;

			else
				imp_factorS = 1.5;


		if (Fa_user == 0)
			Fa = Fa_default;
		else
			Fa = Fa_user;

		Sds = Factor_Q * Fa * Ss;

		if (Fv_user == 0)
			Fv = Fv_default;
		else
			Fv = Fv_user;

		Sd1 = Factor_Q * Fv * S1;

		if (TL_user == 0)
			TL = TL_default;
		else
			TL = TL_user;



		if (K_user == 0)
			K = K_default;
		else
			K = K_user;


		if (option_Av == 1)
			Av = 0.47 * Sds;
		else
			Av = 0;

	} // end of else logic for Edit option



} // end of function Seismic_Data()









void shell_Details()

{


	int a, c, f, n, i;   // temporary variables

	double H_Course, Gd;

	if ((Shell_Appendx_No == 1) || (Shell_Appendx_No == 2))

		Gd = (G > 1.0) ? G : 1.0;
	else

		Gd = G;


	//	shell_detail[0][0] = shell_detail_user[0][1];
	shell_detail[0][9] = shell_detail_user[0][2];

	double H_Remaining = (H - shell_detail[0][0]);
	//	Shell_Appendx = Shell_Appendx_user = Shell_appendx[Shell_Appendx_No_user];

	n = 0; // n Represents (course number-1)

	// Start: Assigning width of shell courses second and above.

	if (edit_option == 0)
	{
		while (H_Remaining >= 0.0005)

		{
			n++;

			cout << endl << "Remaining Height of shell		= " << fixed << setprecision(3) << H_Remaining << endl;
			cout << endl << "Width of shell course Number " << (n + 1) << endl;
			cout << endl << "(Enter '0' if same as previous: " << shell_detail[(n - 1)][0] << ")			=	";
			// cin >> H_Course;

			H_Course = 0;


			if (H_Course < 0.001) H_Course = shell_detail[(n - 1)][0];


			if (H_Course <= (H_Remaining - 0.5))
				shell_detail_user[n][1] = H_Course;
			else
				shell_detail_user[n][1] = H_Remaining;
			shell_detail[n][0] = shell_detail_user[n][1];

			H_Remaining = (H_Remaining - shell_detail[n][0]);

		}

		//	 End: Assigning width of shell courses second and above.

		//	 Start Assigning other design variables for the first shell course:

		No_of_ShellCourses = (n + 1);


		cout << endl << endl << endl << endl;

		cout << endl << "Select material for First Shell Course:	" << endl;
		cout << endl << endl << " Enter Serial Number of Material 			=	";
		// cin >> Shell_Material_No[0][0];

		Shell_Material_No[0][0] = 0;


		if (Shell_Material_No[0][0] == 0)
			Shell_Material_No[0][0] = 6;

		c = Shell_Material_No[0][0];


		if ((c > 66) && (c < 93))
		{

			if ((c == 71) || (c == 74) || (c == 77))
			{
				cout << endl << "Please specify the incresed tensile strength " << endl << "of the specified material" << endl << "(it should be between 585 & 690) ";
				cout << endl << " Enter incresed tensile strength			=	 ";
				cin >> shell_detail_user[0][0];
				if (shell_detail_user[0][0] < 585)
					shell_detail_user[0][0] = 585;
				else if (shell_detail_user[0][0] > 690)
					shell_detail_user[0][0] = 690;

			}

			else
			{
				cout << endl << "Please specify the incresed tensile strength " << endl << "of the specified material" << endl << "(it should be between 515 & 620) ";
				cout << endl << " Enter incresed tensile strength			=	 ";

				cin >> shell_detail_user[0][0];
				shell_detail_user[0][0] = 515;
				if (shell_detail_user[0][0] < 515)
					shell_detail_user[0][0] = 515;
				else if (shell_detail_user[0][0] > 620)
					shell_detail_user[0][0] = 620;

			}

		}
		a = c;

		Material_Selection(Shell_Material_No[0][0], shell_detail_user[0][0]);

		Shell_Material_Name[0][0] = MOC;
		Shell_Material_Name[0][1] = MOC;
		Shell_Material_No[0][1] = Shell_Material_No[0][0];

		shell_detail[0][1] = UTS;
		shell_detail[0][2] = YS;
		Fy_Shell = YS;
		shell_detail[0][3] = Sd;
		shell_detail[0][4] = St;

		shell_detail[0][5] = YS_Atm;
		shell_detail[0][6] = Sd_Atm;
		shell_detail[0][17] = Factor_M; // new line added on 10 Sept 2018
		shell_detail[0][27] = Group_No;
		if (Shell_Appendx_No == 5)
		{
			Y_Mod_X[0][1] = Y_mod_Atm;
			Y_Mod_X[0][2] = Y_mod;
			Factor_M1 = (Y_Mod_X[0][2] / Y_Mod_X[0][1]);
			Y_Mod_Atm = Y_mod_Atm;
			Y_Mod = Y_mod;
		}
		else
		{
			Y_Mod_Atm = Y_mod_Atm;
			Y_Mod = Y_mod;
			Factor_M1 = Y_mod / Y_mod_Atm;
		}





		c = 0;
		f = 0;

		for (i = 1; i <= (No_of_ShellCourses - 1); i++)

		{


			cout << endl << "Material for shell course Number " << (i + 1) << endl;
			cout << endl << "(Enter '0' if same as previous )" << " :	";
			cout << endl << endl << " Enter Serial Number of Material 			=	";
			// cin >> Shell_Material_No[i][0];

			Shell_Material_No[i][0] = 0;

			if (Shell_Material_No[i][0] == 0)
			{
				Shell_Material_Name[i][0] = " "; // store a blank
				Shell_Material_Name[i][1] = Shell_Material_Name[(i - 1)][1];
				shell_detail[i][1] = shell_detail[(i - 1)][1];
				shell_detail[i][2] = shell_detail[(i - 1)][2];
				shell_detail[i][3] = shell_detail[(i - 1)][3];
				shell_detail[i][4] = shell_detail[(i - 1)][4];

				Shell_Material_No[i][1] = Shell_Material_No[(i - 1)][1];
				shell_detail[i][5] = shell_detail[(i - 1)][5];
				shell_detail[i][6] = shell_detail[(i - 1)][6];
				shell_detail[i][17] = shell_detail[(i - 1)][17]; // new line added on 10 Sept 2018
				shell_detail[i][27] = shell_detail[(i - 1)][27]; // new line added on 10 Sept 2018
				if (Shell_Appendx_No == 5)
				{
					Y_Mod_X[i][1] = Y_Mod_X[(i - 1)][1];
					Y_Mod_X[i][2] = Y_Mod_X[(i - 1)][2];

				}


			}


			else
			{
				shell_detail_user[i][0] = 0;
				if ((Shell_Material_No[i][0] > 66) && (Shell_Material_No[i][0] < 100))
				{

					if ((Shell_Material_No[i][0] == 71) || (Shell_Material_No[i][0] == 74) || (Shell_Material_No[i][0] == 77))
					{
						cout << endl << "Please specify the incresed tensile strength " << endl << "of the specified material" << endl << "(it should be between 585 & 690) ";
						cout << endl << " Enter incresed tensile strength			=	 ";
						cin >> shell_detail_user[i][0];

						if (shell_detail_user[i][0] < 585)
							shell_detail_user[i][0] = 585;
						else if (shell_detail_user[i][0] > 690)
							shell_detail_user[i][0] = 690;

					}

					else
					{
						cout << endl << "Please specify the incresed tensile strength " << endl << "of the specified material" << endl << "(it should be between 515 & 620) ";
						cout << endl << " Enter incresed tensile strength			=	 ";

						cin >> shell_detail_user[i][0];

						if (shell_detail_user[i][0] < 515)
							shell_detail_user[i][0] = 515;
						else if (shell_detail_user[i][0] > 620)
							shell_detail_user[i][0] = 620;

					}

				}


				if (c > 0.1)
					a = c;



				Material_Selection(Shell_Material_No[i][0], shell_detail_user[i][0]);

				Shell_Material_Name[i][0] = Shell_Material_Name[i][1] = MOC;
				shell_detail[i][1] = UTS;
				shell_detail[i][2] = YS;
				if (Fy_Shell > YS)
					Fy_Shell = YS;
				shell_detail[i][3] = Sd;
				shell_detail[i][4] = St;
				Shell_Material_No[i][1] = Shell_Material_No[i][0];
				shell_detail[i][5] = YS_Atm;
				shell_detail[i][6] = Sd_Atm;
				shell_detail[i][17] = Factor_M; // new line added on 10 Sept 2018
				shell_detail[i][27] = Group_No;// // new line added on 10 Sept 2018

				if (Shell_Appendx_No == 5)
				{
					Y_Mod_X[i][1] = Y_mod_Atm;
					Y_Mod_X[i][2] = Y_mod;
					if ((Y_Mod_X[i][2] / Y_Mod_X[i][1]) < Factor_M1)

					{
						Factor_M1 = (Y_Mod_X[i][2] / Y_Mod_X[i][1]);
						Y_Mod_Atm = Y_mod_Atm;
						Y_Mod = Y_mod;
					}
				}
			}

			//	cout << endl << "Youngs Modulus (Tr) :			" << Y_Mod_X[0][1] <<"	" <<Y_Mod_X[0][2] << endl << endl;

			//	cout << endl << endl << endl << endl ;
			cout << endl << "CA for shell course Number	" << (i + 1) << endl;
			cout << endl << "(Enter '0' if same as previous; 0.05 if zero		=	";
			// cin >> shell_detail_user[i][2];

			shell_detail_user[i][2] = 0;

			shell_detail_user[i][2] = 0;
			if (shell_detail_user[i][2] < 0.001) shell_detail[i][9] = shell_detail[(i - 1)][9];
			else if (shell_detail_user[i][2] < 0.1) shell_detail[i][9] = 0;
			else shell_detail[i][9] = shell_detail_user[i][2];



		} // end of while statement

		if
			(D_Type == 1)
			D = D_User;

		else

			D = D_User + (shell_detail[(0)][18] / 1000);


		shell_Design();


		if (D_Type == 2)
		{
			while (D_Previous != D)
			{
				shell_Design();

			}
		}




		for (i = 0; i <= (No_of_ShellCourses - 1); i++)
		{

			cout << endl << "Adopted. Thk. for shell course Number	" << (i + 1) << "=	" << roundup((shell_detail[i][16]), RoundUP_to) << endl;
			cout << endl << "Enter Thk. for shell course Number	" << (i + 1) << endl;
			cout << endl << "(Enter '0' for no change)" << "=	";
			// cin >> shell_detail_user[i][3];

			shell_detail_user[i][3] = 0;
		}



	}

	//  beginning of new logic for reading data from file

	else

	{


		//		c = Shell_Material_No[0][0];


		//		a = c;

		for (i = 0; i <= (No_of_ShellCourses - 1); i++)
		{

			shell_detail[i][0] = shell_detail_user[i][1];
			shell_detail[i][9] = shell_detail_user[i][2];
		}

		Material_Selection(Shell_Material_No[0][0], shell_detail_user[0][0]);

		Shell_Material_Name[0][0] = MOC;
		Shell_Material_Name[0][1] = MOC;
		Shell_Material_No[0][1] = Shell_Material_No[0][0];

		shell_detail[0][1] = UTS;
		shell_detail[0][2] = YS;
		Fy_Shell = YS;
		shell_detail[0][3] = Sd;
		shell_detail[0][4] = St;

		shell_detail[0][5] = YS_Atm;
		shell_detail[0][6] = Sd_Atm;
		shell_detail[0][17] = Factor_M; // New Line added on 10 Sept 2018
		shell_detail[0][27] = Group_No;
		if (Shell_Appendx_No == 5)
		{
			Y_Mod_X[0][1] = Y_mod_Atm;
			Y_Mod_X[0][2] = Y_mod;
			Factor_M1 = (Y_Mod_X[0][2] / Y_Mod_X[0][1]);
			Y_Mod_Atm = Y_mod_Atm;
			Y_Mod = Y_mod;
		}
		else
		{
			Y_Mod_Atm = Y_mod_Atm;
			Y_Mod = Y_mod;
			Factor_M1 = Y_mod / Y_mod_Atm;
		}



		for (i = 1; i <= (No_of_ShellCourses - 1); i++)

		{


			if (Shell_Material_No[i][0] == 0)
			{
				Shell_Material_Name[i][0] = " "; // store a blank for user defined material
				Shell_Material_Name[i][1] = Shell_Material_Name[(i - 1)][1];
				shell_detail[i][1] = shell_detail[(i - 1)][1];
				shell_detail[i][2] = shell_detail[(i - 1)][2];
				shell_detail[i][3] = shell_detail[(i - 1)][3];
				shell_detail[i][4] = shell_detail[(i - 1)][4];
				Shell_Material_No[i][1] = Shell_Material_No[(i - 1)][1];
				shell_detail[i][5] = shell_detail[(i - 1)][5];
				shell_detail[i][6] = shell_detail[(i - 1)][6];
				shell_detail[i][17] = shell_detail[(i - 1)][17]; // New Line added on 10 Sept 2018
				shell_detail[i][27] = shell_detail[(i - 1)][27]; // New Line added on 10 Sept 2018
				if (Shell_Appendx_No == 5)
				{
					Y_Mod_X[i][1] = Y_Mod_X[(i - 1)][1];
					Y_Mod_X[i][2] = Y_Mod_X[(i - 1)][2];

				}


			}


			else
			{


				Material_Selection(Shell_Material_No[i][0], shell_detail_user[i][0]);

				Shell_Material_Name[i][0] = Shell_Material_Name[i][1] = MOC;
				shell_detail[i][1] = UTS;
				shell_detail[i][2] = YS;
				if (Fy_Shell > YS)
					Fy_Shell = YS;
				shell_detail[i][3] = Sd;
				shell_detail[i][4] = St;
				Shell_Material_No[i][1] = Shell_Material_No[i][0];
				shell_detail[i][5] = YS_Atm;
				shell_detail[i][6] = Sd_Atm;
				shell_detail[i][17] = Factor_M; // new line added on 10 Sept 2018
				shell_detail[i][27] = Group_No;//  new line added on 10 Sept 2018

				if (Shell_Appendx_No == 5)
				{
					Y_Mod_X[i][1] = Y_mod_Atm;
					Y_Mod_X[i][2] = Y_mod;
					if ((Y_Mod_X[i][2] / Y_Mod_X[i][1]) < Factor_M1)

					{
						Factor_M1 = (Y_Mod_X[i][2] / Y_Mod_X[i][1]);
						Y_Mod_Atm = Y_mod_Atm;
						Y_Mod = Y_mod;
					}
				}
			}


			if (shell_detail_user[i][1] < 0.01)
				shell_detail[i][0] = shell_detail[(i - 1)][0];
			else
				shell_detail[i][0] = shell_detail_user[i][1];


			if (shell_detail_user[i][2] < 0.001) shell_detail[i][9] = shell_detail[(i - 1)][9];
			else if (shell_detail_user[i][2] < 0.1) shell_detail[i][9] = 0;
			else shell_detail[i][9] = shell_detail_user[i][2];



		} // end of For statement

		if
			(D_Type == 1)
			D = D_User;

		else

			D = D_User + (shell_detail[(0)][18] / 1000);


		shell_Design();


		if (D_Type == 2)
		{
			while (D_Previous != D)
			{
				shell_Design();

			}
		}




	}



	shell_Design();



} // end of function shell_Details()













void PWG_Data()

{
	// temporary variables

	string angle_section_name[8] = { "No Curb Angle", "65 x 65 x 6", "65 x 65 x 8", "65 x 65 x 10", "75 x 75 x 6", "75 x 75 x 8", "75 x 75 x 10", "90 x 90 x 10" };
	double angle_section_width[8] = { 0, 65, 65, 65, 75, 75, 75, 90 };
	double PWG_width_min_default;
	int i, k;

	if (edit_option == 0)
	{
		cout << endl << "Is Top Wind Girder used as a walkway ? " << endl;
		cout << endl << "(Enter '0' for No, 1 For Yes )" << "			=	";
		cin >> Option_walkway;


		if (Option_walkway == 0)
		{
			cout << endl << "Spacing of Top WG from top of shell			=	";
			cin >> Spacing_Top_WG;

			if (Spacing_Top_WG < 0.5) Spacing_Top_WG = 1.1;   //  to be taken from "Form For Primary Wind Girder Design".

			Spacing_Top_WG_User = Spacing_Top_WG;

		}

		//      This one line below is added today.

		else if (Option_walkway == 1) Spacing_Top_WG = 1.1;

		Spacing_Top_WG_User = Spacing_Top_WG;

		shell_Stiffener_Location();

		if (Spacing_Top_WG <= 0.6)
			i = 0;
		else

		{
			if (shell_detail[(No_of_ShellCourses - 1)][18] < 5.01)
				i = 1;
			else
				i = 4;

		}


		Curb_angle_default = angle_section_name[i];

		if (i == 0)
			cout << endl << "A Curb Angle is not mandatory for this tank " << endl;
		else
			cout << endl << "Minimum size of Curb Angle Required for this tank is : (" << Curb_angle_default << ")	=	" << endl;

		cout << endl << "User defined Curb angle size is : (Enter: " << endl << endl <<
			"0 For No Curb Aagle" << endl << endl <<
			"1 For L 65 x 65 x 6" << endl << endl <<
			"2 For L 65 x 65 x 8" << endl << endl <<
			"3 For L 65 x 65 x 10" << endl << endl <<
			"4 For L 75 x 75 x 6" << endl << endl <<
			"5 For L 75 x 75 x 8" << endl << endl <<
			"6 For L 75 x 75 x 10" << endl << endl <<
			"7 For L 90 x 90 x 10" << endl << endl;

		cin >> curb_angle_No_user;


		if (curb_angle_No_user >= i)
			k = curb_angle_No_user;
		else
			k = i;
		Curb_angle_user = angle_section_name[curb_angle_No_user];
		Curb_angle = angle_section_name[k];
		curb_angle_No_user = k;

		cout << endl << "Size of Curb Angle Adopted for this tank is : (" << Curb_angle << ")	" << endl;



		if (Option_walkway == 1)
		{
			PWG_width_min_default = 710 + angle_section_width[k];
			cout << endl << "Minimum Required Width of Wind Girder used as a walkway is :  " << PWG_width_min_default << endl;
			cout << endl << "Enter Minimum Required Width of Wind Girder used as a walkway ? " << endl;
			cout << endl << "(Enter '0' for no change )" << "			=	";
			cin >> PWG_width_min_user;

			if (PWG_width_min_user < PWG_width_min_default) // These five lines are not used in UI
				PWG_width_min = PWG_width_min_user = PWG_width_min_default;
		}
		else
			PWG_width_min = 0;

		if (D > 61)
		{
			cout << endl << "Should the Primary WG designed considering the diameter as 61.0 M ? " << endl;
			cout << endl << "(Enter '0' for No, 1 For Yes )" << "			=	";
			cin >> Option_PWG;

		}


		cout << endl << "Enter Thickness of the web (mm)			=	" << endl;
		cout << endl << "Enter zero for 6 thk web :	";
		cin >> PWG_details[7];

		PWG_Thick_Web = PWG_details[7];
		if (PWG_Thick_Web < 6) PWG_Thick_Web = 6;



		cout << endl << "Enter Height of the Flange (mm)			=	";
		cout << endl << "Enter zero for 150 mm flange height :	";
		cin >> PWG_details[8];
		PWG_Height_Flange = PWG_details[8];
		if (PWG_Height_Flange <50) PWG_Height_Flange = 150;

		cout << endl << "Enter Thickness of the Flange (mm)			=	";
		cout << endl << "Enter zero for 6 thk flange :	";
		cin >> PWG_details[9];
		PWG_Thick_Flange = PWG_details[9];

		if (PWG_Thick_Flange < 6) PWG_Thick_Flange = 6;

		PWG_Properties();

		cout << endl << "Proposed size of the PWG			  =	" << endl;
		cout << endl << "Width of Web mm			  =	" << fixed << setprecision(0) << PWG_details[1] << endl << endl;
		cout << endl << "Thickness of Web mm			  =	" << fixed << setprecision(0) << PWG_details[2] << endl << endl;

		cout << endl << "Height of Flange mm			  =	" << fixed << setprecision(0) << PWG_details[3] << endl << endl;
		cout << endl << "Thickness of Flange mm			  =	" << fixed << setprecision(0) << PWG_details[4] << endl << endl;


		cout << endl << "Enter Revised width of the web (mm)			=	";
		cin >> PWG_details[6];
		if ((Option_walkway == 1) && (PWG_details[6] < PWG_width_min))
		{
			PWG_details[6] = 0;
			PWG_details[10] = 0;
			PWG_details[18] = 0;
		}

		PWG_Width_Web_User = PWG_details[6];

		cout << endl << "Width of Web in PWG_Data	  =	" << fixed << setprecision(0) << PWG_Width_Web << endl << endl;

		PWG_Properties_User();
	}



	else
	{

		shell_Stiffener_Location();

		if (Spacing_Top_WG <= 0.6)
			i = 0;
		else
		{
			if (shell_detail[(No_of_ShellCourses - 1)][18] < 5.01)
				i = 1;
			else i = 4;
		}

		Curb_angle_default = angle_section_name[i];


		if (curb_angle_No_user >= i)
			k = curb_angle_No_user;
		else
			k = i;
		curb_angle_No_user = k; //making it equal to what's adopted
		Curb_angle_user = angle_section_name[curb_angle_No_user];
		// Curb_angle = angle_section_name[k];

		if (Option_walkway == 1)
			PWG_width_min = PWG_width_min_user;
		else
			PWG_width_min = 0;

		PWG_details[6] = PWG_Width_Web_User;
		PWG_details[7] = PWG_Thick_Web;
		PWG_details[8] = PWG_Height_Flange;
		PWG_details[9] = PWG_Thick_Flange;

		if ((Option_walkway == 1) && (PWG_details[6] < PWG_width_min))
		{
			PWG_details[6] = 0;
			PWG_details[10] = 0;
			PWG_details[18] = 0;
		}

		PWG_Properties();

		PWG_Properties_User();
	}
} // end of function PWG_Data()



void PWG_Properties_User()
{



	if ((PWG_details[6] > 0) && (PWG_details[7] > 0) && (PWG_details[8] > 0) && (PWG_details[9] > 0))

	{

		if (PWG_details[6] < PWG_width_min)
			PWG_details[6] = PWG_width_min;

		PWG_MOI(PWG_shell_width, PWG_shell_thk, (PWG_details[6] / 10), (PWG_details[7] / 10), (PWG_details[8] / 10), (PWG_details[9] / 10));

		PWG_details[10] = stfr_Sec_Mod;
		cout << "Stiffener sec mod " << stfr_Sec_Mod;
		PWG_details[18] = stfr_MOI;

		if (((D > 61) && (stfr_MOI > PWG_details[16]) && (stfr_Sec_Mod > PWG_details[0]) && (PWG_details[6] >= PWG_width_min)) || ((D <= 61) && (stfr_Sec_Mod > PWG_details[0]) && (PWG_details[6] >= PWG_width_min)))

		{
			PWG_details[11] = PWG_details[6];
			PWG_details[12] = PWG_details[7];
			PWG_details[13] = PWG_details[8];
			PWG_details[14] = PWG_details[9];
			PWG_details[15] = PWG_details[10];
			PWG_details[19] = PWG_details[18];
		}
	}
	else
	{
		PWG_details[10] = 0;
		PWG_details[18] = 0;
	}

}









void PWG_Properties()
{

	shell_Stiffener_Location();

	double H_Pwg, web_width, web_thk, flg_width, flg_thk;

	double w_shell_top, w_shell_bot;
	int j, k;

	H_Pwg = 0; web_width = 0; web_thk = 0; flg_width = 0; flg_thk = 0;  w_shell_top = 0; w_shell_bot = 0;

	if ((D > 61) && (Option_PWG == 1))

	{
		PWG_details[0] = (pow(61, 2) * H / 17)* pow((V / 190), 2);						// Required Sec. Mod
		PWG_details[16] = 3583 * H* pow(61, 3)* pow((V / 190), 2) / Y_mod;		// Required MOI

	}

	else
	{
		PWG_details[0] = (pow(D, 2) * H / 17)* pow((V / 190), 2);						// Required Sec. Mod
		PWG_details[16] = 3583 * H* pow(D, 3)* pow((V / 190), 2) / Y_mod;		// Required MOI
	}

	H_Pwg = (H - Spacing_Top_WG);


	// calculating the serial number (l) of shell on which the Pwg is located.



	j = Shell_Course_No_Actual(H_Pwg);


	if (option_Stfr == 0)
		PWG_shell_thk = shell_detail[j][18] / 10;		// t is the thickness of shell in cm on which stiffener is located

	else
		PWG_shell_thk = shell_detail[j][19] / 10;


	if (Spacing_Top_WG > ((16 * PWG_shell_thk) / 100)) // comparison in M

		w_shell_top = (16 * PWG_shell_thk);
	else
		w_shell_top = Spacing_Top_WG * 100;

	w_shell_bot = (16 * PWG_shell_thk);
	PWG_shell_width = w_shell_top + w_shell_bot;


	if (PWG_width_min < 0.5) // if it is equal to zero
		web_width = 7.5;


	else web_width = PWG_width_min / 10;

	//	PWG_details[7] = PWG_Thick_Web;
	//	PWG_details[8] = PWG_Height_Flange;
	//	PWG_details[9] = PWG_Thick_Flange;


	if (PWG_Height_Flange >= 50) // user defined flange height in mm
		flg_width = (PWG_Height_Flange / 10); // user specified flange height is used in the default also

	else
	{
		if (web_width <= 15) flg_width = web_width;
		else flg_width = 15;
	}

	if (PWG_Thick_Web >= 6) // user defined web thickness in mm

		web_thk = (PWG_Thick_Web / 10); // user specified web thickness is used in the default also

	else 	web_thk = 0.6;


	if (PWG_Thick_Flange >= 6)
		flg_thk = (PWG_details[9] / 10);

	else flg_thk = 0.6;

	k = 0; // changes to 1 when all required conditions for the stiffener ring are fulfilled


	while (k < 0.5)

	{
		PWG_MOI(PWG_shell_width, PWG_shell_thk, web_width, web_thk, flg_width, flg_thk);

		if (D > 61.0)

		{
			if ((stfr_MOI > PWG_details[16]) && (stfr_Sec_Mod > PWG_details[0]))
				k = 1;
		}

		else
		{
			if (stfr_Sec_Mod > PWG_details[0])
				k = 1;
		}

		if (k != 1)
		{
			web_width = web_width + 2.5;

			if (PWG_Height_Flange < 0.5)
			{
				if (web_width < 15) flg_width = web_width;
				else flg_width = 15;
			}
			else
				flg_width = PWG_Height_Flange / 10;

		}

		else
		{
			PWG_details[11] = PWG_details[1] = web_width * 10;
			PWG_details[12] = PWG_details[2] = web_thk * 10;
			PWG_details[13] = PWG_details[3] = flg_width * 10;     // the minimum size of the stiffener meeting the code requirement is assigned to the default section
			PWG_details[14] = PWG_details[4] = flg_thk * 10;
			PWG_details[15] = PWG_details[5] = stfr_Sec_Mod;
			PWG_details[19] = PWG_details[17] = stfr_MOI;         // MOI of default section


		}



	} // end of while loop for default PWG size





	/*
	//	if ((PWG_Width_Web > 0) && (PWG_Thick_Web >= 6) && (PWG_Height_Flange > 0) & (PWG_Thick_Flange >= 6))

	if ((PWG_details[6] > 0) && (PWG_details[7] > 0) && (PWG_details[8] > 0) && (PWG_details[9] > 0))

	{


	//		PWG_MOI(PWG_shell_width, PWG_shell_thk, (PWG_Width_Web / 10), (PWG_Thick_Web / 10), (PWG_Height_Flange / 10), (PWG_Thick_Flange / 10));

	PWG_MOI(PWG_shell_width, PWG_shell_thk, web_width, web_thk, flg_width, flg_thk);

	PWG_details[10] = stfr_Sec_Mod;
	PWG_details[18] = stfr_MOI;

	if (((D > 61) && (stfr_MOI > PWG_details[16]) && (stfr_Sec_Mod > PWG_details[0])) || ((D <= 61) && (stfr_Sec_Mod > PWG_details[0])))

	{
	PWG_details[11] = PWG_details[6];
	PWG_details[12] = PWG_details[7];
	PWG_details[13] = PWG_details[8];
	PWG_details[14] = PWG_details[9];
	PWG_details[15] = PWG_details[10];
	PWG_details[19] = PWG_details[18];



	}




	}


	*/



} //  end of function PWG_Properties()













void PWG_MOI(double temp19, double temp20, double temp21, double temp22, double temp23, double temp24)

{
	double temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9,
		temp10, temp11, temp12, temp13, temp14, temp15, temp16, temp17, temp18;

	temp1 = (temp19* temp20 * temp20 / 2);											//a1di
	temp2 = (temp21 * temp22 * (temp20 + (temp21 / 2)));							// a2d2
	temp3 = (temp23 * temp24 * (temp20 + temp21 + (temp24 / 2)));					// a3d3

	temp4 = temp1 + temp2 + temp3;													// *Sum a*d
	temp5 = temp4 / ((temp19 * temp20) + (temp21  * temp22) + (temp23 * temp24));	// * x': distance to combined CG from inner surface of shell.

	temp6 = (temp5 - (temp20 / 2));													// distance of Cg of shell from combined CG.
	temp7 = ((temp20 + (temp21 / 2) - temp5));										// distance of CG of web from combine CG.
	temp8 = (temp20 + temp21 + (temp24 / 2) - temp5);										// distance of CG of flg from combined CG.

	temp9 = (temp19* temp20)* pow(temp6, 2);										// a1*x1^2
	temp10 = ((temp21  * temp22)) * pow(temp7, 2);									// a2*x2^2
	temp11 = ((temp23  * temp24)) * pow(temp8, 2);									// a3*x3^2

	temp12 = pow(temp20, 3) * temp19 / 12;											// MOI of shell on its own CG
	temp13 = pow(temp21, 3) * temp22 / 12;											// MOI of web on its own CG
	temp14 = pow(temp24, 3) * temp23 / 12;											// MOI of flange on its own CG

	temp15 = temp9 + temp10 + temp11 + temp12 + temp13 + temp14;					// Total MOI of composite section
	temp16 = temp20 + temp21 + temp24 - temp5;										// distance from combined CG to outer most fibre.
	temp17 = max(temp5, temp16, temp5, temp5, temp5, temp5, 2);						// distance to farthest fibre
	temp18 = (temp15 / temp17); 														// section modulus


	stfr_MOI = temp15;
	stfr_Sec_Mod = temp18;

	/*
	int l;

	cout << endl << "Thk of Shell  mm.			  =	" << fixed << setprecision(1) << (temp20 * 10) << endl << endl;
	cout << endl << "width of Shell	mm			  =	" << fixed << setprecision(1) << (temp19 * 10) << endl << endl;
	cout << endl << "Width of Web mm			  =	" << fixed << setprecision(1) << (temp21 * 10) << endl << endl;
	cout << endl << "Thickness of Web mm		  =	" << fixed << setprecision(1) << (temp22 * 10) << endl << endl;
	cout << endl << "Height of flange			  =	" << fixed << setprecision(1) << (temp23 * 10) << endl << endl;
	cout << endl << "Thickness of flange			  =	" << fixed << setprecision(1) << (temp24 * 10) << endl << endl;
	cout << endl << "Section Modulus Available			  =	" << fixed << setprecision(2) << temp18 << endl << endl;
	cout << endl << "Section Modulus Required for the PWG			  =	" << fixed << setprecision(2) << PWG_details[0] << endl << endl;
	if (D > 61)
	{
	cout << endl << "MOI Available			  =	" << fixed << setprecision(2) << temp15 << endl << endl;
	cout << endl << "MOI Required			  =	" << fixed << setprecision(2) << PWG_details[16] << endl << endl;

	}

	cout << endl << "Enter Zero to Proceed			=	";
	cin >> l;

	*/








}






void shell_Stfr_User_EL_Data()
{
	int i, n, c;

	shell_Stfr_User_EL();

	for(int i=0;i<No_of_Stiffeners_R;i++)
	{
		cout<<user_EL_detail[i][9]<<" "<<user_EL_detail[i][10]<<endl;
	}


	if (edit_option == 0)
	{

		// The following Lines before the "for" statement are added on 30/08/2018 to match it with UI:

		cout << endl << "The Number of stiffener required is  =    " << No_of_Stiffeners << endl;
		cout << endl << "Enter Revised Revised Number of Stiffeners (minimum 1)   	 " << endl;
		cout << endl << "Enter zero for no change :    ";
		cin >> No_of_Stiffeners_Max_user;

		if (No_of_Stiffeners_Max_user == 0) No_of_Stiffeners_Max = 20;
		else
			No_of_Stiffeners_Max = No_of_Stiffeners_Max_user;

		if (No_of_Stiffeners != No_of_Stiffeners_Max)
		{
			shell_Stiffener_Location();
			shell_Stfr_User_EL();

		}

		for (n = 0; n <= (No_of_Stiffeners_R - 1); n++)
		{

			cout << endl << "Max. Possible Elevation of Stiffener Number " << (n + 1) << " =	" << fixed << setprecision(3) << user_EL_detail[n][4] << "	M" << endl;
			cout << endl << "Min. Possible Elevation of Stiffener Number " << (n + 1) << " =	" << fixed << setprecision(3) << user_EL_detail[n][2] << "	M" << endl;
			cout << endl << "Proposed Elevation of Stiffener Number	" << (n + 1) << " =	" << fixed << setprecision(3) << user_EL_detail[n][6] << "	M" << endl;

			cout << endl << "Enter Revised Elevation of Stiffener		" << endl;
			cout << endl << "Enter zero for no change :	";
			// cin >> stfr_detail_user[n][0];
			stfr_detail_user[n][0] = 0;

			user_EL_detail[n][8] = stfr_detail_user[n][0];

			if ((user_EL_detail[n][8] > user_EL_detail[n][4]) || (user_EL_detail[n][8] < user_EL_detail[n][2]))
			{
				if (user_EL_detail[n][8] > 0.16) // means not equal to zero
				{
					cout << endl << "User defined elevation is not within the specified range"
						<< endl << "Revise the elevation of siffener" << endl;

					// this logic will work in the form only, where it should be shown in a message box (as a change in any input variable (user_EL_detail[n][8]) will cause
					// all of these calculations to repeat). In the console program, second line will be   "<< endl << "Usr defined elevation is ignored" << endl;
				}
			}

			else
			{
				shell_Stfr_User_EL();

				cout << endl << "Spacing between stiffener and shell joint at top	=	" << user_EL_detail[n][9] << endl << endl;
				cout << endl << "Spacing between stiffener and shell joint at bottom	=	" << user_EL_detail[n][10] << endl << endl;



				if ((user_EL_detail[n][9] < Spacing_Min) || (user_EL_detail[n][10] < Spacing_Min))
				{

					cout << endl << "The Spacing between the Proposed Elevation of stiffener and a shell joint"
						<< endl << "is less than permissible. Revise the elevation of siffener" << endl;

					// this logic will work in the form only, as a change in the any input variable (user_EL_detail[n][8]) will cause all of
					// these calculations to repeat. In the console program, second line will be   "<< endl << "is less than permissible. Usr defined elevation is ignored" << endl;

				}

			}

			cout << endl << "Adopted Elevation	=	" << stfr_detail[n][16] << endl << endl;


		} // end of for statement

		if (Pe > 0.2500001)

		{
			for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)

			{
				if (i == 0)

				{

					cout << endl << "Select material for First stiffener from top:	" << endl;
					cout << endl << " Enter Serial Number of Material 			=	";
					// cin >> c;

					c = 6;
					stfr_Mat_No[i] = c;
				}


				else
				{

					cout << endl << "Material for Siffener Serial Number " << (i + 1) << endl;

					cout << endl << " Enter Serial Number of Material 			" << endl;
					cout << endl << "(Enter '0' if same as previous )		=		";
					//cin >> c;


					c = 0;
					if (c < 0.1)
						stfr_Mat_No[i] = stfr_Mat_No[(i - 1)];
					else
						stfr_Mat_No[i] = c;

				}

				shell_Stfr_User_EL();

			} // end of for statement



		} // end of if statement

	for(int i=0;i<No_of_Stiffeners_R;i++)
	{
		cout<<user_EL_detail[i][9]<<" "<<user_EL_detail[i][10]<<endl;
	}

	}

	// End of Edit Option

	else
	{
		option_ReEdit=0;
		if (option_ReEdit == 1)

		{

			cout << endl << "The Number of stiffener required is  =    " << No_of_Stiffeners << endl;
			cout << endl << "Enter Revised Revised Number of Stiffeners (minimum 1)   	 " << endl;
			cout << endl << "Enter zero for no change :    ";
			cin >> No_of_Stiffeners_Max_user;

			if (No_of_Stiffeners_Max_user > 0)
			{
				No_of_Stiffeners_Max = No_of_Stiffeners_Max_user;
				tu_min = 0;
			}
			shell_Design();
			shell_Stiffener_Location();
			shell_Stfr_User_EL();

			for (n = 0; n <= (No_of_Stiffeners_R - 1); n++)
			{

				cout << endl << "Max. Possible Elevation of Stiffener Number " << (n + 1) << " =	" << fixed << setprecision(3) << user_EL_detail[n][4] << "	M" << endl;
				cout << endl << "Min. Possible Elevation of Stiffener Number " << (n + 1) << " =	" << fixed << setprecision(3) << user_EL_detail[n][2] << "	M" << endl;
				cout << endl << "Adopted Elevation of Stiffener Number	" << (n + 1) << " =	" << fixed << setprecision(3) << stfr_detail[n][16] << "	M" << endl;

				cout << endl << "Enter Revised Elevation of Stiffener		" << endl;
				cout << endl << "Enter zero for no change :	";
				cin >> stfr_detail_user[n][0];
				// stfr_detail_user[n][0] = 0;

				user_EL_detail[n][8] = stfr_detail_user[n][0];

				if ((user_EL_detail[n][8] > user_EL_detail[n][4]) || (user_EL_detail[n][8] < user_EL_detail[n][2]))
				{
					if (user_EL_detail[n][8] > 0.16) // means not equal to zero
					{
						cout << endl << "User defined elevation is not within the specified range"
							<< endl << "Revise the elevation of siffener" << endl;

						// this logic will work in the form only, where it should be shown in a message box (as a change in any input variable (user_EL_detail[n][8]) will cause
						// all of these calculations to repeat). In the console program, second line will be   "<< endl << "Usr defined elevation is ignored" << endl;
					}
				}

				else
				{
					shell_Stfr_User_EL();

					cout << endl << "Spacing between stiffener and shell joint at top	=	" << user_EL_detail[n][9] << endl << endl;
					cout << endl << "Spacing between stiffener and shell joint at bottom	=	" << user_EL_detail[n][10] << endl << endl;



					if ((user_EL_detail[n][9] < Spacing_Min) || (user_EL_detail[n][10] < Spacing_Min))
					{

						cout << endl << "The Spacing between the Proposed Elevation of stiffener and a shell joint"
							<< endl << "is less than permissible. Revise the elevation of siffener" << endl;

						// this logic will work in the form only, as a change in the any input variable (user_EL_detail[n][8]) will cause all of
						// these calculations to repeat. In the console program, second line will be   "<< endl << "is less than permissible. Usr defined elevation is ignored" << endl;

					}

				}

				cout << endl << "Adopted Elevation	=	" << stfr_detail[n][16] << endl << endl;


			} // end of for statement




		} // end of option_ReEdit
		if (No_of_Stiffeners_Max_user == 0)
			No_of_Stiffeners_Max = 20;
		else
			No_of_Stiffeners_Max = No_of_Stiffeners_Max_user;

		if (No_of_Stiffeners != No_of_Stiffeners_Max)
		{
			shell_Stiffener_Location();
			shell_Stfr_User_EL();
		}

		for (n = 0; n <= (No_of_Stiffeners_R - 1); n++)
		{

			user_EL_detail[n][8] = stfr_detail_user[n][0];
			shell_Stfr_User_EL();

		}
		// end of new lines added on 30/08
	}



} // end of function shell_Stfr_User_EL_Data()










void Stiffener_Prop_User_Data()

{
	int i;




	/*
	This data is given for building drop down in sub-screen 4b cell G (+H+I+J)
	assign serial number 0 to 74 for data. when user selects a section, assign the serial number to the variable:

	string stfnr_section_Name[] = { "L200x200x24", "L200x200x20", "L200x200x18", "L180x180x18", "L200x200x16",
	"L200x150x18", "L180x180x16", "L150x150x18", "L200x150x15", "L160x160x15",
	"L150x150x15", "L200x100x15", "L200x150x12", "L200x100x12", "L150x150x12",
	"L150x90x15 ", "L120x120x15", "L150x75x15 ", "L130x130x12", "L150x150x10",
	"L200x100x10", "L150x100x12", "L120x120x12", "L150x100x10", "L100x100x15",
	"L150x90x12 ", "L150x75x12 ", "L150x90x10 ", "L120x120x10", "L150x75x10 ",
	"L100x75x12 ", "L150x75x9  ", "L125x75x10 ", "L135x65x10 ", "L120x120x8 ",
	"L90x90x10  ", "L135x65x8  ", "L100x100x8 ", "L90x90x9   ", "L125x75x12 ",
	"L100x100x12", "L90x90x12  ", "L100x100x10", "L100x65x10 ", "L125x75x8  ",
	"L120x80x12 ", "L120x80x10 ", "L100x75x10 ", "L120x80x8  ", "L90x90x8   ",
	"L100x75x8  ", "L80x80x10  ", "L70x70x10  ", "L100x65x8  ", "L80x80x8   ",
	"L90x90x7   ", "L100x50x8  ", "L75x75x8   ", "L100x65x7  ", "L100x50x6  ",
	"L80x60x8   ", "L90x90x6   ", "L70x70x8   ", "L75x50x8   ", "L70x70x7   ",
	"L80x60x7   ", "L80x80x6   ", "L80x40x8   ", "L75x75x6   ", "L70x70x6   ",
	"L80x60x6   ", "L65x65x7   ", "L65x65x6   " };
	*/

	if (edit_option == 0)
	{
		for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
		{
			cout << endl << "Serial No of angle selected  for stiffener Number:	" << (i + 1) << "	" << stfr_Sec_No[i][0] << endl;
			cout << endl << "Size of angle selected  for stiffener Number:	" << (i + 1) << "	" << Stfnr_Section[i][0] << endl;
			cout << endl << "Enter Type of revised stifener ring for stiffener Number:	" << (i + 1) << endl;
			cout << endl << "(0 for angle, 1 for built-up			=	";
			// cin >> stfr_detail_user[i][1];  //stfr_detail[i][50];

			stfr_detail_user[i][1] = 0;

			stfr_detail[i][50] = stfr_detail_user[i][1];


			if (stfr_detail[i][50] < 0.5)  // if type of stfr is angle
			{

				cout << endl << "Enter serial number of angle section ";
				cout << endl << "(Enter 0 for no change)			=	";
				// cin >> stfr_Sec_No[i][1];

				stfr_Sec_No[i][1] = 0;
			}

			else if (stfr_detail[i][50] > 0.5)  // if type of stfr is "built-up".
			{

				cout << endl << "Size of section selected  for stiffener Number:	" << (i + 1) << "	" << Stfnr_Section[i][0];
				cout << endl << "Enter details of revised section :	";
				cout << endl << "Enter Width of web   :	";
				cin >> stfr_Prop_user[i][0];
				cout << endl << "Enter Thickness of web   :	";
				cin >> stfr_Prop_user[i][1];
				cout << endl << "Enter Height of flange   :	";
				cin >> stfr_Prop_user[i][2];
				cout << endl << "Enter thickness of of flange   :	";
				cin >> stfr_Prop_user[i][3];
			}


		}

		Stiffener_Prop_User();

	}

	else
	{
		option_ReEdit=0;
		if (option_ReEdit == 1)

		{

			for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
			{
				cout << endl << "Serial No of angle selected  for stiffener Number:	" << (i + 1) << "	" << stfr_Sec_No[i][0] << endl;
				cout << endl << "Size of angle selected  for stiffener Number:	" << (i + 1) << "	" << Stfnr_Section[i][0] << endl;
				cout << endl << "Enter Type of revised stifener ring for stiffener Number:	" << (i + 1) << endl;
				cout << endl << "(0 for angle, 1 for built-up			=	";
				// cin >> stfr_detail_user[i][1];  //stfr_detail[i][50];

				stfr_detail_user[i][1] = 0;

				stfr_detail[i][50] = stfr_detail_user[i][1];


				if (stfr_detail[i][50] < 0.5)  // if type of stfr is angle
				{

					cout << endl << "Enter serial number of angle section ";
					cout << endl << "(Enter 0 for no change)			=	";
					// cin >> stfr_Sec_No[i][1];

					stfr_Sec_No[i][1] = 0;
				}

				else if (stfr_detail[i][50] > 0.5)  // if type of stfr is "built-up".
				{

					cout << endl << "Size of section selected  for stiffener Number:	" << (i + 1) << "	" << Stfnr_Section[i][0];
					cout << endl << "Enter details of revised section :	";
					cout << endl << "Enter Width of web   :	";
					cin >> stfr_Prop_user[i][0];
					cout << endl << "Enter Thickness of web   :	";
					cin >> stfr_Prop_user[i][1];
					cout << endl << "Enter Height of flange   :	";
					cin >> stfr_Prop_user[i][2];
					cout << endl << "Enter thickness of of flange   :	";
					cin >> stfr_Prop_user[i][3];
				}


			}

			Stiffener_Prop_User();

		}//end of option ReEdit


		for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
		{

			stfr_detail[i][50] = stfr_detail_user[i][1];


		}
		Stiffener_Prop_User();

	}

	// cout << endl << "Size of section selected  for stiffener Number:	" << (i+1) <<"	" << Stfnr_Section[i][2];




}  // end of function Stiffener_Prop_User_Data()










void Roof_Data()

{


	Roof_Type_No=Roof_Type_No_user;
	// List of Variables

	double live_load_default, JE_roof_default, R_Roof_default, dome_radius_min, dome_radius_max;

	string Roof_type[9] = { "Fixed Roof type", "SELF SUPPORTING CONE ROOF", "SELF SUPPORTING DOME / UMBRELLA ROOF", "SUPPORTED CONE ROOF", "SUPPORTED DOME / UMBRELLA ROOF", "STIFFENED CONE ROOF", "STIFFENED DOME ROOF", "GEODESIC ROOF", "No Fixed Roof" };
	live_load_default = 1.0;
	JE_roof_default = 0.35;
	R_Roof_default = (D / 2 + (shell_detail[(No_of_ShellCourses - 1)][18] / 2000) + 0.012);

	if ((Roof_Type_No_user == 2) || (Roof_Type_No_user == 4) || (Roof_Type_No_user == 6))
	{
		if (Roof_Type_No_user != 2)
		{
			dome_radius_min = 0.8*D;
			dome_radius_max = 1.2*D;
		}

		else
		{
			dome_radius_min = 0.8*D;
			dome_radius_max = 10 * D; // Hold

		}

	}


	if (edit_option == 0)
	{
		cout << endl << "Roof Type (User)		=	" << Roof_Type_user << endl << endl;
		cout << endl << "Roof Type Number (User)	 =	" << Roof_Type_No_user << endl << endl;
		cout << endl << "Hor. Radius at the Base of Roof (default = " << fixed << setprecision(3) << R_Roof_default << " )=	";
		cin >> R_Roof_user;


		if (R_Roof_user >= ((D / 2) - 0.012))
			R_Roof = R_Roof_user;
		else
			R_Roof = R_Roof_default;



		cout << endl << "Frangible roof to shell joint required?	(1 for Y; 0 for N) =	";
		cin >> option_frangible_roof;




		cout << endl << "Design Live Load on Roof in Kpa as per code =	" << fixed << setprecision(1) << live_load_default << endl << endl;
		cout << endl << "Design Live Load on Roof in Kpa (Enter 0 if same as" << live_load_default << ")		=	";
		cin >> live_load_user;



		if (live_load_user < 0.72)
			live_load = live_load_default;
		else
			live_load = live_load_user;

		cout << endl << "Design Snow Load (Balanced) on Roof in Kpa	=	";
		cin >> snow_load_bal;



		cout << endl << "Design Snow Load (Un-Balanced) on Roof in Kpa	=	";
		cin >> snow_load_unbal;



		//if (Roof_Type_No_user == 1)

		if (Roof_Type_No_user == 1)
		{

			cout << endl << "Enter Slope of Roof " << endl;
			cout << endl << "It should be between  (2/12) & (9/12)		=	" << endl;
			cin >> roof_slope_user;


			if (roof_slope_user < 0.166667)
				roof_slope = 0.166667;

			else if (roof_slope_user > 0.75)
				roof_slope = 0.75;
			else roof_slope = roof_slope_user;

		}


		else if ((Roof_Type_No_user == 3) || (Roof_Type_No_user == 5))

		{

			cout << endl << "Enter Slope of Roof " << endl;
			cout << endl << "It should be More than (1/16)		=	";
			cin >> roof_slope_user;


			if (roof_slope_user < 0.0625)
				roof_slope = 0.0625;

			else roof_slope = roof_slope_user;

		}

		else if ((Roof_Type_No_user == 2) || (Roof_Type_No_user == 4) || (Roof_Type_No_user == 6))

		{

			cout << endl << "Enter Radius of the Dome roof " << endl;
			cout << endl << "It should be between  " << dome_radius_min << "	&	" << dome_radius_max << "	=	" << endl;
			cin >> dome_radius_user;
			dome_radius_user = D;

			if (dome_radius_user < dome_radius_min)
				dome_radius = dome_radius_min;

			else if (dome_radius_user > dome_radius_max)
				dome_radius = dome_radius_max;

			else dome_radius = dome_radius_user;
		}

		// The following data entry is added on 24/08/2018 as this was missing, though this part is altrady included in the UI for Roof Design.

		if (Roof_Type_No_user != 8)
		{
			if (Roof_Type_No_user == 7)
				cout << endl << "Weight of GEODESIC Roof 	=	" << Wt_Roof_Str_defaut << endl;
			else
			{
				cout << endl << "As-Built Weight of Roof Structure 	=	" << Wt_Roof_Str_defaut << endl;
				cout << endl << "Enter revised weight of Roof Structure 	" << endl;
				cout << endl << "(Enter '0' for no change)" << "=	";
				cin >> Wt_Roof_Str_user;
				if (Wt_Roof_Str_user == 0) Wt_Roof_Str = Wt_Roof_Str_defaut;
				else
					Wt_Roof_Str = Wt_Roof_Str_user;

				cout << endl << "Corroded Weight of Roof Structure 	=	" << (0.85 * Wt_Roof_Str_defaut) << endl;
				cout << endl << "Enter Corroded weight of Roof Structure 	" << endl;
				cout << endl << "(Enter '0' for no change)" << "=	";
				cin >> Wt_Roof_Str_cor;
				if (Wt_Roof_Str_cor == 0) Wt_Roof_Str_cor = (0.85 * Wt_Roof_Str_defaut);

			}

			if ((Roof_Type_No_user == 3) || (Roof_Type_No_user == 4))

			{
				double temp1;
				cout << endl << "Percentage of weight of Roof Plate & structre supported on sgell 	=	" << 100 << endl;
				cout << endl << "Enter revised percentage supported on shell 	" << endl;
				cout << endl << "(Enter '0' for no change)" << "=	";
				cin >> temp1;
				fraction_roof_weight = (temp1 / 100);


			}





		}




		if ((P > 0.385) && (Roof_Type_No_user <= 6))

		{

			cout << endl << "Joint Efficiency of Roof = ";
			cin >> JE_roof_user;
			if (JE_roof_user == 0) JE_roof_user = 0.35;

			if (JE_roof_user < JE_roof_default)
				JE_roof = JE_roof_default;
			else if (JE_roof_user > 1.0)
				JE_roof = 1.0;
			else
				JE_roof = JE_roof_user;
		}

		if (Roof_Type_No_user <= 6)
		{
			cout << endl << "Select material for Roof:	" << endl;
			cout << endl << "Enter Serial Number of Material 	=	";
			cin >> Roof_Material_No;

			if (Roof_Material_No == 0)
				Roof_Material_No = 6;


			Roof_Design();

			cout << endl << "Required Thickness of roof  =  " << fixed << setprecision(1) << Roof_Thk[6] << endl << endl;
			cout << endl << "Enter Thickness of Roof (Enter 0 if same as" << Roof_Thk[6] << ")		=	";
			cin >> Roof_Thk_user;


			Roof_Thk[7] = Roof_Thk_user;

			if ((JE_roof < 0.7) && (Roof_Thk[8] > 13.0))
			{
				JE_roof = 0.7;
				Roof_Design();
			}

			if ((Roof_Type_No_user == 3) || (Roof_Type_No_user == 5))
				cout << endl << "Maximum Permitted Spacing between rafters is (mm)  =  " << fixed << setprecision(0) << Rafter_spacing << endl << endl;


		}

	} // end of New file option







	else
	{


		if (R_Roof_user >= ((D / 2) - 0.012))
			R_Roof = R_Roof_user;
		else
			R_Roof = R_Roof_default;


		if (live_load_user < 0.72)
			live_load = live_load_default;
		else
			live_load = live_load_user;


		if (Roof_Type_No_user == 1)
		{

			if (roof_slope_user < 0.166667)
				roof_slope = 0.166667;

			else if (roof_slope_user > 0.75)
				roof_slope = 0.75;
			else roof_slope = roof_slope_user;

		}


		else if ((Roof_Type_No_user == 3) || (Roof_Type_No_user == 5))

		{

			if (roof_slope_user < 0.0625)
				roof_slope = 0.0625;

			else roof_slope = roof_slope_user;

		}

		else if ((Roof_Type_No_user == 2) || (Roof_Type_No_user == 4) || (Roof_Type_No_user == 6))

		{

			if (dome_radius_user < dome_radius_min)
				dome_radius = dome_radius_min;

			else if (dome_radius_user > dome_radius_max)
				dome_radius = dome_radius_max;

			else dome_radius = dome_radius_user;
		}

		if (Wt_Roof_Str_user == 0) Wt_Roof_Str = Wt_Roof_Str_defaut;
		else
			Wt_Roof_Str = Wt_Roof_Str_user;





		if (JE_roof_user < JE_roof_default)
			JE_roof = JE_roof_default;

		else if (JE_roof_user > 1.0)
			JE_roof = 1.0;
		else
			JE_roof = JE_roof_user;

		Roof_Thk[7] = Roof_Thk_user;


		if (Roof_Type_No_user <= 6)

		{
			Roof_Thk[7] = Roof_Thk_user;
			Roof_Design();


			if ((JE_roof < 0.7) && (Roof_Thk[8] > 13.0))
			{
				JE_roof = 0.7;

				Roof_Design();
			}



		}

	} // end of edit option


	if ((Roof_Thk[5] - CA_Roof) > 13.0)
	{
		if (Roof_Type_No_user == 1)
			(Roof_Type_No = 3);
		if (Roof_Type_No_user == 2)
			(Roof_Type_No = 4);
		Roof_Design();
		JE_roof = JE_roof_default;
	}

	Roof_Type = Roof_type[Roof_Type_No];
	Roof_Type_user = Roof_type[Roof_Type_No_user];

} // end of function Roof_Data()






void PopulateVariables(InputData& inputData)
{
	inputData.D_User = D_User;
	inputData.H = H;
	inputData.H_td_user = H_td_user;
	inputData.H_tt_user = H_tt_user;
	inputData.H_Norm_user = H_Norm_user;
	inputData.H_Seis_user = H_Seis_user;
	inputData.G = G;
	inputData.Gw = Gw;
	inputData.T = T;
	inputData.MDMT = MDMT;
	inputData.P = P;
	inputData.Fp = Fp;
	inputData.Po_user = Po_user;
	inputData.Pe = Pe;
	inputData.Fpe = Fpe;
	inputData.CA_Bot = CA_Bot;
	inputData.CA_Roof = CA_Roof;
	inputData.JE_user = JE_user;
	inputData.CA_FR = CA_FR;



	inputData.kz_user = kz_user;
	inputData.kzt_user = kzt_user;
	inputData.kd_user = kd_user;
	inputData.basic_v_user = basic_v_user;
	inputData.imp_factorW_user = imp_factorW_user;
	inputData.gust_factor_user = gust_factor_user;
	inputData.V_user = V_user;
	inputData.S0_user = S0_user;
	inputData.Ss_user = Ss_user;
	inputData.S1_user = S1_user;
	inputData.Fa_user = Fa_user;
	inputData.Fv_user = Fv_user;
	inputData.Factor_Q = Factor_Q;
	inputData.TL_user = TL_user;
	inputData.K_user = K_user;

	for (int i = 0; i <= 14; i++)
	{
		for (int j = 0; j<5; j++)
		{
			inputData.shell_detail_user[i][j] = shell_detail_user[i][j];
		}
	}


	for (int i = 0; i <= 44; i++)
	{
		inputData.stfr_detail_user[i][0] = stfr_detail_user[i][0];
		inputData.stfr_detail_user[i][1] = stfr_detail_user[i][1];
		for (int j = 0; j<4; j++)
			inputData.stfr_Prop_user[i][j] = stfr_Prop_user[i][j];
	}


	inputData.Spacing_Top_WG_User = Spacing_Top_WG_User;
	inputData.PWG_width_min_user = PWG_width_min_user;

	inputData.R_Roof_user = R_Roof_user;
	inputData.live_load_user = live_load_user;
	inputData.snow_load_bal = snow_load_bal;
	inputData.snow_load_unbal = snow_load_unbal;


	inputData.dome_radius_user = dome_radius_user;
	inputData.JE_roof_user = JE_roof_user;
	inputData.Roof_Thk_user = Roof_Thk_user;
	inputData.D_Type = D_Type;
	inputData.Option_P = Option_P;
	inputData.Shell_Appendx_No_user = Shell_Appendx_No_user;
	inputData.Roof_Type_No_user = Roof_Type_No_user;
	inputData.Roof_Type_No = Roof_Type_No;
	inputData.Shell_Des_Method_No = Shell_Des_Method_No;
	inputData.RoundUP_to = RoundUP_to;
	inputData.option_Stfr = option_Stfr;
	inputData.wind_design_code = wind_design_code;
	inputData.wind_exp_cat = wind_exp_cat;
	inputData.Seismic_design_code = Seismic_design_code;
	inputData.Zone_Number = Zone_Number;
	inputData.site_class = site_class;
	inputData.ASCE_rule = ASCE_rule;
	inputData.SUG = SUG;
	inputData.option_Av = option_Av;


	for (int i = 0; i <= 14; i++)
	{

		inputData.Shell_Material_No[i][0] = Shell_Material_No[i][0];
		inputData.Shell_Material_No[i][1] = Shell_Material_No[i][1];
		inputData.Shell_Material_No[i][2] = Shell_Material_No[i][2];
		// inputData.Shell_Material_No[i][3] = Shell_Material_No[i][3];

	}

	inputData.Option_walkway = Option_walkway;
	inputData.curb_angle_No_user = curb_angle_No_user;
	inputData.Option_PWG = Option_PWG;



	for (int i = 0; i <= 44; i++)
	{

		inputData.stfr_Mat_No[i] = stfr_Mat_No[i];
		inputData.stfr_Sec_No[i][0] = stfr_Sec_No[i][0];
		inputData.stfr_Sec_No[i][1] = stfr_Sec_No[i][1];
		inputData.stfr_Sec_No[i][2] = stfr_Sec_No[i][2];
		//		cout<<"stfr section "<<i<<" "<<stfr_Sec_No[i][1]<<" "<<stfr_Sec_No[i][2];

	}

	inputData.No_of_ShellCourses = No_of_ShellCourses;
	inputData.No_of_Stiffeners_R = No_of_Stiffeners_R;
	inputData.Shell_Appendx_No = Shell_Appendx_No;
	inputData.weight_stair_user = weight_stair_user;
	inputData.weight_adder_user = weight_adder_user;

	inputData.imp_factorS = imp_factorS;
	inputData.Sds = Sds;
	inputData.Sd1 = Sd1;
	inputData.Av = Av;








	// Additional variables from ItemHeader.h by Raghav / Abhishek


	//Roof Data
	inputData.R_Roof_user = R_Roof_user;
	inputData.live_load_user = live_load_user;
	inputData.option_frangible_roof = option_frangible_roof;
	inputData.FR_Type_No = FR_Type_No;
	inputData.Roof_Material_No = Roof_Material_No;
	inputData.snow_load_bal = snow_load_bal;
	inputData.snow_load_unbal = snow_load_unbal;
	inputData.Rafter_spacing = Rafter_spacing;
	inputData.Rafter_spacing_cent = Rafter_spacing_cent;
	inputData.Weight_FR = Weight_FR;
	inputData.WeightAdder_roof_default = WeightAdder_roof_default;
	inputData.WeightAdder_roof_user = WeightAdder_roof_user;
	inputData.WeightAdder_roof = WeightAdder_roof;
	inputData.weight_platform_default = weight_platform_default;
	inputData.weight_platform_user = weight_platform_user;
	inputData.weight_platform = weight_platform;
	inputData.roof_slope_user_numerator = roof_slope_user_numerator;
	inputData.roof_slope_user_denominator = roof_slope_user_denominator;
	inputData.Wt_Roof_Str_defaut = Wt_Roof_Str_defaut;
	inputData.Wt_Roof_Str_user = Wt_Roof_Str_user;
	inputData.Wt_Roof_Str = Wt_Roof_Str;

	//Roof to Shell
	inputData.type_compression_ring = type_compression_ring;



	inputData.CR_Type_No[0] = CR_Type_No[0];
	inputData.CR_Type_No[1] = CR_Type_No[1];

	for (int i = 0; i <= 2; i++)

	{

		inputData.CR_Material_No[i] = CR_Material_No[i];
		inputData.CR_Size[i] = CR_Size[i];
		inputData.t_bar[i] = t_bar[i];
		inputData.w_bar[i] = w_bar[i];
		inputData.l_bar[i] = l_bar[i];
		inputData.t_shell[i] = t_shell[i];
		inputData.w_shell[i] = w_shell[i];

	}


	//Stiffener Elevation
	inputData.No_of_Stiffeners_Max_user = No_of_Stiffeners_Max_user;
	inputData.H_Ts = H_Ts;
	inputData.t_uniform = t_uniform;
	inputData.H_Max_W = H_Max_W;
	inputData.H_Max_Ps = H_Max_Ps;

	for (int i = 0; i <= 44; i++)

	{
		for (int j = 0; j <= 10; j++)

		{
			inputData.user_EL_detail[i][j] = user_EL_detail[i][j];
			if (i == 0)
			{
				cout << user_EL_detail[i][j] << " ";
			}
		}

	}



	for (int i = 0; i <= 44; i++)

	{
		for (int j = 0; j <= 79; j++)

		{
			inputData.stfr_detail[i][j] = stfr_detail[i][j];
		}

	}

	//PWG
	inputData.PWG_Width_Web = PWG_Width_Web;
	inputData.PWG_Width_Web_User = PWG_Width_Web_User;
	inputData.PWG_Thick_Web = PWG_Thick_Web;
	inputData.PWG_Height_Flange = PWG_Height_Flange;
	inputData.PWG_Thick_Flange = PWG_Thick_Flange;


	//defined by Raghav
	inputData.kz_default = kz_default;
	inputData.V_default = V_default;
	inputData.Fa_default = Fa_default;
	inputData.Fv_default = Fv_default;
	inputData.D = D;
	inputData.Gd = Gd;
	inputData.JE = JE;
	inputData.Spacing_Min = Spacing_Min;

	//defined by Abhishek

	inputData.H_Remaining = H_Remaining;

	// For UI PWG


	inputData.PWG_width_min = PWG_width_min;
	inputData.Spacing_Top_WG = Spacing_Top_WG;

	for (int i = 0; i <= 19; i++)
	{
		inputData.PWG_details[i] = PWG_details[i];
	}


	// Additional Variables added by Ashok for transfering the result to UI (sample)



	for (int i = 0; i <= 14; i++)
	{
		inputData.shell_detail[i][10] = shell_detail[i][10];
		inputData.shell_detail[i][11] = shell_detail[i][11];
		inputData.shell_detail[i][12] = shell_detail[i][12];
		inputData.shell_detail[i][13] = shell_detail[i][13];
		inputData.shell_detail[i][15] = shell_detail[i][15];
		inputData.shell_detail[i][18] = shell_detail[i][18];
		inputData.shell_detail[i][27] = shell_detail[i][28];

	}

	// Additional variables from UI Roof Data


	inputData.R_Roof = R_Roof;
	inputData.live_load = live_load;
	inputData.JE_roof = JE_roof;



	// Adde by Ashok on 3rd Sept 2018

	inputData.Wt_Roof_Str_cor = Wt_Roof_Str_cor;
	inputData.fraction_roof_weight = fraction_roof_weight;

	for (int i = 0; i <= 9; i++)
	{
		inputData.Roof_Thk[i] = Roof_Thk[i];
	}
}  //end of function PopulateVariables()


void ReadVariables(InputData& inputData)
{



	D_User = inputData.D_User;
	H = inputData.H;
	H_td_user = inputData.H_td_user;
	H_tt_user = inputData.H_tt_user;
	H_Norm_user = inputData.H_Norm_user;
	H_Seis_user = inputData.H_Seis_user;
	G = inputData.G;
	Gw = inputData.Gw;
	T = inputData.T;
	MDMT = inputData.MDMT;
	P = inputData.P;
	Fp = inputData.Fp;
	Po_user = inputData.Po_user;
	Pe = inputData.Pe;
	Fpe = inputData.Fpe;
	CA_Bot = inputData.CA_Bot;
	CA_Roof = inputData.CA_Roof;
	JE_user = inputData.JE_user;
	CA_FR = inputData.CA_FR;



	kz_user = inputData.kz_user;
	kzt_user = inputData.kzt_user;
	kd_user = inputData.kd_user;
	basic_v_user = inputData.basic_v_user;
	imp_factorW_user = inputData.imp_factorW_user;
	gust_factor_user = inputData.gust_factor_user;
	V_user = inputData.V_user;
	S0_user = inputData.S0_user;
	Ss_user = inputData.Ss_user;
	S1_user = inputData.S1_user;
	Fa_user = inputData.Fa_user;
	Fv_user = inputData.Fv_user;
	Factor_Q = inputData.Factor_Q;
	TL_user = inputData.TL_user;
	K_user = inputData.K_user;

	for (int i = 0; i <= 14; i++)
	{
		for (int j = 0; j<5; j++)
		{
			shell_detail_user[i][j] = inputData.shell_detail_user[i][j];
		}
	}


	for (int i = 0; i <= 44; i++)
	{
		stfr_detail_user[i][0] = inputData.stfr_detail_user[i][0];
		stfr_detail_user[i][1] = inputData.stfr_detail_user[i][1];
		for (int j = 0; j<4; j++)
			stfr_Prop_user[i][j] = inputData.stfr_Prop_user[i][j];
	}


	Spacing_Top_WG_User = inputData.Spacing_Top_WG_User;
	PWG_width_min_user = inputData.PWG_width_min_user;

	R_Roof_user = inputData.R_Roof_user;
	live_load_user = inputData.live_load_user;
	snow_load_bal = inputData.snow_load_bal;
	snow_load_unbal = inputData.snow_load_unbal;

	roof_slope_user = inputData.roof_slope_user;
	dome_radius_user = inputData.dome_radius_user;
	JE_roof_user = inputData.JE_roof_user;
	Roof_Thk_user = inputData.Roof_Thk_user;
	D_Type = inputData.D_Type;
	Option_P = inputData.Option_P;
	Shell_Appendx_No_user = inputData.Shell_Appendx_No_user;
	Roof_Type_No_user = inputData.Roof_Type_No_user;
	Roof_Type_No = inputData.Roof_Type_No;
	Shell_Des_Method_No = inputData.Shell_Des_Method_No;
	RoundUP_to = inputData.RoundUP_to;
	option_Stfr = inputData.option_Stfr;
	wind_design_code = inputData.wind_design_code;
	wind_exp_cat = inputData.wind_exp_cat;
	Seismic_design_code = inputData.Seismic_design_code;
	Zone_Number = inputData.Zone_Number;
	site_class = inputData.site_class;
	ASCE_rule = inputData.ASCE_rule;
	SUG = inputData.SUG;
	option_Av = inputData.option_Av;


	for (int i = 0; i <= 14; i++)
	{
		Shell_Material_No[i][0] = inputData.Shell_Material_No[i][0];
		Shell_Material_No[i][1] = inputData.Shell_Material_No[i][1];
		Shell_Material_No[i][2] = inputData.Shell_Material_No[i][2];
		// Shell_Material_No[i][3] = inputData.Shell_Material_No[i][3];
	}

	Option_walkway = inputData.Option_walkway;
	curb_angle_No_user = inputData.curb_angle_No_user;
	Option_PWG = inputData.Option_PWG;

	for (int i = 0; i <= 44; i++)
	{
		stfr_Mat_No[i] = inputData.stfr_Mat_No[i];
		stfr_Sec_No[i][0] = inputData.stfr_Sec_No[i][0];
		stfr_Sec_No[i][1] = inputData.stfr_Sec_No[i][1];
		stfr_Sec_No[i][2] = inputData.stfr_Sec_No[i][2];
	}

	No_of_ShellCourses = inputData.No_of_ShellCourses;
	No_of_Stiffeners_R = inputData.No_of_Stiffeners_R;
	Shell_Appendx_No = inputData.Shell_Appendx_No;
	weight_stair_user = inputData.weight_stair_user;
	weight_adder_user = inputData.weight_adder_user;

	imp_factorS = inputData.imp_factorS;
	weight_adder_user = inputData.weight_adder_user;
	Sds = inputData.Sds;
	Sd1 = inputData.Sd1;
	Av = inputData.Av;

	// Additional variables from ItemHeader.h by Raghav / Abhishek


	//Roof Data
	R_Roof_user = inputData.R_Roof_user;
	live_load_user = inputData.live_load_user;
	option_frangible_roof = inputData.option_frangible_roof;
	FR_Type_No = inputData.FR_Type_No;
	Roof_Material_No = inputData.Roof_Material_No;
	snow_load_bal = inputData.snow_load_bal;
	snow_load_unbal = inputData.snow_load_unbal;
	Rafter_spacing = inputData.Rafter_spacing;
	Rafter_spacing_cent = inputData.Rafter_spacing_cent;
	Weight_FR = inputData.Weight_FR;
	WeightAdder_roof_default = inputData.WeightAdder_roof_default;
	WeightAdder_roof_user = inputData.WeightAdder_roof_user;
	WeightAdder_roof = inputData.WeightAdder_roof;
	weight_platform_default = inputData.weight_platform_default;
	weight_platform_user = inputData.weight_platform_user;
	weight_platform = inputData.weight_platform;
	roof_slope_user_numerator = inputData.roof_slope_user_numerator;
	roof_slope_user_denominator = inputData.roof_slope_user_denominator;
	Wt_Roof_Str_defaut = inputData.Wt_Roof_Str_defaut;
	Wt_Roof_Str_user = inputData.Wt_Roof_Str_user;
	Wt_Roof_Str = inputData.Wt_Roof_Str;

	//Roof to Shell
	type_compression_ring = inputData.type_compression_ring;

	CR_Type_No[0] = inputData.CR_Type_No[0];
	CR_Type_No[1] = inputData.CR_Type_No[1];

	for (int i = 0; i <= 2; i++)
	{
		CR_Material_No[i] = inputData.CR_Material_No[i];
		CR_Size[i] = inputData.CR_Size[i];
		t_bar[i] = inputData.t_bar[i];
		w_bar[i] = inputData.w_bar[i];
		l_bar[i] = inputData.l_bar[i];
		t_shell[i] = inputData.t_shell[i];
		w_shell[i] = inputData.w_shell[i];
	}


	//Stiffener Elevation
	No_of_Stiffeners_Max_user = inputData.No_of_Stiffeners_Max_user;
	H_Ts = inputData.H_Ts;
	t_uniform = inputData.t_uniform;
	H_Max_W = inputData.H_Max_W;
	H_Max_Ps = inputData.H_Max_Ps;


	for (int i = 0; i <= 44; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			user_EL_detail[i][j] = inputData.user_EL_detail[i][j];
		}
	}

	for (int i = 0; i <= 44; i++)
	{
		for (int j = 0; j <= 79; j++)
		{
			stfr_detail[i][j] = inputData.stfr_detail[i][j];
		}
	}
	//PWG
	PWG_Width_Web = inputData.PWG_Width_Web;
	PWG_Width_Web_User = inputData.PWG_Width_Web_User;
	PWG_Thick_Web = inputData.PWG_Thick_Web;
	PWG_Height_Flange = inputData.PWG_Height_Flange;
	PWG_Thick_Flange = inputData.PWG_Thick_Flange;


	//defined by Raghav
	kz_default = inputData.kz_default;
	V_default = inputData.V_default;
	Fa_default = inputData.Fa_default;
	Fv_default = inputData.Fv_default;
	D = inputData.D;
	Gd = inputData.Gd;
	JE = inputData.JE;
	Spacing_Min = inputData.Spacing_Min;

	//defined by Abhishek

	H_Remaining = inputData.H_Remaining;

	for (int i = 0; i <= 19; i++)
	{
		PWG_details[i] = inputData.PWG_details[i];
	}

	// Additional Variables added by Ashok for transfering the result to UI. Commenetd out because while running, the program was terminating

	for (int i = 0; i <= 14; i++)
	{
		shell_detail[i][10] = inputData.shell_detail[i][10];
		shell_detail[i][11] = inputData.shell_detail[i][11];
		shell_detail[i][12] = inputData.shell_detail[i][12];
		shell_detail[i][13] = inputData.shell_detail[i][13];
		shell_detail[i][15] = inputData.shell_detail[i][15];
		shell_detail[i][18] = inputData.shell_detail[i][18];
		shell_detail[i][27] = inputData.shell_detail[i][28];
	}


	// For UI PWG
	PWG_width_min = inputData.PWG_width_min;
	Spacing_Top_WG = inputData.Spacing_Top_WG;

	// Additional variables from UI Stiffener Elevation

	No_of_Stiffeners_R = inputData.No_of_Stiffeners_R;
	No_of_Stiffeners_Max_user = inputData.No_of_Stiffeners_Max_user;

	// Additional variables from UI Roof Data

	R_Roof = inputData.R_Roof;
	live_load = inputData.live_load;
	JE_roof = inputData.JE_roof;

	// Adde by Ashok on 3rd Sept 2018

	Wt_Roof_Str_cor = inputData.Wt_Roof_Str_cor;
	fraction_roof_weight = inputData.fraction_roof_weight;

	// Adde by Ashok on 7rd Sept 2018

	for (int i = 0; i <= 9; i++)
	{
		Roof_Thk[i] = inputData.Roof_Thk[i];
	}


} // End of function ReadVariables()





// void CompRing_Data()


// End of all Data functions

// Additional functions used along with Data functions

void Material_Selection(int a, double temp1)
{
	int b; // temporary variables

	double TS[] = { 40, 90, 150, 200, 260 };

	if (a <= 100)
	{
		//										   1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20   21   22   23   24   25   26   27   28   29   30   31   32   33   34   35   36   37   38   39   40   41   42   43   44   45   46   47   48   49   50   51   52   53   54   55   56   57   58   59   60   61   62   63   64   65   66   67   68   69   70   71   72   73   74   75   76   77   78   79   80   81   82   83
		double YS_C[83] = { 0, 205, 205, 235, 235, 360, 250, 220, 220, 240, 290, 290, 290, 205, 205, 220, 220, 240, 240, 260, 260, 275, 295, 345, 415, 345, 345, 345, 415, 345, 345, 415, 260, 260, 260, 300, 300, 300, 350, 350, 350, 235, 250, 250, 250, 250, 276, 275, 265, 275, 265, 355, 345, 335, 355, 345, 335, 275, 265, 275, 265, 355, 345, 335, 355, 345, 335, 360, 290, 295, 345, 415, 345, 345, 415, 345, 345, 415, 350, 335, 335, 335, 335 };
		double UTS_C[83] = { 0, 380, 380, 400, 400, 490, 400, 400, 400, 450, 485, 485, 485, 380, 380, 415, 415, 450, 450, 485, 485, 450, 485, 485, 550, 485, 485, 485, 550, 485, 485, 550, 410, 410, 410, 450, 450, 450, 480, 480, 480, 365, 400, 400, 400, 400, 430, 410, 410, 410, 410, 490, 490, 490, 490, 490, 490, 410, 410, 410, 410, 470, 470, 470, 470, 470, 470, 515, 515, 515, 515, 585, 515, 515, 585, 515, 515, 585, 515, 515, 515, 515, 515 };
		double Sd_C[83] = { 0, 137, 137, 157, 157, 196, 160, 147, 147, 160, 193, 193, 193, 137, 137, 147, 147, 160, 160, 173, 173, 180, 194, 194, 220, 194, 194, 194, 220, 194, 194, 220, 164, 164, 164, 180, 180, 180, 192, 192, 192, 137, 157, 157, 157, 157, 167, 164, 164, 164, 164, 196, 196, 196, 196, 196, 196, 164, 164, 164, 164, 188, 188, 188, 188, 188, 188, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309 };
		double St_C[83] = { 0, 154, 154, 171, 171, 220, 171, 165, 165, 180, 208, 208, 208, 154, 154, 165, 165, 180, 180, 195, 195, 193, 208, 208, 236, 208, 208, 208, 236, 208, 208, 236, 176, 176, 176, 193, 193, 193, 206, 206, 206, 154, 171, 171, 171, 171, 184, 176, 176, 176, 176, 210, 210, 210, 210, 210, 210, 176, 176, 176, 176, 201, 201, 201, 201, 201, 201, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 1234, 234, 234 };
		int group_No[83] = { 0, 10, 10, 10, 20, 60, 20, 30, 35, 40, 40, 45, 50, 30, 35, 30, 35, 40, 50, 40, 50, 40, 45, 60, 60, 60, 60, 60, 60, 60, 60, 60, 20, 30, 35, 40, 45, 50, 40, 45, 50, 10, 10, 20, 30, 35, 40, 40, 40, 45, 45, 40, 40, 40, 45, 45, 45, 40, 40, 45, 45, 40, 40, 40, 45, 45, 45, 60, 40, 45, 60, 60, 60, 60, 60, 60, 60, 60, 50, 40, 45, 40, 45 };

		string Material_Name_C[83] = { "Name",
			"A 283 M-Gr C	",
			"A 285 M-Gr C	",
			"A 131 M-Gr A	",
			"A 131 M-Gr B	",
			"A 131 M-Gr EH 36",
			"A36M		",
			"A 573 M Gr. 400	",
			"A 573 M Gr. 400	",
			"A 573 M Gr. 450	",
			"A 573 M Gr. 485	",
			"A 573 M Gr. 485	",
			"A 573 M Gr. 485	",
			"A 516 M Gr. 380	",
			"A 516 M Gr. 380	",
			"A 516 M Gr. 415	",
			"A 516 M Gr. 415	",
			"A 516 M Gr. 450	",
			"A 516 M Gr. 450	",
			"A 516 M Gr. 485	",
			"A 516 M Gr. 485	",
			"A 662 M Gr. B		",
			"A 662 M Gr. C		",
			"A 537 M Cl-1		",
			"A 537 M Cl-2		",
			"A 663 M Gr. C		",
			"A 663 M Gr. D		",
			"A 678 M Gr. A		",
			"A 678 M Gr. B		",
			"A 737 M Gr. B		",
			"A 841 M Gr. A CL-1	",
			"A 841 M Gr. B CL-2 ",
			"CSA G 40 21M Gr. 260 W	",
			"CSA G 40 21M Gr. 260 W	",
			"CSA G 40 21M Gr. 260 WT	",
			"CSA G 40 21M Gr. 300 W	",
			"CSA G 40 21M Gr. 300 WT	",
			"CSA G 40 21M Gr. 300 WT	",
			"CSA G 40 21M Gr. 350 W	",
			"CSA G 40 21M Gr. 350 W	",
			"CSA G 40 21M Gr. 350 WT	",
			"National Standard Gr. 235",
			"National Standard Gr. 250",
			"National Standard Gr. 250",
			"National Standard Gr. 250",
			"National Standard Gr. 250",
			"National Standard Gr. 275",
			"ISO 630 E 275 C (t <= 16)",
			"ISO 630 E 275 C (t > 16)",
			"ISO 630 E 275 D (t <= 16)",
			"ISO 630 E 275 D (t > 16)",
			"ISO 630 E 355 C (t <= 16)",
			"ISO 630 E 355 C (16 < t <= 40)",
			"ISO 630 E 355 C ( t > 40)",
			"ISO 630 E 355 D (t <= 16)",
			"ISO 630 E 355 D (16 < t <= 40)",
			"ISO 630 E 355 D ( t > 40)",
			"EN 10025 S275 J0 (t <= 16)",
			"EN 10025 S275 J0 (t > 16)",
			"EN 10025 S275 J2 (t <= 16)",
			"EN 10025 S275 J2 (t > 16)",
			"EN 10025 S355 J0 (t <= 16) ",
			"EN 10025 S355 J0 (16 < t <= 40)",
			"EN 10025 S355 J0 ( t > 40)",
			"EN 10025 S355 J2, K2 (t <= 16) ",
			"EN 10025 S355 J2, K2 (16 < t <= 40)",
			"EN 10025 S355 J2, K2 ( t > 40)",
			"A 131 M-Gr EH 36 (High UTS)",
			"A 573 M Gr. 485 (High UTS)",
			"A 662 M Gr. C (High UTS)",
			"A 537 M Cl-1	(High UTS)",
			"A 537 M Cl-2 (High UTS) ",
			"A 663 M Gr. C, D (High UTS)",
			"A 678 M Gr. A	(High UTS)",
			"A 678 M Gr. B	(High UTS)",
			"A 737 M Gr. B	(High UTS)",
			"A 841 M Gr. A CL-1 (High UTS)",
			"A 841 M Gr. B CL-2 (High UTS)",
			"CSA G 40 21M Gr. 350 W (High UTS)",
			"ISO 630 E 355 C ( t > 40) (High UTS)",
			"ISO 630 E 355 D ( t > 40) (High UTS)",
			"EN 10025 S355 J0 ( t > 40) (High UTS)",
			"EN 10025 S355 J2, k2 ( t > 40) (High UTS)" };

		MOC = Material_Name_C[a];

		YS_Atm = YS_C[a], UTS = UTS_C[a], Sd_Atm = Sd_C[a], St = St_C[a], Group_No = group_No[a];
		if ((a <= 66))
		{
			UTS = UTS_C[a];
			Sd_Atm = Sd_C[a];
			St = St_C[a];
		}
		else if (a > 66)
		{
			UTS = temp1;

			if ((2 * YS_Atm / 3) < (2 * UTS / 5))
				Sd_Atm = (2 * YS_Atm / 3);
			else
				Sd_Atm = (2 * UTS / 5);

			if ((3 * YS_Atm / 4) < (3 * UTS / 7))
				St = (3 * YS_Atm / 4);
			else
				St = (3 * UTS / 7);
		}

		if (YS_Atm < 310)
		{
			if (T <= 93) Factor_M = 1.0;
			else if (T <= 94) Factor_M = 0.91;
			else if (T <= 150) Factor_M = (0.91 - (0.03*(T - 94) / 56));
			else if (T <= 200) Factor_M = (0.88 - (0.03*(T - 150) / 50));
			else if (T <= 260) Factor_M = (0.85 - (0.05*(T - 200) / 60));
			else Factor_M = 0.8;
		}
		else if (YS_Atm <= 380)
		{
			if (T <= 93) Factor_M = 1.0;
			else if (T <= 94) Factor_M = 0.88;
			else if (T <= 150) Factor_M = (0.88 - (0.07*(T - 94) / 56));
			else if (T <= 200) Factor_M = (0.81 - (0.06*(T - 150) / 50));
			else if (T <= 260) Factor_M = (0.75 - (0.05*(T - 200) / 60));
			else Factor_M = 0.70;
		}
		else
		{
			if (T <= 93) Factor_M = 1.0f;
			else if (T <= 94) Factor_M = 0.92f;
			else if (T <= 150) Factor_M = (0.92 - (0.05*(T - 94) / 56));
			else if (T <= 200) Factor_M = (0.87 - (0.04*(T - 150) / 50));
			else if (T <= 260) Factor_M = (0.83 - (0.04*(T - 200) / 60));
			else Factor_M = 0.79;
		}

		Y_mod_Atm = 199000;

		if (T <= 93) Y_mod = 199000;
		else if (T <= 150) Y_mod = (199000 - (4000 * (T - 93) / 57));
		else if (T <= 200) Y_mod = (195000 - (4000 * (T - 150) / 50));
		else Y_mod = (191000 - (3000 * (T - 200) / 60));


		if (Factor_M > 0.999)
		{
			YS = YS_Atm;
			Sd = Sd_Atm;
		}
		else
		{
			YS = (YS_Atm * Factor_M);

			if ((2 * YS / 3) < (2 * UTS / 5))
				Sd = (2 * YS / 3);
			else
				Sd = (2 * UTS / 5);
		}
	}
	else if (a < 120)
	{
		string Material_Name_S[9] =
		{ "Material", "A240 TP 201-1	", "A240 TP 201LN	",
		"A240 TP 304	", "A240 TP 304L	", "A240 TP 316	",
		"A240 TP 316L	", "A240 TP 317	", "A240 TP 317L	" };

		double YS_S[5][9] =
		{
			{ 0, 260, 310, 205, 170, 205, 170, 205, 205 },
			{ 0, 199, 250, 170, 148, 178, 145, 179, 179 },
			{ 0, 172, 227, 155, 132, 161, 130, 161, 161 },
			{ 0, 157, 214, 143, 121, 148, 119, 148, 148 },
			{ 0, 50, 207, 134, 113, 137, 110, 138, 138 }
		};

		double Sd_S[5][9] =
		{
			{ 0, 155, 197, 155, 145, 155, 145, 155, 155 },
			{ 0, 136, 172, 155, 132, 155, 131, 155, 155 },
			{ 0, 125, 153, 140, 119, 145, 117, 145, 145 },
			{ 0, 121, 145, 128, 109, 133, 107, 133, 133 },
			{ 0, 50, 143, 121, 101, 123, 99, 123, 123 },
		};

		double UTS_S[9] = { 0, 515, 655, 515, 485, 515, 485, 515, 515 };

		double St_S[9] = { 0, 234, 279, 186, 155, 186, 155, 186, 186 };

		if (T <= 40)  b = 0;
		else if (T <= 90)  b = 1;
		else if (T <= 150) b = 2;
		else if (T <= 200) b = 3;
		else if (T <= 260) b = 4;

		if ((b == 4) && (a == 101))
			a = 102;

		a = a - 100;

		MOC = Material_Name_S[a];

		if (b == 0)
		{
			YS = YS_S[0][a];
			Sd = Sd_S[0][a];
		}
		else
		{
			YS = (YS_S[b - 1][a] - ((YS_S[b - 1][a] - YS_S[b][a])* (T - TS[b - 1]) / (TS[b] - TS[b - 1])));
			Sd = (Sd_S[b - 1][a] - ((Sd_S[b - 1][a] - Sd_S[b][a])* (T - TS[b - 1]) / (TS[b] - TS[b - 1])));
		}

		YS_Atm = YS_S[0][a];

		UTS = UTS_S[a], Sd_Atm = Sd_S[0][a], St = St_S[a];

		Y_mod_Atm = 194000;

		if (T <= 40)  Y_mod = 194000;
		else if (T <= 90)  Y_mod = (194000 - (4000 * (T - 40) / 50));
		else if (T <= 150) Y_mod = (190000 - (4000 * (T - 90) / 60));
		else if (T <= 200) Y_mod = (186000 - (4000 * (T - 150) / 50));
		else Y_mod = (182000 - (3000 * (T - 200) / 60));
	}
	else if (a > 120)
	{
		a = a - 120;

		string Material_Name_X[11] =
		{ "Material", "S31803		", "S32003		",
		"S32101		", "S32202		", "S32205		", "S32304		",
		"S32550		", "S32520		", "S32750		", "S32760		" };

		double YS_X[5][11] =
		{
			{ 0, 450, 450, 450, 448, 450, 400, 550, 550, 550, 550 },
			{ 0, 396, 386, 379, 387, 358, 343, 484, 448, 486, 455 },
			{ 0, 370, 352, 351, 339, 338, 319, 443, 421, 446, 428 },
			{ 0, 353, 331, 324, 321, 319, 307, 421, 400, 418, 414 },
			{ 0, 342, 317, 317, 314, 286, 299, 407, 379, 402, 400 },
		};

		double Sd_X[5][11] =
		{
			{ 0, 248, 262, 260, 262, 262, 240, 303, 308, 318, 298 },
			{ 0, 248, 231, 234, 258, 234, 229, 302, 270, 319, 314 },
			{ 0, 239, 218, 223, 226, 225, 213, 285, 265, 298, 259 },
			{ 0, 230, 215, 215, 214, 208, 205, 279, 256, 279, 256 },
			{ 0, 225, 212, 212, 209, 191, 200, 272, 251, 268, 256 },
		};

		double YMod_X[5][11] =
		{
			{ 0, 198000, 209000, 198000, 198000, 198000, 198000, 209000, 209000, 202000, 199000 },
			{ 0, 190000, 205000, 194000, 185000, 190000, 190000, 206000, 206000, 194000, 193000 },
			{ 0, 185000, 201000, 190000, 190000, 185000, 185000, 202000, 202000, 188000, 190000 },
			{ 0, 180000, 197000, 185000, 186000, 180000, 180000, 198000, 198000, 180000, 185000 },
			{ 0, 174000, 192000, 182000, 182000, 174000, 174000, 194000, 180000, 175000, 182000 },
		};

		double UTS_X[11] = { 0, 620, 655, 650, 655, 655, 600, 760, 770, 795, 750 };

		double St_X[11] = { 0, 266, 281, 278, 281, 281, 257, 325, 331, 343, 319 };

		if (T <= 40)  b = 0;
		else if (T <= 90)  b = 1;
		else if (T <= 150) b = 2;
		else if (T <= 200) b = 3;
		else if (T <= 260) b = 4;

		MOC = Material_Name_X[a];

		if (b == 0)
		{
			YS = YS_X[0][a];
			Sd = Sd_X[0][a];
			Y_mod = YMod_X[0][a];
		}
		else
		{
			YS = (YS_X[b - 1][a] - ((YS_X[b - 1][a] - YS_X[b][a])  * (T - TS[b - 1]) / (TS[b] - TS[b - 1])));
			Sd = (Sd_X[b - 1][a] - ((Sd_X[b - 1][a] - Sd_X[b][a])  * (T - TS[b - 1]) / (TS[b] - TS[b - 1])));
			Y_mod = (YMod_X[b - 1][a] - ((YMod_X[b - 1][a] - YMod_X[b][a])  * (T - TS[b - 1]) / (TS[b] - TS[b - 1])));
		}

		YS_Atm = YS_X[0][a];
		UTS = UTS_X[a], Sd_Atm = Sd_X[0][a], St = St_X[a];

		Y_mod_Atm = YMod_X[0][a];

		cout << endl << "Youngs Modulus :			" << Y_mod_Atm << "	" << Y_mod << endl << endl;
	}
}



double roundup(double x, int n)
{
	x = (ceil(x * pow(10, n)) / pow(10, n));
	return x;
}


double rounddown(double x, int n)
{
	x = (floor(x * pow(10, n)) / pow(10, n));
	return x;
}

double max(double x1, double x2, double x3, double x4, double x5, double x6, int n)
{
	double temp[] = { x1, x2, x3, x4, x5, x6 };
	double y = temp[0];
	int i = 1;
	while (i < n)
	{
		if (y < temp[i])
			y = temp[i];
		i++;
	}
	return y;
}


double min(double x1, double x2, double x3, double x4, double x5, double x6, int n)
{
	double temp[] = { x1, x2, x3, x4, x5, x6 };
	double y = temp[0];
	int i = 1;
	while (i < n)
	{
		if (y > temp[i])
			y = temp[i];
		i++;
	}

	return y;
}

void InitVariables()
{
	edit_option = 1; //default value
	int D_Type = Option_P = Shell_Appendx_No_user = Roof_Type_No_user = FR_Type_No = Shell_Des_Method_No = RoundUP_to = option_Stfr =
		wind_design_code = wind_exp_cat = Seismic_design_code = Zone_Number = site_class = ASCE_rule = SUG = option_Av = Shell_Material_No[15][3] =
		Option_walkway = curb_angle_No_user = Option_PWG = stfr_Mat_No[45] = stfr_Sec_No[45][2] = No_of_Stiffeners_Max_user = option_frangible_roof = Roof_Material_No = option_annularPlate = 0;

	D_User = H = H_td_user = H_tt_user = H_Norm_user = H_Seis_user = G = Gw = T = MDMT = P = Po_user =
		Pe = Fp = Fpe = CA_Bot = CA_Roof = JE_user = CA_FR = Wt_Roof_Str_user =
		kz_user = kzt_user = kd_user = basic_v_user = imp_factorW_user = gust_factor_user = V_user =
		S0_user = Ss_user = S1_user = Fa_user = Fv_user = Factor_Q = TL_user = K_user =
		shell_detail_user[15][5] = weight_stair_user = weight_adder_user =
		stfr_detail_user[45][2] =
		Spacing_Top_WG_User = PWG_width_min_user =
		R_Roof_user = live_load_user = snow_load_bal = snow_load_unbal = roof_slope_user = dome_radius_user = JE_roof_user = Roof_Thk_user = 0;

	D_Previous = D = Min_Nom_Thk = Min_Nom_Thk_1 = t_uniform = tu_min_W = tu_min_Pe = tu_min = H_Max_W = H_Max_Ps = H_Max = Fy_Shell = H_Top = Spacing_Min = N_Sqr =
		Spacing_Top_WG_Tr = kz = kzt = kd = basic_v = imp_factorW = gust_factor = wind_pressure = V = live_load = roof_slope = dome_radius =
		roof_thk_user = roof_thk = JE_roof = R_Roof = Roof_Material_YS = Roof_Material_SA = Roof_Material_Y_mod = Roof_Material_Y_mod_Atm = Wt_FR = Wt_Roof_Str_defaut =
		Wt_Roof_Str = Roof_thk_reqd = weight_Roof_Plate = weight_Roof_Plate_cor = theeta = Roof_Thk[10] = Rafter_spacing = Rafter_spacing_cent =
		dead_load = dead_load_cor = ext_load = ext_load_bal = ext_load_unbal = total_load_bal = total_load_unbal = H_td_default = H_td = H_tt_default = H_tt = H_Norm_default =
		H_Norm = H_Seis_default = H_Seis = JE = Po_default = Po = S0 = Ss = S1 = imp_factorS = Fa_default = Fa = Fv_default = Fv = TL = K = Sds = Sd1 = Av = Spacing_Top_WG = PWG_width_min =
		PWG_width = YS = YS_Atm = UTS = Sd = Sd_Atm = St = Group_No = Psi = W = Ps = H_Ts = H_Avg = H_High = H_Low = New_Spacing = Y_Mod = Y_Mod_Atm = Y_mod = Y_mod_Atm =
		Factor_M = Factor_M1 = ring_area = ring_CG = ring_MOI = stfr_area = stfr_MOI = stfr_Sec_Mod = web_width = web_thk = flng_width = flng_thk =
		Weight_FR = weight[20] = density_steel = cg_shell = Thk_AnnPlate[4] = 0;

	shell_detail[15][30] = Y_Mod_X[15][3] = user_EL_detail[45][11] = stfr_Prop_user[45][4] = stfr_detail[45][80] = PWG_details[20] = comp_ring_detail[10] = 0;
	CR_Material_YS[7] = CR_Material_Y_mod[7] = CR_Material_SA[7] = CR_Area_rqd_SRR = CR_Area_rqd_P = CR_Area_rqd_V = CR_MOI_rqd = CR_fc = 0;


	D_Type = Option_P = Shell_Appendx_No_user = Roof_Type_No_user = FR_Type_No = Shell_Des_Method_No = RoundUP_to = option_Stfr =
		wind_design_code = wind_exp_cat = Seismic_design_code = Zone_Number = site_class = ASCE_rule = SUG = option_Av = Shell_Material_No[15][3] =
		Option_walkway = curb_angle_No_user = Option_PWG = stfr_Mat_No[45] = stfr_Sec_No[45][2] = No_of_Stiffeners_Max_user = option_frangible_roof = Roof_Material_No = option_annularPlate = 0;


	Shell_Appendx_No = Roof_Type_No = No_of_ShellCourses = Apndx_C_MOC = Print_x = Option_walkwayG = No_of_Stiffeners = No_of_Stiffeners_R =
		No_of_Stiffeners_P = No_of_Stiffeners_Max = stfr_location[45][5] = AnnPlate_req[4] = apndx_F = CR_Type_No[3] = CR_Material_No[7] = 0;


	WeightAdder_roof_default = WeightAdder_roof_user = WeightAdder_roof = weight_platform_default = weight_platform_user = weight_platform = 0;

	roof_slope_user_numerator = roof_slope_user_denominator = type_compression_ring = CR_Size[3] = 0;

	t_bar[3] = w_bar[3] = l_bar[3] = t_shell[3] = w_shell[3] = PWG_Width_Web = PWG_Thick_Web = PWG_Height_Flange = PWG_Thick_Flange = kz_default = V_default = Gd = H_Max_Ps = H_Remaining = 0;

	compRing_detail[3] = PWG_shell_thk = PWG_shell_width = 0;

	PWG_Width_Web = PWG_Width_Web_User = PWG_Thick_Web = PWG_Height_Flange = PWG_Thick_Flange = 0;

}




void Calculate_Fa_FV()
{
	double Ss_low, Ss_high, Fa_low, Fa_high, S1_low, S1_high, Fv_low, Fv_high;
	int i, j, k, m;

	double Fa_Data[6][6] = { 0.0, 0.25, 0.5, 0.75, 1.0, 1.25,
		0.8, 0.8, 0.8, 0.8, 0.8, 0.8,
		1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
		1.2, 1.2, 1.2, 1.1, 1.0, 1.0,
		1.6, 1.6, 1.4, 1.2, 1.1, 1.0,
		2.5, 2.5, 1.7, 1.2, 0.9, 0.9 };

	double Fv_Data[6][6] = { 0.0, 0.1, 0.2, 0.3, 0.4, 0.5,
		0.8, 0.8, 0.8, 0.8, 0.8, 0.8,
		1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
		1.7, 1.7, 1.6, 1.5, 1.4, 1.3,
		2.4, 2.4, 2.0, 1.8, 1.6, 1.5,
		3.5, 3.5, 3.2, 2.8, 2.4, 2.4 };


	m = site_class;

	if (Ss >= Fa_Data[0][5])
	{
		Fa_default = Fa_Data[m][5];
	}
	else
	{
		for (i = 0; i <= 4; i++)
		{
			if ((Ss > Fa_Data[0][i]) && (Ss <= Fa_Data[0][(i + 1)]))
			{
				j = i;
			}
		}

		Ss_low = Fa_Data[0][j];
		Ss_high = Fa_Data[0][(j + 1)];
		Fa_low = Fa_Data[m][j];
		Fa_high = Fa_Data[m][(j + 1)];
		Fa_default = Fa_low - ((Fa_low - Fa_high) * (Ss - Ss_low) / (Ss_high - Ss_low));

	}
	// Calculation of Fv.
	if (S1 >= Fv_Data[0][5])
		Fv_default = Fv_Data[m][5];
	else
	{
		for (i = 0; i <= 4; i++)
		{
			if ((S1 > Fv_Data[0][i]) && (S1 <= Fv_Data[0][(i + 1)]))
			{
				//				cout << endl <<  " Value of Ss_low for the specified site class  " << Fa_Data [0][i] << endl;
				//				cout << endl <<  " Value of Ss_high for the specified site class  " << Fa_Data [0][(i+1)] << endl << endl;
				k = i;
			}
		}

		S1_low = Fv_Data[0][k];
		S1_high = Fv_Data[0][(k + 1)];
		Fv_low = Fv_Data[m][k];
		Fv_high = Fv_Data[m][(k + 1)];

		Fv_default = Fv_low - ((Fv_low - Fv_high) * (S1 - S1_low) / (S1_high - S1_low));
	}
} // end of function Calculate_Fa_FV()


void print(std::string File_name)
{
	int i = 0;
	ofstream outf;
	string fileName = File_name + "Result.txt";
	outf.open(fileName.c_str(), ios::out); //reviced line  if file name is sample, then the newly formed name is sample_out.txt


	if (!outf)
	{
		cerr << File_name << ".txt could not be opened for writing!" << endl;
	}
	Print_x = 1;

	// Note to AA. Design Data is the first item in the list of content with page number.

	outf << endl << "						Design Data					" << endl << endl;
	outf << endl << "Diamter of the Tank					=	" << D_User << "   M" << endl << endl;

	string Dia;
	if (D_Type == 1) Dia = "Nominal Dia";
	else Dia = "ID";

	outf << endl << "NOM. Dia (1) / ID (2) ? 				=	" << Dia << endl;
	outf << endl << " Height of the Tank					=	" << H << "   M" << endl << endl;
	outf << endl << "Design Product Level					=	" << H_td_user << "   M" << endl;
	outf << endl << "Test Water Level					=	" << H_tt_user << "   M" << endl;
	outf << endl << "Normal Liquid Level					=	" << H_Norm_user << "   M" << endl;
	outf << endl << "Liquid Level For Seismic Design				=	" << H_Seis_user << "   M" << endl;
	outf << endl << "Specific Gravity of Product				=	" << G << "   " << endl;
	outf << endl << "Specific Gravity of Test Water				=	" << fixed << setprecision(1) << Gw << "   " << endl;
	outf << endl << "Design Temperature					=	" << T << "   Deg. C" << endl;
	outf << endl << "Minimum Design Metal Temperature			=	" << MDMT << "   Deg. C" << endl;
	outf << endl << "Design Internal Pressure				=	" << P << "    KPa" << endl;
	outf << endl << "Pressure Combination Factor_Fp				=	" << Fp << endl;

	string option;
	if (Option_P == 1) option = "YES";
	else option = "No";



	outf << endl << "Add (P/9.8G) to liquid head?				:	" << option << endl;
	outf << endl << "Design External Pressure				=	" << fixed << setprecision(1) << Pe << "   KPa" << endl;
	outf << endl << "Ext. Pr. Combination Factor_Fpe				=	" << Fpe << endl;
	outf << endl << "Applicable Apndx for shell Design 			=	" << Shell_Appendx_user << endl;

	outf << endl << "Course Width of First shell course	  		=	" << shell_detail_user[0][1] << "   M" << endl;
	outf << endl << "Corrossion Allowance of First shell course		=	" << shell_detail_user[0][2] << "   mm" << endl;
	if (Shell_Appendx_No <= 2)
		outf << endl << "JE for shell Vertical Seam				=	" << JE_user << endl;
	outf << endl << "Method for Shell Thk Calculation			=	" << Shell_Des_Method << endl;
	outf << endl << "CA of Bottom Plate (mm)					=	" << fixed << setprecision(1) << CA_Bot << "   mm" << endl;
	outf << endl << "Type of Fixed roof	(User Defined)			=	" << Roof_Type_user << endl;
	outf << endl << "Corrosion Allowance of Fixed Roof 			=	" << fixed << setprecision(1) << CA_Roof << "   mm" << endl;

	outf << endl << "Weight of Spiral Stairway				=	" << weight_stair_user << endl;
	outf << endl << "% Addition of Weight for Misc Items			=	" << weight_adder_user << "   %" << endl;
	outf << endl << "Round-up Shell Thickness to				=	" << RoundUP_to << "   mm" << endl;

	string Stfr;
	if (option_Stfr == 1) Stfr = "Yes";
	else Stfr = "No";
	outf << endl << "Use Cor.Shell Thk for stiffener Design ?		:	" << Stfr << endl << endl << endl;

	string wind_code;
	if (wind_design_code == 1) wind_code = "ASCE 7-05 ";
	else if (wind_design_code == 2) wind_code = "ASCE 7-10 ";
	else wind_code = "NA; V define by User";

	outf << endl << "wind_design_code					=	" << wind_code << endl;

	if (wind_design_code == 3)
		outf << endl << "User Defined Design Wind Velocity			=	" << fixed << setprecision(1) << V << "   Km / Hr" << endl << endl << endl;
	else
	{
		outf << endl << "Three second Gust Design Wind Speed			=	" << fixed << setprecision(3) << basic_v_user << "   M / Sec" << endl;
		string exp_cat;
		if (wind_exp_cat == 1) exp_cat = "CAT. B";
		else if (wind_exp_cat == 2) exp_cat = "CAT. C";
		else exp_cat = "CAT. C";

		outf << endl << "wind_exp_cat						=	" << exp_cat << endl;

		outf << endl << "Wind Vel. Pr. Exposure coefficient (kz)			=	" << fixed << setprecision(3) << kz_user << endl;
		outf << endl << "Wind Topographic Factor (kzt)				=	" << kzt_user << endl;
		outf << endl << "Wind Directionality Factor (kd)				=	" << kd_user << endl;
		outf << endl << "Wind importance Factor 					=	" << imp_factorW_user << endl;
		outf << endl << "gust_factor (G)						=	" << gust_factor_user << endl;

		double wind_pressure = ((0.613  * kz * kzt * kd * gust_factor * imp_factorW * (pow(basic_v, 2))) / 1000) + 0.24;
		double V_default = 190 * pow((wind_pressure / 1.72), 0.5);

		outf << endl << "Design Wind Velocity Calculated				=	" << fixed << setprecision(2) << V_default << "   Km / Hr" << endl;
		outf << endl << "Design Wind Velocity By user				=	" << fixed << setprecision(2) << V_user << "   Km / Hr" << endl;
		outf << endl << "Design Wind Velocity Adopted				=	" << fixed << setprecision(2) << V << "   Km / Hr" << endl << endl << endl;

	}

	string Seismic_Code;
	if (Seismic_design_code == 1) Seismic_Code = "ASCE 7";
	else if (Seismic_design_code == 2) Seismic_Code = "UBC 97";
	else if (Seismic_design_code == 3) Seismic_Code = "Peak Ground Acceleration";

	outf << endl << "Seismic_design_code					=	" << Seismic_Code << endl;
	if (Seismic_design_code == 2)
	{

		string zone;
		if (Zone_Number <= 1) zone = "Zone-1";
		else if (Zone_Number == 2) zone = "Zone-2";
		else if (Zone_Number == 3) zone = "Zone-2A";
		else if (Zone_Number == 4) zone = "Zone-2B";
		else if (Zone_Number == 5) zone = "Zone-3";
		else if (Zone_Number == 6) zone = "Zone-4";


		outf << endl << "UBC Zone						=	" << zone << endl;
		outf << endl << "Peak Ground Acceleration 				=	" << fixed << setprecision(3) << S0 << endl;
	}

	else if (Seismic_design_code == 3)
		outf << endl << "Peak Ground Acceleration 				=	" << fixed << setprecision(3) << S0_user << endl;

	outf << endl << "Spectral Acceleration at short Period Ss 		=	" << fixed << setprecision(3) << Ss_user << endl;
	outf << endl << "Spectral Acceleration at One Second S1   		=	" << fixed << setprecision(3) << S1_user << endl;
	if (Seismic_design_code > 1)
		outf << endl << "Spectral Acceleration at Time Period zero: S0		=	" << fixed << setprecision(3) << S0 << endl;

	string ASCE_Rule = "NO";
	if (ASCE_rule == 1)  ASCE_Rule = "YES";

	outf << endl << "Is The Site Governed By ASCE Rule?			=	" << ASCE_Rule << endl;
	outf << endl << "Scaling Factor - Q - considered				=	" << fixed << setprecision(3) << Factor_Q << endl;

	string sug;
	if (SUG == 1) sug = "SUG-1";
	else if (SUG == 2) sug = "SUG-2";
	else sug = "SUG-3";

	outf << endl << "Seismic User Group - SUG				=	" << sug << endl;
	outf << endl << "Seismic Importance Factor				=	" << fixed << setprecision(2) << imp_factorS << endl;

	string Site_Class;
	if (site_class <= 1) Site_Class = "Site Class A";
	else if (site_class == 2) Site_Class = "Site Class B";
	else if (site_class == 3) Site_Class = "Site Class C";
	else if (site_class == 4) Site_Class = "Site Class D";
	else if (site_class == 5) Site_Class = "Site Class E";

	outf << endl << "Seismic Site Class					=	" << Site_Class << endl;
	outf << endl << "Acceleration Based Site Coefficient (Fa)		=	" << fixed << setprecision(3) << Fa_user << endl;
	outf << endl << "Velocity Based Site Coefficient (Fv)			=	" << fixed << setprecision(3) << Fv_user << endl;
	outf << endl << "Transition Period For Longer Period Ground Motion - TL  =	" << TL_user << endl;
	outf << endl << "Coefficient to adjust 5% Damping Value to 0.5%  - K	=	" << K_user << endl;
	outf << endl << "Design Spec. Response Accln at Short Period - SDS	=	" << fixed << setprecision(3) << Sds << endl;
	outf << endl << "Design Spec. Response Accln at One Second   - SD1	=	" << fixed << setprecision(3) << Sd1 << endl << endl << endl;

	if (Roof_Type_No > 6)
	{
		string walkWay = "NO";
		if (Option_walkway == 1)  walkWay = "YES";

		outf << endl << "Is Primary Wind Girder Used as a walkway ?		=	" << walkWay << endl;
		//		outf << endl << "Thickness of Top Shell course			=	" << shell_detail[(No_of_ShellCourses - 1)][18] << endl;

		if (shell_detail[(No_of_ShellCourses - 1)][18] < 5.01)

			i = 1;
		else i = 4;

		string angle_section_name[8] = { "No Curb Angle", "65 x 65 x 6", "65 x 65 x 8", "65 x 65 x 10", "75 x 75 x 6", "75 x 75 x 8", "75 x 75 x 10", "90 x 90 x 10" };
		double angle_section_width[8] = { 0, 65, 65, 65, 75, 75, 75, 90 };




		outf << endl << "Size of Curb Angle Required as a minimum		=	" << angle_section_name[i] << endl;
		if (curb_angle_No_user < i) curb_angle_No_user = i;

		outf << endl << "Size of Curb Angle Provided				=	" << angle_section_name[curb_angle_No_user] << endl;

		outf << endl << "Spacing of Top Wind Girder from top of Tank		=	" << Spacing_Top_WG_User << endl;

		if (Option_walkway == 1)
			outf << endl << "Minimum Required width of the Primary WG		=	" << fixed << setprecision(1) << (710 + angle_section_width[i]) << endl << endl << endl;
	}

	if (Roof_Type_No <= 6)
	{
		outf << endl << "Type of Fixed roof User					=	" << Roof_Type_user << endl;
		outf << endl << "CA of Roof Plate (mm)					=	" << CA_Roof << "   mm" << endl;
	}
	outf << endl << "Type of Floating roof					=	" << FR_Type << endl << endl << endl;

	// Note to AA. Provide a page break here

	//	Print_x = 1;

	// Note to AA. 'Summary of Results' is the second item in the list of content with page number.

	outf << endl << "						Summary of Results					" << endl << endl;




	if ((T > 91) && ((Shell_Appendx_No == 1) || (Shell_Appendx_No == 2) || (Shell_Appendx_No == 4) || (Shell_Appendx_No == 7)))
	{
		outf << endl << "Factor M for Design					=	" << fixed << setprecision(3) << Factor_M << endl;
		outf << endl << "Youngs Modulous (Atm)					=	" << fixed << setprecision(0) << Y_Mod_Atm << "  MPa" << endl;
		outf << endl << "Youngs Modulous (Des)					=	" << fixed << setprecision(0) << Y_Mod << "  MPa" << endl;
		outf << endl << "Ratio of Youngs Modulus 				=	" << fixed << setprecision(3) << Factor_M1 << endl;
	}
	else if ((T > 40) && ((Shell_Appendx_No == 3) || (Shell_Appendx_No == 4) || (Shell_Appendx_No == 6)))
	{
		outf << endl << "Youngs Modulous (Atm)					=	" << fixed << setprecision(0) << Y_Mod_Atm << "  MPa" << endl;
		outf << endl << "Youngs Modulous (Des)					=	" << fixed << setprecision(0) << Y_Mod << "  MPa" << endl;
		outf << endl << "Ratio of Youngs Modulus 				=	" << fixed << setprecision(3) << Factor_M1 << endl;
	}
	else if ((T > 40) && (Shell_Appendx_No == 5))
	{
		outf << endl << "Ratio of Youngs Modulus 				=	" << fixed << setprecision(3) << Factor_M1 << endl;
	}
	/*
	outf << endl << "MDMT							=	" << MDMT << "   Deg. C" << endl;
	outf << endl << "Design Internal Pressure				=	" << P << "    KPa" << endl;
	outf << endl << "Operating Pressure					=	" << Po << "   KPa" << endl;
	outf << endl << "Design External Pressure				=	" << Pe << "   KPa" << endl;
	outf << endl << "CA of Bottom Plate (mm)					=	" << CA_Bot << "   mm" << endl;



	outf << endl << "Roof					" << endl << endl;



	if (Roof_Type_No_user == 1 || Roof_Type_No_user == 2)
	{
	outf << endl << "Type of Fixed roof specified by User					=	" << Roof_Type_user << endl;
	outf << endl << "Required thickness of self supporting Roof	=		" << max(Roof_Thk[2], Roof_Thk[3], Roof_Thk[4], Roof_Thk[4], Roof_Thk[4], Roof_Thk[4], 3) << endl;

	}

	outf << endl << "Type of Fixed roof Adopted				=	" << Roof_Type << endl;
	outf << endl << "CA of Roof Plate (mm)					=	" << CA_Roof << "   mm" << endl;
	outf << endl << "Type of Floating roof					=	" << FR_Type << endl;
	*/
	if (Shell_Appendx_No_user != Shell_Appendx_No)
	{
		outf << endl << "Applicable Appendix for shell Design (User): 		=	" << Shell_Appendx_user << endl;

		outf << endl << "Applicable Appendix for shell Design (Adptd): 		=	" << Shell_Appendx << endl;
	}

	outf << endl << "Min Nom. Thk. for first shell course			=	" << Min_Nom_Thk_1 << endl;
	outf << endl << "Min Nom. Thk. for upper shell courses			=	" << Min_Nom_Thk << endl;
	outf << endl << "Shell Design Method: 					=	" << Shell_Des_Method << endl;
	outf << endl << "Number of Shell Courses					=	" << No_of_ShellCourses << endl;

	outf << endl << "Use Cor.Shell Thk for stiffener Design ?		:	" << Stfr << endl << endl << endl;
	//	outf << endl << "Top Shell Thickness					=	" << t_uniform << endl;

	if (No_of_Stiffeners_Max_user > 0)
	{
		outf << endl << "User Specified Max. Number of Stiffeners		=	" << No_of_Stiffeners_Max_user << endl;
		outf << endl << "A/B Top Shell Thickness					=	" << shell_detail[(No_of_ShellCourses - 1)][18] << endl;
		outf << endl << "Corroded Top Shell Thickness				=	" << shell_detail[(No_of_ShellCourses - 1)][19] << endl;

		if (shell_detail[(No_of_ShellCourses - 1)][18] > Min_Nom_Thk)

			outf << endl << "Shell Thickness 					=	" << shell_detail[(No_of_ShellCourses - 1)][19] << endl << endl;
	}

	if (Shell_Des_Method_No == 2)
	{
		outf << endl << "Required Thk. of first shell course (VDP) td		=	" << shell_detail[0][12] << endl;
		outf << endl << "Required Thk. of first shell course (VDP) tt		=	" << shell_detail[0][13] << endl << endl;

	}

	outf << endl << "Properties of Material selected for each shell course 					" << endl;
	outf << "----------------------------------------------------- 					" << endl;

	// Note to AA: This is a table with 8 columns (max) and number of rows = number of shell courses + 1. Top Row is for headings. Common note for all tables: If required to prevent any table crossing over to next page, provide a page break before the beginning of the heading (above).

	outf
		<< "\ncourse number	"

		<< "YS_Atm	\t"
		<< "UTS	\t"
		<< "Sd_Atm	\t"
		<< "St	\t"
		<< "YS_Des	\t"
		<< "Sd_Des	\t"
		<< "MOC				"
		<< endl << endl;

	for (i = 0; i <= (No_of_ShellCourses - 1); i++)

		outf << endl
		<< "	" << (i + 1)

		<< fixed << setprecision(3) << "	" << shell_detail[i][5]
		<< fixed << setprecision(3) << "		" << shell_detail[i][1]
		<< fixed << setprecision(3) << "		" << shell_detail[i][6]
		<< fixed << setprecision(3) << "		" << shell_detail[i][4]
		<< fixed << setprecision(3) << "		" << shell_detail[i][2]
		<< fixed << setprecision(3) << "		" << shell_detail[i][3]
		<< "		" << Shell_Material_Name[i][1]
		<< endl;

	// Note to AA: This is a table with 11 columns (max) and number of rows = number of shell courses + 1. Top Row is for headings. If these can not be accommodated in one table, Move the 9th, 10th and 11th columns (whwrwever applicable) to a new table with shell course number is repeated in first column in the second table

	outf << endl << "Required Thickness of Individual Shell courses					" << endl;
	outf << "---------------------------------------------- 					" << endl;
	if ((Shell_Des_Method_No == 1) && (Shell_Appendx_No == 5))

	{
		outf
			<< "\ncourse			"
			<< "Course	"
			<< "CA	"
			<< "Liquid Head 	"
			<< "Liquid Head 	"
			<< "Design Thk		"
			<< "Design Thk		"
			<< "Adopted		"
			//<< "Joint "
			//<< "User Thk.		"
			<< "Youngs Mod.		"
			<< "Youngs Mod.	"
			<< "Factor_M1	\n"
			<< endl;

		outf
			<< "\n\n number			"
			<< "height	"
			<< "CA	"
			<< "For td		"
			<< "For tt	"
			<< "td		"
			<< "tt		"
			<< "Thickness	"
			//<< "Efficiency		"
			//<< "User Thk.		"
			<< "E_Atm		"
			<< "E_Des	"
			<< "	\n"
			<< endl << endl;

		for (i = 0; i <= (No_of_ShellCourses - 1); i++)

			outf
			<< "	"
			<< (i + 1)
			<< fixed << setprecision(3) << "	" << shell_detail[i][0]
			<< fixed << setprecision(1) << "	" << shell_detail[i][9]
			<< fixed << setprecision(3) << "	" << shell_detail[i][7]
			<< fixed << setprecision(3) << "		" << shell_detail[i][8]
			<< fixed << setprecision(3) << "		" << shell_detail[i][10]
			<< fixed << setprecision(3) << "		" << shell_detail[i][11]
			<< fixed << setprecision(3) << "		" << shell_detail[i][18]
			<< fixed << setprecision(2) << "		" << JE
			// << fixed << setprecision(2) << "		" << shell_detail_user[i][3]
			<< fixed << setprecision(0) << "		" << Y_Mod_X[i][1]
			<< fixed << setprecision(0) << "		" << Y_Mod_X[i][2]
			<< fixed << setprecision(3) << "		" << (Y_Mod_X[i][2] / Y_Mod_X[i][1])
			<< endl << endl;
	}


	else if ((Shell_Des_Method_No == 1) && (Shell_Appendx_No != 5))
	{

		outf
			<< "\n\ncourse		"
			<< "Course	"
			<< "CA	"
			<< "Liquid Head 	"
			<< "Liquid Head 	"
			<< "Design Thk	"
			<< "Design Thk	"
			<< "Adopted		";
		//<< "Joint		"
		//<< "User defined	";
		//		<< endl;

		outf
			<< "\nnumber		"
			<< "height	"
			<< "CA	"
			<< "For td		"
			<< "For tt		"
			<< "td		"
			<< "tt		"
			<< "Thickness	"
			//<< "Efficiency	"
			//<< "Thickness	"
			<< endl << endl;

		/*
		outf
		<< "\n\ncourse number	"
		<< "height	"
		<< "CA	"
		<< "H for td	"
		<< "H For tt	"
		<< "td		"
		<< "tt		"
		<< "Adopted Thk	"
		<< "JE		"
		<< "User Thk.		"
		<< endl;
		*/
		for (i = 0; i <= (No_of_ShellCourses - 1); i++)

			outf
			<< "	"
			<< (i + 1)
			<< fixed << setprecision(3) << "	" << shell_detail[i][0]
			<< fixed << setprecision(1) << "	" << shell_detail[i][9]
			<< fixed << setprecision(3) << "	" << shell_detail[i][7]
			<< fixed << setprecision(3) << "		" << shell_detail[i][8]
			<< fixed << setprecision(3) << "		" << shell_detail[i][10]
			<< fixed << setprecision(3) << "		" << shell_detail[i][11]
			<< fixed << setprecision(3) << "		" << shell_detail[i][18]
			//<< fixed << setprecision(2) << "		" << JE
			//<< fixed << setprecision(2) << "		" << shell_detail_user[i][3]
			<< endl << endl;
	}

	else if ((Shell_Des_Method_No == 2) && (Shell_Appendx_No == 5))
	{
		outf
			<< "\n\ncourse			"
			<< "Course	"
			<< "CA	"
			<< "Liquid Head 	"
			<< "Liquid Head 	"
			<< "Design Thk		"
			<< "Design Thk		"
			<< "Adopted		"
			<< "Joint "
			//<< "User Thk.		"
			<< "Youngs Mod.		"
			<< "Youngs Mod.	"
			<< "Factor_M1	\n"
			<< endl;

		outf
			<< "\n\n number			"
			<< "height	"
			<< "CA	"
			<< "For td		"
			<< "For tt	"
			<< "td		"
			<< "tt		"
			<< "Thickness	"
			<< "Efficiency		"
			//<< "User Thk.		"
			<< "E_Atm		"
			<< "E_Des	"
			<< "	\n"
			<< endl << endl << endl;

		for (i = 0; i <= (No_of_ShellCourses - 1); i++)

			outf
			<< "	"
			<< (i + 1) << fixed << setprecision(3) << "	" << shell_detail[i][0]
			<< fixed << setprecision(1) << "	" << shell_detail[i][9]
			<< fixed << setprecision(3) << "	" << shell_detail[i][7]
			<< fixed << setprecision(3) << "		" << shell_detail[i][8]
			<< fixed << setprecision(3) << "		" << shell_detail[i][12]
			<< fixed << setprecision(3) << "		" << shell_detail[i][13]
			<< fixed << setprecision(3) << "		" << shell_detail[i][18]
			//			<< fixed << setprecision(2) << "		" << JE
			<< fixed << setprecision(2) << "		" << shell_detail_user[i][3]
			<< fixed << setprecision(0) << "	" << Y_Mod_X[i][1]
			<< fixed << setprecision(0) << "		" << Y_Mod_X[i][2]
			<< fixed << setprecision(3) << "		" << (Y_Mod_X[i][2] / Y_Mod_X[i][1])
			<< endl << endl;
	}

	else if ((Shell_Des_Method_No == 2) && (Shell_Appendx_No != 5))
	{
		outf
			<< "\n\ncourse			"
			<< "Course	"
			<< "CA	"
			<< "Liquid Head 	"
			<< "Liquid Head 	"
			<< "Design Thk		"
			<< "Design Thk		"
			<< "Adopted		"
			<< "Joint "
			<< "User defined	"

			<< endl;

		outf
			<< "\n\n number		"
			<< "height	"
			<< "CA	"
			<< "For td		"
			<< "For tt	"
			<< "td		"
			<< "tt		"
			<< "Thickness	"
			<< "Efficiency		"
			<< "Thickness	"
			<< endl;

		for (i = 0; i <= (No_of_ShellCourses - 1); i++)

			outf
			<< "	" << (i + 1)
			<< fixed << setprecision(3) << "	" << shell_detail[i][0]
			<< fixed << setprecision(1) << "	" << shell_detail[i][9]
			<< fixed << setprecision(3) << "	" << shell_detail[i][7]
			<< fixed << setprecision(3) << "		" << shell_detail[i][8]
			<< fixed << setprecision(3) << "		" << shell_detail[i][12]
			<< fixed << setprecision(3) << "		" << shell_detail[i][13]
			<< fixed << setprecision(3) << "		" << shell_detail[i][18]
			//		<< fixed << setprecision(2) << "		" << JE
			<< fixed << setprecision(2) << "		" << shell_detail_user[i][3]
			<< endl << endl;
	}
	double	temp1 = pow((D / t_uniform), 0.75) * (H_Ts / D) * pow((Fy_Shell / Y_Mod), 0.5);
	double 	temp2 = Y_Mod / (15203 * Psi * pow((D / t_uniform), 2.5) * (H_Ts / D));
	double 	temp3 = 47.07 * pow((Psi * H_Ts * Ps), 0.4) * pow(D, 0.6) / pow(Y_Mod, 0.4);
	int k;

	/*
	outf << endl << "wind_design_code					=	" << wind_design_code << endl;
	outf << endl << "wind_exp_cat						=	" << wind_exp_cat << endl;
	outf << endl << "basic_v							=	" << basic_v << endl;
	outf << endl << "kz							=	" << kz << endl;
	outf << endl << "kzt							=	" << kzt << endl;
	outf << endl << "kd							=	" << kd << endl;
	outf << endl << "imp_factorW						=	" << imp_factorW << endl;
	outf << endl << "gust_factor						=	" << gust_factor << endl;

	*/
	outf << endl << "Design of Shell Stiffeners					" << endl;
	outf << "--------------------------					" << endl << endl << endl;


	outf << endl << "\nDesign Wind Velocity					=	" << V << "	KmPH" << endl;
	outf << endl << "Transposed Height of shell				=	" << H_Ts << "	M" << endl;
	outf << endl << "Maximum Un-Stiffend Height for Wind			=	" << fixed << setprecision(4) << H_Max_W << "	M" << endl;
	outf << endl << "Top Shell Thickness (Original)				=	" << t_uniform << endl;
	if (Pe > 0.2500001)
	{
		outf << endl << "Design External Pressure				=	" << fixed << setprecision(4) << Pe << "	KPa" << endl;
		outf << endl << "Design External Pressure from Wind			=	" << fixed << setprecision(4) << W << "	KPa" << endl;
		outf << endl << "Total External Pressure Ps (Wind + Pe)			=	" << fixed << setprecision(4) << Ps << "	KPa" << endl;
		outf << endl << "Maximum Un-Stiffend Height as per Apndx V 		=	" << fixed << setprecision(4) << H_Max_Ps << "	M" << endl;
		outf << endl << "(D/t_u)^0.75)*(H_Ts/D)*(Fy / Y_Mod)^0.5) 		=	" << fixed << setprecision(4) << temp1 << endl;
		outf << endl << "Should be more than 0.00675" << endl;
		outf << endl << "Max.Ext. Pressure for un-stiffened shell; Ps 		=	" << fixed << setprecision(3) << temp2 << "	KPa" << endl;
		outf << endl << "Minimum shell thickness for un-stiffened shell 		=	" << fixed << setprecision(3) << temp3 << "	mm" << endl;
		outf << endl << "Top Shell Thickness (Min Reqd for Pe)			=	" << tu_min_Pe << endl;
		outf << endl << "Sq. of Number of waves of shell while buckling		=	" << N_Sqr << endl;
	}
	outf << endl << "Top Shell Thickness (Min Reqd for Wind)			=	" << tu_min_W << endl;
	outf << endl << "Maximum Un-Stiffend Height adopted			=	" << H_Max << "	m" << endl;
	outf << endl << "Number of Stiffeners Required (original)		=	" << No_of_Stiffeners << endl;
	outf << endl << "Number of Stiffeners Required (Revised)			=	" << No_of_Stiffeners_R << endl;
	outf << endl << "Squire of No of buckling wave adoptedd)			=	" << N_Sqr << endl;
	outf << endl << "Youngs Modulus used for design)				=	" << Y_Mod << endl;
	outf << endl << "Spcing of top Wg from top)				=	" << Spacing_Top_WG << endl << endl;





	outf << endl << "Details of Top & Bottom Elevations of Shell Courses (Actual & Transposed Shell)					" << endl;
	outf << "------------------------------------------------------------------------------- 					" << endl;
	outf << "\n\n\tcourse	"
		<< "height		"
		<< "Thk. for	"
		<< "Bot. El		"
		<< "Top. El		"
		<< "Transposed-	"
		<< "Bot. El of	"
		<< "Top. El of "
		<< "Clearance Required\n";


	outf << "\tnumber"
		<< "			"
		<< "design		"
		<< "of Shell	"
		<< "of Shell	"
		<< "height		"
		<< "Tr Shell	"
		<< "Tr Shell	"
		<< "from Joints	"
		<< "\n\n";
	//		int n;
	if (option_Stfr == 1)
		k = 19;
	else	k = 18;

	for (i = 0; i <= (No_of_ShellCourses - 1); i++)
	{
		outf << "	" << (i + 1)
			<< fixed << setprecision(3) << "	" << shell_detail[i][0]
			<< fixed << setprecision(1) << "		" << shell_detail[i][k]
			<< fixed << setprecision(3) << "		" << shell_detail[i][24]
			<< fixed << setprecision(3) << "		" << shell_detail[i][25]
			<< fixed << setprecision(3) << "		" << shell_detail[i][21]
			<< fixed << setprecision(3) << "		" << shell_detail[i][22]
			<< fixed << setprecision(3) << "		" << shell_detail[i][23]
			<< fixed << setprecision(4) << "		" << shell_detail[i][26]
			<< endl << endl;

	}

	// Start copy of PWG Results

	if (Roof_Type_No > 6)
	{
		string walkWay = "NO";
		if (Option_walkway == 1)  walkWay = "YES";


		outf << endl << "Design of Primary Wind Girder					" << endl;
		outf << "-----------------------------					" << endl << endl << endl;
		outf << endl << "Is Primary Wind Girder Used as a walkway ?		=	" << walkWay << endl;
		//		outf << endl << "Thickness of Top Shell course			=	" << shell_detail[(No_of_ShellCourses - 1)][18] << endl;

		if (shell_detail[(No_of_ShellCourses - 1)][18] < 5.01)

			i = 1;
		else i = 4;

		string angle_section_name[8] = { "No Curb Angle", "65 x 65 x 6", "65 x 65 x 8", "65 x 65 x 10", "75 x 75 x 6", "75 x 75 x 8", "75 x 75 x 10", "90 x 90 x 10" };
		double angle_section_width[8] = { 0, 65, 65, 65, 75, 75, 75, 90 };




		outf << endl << "Size of Curb Angle Required as a minimum		=	" << angle_section_name[i] << endl;
		if (curb_angle_No_user < i) curb_angle_No_user = i;

		outf << endl << "Size of Curb Angle Provided				=	" << angle_section_name[curb_angle_No_user] << endl;

		outf << endl << "Spacing of Top Wind Girder from top of Tank		=	" << Spacing_Top_WG_User << endl;

		if (Option_walkway == 1)
			outf << endl << "Minimum Required width of the Primary WG		=	" << fixed << setprecision(0) << (710 + angle_section_width[i]) << endl;

		outf << endl << "Required Section Modulus of Primary WG			=	" << fixed << setprecision(0) << PWG_details[0] << "   Cub. CM" << endl;
		if (D > 61)
			outf << endl << "Required Moment of Inertia of Primary WG		=	" << fixed << setprecision(0) << PWG_details[16] << "   CM^4" << endl << endl;
		outf << endl << "Design thickness of shell at PWG 			=	" << fixed << setprecision(1) << (PWG_shell_thk * 10) << "   mm" << endl;
		outf << endl << "Participating width of shell at PWG 			=	" << fixed << setprecision(1) << (PWG_shell_width * 10) << "   mm" << endl;
		outf << endl << "User defined Width of Web		 		=	" << fixed << setprecision(1) << (PWG_Width_Web_User) << "   mm" << endl;
		outf << endl << "User defined Thk of Web		 			=	" << fixed << setprecision(1) << (PWG_Thick_Web) << "   mm" << endl;
		outf << endl << "User defined Width of Flange		 		=	" << fixed << setprecision(1) << (PWG_Height_Flange) << "   mm" << endl;
		outf << endl << "User defined Thk of Flange		 		=	" << fixed << setprecision(1) << (PWG_Thick_Flange) << "   mm" << endl << endl << endl;

		outf << endl << "Size of Primary Wind Girder					" << endl;
		outf << "---------------------------					" << endl << endl << endl;

		outf << "\n\n\n		"

			<< "Width Of \t"
			<< "Thickness \t"
			<< "Width of \t"
			<< "Thickness of \t"
			<< "Section Mod \t\t"
			<< "MOI Availale\t"
			<< endl;


		outf << "		"

			<< "Web (mm)\t"
			<< "of Web (mm)	"
			<< "Flange (mm)\t"
			<< "Flange	(mm) \t"
			<< "Availale (Cub. CM)	"
			<< "(CM^4)\t"
			<< endl;

		outf << endl
			<< "default	"

			<< fixed << setprecision(0) << "	" << PWG_details[1]
			<< fixed << setprecision(0) << "		" << PWG_details[2]
			<< fixed << setprecision(0) << "		" << PWG_details[3]
			<< fixed << setprecision(0) << "		" << PWG_details[4]
			<< fixed << setprecision(0) << "		" << PWG_details[5]
			<< fixed << setprecision(2) << "			" << PWG_details[17]
			<< endl;

		outf << endl
			<< "User"

			<< fixed << setprecision(0) << "		" << PWG_details[6]
			<< fixed << setprecision(0) << "		" << PWG_details[7]
			<< fixed << setprecision(0) << "		" << PWG_details[8]
			<< fixed << setprecision(0) << "		" << PWG_details[9]
			<< fixed << setprecision(0) << "		" << PWG_details[10]
			<< fixed << setprecision(2) << "			" << PWG_details[18]
			<< endl;


		outf << endl
			<< "Adoptedt"

			<< fixed << setprecision(0) << "	" << PWG_details[11]
			<< fixed << setprecision(0) << "		" << PWG_details[12]
			<< fixed << setprecision(0) << "		" << PWG_details[13]
			<< fixed << setprecision(0) << "		" << PWG_details[14]
			<< fixed << setprecision(0) << "		" << PWG_details[15]
			<< fixed << setprecision(2) << "			" << PWG_details[19]
			<< endl << endl << endl;


	} // end of PWG details



	outf << endl << "Location of Shell Stiffeners Based on Maximum permissible spacing from top				" << endl;
	outf << "--------------------------------------------------------------------------					" << endl;
	if (No_of_Stiffeners > 0)
	{
		outf << "\n\n\tSl.No	"
			<< "shell course	"
			<< "Elv. on		"
			<< "Spacing to	"
			<< "Spacing to	"
			<< "Elv. on		"
			<< "Spacing to	"
			<< "\n";



		outf << "\tstifnr	"
			<< "number		"
			<< "actual shell	"
			<< "Top Joint	"
			<< "Bottom Joint	"
			<< "Trans shell	"
			<< "stfr above	"
			<< "\n\n";

		for (i = 0; i <= (No_of_Stiffeners - 1); i++)
		{
			outf << "	" << (i + 1)
				<< "	" << stfr_location[i][0]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][2]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][5]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][6]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][0]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][1]
				<< endl << endl;


		}

		outf << endl << "Location of Shell Stiffeners Based on average spacing from top				" << endl;
		outf << "-------------------------------------------------------------- 					" << endl;
		outf << "\n\n\tSl.No	"
			<< "shell course	"
			<< "Elv. on		"
			<< "Spacing to	"
			<< "Spacing to	"
			<< "Elv. on		"
			<< "Spacing to	"
			<< "\n";



		outf << "\tstifnr	"
			<< "number		"
			<< "actual shell	"
			<< "Top Joint	"
			<< "Bottom Joint	"
			<< "Trans shell	"
			<< "stfr above	"
			<< "\n\n";

		for (i = 0; i <= (No_of_Stiffeners - 1); i++)
		{
			outf << "	" << (i + 1)
				<< "	" << stfr_location[i][1]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][9]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][12]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][13]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][7]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][8]
				<< endl << endl;
		}

		outf << endl << " Final Location of Shell Stiffeners adopted				" << endl;
		outf << " ------------------------------------------					" << endl;
		outf << "\n\n\tSl.No	"
			<< "shell course	"
			<< "Elv. on		"
			<< "Spacing to	"
			<< "Spacing to	"
			<< "Elv. on		"
			<< "Spacing to	"
			<< "\n";



		outf << "\tstifnr	"
			<< "number		"
			<< "actual shell	"
			<< "Top Joint	"
			<< "Bottom Joint	"
			<< "Trans shell	"
			<< "stfr above	"
			<< "\n\n";

		for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
		{
			outf << "	" << (i + 1)
				<< "	" << stfr_location[i][2]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][16]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][19]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][20]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][14]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][15]
				<< endl << endl;
		}

		/*
		for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
		{

		//			outf << endl << "spacing on trans_shell to upper stiffener for stfr No " << (i + 1) << "					=	" << user_EL_detail[i][3] << endl;
		outf << endl << "Maximum possible elevation of stiff. No. " << (i + 1) << "					=	" << user_EL_detail[i][4] << endl;
		}



		outf
		<< "\n\n\tSl.No	"
		<< "Elv. on		"
		<< "Highest possible"
		<< "Lowest Possible"
		<< "spacing to seam"
		<< "spacing to seam"
		<< "Adopted			"
		<< "Elevation on	"
		<< "Ht of un-stfnd  "
		<< "User Thk.		"
		<< endl;

		outf << "\tstfnr	"
		<< "actual shell	"
		<< "Elevation	"
		<< "Elevation	"
		<< "below		"
		<< "above		"
		<< "Elevation	"
		<< "Transp.shell"
		<< "on Tr. Shell"
		<< "\n\n";



		for (i = 0; i <= (No_of_ShellCourses - 1); i++)

		outf
		<< "	" << (i + 1)
		<< fixed << setprecision(3) << "	" << stfr_detail[i][16]
		<< fixed << setprecision(1) << "	" << shell_detail[i][9]
		<< fixed << setprecision(3) << "	" << shell_detail[i][7]
		<< fixed << setprecision(3) << "		" << shell_detail[i][8]
		<< fixed << setprecision(3) << "		" << shell_detail[i][12]
		<< fixed << setprecision(3) << "		" << shell_detail[i][13]
		<< fixed << setprecision(3) << "		" << shell_detail[i][18]
		//			<< fixed << setprecision(2) << "		" << JE
		<< fixed << setprecision(2) << "		" << shell_detail_user[i][3]
		<< endl << endl;

		*/
		outf << endl << "Required Properties of Stiffener Rings				" << endl;
		outf << "-------------------------------------- 					" << endl;

		outf << "\n\n\tSl.No	"
			<< "Section Mod.	"
			<< "H abov stfr on	"
			<< "Ys of Stfnr	"
			<< "Ls		"
			<< "Area		"
			<< "MOI 	  \n";

		//				<< "Ys of Stfnr	\n";



		outf << "\tstifnr	"
			<< "Required	"
			<< "act. shell	"
			<< "Used		"
			<< "		"
			<< "Required	"
			<< "Required	"
			//				<< "Bottom Joint	"
			<< "\n\n";

		for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
		{
			outf << "	" << (i + 1)
				<< fixed << setprecision(3) << "	" << stfr_detail[i][23]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][17]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][26]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][24]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][30]
				<< fixed << setprecision(2) << "		" << stfr_detail[i][29]
				<< endl << endl;
		}


		outf << endl << "Thickness, Participating width and available Area of the Shell at the location of Stiffeners 				" << endl;
		outf << "-------------------------------------------------------------------------------------------- 					" << endl;
		outf << "\n\n\tstfr No	"
			<< "shell thk	"
			<< "shell Ht	"
			<< "Shell Area	"
			//			<< "Stfr Area	"
			//			<< "Total Area	"
			//			<< "Size of Ring"
			<< "\n\n\n";

		for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
		{
			outf << "	" << (i + 1)
				<< fixed << setprecision(3) << "	" << stfr_detail[i][31]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][32]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][33]
				//				<< fixed << setprecision(3) << "		" << stfr_detail[i][39]
				//				<< fixed << setprecision(3) << "		" << stfr_detail[i][45]

				<< endl << endl;
		}





		outf << "\n\n Details of stiffener ring proposed" << endl;
		outf << "---------------------------------- 					" << endl;

		outf << "\n\n\tSl.No	"
			<< "Section Mod.	"
			<< "Tota Area	"
			<< "MOI 			"
			<< "Required Area	"
			<< "Available Area	"
			<< "Size 	\n";

		outf << "\tstfnr	"
			<< "Available	"
			<< "Available	"
			<< "Available		"
			<< " of section	"
			<< " of section	"
			<< " of Ring		"
			<< "\n\n";

		for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
		{
			outf << "	" << (i + 1)

				<< fixed << setprecision(3) << "	" << stfr_detail[i][47]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][45]
				<< fixed << setprecision(1) << "		" << stfr_detail[i][46] << "\t"
				<< fixed << setprecision(3) << "		" << stfr_detail[i][30] / 2
				<< "		" << stfr_detail[i][39]
				<< fixed << setprecision(3) << "		" << Stfnr_Section[i][0]
				<< endl << endl;
		}


		outf << "\n\n Details of stiffener ring Specified by user" << endl;
		outf << "------------------------------------------ 					" << endl;

		outf << "\n\n\tSl.No	"
			<< "Section Mod.	"
			<< "Tota Area	"
			<< "MOI 			"
			<< "Required Area	"
			<< "Available Area	"
			<< "Size 	\n";

		outf << "\tstfnr	"
			<< "Available	"
			<< "Available	"
			<< "Available		"
			<< " of section	"
			<< " of section	"
			<< " of Ring		"
			<< "\n\n";

		for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
		{
			outf << "	" << (i + 1)

				<< fixed << setprecision(3) << "	" << stfr_detail[i][62]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][60]
				<< fixed << setprecision(1) << "		" << stfr_detail[i][61] << "\t"
				<< fixed << setprecision(3) << "		" << stfr_detail[i][30] / 2
				<< "		" << stfr_detail[i][54]
				<< fixed << setprecision(3) << "		" << Stfnr_Section[i][1]
				<< endl << endl;
		}




		outf << "\n\n Details of stiffener ring Adopted" << endl;
		outf << "--------------------------------- 					" << endl;

		outf << "\n\n\tSl.No	"
			<< "Section Mod.	"
			<< "Tota Area	"
			<< "MOI 			"
			<< "Required Area	"
			<< "Available Area	"
			<< "Size 	\n";

		outf << "\tstfnr	"
			<< "Available	"
			<< "Available	"
			<< "Available		"
			<< " of section	"
			<< " of section	"
			<< " of Ring		"
			<< "\n\n";

		for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
		{
			outf << "	" << (i + 1)

				<< fixed << setprecision(3) << "	" << stfr_detail[i][77]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][75]
				<< fixed << setprecision(1) << "		" << stfr_detail[i][76] << "\t"
				<< fixed << setprecision(3) << "		" << stfr_detail[i][30] / 2
				<< "		" << stfr_detail[i][69]
				<< fixed << setprecision(3) << "		" << Stfnr_Section[i][2]
				<< endl << endl;
		}



	}
	outf << endl << "Roof Design					" << endl;
	outf << "-----------					" << endl;

	outf << endl << "Roof Type Adopted					=	" << fixed << setprecision(2) << Roof_Type << endl;
	if (Roof_Type_No < 7)
	{
		outf << "-----------					" << endl;
		outf << endl << "Type of Fixed Roof Specified by User			=	" << fixed << setprecision(2) << Roof_Type_user << endl;
		if ((Roof_Type_No_user == 1) || (Roof_Type_No_user == 2))
			outf << endl << "Required thickness of self supporting Roof		=	" << max(Roof_Thk[2], Roof_Thk[3], Roof_Thk[4], Roof_Thk[4], Roof_Thk[4], Roof_Thk[4], 3) << "   mm" << endl;

		outf << endl << "CA of Roof Plate (mm)					=	" << CA_Roof << "   mm" << endl;
		outf << endl << "Youngs Modulus of Roof					=	" << fixed << setprecision(2) << Roof_Material_Y_mod << "   MPa" << endl;
		outf << endl << "Yield Strength of Roof					=	" << fixed << setprecision(2) << Roof_Material_YS << "   MPa" << endl;
		outf << endl << "Allowable stess of Roof					=	" << fixed << setprecision(2) << Roof_Material_SA << "   MPa" << endl;
		outf << endl << "Design Internal Pressure				=	" << fixed << setprecision(2) << P << "   KPa" << endl;
		outf << endl << "Dead Load						=	" << fixed << setprecision(3) << dead_load << "   KPa" << endl;
		outf << endl << "Design External Pressure				=	" << fixed << setprecision(2) << Pe << "   KPa" << endl;
		outf << endl << "(0.4 * Pe) + live_load					=	" << fixed << setprecision(2) << ((0.4 * Pe) + live_load) << "   KPa" << endl;
		outf << endl << "(0.4 * live_load) + Pe					=	" << fixed << setprecision(2) << ((0.4 * live_load) + Pe) << "   KPa" << endl;
		outf << endl << "External load balanced (T)				=	" << fixed << setprecision(2) << ext_load_bal << "   KPa" << endl;
		outf << endl << "External load un balanced (U)				=	" << fixed << setprecision(2) << ext_load_unbal << "   KPa" << endl;
		outf << endl << "Govering External load					=	" << fixed << setprecision(2) << ext_load << "   KPa" << endl;
		if ((Roof_Type_No == 1) || (Roof_Type_No == 3) || (Roof_Type_No == 3))
			outf << endl << "Slope of Roof						=	" << fixed << setprecision(4) << roof_slope << endl;

		else if ((Roof_Type_No == 2) || (Roof_Type_No == 4) || (Roof_Type_No == 6))

			outf << endl << "Radius of Dome							=	" << fixed << setprecision(3) << dome_radius << "   M" << endl;
		outf << endl << "Joint Efiiciency of Roof				=	" << fixed << setprecision(2) << JE_roof << endl;



		if ((Roof_Type_No_user == 1) || (Roof_Type_No_user == 2))
		{

			outf << endl << "Roof thk for load T					=	" << fixed << setprecision(2) << Roof_Thk[2] << "   mm" << endl;
			outf << endl << "Roof thk for load u					=	" << fixed << setprecision(2) << Roof_Thk[3] << "   mm" << endl;
			outf << endl << "Roof thk as per Apx V					=	" << fixed << setprecision(2) << Roof_Thk[4] << "   mm" << endl;
		}

		outf << endl << "Roof thk for Internal Pressure				=	" << fixed << setprecision(2) << Roof_Thk[1] << "   mm" << endl;

		outf << endl << "Minimum Required Roof thk				=	" << fixed << setprecision(2) << Roof_Thk[5] << "   mm" << endl;
		outf << endl << "Roof thk defined by user				=	" << fixed << setprecision(2) << Roof_Thk[7] << "   mm" << endl;
		outf << endl << "Roof thk Adopted					=	" << fixed << setprecision(2) << Roof_Thk[8] << "   mm" << endl;
		if ((Roof_Type_No == 3) || (Roof_Type_No == 5))
			outf << endl << "Maximum Rafter Spacing					=	" << fixed << setprecision(0) << Rafter_spacing << "   mm" << endl;

		else if ((Roof_Type_No == 4) || (Roof_Type_No == 6))
		{
			outf << endl << "Maximum Rafter Spacing at periphery			=	" << fixed << setprecision(0) << Rafter_spacing << "   mm" << endl;
			outf << endl << "Maximum Rafter Spacing at center			=	" << fixed << setprecision(0) << Rafter_spacing_cent << "   mm" << endl;

		}

	}

	outf << endl << "Type of Floating roof					=	" << FR_Type << endl;


	//		outf << endl << "Weight Calculation					" << endl;
	//		outf <<			"------------------					" << endl;


	outf << endl << "NOM. Dia (1) / ID (2) / 				=	" << Dia << endl;
	outf << endl << " Height of the Tank					=	" << H << "   M" << endl << endl;
	outf << endl << "Design Product Level					=	" << H_td_user << "   M" << endl;
	outf << endl << "Test Water Level					=	" << H_tt_user << "   M" << endl;


	// Note to AA. Provide a page break here

	// Note to AA. 'Shell Design' is the 3rd item in the list of contents

	outf << endl << "						Shell Design					" << endl << endl;
	outf << "						-----------					" << endl;
	outf << endl << "Nominal Diamter of the Tank				=	" << D << "   M" << endl;
	outf << endl << "Height of the Tank					=	" << H << "   M" << endl;
	outf << endl << "Design Product Level					=	" << H_td_user << "   M" << endl;
	outf << endl << "Test Water Level					=	" << H_tt_user << "   M" << endl;

	if (Shell_Des_Method_No == 1)

	{
		if (Shell_Appendx_No_user < 7)
		{
			outf << endl << "Applicable Appendix for shell Design  			=	" << Shell_Appendx_user << endl;
			outf << endl << "Joint Efficiency for shell Design  			=	" << JE << endl << endl << endl;
		}

		if (Shell_Appendx_No_user < 3)
		{
			outf << endl << "Specific Gravity of Product				=	" << G << "   " << endl;
			if (G < 1.0) Gd = 1.0;
			else
				Gd = G;
			outf << endl << "Design Specific Gravity (App.A)				=	" << Gd << "   " << endl;
			outf << endl << "Allowable stress for design (App.A)			=	" << fixed << 145 << "   MPa" << endl << endl;

			for (i = 0; i <= (No_of_ShellCourses - 1); i++)
			{
				outf << endl << "Shell Course No :" << (i + 1) << "   " << endl;
				outf << "------------------					" << endl;
				outf << endl << "Design Product Level (H)				=	" << fixed << setprecision(2) << shell_detail[i][7] << "   M" << endl;
				outf << endl << "Course Height						=	" << fixed << setprecision(3) << shell_detail[i][0] << "   M" << endl;
				outf << endl << "Corrosion Allowance					=	" << fixed << setprecision(1) << shell_detail[i][9] << "   mm" << endl;
				if (T < 91)
				{
					outf << endl << "Required Thickness t = ( (4.9xDx(H-0.3)G / (ExJE) ) + CA  :" << endl;
					outf << endl << "Required Thickness					=	" << fixed << setprecision(2) << shell_detail[i][18] << "   mm" << endl;

				}
				else
				{
					outf << endl << "Temperature correction factor -m-		=	" << fixed << setprecision(2) << shell_detail[i][17] << "   mm" << endl;
					outf << endl << "Required Thickness t = ( (4.9xDx(H-0.3)G / (ExJE x m) ) + CA  :" << endl;
					outf << endl << "Required Thickness					=	" << fixed << setprecision(2) << shell_detail[i][18] << "   mm" << endl;

				}


			}// end of for sattement


		} // end of calculation for ahell appendix N. 1 or 2.


		else if (Shell_Appendx_No_user == 7)

		{
			outf << endl << "Specific Gravity of Product				=	" << G << "   " << endl;
			outf << endl << "Design Product Level					=	" << H_td_user << "   M" << endl;
			outf << endl << "Allowable stress for design 			=	" << fixed << 145 << "   MPa" << endl << endl;

			for (i = 0; i <= (No_of_ShellCourses - 1); i++)
			{
				outf << endl << "Shell Course No :" << (i + 1) << "   " << endl;
				outf << "------------------					" << endl;
				outf << endl << "Course Height						=	" << fixed << setprecision(3) << shell_detail[i][0] << "   M" << endl;
				outf << endl << "Corrosion Allowance					=	" << fixed << setprecision(1) << shell_detail[i][9] << "   mm" << endl;
				outf << endl << "Required Thickness for design td = ( (4.9xDx(H-0.3)G / (ExJE) ) + CA  :" << endl;
				outf << endl << "Required Thickness	for design td				=	" << fixed << setprecision(2) << shell_detail[i][10] << "   mm" << endl;
				outf << endl << "Required Thickness for Hydrotestgn tt = ( (4.9xDx(H-0.3)Gw / (ExJE) ) + CA  :" << endl;
				outf << endl << "Required Thickness	for design td				=	" << fixed << setprecision(2) << shell_detail[i][10] << "   mm" << endl;



			}// end of for sattement

		}// end of if statement for Shell_Des_Method_No == 3


	}// end of if statement for Shell_Des_Method_No == 1













	outf.close();
} // End of function print()






// Start of functions for design







void weight_cal()
{




	int i;
	double temp1, temp2, temp3, temp4, ID, sigma_WH_shell, sigma_WH_stfr, OD_PWG, ID_PWG;
	temp1 = temp2 = temp3 = temp4 = OD_PWG = ID_PWG = 0;
	density_steel = 7.85;

	double Dia_L, Dia_H, CR_wt_L, CR_wt_H, CR_wt, DR_wt_L, DR_wt_H, DR_wt, SDFR_wt_L, SDFR_wt_H, SDFR_wt, DDFR_wt_L, DDFR_wt_H, DDFR_wt, GEOR_wt_L, GEOR_wt_H;


	weight_multiplier = (1 + weight_adder_user / 100);

	if (D_Type == 0) ID = (D - shell_detail[0][18]); // ID of teh tank
	else
		ID = D;

	//	if (thk_bottom == 0)

	//		if (Shell_Appendx_No == )

	thk_bottom = (6 + CA_Bot);
	if (thk_annular == 0) thk_annular = thk_bottom;
	if (width_annular == 0) width_annular = 0.6;


	temp1 = ID - width_annular + 0.1; // OD of bottom plate; 50 mm overlap
	temp2 = temp1 - 0.05; // ID of annular plate
	temp3 = ID + (2 * shell_detail[0][18]) + 0.13;  // OD of annular plate; 65 mm external projection of annular plate.

	if (option_annular == 0)

		weight_bottom = (PI * (pow(temp3, 2)) * thk_bottom * density_steel * acln_gravity * 1.03 / 4 / 1000); // in KN

	else
		weight_bottom = (PI * (((pow(temp1, 2))* thk_bottom) + ((pow(temp3, 2)) - (pow(temp1, 2)) * thk_annular)) * density_steel * acln_gravity * 1.03 / 1000); // in KN


	for (i = 0; i <= No_of_ShellCourses; i++)
	{
		if (i == 0) { weight_shell_AB = weight_shell_cor = 0, sigma_WH_shell = 0; }

		weight_shell_AB = weight_shell_AB + (PI * D * shell_detail[i][0] * shell_detail[i][18] * weight_multiplier *  density_steel * 9.80665 / 1000);
		weight_shell_cor = weight_shell_cor + (PI * D * shell_detail[i][0] * shell_detail[i][19] * weight_multiplier * density_steel * 9.80665 / 1000);
		sigma_WH_shell = sigma_WH_shell + (PI * D * shell_detail[i][0] * shell_detail[i][18] * density_steel * 9.80665 / 1000) * (shell_detail[i][24] + (shell_detail[i][18] / 2)); // sum of (W x H) for shell

	}

	for (i = 0; i <= No_of_Stiffeners_R; i++)
	{
		if (i == 0){ weight_stfr = 0; sigma_WH_stfr = 0; }

		weight_stfr = weight_stfr + (PI * D * stfr_detail[i][69] * density_steel * 9.80665 / 10000); // need to be corrected using mean dia of ring inplace nominal dia of tank
		sigma_WH_stfr = sigma_WH_stfr + ((PI * D * stfr_detail[i][39] * density_steel * 9.80665 / 10000) * stfr_detail[i][21]); // sum of (W x H) for stiffener
	}

	if ((Roof_Type_No == 6) || (Roof_Type_No == 7))
	{
		OD_PWG = (2 * PWG_details[11] / 1000) + D;

		weight_PWG = ((pow(OD_PWG, 2) - pow(D, 2)) * PWG_details[12] * PI * density_steel * 9.80665 / 1000) + (OD_PWG *PI * PWG_details[13] * PWG_details[13] * density_steel * 9.80665 / 1000000);
	}

	else
		weight_PWG = 0;




	cg_shell = (sigma_WH_shell + sigma_WH_stfr + (weight_PWG *(H - Spacing_Top_WG))) / (weight_shell_AB + weight_stfr + weight_PWG);

	double Dia[23] = { 0, 4.5, 6.0, 8.0, 10.0, 12.0, 15.0, 17.0, 20.0, 23.0, 25.0, 28.0, 31.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 70.0, 80.0, 90.0, 100.0 };
	double Cone_Roof_Str_wt[23] = { 0, 300, 360, 630, 1030, 2710, 4140, 6500, 8780, 15020, 18100, 21200, 29300, 38700, 59710, 81000, 115000, 154000, 186000, 281000, 399000, 542000, 714000 };
	double Dome_Roof_Str_wt[23] = { 0, 157, 343, 748, 1369, 2244, 4109, 5768, 8960, 13086, 16403, 22300, 29383, 40826, 58626, 80671, 107330, 138961, 175914, 267133, 383606, 527847, 702282, };
	double SD_FR_weight[23] = { 0, 10174, 11676, 14283, 17582, 23000, 30000, 35000, 42000, 51000, 58000, 68000, 79000, 95000, 116000, 142000, 176000, 213000, 243000, 315000, 420000, 716272, 881363 };
	double DD_FR_weight[23] = { 0, 10174, 11676, 14283, 17582, 23000, 29206, 35238, 45699, 57857, 66905, 81890, 98572, 123454, 158796, 198852, 243619, 293100, 347292, 469814, 611186, 771407, 950478, };
	double GEOD_Roof_weight[23]			{ 0, 530, 839, 1448, 2224, 3672, 5419, 7256, 9505, 13285, 15311, 17697, 21628, 25896, 32887, 38198, 44275, 48340, 47945, 67119, 89120, 109548, 135651	}; // Needs correction after data is available


	for (i = 0; i <= 22; i++)
	{
		if (Dia[i] < D)
		{

			Dia_L = Dia[i];
			Dia_H = Dia[(i + 1)];
			CR_wt_L = Cone_Roof_Str_wt[i];
			CR_wt_H = Cone_Roof_Str_wt[(i + 1)];
			DR_wt_L = Dome_Roof_Str_wt[i];
			DR_wt_H = Dome_Roof_Str_wt[(i + 1)];
			GEOR_wt_L = GEOD_Roof_weight[i];
			GEOR_wt_H = GEOD_Roof_weight[(i + 1)];
			SDFR_wt_L = SD_FR_weight[i];
			SDFR_wt_H = SD_FR_weight[(i + 1)];
			DDFR_wt_L = DD_FR_weight[i];
			DDFR_wt_H = DD_FR_weight[(i + 1)];

		}
	}
	CR_wt = CR_wt_L + (CR_wt_H - CR_wt_L)*(D - Dia_L) / (Dia_H - Dia_L);
	DR_wt = DR_wt_L + (DR_wt_H - DR_wt_L)*(D - Dia_L) / (Dia_H - Dia_L);
	SDFR_wt = SDFR_wt_L + (SDFR_wt_H - SDFR_wt_L)*(D - Dia_L) / (Dia_H - Dia_L);
	DDFR_wt = DDFR_wt_L + (DDFR_wt_H - DDFR_wt_L)*(D - Dia_L) / (Dia_H - Dia_L);

	if ((Roof_Type_No == 3) || (Roof_Type_No == 5))
		Wt_Roof_Str_defaut = CR_wt;

	else
		if ((Roof_Type_No == 4) || (Roof_Type_No == 6))
			Wt_Roof_Str_defaut = DR_wt;
		else
			Wt_Roof_Str_defaut = DR_wt;

	if (FR_Type_No == 1)

		Weight_FR = SDFR_wt;
	else
		if (FR_Type_No == 2)
			Weight_FR = DDFR_wt;
		else
			Weight_FR = 0;





} // end of function weight_cal()



void stability_check()
{
	double  Mpi, Mwr, MDL, MF, MDLR, WL, Wp, Wi, Wc, Ks, Tc, Ai, Ac, Rwi, Rwc, Xi, Xc, Xis, Xcs, wind_pressure_shell, wind_pressure_roof;
	double temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8;


	weight_W1 = weight_W2 = weight_Roof_Plate_cor + Wt_Roof_Str_cor + Wt_Roof_Nozzles + weight_shell_cor + weight_stfr;
	weight_W3 = weight_Roof_Plate + Wt_Roof_Str + Wt_Roof_Nozzles + weight_shell_AB + weight_stfr;

	wind_pressure_shell = 0.86 * pow((V / 190), 2);
	wind_pressure_roof = 1.44 * pow((V / 190), 2);

	wind_moment_Mws = wind_pressure_shell * D * pow(H, 2) / 2;
	Mwr = (PI / 4) * pow(D, 2) * wind_pressure_roof * (D / 2); // wind moment from vertical wind load on roof
	wind_moment_Mw = wind_moment_Mws + Mwr;

	Mpi = (PI / 4) * pow(D, 2) * P * (D / 2);





	if (G < 0.7) temp1 = G;
	else temp1 = 0.7;

	if (Thk_AnnPlate[3] < shell_detail[0][19]) temp2 = Thk_AnnPlate[3];
	else
		temp2 = shell_detail[0][19];


	WL = 70 * temp2 * (pow((YS_AnnPlate*temp1 * H_Norm), 2));
	if (WL > (70.4 * H* D)) WL = (70.4 * H_Norm * D); // N/M

	MF = WL * PI * D * D / 2000; // KN-M


	if (Roof_Type_No <= 4)  // for supperted or self supporting roofs
	{
		MDL = (Wt_Roof_Str * fraction_roof_weight) + weight_shell_AB + weight_stfr + weight_Comp_ring_AB; //weight_str = 0 for type 1 & 2
		MDLR = (weight_Roof_Plate + Wt_Roof_Nozzles) * fraction_roof_weight;
	}

	else
		if ((Roof_Type_No == 5) || (Roof_Type_No == 6)) // for stiffened Roof
		{
			MDL = weight_shell_AB + weight_stfr + weight_Comp_ring_AB; // weight_PWG = 0 for type 5 & 6
			MDLR = (Wt_Roof_Str + weight_Roof_Plate + Wt_Roof_Nozzles);
		}

		else
			if ((Roof_Type_No == 7))
			{

				MDL = weight_shell_AB + weight_stfr + weight_PWG;
				MDLR = Wt_Roof_Str + Wt_Roof_Nozzles;

			}


			else
				if (Roof_Type_No == 8)

				{
					MDL = weight_shell_AB + weight_stfr + weight_PWG;
					MDLR = 0;
				}

	if ((0.6 * wind_moment_Mw + Mpi - (MDL / 1.5) - MDLR) < 0)

		check_anchorage1 = 1; // Clause 5.11.2.1 (1)

	if ((wind_moment_Mw + (Fp * Mpi) - (MDL / 1.5) - MDLR) < 0)

		check_anchorage2 = 1; // Clause 5.11.2.1 (3)


	if ((wind_moment_Mws + (Fp *Mpi) - ((MDL + MF) / 2) - MDLR) < 0)

		check_anchorage3 = 1;  // Clause 5.11.2.1 (2)  Note: This equation need further qualification for annular plate width.



	temp3 = (8000 / (PI* (pow(D, 3)))) * ((MDL / 1.5) + MDLR - (0.6 * wind_moment_Mw)); // Clause F.4.2 (1)

	temp4 = (8000 / (Fp * PI* (pow(D, 3)))) * (((MDL + MF) / 2) + MDLR - wind_moment_Mw); // Clause F.4.2 (2)

	temp5 = (8000 / (Fp * PI * (pow(D, 3)))) * ((MDL / 1.5) + MDLR - wind_moment_Mws); // Clause F.4.2 (3)

	temp6 = min(temp3, temp4, temp5, temp5, temp5, temp5, 3);

	if (P > temp6)
		check_anchorage4 = 1;

	// Check For Seismic overturning:

	Ks = 0.578 / (pow(tanh((3.68*H_Seis / D)), 0.5));

	Tc = Ks * pow(D, 0.5);

	Wp = PI*pow(D, 2)*H_Seis*G*acln_gravity / 4; // KN

	if ((D / H) >= 1.333)
	{
		Wi = Wp * (tanh((0.866*D / H)) / (0.866*D / H));
		Xi = 0.375*H;
		Xis = 0.375*(1.0 + (1.333*(((0.866*D / H) / tanh((0.866*D / H))) - 1)))*H_Seis;

	}
	else       Wi = Wp * (1 - (0.218*D / H));
	{
		Wc = Wp*(0.23*D / H_Seis)*(tanh((3.67*H_Seis / D)));
		Xi = (0.5 - (0.094*D / H_Seis));

		Xis = (0.5 - (0.060*D / H_Seis))*H_Seis;
	}

	if ((check_anchorage1 == 1) || (check_anchorage2 == 1) || (check_anchorage3 == 1) || (check_anchorage5 == 1))
		Rwi = 4.0;
	else Rwi = 3.5;

	Rwc = 2;

	if (S1 <= 0.6)
	{
		Ai = (Sds*imp_factorS / Rwi);
		if (Ai < 0.007)
			Ai = 0.007;
	}
	else
		Ai = 0.5*S1*imp_factorS / Rwi;

	if (Tc <= TL)

		Ac = K*Sd1*imp_factorS / (Rwc*Tc);
	else
		Ac = K*Sd1*TL*imp_factorS / (Rwc*Tc*Tc);

	Xc = (1 - (((cosh((3.67*H_Seis / D))) - 1) / ((3.67*H_Seis / D) * sinh((3.67*H_Seis / D))))) * H_Seis;
	Xcs = (1 - (((cosh((3.67*H_Seis / D))) - 1.937) / ((3.67*H_Seis / D) * sinh((3.67*H_Seis / D))))) * H_Seis;




} // end of function stability_check







void shell_Design()

{


	// Start of function Shell_Design()

	// Start: Calculattions:(for td & tt of first shell course);(Calculation for Nom.Dia); (check for applicability of appendix J & A);

	double Gd, temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9, temp10;
	int i, a, b, c, d;;

	if (Shell_Appendx_No == 1 || Shell_Appendx_No == 2)
		Gd = (G > Gw) ? G : Gw;
	else Gd = G;

	// Beginning of correction dated 10th Sept 2018

	if (D < 3.2)
		Min_Nom_Thk_1 = Min_Nom_Thk = 5.0;

	else if (D < 15)
	{
		if ((Shell_Appendx_No == 1) || (Shell_Appendx_No == 7))
			Min_Nom_Thk_1 = 6;
		Min_Nom_Thk = 5.0;
	}

	else if (D < 36)
		Min_Nom_Thk_1 = Min_Nom_Thk = 6.0;
	else if (D <= 60)
		Min_Nom_Thk_1 = Min_Nom_Thk = 8.0;
	else if (D > 60)
		Min_Nom_Thk_1 = Min_Nom_Thk = 10.0;

	if (Shell_Appendx_No == 2)
	{
		if (D<3.2)
			Min_Nom_Thk_1 = Min_Nom_Thk = 4.8;
		else
			Min_Nom_Thk_1 = Min_Nom_Thk = 6.0;

	}

	if ((Shell_Appendx_No == 4) && (Shell_Material_No[0][1] > 100) && (D > 3.2) && (D<15)) // If Appendix SC & bottom shell course is CS, for 3.2 < D < 15.
		Min_Nom_Thk_1 = 6;


	//	if (((Shell_Appendx_No == 1) || (Shell_Appendx_No == 2) || (Shell_Appendx_No == 7) || (Shell_Appendx_No == 4)) && (Apndx_C_MOC == 1) && (D < 15) && (D > 3.2)) // commented out

	//	Min_Nom_Thk_1 = 6.0; // Commented out

	// End of correction dated 10th Sep 2018





	// assigning values of Design Liquid Head

	shell_detail[0][7] = (H_td + ((P*Option_P) / (9.800f*G)));
	shell_detail[0][8] = (H_tt + ((P*Option_P) / (9.800f*Gw)));

	//

	for (i = 1; i <= (No_of_ShellCourses - 1); i++)
	{

		if ((shell_detail[(i - 1)][7] - shell_detail[(i - 1)][0]) < 0)
			shell_detail[(i)][7] = 0;
		else
			shell_detail[(i)][7] = shell_detail[(i - 1)][7] - shell_detail[(i - 1)][0];


		if ((shell_detail[(i - 1)][8] - shell_detail[(i - 1)][0]) < 0)
			shell_detail[(i)][8] = 0;
		else
			shell_detail[(i)][8] = shell_detail[(i - 1)][8] - shell_detail[(i - 1)][0];

	}




	// Itertative process to calculate shell thickness of the first course & Nominal Dia (if D_User is ID)


	// For Appndx A & J



	if (Shell_Appendx_No <= 2)

	{

		temp1 = (shell_detail[0][3] > (145 * Factor_M)) ? (145 * Factor_M) : shell_detail[0][3]; // Revised on 10th Sept 2018 (multiplication with Factor_M added)

		temp3 = (((4.9*D*(shell_detail[0][7] - 0.3))*Gd / (temp1*JE)) + shell_detail[0][9]);

		temp4 = (((4.9*D*(shell_detail[0][7] - 0.3))*Gd / (temp1*0.85)) + shell_detail[0][9]);

		temp5 = roundup(temp3, RoundUP_to);
		temp6 = roundup(temp4, RoundUP_to);

		if ((Shell_Appendx_No == 2) && (D > 6.0f))
		{
			Shell_Appendx_No = 1;
			Shell_Appendx = Shell_appendx[1];

		}

		if (temp5 < 13.0)
		{
			shell_detail[0][10] = temp3;
			shell_detail[0][11] = temp3 - shell_detail[0][9];
		}

		if ((temp5 > 13.0) && (temp6 <= 13.0))
		{
			shell_detail[0][10] = temp4;
			shell_detail[0][11] = temp4 - shell_detail[0][9];

			JE = 0.85;

		}

		else if (temp6 > 13.0f)
		{

			Shell_Appendx_No = 7;
			Shell_Appendx = Shell_appendx[7];

			JE = 1.0;

		}



	}	// end of if statement for appendix 1 & 2



	else if (Shell_Appendx_No >= 3)

	{


		// For Apndx S, SC, X or None; one foot or variable design method:

		Gd = G;

		shell_detail[0][10] = (((4.9f*D*(shell_detail[0][7] - 0.3f))*Gd / (shell_detail[0][3] * JE)) + shell_detail[0][9]);
		shell_detail[0][11] = ((4.9f*D*(shell_detail[0][8] - 0.3f))*Gw / (shell_detail[0][4] * JE));

		temp1 = (((1.06f - (0.0696f*D / shell_detail[0][7])*(pow((shell_detail[0][7] * G / shell_detail[0][3]), 0.5)))*(4.9f*D*shell_detail[0][7] * G / shell_detail[0][3])) + shell_detail[0][9]);

		shell_detail[0][12] = (temp1 < shell_detail[0][10]) ? temp1 : shell_detail[0][10];

		temp2 = ((1.06f - (0.0696f*D / shell_detail[0][8])*(pow((shell_detail[0][8] * Gw / shell_detail[0][4]), 0.5)))*(4.9f*D*shell_detail[0][8] * Gw / shell_detail[0][4]));

		shell_detail[0][13] = (temp2 < shell_detail[0][11]) ? temp2 : shell_detail[0][11];

		cout << endl << "Dia of Tank =			" << fixed << setprecision(2) << D << endl << endl;
		cout << endl << "Liquid Head =			" << fixed << setprecision(2) << shell_detail[0][7] << endl << endl;
		cout << endl << "G			 =			" << fixed << setprecision(2) << Gd << endl << endl;
		cout << endl << "Allowable stress Sd =	" << fixed << setprecision(2) << shell_detail[0][3] << endl << endl;
		cout << endl << "Gw			 =			" << fixed << setprecision(2) << Gw << endl << endl;
		cout << endl << "Allowable stress St =	" << fixed << setprecision(2) << shell_detail[0][4] << endl << endl;
		cout << endl << "JE			 =			" << fixed << setprecision(2) << JE << endl << endl;
		cout << endl << "CA			=			" << fixed << setprecision(2) << shell_detail[0][9] << endl << endl;
		cout << endl << "Shell Thk td	 =			" << fixed << setprecision(2) << shell_detail[0][10] << endl << endl;
		cout << endl << "Shell Thk tt	 =			" << fixed << setprecision(2) << shell_detail[0][11] << endl << endl;

	} // end of if statement for appendix 3 & above

	temp3 = (Shell_Des_Method_No == 1) ? shell_detail[0][10] : shell_detail[0][12];
	temp4 = (Shell_Des_Method_No == 1) ? shell_detail[0][11] : shell_detail[0][13];



	// design of shell for the upper courses:



	if (Shell_Appendx_No <= 2)
	{

		for (i = 1; i <= (No_of_ShellCourses - 1); i++)
		{

			temp1 = (shell_detail[i][3] > 145) ? 145 : shell_detail[i][3];
			temp4 = (shell_detail[i][4] > 145) ? 145 : shell_detail[i][4];

			if ((shell_detail[i][7] - 0.3) <= 0) // to prevent a negetive thickness
				shell_detail[i][10] = shell_detail[i][12] = 0;
			else
				shell_detail[i][10] = ((4.9f*D*(shell_detail[i][7] - 0.3f))*Gd / (temp1*JE)) + shell_detail[i][9];


			if ((shell_detail[i][8] - 0.3) <= 0)
				shell_detail[i][11] = shell_detail[i][13] = 0;
			else
				shell_detail[i][11] = ((4.9*D*(shell_detail[i][8] - 0.3f))*Gw / (temp4*JE));


		}

	}



	else

		if (Shell_Appendx_No >= 3)
		{

			i = 1;
			while (i <= (No_of_ShellCourses - 1))
			{

				if ((shell_detail[i][7] - 0.3) <= 0) // to prevent a negetive thickness
					shell_detail[i][10] = shell_detail[i][12] = 0;
				else
					shell_detail[i][10] = ((4.9f*D*(shell_detail[i][7] - 0.3f))*Gd / (shell_detail[i][3] * JE)) + shell_detail[i][9];
				if (Shell_Des_Method_No == 2)
					shell_Design_VDP_td(i);

				if ((shell_detail[i][8] - 0.3) <= 0)
					shell_detail[i][11] = shell_detail[i][13] = 0;
				else
					shell_detail[i][11] = ((4.9f*D*(shell_detail[i][8] - 0.3f))*Gw / (shell_detail[i][4] * JE));
				if (Shell_Des_Method_No == 2)
					shell_Design_VDP_tt(i);


				i++;
			}

		}

	// The For statement below is added only to test the UI; to be deleted later

	for (i = 0; i <= (No_of_ShellCourses - 1); i++)
	{

		shell_detail[i][14] = shell_detail[i][10] * 0.8;
		shell_detail[i][15] = shell_detail[i][10] * 0.82;

	}





	i = (No_of_ShellCourses - 1);
	while (i >= 0)

	{

		temp1 = (Shell_Des_Method_No == 1) ? shell_detail[i][10] : shell_detail[i][12];
		temp2 = (Shell_Des_Method_No == 1) ? shell_detail[i][11] : shell_detail[i][13];
		temp7 = (option_Stfr == 1) ? (tu_min + shell_detail[(No_of_ShellCourses - 1)][9]) : tu_min; // minimum required thickness of top shell course from external pressure calculation

		if (i == No_of_ShellCourses - 1)
			shell_detail[i][16] = (max(temp1, temp2, shell_detail[i][14], shell_detail[i][15], temp7, Min_Nom_Thk, 6));

		else if (i != 0)
			shell_detail[i][16] = (max(temp1, temp2, shell_detail[i][14], shell_detail[i][15], shell_detail[i + 1][16], Min_Nom_Thk, 6));
		else
			shell_detail[i][16] = (max(temp1, temp2, shell_detail[i][14], shell_detail[i][15], shell_detail[i + 1][16], Min_Nom_Thk_1, 6));


		if (shell_detail_user[i][3] == 0)
		{
			shell_detail[i][18] = (roundup(shell_detail[i][16], RoundUP_to));
			shell_detail[i][19] = shell_detail[i][18] - shell_detail[i][9];
		}
		else
		{

			shell_detail[i][18] = (shell_detail_user[i][3] >= shell_detail[i][16]) ? shell_detail_user[i][3] : (roundup(shell_detail[i][16], RoundUP_to));
			shell_detail[i][19] = shell_detail[i][18] - shell_detail[i][9];
		}

		// the if logic below is added on 25/08/2018 to take change the adopted thickness of shell same equal to upper shell course thickness if it is higher.

		if (i < (No_of_ShellCourses - 1))

		{
			if (shell_detail[(i + 1)][18] > shell_detail[i][18])
				shell_detail[i][18] = shell_detail[(i + 1)][18];
			shell_detail[i][19] = shell_detail[i][18] - shell_detail[i][9];
		}

		i--;
	}


	if (D_Type == 2)
	{
		D_Previous = D;
		D = D_User + (shell_detail[0][18] / 1000);

	}

	if (option_Stfr == 1)
		t_uniform = shell_detail[(No_of_ShellCourses - 1)][19];

	else
		t_uniform = shell_detail[(No_of_ShellCourses - 1)][18];
	tu_min_W = tu_min_Pe = t_uniform;


	// calculation of stress in the bottom shell course.

	if (Shell_Des_Method_No == 1)
	{

		temp8 = shell_detail[0][3] * (shell_detail[0][10] - shell_detail[0][9]) / shell_detail[0][19];
		temp9 = shell_detail[0][4] * shell_detail[0][11] / shell_detail[0][18];

	}

	else
	{

		temp8 = shell_detail[0][3] * (shell_detail[0][12] - shell_detail[0][9]) / shell_detail[0][19];
		temp9 = shell_detail[0][4] * shell_detail[0][13] / shell_detail[0][18];

	}

	temp10 = (temp8 > temp9) ? temp8 : temp9;

	if (((shell_detail[0][27] > 36) && (temp8 > 160)) || ((shell_detail[0][27] > 36) && (temp9 > 171)))             // if group No is IV, IVA, V or VI

		AnnPlate_req[0] = 1;

	if (((Shell_Appendx_No <= 2) || (Shell_Appendx_No == 7)) && (D > 30.0) && (T >= 94))

		AnnPlate_req[1] = 1;
	if ((AnnPlate_req[0] == 1) || (AnnPlate_req[1] = 1)) (AnnPlate_req[2] = 1);


	// Table 5.1 a of API 650

	if (shell_detail[0][19] <= 19)	a = 0;
	else if (shell_detail[0][19] <= 25)	a = 1;
	else if (shell_detail[0][19] <= 32)	a = 2;
	else if (shell_detail[0][19] <= 40)	a = 3;
	else a = 4;

	if (temp8 <= 190) c = 0;
	else if (temp8 <= 210) c = 1;
	else if (temp8 <= 220) c = 2;
	else if (temp8 <= 250) c = 3;
	else c = 4;

	if (shell_detail[0][18] <= 19) b = 0;
	else if (shell_detail[0][18] <= 25) b = 1;
	else if (shell_detail[0][18] <= 32) b = 2;
	else if (shell_detail[0][18] <= 40) b = 3;
	else b = 4;

	if (temp9 <= 190) d = 0;
	else if (temp9 <= 210) d = 1;
	else if (temp9 <= 220) d = 2;
	else if (temp9 <= 250) d = 3;
	else d = 4;

	float thk_AnnPlate[5][5] =

	{
		{ 6, 6, 7, 9, 12 },   // first bracket represent Row number and the second column number
		{ 6, 7, 10, 11, 15 },
		{ 6, 9, 12, 14, 19 },
		{ 8, 11, 14, 17, 23 },
		{ 9, 13, 16, 19, 25 },
	};


	Thk_AnnPlate[0] = thk_AnnPlate[a][c] + CA_Bot;
	Thk_AnnPlate[1] = thk_AnnPlate[b][d];
	if (Thk_AnnPlate[0] > Thk_AnnPlate[1]) Thk_AnnPlate[2] = Thk_AnnPlate[0];
	else Thk_AnnPlate[2] = Thk_AnnPlate[1];



} //end of function Shell_Design()



// End of functions for design






// Start of functions for design



double Actual_To_Transposed(double x)

{
	double y;
	int i, j = 0;

	// finding shell course number on which stiffener is fixed

	for (i = 0; i <= (No_of_ShellCourses - 1); i++)
	{

		if ((x > shell_detail[i][24]) && (x <= shell_detail[i][25]))
			j = i;

	}

	y = shell_detail[j][22] + ((x - shell_detail[j][24]) *   shell_detail[j][21] / shell_detail[j][0]);

	return y;
}


double Transposed_To_Actual(double y)

{
	double x;
	int i, j;
	j = 0;

	// finding shell course number on which stiffener is fixed

	for (i = 0; i <= (No_of_ShellCourses - 1); i++)
	{

		if ((y > shell_detail[i][22]) && (y <= shell_detail[i][23]))
			j = i;

	}

	x = shell_detail[j][24] + ((y - shell_detail[j][22]) *   shell_detail[j][0] / shell_detail[j][21]);

	return x;
}

int Shell_Course_No_Actual(double x)
{
	int i, j = 0;
	for (i = 0; i <= (No_of_ShellCourses - 1); i++)
	{
		if ((x > shell_detail[i][24]) && (x <= shell_detail[i][25]))
			j = i;
	}

	return j;
}

int Shell_Course_No_Transposed(double y)
{
	int i, j = 0;
	for (i = 0; i <= (No_of_ShellCourses - 1); i++)
	{
		if ((y > shell_detail[i][22]) && (y <= shell_detail[i][23]))
			j = i;
	}

	return j;
}


void shell_Design_VDP_td(int i)

{

	double temp1, temp2, x, x1, x2, x3, K, C, tL, tu, H1;
	int n;
	temp1 = (shell_detail[0][0] * 1000 / (pow((500 * D* (shell_detail[0][12] - shell_detail[0][9])), 0.5)));
	temp2 = (shell_detail[0][0] * 1000 / (pow((500 * D* shell_detail[0][13]), 0.5)));


	if ((i == 1) && (temp1 < 2.625f))
	{
		shell_detail[1][1] = shell_detail[0][1];
		shell_detail[1][2] = shell_detail[0][2];
		shell_detail[1][3] = shell_detail[0][3];
		shell_detail[1][4] = shell_detail[0][4];
		shell_detail[1][5] = shell_detail[0][5];
		shell_detail[1][6] = shell_detail[0][6];
		Shell_Material_No[1][1] = Shell_Material_No[0][1];
		Shell_Material_Name[1][1] = Shell_Material_Name[0][1];
		shell_detail[1][10] = ((4.9f*D*(shell_detail[1][7] - 0.3f))*G / (shell_detail[1][3])) + shell_detail[1][9];
	}


	tL = (shell_detail[(i - 1)][12] - shell_detail[(i - 1)][9]);
	tu = (shell_detail[i][10] - shell_detail[i][9]);
	H1 = shell_detail[i][8];

	ofstream outf("Sample.Out", ios::app);

	if (!outf)
	{  // Print an error and exit
		cerr << "Result File could not be opened for writing!" << endl;

	}

	if ((i == 1) && (Print_x == 1))
	{
		outf << endl << "Lower Course height (h1) 				=	" << shell_detail[0][0] << endl;
		outf << endl << "Constant (h1 / (rt1)^0.5) For td.		=	" << temp1 << endl;
		outf << endl << "Constant (h1 / (rt1)^0.5) For tt.		=	" << temp2 << endl;
		//		outf << endl << "All thicknesses below are exclusive of CA" << endl;

	}
	if (Print_x == 1)
	{
		outf << endl << "\n\n\t\t\t\t\tCourse No	=	" << (i + 1) << endl;
		outf << endl << "\t\t\t\t\tCalculation of design thickness" << endl;
		outf << endl << "Thickness of Lower Course (Corroded)			=	" << fixed << setprecision(3) << tL << endl << endl;
		outf << endl << "\tTrial	tu(d)	K	C	H	x1	x2	x3	x	T2A(d) \n\n";
	}


	for (n = 0; n <= 6; n++)
	{

		K = tL / tu;
		if (K < 1) K = 1;
		C = (((pow(K, 0.5))*(K - 1) / (1 + (pow(K, 1.5)))));
		x1 = ((0.61f * (pow((500 * D*tu), 0.5))) + (320 * C * H1));
		x2 = 1000 * C * H1;
		x3 = (1.22f* pow((500 * D*tu), 0.5));
		x = min(x1, x2, x3, x3, x3, x3, 3);
		double New_tu = roundup((4.9f*D*(H1 - (x / 1000))*G / shell_detail[i][3]), 3);



		if (Print_x == 1)

			outf << "\t"
			<< (n + 1) << "\t"
			<< fixed << setprecision(3) << tu << "\t"
			<< fixed << setprecision(3) << K << "\t"
			<< fixed << setprecision(3) << C << "\t"
			<< fixed << setprecision(3) << H1 << "\t"
			<< fixed << setprecision(1) << x1 << "\t"
			<< fixed << setprecision(1) << x2 << "\t"
			<< fixed << setprecision(1) << x3 << "\t"
			<< fixed << setprecision(1) << x << "\t"
			<< fixed << setprecision(3) << New_tu
			<< endl;

		tu = New_tu;

	}

	if (i == 1)
	{
		if (temp1 < 1.375)
		{
			shell_detail[i][12] = tL + shell_detail[i][9];

			if (Print_x == 1)
			{
				outf << "\n\n (h1/(rt1)^0.5) < 1.375		=	\n";
				outf << " ( hence t2 = t1		=	" << shell_detail[0][12] - shell_detail[0][9] << endl;

			}
		}
		else if (temp1 < 2.625)
		{
			shell_detail[i][12] = ((tu + ((tL - tu)* (2.1 - (temp1 / 1.25)))) + shell_detail[i][9]);

			if (Print_x == 1)
			{

				outf << "\n\n(h1/(rt1)^0.5) is between 1.375  & 2.625		\n";
				outf << "\nt2 = t2a + (t1-t2a)*(2.1-(h1 / (rt1)^0.5)\t\t=	" << shell_detail[i][12] - shell_detail[0][9] << endl;

			}
		}
		else
		{
			shell_detail[i][12] = tu + shell_detail[i][9];

			if (Print_x == 1)
			{

				outf << "  (h1/(rt1)^0.5) > 2.625		=	\n";
				outf << "hence t2 = t2a				=	" << shell_detail[i][12] - shell_detail[0][9] << endl;
			}
		}

		shell_detail[i][12] = tu + shell_detail[i][9];
		if (Print_x == 1)
			outf.close();
	}

	else
		shell_detail[i][12] = tu + shell_detail[i][9];
	if (Print_x == 1)
		outf.close();

	if ((K < 1.0001) && (Print_x == 1))
	{

		outf << endl << "The Required thickness of the upper course is \nmore than the Required thickness of lower course" <<
			"\nThe adopted thickness of the lower course will be\nincreased to same as the upper course thickness;" << endl;

		outf.close();
	}





}  // end of function shell_Design_VDP_td()









void shell_Design_VDP_tt(int i)

{

	double temp1, x, x1, x2, x3, K, C, tL, tu, H1;
	int n;

	temp1 = (shell_detail[0][0] * 1000 / (pow((500 * D* shell_detail[0][13]), 0.5)));


	if ((i == 1) && (temp1 < 2.625f) && (Shell_Material_No[1][2] != Shell_Material_No[0][2]))
	{
		shell_detail[1][1] = shell_detail[0][1];
		shell_detail[1][2] = shell_detail[0][2];
		shell_detail[1][3] = shell_detail[0][3];
		shell_detail[1][4] = shell_detail[0][4];
		shell_detail[1][5] = shell_detail[0][5];
		shell_detail[1][6] = shell_detail[0][6];
		Shell_Material_No[1][2] = Shell_Material_No[0][2];
		Shell_Material_Name[1][1] = Shell_Material_Name[0][1];
		shell_detail[1][11] = ((4.9f*D*(shell_detail[1][7] - 0.3f))*Gw / (shell_detail[1][4]));
	}


	tL = (shell_detail[(i - 1)][13]);
	tu = (shell_detail[i][11]);
	H1 = shell_detail[i][8];

	ofstream outf("Sample.Out", ios::app);

	if (!outf)
	{  // Print an error and exit
		cerr << "Result File could not be opened for writing!" << endl;
//		exit(1);
	}

	if ((i == 1) && (Print_x == 1))
	{
		//		outf << endl << "Lower Course height (h1) 				=	" << shell_detail[0][0] << endl;
		//		outf << endl << "Constant ( h1 / (rt1)^0.5 )			=	" << temp1 << endl;
		//		outf << endl << "All thicknesses below are exclusive of CA" << endl;

	}
	if (Print_x == 1)
	{
		//	outf << endl << "\t\t\t\t\tCourse No	=	" << (i+1) << endl;
		outf << endl << "\n\t\t\t\t\tCalculation of Test thickness" << endl;
		outf << endl << "Thickness of Lower Course	=	" << fixed << setprecision(3) << tL << endl << endl;
		outf << endl << "\tTrial	tu(t)	K	C	H	x1	x2	x3	x	T2A(t) \n\n";
	}


	for (n = 0; n <= 6; n++)
	{

		K = tL / tu;
		if (K < 1) K = 1;
		C = (((pow(K, 0.5))*(K - 1) / (1 + (pow(K, 1.5)))));
		x1 = ((0.61f * (pow((500 * D*tu), 0.5))) + (320 * C * H1));
		x2 = 1000 * C * H1;
		x3 = (1.22f* pow((500 * D*tu), 0.5));
		x = min(x1, x2, x3, x3, x3, x3, 3);
		double New_tu = roundup((4.9f*D*(H1 - (x / 1000))*Gw / shell_detail[i][4]), 3);


		if (Print_x == 1)
		{
			outf << "\t"
				<< (n + 1) << "\t"
				<< fixed << setprecision(3) << tu << "\t"
				<< fixed << setprecision(3) << K << "\t"
				<< fixed << setprecision(3) << C << "\t"
				<< fixed << setprecision(3) << H1 << "\t"
				<< fixed << setprecision(1) << x1 << "\t"
				<< fixed << setprecision(1) << x2 << "\t"
				<< fixed << setprecision(1) << x3 << "\t"
				<< fixed << setprecision(1) << x << "\t"
				<< fixed << setprecision(3) << New_tu
				<< endl;

		}
		tu = New_tu;

	}

	if (i == 1)
	{
		if (temp1 < 1.375)
		{
			shell_detail[i][13] = tL;

			if (Print_x == 1)
			{
				outf << "\n\n (h1/(rt1)^0.5) < 1.375		=	\n";
				outf << " ( hence t2 = t1		=	" << shell_detail[0][13] << endl;

			}
		}
		else if (temp1 < 2.625)
		{
			shell_detail[i][13] = (tu + ((tL - tu)* (2.1 - (temp1 / 1.25))));

			if (Print_x == 1)
			{

				outf << "\n\n(h1/(rt1)^0.5) is between 1.375  & 2.625		\n";
				outf << "\nt2 = t2a + (t1-t2a)*(2.1-(h1 / (rt1)^0.5)\t\t=	" << shell_detail[i][13] << endl;

			}
		}
		else
		{
			shell_detail[i][13] = tu;

			if (Print_x == 1)
			{

				outf << "  (h1/(rt1)^0.5) > 2.625		=	\n";
				outf << "hence t2 = t2a				=	" << shell_detail[i][13] << endl;
			}
		}

		shell_detail[i][13] = tu;
		if (Print_x == 1)
			outf.close();
	}

	else
		shell_detail[i][13] = tu;

	if ((K < 1.0001) && (Print_x == 1))
	{

		outf << endl << "The Required thickness of the upper course is \nmore than the Required thickness of lower course\nThe adopted thickness of the lower course will be\nincreased to same as the upper course thickness;" << endl;

		outf.close();
	}






}  // end of function shell_Design_VDP_tt()










void shell_Stiffener_Location()

{

	double incrmt;

	No_of_Stiffeners_R = No_of_Stiffeners = 0; // New Line added on 10th Sept 2018

	H_Ts_Calculation(); // This function will return the value of total transposed height of shell H_Ts

	if (RoundUP_to == 1)
		incrmt = 0.1;
	else
		incrmt = 1;

	//No_of_Stiffeners_Max = 20;

	/*
	// New Logic Added on 9th sept.

	if (No_of_Stiffeners_Max == 20)
	{
	if (tu_min_W > tu_min_Pe)
	tu_min = tu_min_W;
	else
	tu_min = tu_min_Pe;
	if (tu_min > t_uniform)
	shell_Design();
	H_Ts_Calculation();
	shell_Stfr_Min_EL();

	}



	// end of New Logic Added on 9th sept.

	*/

	if (No_of_Stiffeners_P > No_of_Stiffeners_Max)

	{

		while (No_of_Stiffeners_P > No_of_Stiffeners_Max)
		{
			tu_min = tu_min + incrmt;
			shell_Design();
			H_Ts_Calculation();
			shell_Stfr_Min_EL();
		}
	}

	shell_Stfr_Min_EL();

	if (No_of_Stiffeners > No_of_Stiffeners_Max)

	{

		while (No_of_Stiffeners > No_of_Stiffeners_Max)
		{
			tu_min = tu_min + incrmt;
			shell_Design();
			H_Ts_Calculation();
			shell_Stfr_Min_EL();
		}
	}


	shell_Stfr_Avg_EL();

}  // end of function shell_Stiffener_Location();


void H_Ts_Calculation()
{
	// beginning of of function H_Ts_Calculation();

	int i;

	double temp1, temp2;

	Ps = H_Max_Ps = H_Max_W = 0;

	H_Top = H - Spacing_Top_WG;

	if (Pe >	0.2500001)
	{
		if (Pe < 0.7)
			Psi = (Pe + 0.7) / 0.95;
		else if (Pe <= 1.2)
			Psi = (Pe / 0.48);
		else
			Psi = 2.5;
		W = 1.48 * pow((V / 190), 2);
		if ((W + (0.4 * Pe)) < Pe)
		{
			Ps = Pe;
			Psi = 3.0;
		}
		else
			Ps = W + (0.4 * Pe);

		H_Max_Ps = pow(t_uniform, 2.5) * Y_Mod / (15203 * pow(D, 1.5) * Ps * Psi);


		if (H_Max_Ps < (3 * Spacing_Min))
		{
			temp1 = 47.07 * pow((Psi * (3 * Spacing_Min) * Ps), 0.4) * pow(D, 0.6) / pow(Y_Mod, 0.4);
			tu_min_Pe = roundup(temp1, RoundUP_to);
			H_Max_Ps = pow(tu_min_Pe, 2.5) * Y_Mod / (15203 * pow(D, 1.5) * Ps * Psi);
		}



		//		end of check for the requirement of Appendix-V

	}

	H_Max_W = 9.47 * t_uniform * pow((t_uniform / D), 1.5) * pow((190 / V), 2) * Factor_M1;


	if ((Roof_Type_No >  6) && (H_Max_W <= Spacing_Top_WG))
	{
		temp2 = pow((Spacing_Top_WG * pow(D, 1.5) / (9.470 * pow((190 / V), 2) * Factor_M1)), 0.4);
		tu_min_W = roundup(temp2, RoundUP_to);
		H_Max_W = 9.47 * tu_min_W * pow((tu_min_W / D), 1.5) * pow((190 / V), 2) * Factor_M1;

	}

	if (H_Max_W < (3 * Spacing_Min))
	{
		temp2 = pow(((3 * Spacing_Min) * pow(D, 1.5) / (9.470 * pow((190 / V), 2) * Factor_M1)), 0.4);
		tu_min_W = roundup(temp2, RoundUP_to);
		H_Max_W = 9.47 * tu_min_W * pow((tu_min_W / D), 1.5) * pow((190 / V), 2) * Factor_M1;
	}

	if (Pe <= 0.2500001)
		H_Max = H_Max_W;
	else
		H_Max = (H_Max_W < H_Max_Ps) ? H_Max_W : H_Max_Ps;

	// correcting shell course thickness for the required minimum thickness;

	if (tu_min_W > tu_min_Pe)
		tu_min = tu_min_W;
	else
		tu_min = tu_min_Pe;
	if (tu_min > t_uniform)
		shell_Design();



	// start calculatio of H_Ts

	for (i = 0; i <= (No_of_ShellCourses - 1); i++)

	{
		if (option_Stfr == 1)
			shell_detail[i][21] = shell_detail[i][0] * (pow((t_uniform / shell_detail[i][19]), 2.5));
		else
			shell_detail[i][21] = shell_detail[i][0] * (pow((t_uniform / shell_detail[i][18]), 2.5));

		if (i == 0)
		{
			shell_detail[i][22] = 0;
			shell_detail[i][23] = shell_detail[i][21];
			shell_detail[i][24] = 0;
			shell_detail[i][25] = shell_detail[i][0];
			shell_detail[i][26] = Spacing_Min * shell_detail[i][21] / shell_detail[i][0];
		}
		else
		{
			shell_detail[i][22] = shell_detail[(i - 1)][23];
			shell_detail[i][23] = shell_detail[i][22] + shell_detail[i][21];
			shell_detail[i][24] = shell_detail[(i - 1)][25];
			shell_detail[i][25] = shell_detail[i][24] + shell_detail[i][0];
			shell_detail[i][26] = Spacing_Min * shell_detail[i][21] / shell_detail[i][0];
		}

	}

	if (shell_detail[(No_of_ShellCourses - 1)][0] > Spacing_Top_WG)

		H_Ts = shell_detail[(No_of_ShellCourses - 1)][23] - Spacing_Top_WG;
	else
		H_Ts = shell_detail[(No_of_ShellCourses - 1)][23] - shell_detail[(No_of_ShellCourses - 1)][0] - ((Spacing_Top_WG - shell_detail[(No_of_ShellCourses - 1)][0]) * shell_detail[(No_of_ShellCourses - 2)][21] / shell_detail[(No_of_ShellCourses - 2)][0]);



	No_of_Stiffeners_P = static_cast<int> (floor((H_Ts / H_Max)));


} // end of of function H_Ts_Calculation();


void call_test_tu_min()
{
	if (No_of_Stiffeners_Max_user > 0)
	{
		No_of_Stiffeners_Max = No_of_Stiffeners_Max_user;
		tu_min = 0;
	}
}


void shell_Stfr_Min_EL()

{
	// beginning of function for Calculation of Minimum Possible Elevation of stiffeners: shell_Stfr_Min_EL()

	int n, i, j;
	double temp4;

	n = 0;
	double H_Remaining = H_Ts;

	while (H_Remaining >= H_Max)
	{
		temp4 = H_Remaining - H_Max;
		// finding shell course number on which stiffener is fixed

		for (i = 0; i <= (No_of_ShellCourses - 1); i++)
		{
			if ((temp4 > shell_detail[i][22]) && (temp4 < shell_detail[i][23]))
				j = i;
		}


		if (temp4 < (shell_detail[j][22] + shell_detail[j][26]))
			stfr_detail[n][0] = (shell_detail[j][22] + shell_detail[j][26]);

		else if (temp4 >(shell_detail[j][23] - shell_detail[j][26]))
		{
			j = j + 1;
			stfr_detail[n][0] = (shell_detail[(j)][22] + shell_detail[(j)][26]);
		}

		else
			stfr_detail[n][0] = temp4;
		stfr_detail[n][1] = H_Remaining - stfr_detail[n][0];
		stfr_detail[n][2] = shell_detail[j][24] + ((stfr_detail[n][0] - shell_detail[j][22]) *  shell_detail[j][0] / shell_detail[j][21]); // Minimum Possible Elevation (Actual shell)
		if (n == 1)
			stfr_detail[n][3] = H - Spacing_Top_WG - stfr_detail[n][2];
		else
			stfr_detail[n][3] = stfr_detail[(n - 1)][2] - stfr_detail[n][2];
		stfr_location[n][0] = (j + 1);
		stfr_detail[n][5] = shell_detail[j][25] - stfr_detail[n][2];
		stfr_detail[n][6] = stfr_detail[n][2] - shell_detail[j][24];



		H_Remaining = stfr_detail[n][0];
		n++;


	}  // end of while loop


	No_of_Stiffeners = n;


}  // end of function for Calculation of Minimum Possible Elevation of stiffeners: shell_Stfr_Min_EL()



void shell_Stfr_Avg_EL()

{
	// beginning of function shell_Stfr_Avg_EL() for calculating the minimum spacing between stiffeners without incresing the number of stiffeners


	double temp4, temp5;
	int i, j, n;

	double H_Remaining = H_Ts;
	H_Avg = H_Ts / (No_of_Stiffeners + 1);

	temp5 = (H_Max - H_Avg) / 20;


	while (H_Remaining >= H_Avg)
	{
		H_Remaining = H_Ts;

		for (n = 0; n <= (No_of_Stiffeners - 1); n++)
		{
			temp4 = H_Remaining - H_Avg;

			// finding shell course number on which stiffener is fixed


			for (i = 0; i <= (No_of_ShellCourses - 1); i++)
			{
				if ((temp4 > shell_detail[i][22]) && (temp4 < shell_detail[i][23]))
					j = i;
			}




			if (temp4 < (shell_detail[j][22] + shell_detail[j][26]))
			{
				if ((shell_detail[j][22] - shell_detail[(j - 1)][26]) >(H_Remaining - H_Max))
				{
					stfr_detail[n][7] = (shell_detail[j][22] - shell_detail[(j - 1)][26]);
					j = j - 1;
				}

				else
					stfr_detail[n][7] = (shell_detail[j][22] + shell_detail[j][26]);
			}


			else if (temp4 > (shell_detail[j][23] - shell_detail[j][26]))
			{
				if ((shell_detail[j][23] - shell_detail[j][26]) > (H_Remaining - H_Max))

					stfr_detail[n][7] = (shell_detail[j][23] - shell_detail[j][26]);
				else
				{
					j = j + 1;
					stfr_detail[n][7] = (shell_detail[(j)][22] + shell_detail[(j)][26]);
				}
			}


			else
				stfr_detail[n][7] = temp4;
			stfr_detail[n][8] = H_Remaining - stfr_detail[n][7];
			stfr_detail[n][9] = shell_detail[j][24] + ((stfr_detail[n][7] - shell_detail[j][22]) *  shell_detail[j][0] / shell_detail[j][21]); //  Elevation (Actual shell)
			if (n == 0)
				stfr_detail[n][10] = H - Spacing_Top_WG - stfr_detail[n][9];
			else
				stfr_detail[n][10] = stfr_detail[(n - 1)][9] - stfr_detail[n][9];

			stfr_location[n][1] = j + 1;
			stfr_detail[n][12] = shell_detail[j][25] - stfr_detail[n][9];
			stfr_detail[n][13] = stfr_detail[n][9] - shell_detail[j][24];

			H_Remaining = stfr_detail[n][7];



		} // end of for loop

		H_Avg = H_Avg + temp5;




	}  //	end of while loop



} // end of function shell_Stfr_Avg_EL()




void shell_Stfr_User_EL()

{


	// beginning of function shell_Stfr_User_EL() for calculating the stiffener location, when user defines location of some of the stiffeners



	double temp1, temp3, temp5, temp7, temp8;
	int  i, j, k, n;

	double H_Remaining = H_Ts;
	n = 0;
	while (H_Remaining > H_Max)
	{
		// Calculation of maximum possible elevation of the first stiffener. New added on 28/08/2018

		temp1 = H_Remaining;
		j = Shell_Course_No_Transposed(temp1);


		// Calculation of "user_EL_detail[n][1] & [2]":  minimum possible elevation on  transposed & actual shell:
		temp1 = H_Remaining - H_Max;

		j = Shell_Course_No_Transposed(temp1);

		if (temp1 < (shell_detail[j][22] + shell_detail[j][26]))
			user_EL_detail[n][1] = (shell_detail[j][22] + shell_detail[j][26]);

		else if (temp1 >(shell_detail[j][23] - shell_detail[j][26]))
			user_EL_detail[n][1] = (shell_detail[(j + 1)][22] + shell_detail[(j + 1)][26]);

		else
			user_EL_detail[n][1] = temp1;

		user_EL_detail[n][2] = Transposed_To_Actual(user_EL_detail[n][1]);

		// Calculation of "user_EL_detail[n][3] & [4]" Maximum possible elevation on  transposed & actual shell :


		j = Shell_Course_No_Transposed(H_Remaining);
		temp3 = H_Remaining - shell_detail[j][26];     // Maximum possible elevation on transposed shell before correcting for fouling

		if (temp3 < (shell_detail[j][22] + shell_detail[j][26]))
		{
			j = j - 1;
			user_EL_detail[n][3] = (shell_detail[j][23] - shell_detail[j][26]);
		}

		else
			user_EL_detail[n][3] = temp3;

		user_EL_detail[n][4] = Transposed_To_Actual(user_EL_detail[n][3]);



		if ((n == 0) && (Roof_Type_No <= 6))
		{
			double temp1;
			temp1 = H_Ts - shell_detail[(No_of_ShellCourses - 1)][26];

			user_EL_detail[n][4] = (Transposed_To_Actual(temp1));

		}


		// Calculation of Proposed elevation on actual & transposed shell; Purpose is to reach as near to the Elevation calculated using average spacing.:

		if ((H_Remaining - H_Max) < stfr_detail[n][7])

			temp5 = stfr_detail[n][7];
		else
			temp5 = (H_Remaining - H_Max);

		j = Shell_Course_No_Transposed(temp5);

		if (temp5 < (shell_detail[j][22] + shell_detail[j][26]))
			user_EL_detail[n][5] = (shell_detail[j][22] + shell_detail[j][26]);

		else if (temp5 >(shell_detail[j][23] - shell_detail[j][26]))
			user_EL_detail[n][5] = (shell_detail[(j + 1)][22] + shell_detail[(j + 1)][26]);

		else
			user_EL_detail[n][5] = temp5;

		user_EL_detail[n][6] = Transposed_To_Actual(user_EL_detail[n][5]);  // Minimum possible elevation on actual shell after correcting for fouling


		k = 0; // k is used as a flag to indicate that the user specified elevation is not suitable to be used

		if ((user_EL_detail[n][8] > user_EL_detail[n][4]) || (user_EL_detail[n][8] < user_EL_detail[n][2]))
			k = 1;


		else if ((user_EL_detail[n][8] <= user_EL_detail[n][4]) && (user_EL_detail[n][8] >= user_EL_detail[n][2]))

		{
			user_EL_detail[n][7] = Actual_To_Transposed(user_EL_detail[n][8]);
			j = Shell_Course_No_Actual(user_EL_detail[n][8]);

			user_EL_detail[n][9] = shell_detail[j][25] - user_EL_detail[n][8];
			user_EL_detail[n][10] = user_EL_detail[n][8] - shell_detail[j][24];


			if ((user_EL_detail[n][9] < Spacing_Min) || (user_EL_detail[n][10] < Spacing_Min))
				k = 1;

			else

			{
				stfr_detail[n][14] = user_EL_detail[n][7];
				stfr_detail[n][16] = user_EL_detail[n][8];

			}

		}

		if ((user_EL_detail[n][8] < 0.1) || (k == 1))

		{
			if ((H_Remaining - H_Max) < stfr_detail[n][7])
				temp7 = stfr_detail[n][7];
			else
				temp7 = (H_Remaining - H_Max);

			j = Shell_Course_No_Transposed(temp7);

			if (temp7 < (shell_detail[j][22] + shell_detail[j][26]))
				user_EL_detail[n][7] = (shell_detail[j][22] + shell_detail[j][26]);

			else if (temp7 >(shell_detail[j][23] - shell_detail[j][26]))
				user_EL_detail[n][7] = (shell_detail[(j + 1)][22] + shell_detail[(j + 1)][26]);

			else
				user_EL_detail[n][7] = temp7;

			temp8 = Transposed_To_Actual(temp7);
			j = Shell_Course_No_Actual(temp8);

			user_EL_detail[n][9] = shell_detail[j][25] - temp8;
			user_EL_detail[n][10] = temp8 - shell_detail[j][24];

			stfr_detail[n][14] = user_EL_detail[n][7];
			stfr_detail[n][16] = temp8;


		}


		j = Shell_Course_No_Transposed(stfr_detail[n][14]);
		stfr_detail[n][15] = H_Remaining - stfr_detail[n][14];
		if (n == 0)
			stfr_detail[n][17] = H - Spacing_Top_WG - stfr_detail[n][16];
		else
			stfr_detail[n][17] = stfr_detail[(n - 1)][16] - stfr_detail[n][16];
		stfr_location[n][2] = (j + 1);
		stfr_detail[n][19] = shell_detail[j][25] - stfr_detail[n][16];
		stfr_detail[n][20] = stfr_detail[n][16] - shell_detail[j][24];

		H_Remaining = stfr_detail[n][14];
		if (H_Remaining > H_Max)

			n++;
		No_of_Stiffeners_R = (n + 1);

		// end of while loop
	}

	// selection of material for stiffeners



	if (Pe > 0.2500001)
	{
		for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
		{

			/*
			if (i == 0)

			{

			//		cout << endl << "Select material for First stiffener from top:	" << endl;
			//			cout  << endl << " Enter Serial Number of Material 			=	";
			//			cin >> c;
			c = 6;
			//			stfr_Mat_No[i] = c;

			}

			else
			{
			//			cout << endl << "Material for Siffener Serial Number " << (i+1)  << endl;

			//			cout  << endl << " Enter Serial Number of Material 			" << endl;
			//			cout << endl << "(Enter '0' if same as previous )		=		";
			//			cin >> c;

			//			c = 0;
			//			if (c > 0.1)
			//			stfr_Mat_No[i] = stfr_Mat_No[(i-1)];
			}
			*/
			Material_Selection(stfr_Mat_No[i], 515);

			Stfnr_Material_Name[i] = MOC;
			k = stfr_location[i][2] - 1;
			stfr_detail[i][25] = YS;
			if (stfr_detail[i][25] <= shell_detail[k][2])
				stfr_detail[i][26] = stfr_detail[i][25];
			else
				stfr_detail[i][26] = shell_detail[k][2];
			if (stfr_detail[i][26] * 0.4 < 103)
				stfr_detail[i][27] = 103;
			else
				stfr_detail[i][27] = stfr_detail[i][26] * 0.4;


		} // end of for statement for calculating the required properties of stiffener ring


	} // end of if statement for Pe > 0.25

	//I think this is necessary when a new value of no of stiffeners is assigned -- Abhishek on 27th Sept

	for(int i=No_of_Stiffeners_R;i<45;i++)
		user_EL_detail[i][8]=0.0; // reinitializing all the user defined values to 0 for stiffeners which have been rejected




} // end of function  shell_Stfr_User_EL()






void Roof_Design()


{
	double temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9, roof_thk_previous;

	int i;

	temp1 = (0.4 * Pe) + live_load;
	temp2 = (0.4 * live_load) + Pe;
	temp3 = (0.4 * Pe) + snow_load_bal;
	temp4 = (0.4 * snow_load_bal) + Pe;
	temp5 = (0.4 * Pe) + snow_load_unbal;
	temp6 = (0.4 * snow_load_unbal) + Pe;


	ext_load_bal = max(temp1, temp2, temp3, temp4, temp4, temp4, 4);
	ext_load_unbal = max(temp1, temp2, temp5, temp6, temp6, temp6, 4);
	ext_load = max(ext_load_bal, ext_load_unbal, ext_load, ext_load, ext_load, ext_load, 2);

	Material_Selection(Roof_Material_No, 515);

	Roof_Material_Name = MOC;
	Roof_Material_YS = YS;
	Roof_Material_SA = Sd;
	Roof_Material_Y_mod = Y_mod;
	Roof_Material_Y_mod_Atm = Y_mod_Atm;


	if ((Roof_Type_No == 1) || (Roof_Type_No == 2))
		Roof_Thk[2] = Roof_Thk[3] = Roof_Thk[4] = Roof_Thk[5] = Roof_Thk[6] = Roof_Thk[8] = 5.0;

	else

		//		Roof_Thk[2] = Roof_Thk[3] = Roof_Thk[4] = Roof_Thk[5] = 5.0 + CA_Roof;
		Roof_Thk[5] = 5.0 + CA_Roof;


	Roof_Thk[6] = roundup(Roof_Thk[5], RoundUP_to);

	if (Roof_Thk[7] > Roof_Thk[5])
		Roof_Thk[8] = Roof_Thk[7];
	else
		Roof_Thk[8] = Roof_Thk[6];
	Roof_Thk[9] = Roof_Thk[8] - CA_Roof;

	// for cone roof type 1,3 & 5

	if ((Roof_Type_No == 1) || (Roof_Type_No == 3) || (Roof_Type_No == 5))

	{

		theeta = atan(roof_slope);

		weight_Roof_Plate = PI*(pow(R_Roof, 2))* Roof_Thk[8] * 7.85 * 9.80665 / (1000 * cos(theeta)); // Kilo Newtons
		dead_load = weight_Roof_Plate / (PI*pow(R_Roof, 2));
		total_load_bal = dead_load + ext_load_bal;
		total_load_unbal = dead_load + ext_load_unbal;

		if (Roof_Type_No == 3) // calculation of minimum required thickness  for internal pressure

		{
			for (i = 0; i <= 5; i++)
			{
				if ((P - (dead_load * cos(theeta))) > 0)
					Roof_Thk[1] = ((P - (dead_load * cos(theeta)))*R_Roof / ((sin(theeta)) * JE_roof * Roof_Material_SA)) + CA_Roof;
				else Roof_Thk[1] = 0;

				if (Roof_Thk[1] > Roof_Thk[5])
				{
					Roof_Thk[5] = Roof_Thk[1];
					Roof_Thk[6] = roundup(Roof_Thk[5], RoundUP_to);

					if (Roof_Thk[7] >= Roof_Thk[6])
						Roof_Thk[8] = Roof_Thk[7];
					else
						Roof_Thk[8] = Roof_Thk[6];


					weight_Roof_Plate = PI*(pow(R_Roof, 2))* Roof_Thk[8] * 7.85 * 9.80665 / (1000 * cos(theeta)); // Kilo Newtons
					dead_load = weight_Roof_Plate / (PI*pow(R_Roof, 2));

					Roof_Thk[9] = Roof_Thk[8] - CA_Roof;
					weight_Roof_Plate_cor = PI*(pow(R_Roof, 2))* Roof_Thk[9] * 7.85 * 9.80665 / (1000 * cos(theeta)); // Kilo Newtons
					dead_load_cor = weight_Roof_Plate_cor / (PI*pow(R_Roof, 2));

				}

			}
			total_load_bal = dead_load + ext_load_bal;
			total_load_unbal = dead_load + ext_load_unbal;
			Rafter_spacing = (Roof_Thk[8] - CA_Roof) * pow((1.5*Roof_Material_YS * 1000 / (ext_load + dead_load)), 0.5);

		}


		else if (Roof_Type_No == 1) // calculation of minimum required thickness  for self supported cone roof

		{
			roof_thk_previous = Roof_Thk[8];
			Roof_Thk[2] = (D / (4.8 * sin(theeta))  * (pow((total_load_bal / 2.2), 0.5)) * (Roof_Material_Y_mod_Atm / Roof_Material_Y_mod)) + CA_Roof;
			Roof_Thk[3] = (D / (5.5 * sin(theeta))  * (pow((total_load_unbal / 2.2), 0.5)) * (Roof_Material_Y_mod_Atm / Roof_Material_Y_mod)) + CA_Roof;

			if (Pe > 0.2500001)
				Roof_Thk[4] = (83 * D / (sin(theeta))  * (pow((total_load_bal / (1.72 * Roof_Material_Y_mod)), 0.5))) + CA_Roof;

			Roof_Thk[5] = max(Roof_Thk[1], Roof_Thk[2], Roof_Thk[3], Roof_Thk[4], Roof_Thk[4], Roof_Thk[4], 4); // Minimum reqd thk
			Roof_Thk[6] = roundup(Roof_Thk[5], RoundUP_to);
			Roof_Thk[8] = max(Roof_Thk[6], Roof_Thk[7], Roof_Thk[7], Roof_Thk[7], Roof_Thk[7], Roof_Thk[7], 2);
			weight_Roof_Plate = PI*(pow(R_Roof, 2))* Roof_Thk[8] * 7.85 * 9.80665 / (1000 * cos(theeta)); // Kilo Newtons
			dead_load = weight_Roof_Plate / (PI*pow(R_Roof, 2));

			Roof_Thk[9] = Roof_Thk[8] - CA_Roof;
			weight_Roof_Plate_cor = PI*(pow(R_Roof, 2))* Roof_Thk[9] * 7.85 * 9.80665 / (1000 * cos(theeta)); // Kilo Newtons
			dead_load_cor = weight_Roof_Plate_cor / (PI*pow(R_Roof, 2));

			total_load_bal = dead_load + ext_load_bal;
			total_load_unbal = dead_load + ext_load_unbal;

			while (Roof_Thk[8] > roof_thk_previous)

			{
				roof_thk_previous = Roof_Thk[8];
				if ((P - (dead_load * cos(theeta))) > 0)
					Roof_Thk[1] = ((P - (dead_load * cos(theeta)))*R_Roof / ((sin(theeta)) * JE_roof * Roof_Material_SA)) + CA_Roof;
				else

					Roof_Thk[2] = (D / (4.8 * sin(theeta))  * (pow((total_load_bal / 2.2), 0.5)) * (Roof_Material_Y_mod_Atm / Roof_Material_Y_mod)) + CA_Roof;
				Roof_Thk[3] = (D / (5.5 * sin(theeta))  * (pow((total_load_unbal / 2.2), 0.5)) * (Roof_Material_Y_mod_Atm / Roof_Material_Y_mod)) + CA_Roof;

				if (Pe > 0.2500001)
					Roof_Thk[4] = (83 * D / (sin(theeta))  * (pow((total_load_bal / (1.72 * Roof_Material_Y_mod)), 0.5))) + CA_Roof;

				Roof_Thk[5] = max(Roof_Thk[1], Roof_Thk[2], Roof_Thk[3], Roof_Thk[4], Roof_Thk[4], Roof_Thk[4], 4); // Minimum reqd thk
				Roof_Thk[6] = roundup(Roof_Thk[5], RoundUP_to);
				Roof_Thk[8] = max(Roof_Thk[6], Roof_Thk[7], Roof_Thk[7], Roof_Thk[7], Roof_Thk[7], Roof_Thk[7], 2);

				dead_load = weight_Roof_Plate / (PI*pow(R_Roof, 2));
				total_load_bal = dead_load + ext_load_bal;
				total_load_unbal = dead_load + ext_load_unbal;

				Roof_Thk[9] = Roof_Thk[8] - CA_Roof;
				weight_Roof_Plate_cor = PI*(pow(R_Roof, 2))* Roof_Thk[9] * 7.85 * 9.80665 / (1000 * cos(theeta)); // Kilo Newtons
				dead_load_cor = weight_Roof_Plate_cor / (PI*pow(R_Roof, 2));


			} // end of while statement




		} // end of calculation for Roof_Type_No = 1

		else if (Roof_Type_No == 5)
		{
			if (P < (ext_load + dead_load))
				Rafter_spacing = (Roof_Thk[8] - CA_Roof) * pow((1.5*Roof_Material_YS * 1000 / (ext_load + dead_load)), 0.5);
			else
				Rafter_spacing = (Roof_Thk[8] - CA_Roof) * pow((1.5*Roof_Material_YS * 1000 / P), 0.5);
		}




	} //end of calculation for roof type 1,3,5



	else if ((Roof_Type_No == 2) || (Roof_Type_No == 4) || (Roof_Type_No == 6))
	{

		double temp = R_Roof / (dome_radius);
		theeta = asin(temp);
		roof_slope = tan(theeta);
		weight_Roof_Plate = (2 * PI * (pow(dome_radius, 2)) * (1 - cos(theeta)) * Roof_Thk[8] * 7.85 * 9.80665 / 1000); // Kilo Newtons
		dead_load = weight_Roof_Plate / (PI*pow(R_Roof, 2));
		total_load_bal = dead_load + ext_load_bal;
		total_load_unbal = dead_load + ext_load_unbal;

		Roof_Thk[9] = Roof_Thk[8] - CA_Roof;
		weight_Roof_Plate_cor = PI*(pow(R_Roof, 2))* Roof_Thk[9] * 7.85 * 9.80665 / (1000 * cos(theeta)); // Kilo Newtons
		dead_load_cor = weight_Roof_Plate_cor / (PI*pow(R_Roof, 2));


		temp9 = (1 - 2 * cos(theeta));

		if (Roof_Type_No == 4)
		{
			for (i = 0; i <= 5; i++)
			{

				temp7 = dead_load; // (W / At: weight of roof devided by Hor. projected area of roof)

				temp8 = dome_radius * (P + (temp9 * dead_load)) / 2;  // T2: the governing of the two unit forces T1 & T2. dead_load represent (W/At)
				if (temp8 > 0)

					Roof_Thk[1] = (temp8 / (JE_roof * Roof_Material_SA)) + CA_Roof;
				else
					Roof_Thk[1] = 0;

				if (Roof_Thk[1] > Roof_Thk[5])
				{
					Roof_Thk[5] = Roof_Thk[1];
					Roof_Thk[6] = roundup(Roof_Thk[5], RoundUP_to);

					if (Roof_Thk[7] >= Roof_Thk[6])
						Roof_Thk[8] = Roof_Thk[7];
					else
						Roof_Thk[8] = Roof_Thk[6];

					weight_Roof_Plate = PI*(pow(R_Roof, 2))* Roof_Thk[8] * 7.85 * 9.80665 / (1000 * cos(theeta)); // Kilo Newtons
					dead_load = weight_Roof_Plate / (PI*pow(R_Roof, 2));
					total_load_bal = dead_load + ext_load_bal;
					total_load_unbal = dead_load + ext_load_unbal;

					Roof_Thk[9] = Roof_Thk[8] - CA_Roof;
					weight_Roof_Plate_cor = PI*(pow(R_Roof, 2))* Roof_Thk[9] * 7.85 * 9.80665 / (1000 * cos(theeta)); // Kilo Newtons
					dead_load_cor = weight_Roof_Plate_cor / (PI*pow(R_Roof, 2));

				}


			}

			Rafter_spacing = (Roof_Thk[8] - CA_Roof) * pow((1.5*Roof_Material_YS * 1000 / ((ext_load + dead_load) * cos(theeta))), 0.5);
			Rafter_spacing_cent = (Roof_Thk[8] - CA_Roof) * pow((1.5*Roof_Material_YS * 1000 / (ext_load + dead_load)), 0.5);

		}

		else if (Roof_Type_No == 2) // calculation of minimum required thickness  for self supported roof
		{
			roof_thk_previous = Roof_Thk[8];
			temp8 = dome_radius * (P + (temp9 * dead_load)) / 2;  // T2: the governing of the two unit forces T1 & T2. dead_load represent (W/At)
			//			cout << endl << "dome_radius * ( P + (temp9 * dead_load) ) / 2 =	" << fixed << setprecision(2) << Roof_Thk[1] << endl << endl;
			if (temp8 > 0)
				Roof_Thk[1] = (temp8 / (JE_roof * Roof_Material_SA)) + CA_Roof;
			else
				Roof_Thk[1] = 0;
			//			cout << endl << "Roof thk for Internal Pressure =	" << fixed << setprecision(2) << Roof_Thk[1] << endl << endl;
			Roof_Thk[2] = ((dome_radius / 2.4)  * (pow((total_load_bal / 2.2), 0.5)) * (Roof_Material_Y_mod_Atm / Roof_Material_Y_mod)) + CA_Roof;
			Roof_Thk[3] = ((dome_radius / 2.7)  * (pow((total_load_bal / 2.2), 0.5)) * (Roof_Material_Y_mod_Atm / Roof_Material_Y_mod)) + CA_Roof;

			if (Pe > 0.2500001)
				Roof_Thk[4] = (141 * dome_radius * (pow((total_load_bal / Roof_Material_Y_mod), 0.5))) + CA_Roof;
			Roof_Thk[5] = max(Roof_Thk[1], Roof_Thk[2], Roof_Thk[3], Roof_Thk[4], Roof_Thk[4], Roof_Thk[4], 4); // Minimum reqd thk for external pressure

			Roof_Thk[6] = roundup(Roof_Thk[5], RoundUP_to);
			Roof_Thk[8] = max(Roof_Thk[6], Roof_Thk[7], Roof_Thk[7], Roof_Thk[7], Roof_Thk[7], Roof_Thk[7], 2);
			weight_Roof_Plate = (2 * PI * (pow(dome_radius, 2)) * (1 - cos(theeta)) * Roof_Thk[8] * 7.85 * 9.80665 / 1000); // Kilo Newtons

			dead_load = weight_Roof_Plate / (PI*pow(R_Roof, 2));
			total_load_bal = dead_load + ext_load_bal;
			total_load_unbal = dead_load + ext_load_unbal;

			Roof_Thk[9] = Roof_Thk[8] - CA_Roof;
			weight_Roof_Plate_cor = PI*(pow(R_Roof, 2))* Roof_Thk[9] * 7.85 * 9.80665 / (1000 * cos(theeta)); // Kilo Newtons
			dead_load_cor = weight_Roof_Plate_cor / (PI*pow(R_Roof, 2));

			while (Roof_Thk[8] > roof_thk_previous)
			{

				roof_thk_previous = Roof_Thk[8];

				temp8 = dome_radius * (P + (temp9 * dead_load)) / 2;  // T2: the governing of the two unit forces T1 & T2. dead_load represent (W/At)

				if (temp8 > 0)
					Roof_Thk[1] = (temp8 / (JE_roof * Roof_Material_SA)) + CA_Roof;
				else
					Roof_Thk[1] = 0;


				Roof_Thk[2] = ((dome_radius / 2.4)  * (pow((total_load_bal / 2.2), 0.5)) * (Roof_Material_Y_mod_Atm / Roof_Material_Y_mod)) + CA_Roof;
				Roof_Thk[3] = ((dome_radius / 2.7)  * (pow((total_load_bal / 2.2), 0.5)) * (Roof_Material_Y_mod_Atm / Roof_Material_Y_mod)) + CA_Roof;

				if (Pe > 0.2500001)
					Roof_Thk[4] = (141 * dome_radius * (pow((total_load_bal / Roof_Material_Y_mod), 0.5))) + CA_Roof;

				Roof_Thk[5] = max(Roof_Thk[1], Roof_Thk[2], Roof_Thk[3], Roof_Thk[4], Roof_Thk[4], Roof_Thk[4], 4); // Minimum reqd thk for external pressure

				Roof_Thk[6] = roundup(Roof_Thk[5], RoundUP_to);
				Roof_Thk[8] = max(Roof_Thk[6], Roof_Thk[7], Roof_Thk[7], Roof_Thk[7], Roof_Thk[7], Roof_Thk[7], 2);

				weight_Roof_Plate = (2 * PI * (pow(dome_radius, 2)) * (1 - cos(theeta)) * Roof_Thk[8] * 7.85 * 9.80665 / 1000); // Kilo Newtons
				dead_load = weight_Roof_Plate / (PI*pow(R_Roof, 2));
				total_load_bal = dead_load + ext_load_bal;
				total_load_unbal = dead_load + ext_load_unbal;

				Roof_Thk[9] = Roof_Thk[8] - CA_Roof;
				weight_Roof_Plate_cor = PI*(pow(R_Roof, 2))* Roof_Thk[9] * 7.85 * 9.80665 / (1000 * cos(theeta)); // Kilo Newtons
				dead_load_cor = weight_Roof_Plate_cor / (PI*pow(R_Roof, 2));



			} // end of while statement

		} //end of calculation for roof type 2


		else if (Roof_Type_No == 6)
		{
			if (P < (ext_load + dead_load))
			{
				Rafter_spacing = (Roof_Thk[8] - CA_Roof) * pow((1.5*Roof_Material_YS * 1000 / ((ext_load + dead_load) * cos(theeta))), 0.5);
				Rafter_spacing_cent = (Roof_Thk[8] - CA_Roof) * pow((1.5*Roof_Material_YS * 1000 / (ext_load + dead_load)), 0.5);
			}
			else
			{
				Rafter_spacing = (Roof_Thk[8] - CA_Roof) * pow((1.5*Roof_Material_YS * 1000 / (P * cos(theeta))), 0.5);
				Rafter_spacing_cent = (Roof_Thk[8] - CA_Roof) * pow((1.5*Roof_Material_YS * 1000 / P), 0.5);
			}
		}




	} //end of calculation for roof type 2,4,6

	if (Rafter_spacing > 2100)
		Rafter_spacing = 2100;

	if (Rafter_spacing_cent > 2100)
		Rafter_spacing_cent = 2100;



	cout << endl << "Roof Type Considered =	" << fixed << setprecision(2) << Roof_Type_No << endl << endl;
	cout << endl << "Youngs Modulus of Roof =	" << fixed << setprecision(2) << Roof_Material_Y_mod << endl << endl;
	cout << endl << "Yield Strength of Roof =	" << fixed << setprecision(2) << Roof_Material_YS << endl << endl;
	cout << endl << "Allowable stess of Roof =	" << fixed << setprecision(2) << Roof_Material_SA << endl << endl;
	cout << endl << "Design Internal Pressure =	" << fixed << setprecision(2) << P << endl << endl;
	cout << endl << "Dead Load =	" << fixed << setprecision(3) << dead_load << endl << endl;
	cout << endl << "Design External Pressure =	" << fixed << setprecision(2) << Pe << endl << endl;
	cout << endl << "(0.4 * Pe) + live_load =	" << fixed << setprecision(2) << ext_load_bal << endl << endl;
	cout << endl << "(0.4 * live_load) + Pe =	" << fixed << setprecision(2) << ext_load_unbal << endl << endl;
	cout << endl << "Governing External load =	" << fixed << setprecision(2) << ext_load << endl << endl;
	cout << endl << "Design Internal Pressure =	" << fixed << setprecision(2) << P << endl << endl;
	if ((Roof_Type_No == 1) || (Roof_Type_No == 2))
	{
		cout << endl << "Load Combination T =	" << fixed << setprecision(2) << ext_load_bal << endl << endl;
		cout << endl << "Load Combination U =	" << fixed << setprecision(2) << ext_load_unbal << endl << endl;
		cout << endl << "Roof thk for load T =	" << fixed << setprecision(2) << Roof_Thk[2] << endl << endl;
		cout << endl << "Roof thk for load u =	" << fixed << setprecision(2) << Roof_Thk[3] << endl << endl;
		cout << endl << "Roof thk as per Apx V =	" << fixed << setprecision(2) << Roof_Thk[4] << endl << endl;
	}
	cout << endl << "Joint Efiiciency of Roof =	" << fixed << setprecision(2) << JE_roof << endl << endl;
	cout << endl << "Roof thk for Internal Pressure =	" << fixed << setprecision(2) << Roof_Thk[1] << endl << endl;

	cout << endl << "Minimum Required Roof thk =	" << fixed << setprecision(2) << Roof_Thk[5] << endl << endl;
	cout << endl << "Roof thk defined by user		=	" << fixed << setprecision(2) << Roof_Thk[7] << endl << endl;
	cout << endl << "Roof thk Adopted =	" << fixed << setprecision(2) << Roof_Thk[8] << endl << endl;
	if ((Roof_Type_No == 3) || (Roof_Type_No == 5))
		cout << endl << "Maximum Rafter Spacing =	" << fixed << setprecision(0) << Rafter_spacing << endl << endl;

	else if ((Roof_Type_No == 4) || (Roof_Type_No == 6))
	{
		cout << endl << "Maximum Rafter Spacing at periphery =	" << fixed << setprecision(0) << Rafter_spacing << endl << endl;
		cout << endl << "Maximum Rafter Spacing at center =	" << fixed << setprecision(0) << Rafter_spacing_cent << endl << endl;
	}

	cout << endl << "At the end of roof design			" << endl;
	cout << endl << "Roof Type specified by user =	" << fixed << setprecision(2) << Roof_Type_No_user << endl << endl;
	cout << endl << "Roof Type Adopted			 =	" << fixed << setprecision(2) << Roof_Type_No << endl << endl;



} // end function Roof_Design()




void CompRing_Data()
{

	// local variable



	string CompRing_list[11] = { "compRing", "detail a", "detail b", "detail c", "detail d", "detail e", "detail f", "detail g", "detail h", "detail i", "detail k" };;

	cout << endl << "Detail of Roof to shell junction : (Enter: " << endl << endl <<
		"1	For detail a " << endl << endl <<
		"2	For detail b " << endl << endl <<
		"3	For detail c " << endl << endl <<
		"4	For detail d " << endl << endl <<
		"5	For detail e " << endl << endl <<
		"6	For detail f " << endl << endl <<
		"7	For detail g " << endl << endl <<
		"8	For detail h " << endl << endl <<
		"9	For detail i " << endl << endl <<
		"10 For detail k  )" << endl;
	cin >> CR_Type_No[1];

	if (CR_Type_No[1] == 0)
		CR_Type_No[1] = 2;

	CR_Type_No[0] = CR_Type_No[1];

	CompRing_Type[1] = CompRing_list[CR_Type_No[1]];
	CompRing_Type[0] = CompRing_Type[1];





	if (CR_Type_No[1] <= 7)
	{
		cout << endl << endl << " Enter Serial Number of Material of the added angle	=	";
		cin >> CR_Material_No[1];

	}

	else if (CR_Type_No[1] == 9)
	{
		cout << endl << endl << " Enter Serial Number of the Material for Thicker Roof Plate; (Enter 0 if same as:   " << Roof_Material_No << ")		=	";

		cin >> CR_Material_No[1];

	}




	else if ((CR_Type_No[1] == 8) || (CR_Type_No[1] == 10))
	{
		cout << endl << endl << " Enter Serial Number of Material for the added bar in the roof to shell joint	=	";
		cin >> CR_Material_No[1];

		if (CR_Type_No[1] == 10)
		{
			cout << endl << "Enter Serial Number of Material for the thicker shell; (Enter 0 if same as:   " << Shell_Material_No[(No_of_ShellCourses - 1)][1] << ")		=	";

			cin >> CR_Material_No[4];


		}

	}


} // end of function CompRing_Data()



double wc_corr, wc_asbuilt, wh_corr, wh_asbuilt, Rc, Rc_corr, R2, R2_corr, CompRing_area_corr,
CompRing_area_asbuilt, CompRing_MOI_Corr, CompRing_MOI_asbuilt;

double  YS_CR_Ring, AS_CR_Ring, YS_CR_Ring_angle, AS_CR_Ring_angle, YS_CR_Ring_bar, AS_CR_Ring_bar, YS_CR_Ring_shell, AS_CR_Ring_shell, YS_CR_Ring_roof, AS_CR_Ring_roof, Y_Mod_CR_Ring_angle, Y_Mod_Atm_CR_Ring_angle,
Y_Mod_Atm_CR_Ring_shell, Y_Mod_CR_Ring_shell, Y_Mod_Atm_CR_Ring_Roof, Y_Mod_CR_Ring_Roof, Y_Mod_Atm_CR_Ring_bar, Y_Mod_CR_Ring_bar, Y_Mod_CR_Ring, Factor_M1_CR_Ring, DLR;


void CompRing_Design()
{



	// calculation for required properties

	double temp1 = 0;

	int i, j, k, m, n, p;

	string Name_CR_Ring_Material, Name_CR_Ring_Shell_Material, Name_CR_Ring_Roof_Material, Name_CR_Ring_bar_Material;

	Material_Selection(CR_Material_No[0], 515);
	YS_CR_Ring_bar = YS_CR_Ring_angle = YS;
	AS_CR_Ring_bar = AS_CR_Ring_angle = Sd;
	if (Shell_Appendx_No == 5)
	{
		Y_Mod_Atm_CR_Ring_angle = Y_Mod_Atm_CR_Ring_bar = Y_mod_Atm;
		Y_Mod_CR_Ring_angle = Y_Mod_CR_Ring_bar = Y_mod;
		Y_Mod_Atm_CR_Ring_shell = Y_Mod_X[(No_of_ShellCourses - 1)][1];
		Y_Mod_CR_Ring_shell = Y_Mod_X[(No_of_ShellCourses - 1)][0];
		Y_Mod_Atm_CR_Ring_Roof = Roof_Material_Y_mod_Atm;
		Y_Mod_CR_Ring_Roof = Roof_Material_Y_mod;
	}

	Name_CR_Ring_bar_Material = Name_CR_Ring_Material = MOC;


	Name_CR_Ring_Roof_Material = Roof_Material_Name;
	Name_CR_Ring_Shell_Material = Shell_Material_No[(No_of_ShellCourses - 1)][1];

	YS_CR_Ring_roof = Roof_Material_YS;
	YS_CR_Ring_shell = shell_detail[(No_of_ShellCourses - 1)][2];

	AS_CR_Ring_roof = Roof_Material_SA;
	AS_CR_Ring_shell = Shell_Material_No[(No_of_ShellCourses - 1)][3];

	if (CR_Type_No[0] <= 8)

	{
		YS_CR_Ring = min(YS_CR_Ring_shell, YS_CR_Ring_roof, YS_CR_Ring_bar, YS_CR_Ring_angle, YS_CR_Ring_angle, YS_CR_Ring_angle, 3);

		AS_CR_Ring = min(AS_CR_Ring_shell, AS_CR_Ring_roof, AS_CR_Ring_bar, AS_CR_Ring_angle, YS_CR_Ring_angle, YS_CR_Ring_angle, 3);

	}
	else if (CR_Type_No[0] == 9)

	{
		YS_CR_Ring_roof = YS_CR_Ring_angle;
		AS_CR_Ring_roof = AS_CR_Ring_angle;
		if (Shell_Appendx_No == 5)
		{
			Y_Mod_Atm_CR_Ring_Roof = Roof_Material_Y_mod_Atm;
			Y_Mod_Atm_CR_Ring_Roof = Roof_Material_Y_mod;
		}

		YS_CR_Ring = min(YS_CR_Ring_shell, YS_CR_Ring_roof, YS_CR_Ring_roof, YS_CR_Ring_roof, YS_CR_Ring_roof, YS_CR_Ring_roof, 2);
		AS_CR_Ring = min(AS_CR_Ring_shell, AS_CR_Ring_roof, AS_CR_Ring_roof, AS_CR_Ring_roof, AS_CR_Ring_roof, AS_CR_Ring_roof, 2);

		Name_CR_Ring_Roof_Material = Name_CR_Ring_Material;

	}

	else // For CR Ring type K
	{

		Material_Selection(CR_Material_No[1], 515);
		YS_CR_Ring_shell = YS;
		Name_CR_Ring_Shell_Material = MOC;

		if (Shell_Appendx_No == 5)
		{
			Y_Mod_Atm_CR_Ring_shell = Y_mod_Atm;
			Y_Mod_CR_Ring_shell = Y_mod;

		}


		YS_CR_Ring = min(YS_CR_Ring_shell, YS_CR_Ring_roof, YS_CR_Ring_bar, YS_CR_Ring_bar, YS_CR_Ring_bar, YS_CR_Ring_bar, 3);
		AS_CR_Ring = min(AS_CR_Ring_shell, AS_CR_Ring_roof, AS_CR_Ring_bar, AS_CR_Ring_bar, AS_CR_Ring_bar, AS_CR_Ring_bar, 3);

	}

	if (Shell_Appendx_No == 5)
	{
		Factor_M1_CR_Ring = min((Y_Mod_CR_Ring_angle / Y_Mod_Atm_CR_Ring_angle), (Y_Mod_CR_Ring_shell / Y_Mod_Atm_CR_Ring_shell), (Y_Mod_CR_Ring_Roof / Y_Mod_Atm_CR_Ring_Roof), 2.0, 2.0, 2.0, 4);

		Y_Mod_CR_Ring = min(Y_Mod_CR_Ring_angle, Y_Mod_CR_Ring_shell, Y_Mod_CR_Ring_Roof, Y_Mod_CR_Ring_Roof, Y_Mod_CR_Ring_Roof, Y_Mod_CR_Ring_Roof, 3);
		AS_CR_Ring = 0.6* YS_CR_Ring; // clause X.3.5.2
	}

	else
		Factor_M1_CR_Ring = Y_Mod / Y_Mod_Atm;

	// Calculation of DLR.

	if ((Roof_Type_No = 5) || (Roof_Type_No = 6))

		DLR = weight_Roof_Plate + Wt_Roof_Str;
	else
		DLR = weight_Roof_Plate;



	if ((P - (0.00127 * DLR / pow(D, 2))) > 0)
	{
		apndx_F = 1;

		compRing_detail[0] = (200 * pow(D, 2) * (P - (0.00127 * DLR / pow(D, 2)))) / (Roof_Material_YS * tan(theeta)); // Area required for Internal pressure

	}

	else
	{
		apndx_F = 0;

		compRing_detail[0] = 0;

	}

	if (Roof_Type_No == 1)

		compRing_detail[1] = 125 * total_load_bal * pow(D, 2) / (AS_CR_Ring * tan(theeta)); // area required for self supporting cone roof

	else if (Roof_Type_No == 2)

		compRing_detail[1] = 300 * total_load_bal * D * dome_radius / (AS_CR_Ring); // area required for self supporting dome roof.
	else

		compRing_detail[1] = 0;

	if (Pe > 0.2500001)
	{
		temp1 = 250 * Ps * H; // V
		compRing_detail[2] = temp1 * D / (2 * AS_CR_Ring); // Required Area of end stiffener
		compRing_detail[3] = 37.5 * temp1 * pow(D, 3) / (Y_Mod_CR_Ring * (N_Sqr - 1)); // Required MOI as per clause V8.2.3.2 (cm^4) stfr_detail[i][29]

	}

	compRing_detail[4] = max(compRing_detail[0], compRing_detail[1], compRing_detail[2], compRing_detail[0], compRing_detail[0], compRing_detail[0], 3); // Highest of reuired areas.


	if (D_Type == 1)
		Rc = (D * 1000 - shell_detail[(No_of_ShellCourses - 1)][18]) / 2; // Inner Radius in mm'
	else
		Rc = (D * 1000) / 2;
	Rc_corr = Rc + shell_detail[(No_of_ShellCourses - 1)][9];

	R2 = Rc / (sin(theeta));
	R2_corr = R2 + CA_Roof;


	wc_corr = 0.6* (pow((Rc*shell_detail[(No_of_ShellCourses - 1)][19]), 0.5));

	wh_corr = 0.3* (pow((R2*Roof_Thk[9]), 0.5));
	if (wh_corr > 300) wh_corr = 300;

	wc_asbuilt = 0.6* (pow((Rc*shell_detail[(No_of_ShellCourses - 1)][18]), 0.5));

	wh_asbuilt = 0.3* (pow((R2*Roof_Thk[8]), 0.5));
	if (wh_asbuilt > 300) wh_asbuilt = 300;


	if (D <= 11) j = 0;
	else if (D <= 18) j = 1;
	else
		j = 10;                   // Assigning minimum size of curbe angle as per clause
	k = 1;

	m = n = p = 0;
	if (Roof_Type_No > 2) n = 1;
	if (Pe < 0.25001) p = 1;

	if (CR_Type_No[0] <= 6)
	{
		while ((m = 0) || (n = 0) || (p = 0))
		{
			CompRing_Angle_Properties(j, k); // Returns the values of CompRing_area_asbuilt, CompRing_area_corroded, CompRing_MOI_asbuilt, CompRing_MOI_corroded

			if (CompRing_area_corr > compRing_detail[0]) m = 1;


			if ((option_Stfr == 1) && (Roof_Type_No <= 2) && (CompRing_area_corr > compRing_detail[1])) n = 1;
			else
				if ((option_Stfr == 0) && (Roof_Type_No <= 2) && (CompRing_area_asbuilt > compRing_detail[1])) n = 1;

			if (Pe > 0.25001)

			{
				if ((option_Stfr == 1) && (CompRing_area_corr > compRing_detail[0]) && (CompRing_MOI_Corr > compRing_detail[3])) p = 1;

				else if ((option_Stfr == 0) && (CompRing_area_asbuilt > compRing_detail[0]) && (CompRing_MOI_asbuilt > compRing_detail[3])) p = 1;

			}

			if ((m = 0) || (n = 0) || (p = 0)) j++;

		}

	}






} // end of function CompRing_Design()







void CompRing_Angle_Properties(int j, int k)




{
	double temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9, temp10, temp11, temp12, temp13, temp14, temp15, temp16, temp17, temp18, temp19, temp20, temp21, temp22, temp23, temp24, temp25, temp26, temp27, temp28, temp29, temp30, temp31, temp32, temp33, temp34, temp35;

	string CR_angle_name[] = { "L50x50x5   ", "L50x50x6   ", "L65x65x6   ", "L70x70x6   ", "L75x75x6   ", "L80x80x6   ", "L90x90x6   ", "L75x75x8   ", "L80x80x8   ", "L90x90x8   ", "L75x75x10   ", "L80x80x10  ", "L100x100x8 ", "L90x90x10  ", "L120x120x8 ", "L100x100x10", "L90x90x12  ", "L100x100x12", "L120x120x10", "L120x120x12", "L150x150x10", "L150x150x12", "L160x160x15", "L150x150x18", "L180x180x16", "L200x200x16", "L200x200x18", "L200x200x20", "L200x200x24" };


	double CR_Ring_width[] = { 50.0, 50.0, 65.0, 70.0, 75.0, 80.0, 90.0, 75.0, 80.0, 90.0, 75.0, 80.0, 100.0, 90.0, 120.0, 100.0, 90.0, 100.0, 120.0, 120.0, 150.0, 150.0, 160.0, 150.0, 180.0, 200.0, 200.0, 200.0, 200.0 };


	double CR_Ring_thk[] = { 5.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 8.0, 8.0, 8.0, 10.0, 10.0, 8.0, 10.0, 8.0, 10.0, 12.0, 12.0, 10.0, 12.0, 10.0, 12.0, 15.0, 18.0, 16.0, 16.0, 18.0, 20.0, 24.0 };


	double CR_Ring_area[] = { 4.750, 5.640, 7.440, 8.040, 8.640, 9.240, 10.440, 11.360, 12.160, 13.760, 14.000, 15.000, 15.360, 17.000, 18.560, 19.000, 20.160, 22.560, 23.000, 27.360, 29.000, 34.560, 45.750, 50.760, 55.040, 61.440, 68.760, 76.000, 90.240 };


	if (CR_Type_No[1] < 6) // This is only for type a; otheres to be made

	{

		temp31 = 0.6* (pow((Rc*  (shell_detail[(No_of_ShellCourses - 1)][18] + CR_Ring_thk[j])), 0.5)); // Asbuilt effective length of shell using combined thickness
		temp32 = 0.6* (pow((Rc*  (shell_detail[(No_of_ShellCourses - 1)][19] + CR_Ring_thk[j])), 0.5));   // corroded effective length of shell using combined thickness

		if (temp31 > CR_Ring_width[j]) temp31 = CR_Ring_width[j];
		if (temp32 > CR_Ring_width[j]) temp32 = CR_Ring_width[j];

		if (temp31 < wc_asbuilt) temp31 = wc_asbuilt;

		if (temp32 < wc_corr) temp32 = wc_corr;

		CompRing_area_asbuilt = (temp31*shell_detail[(No_of_ShellCourses - 1)][18]) + (wh_asbuilt*Roof_Thk[8]) + (CR_Ring_area[j]);
		CompRing_area_corr = (temp32*shell_detail[(No_of_ShellCourses - 1)][19]) + (wh_corr*Roof_Thk[9]) + (CR_Ring_area[j]);  //  Loss in area of angle due to corrosion is ignored.

		//calculation of compression ring MOI_corr & MOI_asbuilt

		//MOI_asbuilt

		temp1 = (temp31*shell_detail[(No_of_ShellCourses - 1)][18]) * (Rc + (shell_detail[(No_of_ShellCourses - 1)][18] / 2)); // A1*D1 (shell)

		temp2 = (CR_Ring_width[j] * CR_Ring_thk[j])* (Rc + shell_detail[(No_of_ShellCourses - 1)][18] + (CR_Ring_thk[j] / 2)); // A2*D2 (flange of angle)

		temp34 = (250 / pow(YS_CR_Ring_angle, 0.5)); // L
		if (temp34 > (CR_Ring_width[j] - CR_Ring_thk[j]))
			temp3 = (CR_Ring_width[j] - CR_Ring_thk[j]); // effective web width of outer angle
		else temp3 = temp34;

		temp4 = (temp3 * CR_Ring_thk[j])* (Rc + shell_detail[(No_of_ShellCourses - 1)][18] + CR_Ring_thk[j] + (temp3 / 2)); // A3*D3 (web of angle)

		temp5 = (temp31*shell_detail[(No_of_ShellCourses - 1)][18]) + (CR_Ring_width[j] * CR_Ring_thk[j]) + (temp3 * CR_Ring_thk[j]); // Sigma Area

		temp6 = temp1 + temp2 + temp4; // sigma AD

		temp7 = temp6 / temp5;  // sigma ADS / Sigma A;


		temp8 = pow((temp7 - (Rc + (shell_detail[(No_of_ShellCourses - 1)][18] / 2))), 2);                             //Y1^2
		temp9 = pow((temp7 - (Rc + shell_detail[(No_of_ShellCourses - 1)][18] + (CR_Ring_thk[j] / 2))), 2);                  //Y2^2
		temp10 = pow(((Rc + shell_detail[(No_of_ShellCourses - 1)][18] + CR_Ring_thk[j] + (temp3 / 2)) - temp7), 2);       // Y3^2


		CompRing_MOI_asbuilt = (((temp31*shell_detail[(No_of_ShellCourses - 1)][18]) * pow(temp8, 2)) + ((CR_Ring_width[j] * CR_Ring_thk[j])* pow(temp9, 2)) + ((temp3 * CR_Ring_thk[j]) * pow(temp10, 2)) +
			(temp31 * pow(shell_detail[(No_of_ShellCourses - 1)][18], 3) / 12) + (CR_Ring_width[j] * pow(CR_Ring_thk[j], 3) / 12) + (CR_Ring_thk[j] * pow(temp3, 3) / 12));


		//MOI_corroded

		temp11 = (temp32*shell_detail[(No_of_ShellCourses - 1)][19]) * (Rc_corr + (shell_detail[(No_of_ShellCourses - 1)][19] / 2)); // A1*D1 (shell)

		temp12 = (CR_Ring_width[j] * CR_Ring_thk[j])* (Rc_corr + shell_detail[(No_of_ShellCourses - 1)][19] + (CR_Ring_thk[j] / 2)); // A2*D2 (flange of angle)

		temp13 = (250 / pow(YS_CR_Ring_angle, 0.5)); // L
		if (temp13 < (CR_Ring_width[j] - CR_Ring_thk[j]))
			temp13 = (CR_Ring_width[j] - CR_Ring_thk[j]);

		temp14 = (temp13 * CR_Ring_thk[j])* (Rc_corr + shell_detail[(No_of_ShellCourses - 1)][19] + CR_Ring_thk[j] + (temp13 / 2)); // A3*D3 (web of angle)

		temp15 = (temp32*shell_detail[(No_of_ShellCourses - 1)][19]) + (CR_Ring_width[j] * CR_Ring_thk[j]) + (temp13 * CR_Ring_thk[j]); // Sigma Area

		temp16 = temp11 + temp12 + temp14; // sigma AD

		temp17 = temp16 / temp15;  // sigma AD / Sigma A;




		temp18 = pow((temp7 - (Rc_corr + (shell_detail[(No_of_ShellCourses - 1)][19] / 2))), 2);                             //Y1^2
		temp19 = pow((temp7 - (Rc_corr + shell_detail[(No_of_ShellCourses - 1)][19] + (CR_Ring_thk[j] / 2))), 2);                  //Y2^2
		temp20 = pow(((Rc_corr + shell_detail[(No_of_ShellCourses - 1)][19] + CR_Ring_thk[j] + (temp3 / 2)) - temp7), 2);       // Y3^2


		CompRing_MOI_asbuilt = (((temp32*shell_detail[(No_of_ShellCourses - 1)][19]) * pow(temp18, 2)) + ((CR_Ring_width[j] * CR_Ring_thk[j])* pow(temp19, 2)) + ((temp13 * CR_Ring_thk[j]) * pow(temp20, 2)) +
			(temp32 * pow(shell_detail[(No_of_ShellCourses - 1)][19], 3) / 12) + (CR_Ring_width[j] * pow(CR_Ring_thk[j], 3) / 12) + (CR_Ring_thk[j] * pow(temp3, 3) / 12));



	}



	/*
	else if (CR_Type_No[1] == 7)

	{

		temp31 = 0.6* (pow((Rc*  (shell_detail[(No_of_ShellCourses - 1)][18] + CR_Ring_thk[j] + CR_Ring_thk[k])), 0.5)); // Asbuilt effective length of shell using combined thickness
		temp32 = 0.6* (pow((Rc*  (shell_detail[(No_of_ShellCourses - 1)][19] + CR_Ring_thk[j] + CR_Ring_thk[k])), 0.5));   // corroded effective length of shell using combined thickness

		if (CR_Ring_width[j] > CR_Ring_width[k]) temp33 = CR_Ring_width[j];
		else
			temp33 = CR_Ring_width[k];


		if (temp31 > temp33) temp31 = temp33;
		if (temp32 > temp33) temp32 = temp33;

		if (temp31 < wc_asbuilt) temp31 = wc_asbuilt;
		if (temp32 < wc_corr) temp32 = wc_corr;



		temp21 = (250 / pow(YS_CR_Ring_angle, 0.5)); // L
		if (temp21 > (CR_Ring_width[j] - CR_Ring_thk[j]))
			temp3 = (CR_Ring_width[j] - CR_Ring_thk[j]); // effective web width of outer angle A/B
		else temp3 = temp34;


		if (temp21 > (CR_Ring_width[k] - CR_Ring_thk[k]))
			temp22 = (CR_Ring_width[k] - CR_Ring_thk[k]); // effective web width of inner angle A/B
		else temp22 = temp21;

		temp23 = (temp3 + CR_Ring_width[j] )* CR_Ring_thk[j]; // participating area of  outer angle A/B



		// corroded area of internal angle

		temp24 = (CR_Ring_thk[k] - 2 * shell_detail[(No_of_ShellCourses - 1)][9]); // corroded thickness of web of internal angle



		if (temp24 > 0)

			temp25 = (temp22 + CR_Ring_width[k])* temp24;  // corroded area of internal angle
		else
			temp25 = CR_Ring_width[k]* temp24;

		CompRing_area_asbuilt = (temp31*shell_detail[(No_of_ShellCourses - 1)][18]) + (wh_asbuilt*Roof_Thk[8]) + (CR_Ring_area[j]) + temp23;

		CompRing_area_corr = (temp32*shell_detail[(No_of_ShellCourses - 1)][19]) + (wh_corr*Roof_Thk[9]) + temp25);

		//calculation of compression ring MOI_corr & MOI_asbuilt

		//MOI_asbuilt

		temp1 = (temp31*shell_detail[(No_of_ShellCourses - 1)][18]) * (Rc + (shell_detail[(No_of_ShellCourses - 1)][18] / 2)); // A1*D1 (shell)

		temp2 = (CR_Ring_width[j] * CR_Ring_thk[j])* (Rc + shell_detail[(No_of_ShellCourses - 1)][18] + (CR_Ring_thk[j] / 2)); // A2*D2 (flange of outside angle)
		temp4 = (temp3 * CR_Ring_thk[j])* (Rc + shell_detail[(No_of_ShellCourses - 1)][18] + CR_Ring_thk[j] + (temp3 / 2)); // A3*D3 (web of angle)

		temp26 = (CR_Ring_width[k] * CR_Ring_thk[j])* (Rc - (CR_Ring_thk[k] / 2)); // A4*D4 (flange of inside angle)
		temp27 =



		temp4 = (temp3 * CR_Ring_thk[j])* (Rc + shell_detail[(No_of_ShellCourses - 1)][18] + CR_Ring_thk[j] + (temp3 / 2)); // A3*D3 (web of angle)

		temp5 = (temp31*shell_detail[(No_of_ShellCourses - 1)][18]) + (CR_Ring_width[j] * CR_Ring_thk[j]) + (temp3 * CR_Ring_thk[j]); // Sigma Area

		temp6 = temp1 + temp2 + temp4; // sigma AD

		temp7 = temp6 / temp5;  // sigma ADS / Sigma A;


		temp8 = pow((temp7 - (Rc + (shell_detail[(No_of_ShellCourses - 1)][18] / 2))), 2);                             //Y1^2
		temp9 = pow((temp7 - (Rc + shell_detail[(No_of_ShellCourses - 1)][18] + (CR_Ring_thk[j] / 2))), 2);                  //Y2^2
		temp10 = pow(((Rc + shell_detail[(No_of_ShellCourses - 1)][18] + CR_Ring_thk[j] + (temp3 / 2)) - temp7), 2);       // Y3^2


		CompRing_MOI_asbuilt = (((temp31*shell_detail[(No_of_ShellCourses - 1)][18]) * pow(temp8, 2)) + ((CR_Ring_width[j] * CR_Ring_thk[j])* pow(temp9, 2)) + ((temp3 * CR_Ring_thk[j]) * pow(temp10, 2)) +
			(temp31 * pow(shell_detail[(No_of_ShellCourses - 1)][18], 3) / 12) + (CR_Ring_width[j] * pow(CR_Ring_thk[j], 3) / 12) + (CR_Ring_thk[j] * pow(temp3, 3) / 12));


		//MOI_corroded

		temp11 = (temp32*shell_detail[(No_of_ShellCourses - 1)][19]) * (Rc_corr + (shell_detail[(No_of_ShellCourses - 1)][19] / 2)); // A1*D1 (shell)

		temp12 = (CR_Ring_width[j] * CR_Ring_thk[j])* (Rc_corr + shell_detail[(No_of_ShellCourses - 1)][19] + (CR_Ring_thk[j] / 2)); // A2*D2 (flange of angle)

		temp13 = (250 / pow(YS_CR_Ring_angle, 0.5)); // L
		if (temp13 < (CR_Ring_width[j] - CR_Ring_thk[j]))
			temp13 = (CR_Ring_width[j] - CR_Ring_thk[j]);

		temp14 = (temp13 * CR_Ring_thk[j])* (Rc_corr + shell_detail[(No_of_ShellCourses - 1)][19] + CR_Ring_thk[j] + (temp13 / 2)); // A3*D3 (web of angle)

		temp15 = (temp32*shell_detail[(No_of_ShellCourses - 1)][19]) + (CR_Ring_width[j] * CR_Ring_thk[j]) + (temp13 * CR_Ring_thk[j]); // Sigma Area

		temp16 = temp11 + temp12 + temp14; // sigma AD

		temp17 = temp16 / temp15;  // sigma AD / Sigma A;




		temp18 = pow((temp7 - (Rc_corr + (shell_detail[(No_of_ShellCourses - 1)][19] / 2))), 2);                             //Y1^2
		temp19 = pow((temp7 - (Rc_corr + shell_detail[(No_of_ShellCourses - 1)][19] + (CR_Ring_thk[j] / 2))), 2);                  //Y2^2
		temp20 = pow(((Rc_corr + shell_detail[(No_of_ShellCourses - 1)][19] + CR_Ring_thk[j] + (temp3 / 2)) - temp7), 2);       // Y3^2


		CompRing_MOI_asbuilt = (((temp32*shell_detail[(No_of_ShellCourses - 1)][19]) * pow(temp18, 2)) + ((CR_Ring_width[j] * CR_Ring_thk[j])* pow(temp19, 2)) + ((temp13 * CR_Ring_thk[j]) * pow(temp20, 2)) +
			(temp32 * pow(shell_detail[(No_of_ShellCourses - 1)][19], 3) / 12) + (CR_Ring_width[j] * pow(CR_Ring_thk[j], 3) / 12) + (CR_Ring_thk[j] * pow(temp3, 3) / 12));



	}

*/


else if (CR_Type_No[1] == 7)

{

	temp1 = 0.6* (pow((Rc*  (shell_detail[(No_of_ShellCourses - 1)][18] + CR_Ring_thk[j] + CR_Ring_thk[k])), 0.5)); // Asbuilt effective length of shell using combined thickness
	temp2 = 0.6* (pow((Rc*  (shell_detail[(No_of_ShellCourses - 1)][19] + CR_Ring_thk[j] + CR_Ring_thk[k])), 0.5));   // corroded effective length of shell using combined thickness

	if (CR_Ring_width[j] >= CR_Ring_width[j]) temp3 = CR_Ring_width[j];
	else
		temp3 = CR_Ring_width[k]; // higher of the flange width of the two angles.


	if (temp1 > temp3) temp1 = temp3;
	if (temp2 > temp3) temp2 = temp3;

	if (temp1 < wc_asbuilt) temp1 = wc_asbuilt;
	if (temp2 < wc_corr) temp2 = wc_corr;



	temp4 = (250 / pow(YS_CR_Ring_angle, 0.5)); // L
	if (temp4 >(CR_Ring_width[j] - CR_Ring_thk[j]))
		temp5 = (CR_Ring_width[j] - CR_Ring_thk[j]); // effective web width of outer angle
	else temp5 = temp4;


	if (temp4 > (CR_Ring_width[k] - CR_Ring_thk[k]))
		temp6 = (CR_Ring_width[k] - CR_Ring_thk[k]); // effective web width of inner angle
	else temp6 = temp4;

	temp7 = (temp5 + CR_Ring_width[j])* CR_Ring_thk[j]; // participating area of  outer angle  (both A/B & corroded)



	// corroded area of internal angle


	temp8 = (temp6 + CR_Ring_width[k]) *CR_Ring_thk[k]; // As built area of inner angle

	temp9 = (CR_Ring_thk[k] - 2 * shell_detail[(No_of_ShellCourses - 1)][9]); // corroded thickness of web of internal angle



	if (temp9 > 0)

		temp10 = (temp6 * temp9) + (CR_Ring_width[k] * CR_Ring_thk[k]);  // corroded area of internal angle
	else
		temp10 = (CR_Ring_width[k] * CR_Ring_thk[k]);

	CompRing_area_asbuilt = (temp31*shell_detail[(No_of_ShellCourses - 1)][18]) + (wh_asbuilt*Roof_Thk[8]) + (CR_Ring_area[j]) + temp23;

	CompRing_area_corr = (temp32*shell_detail[(No_of_ShellCourses - 1)][19]) + (wh_corr*Roof_Thk[9]) + temp25;

	//calculation of compression ring MOI_corr & MOI_asbuilt

	//MOI_asbuilt

	temp1 = (temp31*shell_detail[(No_of_ShellCourses - 1)][18]) * (Rc + (shell_detail[(No_of_ShellCourses - 1)][18] / 2)); // A1*D1 (shell)

	temp2 = (CR_Ring_width[j] * CR_Ring_thk[j])* (Rc + shell_detail[(No_of_ShellCourses - 1)][18] + (CR_Ring_thk[j] / 2)); // A2*D2 (flange of outside angle)
	temp4 = (temp3 * CR_Ring_thk[j])* (Rc + shell_detail[(No_of_ShellCourses - 1)][18] + CR_Ring_thk[j] + (temp3 / 2)); // A3*D3 (web of angle)

	temp26 = (CR_Ring_width[k] * CR_Ring_thk[j])* (Rc - (CR_Ring_thk[k] / 2)); // A4*D4 (flange of inside angle)
	temp27 =



		temp4 = (temp3 * CR_Ring_thk[j])* (Rc + shell_detail[(No_of_ShellCourses - 1)][18] + CR_Ring_thk[j] + (temp3 / 2)); // A3*D3 (web of angle)

	temp5 = (temp31*shell_detail[(No_of_ShellCourses - 1)][18]) + (CR_Ring_width[j] * CR_Ring_thk[j]) + (temp3 * CR_Ring_thk[j]); // Sigma Area

	temp6 = temp1 + temp2 + temp4; // sigma AD

	temp7 = temp6 / temp5;  // sigma ADS / Sigma A;


	temp8 = pow((temp7 - (Rc + (shell_detail[(No_of_ShellCourses - 1)][18] / 2))), 2);                             //Y1^2
	temp9 = pow((temp7 - (Rc + shell_detail[(No_of_ShellCourses - 1)][18] + (CR_Ring_thk[j] / 2))), 2);                  //Y2^2
	temp10 = pow(((Rc + shell_detail[(No_of_ShellCourses - 1)][18] + CR_Ring_thk[j] + (temp3 / 2)) - temp7), 2);       // Y3^2


	CompRing_MOI_asbuilt = (((temp31*shell_detail[(No_of_ShellCourses - 1)][18]) * pow(temp8, 2)) + ((CR_Ring_width[j] * CR_Ring_thk[j])* pow(temp9, 2)) + ((temp3 * CR_Ring_thk[j]) * pow(temp10, 2)) +
		(temp31 * pow(shell_detail[(No_of_ShellCourses - 1)][18], 3) / 12) + (CR_Ring_width[j] * pow(CR_Ring_thk[j], 3) / 12) + (CR_Ring_thk[j] * pow(temp3, 3) / 12));


	//MOI_corroded

	temp11 = (temp32*shell_detail[(No_of_ShellCourses - 1)][19]) * (Rc_corr + (shell_detail[(No_of_ShellCourses - 1)][19] / 2)); // A1*D1 (shell)

	temp12 = (CR_Ring_width[j] * CR_Ring_thk[j])* (Rc_corr + shell_detail[(No_of_ShellCourses - 1)][19] + (CR_Ring_thk[j] / 2)); // A2*D2 (flange of angle)

	temp13 = (250 / pow(YS_CR_Ring_angle, 0.5)); // L
	if (temp13 < (CR_Ring_width[j] - CR_Ring_thk[j]))
		temp13 = (CR_Ring_width[j] - CR_Ring_thk[j]);

	temp14 = (temp13 * CR_Ring_thk[j])* (Rc_corr + shell_detail[(No_of_ShellCourses - 1)][19] + CR_Ring_thk[j] + (temp13 / 2)); // A3*D3 (web of angle)

	temp15 = (temp32*shell_detail[(No_of_ShellCourses - 1)][19]) + (CR_Ring_width[j] * CR_Ring_thk[j]) + (temp13 * CR_Ring_thk[j]); // Sigma Area

	temp16 = temp11 + temp12 + temp14; // sigma AD

	temp17 = temp16 / temp15;  // sigma AD / Sigma A;




	temp18 = pow((temp7 - (Rc_corr + (shell_detail[(No_of_ShellCourses - 1)][19] / 2))), 2);                             //Y1^2
	temp19 = pow((temp7 - (Rc_corr + shell_detail[(No_of_ShellCourses - 1)][19] + (CR_Ring_thk[j] / 2))), 2);                  //Y2^2
	temp20 = pow(((Rc_corr + shell_detail[(No_of_ShellCourses - 1)][19] + CR_Ring_thk[j] + (temp3 / 2)) - temp7), 2);       // Y3^2


	CompRing_MOI_asbuilt = (((temp32*shell_detail[(No_of_ShellCourses - 1)][19]) * pow(temp18, 2)) + ((CR_Ring_width[j] * CR_Ring_thk[j])* pow(temp19, 2)) + ((temp13 * CR_Ring_thk[j]) * pow(temp20, 2)) +
		(temp32 * pow(shell_detail[(No_of_ShellCourses - 1)][19], 3) / 12) + (CR_Ring_width[j] * pow(CR_Ring_thk[j], 3) / 12) + (CR_Ring_thk[j] * pow(temp3, 3) / 12));



}

}


void shell_Stiffener_Properties()
{
	// beginning of function for Calculation of Required & available properties of stiffeners


	int i, k, l, m, n;
	double Ls_Tr, t, temp1;


	double w_shell_top, w_shell_bot;

	for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
	{
		stfr_detail[i][21] = stfr_detail[i][16]; // variable [21] is defined equal to [16] for future refining the final elevation [16] without disturbing the existing listings
		stfr_detail[i][22] = stfr_detail[i][17]; // variable [22] is defined equalto [17] for future refining the final spacing [17] without disturbing the existing listings
		stfr_detail[i][23] = (pow(D, 2) * stfr_detail[i][22] * pow((V / 190), 2) / 17); // section modulus required for stiffener
	}


	if (Pe > 0.2500001)
	{


		// beginning of Calculation of Ls for each stiffener & heighest of the heights of tranposed shell (Ls_Tr) :

		if ((No_of_Stiffeners_R - 1) == 1)
			Ls_Tr = (stfr_detail[0][15] + stfr_detail[(0)][14]) / 2;
		else
		{
			Ls_Tr = (stfr_detail[0][15] + stfr_detail[1][15]) / 2;

			for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
			{
				if (i != (No_of_Stiffeners_R - 1))

				{
					stfr_detail[i][24] = (stfr_detail[i][17] + stfr_detail[(i + 1)][17]) / 2;
					temp1 = (stfr_detail[i][15] + stfr_detail[(i + 1)][15]) / 2;
					if (temp1 > Ls_Tr)
						Ls_Tr = temp1;

				}
				else
				{

					stfr_detail[i][24] = (stfr_detail[i][17] + stfr_detail[i][16]) / 2;
					temp1 = (stfr_detail[i][15] + stfr_detail[(i)][14]) / 2;
					if (temp1 > Ls_Tr)
						Ls_Tr = temp1;


				}

			}  // end of 'for loop' for Calculation of Ls for each stiffener & heighest of the heights of tranposed shell (Ls_Tr)

		}  // end of else statement for number of stiffener more than 1;

		N_Sqr = pow((445 * pow(D, 3) / (t_uniform * pow(Ls_Tr, 2))), 0.5);

		if (N_Sqr < 4)
			N_Sqr = 4;

		else

			N_Sqr = pow((roundup((pow(N_Sqr, 0.5)), 0)), 2);  // rounding up to next higher perfect squire

		if (N_Sqr > 100)
			N_Sqr = 100;



		for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
		{


			stfr_detail[i][28] = 1000 * Ps * stfr_detail[i][24]; // Q
			stfr_detail[i][29] = 37.5 * stfr_detail[i][28] * pow(D, 3) / (Y_Mod * (N_Sqr - 1)); // Required MOI
			stfr_detail[i][30] = stfr_detail[i][28] * D / (2 * stfr_detail[i][27] * 100);    // Required Area (total)
			stfr_detail[i][34] = stfr_detail[i][30] / 2;

		} // end of for statement for calculating the required properties of stiffener ring

	}   // end of 'if' statement for appendix V calculation

	else

		stfr_detail[i][29] = stfr_detail[i][30] = stfr_detail[i][34] = 0;  // if appendix v is not applicable



	for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
	{


		//			calculating the participating width of shell above the stiffener;

		l = (stfr_location[i][2] - 1); // serial number of shell on which stiffener is located

		if (option_Stfr == 0)
			t = shell_detail[l][18] / 10;		// t is the thickness of shell in cm on which stiffener is located

		else
			t = shell_detail[l][19] / 10;

		w_shell_bot = w_shell_top = 13.4 * (pow((D*t * 10), 0.5)) / 10;

		if (w_shell_top > (stfr_detail[i][17] * 100 / 2))
			w_shell_top = (stfr_detail[i][17] * 100 / 2);

		if (w_shell_top > (stfr_detail[i][19] * 100))
			w_shell_top = (stfr_detail[i][19] * 100);      // participating width if any, above the shell joint is ignored.

		if (i != (No_of_Stiffeners - 1))		// if the stiffener is not the lowest one
		{
			if (w_shell_bot > (stfr_detail[(i + 1)][17] * 100 / 2))  // half the spacing on actual shell above the lower stiffener
				w_shell_bot = (stfr_detail[(i + 1)][17] * 100 / 2);
		}

		else
		{
			if (w_shell_bot > (stfr_detail[i][16] * 100 / 2))		// half the elevation of the stiffener.
				w_shell_bot = (stfr_detail[i][16] * 100 / 2);
		}

		stfr_detail[i][31] = t;
		stfr_detail[i][32] = (w_shell_top + w_shell_bot);
		stfr_detail[i][33] = stfr_detail[i][31] * stfr_detail[i][32]; //  area of shell Sq. CM.


		stfr_detail[i][35] = 0;		// default type of ring is angle.

		// checking each of the angle from data bank for suitability

		m = 0; // changes to 1 when all required conditions for the stiffener ring are fulfilled
		n = 73; // serial number of the angle selected as the stiffener ring
		k = 72;


		if (stfr_detail[i][35] < 0.1)
		{

			while (m < 1)
			{




				Section_Modulus_Angle(i, k);

				if (Pe <= 0.2500001)
				{

					if (stfr_detail[i][23]  < stfr_Sec_Mod)
						m = 1;


				}

				else
				{

					if ((stfr_detail[i][30]  < (stfr_detail[i][33] + ring_area)) && ((stfr_detail[i][30] / 2) < ring_area) &&
						(stfr_detail[i][29]  < stfr_MOI) && (stfr_detail[i][23]  < stfr_Sec_Mod))
						m = 1;

				}

				if (m != 1)
					k--;

				else
				{

					stfr_detail[i][36] = ring_CG;	//= stfnr_section_CG[k];
					stfr_detail[i][37] = ring_MOI;	//= stfnr_section_MOI[k];
					stfr_detail[i][39] = ring_area; //	= stfnr_section_area[k];
					stfr_detail[i][45] = stfr_area; //	= (stfr_detail[i][33] + stfnr_section_area[k]);
					stfr_detail[i][46] = stfr_MOI; //	=	temp12;
					stfr_detail[i][47] = stfr_Sec_Mod; //	= temp15;
					Stfnr_Section[i][0] = ring_Name; //		= stfnr_section_Name[k];
					stfr_Sec_No[i][0] = (k + 1);

				}

				if (k == 0)
				{
					m = 1;
					stfr_detail[i][35] = 1;

				}







			} // end of while loop



		} // end of if logic for the type of ring (angle / built-up) used



		if (stfr_detail[i][35] > 0.5)

		{
			// Start of stiffener sizing of Built-up section

			m = 0;



			double temp19, temp20, temp21, temp22;

			temp19 = 20;  // web width
			temp20 = 0.6; // web thickness
			temp21 = 15;  // Flange width
			temp22 = 0.6; // Flange thickness

			while (m < 1)
			{


				Section_Modulus_Builtup(i, temp19, temp20, temp21, temp22);


				if (Pe <= 0.2500001)
				{

					if (stfr_detail[i][23]  < stfr_Sec_Mod)
						m = 1;


				}

				else
				{

					if ((stfr_detail[i][30]  < (stfr_detail[i][33] + ring_area)) && ((stfr_detail[i][30] / 2) < ring_area) &&
						(stfr_detail[i][29]  < stfr_MOI) && (stfr_detail[i][23]  < stfr_Sec_Mod))
						m = 1;

				}


				if (m != 1)

					temp19 = temp19 + 5.0;

				else
				{
					stfr_detail[i][39] = ring_area;  // Area of ring
					stfr_detail[i][40] = web_width * 10;  // web width
					stfr_detail[i][41] = web_thk * 10; // web thickness
					stfr_detail[i][42] = flng_width * 10;  // Flange width
					stfr_detail[i][43] = flng_thk * 10; // Flange thickness
					stfr_detail[i][45] = stfr_area;					// Total area (ring + shell)
					stfr_detail[i][46] = stfr_MOI;
					stfr_detail[i][47] = stfr_Sec_Mod;

					Stfnr_Section[i][0] = ring_Name;


				}

				//cout << endl << "Value of m for stiffener Number" << (i+1) << " =  " << m;



			} // end of while loop



		}  // end of stiffener sizing of Built-up section



		// start of check for user defined ring:

		if (stfr_detail[i][35] < 0.5)
			Type_Stfr[i][0] = "Angle";
		else
			Type_Stfr[i][0] = "Built-up Section";

		stfr_detail[i][65] = stfr_detail[i][35];

		if (stfr_detail[i][50] < 0.5)  // if type of stfr is angle
		{

			stfr_detail[i][66] = stfr_detail[i][36];
			stfr_detail[i][67] = stfr_detail[i][37];
			stfr_detail[i][69] = stfr_detail[i][39];
			stfr_detail[i][75] = stfr_detail[i][45];
			stfr_detail[i][76] = stfr_detail[i][46];
			stfr_detail[i][77] = stfr_detail[i][47];
			Stfnr_Section[i][2] = Stfnr_Section[i][0];
			stfr_Sec_No[i][2] = stfr_Sec_No[i][0];

			if (((Pe <= 0.2500001) && (stfr_detail[i][23]  < stfr_detail[i][62])) || ((Pe > 0.2500001) && ((stfr_detail[i][30]  < (stfr_detail[i][33] + stfr_detail[i][54])) && ((stfr_detail[i][30] / 2) < stfr_detail[i][54]) &&
				(stfr_detail[i][29]  < stfr_detail[i][61]) && (stfr_detail[i][23]  < stfr_detail[i][62]))))

			{
				stfr_detail[i][65] = stfr_detail[i][50];
				stfr_detail[i][66] = stfr_detail[i][51];
				stfr_detail[i][67] = stfr_detail[i][52];
				stfr_detail[i][69] = stfr_detail[i][54];
				stfr_detail[i][75] = stfr_detail[i][60];
				stfr_detail[i][76] = stfr_detail[i][61];
				stfr_detail[i][77] = stfr_detail[i][62];
				Stfnr_Section[i][2] = Stfnr_Section[i][1];
				stfr_Sec_No[i][2] = stfr_Sec_No[i][1];

			}




		} // end of if statement for angle type stiffener
		else if (stfr_detail[i][50] > 0.5)  // if type of stfr is "built-up".
		{

			// primary assignment of  properties of adopted section same as default section.

			stfr_detail[i][69] = stfr_detail[i][39];  // Area of ring
			stfr_detail[i][70] = stfr_detail[i][40];  // web width
			stfr_detail[i][71] = stfr_detail[i][41]; // web thickness
			stfr_detail[i][72] = stfr_detail[i][42];  // Flange width
			stfr_detail[i][73] = stfr_detail[i][43]; // Flange thickness
			stfr_detail[i][75] = stfr_detail[i][39];	// Total area (ring + shell)
			stfr_detail[i][76] = stfr_detail[i][46];
			stfr_detail[i][77] = stfr_detail[i][47];
			Stfnr_Section[i][2] = Stfnr_Section[i][0];


			if (((Pe <= 0.250001) && (stfr_detail[i][23]  < stfr_detail[i][62])) || ((Pe > 0.2500001) && ((stfr_detail[i][30]  < (stfr_detail[i][33] + stfr_detail[i][54])) && ((stfr_detail[i][30] / 2) < stfr_detail[i][54]) &&
				(stfr_detail[i][29]  < stfr_detail[i][61]) && (stfr_detail[i][23]  < stfr_detail[i][62]))))

			{
				stfr_detail[i][65] = stfr_detail[i][50];
				stfr_detail[i][69] = stfr_detail[i][54];  // Area of ring
				stfr_detail[i][70] = stfr_detail[i][55];  // web width
				stfr_detail[i][71] = stfr_detail[i][56]; // web thickness
				stfr_detail[i][72] = stfr_detail[i][57];  // Flange width
				stfr_detail[i][73] = stfr_detail[i][58]; // Flange thickness
				stfr_detail[i][75] = stfr_detail[i][60];	// Total area (ring + shell)
				stfr_detail[i][76] = stfr_detail[i][61];
				stfr_detail[i][77] = stfr_detail[i][62];
				Stfnr_Section[i][2] = Stfnr_Section[i][1];


			}



		} // end of if statement for built-up type stfr.




	} // end of for loop



} //	end of function shell_Stiffener_Properties()


void Stiffener_Prop_User()
{
	int i, k;
	double temp1, temp2, temp3, temp4;

	for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
	{
		// start of check for user defined ring:



		stfr_detail[i][50] = stfr_detail_user[i][1];  // this line is for use when "Edit an existing input file" option is used

		if (stfr_detail[i][50] < 0.5)
			Type_Stfr[i][1] = "Angle";
		else
			Type_Stfr[i][1] = "Built-up Section";

		if (stfr_detail[i][50] < 0.5)  // if type of stfr is angle ; copying the default value to adopted.
		{

			stfr_detail[i][66] = stfr_detail[i][36];
			stfr_detail[i][67] = stfr_detail[i][37];
			stfr_detail[i][69] = stfr_detail[i][39];
			stfr_detail[i][75] = stfr_detail[i][45];
			stfr_detail[i][76] = stfr_detail[i][46];
			stfr_detail[i][77] = stfr_detail[i][47];
			Stfnr_Section[i][2] = Stfnr_Section[i][0];



			if (stfr_Sec_No[i][1] == 0)
				stfr_Sec_No[i][1] = stfr_Sec_No[i][0];

			k = stfr_Sec_No[i][1] - 1;

			Section_Modulus_Angle(i, k);

			stfr_detail[i][51] = ring_CG;	//= stfnr_section_CG[k];
			stfr_detail[i][52] = ring_MOI;	//= stfnr_section_MOI[k];
			stfr_detail[i][54] = ring_area; //	= stfnr_section_area[k];
			stfr_detail[i][60] = stfr_area; //	= (stfr_detail[i][33] + stfnr_section_area[k]);
			stfr_detail[i][61] = stfr_MOI; //	=	temp12;
			stfr_detail[i][62] = stfr_Sec_Mod; //	= temp15;
			Stfnr_Section[i][1] = ring_Name; //		= stfnr_section_Name[k];

		} // end of if (stfr_detail[i][50] < 0.5)  for type of stfr is angle
		else if (stfr_detail[i][50] > 0.5)  // if type of stfr is "built-up".
		{
			/*
			cout << endl << "Size of section selected  for stiffener Number:	" << (i+1) <<"	" << Stfnr_Section[i][0];
			cout << endl << "Enter details of revised section :	";
			cout << endl << "Enter details of revised section :	";
			cout << endl << "Enter Width of web   :	";
			cin >> stfr_Prop_user[i][0];
			cout << endl << "Enter Thickness of web   :	";
			cin >> stfr_Prop_user[i][1];
			cout << endl << "Enter Height of of flange   :	";
			cin >> stfr_Prop_user[i][2];
			cout << endl << "Enter thickness of of flange   :	";
			cin >> stfr_Prop_user[i][3];

			*/

			temp1 = stfr_Prop_user[i][0] / 10;
			temp2 = stfr_Prop_user[i][1] / 10;
			temp3 = stfr_Prop_user[i][2] / 10;
			temp4 = stfr_Prop_user[i][3] / 10;

			Section_Modulus_Builtup(i, temp1, temp2, temp3, temp4);


			stfr_detail[i][54] = ring_area;  // Area of ring
			stfr_detail[i][55] = web_width * 10;  // web width
			stfr_detail[i][56] = web_thk * 10; // web thickness
			stfr_detail[i][57] = flng_width * 10;  // Flange width
			stfr_detail[i][58] = flng_thk * 10; // Flange thickness
			stfr_detail[i][60] = stfr_area;					// Total area (ring + shell)
			stfr_detail[i][61] = stfr_MOI;
			stfr_detail[i][62] = stfr_Sec_Mod;
			Stfnr_Section[i][1] = ring_Name;

		} // end of if loop for built-up section

		shell_Stiffener_Properties();

		if (stfr_detail[i][65] < 0.5)
			Type_Stfr[i][2] = "Angle";
		else
			Type_Stfr[i][2] = "Built-up Section";
	} // end of for loop
}// end of function Stiffener_Prop_User()


void Section_Modulus_Angle(int i, int k)
{
	// beginning of function Section_Modulus_Angle(int, int);
	double temp3, temp4, temp5, temp6, temp7, temp8, temp9,
		temp10, temp11, temp12, temp13, temp14, temp15;

	string stfnr_section_Name[] = { "L200x200x24", "L200x200x20", "L200x200x18", "L180x180x18", "L200x200x16",
		"L200x150x18", "L180x180x16", "L150x150x18", "L200x150x15", "L160x160x15",
		"L150x150x15", "L200x100x15", "L200x150x12", "L200x100x12", "L150x150x12",
		"L150x90x15 ", "L120x120x15", "L150x75x15 ", "L130x130x12", "L150x150x10",
		"L200x100x10", "L150x100x12", "L120x120x12", "L150x100x10", "L100x100x15",
		"L150x90x12 ", "L150x75x12 ", "L150x90x10 ", "L120x120x10", "L150x75x10 ",
		"L100x75x12 ", "L150x75x9  ", "L125x75x10 ", "L135x65x10 ", "L120x120x8 ",
		"L90x90x10  ", "L135x65x8  ", "L100x100x8 ", "L90x90x9   ", "L125x75x12 ",
		"L100x100x12", "L90x90x12  ", "L100x100x10", "L100x65x10 ", "L125x75x8  ",
		"L120x80x12 ", "L120x80x10 ", "L100x75x10 ", "L120x80x8  ", "L90x90x8   ",
		"L100x75x8  ", "L80x80x10  ", "L70x70x10  ", "L100x65x8  ", "L80x80x8   ",
		"L90x90x7   ", "L100x50x8  ", "L75x75x8   ", "L100x65x7  ", "L100x50x6  ",
		"L80x60x8   ", "L90x90x6   ", "L70x70x8   ", "L75x50x8   ", "L70x70x7   ",
		"L80x60x7   ", "L80x80x6   ", "L80x40x8   ", "L75x75x6   ", "L70x70x6   ",
		"L80x60x6   ", "L65x65x7   ", "L65x65x6   " };

	double stfnr_section_area[] = { 90.6, 76.3, 69.1, 61.9, 61.8, 60, 55.4, 51, 50.5, 46.1,
		43, 43, 40.8, 34.8, 34.8, 33.9, 33.9, 31.6, 30, 29.3,
		29.2, 28.7, 27.5, 24.2, 27.9, 27.5, 25.7, 23.2, 23.2, 21.6,
		19.7, 19.6, 19.1, 19.1, 18.7, 17.1, 15.5, 15.5, 15.5, 22.7,
		22.7, 20.3, 19.2, 15.6, 15.5, 22.7, 19.1, 16.6, 15.5, 13.9,
		13.5, 15.1, 13.1, 12.7, 12.3, 12.2, 11.4, 11.4, 11.2, 8.71,
		10.6, 10.6, 10.6, 9.41, 9.4, 9.38, 9.35, 9.01, 8.73, 8.13,
		8.11, 8.7, 7.53 };






	double stfnr_section_CG[] = { 14.16, 14.32, 14.4, 12.9, 14.48, 13.67, 12.98, 10.63, 13.79, 11.51,
		10.75, 12.84, 13.92, 12.97, 10.88, 9.79, 8.49, 9.47, 9.36, 10.97,
		13.07, 10.1, 8.6, 10.19, 6.98, 9.92, 9.59, 10.0, 8.69, 9.68,
		6.73, 9.74, 8.27, 8.62, 8.77, 6.42, 8.72, 7.26, 6.46, 8.19,
		7.1, 6.34, 7.18, 6.64, 8.36, 8.0, 8.08, 6.81, 8.17, 6.5,
		6.9, 5.66, 4.91, 6.73, 5.74, 6.55, 6.4, 5.36, 6.77, 6.49,
		5.45, 6.59, 4.99, 4.98, 5.03, 5.49, 5.83, 5.06, 5.45, 5.07,
		5.53, 4.65, 4.69 };

	double stfnr_section_MOI[] = { 3331, 2851, 2600, 1866, 2341, 2376, 1682, 1050, 2022, 1099,
		898, 1758, 1652, 1440, 737, 761, 445, 713, 472, 624,
		1219, 651, 368, 553, 249, 627, 589, 533, 313, 501,
		189, 455, 302, 356, 255, 127, 291, 145, 116, 354,
		207, 148, 177, 154, 247, 323, 276, 162, 226, 104,
		133, 87.5, 57.2, 127, 72.2, 92.5, 89.9, 59.1, 113, 89.9,
		66.3, 80.3, 47.5, 52, 42.3, 59, 55.8, 57.6, 45.8, 36.9,
		51.4, 33.4, 29.2 };

	double stfnr_section_width[] = { 200, 200, 200, 180, 200, 200, 180, 150, 200, 160,
		150, 200, 200, 200, 150, 150, 120, 150, 130, 150,
		200, 150, 120, 150, 100, 150, 150, 150, 120, 150,
		100, 150, 125, 135, 120, 90, 135, 100, 90, 125,
		100, 90, 100, 100, 125, 120, 120, 100, 120, 90,
		100, 80, 70, 100, 80, 90, 756, 75, 100, 100,
		80, 90, 70, 75, 70, 80, 80, 80, 75, 70,
		80, 65, 65 };








	temp3 = stfr_detail[i][33] * (stfr_detail[i][31] / 2);  // a1*d1
	temp4 = stfnr_section_area[k] * ((stfnr_section_CG[k]) + stfr_detail[i][31]);  // a2*d2
	temp5 = temp3 + temp4;  // *Sum a*d
	temp6 = temp5 / (stfr_detail[i][33] + stfnr_section_area[k]); // * x': distance to combined CG from inner surface of shell.
	temp7 = temp6 - (stfr_detail[i][31] / 2); // x1: distance of mid thickness from combined CG
	temp8 = ((stfnr_section_CG[k]) + stfr_detail[i][31]) - temp6; // x2; distance of CG of angle from combined CG
	temp9 = stfr_detail[i][33] * pow(temp7, 2); // a1*x1^2
	temp10 = stfnr_section_area[k] * pow(temp8, 2); // a2*x2^2
	temp11 = stfr_detail[i][32] * pow(stfr_detail[i][31], 3) / 12;  // MOI of shell on its own CG
	temp12 = temp9 + temp10 + temp11 + stfnr_section_MOI[k];			// Total MOI of composite section
	temp13 = (stfnr_section_width[k] / 10) + stfr_detail[i][31] - temp6; // distance from combined CG to outer most fibre.
	temp14 = max(temp6, temp13, temp13, temp13, temp13, temp13, 2);	//
	temp15 = temp12 / temp14; // section modulus


	ring_CG = stfnr_section_CG[k];
	ring_MOI = stfnr_section_MOI[k];
	ring_area = stfnr_section_area[k];
	stfr_area = (stfr_detail[i][33] + stfnr_section_area[k]);
	stfr_MOI = temp12;
	stfr_Sec_Mod = temp15;
	ring_Name = stfnr_section_Name[k];

	/*
	if (k < 20)
	{
	cout << endl << "Stiffener size =	" << stfnr_section_Name[k] << endl << endl;
	cout << endl << "temp4 =	" << fixed << setprecision(2) << temp4 << endl << endl;
	cout << endl << "temp5 =	" << fixed << setprecision(2) << temp5 << endl << endl;
	cout << endl << "temp6 =	" << fixed << setprecision(2) << temp6 << endl << endl;
	cout << endl << "temp7 =	" << fixed << setprecision(2) << temp7 << endl << endl;
	cout << endl << "temp8 =	" << fixed << setprecision(2) << temp8 << endl << endl;

	cout << endl << "temp9 =	" << fixed << setprecision(2) << temp9 << endl << endl;
	cout << endl << "temp10 =	" << fixed << setprecision(2) << temp10 << endl << endl;
	cout << endl << "temp11 =	" << fixed << setprecision(2) << temp11 << endl << endl;
	cout << endl << "MOI section =	" << fixed << setprecision(2) << stfnr_section_MOI[k] << endl << endl;
	cout << endl << "Enter zero to proceed ";
	cin >> x;
	}
	*/
}  // end of function Section_Modulus_Angle(int, int);


void Section_Modulus_Builtup(int i, double temp19, double temp20, double temp21, double temp22)
{
	// start function Section_Modulus_Builtup()

	double temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9,
		temp10, temp11, temp12, temp13, temp14, temp15, temp16, temp17, temp18;

	temp1 = stfr_detail[i][33] * (stfr_detail[i][31] / 2);  // a1*d1
	temp2 = (temp19  * temp20) * ((temp19 / 2) + stfr_detail[i][31]);  // a2*d2
	temp3 = (temp21  * temp22) * (stfr_detail[i][31] + temp19 + (temp20 / 2));  // a3*d3

	temp4 = temp1 + temp2 + temp3;  // *Sum a*d
	temp5 = temp4 / ((temp19 * temp20) + (temp21  * temp22) + stfr_detail[i][33]); // * x': distance to combined CG from inner surface of shell.

	temp6 = temp5 - (stfr_detail[i][31] / 2); // x1: distance of mid thickness from combined CG
	temp7 = ((temp19 / 2) + stfr_detail[i][31]) - temp5; // x2; distance of CG of angle from combined CG
	temp8 = (stfr_detail[i][31] + temp19 + (temp20 / 2)) - temp5;  // x3; distance of CG of flange from combined CG

	temp9 = stfr_detail[i][33] * pow(temp6, 2); // a1*x1^2
	temp10 = ((temp19  * temp20)) * pow(temp7, 2); // a2*x2^2
	temp11 = ((temp21  * temp22)) * pow(temp8, 2); // a3*x3^2

	temp12 = stfr_detail[i][32] * pow(stfr_detail[i][31], 3) / 12;  // MOI of shell on its own CG
	temp13 = pow(temp19, 3) * temp20 / 12;
	temp14 = pow(temp22, 3) * temp21 / 12;

	temp15 = temp9 + temp10 + temp11 + temp12 + temp13 + temp14;			// Total MOI of composite section
	temp16 = stfr_detail[i][31] + temp19 + temp22 - temp5; // distance from combined CG to outer most fibre.
	temp17 = max(temp5, temp16, temp16, temp16, temp16, temp16, 2);	//
	temp18 = temp15 / temp17;

	ring_area = ((temp19 * temp20) + (temp21  * temp22));  // Area of ring
	web_width = temp19;  // web width
	web_thk = temp20; // web thickness
	flng_width = temp21;  // Flange width
	flng_thk = temp22; // Flange thickness
	stfr_area = ((temp19 * temp20) + (temp21  * temp22) + stfr_detail[i][33]);					// Total area (ring + shell)
	stfr_MOI = temp15;
	stfr_Sec_Mod = temp18;
	std::ostringstream s;
	s << "T" << (temp19 * 10) << "x" << (temp20 * 10) << "x" << (temp21 * 10) << "x" << (temp22 * 10);
	ring_Name = s.str();
} // end function Section_Modulus_Builtup()
