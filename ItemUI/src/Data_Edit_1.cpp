// April_18_Edit.cpp : main project file.

// Made from Tank_2018 to remove all hard writing of Input Data.

#include <iostream>
#include <iomanip> // for set precission
#include <math.h>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include "../include/ItemHeaders.h"
#include "../include/Tank.h"
using namespace std;

#include <string>
using namespace std;
// data from user

double D_User, H, H_td_user, H_tt_user, H_Norm_user, H_Seis_user, G, Gw, T, MDMT, P, Po_user,
Pe, Fp, Fpe, CA_Bot, CA_Roof, JE_user, CA_FR, Wt_Roof_Str_user,
kz_user, kzt_user, kd_user, basic_v_user, imp_factorW_user, gust_factor_user, V_user,
S0_user, Ss_user, S1_user, Fa_user, Fv_user, Factor_Q, TL_user, K_user,
shell_detail_user[15][5],
stfr_detail_user[45][2],
Spacing_Top_WG_User, PWG_width_min_user,
R_Roof_user, live_load_user, snow_load_bal, snow_load_unbal, roof_slope_user, dome_radius_user, JE_roof_user, Roof_Thk_user;

int D_Type, Option_P, Shell_Appendx_No_user, Roof_Type_No_user, FR_Type_No, Shell_Des_Method_No, RoundUP_to, option_Stfr,
wind_design_code, wind_exp_cat, Seismic_design_code, Zone_Number, site_class, ASCE_rule, SUG, option_Av, Shell_Material_No[15][3],
Option_walkway, curb_angle_No_user, Option_PWG, stfr_Mat_No[45], stfr_Sec_No[45][2], No_of_Stiffeners_Max_user, option_frangible_roof, Roof_Material_No, option_annularPlate;


string File_name;



// other variables used

double	D_Previous, D, Min_Nom_Thk, Min_Nom_Thk_1, t_uniform, tu_min_W, tu_min_Pe, tu_min, H_Max_W, H_Max_Ps, H_Max, Fy_Shell, H_Top, Spacing_Min, N_Sqr,
Spacing_Top_WG_Tr, kz, kzt, kd, basic_v, imp_factorW, gust_factor, wind_pressure, V, live_load, roof_slope, dome_radius,
roof_thk_user, roof_thk, JE_roof, R_Roof, Roof_Material_YS, Roof_Material_SA, Roof_Material_Y_mod, Roof_Material_Y_mod_Atm, Wt_FR, Wt_Roof_Str_defaut,
Wt_Roof_Str, Roof_thk_reqd, weight_Roof_Plate, weight_Roof_Plate_cor, theeta, Roof_Thk[10], Rafter_spacing, Rafter_spacing_cent,
dead_load, dead_load_cor, ext_load, ext_load_bal, ext_load_unbal, total_load_bal, total_load_unbal, H_td_default, H_td, H_tt_default, H_tt, H_Norm_default,
H_Norm, H_Seis_default, H_Seis, JE, Po_default, Po, S0, Ss, S1, imp_factorS, Fa_default, Fa, Fv_default, Fv, TL, K, Sds, Sd1, Av, Spacing_Top_WG, PWG_width_min,
PWG_width, YS, YS_Atm, UTS, Sd, Sd_Atm, St, Group_No, Psi, W, Ps, H_Ts, H_Avg, H_High, H_Low, New_Spacing, Y_Mod, Y_Mod_Atm, Y_mod, Y_mod_Atm,
Factor_M, Factor_M1, ring_area, ring_CG, ring_MOI, stfr_area, stfr_MOI, stfr_Sec_Mod, web_width, web_thk, flng_width, flng_thk,
Weight_FR, weight[20], density_steel, cg_shell, Thk_AnnPlate[4];

string Roof_Type, Roof_Type_user, FR_Type, Shell_Appendx, Shell_Appendx_user, Shell_Des_Method, MOC;

int  Shell_Appendx_No, Roof_Type_No, No_of_ShellCourses, Apndx_C_MOC, Print_x, Option_walkwayG, No_of_Stiffeners, No_of_Stiffeners_R,
No_of_Stiffeners_P, No_of_Stiffeners_Max, stfr_location[45][5], AnnPlate_req[3], edit_option = 1;

double shell_detail[15][30], Y_Mod_X[15][3], user_EL_detail[45][11], stfr_Prop_user[45][4], stfr_detail[45][80], PWG_details[20], comp_ring_detail[10];

double PI = 3.14159;


string Roof_Material_Name, Shell_Material_Name[15][2], Stfnr_Material_Name[45], Stfnr_Section[45][3], Type_Stfr[45][3], Curb_angle_default, Curb_angle_user, ring_Name;
string Shell_appendx[] = { " Design Procedure", "Appendix - A", "Appendix - J", "Appendix - S", "Appendix - SC", "Appendix - X", "Appendix - AL", "None" };
string Curb_angle;

// global variables of function CompRing_Data() & CompRing_Design()


double  CR_Material_YS[7], CR_Material_Y_mod[7], CR_Material_SA[7], CR_Area_rqd_SRR, CR_Area_rqd_P, CR_Area_rqd_V, CR_MOI_rqd, CR_fc;

int apndx_F, CR_Type_No[3], CR_Material_No[7], CR_Size;
string CompRing_Type[3], CompRing_size[3], CR_Material_Name[7];

double Rc_AB, Rc_COR, t_shell_AB, t_shell_COR, Wc_COR, Wc_AB, Wh_COR, Wh_AB, t_roof_AB, t_roof_COR, R2_COR, R2_AB;

double v_Leg_ht_AB, v_Leg_ht_COR, h_Leg_w_AB, h_Leg_w_COR, v_Leg_thk_AB, v_Leg_thk_COR, h_Leg_thk_AB, h_Leg_thk_COR, CR_Area_Available_AB, CR_Area_Available_COR;

string tempFileName = "tempfiledatabin.bin";

void Input_Screen_1();
void Material_Selection(int, double);

void Wind_Data(); // done
void Seismic_Data(); // done
void shell_Details(); // a lot of work
void PWG_Data(); // easy
void shell_Stfr_User_EL_Data(); // done
void Stiffener_Prop_User_Data(); // easy
void Roof_Data(); // will take around 2 hours
void CompRing_Data(); // easy

void Calculate_Fa_FV(); // from design
void shell_Design(); // from design
void shell_Design_VDP_td(int); // not called anywhere
void shell_Design_VDP_tt(int); // not called anywhere
void PWG_Properties(); // not called anywhere
void shell_Stiffener_Location(); // from design
void H_Ts_Calculation(); // not called anywhere
void shell_Stfr_Min_EL(); // not called anywhere
void shell_Stfr_Avg_EL(); // not called anywhere
void shell_Stfr_User_EL(); // from design
void Roof_Design(); // from design
void weight_cal(); // not called anywhere
void CompRing_Design(); // // from design
void CR_Angle_Properties(int, int); // not called anywhere

void shell_Stiffener_Properties(); // from design
void Stiffener_Prop_User(); // from design program

void Section_Modulus_Angle(int, int); // not called anywhere
void Section_Modulus_Builtup(int, double, double, double, double); // not called anywhere
// void Store();

// These functions are defined in this file
double roundup(double, int);
double rounddown(double, int);
double max(double x1, double x2, double x3, double x4, double x5, double x6, int n);
double min(double x1, double x2, double x3, double x4, double x5, double x6, int n);
double Transposed_To_Actual(double);
double Actual_To_Transposed(double);
int Shell_Course_No_Actual(double);
int Shell_Course_No_Transposed(double);
void print();

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
(17) Not Used,
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

//Default value of edit_option is 1 i.e. open existing file mode
int mainTest()
{
	struct InputData inputData;
	memset(&inputData, 0, sizeof(InputData));

	InitVariables();

	ofstream outf;
	cout << "Enter the file name For Result File ";
	cin >> File_name;
	Print_x = 0;
	tu_min = 0;
	string fileName = File_name;

	// Bypassing the option for read from .bin file and re-run.

	if (exists(fileName))
	{
		edit_option = 1;

		fstream data_file(fileName.c_str(), ios::in | ios::binary);
		data_file.read(reinterpret_cast<char *>(&inputData), sizeof(InputData));

		ReadVariables(inputData);

		data_file.close(); // newline
	}
	else
	{
		edit_option = 0;
		fileName += "Data.bin";
	}


	Input_Screen_1();
	Wind_Data();
	Seismic_Data();
	shell_Details();
	if (Roof_Type_No > 6)
		PWG_Data();
	// shell_Stiffener_Location();
	shell_Stfr_User_EL_Data();
	// shell_Stfr_User_EL();
	// shell_Stiffener_Properties();
	Stiffener_Prop_User_Data();

	if (Roof_Type_No != 7)
		Roof_Data();

	CompRing_Data();
	//CompRing_Design();

	PopulateVariables(inputData);

	fstream data_file(fileName.c_str(), ios::out|ios::binary);
	data_file.write(reinterpret_cast<char *>(&inputData), sizeof(InputData));
	data_file.flush();
	data_file.close();

	print();
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
	struct InputData inputData;
	fstream data_file(tempFileName.c_str(), ios::in | ios::binary);
	data_file.read(reinterpret_cast<char *>(&inputData), sizeof(InputData));

	ReadVariables(inputData);

	// temporary variables
	string Roof_type[8] = { "Fixed Roof type", "SELF SUPPORTING CONE ROOF", "SELF SUPPORTING DOME / UMBRELLA ROOF", "SUPPORTED CONE ROOF", "SUPPORTED DOME / UMBRELLA ROOF", "STIFFENED CONE ROOF", "GEODESIC ROOF", "No Fixed Roof" };
	string FR_type[5] = { "Floating Roof type", "SINGLE DECK FLOATING ROOF", "DOUBLE DECK FLOATING ROOF", "ALUMINUM FLOATING ROOF", "NO FLOATING ROOF" };
	string Shell_appendx[] = { " Design Procedure", "Appendix - A", "Appendix - J", "Appendix - S", "Appendix - SC", "Appendix - X", "Appendix - AL", "None" };

	double temp1, temp2, Gd;


	if (edit_option == 0)
	{
		cout << endl << "Tank Dia in M						=	"; 		cin >> D_User;

		cout << endl << "Enter 1 for Nominal Dia; 2 for ID:			=	"; 		cin >> D_Type;
		if (D_Type == 0, D_Type = 1);

		cout << endl << "Tank Height H in M					=	"; 		cin >> H;

		if (H == 0) H = 22;


		H_td_default = H;

		cout << endl << "H for Calculation of td: (Enter 0 if same as:    " << H << ")		=	"; 		cin >> H_td_user;

		if (H_td_user == 0)

			H_td = H_td_user = H_td_default;


		else
			H_td = H_td_user;

		H_tt_default = H_td;

		cout << endl << "H for Calculation of tt; (Enter 0 if same as:   " << H << ")		=	";      cin >> H_tt_user;

		if (H_tt_user == 0)
			H_tt = H_tt_user = H_tt_default;
		else
			H_tt = H_tt_user;

		H_Norm_default = (H_td - 0.5);

		cout << endl << "Normal Product Level Hn (Enter 0 if equal to:	" << H_Norm_default << ")	=	"; 		cin >> H_Norm_user;

		if (H_Norm_user == 0)
			H_Norm = H_Norm_user = H_Norm_default;
		else
			H_Norm = H_Norm_user;

		H_Seis_default = H_Norm;

		cout << endl << "H for Seismic Design; (Enter 0 if equal to:	" << H_Seis_default << ")	=	"; 		cin >> H_Seis_user;

		if (H_Seis_user == 0)
			H_Seis = H_Seis_user = H_Seis_default;
		else
			H_Seis = H_Seis_user;

		cout << endl << "Design Specific Gravity of Stored product		=	"; 		cin >> G;

		if (G == 0)
			G = 0.85;

		cout << endl << "Specific Gravity of Test water				=	";		cin >> Gw;
		if (Gw < 1.0)
			Gw = 1.0;

		cout << endl << "Design Temperature	in Deg. C			=	";		cin >> T;

		if (T < 0.050)
			T = 85;

		if (T > 260)
		{
			cout << endl << "Max. Permitted Design Temperature is 260 Deg C." << endl;
			cout << endl << "Enter Design Temperature				=	";			cin >> T;
			if (T > 260) T = 260;
		}

		cout << endl << "Minimum Design Metal Temperature	in Deg. C	=	"; 		cin >> MDMT;


		cout << endl << "Design Internal Pressure in KPa :			=	"; 		cin >> P;
		if (P < 0.050)
			P = 2.0;

		if (P > 18)
		{
			cout << endl << "Max. Permitted Design Pressure is 18 KPa." << endl;
			cout << endl << "Enter Design Pressure in KPa:				=	";			cin >> P;
			if (P > 18) P = 18;
		}

		if ((P > 0) && (P < 1))
		{
			cout << endl << "Add (P/9.8G) to design liquid head? (1 for Y; 0 for N)	:	 "; 			cin >> Option_P;

		}


		cout << endl << "Pressure Combination Factor (Enter 0 if equal to  0.4:	)	=	";		cin >> Fp;

		if (Fp < 0.4)
			Fp = 0.4;

		Po = Fp * P;


		cout << endl << "Design External Pressure in KPa:			=	"; 		cin >> Pe;

		if (P < 0.050)
			P = 0.25;


		if (Pe > 6.9)
		{
			cout << endl << "Max. Permitted External Pressure is 6.9 KPa." << endl;
			cout << endl << "Enter Design External Pressure in KPa:			=	"; 			cin >> Pe;
			if (Pe > 6.9) Pe = 6.9;
		}


		cout << endl << "External Pr. Combination Factor (Enter 0 if equal to  0.4:	)	=	";		cin >> Fpe;

		if (Fpe < 0.4)
			Fpe = 0.4;



		cout << endl << "Applicable Appendix For Shell Design: (Enter: " << endl << endl <<
			"1 For Appendix - A " << endl << endl <<
			"2 For Appendix - J" << endl << endl <<
			"3 For Appendix - S " << endl << endl <<
			"4 For Appendix - SC " << endl << endl <<
			"5 For Appendix - X " << endl << endl <<
			//	"6 For Appendix - AL " << endl << endl <<
			"7 For None )" << endl;

		cout << endl << "Applicable Appendix For Shell Design			=	"; 		cin >> Shell_Appendx_No_user;

		if (Shell_Appendx_No_user == 0)
			Shell_Appendx_No_user = 7;

		Shell_Appendx_No = Shell_Appendx_No_user;
		Shell_Appendx = Shell_Appendx_user = Shell_appendx[Shell_Appendx_No_user];

		cout << endl << "Width of First shell course in Meter			=	"; 		cin >> shell_detail_user[0][1];
		if (shell_detail_user[0][1] == 0)
			shell_detail_user[0][1] = 2.5;

		shell_detail[0][0] = shell_detail_user[0][1];


		cout << endl << "CA for First shell course (mm)					=	"; 		cin >> shell_detail_user[0][2];

		if (shell_detail_user[0][2] == 0) shell_detail_user[0][2] = 3;

		shell_detail[0][9] = shell_detail_user[0][2];




		if (Shell_Appendx_No != 7)
		{
			cout << endl << "Joint Efficiency to be considered for shell design		=	";			cin >> JE_user;
		}

		if (JE_user <0.7)
			JE_user = 0.7;

		cout << endl << "Corrosion Allowance of Bottom Plate (mm):		=	"; 		cin >> CA_Bot;
		if (CA_Bot < 0.1) CA_Bot = 2.0;


		cout << endl << "Type of Fixed roof: (Enter: " << endl << endl <<
			"1 For SELF SUPPORTING CONE ROOF " << endl << endl <<
			"2 For SELF SUPPORTING DOME/UMBRELLA ROOF" << endl << endl <<
			"3 For SUPPORTED CONE ROOF" << endl << endl <<
			"4 For SUPPORTED DOME/UMBRELLA ROOF" << endl << endl <<
			"5 For STIFFENED CONE ROOF" << endl << endl <<
			"6 For STIFFENED DOME ROOF" << endl << endl <<
			"7 For No Fixed Roof " << endl << endl <<
			"8 For GEODESIC ROOF" << endl << endl;

		cout << endl << "Type of Fixed roof:					=	"; 		cin >> Roof_Type_No_user;


		if (Roof_Type_No_user == 0) Roof_Type_No_user = 3;

		Roof_Type_No = Roof_Type_No_user;

		Roof_Type_user = Roof_type[Roof_Type_No_user];

		cout << endl << "Roof_Type_No   " << Roof_Type_No << endl << endl;

		cout << endl << "Type of Fixed roof   " << Roof_Type << endl << endl;
		if (Roof_Type_No <= 6)
		{
			cout << endl << "Corrosion Allowance of Roof Plate (mm):			=	"; 			cin >> CA_Roof;
		}
		if (CA_Roof == 0) CA_Roof = 1.0;


		cout << endl << "Type of Floating Roof:  (Enter" << endl << endl <<
			"1 For SINGLE DECK FLOATING ROOF " << endl << endl <<
			"2 For DOUBLE DECK FLOATING ROOF" << endl << endl <<
			"3 For ALUMINUM FLOATING ROOF" << endl << endl <<
			"4 For NO FLOATING ROOF )" << endl;

		cout << endl << "Type of Floating  roof:					=	"; 		cin >> FR_Type_No;

		if (FR_Type_No == 0) FR_Type_No = 4;

		FR_Type = FR_type[FR_Type_No];
		cout << endl << "Type of Floating roof   " << FR_Type << endl << endl;

		if ((FR_Type_No == 1) || (FR_Type_No == 2))
		{
			cout << endl << "Corrosion Allowance of Floating Roof (mm):		=	"; 			cin >> CA_FR;
		}


		cout << endl << "Shell Design Method: (Enter: " << endl << endl <<
			"1 For One-Foot Method " << endl << endl <<
			"2 For Variable Design Point Method" << endl;
		cout << endl << "Shell Design Method					=	 "; 		cin >> Shell_Des_Method_No;

		if (Shell_Des_Method_No == 0) Shell_Des_Method_No = 1;



		if (Shell_Appendx_No < 3)
			Shell_Des_Method_No = 1;
		else if (D_User >= 61)
			Shell_Des_Method_No = 2;

		cout << endl << "Rounding-up of thickness: mm" << endl
			<< "(Enter 0 for round-up to 1 mm; 1 for 0.1 mm ):		=	 "; 		cin >> RoundUP_to;

		RoundUP_to = 0;

		cout << endl << "Use Corroded thickness for stiffener design \n"
			<< " ( 1 for Yes; 0 for No) ? :				=	             "; 		cin >> option_Stfr;

		option_Stfr = 0;

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

			temp1 = (4.9 * D * ((H_td + ((P*Option_P) / (9.8*Gd))) - 0.3) * Gd / (0.85 * 145)) + shell_detail[0][9];
			temp2 = (4.9 * D * ((H_td + ((P*Option_P) / (9.8*Gd))) - 0.3) * Gd / (JE_user * 145)) + shell_detail[0][9];

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





	} // end of edit option

	else
	{
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
			Shell_Appendx_No_user = 7;

		if (Shell_Appendx_No < 3)
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

			if (JE_user == 0)
				JE_user = 0.7,


				temp1 = (4.9 * D * ((H_td + ((P*Option_P) / (9.8*Gd))) - 0.3) * Gd / (0.85 * 145)) + shell_detail[0][9];
			temp2 = (4.9 * D * ((H_td + ((P*Option_P) / (9.8*Gd))) - 0.3) * Gd / (JE_user * 145)) + shell_detail[0][9];

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
			else
				JE = JE_user;

		}

		Shell_Appendx_No = Shell_Appendx_No_user;
		Shell_Appendx = Shell_Appendx_user = Shell_appendx[Shell_Appendx_No_user];



		shell_detail[0][0] = shell_detail_user[0][1];
		shell_detail[0][9] = shell_detail_user[0][2];


		Roof_Type_No = Roof_Type_No_user;

		Roof_Type_user = Roof_type[Roof_Type_No];



		FR_Type = FR_type[FR_Type_No];

		Spacing_Min = 0.160;


	}

	Roof_Type_user = Roof_type[Roof_Type_No_user], FR_Type = FR_type[FR_Type_No], Shell_Appendx = Shell_Appendx_user = Shell_appendx[Shell_Appendx_No],
		No_of_Stiffeners_Max = 40;

	Roof_Type_No = Roof_Type_No_user;



	if (Shell_Des_Method_No == 1)
		Shell_Des_Method = "One-Foot Method";
	else
		Shell_Des_Method = "Variable Design Point Method";



	cout << endl << "Input Screen-1" << endl << endl;
	cout << endl << "User defined CA for first shell course			  =	" << fixed << setprecision(1) << shell_detail_user[0][2] << endl << endl;
	cout << endl << "Adopted CA for first shell course			  =	" << fixed << setprecision(1) << shell_detail[0][9] << endl << endl;

} // end of function Input_Screen_1()





void Wind_Data()
{
	/*
	Beginning of function Wind_Data();
	Purpose of this function is to take inputs related to wind load from user using form "Input Screen
	For Wind Data" and calculate design wind velocity
	The entire listing may be taken to the form "Input Screen For Wind Data" so that this function can be
	replaced with the form, which will return the following global variables to the console program:

	*/

	struct InputData inputData;
	fstream data_file(tempFileName.c_str(), ios::in | ios::binary);
	data_file.read(reinterpret_cast<char *>(&inputData), sizeof(InputData));

	ReadVariables(inputData);

	double kz_default, kzt_default, kd_default, basic_v_default, imp_factorW_default, gust_factor_default, V_default, wind_pressure;

	if (edit_option == 0)

	{


		cout << endl << "Wind Design Code: (Enter: " << endl << endl <<
			"1 ASCE 7-05 " << endl << endl <<
			"2 ASCE 7-10 " << endl << endl <<
			"3 User Defined Design Wind Velocity			:	";

		cin >> wind_design_code;

		if (wind_design_code == 0) wind_design_code = 1;

		if (wind_design_code == 3)

		{

			V_default = 190;

			cout << endl << "Enter Design Wind Velocity in Km/h			=	";
			cin >> V_user;


			//add this
			if (V_user > 0.01)
				V = V_user;
			else
				V = V_user = V_default;

		}

		else
		{

			basic_v_default = 53.6182;


			cout << endl << "Three Second Gust Design Wind Speed (V) at 10 M above ground =	" << fixed << setprecision(3) << basic_v_default << endl << endl;
			cout << endl << "Enter Three Second Gust Design Wind Speed ";
			cout << endl << "(Enter 0 for no change)					=	";
			cin >> basic_v_user;


			if (basic_v_user > 0.01)
				basic_v = basic_v_user;
			else
				basic_v = basic_v_user = basic_v_default;


			cout << endl << "Exposure Category:  Enter: " << endl << endl <<
				"1 Category B " << endl << endl <<
				"2 Category C " << endl << endl <<
				"3 Category D" << endl << endl << endl;
			cout << endl << "Exposure Category:					=	";
			cin >> wind_exp_cat;


			//add this
			if (wind_exp_cat < 2) // equala 0 or 1;

				kz_default = 0.76;
			else
				if (wind_exp_cat == 2)
					kz_default = 1.04;
				else
					kz_default = 1.22;


			cout << endl << "Velocity Pressure Exposure Coefficient Kz		=	" << kz_default << endl << endl;
			cout << endl << "Enter Velocity Pressure Exposure Coefficient Kz ";
			cout << endl << "(Enter 0 for no change)					=	";

			cin >> kz_user;

			if (kz_user > 0.01)
				kz = kz_user;
			else
				kz = kz_user = kz_default;


			kzt_default = 1.0;

			cout << endl << "Topgraphic Factor Kzt =	" << fixed << setprecision(2) << kzt_default << endl << endl;
			cout << endl << "Enter Topgraphic Factor Kzt ";
			cout << endl << "(Enter 0 for no change)					=	";

			cin >> kzt_user;


			if (kzt_user > 0.01)
				kzt = kzt_user;
			else
				kzt = kzt_user = kzt_default;

			kd_default = 0.95;


			cout << endl << "Directionality Factor Kd =	" << fixed << setprecision(2) << kzt_default << endl << endl;
			cout << endl << "Enter Directionality Factor kd ";
			cout << endl << "(Enter 0 for no change)					=	";

			cin >> kd_user;


			if (kd_user > 0.01)
				kd = kd_user;
			else
				kd = kd_user = kd_default;




			imp_factorW_default = 1.0;


			cout << endl << "Importance Facor (I) =	" << fixed << setprecision(2) << imp_factorW_default << endl << endl;
			cout << endl << "Enter Importance Facor (I)";
			cout << endl << "(Enter 0 for no change)					=	";

			cin >> imp_factorW_user;


			// drop down menu, So this condition is not needed in our case
			if (imp_factorW_user < 0.1)
				imp_factorW = imp_factorW_user = imp_factorW_default;
			else
				imp_factorW = imp_factorW_user;


			gust_factor_default = 0.85;


			cout << endl << "Gust Factor (G) =	" << fixed << setprecision(2) << gust_factor_default << endl << endl;
			cout << endl << "Enter Gust Factor (G)";
			cout << endl << "(Enter 0 for no change)					=	";

			cin >> gust_factor_user;


			if (gust_factor_user > 0.01)
				gust_factor = gust_factor_user;
			else
				gust_factor = gust_factor_user = gust_factor_default;

			//define a run button and do these calculations
			wind_pressure = ((0.613  * kz * kzt * kd * gust_factor * imp_factorW * (pow(basic_v, 2))) / 1000) + 0.24;
			V_default = 190 * pow((wind_pressure / 1.72), 0.5);


			cout << endl << "Design Wind Velocity =	" << fixed << setprecision(3) << V_default << endl << endl;
			cout << endl << "Enter Design Wind Velocity";
			cout << endl << "(Enter 0 for no change)					=	";

			cin >> V_user;


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
	//Required till this point only
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

	struct InputData inputData;
	fstream data_file(tempFileName.c_str(), ios::in | ios::binary);
	data_file.read(reinterpret_cast<char *>(&inputData), sizeof(InputData));

	ReadVariables(inputData);

	double TL_default = 0.4;
	double K_default = 1.50;


	if (edit_option == 0)

	{



		cout << endl << "Seismic Design Code: (Enter: " << endl << endl <<
			"1 for ASCE 7 " << endl << endl <<
			"2 for UBC 97 " << endl << endl <<
			"3 for Peak Ground Acceleration			:	";

		cin >> Seismic_design_code;


		if (Seismic_design_code == 0) Seismic_design_code = 1;

		if (Seismic_design_code == 3)
		{

			cout << endl << "Enter Peak Ground Acceleration S0			=	";
			cin >> S0_user;

			if (S0_user > 0.01)
				S0 = S0_user;
			else
				S0 = S0_user = 0.075;

			Ss = 2.5* S0;
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
			else if (Zone_Number == 2)
				S0 = 0.15;
			else if (Zone_Number == 3)
				S0 = 0.20;
			else if (Zone_Number == 4)
				S0 = 0.30;
			else
				S0 = 0.4;

			Ss = 2.5*S0;
			S1 = Ss * 0.5;

		}

		else
		{
			//add this
			cout << endl << "Spectral Resp. Accln. Parameter (Ss) for short period 		=	";
			cin >> Ss_user;
			if (Ss_user < 0.01) Ss_user = 0.2;

			cout << endl << "Spectral Resp. Accln. Parameter (S1) for One Second 		=	";
			cin >> S1_user;

			if (S1_user < 0.01) S1_user = 0.1;


			Ss = Ss_user;
			S1 = S1_user;

		} // end of else if logic for ASCE method


		cout << endl << "Seismic Site Class: (Enter: " << endl << endl <<
			"1 Site Class A" << endl << endl <<
			"2 Site Class B" << endl << endl <<
			"3 Site Class C" << endl << endl <<
			"4 Site Class D" << endl << endl <<
			"5 Site Class E							:	";
		cin >> site_class;

		// site_class = 3;

		// Calculate_Fa_FV();
		cout << endl << endl << endl << " Value of Ss								" << Ss_user << endl;
		cout << endl << " Value of Fa for the specified site class =		 " << Fa_default << endl;
		cout << endl << " Value of S1 								" << S1_user << endl;
		cout << endl << " Value of Fv for the specified site class =		" << Fv_default << endl << endl;



		cout << endl << "Is the site governed by ASCE rules?: (Enter: " << endl << endl <<
			"1 for YES" << endl << endl <<
			"0 for NO							:	";
		cin >> ASCE_rule;



		if (ASCE_rule == 1)
			Factor_Q = 0.667;
		else
			Factor_Q = 1.0;



		cout << endl << "Seismic User Group: (Enter: " << endl << endl <<
			"1 for SUG-1" << endl << endl <<
			"2 for SUG-2" << endl << endl <<
			"3 for SUG-3							:	";

		cin >> SUG;

		if (SUG == 0) SUG = 2;


		if (SUG == 1)
			imp_factorS = 1.0;
		else if (SUG == 2)
			imp_factorS = 1.25;
		else
			imp_factorS = 1.5;


		cout << endl << "Acceleration based site coefficient (Fa)=	" << Fa_default << endl << endl;
		cout << endl << "Enter Acceleration based site coefficient (Fa)";
		cout << endl << "(Enter 0 for no change)					=	";

		cin >> Fa_user;


		//Fa_default will be calculated by the design function
		//add this
		if (Fa_user == 0)
			Fa = Fa_user = Fa_default;
		else
			Fa = Fa_user;

		Sds = Factor_Q * Fa * Ss;


		cout << endl << "Velocity based site coefficient (Fv)=	" << Fv_default << endl << endl;
		cout << endl << "Enter GAcceleration based site coefficient (Fv)";
		cout << endl << "(Enter 0 for no change)					=	";

		cin >> Fv_user;

		if (Fv_user == 0)
			Fv = Fv_user = Fv_default;
		else
			Fv = Fv_user;

		Sd1 = Factor_Q * Fv * S1;


		cout << endl << "Transition Period For Longer Period Ground Motion (TL)  =	" << TL_default << endl << endl;
		cout << endl << "Transition Period For Longer Period Ground Motion (TL)";
		cout << endl << "(Enter 0 for no change)					=	";

		cin >> TL_user;

		if (TL_user == 0)
			TL = TL_user = TL_default;
		else
			TL = TL_user;



		cout << endl << "Coefficient to adjust 5% damping value \n" << " to 0.5% Damping value (K)=	" << K_default << endl << endl;
		//cout << endl << "Enter Coefficient to adjust 5% damping value to 0.5% Damping value (K)Transition Period For Longer Period Ground Motion (TL)";
		cout << endl << "(Enter 0 for no change)					=	";

		cin >> K_user;


		if (K_user == 0)
			K = K_user = K_default;
		else
			K = K_user;


		cout << endl << "Is Vertical Seismic Effect to be applied ?: (Enter: " << endl << endl <<
			"1 for YES" << endl << endl <<
			"0 for NO							:	";
		cin >> option_Av;

		if (option_Av == 1)
			Av = 0.47 * Sds;
		else
			Av = 0;

	}

	else
	{



		if (Seismic_design_code == 3)
		{

			if (S0_user > 0.01)
				S0 = S0_user;
			else
				S0 = S0_user = 0.075;

			Ss = 2.5*S0;
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



		//  Calculate_Fa_FV();


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
			Fa = Fa_user = Fa_default;
		else
			Fa = Fa_user;

		Sds = Factor_Q * Fa * Ss;

		if (Fv_user == 0)
			Fv = Fv_default;
		else
			Fv = Fv_user;

		Sd1 = Factor_Q * Fv * S1;

		if (TL_user == 0)
			TL = TL_user = TL_default;
		else
			TL = TL_user;



		if (K_user == 0)
			K = K_user = K_default;
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
	struct InputData inputData;
	fstream data_file(tempFileName.c_str(), ios::in | ios::binary);
	data_file.read(reinterpret_cast<char *>(&inputData), sizeof(InputData));

	ReadVariables(inputData);


	//cout<<"value of shell detail[0][0]: "<< shell_detail[0][0]<<endl;
	int a, c, f, n, i;   // temporary variables
	//exit();
	double H_Course, Gd;

	if ((Shell_Appendx_No == 1) || (Shell_Appendx_No == 2)) // input screen1

		Gd = (G > 1.0) ? G : 1.0;// specific gravity in input screen1
	else

		Gd = G;


	//	shell_detail[0][0] = shell_detail_user[0][1];
	shell_detail[0][9] = shell_detail_user[0][2];

	double H_Remaining = (H - shell_detail[0][0]);
	Shell_Appendx = Shell_Appendx_user = Shell_appendx[Shell_Appendx_No_user];

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
			cin >> H_Course;

			//  H_Course = 0;


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
		cin >> Shell_Material_No[0][0];


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
			cin >> Shell_Material_No[i][0];



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
			cin >> shell_detail_user[i][2];

			// shell_detail_user[i][2] = 0;
			if (shell_detail_user[i][2] < 0.001) shell_detail[i][9] = shell_detail[(i - 1)][9];
			else if (shell_detail_user[i][2] < 0.1) shell_detail[i][9] = 0;
			else shell_detail[i][9] = shell_detail_user[i][2];



		} // end of while statement

		if
			(D_Type == 1)
			D = D_User;

		else

			D = D_User + (shell_detail[(0)][18] / 1000);

		/*
		shell_Design();


		if (D_Type == 2)
		{
			while (D_Previous != D)
			{
				shell_Design();

			}
		}

		*/


		for (i = 0; i <= (No_of_ShellCourses - 1); i++)
		{
			/*
			cout << endl << "Adopted. Thk. for shell course Number	" << (i + 1) << "=	" << roundup((shell_detail[i][16]), RoundUP_to) << endl;
			cout << endl << "Enter Thk. for shell course Number	" << (i + 1) << endl;
			cout << endl << "(Enter '0' for no change)" << "=	";
			cin >> shell_detail_user[i][3];
			*/
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

		/*
		shell_Design();


		if (D_Type == 2)
		{
			while (D_Previous != D)
			{
				shell_Design();

			}
		}

		*/


	}



	// shell_Design();



} // end of function shell_Details()



void PWG_Data()
{
	// temporary variables
	struct InputData inputData;
	fstream data_file(tempFileName.c_str(), ios::in | ios::binary);
	data_file.read(reinterpret_cast<char *>(&inputData), sizeof(InputData));

	ReadVariables(inputData);

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
			cin >> Spacing_Top_WG_User;

			//  Spacing_Top_WG_User = 1.0;   //  to be taken from "Form For Primary Wind Girder Design".
			Spacing_Top_WG = Spacing_Top_WG_User;
		}

		else
			Spacing_Top_WG = 1.1;

		if (Spacing_Top_WG <= 0.6)
			i = 0;
		else
			if (shell_detail[(No_of_ShellCourses - 1)][18] < 5.01)

				i = 1;
			else i = 4;

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

			//			curb_angle_No_user = 0;

			if (curb_angle_No_user >= i)
				k = curb_angle_No_user;
			else
				k = i;
			Curb_angle_user = angle_section_name[curb_angle_No_user];
			Curb_angle = angle_section_name[k];


			cout << endl << "Size of Curb Angle Adopted for this tank is : (" << Curb_angle << ")	" << endl;

			if (Option_walkway == 1)
			{
				PWG_width_min_default = 710 + angle_section_width[k];
				cout << endl << "Minimum Required Width of Wind Girder used as a walkway is :  " << PWG_width_min_default << endl;
				cout << endl << "Enter Minimum Required Width of Wind Girder used as a walkway ? " << endl;
				cout << endl << "(Enter '0' for no change )" << "			=	";
				cin >> PWG_width_min_user;

				//				PWG_width_min_user = 0;

				if (PWG_width_min_user >= PWG_width_min_default)
					PWG_width_min = PWG_width_min_user;
				else
					PWG_width_min = PWG_width_min_default;

			}

			else
				PWG_width_min = 0;

			if (D > 61)
			{
				cout << endl << "Should the Primary WG designed considering the diameter as 61.0 M ? " << endl;
				cout << endl << "(Enter '0' for No, 1 For Yes )" << "			=	";
				cin >> Option_PWG;

			}

	}


	else
	{

		if (Option_walkway == 0)

			Spacing_Top_WG = Spacing_Top_WG_User;

		else
			Spacing_Top_WG = 1.1;

		if (Spacing_Top_WG <= 0.6)
			i = 0;
		else
			if (shell_detail[(No_of_ShellCourses - 1)][18] < 5.01)

				i = 1;
			else i = 4;

			Curb_angle_default = angle_section_name[i];


			if (curb_angle_No_user >= i)
				k = curb_angle_No_user;
			else
				k = i;
			Curb_angle_user = angle_section_name[curb_angle_No_user];
			Curb_angle = angle_section_name[k];


			if (Option_walkway == 1)
			{
				PWG_width_min_default = 710 + angle_section_width[k];
				if (PWG_width_min_user >= PWG_width_min_default)
					PWG_width_min = PWG_width_min_user;
				else
					PWG_width_min = PWG_width_min_default;

			}

			else
				PWG_width_min = 0;
	}
} // end of function PWG_Data()


void shell_Stfr_User_EL_Data()
{
	struct InputData inputData;
	fstream data_file(tempFileName.c_str(), ios::in | ios::binary);
	data_file.read(reinterpret_cast<char *>(&inputData), sizeof(InputData));

	ReadVariables(inputData);

	int i, n, c;

	// shell_Stfr_User_EL();

	if (edit_option == 0)
	{
		cout<<"Number of stiffeners"<<No_of_Stiffeners_R;
		for (n = 0; n <= (No_of_Stiffeners_R - 1); n++)
		{
			cout << endl << "Max. Possible Elevation of Stiffener Number " << (n + 1) << " =	" << fixed << setprecision(3) << user_EL_detail[n][4] << "	M" << endl;
			cout << endl << "Min. Possible Elevation of Stiffener Number " << (n + 1) << " =	" << fixed << setprecision(3) << user_EL_detail[n][2] << "	M" << endl;
			cout << endl << "Proposed Elevation of Stiffener Number	" << (n + 1) << " =	" << fixed << setprecision(3) << user_EL_detail[n][6] << "	M" << endl;
			cout << endl << "Enter Revised Elevation of Stiffener		" << endl;
			cout << endl << "Enter zero for no change :	";
			cin >> stfr_detail_user[n][0];
			//    stfr_detail_user[n][0] = 0;
			user_EL_detail[n][8] = stfr_detail_user[n][0];
			if (((user_EL_detail[n][8] > user_EL_detail[n][4]) || (user_EL_detail[n][8] < user_EL_detail[n][2]))&&user_EL_detail[n][8] > 0.16)
			{
					cout << endl << "User defined elevation is not within the specified range"
						<< endl << "Revise the elevation of siffener" << endl;

					// this logic will work in the form only, where it should be shown in a message box (as a change in any input variable (user_EL_detail[n][8]) will cause
					// all of these calculations to repeat). In the console program, second line will be   "<< endl << "Usr defined elevation is ignored" << endl;
			}
			else
			{	//  shell_Stfr_User_EL();
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
					//	cin >> c;

					c = 6;
					stfr_Mat_No[i] = c;
				}
				else
				{
					cout << endl << "Material for Siffener Serial Number " << (i + 1) << endl;

					cout << endl << " Enter Serial Number of Material 			" << endl;
					cout << endl << "(Enter '0' if same as previous )		=		";
					cin >> c;


					//				c = 0;

					if (c < 0.1)
						stfr_Mat_No[i] = stfr_Mat_No[(i - 1)];
					else
						stfr_Mat_No[i] = c;
				}
				// shell_Stfr_User_EL();
			} // end of for statement
		} // end of if statement
	}
	// Start Edit Option
	else
	{
		for (n = 0; n <= (No_of_Stiffeners_R - 1); n++)
		{
			user_EL_detail[n][8] = stfr_detail_user[n][0];
			// shell_Stfr_User_EL();
		}
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

	struct InputData inputData;
	fstream data_file(tempFileName.c_str(), ios::in | ios::binary);
	data_file.read(reinterpret_cast<char *>(&inputData), sizeof(InputData));

	ReadVariables(inputData);

	if (edit_option == 0)
	{
		for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
		{
			cout << endl << "Size of angle selected  for stiffener Number:	" << (i + 1) << "	" << Stfnr_Section[i][0] << endl;
			cout << endl << "Enter Type of revised stifener ring for stiffener Number:	" << (i + 1) << endl;
			cout << endl << "(0 for angle, 1 for built-up			=	";
			cin >> stfr_detail_user[i][1];  //stfr_detail[i][50];

			//    stfr_detail_user[i][1] = 0;

			stfr_detail[i][50] = stfr_detail_user[i][1];

			if (stfr_detail[i][50] < 0.5)  // if type of stfr is angle
			{
				cout << endl << "Enter serial number of angle section ";

				cout << endl << "(Enter 0 for no change)			=	";
				cin >> stfr_Sec_No[i][1];

				//    stfr_Sec_No[i][1] = 0;
			}
			else if (stfr_detail[i][50] > 0.5)  // if type of stfr is "built-up".
			{
				cout << endl << "Size of section selected  for stiffener Number:	" << (i + 1) << "	" << Stfnr_Section[i][0];
				cout << endl << "Enter details of revised section :	";
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
		// Stiffener_Prop_User();
	}
	else
	{
		for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
		{
			stfr_detail[i][50] = stfr_detail_user[i][1];
		}
		// Stiffener_Prop_User();
	}
	// cout << endl << "Size of section selected  for stiffener Number:	" << (i+1) <<"	" << Stfnr_Section[i][2];

}  // end of function Stiffener_Prop_User_Data()


void Roof_Data()
{
	struct InputData inputData;
	fstream data_file(tempFileName.c_str(), ios::in | ios::binary);
	data_file.read(reinterpret_cast<char *>(&inputData), sizeof(InputData));

	ReadVariables(inputData);
	// List of Variables

	double live_load_default, JE_roof_default, R_Roof_default, dome_radius_min, dome_radius_max;

	string Roof_type[8] = { "Fixed Roof type", "SELF SUPPORTING CONE ROOF", "SELF SUPPORTING DOME / UMBRELLA ROOF", "SUPPORTED CONE ROOF", "SUPPORTED DOME / UMBRELLA ROOF", "STIFFENED CONE ROOF", "GEODESIC ROOF", "No Fixed Roof" };

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
		else if ((Roof_Type_No == 3) || (Roof_Type_No == 5))
		{
			cout << endl << "Enter Slope of Roof " << endl;
			cout << endl << "It should be More than (1/16)		=	";
			cin >> roof_slope_user;

			if (roof_slope_user < 0.0625)
				roof_slope = 0.0625;

			else roof_slope = roof_slope_user;
		}
		else if ((Roof_Type_No == 2) || (Roof_Type_No == 4) || (Roof_Type_No == 6))
		{
			cout << endl << "Enter Radius of the Dome roof " << endl;
			cout << endl << "It should be between  " << dome_radius_min << "	&	" << dome_radius_max << "	=	" << endl;
			cin >> dome_radius_user;
			//			 dome_radius_user = D;

			if (dome_radius_user < dome_radius_min)
				dome_radius = dome_radius_min;

			else if (dome_radius_user > dome_radius_max)
				dome_radius = dome_radius_max;

			else dome_radius = dome_radius_user;
		}

		if ((P > 0.385) && (Roof_Type_No != 8))
		{
			cout << endl << "Joint Efficiency of Roof = ";
			cin >> JE_roof_user;


			if (JE_roof_user < JE_roof_default)
				JE_roof = JE_roof_default;
			else if (JE_roof_user > 1.0)
				JE_roof = 1.0;
			else
				JE_roof = JE_roof_user;
		}

		if (Roof_Type_No != 8)
		{
			cout << endl << "Select material for Roof:	" << endl;
			cout << endl << "Enter Serial Number of Material 	=	";
			cin >> Roof_Material_No;

			if (Roof_Material_No == 0)
				Roof_Material_No = 6;


			// Roof_Design();

			cout << endl << "Required Thickness of roof  =  " << fixed << setprecision(1) << Roof_Thk[6] << endl << endl;
			cout << endl << "Enter Thickness of Roof (Enter 0 if same as" << Roof_Thk[6] << ")		=	";
			cin >> Roof_Thk_user;


			Roof_Thk[7] = Roof_Thk_user;

			if ((JE_roof < 0.7) && (Roof_Thk[8] > 13.0))
			{
				JE_roof = 0.7;
				//  Roof_Design();
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


		if (Roof_Type_No == 1)
		{
			if (roof_slope_user < 0.166667)
				roof_slope = 0.166667;
			else if (roof_slope_user > 0.75)
				roof_slope = 0.75;
			else roof_slope = roof_slope_user;
		}
		else if ((Roof_Type_No == 3) || (Roof_Type_No == 5))
		{
			if (roof_slope_user < 0.0625)
				roof_slope = 0.0625;

			else roof_slope = roof_slope_user;
		}
		else if ((Roof_Type_No == 2) || (Roof_Type_No == 4) || (Roof_Type_No == 6))
		{
			if (dome_radius_user < dome_radius_min)
				dome_radius = dome_radius_min;

			else if (dome_radius_user > dome_radius_max)
				dome_radius = dome_radius_max;

			else dome_radius = dome_radius_user;
		}


		if (JE_roof_user < JE_roof_default)
			JE_roof = JE_roof_default;

		else if (JE_roof_user > 1.0)
			JE_roof = 1.0;
		else
			JE_roof = JE_roof_user;

		Roof_Thk[7] = Roof_Thk_user;


		if (Roof_Type_No != 8)

		{
			Roof_Thk[7] = Roof_Thk_user;
			// Roof_Design();


			if ((JE_roof < 0.7) && (Roof_Thk[8] > 13.0))
			{
				JE_roof = 0.7;

				// Roof_Design();
			}
		}
	} // end of edit option

	if ((Roof_Thk[5] - CA_Roof) > 13.0)
	{
		if (Roof_Type_No_user == 1)
			(Roof_Type_No = 3);
		if (Roof_Type_No_user == 2)
			(Roof_Type_No = 4);
		// Roof_Design();
	}

	Roof_Type = Roof_type[Roof_Type_No];

} // end of function Roof_Data()


void PopulateVariables(InputData& inputData)
{
	cout << endl << "Populate Variable (beg)" << endl << endl;
	cout << endl << "User defined CA for first shell course			  =	" << fixed << setprecision(1) << shell_detail_user[0][2] << endl << endl;
	cout << endl << "Adopted CA for first shell course			  =	" << fixed << setprecision(1) << shell_detail[0][9] << endl << endl;

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
	inputData.Wt_Roof_Str_defaut = Wt_Roof_Str_defaut;
	inputData.Wt_Roof_Str_user = Wt_Roof_Str_user;
	inputData.Wt_Roof_Str = Wt_Roof_Str;
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

	for (int i = 1; i <= 14; i++)
	{
		inputData.shell_detail_user[i][0] = shell_detail_user[i][0];
		inputData.shell_detail_user[i][1] = shell_detail_user[i][1];
		inputData.shell_detail_user[i][2] = shell_detail_user[i][2];
		inputData.shell_detail_user[i][3] = shell_detail_user[i][3];

	}

	inputData.shell_detail_user[0][0] = shell_detail_user[0][0];
	inputData.shell_detail_user[0][1] = shell_detail_user[0][1];
	inputData.shell_detail_user[0][2] = shell_detail_user[0][2];
	inputData.shell_detail_user[0][3] = shell_detail_user[0][3];


	for (int i = 0; i <= 44; i++)
	{

		inputData.stfr_detail_user[i][0] = stfr_detail_user[i][0];
		inputData.stfr_detail_user[i][1] = stfr_detail_user[i][1];
		inputData.stfr_detail_user[i][2] = stfr_detail_user[i][2];


	}


	inputData.Spacing_Top_WG_User = Spacing_Top_WG_User;
	inputData.PWG_width_min_user = PWG_width_min_user;
	inputData.R_Roof_user = R_Roof_user;
	inputData.live_load_user = live_load_user;
	inputData.snow_load_bal = snow_load_bal;
	inputData.snow_load_unbal = snow_load_unbal;
	inputData.roof_slope_user = roof_slope_user;
	inputData.dome_radius_user = dome_radius_user;
	inputData.JE_roof_user = JE_roof_user;
	inputData.Roof_Thk_user = Roof_Thk_user;
	inputData.D_Type = D_Type;
	inputData.Option_P = Option_P;
	inputData.Shell_Appendx_No_user = Shell_Appendx_No_user;
	inputData.Roof_Type_No_user = Roof_Type_No_user;
	inputData.FR_Type_No = FR_Type_No;
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

	}


	inputData.Option_walkway = Option_walkway;
	inputData.curb_angle_No_user = curb_angle_No_user;
	inputData.Option_PWG = Option_PWG;

	for (int i = 0; i <= 44; i++)
	{

		inputData.stfr_Mat_No[i] = stfr_Mat_No[i];
		inputData.stfr_Sec_No[i][0] = stfr_Sec_No[i][0];
		inputData.stfr_Sec_No[i][1] = stfr_Sec_No[i][1];

	}


	inputData.option_frangible_roof = option_frangible_roof;
	inputData.Roof_Material_No = Roof_Material_No;
	inputData.No_of_ShellCourses = No_of_ShellCourses;
	inputData.No_of_Stiffeners_R = No_of_Stiffeners_R;
	inputData.Shell_Appendx_No = Shell_Appendx_No;

	cout << endl << "Populate Variable (end)" << endl << endl;
	cout << endl << "User defined CA for first shell course			  =	" << fixed << setprecision(1) << shell_detail_user[0][2] << endl << endl;
	cout << endl << "Adopted CA for first shell course			  =	" << fixed << setprecision(1) << shell_detail[0][9] << endl << endl;

}


void ReadVariables(InputData& inputData)
{

	cout << endl << "Read Variables (beg)" << endl << endl;
	cout << endl << "User defined CA for first shell course			  =	" << fixed << setprecision(1) << shell_detail_user[0][2] << endl << endl;
	cout << endl << "Adopted CA for first shell course			  =	" << fixed << setprecision(1) << shell_detail[0][9] << endl << endl;
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
	Wt_Roof_Str_defaut = inputData.Wt_Roof_Str_defaut;
	Wt_Roof_Str_user = inputData.Wt_Roof_Str_user;
	Wt_Roof_Str = inputData.Wt_Roof_Str;
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
	Factor_Q = inputData.Factor_Q;;
	TL_user = inputData.TL_user;
	K_user = inputData.K_user;


	for (int i = 0; i <= 14; i++)
	{
		shell_detail_user[i][0] = inputData.shell_detail_user[i][0];
		shell_detail_user[i][1] = inputData.shell_detail_user[i][1];
		shell_detail_user[i][2] = inputData.shell_detail_user[i][2];
		shell_detail_user[i][3] = inputData.shell_detail_user[i][3];

	}

	for (int i = 0; i <= 44; i++)
	{
		stfr_detail_user[i][0] = inputData.stfr_detail_user[i][0];
		stfr_detail_user[i][1] = inputData.stfr_detail_user[i][1];
		stfr_detail_user[i][2] = inputData.stfr_detail_user[i][2];
	}


	Spacing_Top_WG_User = inputData.Spacing_Top_WG_User;
	PWG_width_min_user = inputData.PWG_width_min_user;
	R_Roof_user = inputData.R_Roof_user;
	live_load_user = inputData.live_load_user;
	snow_load_bal = inputData.snow_load_bal;;
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
	FR_Type_No = inputData.FR_Type_No;
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
	}

	Option_walkway = inputData.Option_walkway;
	curb_angle_No_user = inputData.curb_angle_No_user;
	Option_PWG = inputData.Option_PWG;

	for (int i = 0; i <= 44; i++)
	{
		stfr_Mat_No[i] = inputData.stfr_Mat_No[i];
		stfr_Sec_No[i][0] = inputData.stfr_Sec_No[i][0];
		stfr_Sec_No[i][1] = inputData.stfr_Sec_No[i][1];
	}

	option_frangible_roof = inputData.option_frangible_roof;
	Roof_Material_No = inputData.Roof_Material_No;
	No_of_ShellCourses = inputData.No_of_ShellCourses;
	No_of_Stiffeners_R = inputData.No_of_Stiffeners_R;
	Shell_Appendx_No = inputData.Shell_Appendx_No;

	//newly added
	// weight_stair_user = inputData.weight_stair_user;
	// weight_adder_user = inputData.weight_adder_user;

	// imp_factorS = inputData.imp_factorS;
	// Sds = inputData.Sds;
	// Sd1 = inputData.Sd1;
	// Av = inputData.Av;

	// Rafter_spacing = inputData.Rafter_spacing;
	// Rafter_spacing_cent = inputData.Rafter_spacing_cent;
	// Weight_FR = inputData.Weight_FR;
	// WeightAdder_roof_default = inputData.WeightAdder_roof_default;
	// WeightAdder_roof_user = inputData.WeightAdder_roof_user;
	// WeightAdder_roof = inputData.WeightAdder_roof;
	// weight_platform_default = inputData.weight_platform_default;
	// weight_platform_user = inputData.weight_platform_user;
	// weight_platform = inputData.weight_platform;
	// roof_slope_user_numerator = inputData.roof_slope_user_numerator;
	// roof_slope_user_denominator = inputData.roof_slope_user_denominator;

	// type_compression_ring = inputData.type_compression_ring;

	// CR_Type_No[0]= inputData.CR_Type_No[0];
	// CR_Type_No[1]= inputData.CR_Type_No[1];

	// for(int i=0;i<3;i++)
	// {
	// 	CR_Material_No[i] = inputData.CR_Material_No[i];
	// 	CR_Size[i] = inputData.CR_Size[i];
	// 	t_bar[i] = inputData.t_bar[i];
	// 	w_bar[i] = inputData.w_bar[i];;
	// 	l_bar[i] = inputData.l_bar[i];;
	// 	t_shell[i] = inputData.t_shell[i];;
	// 	w_shell[i] = inputData.w_shell[i];;
	// }

	// No_of_Stiffeners_Max_user = inputData.No_of_Stiffeners_Max_user;
	// H_Ts = inputData.H_Ts;
	// t_uniform = inputData.t_uniform;
	// H_Max_W = inputData.H_Max_W;
	// H_Max_V = inputData.H_Max_V;

	// //not including these as of now, will see later
	// //user_EL_detail[45][11];
	// //stfr_detail[45][80];

	// //PWG
	// PWG_Width_Web = inputData.PWG_Width_Web;
	// PWG_Thick_Web = inputData.PWG_Thick_Web;
	// PWG_Height_Flange = inputData.PWG_Height_Flange;
	// PWG_Thick_Flange = inputData.PWG_Thick_Flange;

	// //defined by Raghav
	// kz_default = inputData.kz_default;
	// V_default = inputData.V_default;
	// Fa_default = inputData.Fa_default;
	// Fv_default = inputData.Fv_default;
	// D = inputData.D;
	// Gd = inputData.Gd;
	// JE = inputData.JE;
	// Spacing_Min = inputData.Spacing_Min;

	// //defined by Abhishek
	// H_Remaining = inputData.H_Remaining;

	//	cout << endl << "Read Variables (end)" << endl << endl;
	//	cout << endl << "User defined CA for first shell course			  =	" << fixed << setprecision(1) << shell_detail_user[0][2] << endl << endl;
	//	cout << endl << "Adopted CA for first shell course			  =	" << fixed << setprecision(1) << shell_detail[0][9] << endl << endl;
}


void CompRing_Data()
{
	struct InputData inputData;
	fstream data_file(tempFileName.c_str(), ios::in | ios::binary);
	data_file.read(reinterpret_cast<char *>(&inputData), sizeof(InputData));

	ReadVariables(inputData);
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

	// Yield strength of top shell = shell_detail[No_of_ShellCourses-1][2]
	// Allowable stress of top shell = shell_detail[No_of_ShellCourses-1][3]
	//Roof_Material_YS Roof_Material_SA

} // end of function CompRing_Data()


double Actual_To_Transposed(double x)
{
	double y;
	int i, j;

	// finding shell course number on which stiffener is fixed

	for (i = 0; i <= (No_of_ShellCourses - 1); i++)
	{

		if ((x > shell_detail[i][24]) && (x < shell_detail[i][25]))
			j = i;

	}

	y = shell_detail[j][22] + ((x - shell_detail[j][24]) *   shell_detail[j][21] / shell_detail[j][0]);

	return y;
}


double Transposed_To_Actual(double y)
{
	double x;
	int i, j;

	// finding shell course number on which stiffener is fixed
	for (i = 0; i <= (No_of_ShellCourses - 1); i++)
	{

		if ((y > shell_detail[i][22]) && (y < shell_detail[i][23]))
			j = i;

	}

	x = shell_detail[j][24] + ((y - shell_detail[j][22]) *   shell_detail[j][0] / shell_detail[j][21]);

	return x;
}

int Shell_Course_No_Actual(double x)
{
	int j;
	int i;
	for (i = 0; i <= (No_of_ShellCourses - 1); i++)
	{
		if ((x > shell_detail[i][24]) && (x < shell_detail[i][25]))
			j = i;
	}

	return j;
}

int Shell_Course_No_Transposed(double y)
{
	int j;
	int i;
	for (i = 0; i <= (No_of_ShellCourses - 1); i++)
	{
		if ((y > shell_detail[i][22]) && (y < shell_detail[i][23]))
			j = i;
	}

	return j;
}


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
		else               Y_mod = (191000 - (3000 * (T - 200) / 60));

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
		else               Y_mod = (182000 - (3000 * (T - 200) / 60));
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
	D_User = H = H_td_user = H_tt_user = H_Norm_user = H_Seis_user = G = Gw = T = MDMT = P = Po_user =
		Pe = CA_Bot = CA_Roof = JE_user = CA_FR = Wt_Roof_Str_user =
		kz_user = kzt_user = kd_user = basic_v_user = imp_factorW_user = gust_factor_user = V_user =
		S0_user = Ss_user = S1_user = Fa_user = Fv_user = Factor_Q = TL_user = K_user =
		shell_detail_user[15][4] =
		stfr_detail_user[45][2] =
		Spacing_Top_WG_User = PWG_width_min_user =
		R_Roof_user = live_load_user = snow_load_bal = snow_load_unbal = roof_slope_user = dome_radius_user = JE_roof_user = Roof_Thk_user = 0.0;

	int D_Type = Option_P = Shell_Appendx_No_user = Roof_Type_No_user = FR_Type_No = Shell_Des_Method_No = RoundUP_to = option_Stfr =
		wind_design_code = wind_exp_cat = Seismic_design_code = Zone_Number = site_class = ASCE_rule = SUG = option_Av = Shell_Material_No[15][3] =
		Option_walkway = curb_angle_No_user = Option_PWG = stfr_Mat_No[45] = stfr_Sec_No[45][2] = No_of_Stiffeners_Max_user = option_frangible_roof = Roof_Material_No = option_annularPlate = 0;

}


// Start of functions for design





// End of functions for design



void print()
{
	int i = 0;
	ofstream outf;
	string fileName = File_name + "Result.txt";
	outf.open(fileName.c_str(), ios::out); //reviced line  if file name is sample, then the newly formed name is sample_out.txt
	//	outf.open(strcat(File_name),ios::txt); //reviced line  if file name is sample, then the newly formed name is sample_out.txt

	if (!outf)
	{  // Print an error and exit
		cerr << File_name << ".txt could not be opened for writing!" << endl;
	}
	Print_x = 1;

	/*std::string finalString = "						USER DATA					 \n";
	char buff[100];

	*/
	outf << endl << "						USER DATA					" << endl << endl;
	outf << endl << "The User Defined Diamter of the Tank			=	" << D_User << "   M" << endl << endl;
	/*sprintf_s(buff, sizeof(buff), "The User Defined Diamter of the Tank			=	%d,     M\n", D_User);
	finalString.append(buff);
	*/
	outf << endl << "NOM. Dia (1) / ID (2) / 				=	" << D_Type << endl;
	/*sprintf_s(buff, sizeof(buff), "NOM. Dia (1) / ID (2) / 				=	%d\n", D_Type);
	finalString.append(buff); */

	outf << endl << "The User Defined Height of the Tank			=	" << H << "   M" << endl << endl;
	/*sprintf_s(buff, sizeof(buff), "The User Defined Height of the Tank			=	%d    M\n", H);
	finalString.append(buff);
	*/

	outf << endl << "H for Calculation of td is				=	" << H_td_user << "   M" << endl;
	/*sprintf_s(buff, sizeof(buff), "H for Calculation of td is				=	%d    M\n", H_td_user);
	finalString.append(buff); */


	outf << endl << "H for Calculation of tt is				=	" << H_tt_user << "   M" << endl;
	/*sprintf_s(buff, sizeof(buff), "H for Calculation of tt is				=	%d    M\n", H_tt_user);
	finalString.append(buff);
	*/
	outf << endl << "Normal Filling Height					=	" << H_Norm_user << "   M" << endl;
	/*sprintf_s(buff, sizeof(buff), "Normal Filling Height					=	%d    M\n", H_Norm_user);
	finalString.append(buff);
	*/

	outf << endl << "H for Seismic Design is					=	" << H_Seis_user << "   M" << endl;
	/*sprintf_s(buff, sizeof(buff), "H for Seismic Design is					=	%d    M\n", H_Seis_user);
	finalString.append(buff);
	*/

	outf << endl << "Specific Gravity of Product				=	" << G << "   " << endl;
	/*sprintf_s(buff, sizeof(buff), "Specific Gravity of Product				=	%d    \n", G);
	finalString.append(buff);*/

	outf << endl << "Specific Gravity of Test Water				=	" << Gw << "   " << endl;
	outf << endl << "Design Temperature					=	" << T << "   Deg. C" << endl;
	outf << endl << "Minimum Design Metal Temperature			=	" << MDMT << "   Deg. C" << endl;
	outf << endl << "Design Internal Pressure				=	" << P << "    KPa" << endl;
	cout << endl << "Add (P/9.8G) to liquid head? (1=Y; 0=N):	=	" << Option_P << endl;
	outf << endl << "Operating Pressure					=	" << Po_user << "   KPa" << endl;
	outf << endl << "Design External Pressure				=	" << Pe << "   KPa" << endl;
	outf << endl << "Shell_Appendx_No_user					=	" << Shell_Appendx_No_user << endl;


	outf << endl << "JE for shell Design					=	" << JE_user << endl;
	outf << endl << "CA of Bottom Plate (mm)					=	" << CA_Bot << "   mm" << endl;
	outf << endl << "CA of Roof Plate (mm)					=	" << CA_Roof << "   mm" << endl;
	outf << endl << "CA of Floating Roof (mm)				=	" << CA_FR << "   mm" << endl;
	outf << endl << "Shell_Des_Method_No					=	" << Shell_Des_Method_No << endl;
	outf << endl << "Wt_Roof_Str_user					=	" << Wt_Roof_Str_user << endl;

	outf << endl << "Roof_Type_No_user					=	" << Roof_Type_No_user << endl;
	outf << endl << "Roof_Type_No Adopted					=	" << Roof_Type_No << endl;
	outf << endl << "FR_Type_No						=	" << FR_Type_No << endl;
	outf << endl << "Applicable Apndx for shell Design 			=	" << Shell_Appendx_user << endl;
	outf << endl << "RoundUP_to						=	" << RoundUP_to << endl;
	outf << endl << "option_Stfr.						=	" << option_Stfr << endl;
	outf << endl << "Number of Shell Courses					=	" << No_of_ShellCourses << endl;

	outf << endl << "wind_design_code					=	" << wind_design_code << endl;
	outf << endl << "V_user							=	" << V_user << endl;
	outf << endl << "wind_exp_cat						=	" << wind_exp_cat << endl;

	outf << endl << "basic_v_user						=	" << basic_v_user << endl;
	outf << endl << "kz_user							=	" << kz_user << endl;
	outf << endl << "kzt_user						=	" << kzt_user << endl;
	outf << endl << "kd_user							=	" << kd_user << endl;
	outf << endl << "imp_factorW_user					=	" << imp_factorW_user << endl;
	outf << endl << "gust_factor_user					=	" << gust_factor_user << endl;

	outf << endl << "Seismic_design_code					=	" << Seismic_design_code << endl;
	outf << endl << "Zone_Number						=	" << Zone_Number << endl;

	outf << endl << "S0_user							=	" << S0_user << endl;
	outf << endl << "Ss_user							=	" << Ss_user << endl;
	outf << endl << "S1_user							=	" << S1_user << endl;
	outf << endl << "site_class						=	" << site_class << endl;
	outf << endl << "ASCE_rule						=	" << ASCE_rule << endl;
	outf << endl << "SUG							=	" << SUG << endl;
	outf << endl << "option_Av						=	" << option_Av << endl;

	outf << endl << "Fa_user							=	" << Fa_user << endl;
	outf << endl << "Fv_user							=	" << Fv_user << endl;
	outf << endl << "Factor_Q						=	" << Factor_Q << endl;
	outf << endl << "TL_user							=	" << TL_user << endl;
	outf << endl << "K_user							=	" << K_user << endl;
	outf << endl << "option_Av						=	" << option_Av << endl;

	for (i = 0; i <= (No_of_ShellCourses - 1); i++)
	{
		outf << endl << "Width of shell course Number " << (i + 1) << "				=	" << shell_detail_user[i][1] << "   M" << endl;
		outf << endl << "Sl. No. of Material for shell course Number " << (i + 1) << "		=	" << Shell_Material_No[i][0] << endl;
		outf << endl << "UTS of shell course Number " << (i + 1) << "				=	" << shell_detail_user[i][0] << "   MPa" << endl;
		outf << endl << "CA of shell course Number " << (i + 1) << "				=	" << shell_detail_user[i][2] << "   mm" << endl;
		outf << endl << "User defined thickness shell course Number " << (i + 1) << "		=	" << shell_detail_user[i][3] << "   mm" << endl << endl << endl;

	}

	outf << endl << "Option_walkway						=	" << Option_walkway << endl;
	outf << endl << "curb_angle_No_user					=	" << curb_angle_No_user << endl;
	outf << endl << "Spacing_Top_WG_User					=	" << Spacing_Top_WG_User << endl;
	outf << endl << "PWG_width_min_user					=	" << PWG_width_min_user << endl;
	outf << endl << "Option_PWG						=	" << Option_PWG << endl;


	for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
	{
		outf << endl << "Elevation of stfr. No " << (i + 1) << "					=	" << stfr_detail_user[i][0] << endl;
		outf << endl << "Material for stfr. No " << (i + 1) << "					=	" << stfr_Mat_No[i] << endl;

		if (stfr_detail[i][50] < 0.5)  // if type of stfr is angle
		{
			outf << endl << "Type of stfr Ring No " << (i + 1) << "					=	" << stfr_detail_user[i][1] << endl;
			outf << endl << "Sl. No of angle stfr No " << (i + 1) << "				=	" << stfr_Sec_No[i][1] << endl;
		}

		else if (stfr_detail[i][50] > 0.5)  // if type of stfr is "built-up".
		{
			outf << endl << "Width of Web for stfr No " << (i + 1) << "					=	" << stfr_Prop_user[i][0] << endl;
			outf << endl << "Thickness of Web for stfr No " << (i + 1) << "				=	" << stfr_Prop_user[i][1] << endl;
			outf << endl << "Height of flange for stfr No " << (i + 1) << "				=	" << stfr_Prop_user[i][2] << endl;
			outf << endl << "thickness of flange for stfr No " << (i + 1) << "				=	" << stfr_Prop_user[i][3] << endl;
		}

	}

	outf << endl << "R_Roof_user						=	" << R_Roof_user << endl;
	outf << endl << "option_frangible_roof					=	" << option_frangible_roof << endl;
	outf << endl << "live_load_user						=	" << live_load_user << endl;
	outf << endl << "snow_load_bal						=	" << snow_load_bal << endl;
	outf << endl << "snow_load_unbal						=	" << snow_load_unbal << endl;
	outf << endl << "roof_slope_user						=	" << roof_slope_user << endl;
	outf << endl << "dome_radius_user					=	" << dome_radius_user << endl;
	outf << endl << "JE_roof_user						=	" << JE_roof_user << endl;
	outf << endl << "Roof_Material_No					=	" << Roof_Material_No << endl;
	outf << endl << "Roof_Thk_user						=	" << Roof_Thk_user << endl << endl << endl;

	Print_x = 1;

	outf << endl << "						RESULT					" << endl << endl;
	outf << endl << "						DESIGN VARIABLE					" << endl << endl;
	outf << endl << "The User Defined Diamter of the Tank			=	" << D_User << "   M" << endl << endl;
	outf << endl << "The Nominal Diamter of the Tank				=	" << D << "   M" << endl << endl;
	outf << endl << "The Height of the Tank					=	" << H << "   M" << endl;
	outf << endl << "Specific Gravity of Product				=	" << G << "   " << endl;
	outf << endl << "Specific Gravity of Test Water				=	" << Gw << "   " << endl;
	outf << endl << "The Normal Product Level				=	" << H_Norm << "   M" << endl;
	outf << endl << "H for Calculation of td is				=	" << H_td << "   M" << endl;
	outf << endl << "H for Calculation of tt is				=	" << H_tt << "   M" << endl;
	outf << endl << "H for Seismic Design is					=	" << H_Seis << "   M" << endl;
	outf << endl << "Design Temperature					=	" << T << "   Deg. C" << endl;
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
	outf << endl << "MDMT							=	" << MDMT << "   Deg. C" << endl;
	outf << endl << "Design Internal Pressure				=	" << P << "    KPa" << endl;
	outf << endl << "Operating Pressure					=	" << Po << "   KPa" << endl;
	outf << endl << "Design External Pressure				=	" << Pe << "   KPa" << endl;
	outf << endl << "CA of Bottom Plate (mm)					=	" << CA_Bot << "   mm" << endl;
	outf << endl << "Type of Fixed roof User					=	" << Roof_Type_user << endl;

	if (Roof_Type_No_user == 1 || Roof_Type_No_user == 2)
		outf << endl << "Required thickness of self supporting Roof	=		" << max(Roof_Thk[2], Roof_Thk[3], Roof_Thk[4], Roof_Thk[4], Roof_Thk[4], Roof_Thk[4], 3) << endl;

	outf << endl << "Type of Fixed roof Adopted				=	" << Roof_Type << endl;
	outf << endl << "CA of Roof Plate (mm)					=	" << CA_Roof << "   mm" << endl;
	outf << endl << "Type of Floating roof					=	" << FR_Type << endl;
	//	outf << endl << "Option For Adding Design Pr. to Static Head		=	" << Option_P << endl;
	//	outf << endl << "Applicable Appendix Number for shell Design: 		=	" << Shell_Appendx_No << endl;
	outf << endl << "Applicable Appendix for shell Design (User): 		=	" << Shell_Appendx_user << endl;
	outf << endl << "Applicable Appendix for shell Design (Adptd): 		=	" << Shell_Appendx << endl;
	outf << endl << "Min Nom. Thk. for first shell course)			=	" << Min_Nom_Thk_1 << endl;
	outf << endl << "Min Nom. Thk. for upper shell course)			=	" << Min_Nom_Thk << endl;
	outf << endl << "Shell Design Method: 					=	" << Shell_Des_Method << endl;
	outf << endl << "Number of Shell Courses					=	" << No_of_ShellCourses << endl;
	outf << endl << "Option for using Cor. thk. for stfr. des.		=	" << option_Stfr << endl;
	outf << endl << "Top Shell Thickness					=	" << t_uniform << endl;
	outf << endl << "Top Shell Thickness (Min Reqd for wind)			=	" << tu_min_W << endl;
	if (Shell_Des_Method_No == 2)
	{
		outf << endl << "Required Thk. of first shell course (VDP) td		=	" << shell_detail[0][12] << endl;
		outf << endl << "Required Thk. of first shell course (VDP) tt		=	" << shell_detail[0][13] << endl;

	}


	//	int i;
	outf
		<< "\n\n\ncourse number	"

		<< "YS_Atm	\t"
		<< "UTS	\t"
		<< "Sd_Atm	\t"
		<< "St	\t"
		<< "YS_Des	\t"
		<< "Sd_Des	\t"
		<< "MOC				"
		<< endl;

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




	if ((Shell_Des_Method_No == 1) && (Shell_Appendx_No == 5))

	{
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
			<< "E_Atm		"
			<< "E_Des	"
			<< "Factor_M1	\n"
			<< endl;


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
			<< fixed << setprecision(0) << "		" << Y_Mod_X[i][1]
			<< fixed << setprecision(0) << "		" << Y_Mod_X[i][2]
			<< fixed << setprecision(3) << "		" << (Y_Mod_X[i][2] / Y_Mod_X[i][1])
			<< endl << endl;
	}


	else if ((Shell_Des_Method_No == 1) && (Shell_Appendx_No != 5))
	{

		outf
			<< "\n\ncourse number	"
			<< "height	"
			<< "CA	"
			<< "H for td	"
			<< "H For tt	"
			<< "td		"
			<< "tt		"
			<< "Adopted Thk	"
			<< "JE	\n"
			<< endl;

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
			<< endl << endl;
	}

	else if ((Shell_Des_Method_No == 2) && (Shell_Appendx_No == 5))
	{
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
			<< "E_Atm		"
			<< "E_Des	"
			<< "Factor_M1	\n"
			<< endl;

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
			<< fixed << setprecision(2) << "		" << JE
			<< fixed << setprecision(0) << "	" << Y_Mod_X[i][1]
			<< fixed << setprecision(0) << "		" << Y_Mod_X[i][2]
			<< fixed << setprecision(3) << "		" << (Y_Mod_X[i][2] / Y_Mod_X[i][1])
			<< endl << endl;
	}

	else if ((Shell_Des_Method_No == 2) && (Shell_Appendx_No != 5))
	{
		outf
			<< "\n\ncourse number	"
			<< "height	"
			<< "CA	"
			<< "H for td	"
			<< "H For tt	"
			<< "td		"
			<< "tt		"
			<< "Adopted Thk	"
			<< "JE	\n"
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
			<< fixed << setprecision(2) << "		" << JE
			<< endl << endl;
	}
	double	temp1 = pow((D / t_uniform), 0.75) * (H_Ts / D) * pow((Fy_Shell / Y_Mod), 0.5);
	double 	temp2 = Y_Mod / (15203 * Psi * pow((D / t_uniform), 2.5) * (H_Ts / D));
	double 	temp3 = 47.07 * pow((Psi * H_Ts * Ps), 0.4) * pow(D, 0.6) / pow(Y_Mod, 0.4);
	int k;

	outf << endl << "wind_design_code					=	" << wind_design_code << endl;
	outf << endl << "wind_exp_cat						=	" << wind_exp_cat << endl;
	outf << endl << "basic_v							=	" << basic_v << endl;
	outf << endl << "kz							=	" << kz << endl;
	outf << endl << "kzt							=	" << kzt << endl;
	outf << endl << "kd							=	" << kd << endl;
	outf << endl << "imp_factorW						=	" << imp_factorW << endl;
	outf << endl << "gust_factor						=	" << gust_factor << endl;



	outf << endl << "\n\n\n\nDesign Wind Velocity					=	" << V << "		KmPH" << endl;
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
	outf << endl << "Spcing of top Wg from top)				=	" << Spacing_Top_WG << endl;

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

	if (No_of_Stiffeners > 0)
	{
		outf << "\n\n\tSl.No	"
			<< "shell course	"
			<< "Elv. on		"
			<< "Spacing to	"
			<< "Elv. on		"
			<< "Spacing to	"
			<< "Spacing to\n";



		outf << "\tstifnr	"
			<< "number		"
			<< "Trns. shell	"
			<< "stfr above	"
			<< "actual shell	"
			<< "Top Joint	"
			<< "Bottom Joint	"
			<< "\n\n";

		for (i = 0; i <= (No_of_Stiffeners - 1); i++)
		{
			outf << "	" << (i + 1)
				<< "	" << stfr_location[i][0]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][0]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][1]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][2]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][5]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][6]
				<< endl << endl;


		}

		outf << "\n\n\tSl.No	"
			<< "shell course	"
			<< "Elv. on		"
			<< "Spacing to	"
			<< "Elv. on		"
			<< "Spacing to	"
			<< "Spacing to\n";



		outf << "\tstifnr	"
			<< "number		"
			<< "Trns. shell	"
			<< "stfr above	"
			<< "actual shell	"
			<< "Top Joint	"
			<< "Bottom Joint	"
			<< "\n\n";

		for (i = 0; i <= (No_of_Stiffeners - 1); i++)
		{
			outf << "	" << (i + 1)
				<< "	" << stfr_location[i][1]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][7]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][8]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][9]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][12]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][13]
				<< endl << endl;
		}


		outf << "\n\n\tSl.No	"
			<< "shell course	"
			<< "Elv. on		"
			<< "Spacing to	"
			<< "Elv. on		"
			<< "Spacing to	"
			<< "Spacing to\n";



		outf << "\tstifnr	"
			<< "number		"
			<< "Trns. shell	"
			<< "stfr above	"
			<< "actual shell	"
			<< "Top Joint	"
			<< "Bottom Joint	"
			<< "\n\n";

		for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
		{
			outf << "	" << (i + 1)
				<< "	" << stfr_location[i][2]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][14]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][15]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][16]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][19]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][20]
				<< endl << endl;
		}




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

		outf << "\n\n\tstfr No	"
			<< "shell thk	"
			<< "shell Ht	"
			<< "Shell Area	"
			<< "Stfr Area	"
			<< "Total Area	"
			<< "Size of Ring"
			<< "\n\n\n";

		for (i = 0; i <= (No_of_Stiffeners_R - 1); i++)
		{
			outf << "	" << (i + 1)
				<< fixed << setprecision(3) << "	" << stfr_detail[i][31]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][32]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][33]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][39]
				<< fixed << setprecision(3) << "		" << stfr_detail[i][45]

				<< endl << endl;
		}





		outf << "\n\n\t\t\t Details of stiffener ring proposed";

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


		outf << "\n\n\t\t\t Details of stiffener ring Specified by user";

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




		outf << "\n\n\t\t\t Details of stiffener ring Adopted";

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

	if (Roof_Type_No < 7)
	{

		outf << endl << "						Roof Design					" << endl;
		outf << endl << "-----------					" << endl;
		outf << endl << "Roof Type Considered					=	" << fixed << setprecision(2) << Roof_Type << endl;
		outf << endl << "Youngs Modulus of Roof					=	" << fixed << setprecision(2) << Roof_Material_Y_mod << "   MPa" << endl;
		outf << endl << "Yield Strength of Roof					=	" << fixed << setprecision(2) << Roof_Material_YS << "   MPa" << endl;
		outf << endl << "Allowable stess of Roof					=	" << fixed << setprecision(2) << Roof_Material_SA << "   MPa" << endl;
		outf << endl << "Design Internal Pressure				=	" << fixed << setprecision(2) << P << "   KPa" << endl;
		outf << endl << "Dead Load						=	" << fixed << setprecision(3) << dead_load << "   KPa" << endl;
		outf << endl << "Design External Pressure				=	" << fixed << setprecision(2) << Pe << "   KPa" << endl;
		outf << endl << "(Fpe * Pe) + live_load					=	" << fixed << setprecision(2) << ((Fpe * Pe) + live_load) << "   KPa" << endl;
		outf << endl << "(Fpe * live_load) + Pe					=	" << fixed << setprecision(2) << ((Fpe * live_load) + Pe) << "   KPa" << endl;
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
	outf.close();
}
