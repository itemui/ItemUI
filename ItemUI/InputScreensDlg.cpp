#include "InputScreensDlg.h"
#include <wx/valnum.h>
#include <wx/msgdlg.h>
#include <wx/wxprec.h>
//#include <wx/pdfdoc.h>
#include <string.h>
#include <fstream>


#include "MaterialSelection.h"
#include "AngleSelection.h"
#include "StiffenerSelection.h"
// #include "include/Tank.h"
//(*InternalHeaders(InputScreensDlg)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

using namespace std;

//declaration of functions defined in source file
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
void call_test_tu_min();
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
void print(std::string);
// void generateReport(std::string);

void PopulateVariables(InputData& inputData);
void ReadVariables(InputData& inputData);
void InitVariables();


bool exists(const std::string& name);

//(*IdInit(InputScreensDlg)
const long InputScreensDlg::ID_STATICTEXT1 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL1 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT2 = wxNewId();
const long InputScreensDlg::ID_CHOICE1 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT3 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL3 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT4 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL4 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT5 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL5 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT6 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL6 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT7 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL7 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT8 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL8 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT9 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL9 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT10 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL10 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT11 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL11 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT12 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL12 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT13 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL13 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT14 = wxNewId();
const long InputScreensDlg::ID_CHOICE2 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT15 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL15 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT16 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL16 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT17 = wxNewId();
const long InputScreensDlg::ID_CHOICE3 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT18 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL18 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT19 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL19 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT20 = wxNewId();
const long InputScreensDlg::ID_CHOICE21 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT21 = wxNewId();
const long InputScreensDlg::ID_CHOICE4 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT22 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL22 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT23 = wxNewId();
const long InputScreensDlg::ID_CHOICE5 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT24 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL24 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT25 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL25 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT26 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL26 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT64 = wxNewId();
const long InputScreensDlg::ID_CHOICE18 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT65 = wxNewId();
const long InputScreensDlg::ID_CHOICE19 = wxNewId();
const long InputScreensDlg::ID_PANEL1 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT27 = wxNewId();
const long InputScreensDlg::ID_CHOICE6 = wxNewId();
const long InputScreensDlg::ID_PANEL3 = wxNewId();
const long InputScreensDlg::ID_PANEL12 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT29 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL17 = wxNewId();
const long InputScreensDlg::ID_PANEL5 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT28 = wxNewId();
const long InputScreensDlg::ID_CHOICE7 = wxNewId();
const long InputScreensDlg::ID_PANEL6 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT30 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL2 = wxNewId();
const long InputScreensDlg::ID_PANEL4 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT31 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL14 = wxNewId();
const long InputScreensDlg::ID_PANEL7 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT32 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL21 = wxNewId();
const long InputScreensDlg::ID_PANEL8 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT33 = wxNewId();
const long InputScreensDlg::ID_CHOICE8 = wxNewId();
const long InputScreensDlg::ID_PANEL9 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT34 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL23 = wxNewId();
const long InputScreensDlg::ID_PANEL10 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT35 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL27 = wxNewId();
const long InputScreensDlg::ID_PANEL11 = wxNewId();
const long InputScreensDlg::ID_BUTTON1 = wxNewId();
const long InputScreensDlg::ID_PANEL2 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT36 = wxNewId();
const long InputScreensDlg::ID_CHOICE9 = wxNewId();
const long InputScreensDlg::ID_PANEL14 = wxNewId();
const long InputScreensDlg::ID_PANEL15 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT37 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL28 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT38 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL29 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT39 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL30 = wxNewId();
const long InputScreensDlg::ID_PANEL16 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT40 = wxNewId();
const long InputScreensDlg::ID_CHOICE10 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT41 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL31 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT42 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL32 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT43 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL33 = wxNewId();
const long InputScreensDlg::ID_PANEL17 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT44 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL34 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT45 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL35 = wxNewId();
const long InputScreensDlg::ID_PANEL18 = wxNewId();
const long InputScreensDlg::ID_BUTTON5 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT46 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL36 = wxNewId();
const long InputScreensDlg::ID_PANEL20 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT47 = wxNewId();
const long InputScreensDlg::ID_CHOICE11 = wxNewId();
const long InputScreensDlg::ID_PANEL21 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT48 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL38 = wxNewId();
const long InputScreensDlg::ID_PANEL22 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT49 = wxNewId();
const long InputScreensDlg::ID_CHOICE12 = wxNewId();
const long InputScreensDlg::ID_PANEL23 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT50 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL40 = wxNewId();
const long InputScreensDlg::ID_PANEL24 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT51 = wxNewId();
const long InputScreensDlg::ID_CHOICE13 = wxNewId();
const long InputScreensDlg::ID_PANEL25 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT52 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL42 = wxNewId();
const long InputScreensDlg::ID_PANEL26 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT53 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL43 = wxNewId();
const long InputScreensDlg::ID_PANEL27 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT54 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL44 = wxNewId();
const long InputScreensDlg::ID_PANEL28 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT55 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL45 = wxNewId();
const long InputScreensDlg::ID_PANEL29 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT56 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL46 = wxNewId();
const long InputScreensDlg::ID_PANEL30 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT57 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL47 = wxNewId();
const long InputScreensDlg::ID_PANEL31 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT58 = wxNewId();
const long InputScreensDlg::ID_CHOICE14 = wxNewId();
const long InputScreensDlg::ID_PANEL19 = wxNewId();
const long InputScreensDlg::ID_PANEL13 = wxNewId();
const long InputScreensDlg::ID_GRID1 = wxNewId();
const long InputScreensDlg::ID_BUTTON2 = wxNewId();
const long InputScreensDlg::ID_BUTTON3 = wxNewId();
const long InputScreensDlg::ID_GRID44 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT91 = wxNewId();
const long InputScreensDlg::ID_PANEL32 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT59 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT60 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT61 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT62 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT63 = wxNewId();
const long InputScreensDlg::ID_CHOICE15 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL37 = wxNewId();
const long InputScreensDlg::ID_CHOICE16 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL39 = wxNewId();
const long InputScreensDlg::ID_CHOICE17 = wxNewId();
const long InputScreensDlg::ID_GRID6 = wxNewId();
const long InputScreensDlg::ID_BUTTON6 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT66 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL41 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT67 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL48 = wxNewId();
const long InputScreensDlg::ID_PANEL33 = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblHeightTransShell = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblT_uniform = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblHMaxWind = wxNewId();
const long InputScreensDlg::ID_STATICTEXT92 = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblNumStiff = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblNumStiffMax = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLTextHeightTransShell = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLTextT_uniform = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLTextHMaxWind = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLTextHMaxPressure = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLTextNumStiff = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLTextNumStiffMax = wxNewId();
const long InputScreensDlg::ID_GRID2 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT89 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT90 = wxNewId();
const long InputScreensDlg::ID_GRID3 = wxNewId();
const long InputScreensDlg::ID_BUTTON4 = wxNewId();
const long InputScreensDlg::ID_PANEL35 = wxNewId();
const long InputScreensDlg::ID_GRID4 = wxNewId();
const long InputScreensDlg::ID_GRID5 = wxNewId();
const long InputScreensDlg::ID_BUTTON7 = wxNewId();
const long InputScreensDlg::ID_PANEL37 = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblRoofTypeUser = wxNewId();
const long InputScreensDlg::ID_CHOICEroofTypeUser = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblRRoof = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblFrangible = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblLiveLoad = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblBalSL = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblUnBalSL = wxNewId();
const long InputScreensDlg::ID_STATICTEXTtypeFR = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblMaterialRoof = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblJEff = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblThickness = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL61 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtMaxSpace1 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtMaxSpace2 = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblWeightNozzle = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblWeightFR = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblSlopeRoof = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblDomeRadius = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblMaxSpace = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblMaxSPacePeri = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtRRoof = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblRoofTypeAdopted = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtRoofTypeAdopted = wxNewId();
const long InputScreensDlg::ID_CHOICEFrangible = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtLiveLoad = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtBalancedSL = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtUnBalancedSL = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtDomeRadius = wxNewId();
const long InputScreensDlg::ID_STATICTEXTwtGeodesicRoof = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLWtGeodesicRoof = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtMaterialRoof = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtWeightNozzle = wxNewId();
const long InputScreensDlg::ID_CHOICEFR = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtWeightFloatingRoof = wxNewId();
const long InputScreensDlg::ID_CHOICE20 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT68 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL20 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL49 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT69 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT70 = wxNewId();
const long InputScreensDlg::ID_GAUGE1 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL52 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT72 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRL50 = wxNewId();
const long InputScreensDlg::ID_BUTTON9 = wxNewId();
const long InputScreensDlg::ID_PANEL = wxNewId();
const long InputScreensDlg::ID_CHOICEcmbTypeCR = wxNewId();
const long InputScreensDlg::ID_STATICBITMAP = wxNewId();
const long InputScreensDlg::ID_STATICTEXTud = wxNewId();
const long InputScreensDlg::ID_STATICTEXT88req = wxNewId();
const long InputScreensDlg::ID_STATICTEXTaval = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtCrossSecInternalPressureReq = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtCrossSecExternalPressureReq = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtMIExternalPressureReq = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtCrossSecInternalPressureAvail = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtCrossSecExternalPressureAvail = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtMIExternalPressureAvail = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblCrossInt = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblCrossExt = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblMIExt = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblTypeCR = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblThick = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblWidth = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblProj = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtCRSize1 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtCRSize2 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtTbar = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtWBar = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtLBar = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtTShell = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtWShell = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblUser1 = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblUser2 = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblUser3 = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblUser4 = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblMaterialCR = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtCRMaterial0 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtCRMaterial2 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtCRMaterial1 = wxNewId();
const long InputScreensDlg::ID_STATICTEXT88 = wxNewId();
const long InputScreensDlg::ID_CHOICEcmbTypeCRAD = wxNewId();
const long InputScreensDlg::ID_TCRAD = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblThickNessAD = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblWidthAD = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblProjAD = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblAD1 = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblAD2 = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblAD3 = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblAD4 = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtTypeCR1AD = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtTypeCR2AD = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtTBarAD = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtWBarAD = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtLBarAD = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtTShellAD = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLWShell = wxNewId();
const long InputScreensDlg::ID_PANEL34 = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblThicknessBottomPlate = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblReqAnnular = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblThicknessAnnularPlate = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblWidthAnnularPlate = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblReqAnchorage = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblNumAnchorBolts = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblNominalBoltDia = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblCorrosionAllowance = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblYeildStrengthBoltMaterial = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtThicknessBottomPlate = wxNewId();
const long InputScreensDlg::ID_CHOICEcmbReqAnnular = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtThicknessAnnularPlate = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtWidthAnnularPlate = wxNewId();
const long InputScreensDlg::ID_CHOICEcmbReqAnchorage = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtNumAnchorBolts = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtNominalBoltDia = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtCorrosionAllowance = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtYeildStrengthBoltMaterial = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblPadThickness = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblSpacingBetweenGussets = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblTopPlateLengthShell = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblTopPlateLengthRadial = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblTopPlateThickness = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblBoltEccentricity = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblAnchorChairHeight = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblVerticalPlateThickness = wxNewId();
const long InputScreensDlg::ID_STATICTEXTlblAvgVerticalPlateWidth = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtPadThickness = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtSpacingBetweenGussets = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtTopPlateLengthShell = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtTopPlateLengthRadial = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtTopPlateThickness = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtBoltEccentricity = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtAnchorChairHeight = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtVerticalPlateThickness = wxNewId();
const long InputScreensDlg::ID_TEXTCTRLtxtAvgVerticalPlateWidth = wxNewId();
const long InputScreensDlg::ID_PANEL36 = wxNewId();
const long InputScreensDlg::ID_NOTEBOOK1 = wxNewId();
const long InputScreensDlg::ID_BUTTON8 = wxNewId();
//*)

BEGIN_EVENT_TABLE(InputScreensDlg,wxDialog)
	//(*EventTable(InputScreensDlg)
	//*)
END_EVENT_TABLE()

InputScreensDlg::InputScreensDlg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(InputScreensDlg)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizerASCESpectralAccelOneSec;
	wxBoxSizer* BoxSizerASCESpectralAccelShort;
	wxBoxSizer* BoxSizerAccelBaseSiteCoeff;
	wxBoxSizer* BoxSizerCodeWindLoad;
	wxBoxSizer* BoxSizerCoeffAdjust;
	wxBoxSizer* BoxSizerControls1;
	wxBoxSizer* BoxSizerControls2;
	wxBoxSizer* BoxSizerDesignWindVel;
	wxBoxSizer* BoxSizerDirectionFactor;
	wxBoxSizer* BoxSizerDummy;
	wxBoxSizer* BoxSizerDummySeismic;
	wxBoxSizer* BoxSizerExposureCatgory;
	wxBoxSizer* BoxSizerFixedCtrls;
	wxBoxSizer* BoxSizerGovByASCERules;
	wxBoxSizer* BoxSizerGrpASCE;
	wxBoxSizer* BoxSizerGrpPeakGrndAcce;
	wxBoxSizer* BoxSizerGrpPeakGrndAccel;
	wxBoxSizer* BoxSizerGrpUBC;
	wxBoxSizer* BoxSizerGustDesignWindSpeed;
	wxBoxSizer* BoxSizerGustFactor;
	wxBoxSizer* BoxSizerImportanceFactor;
	wxBoxSizer* BoxSizerInputScreen_1;
	wxBoxSizer* BoxSizerPGASpectralAccelOneSec;
	wxBoxSizer* BoxSizerPGASpectralAccelShort;
	wxBoxSizer* BoxSizerPeakGroundAccel;
	wxBoxSizer* BoxSizerPnlAccelBaseSiteCoeff;
	wxBoxSizer* BoxSizerPnlCodeWindLoad;
	wxBoxSizer* BoxSizerPnlCoeffAdjust;
	wxBoxSizer* BoxSizerPnlDesignWindVel;
	wxBoxSizer* BoxSizerPnlDirectionFactor;
	wxBoxSizer* BoxSizerPnlExposureCatgory;
	wxBoxSizer* BoxSizerPnlGovByASCERules;
	wxBoxSizer* BoxSizerPnlGrpASCE;
	wxBoxSizer* BoxSizerPnlGrpUBC;
	wxBoxSizer* BoxSizerPnlGustDesignWindSpeed;
	wxBoxSizer* BoxSizerPnlGustFactor;
	wxBoxSizer* BoxSizerPnlImportanceFactor;
	wxBoxSizer* BoxSizerPnlSD1QFvS1;
	wxBoxSizer* BoxSizerPnlSDSQFaSs;
	wxBoxSizer* BoxSizerPnlSeismicDesignChoice;
	wxBoxSizer* BoxSizerPnlSeismicImportanceFactor;
	wxBoxSizer* BoxSizerPnlSeismicScaleFactor;
	wxBoxSizer* BoxSizerPnlSeismicSiteClass;
	wxBoxSizer* BoxSizerPnlSeismicUserGrp;
	wxBoxSizer* BoxSizerPnlSpectralAccelTimePeriod0;
	wxBoxSizer* BoxSizerPnlTopographicFactor;
	wxBoxSizer* BoxSizerPnlTransitionLongGrnd;
	wxBoxSizer* BoxSizerPnlVelBasedSiteCoeff;
	wxBoxSizer* BoxSizerPnlVelPressureExpCoeff;
	wxBoxSizer* BoxSizerPnlVertSeismicEffect;
	wxBoxSizer* BoxSizerSD1QFvS1;
	wxBoxSizer* BoxSizerSDSQFaSs;
	wxBoxSizer* BoxSizerSeismicDesignChoice;
	wxBoxSizer* BoxSizerSeismicImportanceFactor;
	wxBoxSizer* BoxSizerSeismicScaleFactor;
	wxBoxSizer* BoxSizerSeismicSiteClass;
	wxBoxSizer* BoxSizerSeismicUserGrp;
	wxBoxSizer* BoxSizerSpectralAccelTimePeriod0;
	wxBoxSizer* BoxSizerTopographicFactor;
	wxBoxSizer* BoxSizerTransitionLongGrnd;
	wxBoxSizer* BoxSizerUBCPeakGrndAccel;
	wxBoxSizer* BoxSizerUBCSpectralAccelOneSec;
	wxBoxSizer* BoxSizerUBCSpectralAccelShort;
	wxBoxSizer* BoxSizerUBCZoneNo;
	wxBoxSizer* BoxSizerVelBasedSiteCoeff;
	wxBoxSizer* BoxSizerVelPressureExpCoeff;
	wxBoxSizer* BoxSizerVertSeismicEffect;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
	BoxSizerMain = new wxBoxSizer(wxVERTICAL);
	BoxSizerControlsMain = new wxBoxSizer(wxHORIZONTAL);
	NotebookInputScreen_1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(1500,800), 0, _T("ID_NOTEBOOK1"));
	pnlInputScreen_1 = new wxPanel(NotebookInputScreen_1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizerInputScreen_1 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizerControls1 = new wxBoxSizer(wxVERTICAL);
	BoxSizerDiaTank = new wxBoxSizer(wxHORIZONTAL);
	lblDiaTank = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT1, _("Diameter of Tank  (M) *"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizerDiaTank->Add(lblDiaTank, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtDiaTank = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	txtDiaTank->SetMinSize(wxSize(240,-1));
	txtDiaTank->SetMaxSize(wxSize(240,-1));
	txtDiaTank->SetBackgroundColour(wxColour(100,255,200));
	BoxSizerDiaTank->Add(txtDiaTank, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls1->Add(BoxSizerDiaTank, 1, wxALL|wxALIGN_RIGHT, 5);
	BoxSizerChoiceDiaType = new wxBoxSizer(wxHORIZONTAL);
	lblDiaType = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT2, _("ID / Nominal DIA\?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizerChoiceDiaType->Add(lblDiaType, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cmbChoiceDiaType = new wxChoice(pnlInputScreen_1, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	cmbChoiceDiaType->SetSelection( cmbChoiceDiaType->Append(_("ID")) );
	cmbChoiceDiaType->Append(_("NOMINAL DIAMETER"));
	cmbChoiceDiaType->SetMinSize(wxSize(240,-1));
	cmbChoiceDiaType->SetMaxSize(wxSize(240,-1));
	cmbChoiceDiaType->SetBackgroundColour(wxColour(100,255,200));
	BoxSizerChoiceDiaType->Add(cmbChoiceDiaType, 0, wxALL|wxALIGN_TOP, 5);
	BoxSizerControls1->Add(BoxSizerChoiceDiaType, 1, wxALL|wxALIGN_RIGHT, 5);
	BoxSizerTankHeight = new wxBoxSizer(wxHORIZONTAL);
	lblHTankHeight = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT3, _("Height of Tank (M)*"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizerTankHeight->Add(lblHTankHeight, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtTankHeight = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	txtTankHeight->SetMinSize(wxSize(240,-1));
	txtTankHeight->SetMaxSize(wxSize(240,-1));
	BoxSizerTankHeight->Add(txtTankHeight, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls1->Add(BoxSizerTankHeight, 0, wxALL|wxALIGN_RIGHT, 5);
	BoxSizerDesignPrdLvl = new wxBoxSizer(wxHORIZONTAL);
	lblDesignPrdLvl = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT4, _("Design Product level (M)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizerDesignPrdLvl->Add(lblDesignPrdLvl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtDesignPrdLvl = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	txtDesignPrdLvl->SetMinSize(wxSize(240,-1));
	txtDesignPrdLvl->SetMaxSize(wxSize(240,-1));
	txtDesignPrdLvl->SetBackgroundColour(wxColour("PINK"));
	BoxSizerDesignPrdLvl->Add(txtDesignPrdLvl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls1->Add(BoxSizerDesignPrdLvl, 1, wxALL|wxALIGN_RIGHT, 5);
	BoxSizerTestWaterLvl = new wxBoxSizer(wxHORIZONTAL);
	lblTestWaterLvl = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT5, _("Test water level (M)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizerTestWaterLvl->Add(lblTestWaterLvl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtTestWaterLvl = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	txtTestWaterLvl->SetMinSize(wxSize(240,-1));
	txtTestWaterLvl->SetMaxSize(wxSize(240,-1));
	txtTestWaterLvl->SetBackgroundColour(wxColour("PINK"));
	BoxSizerTestWaterLvl->Add(txtTestWaterLvl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls1->Add(BoxSizerTestWaterLvl, 1, wxALL|wxALIGN_RIGHT, 5);
	BoxSizerNormalLiqdLvl = new wxBoxSizer(wxHORIZONTAL);
	lblNormalLiqdLvl = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT6, _("Normal liquid level (M)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	BoxSizerNormalLiqdLvl->Add(lblNormalLiqdLvl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtNormalLiqdLvl = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	txtNormalLiqdLvl->SetMinSize(wxSize(240,-1));
	txtNormalLiqdLvl->SetMaxSize(wxSize(240,-1));
	txtNormalLiqdLvl->SetBackgroundColour(wxColour("PINK"));
	BoxSizerNormalLiqdLvl->Add(txtNormalLiqdLvl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls1->Add(BoxSizerNormalLiqdLvl, 1, wxALL|wxALIGN_RIGHT, 5);
	BoxSizerLiqdLvlSesDesign = new wxBoxSizer(wxHORIZONTAL);
	lblLiqdLvlSesDesign = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT7, _("Liquid level for seismic design (M)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	BoxSizerLiqdLvlSesDesign->Add(lblLiqdLvlSesDesign, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtLiqdLvlSesDesign = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	txtLiqdLvlSesDesign->SetMinSize(wxSize(240,-1));
	txtLiqdLvlSesDesign->SetMaxSize(wxSize(240,-1));
	txtLiqdLvlSesDesign->SetBackgroundColour(wxColour("PINK"));
	BoxSizerLiqdLvlSesDesign->Add(txtLiqdLvlSesDesign, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls1->Add(BoxSizerLiqdLvlSesDesign, 1, wxALL|wxALIGN_RIGHT, 5);
	BoxSizerSpecificGrvtyStrdPrd = new wxBoxSizer(wxHORIZONTAL);
	lblSpecificGrvtyStrdPrd = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT8, _("Specific gravity of stored product*"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	BoxSizerSpecificGrvtyStrdPrd->Add(lblSpecificGrvtyStrdPrd, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtSpecificGrvtyStrdPrd = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	txtSpecificGrvtyStrdPrd->SetMinSize(wxSize(240,-1));
	txtSpecificGrvtyStrdPrd->SetMaxSize(wxSize(240,-1));
	txtSpecificGrvtyStrdPrd->SetBackgroundColour(wxColour(100,255,200));
	BoxSizerSpecificGrvtyStrdPrd->Add(txtSpecificGrvtyStrdPrd, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls1->Add(BoxSizerSpecificGrvtyStrdPrd, 1, wxALL|wxALIGN_RIGHT, 5);
	BoxSizerSpecificGrvtyHydroTest = new wxBoxSizer(wxHORIZONTAL);
	lblSpecificGrvtyHydroTest = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT9, _("Specific gravity of water used for hydro test."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	BoxSizerSpecificGrvtyHydroTest->Add(lblSpecificGrvtyHydroTest, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtSpecificGrvtyHydroTest = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL9, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
	txtSpecificGrvtyHydroTest->SetMinSize(wxSize(240,-1));
	txtSpecificGrvtyHydroTest->SetMaxSize(wxSize(240,-1));
	txtSpecificGrvtyHydroTest->SetBackgroundColour(wxColour("PINK"));
	BoxSizerSpecificGrvtyHydroTest->Add(txtSpecificGrvtyHydroTest, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls1->Add(BoxSizerSpecificGrvtyHydroTest, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxFIXED_MINSIZE, 5);
	BoxSizerDesignTemp = new wxBoxSizer(wxHORIZONTAL);
	lblDesignTemp = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT10, _("Design Temperature (Deg.C)*"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	BoxSizerDesignTemp->Add(lblDesignTemp, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtDesignTemp = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL10, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
	txtDesignTemp->SetMinSize(wxSize(240,-1));
	txtDesignTemp->SetMaxSize(wxSize(240,-1));
	txtDesignTemp->SetBackgroundColour(wxColour(100,255,200));
	BoxSizerDesignTemp->Add(txtDesignTemp, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls1->Add(BoxSizerDesignTemp, 1, wxALL|wxALIGN_RIGHT, 5);
	BoxSizerMinDesignMetalTemp = new wxBoxSizer(wxHORIZONTAL);
	lblMinDesignMetalTemp = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT11, _("Minimum design metal temperature (Deg.C)*"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	BoxSizerMinDesignMetalTemp->Add(lblMinDesignMetalTemp, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtMinDesignMetalTemp = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL11, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
	txtMinDesignMetalTemp->SetMinSize(wxSize(240,-1));
	txtMinDesignMetalTemp->SetMaxSize(wxSize(240,-1));
	txtMinDesignMetalTemp->SetBackgroundColour(wxColour(100,255,200));
	BoxSizerMinDesignMetalTemp->Add(txtMinDesignMetalTemp, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls1->Add(BoxSizerMinDesignMetalTemp, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerDesignInternalPressure = new wxBoxSizer(wxHORIZONTAL);
	lblDesignInternalPressure = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT12, _("Design internal pressure (kPa)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	BoxSizerDesignInternalPressure->Add(lblDesignInternalPressure, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtDesignInternalPressure = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL12, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
	txtDesignInternalPressure->SetMinSize(wxSize(240,-1));
	txtDesignInternalPressure->SetMaxSize(wxSize(240,-1));
	txtDesignInternalPressure->SetBackgroundColour(wxColour("PINK"));
	BoxSizerDesignInternalPressure->Add(txtDesignInternalPressure, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls1->Add(BoxSizerDesignInternalPressure, 1, wxALL|wxALIGN_RIGHT, 5);
	BoxSizerPressureCmbFact = new wxBoxSizer(wxHORIZONTAL);
	lblPressureCmbFact = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT13, _("Pressure combination Factor (Fp)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	BoxSizerPressureCmbFact->Add(lblPressureCmbFact, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtPressureCmbFact = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL13, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL13"));
	txtPressureCmbFact->SetMinSize(wxSize(240,-1));
	txtPressureCmbFact->SetMaxSize(wxSize(240,-1));
	txtPressureCmbFact->SetBackgroundColour(wxColour("PINK"));
	BoxSizerPressureCmbFact->Add(txtPressureCmbFact, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls1->Add(BoxSizerPressureCmbFact, 1, wxALL|wxALIGN_RIGHT, 5);
	BoxSizerInputScreen_1->Add(BoxSizerControls1, 0, wxALL, 5);
	BoxSizerControls2 = new wxBoxSizer(wxVERTICAL);
	BoxSizerChoiceAddDesignLqdHead = new wxBoxSizer(wxHORIZONTAL);
	lblAddDesignLqdHead = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT14, _("Add (P/9.8G) to design liquid head\?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	BoxSizerChoiceAddDesignLqdHead->Add(lblAddDesignLqdHead, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cmbChoiceAddDesignLqdHead = new wxChoice(pnlInputScreen_1, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	cmbChoiceAddDesignLqdHead->Append(_("NO"));
	cmbChoiceAddDesignLqdHead->Append(_("YES"));
	cmbChoiceAddDesignLqdHead->SetMinSize(wxSize(240,-1));
	cmbChoiceAddDesignLqdHead->SetMaxSize(wxSize(240,-1));
	cmbChoiceAddDesignLqdHead->Disable();
	BoxSizerChoiceAddDesignLqdHead->Add(cmbChoiceAddDesignLqdHead, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerChoiceAddDesignLqdHead->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls2->Add(BoxSizerChoiceAddDesignLqdHead, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerDesignExtPressure = new wxBoxSizer(wxHORIZONTAL);
	lblDesignExtPressure = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT15, _("Design external pressure (kPa)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
	BoxSizerDesignExtPressure->Add(lblDesignExtPressure, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtDesignExtPressure = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL15, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
	txtDesignExtPressure->SetMinSize(wxSize(240,-1));
	txtDesignExtPressure->SetMaxSize(wxSize(240,-1));
	txtDesignExtPressure->SetBackgroundColour(wxColour("PINK"));
	BoxSizerDesignExtPressure->Add(txtDesignExtPressure, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerDesignExtPressure->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls2->Add(BoxSizerDesignExtPressure, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerExtPressureCmbFactor = new wxBoxSizer(wxHORIZONTAL);
	lblExtPressureCmbFactor = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT16, _("External Pressure combination Factor"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
	BoxSizerExtPressureCmbFactor->Add(lblExtPressureCmbFactor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtExtPressureCmbFactor = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL16, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL16"));
	txtExtPressureCmbFactor->SetMinSize(wxSize(240,-1));
	txtExtPressureCmbFactor->SetMaxSize(wxSize(240,-1));
	txtExtPressureCmbFactor->SetBackgroundColour(wxColour("PINK"));
	BoxSizerExtPressureCmbFactor->Add(txtExtPressureCmbFactor, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerExtPressureCmbFactor->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls2->Add(BoxSizerExtPressureCmbFactor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerChoiceAppendixShellDesign = new wxBoxSizer(wxHORIZONTAL);
	lblAppendixShellDesign = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT17, _("Applicable Appendix for shell design: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
	BoxSizerChoiceAppendixShellDesign->Add(lblAppendixShellDesign, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cmbChoiceAppendixShellDesign = new wxChoice(pnlInputScreen_1, ID_CHOICE3, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
	cmbChoiceAppendixShellDesign->Append(_("Appendix-A"));
	cmbChoiceAppendixShellDesign->Append(_("Appendix-J"));
	cmbChoiceAppendixShellDesign->Append(_("Appendix-S"));
	cmbChoiceAppendixShellDesign->Append(_("Appendix-SC"));
	cmbChoiceAppendixShellDesign->Append(_("Appendix-X"));
	cmbChoiceAppendixShellDesign->Append(_("None"));
	cmbChoiceAppendixShellDesign->SetMinSize(wxSize(240,-1));
	cmbChoiceAppendixShellDesign->SetMaxSize(wxSize(240,-1));
	BoxSizerChoiceAppendixShellDesign->Add(cmbChoiceAppendixShellDesign, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerChoiceAppendixShellDesign->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls2->Add(BoxSizerChoiceAppendixShellDesign, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerCourseWidthFirstShellBtm = new wxBoxSizer(wxHORIZONTAL);
	lblCourseWidthFirstShellBtm = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT18, _("Course Width for First Shell Course from bottom (M)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
	BoxSizerCourseWidthFirstShellBtm->Add(lblCourseWidthFirstShellBtm, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtCourseWidthFirstShellBtm = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL18, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL18"));
	txtCourseWidthFirstShellBtm->SetMinSize(wxSize(240,-1));
	txtCourseWidthFirstShellBtm->SetMaxSize(wxSize(240,-1));
	txtCourseWidthFirstShellBtm->SetBackgroundColour(wxColour(100,255,200));
	BoxSizerCourseWidthFirstShellBtm->Add(txtCourseWidthFirstShellBtm, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerCourseWidthFirstShellBtm->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls2->Add(BoxSizerCourseWidthFirstShellBtm, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerCorrosionAllowanceFirstShllBtm = new wxBoxSizer(wxHORIZONTAL);
	lblCorrosionAllowanceFirstShllBtm = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT19, _("Corrosion Allowance of First Shell Course from bottom (mm)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
	BoxSizerCorrosionAllowanceFirstShllBtm->Add(lblCorrosionAllowanceFirstShllBtm, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtCorrosionAllowanceFirstShllBtm = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL19, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL19"));
	txtCorrosionAllowanceFirstShllBtm->SetMinSize(wxSize(240,-1));
	txtCorrosionAllowanceFirstShllBtm->SetMaxSize(wxSize(240,-1));
	txtCorrosionAllowanceFirstShllBtm->SetBackgroundColour(wxColour("PINK"));
	BoxSizerCorrosionAllowanceFirstShllBtm->Add(txtCorrosionAllowanceFirstShllBtm, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerCorrosionAllowanceFirstShllBtm->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls2->Add(BoxSizerCorrosionAllowanceFirstShllBtm, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerJointEffcncyShellVertSeams = new wxBoxSizer(wxHORIZONTAL);
	lblJointEffcncyShellVertSeams = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT20, _("Joint Efficiency for shell vertical seams "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
	BoxSizerJointEffcncyShellVertSeams->Add(lblJointEffcncyShellVertSeams, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cmbJointEffcncyShellVertSeams = new wxChoice(pnlInputScreen_1, ID_CHOICE21, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE21"));
	cmbJointEffcncyShellVertSeams->Append(_("0.7"));
	cmbJointEffcncyShellVertSeams->Append(_("0.85"));
	cmbJointEffcncyShellVertSeams->Append(_("1.0"));
	cmbJointEffcncyShellVertSeams->SetMinSize(wxSize(240,-1));
	cmbJointEffcncyShellVertSeams->SetMaxSize(wxSize(240,-1));
	BoxSizerJointEffcncyShellVertSeams->Add(cmbJointEffcncyShellVertSeams, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerJointEffcncyShellVertSeams->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls2->Add(BoxSizerJointEffcncyShellVertSeams, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerChoiceMethodShellThickCalc = new wxBoxSizer(wxHORIZONTAL);
	lblMethodShellThickCalc = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT21, _("Method for Shell Thickness Calculation"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
	BoxSizerChoiceMethodShellThickCalc->Add(lblMethodShellThickCalc, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cmbChoiceMethodShellThickCalc = new wxChoice(pnlInputScreen_1, ID_CHOICE4, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
	cmbChoiceMethodShellThickCalc->Append(_("One Foot"));
	cmbChoiceMethodShellThickCalc->Append(_("Variable Design Point"));
	cmbChoiceMethodShellThickCalc->SetMinSize(wxSize(240,-1));
	cmbChoiceMethodShellThickCalc->SetMaxSize(wxSize(240,-1));
	BoxSizerChoiceMethodShellThickCalc->Add(cmbChoiceMethodShellThickCalc, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerChoiceMethodShellThickCalc->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls2->Add(BoxSizerChoiceMethodShellThickCalc, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerCorrosionAllowanceBtmPlate = new wxBoxSizer(wxHORIZONTAL);
	lblCorrosionAllowanceBtmPlate = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT22, _("Corrosion Allowance of Bottom Plate (mm)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
	BoxSizerCorrosionAllowanceBtmPlate->Add(lblCorrosionAllowanceBtmPlate, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtCorrosionAllowanceBtmPlate = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL22, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL22"));
	txtCorrosionAllowanceBtmPlate->SetMinSize(wxSize(240,-1));
	txtCorrosionAllowanceBtmPlate->SetMaxSize(wxSize(240,-1));
	txtCorrosionAllowanceBtmPlate->SetBackgroundColour(wxColour("PINK"));
	BoxSizerCorrosionAllowanceBtmPlate->Add(txtCorrosionAllowanceBtmPlate, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerCorrosionAllowanceBtmPlate->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls2->Add(BoxSizerCorrosionAllowanceBtmPlate, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerChoiceTypeFixedRoof = new wxBoxSizer(wxHORIZONTAL);
	lblTypeFixedRoof = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT23, _("Type of Fixed Roof"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
	BoxSizerChoiceTypeFixedRoof->Add(lblTypeFixedRoof, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cmbChoiceTypeFixedRoof = new wxChoice(pnlInputScreen_1, ID_CHOICE5, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
	cmbChoiceTypeFixedRoof->Append(_("SELF SUPPORTING CONE ROOF"));
	cmbChoiceTypeFixedRoof->Append(_("SELF SUPPORTING DOME/UMBRELLA ROOF"));
	cmbChoiceTypeFixedRoof->Append(_("SUPPORTED CONE ROOF"));
	cmbChoiceTypeFixedRoof->Append(_("SUPPORTED DOME/UMBRELLA ROOF"));
	cmbChoiceTypeFixedRoof->Append(_("STIFFENED CONE ROOF"));
	cmbChoiceTypeFixedRoof->Append(_("STIFFENED DOME ROOF"));
	cmbChoiceTypeFixedRoof->Append(_("GEODESIC ROOF"));
	cmbChoiceTypeFixedRoof->Append(_("NONE"));
	cmbChoiceTypeFixedRoof->SetMinSize(wxSize(240,-1));
	cmbChoiceTypeFixedRoof->SetMaxSize(wxSize(240,0));
	BoxSizerChoiceTypeFixedRoof->Add(cmbChoiceTypeFixedRoof, 0, wxALL|wxALIGN_TOP, 5);
	BoxSizerChoiceTypeFixedRoof->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls2->Add(BoxSizerChoiceTypeFixedRoof, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerCorrosionAllowanceFixedRoof = new wxBoxSizer(wxHORIZONTAL);
	lblCorrosionAllowanceFixedRoof = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT24, _("Corrosion Allowance of Fixed Roof (mm)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
	BoxSizerCorrosionAllowanceFixedRoof->Add(lblCorrosionAllowanceFixedRoof, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtCorrosionAllowanceFixedRoof = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL24, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL24"));
	txtCorrosionAllowanceFixedRoof->SetMinSize(wxSize(240,-1));
	txtCorrosionAllowanceFixedRoof->SetMaxSize(wxSize(240,-1));
	txtCorrosionAllowanceFixedRoof->SetBackgroundColour(wxColour("PINK"));
	BoxSizerCorrosionAllowanceFixedRoof->Add(txtCorrosionAllowanceFixedRoof, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerCorrosionAllowanceFixedRoof->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls2->Add(BoxSizerCorrosionAllowanceFixedRoof, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerWtSpiralStairway = new wxBoxSizer(wxHORIZONTAL);
	lblWtSpiralStairway = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT25, _("Weight of Spiral Stairway (Kg)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
	BoxSizerWtSpiralStairway->Add(lblWtSpiralStairway, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtWtSpiralStairway = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL25, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL25"));
	txtWtSpiralStairway->SetMinSize(wxSize(240,-1));
	txtWtSpiralStairway->SetMaxSize(wxSize(240,-1));
	txtWtSpiralStairway->SetBackgroundColour(wxColour(100,255,200));
	BoxSizerWtSpiralStairway->Add(txtWtSpiralStairway, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerWtSpiralStairway->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls2->Add(BoxSizerWtSpiralStairway, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
	BoxSizerIncWtShellNozzleOtherShellApptnces = new wxBoxSizer(wxHORIZONTAL);
	lblIncWtShellNozzleOtherShellApptnces = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT26, _("                                % increase in weight For Misc Items"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT26"));
	BoxSizerIncWtShellNozzleOtherShellApptnces->Add(lblIncWtShellNozzleOtherShellApptnces, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtIncWtShellNozzleOtherShellApptnces = new wxTextCtrl(pnlInputScreen_1, ID_TEXTCTRL26, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL26"));
	txtIncWtShellNozzleOtherShellApptnces->SetMinSize(wxSize(240,-1));
	txtIncWtShellNozzleOtherShellApptnces->SetMaxSize(wxSize(240,-1));
	txtIncWtShellNozzleOtherShellApptnces->SetBackgroundColour(wxColour(100,255,200));
	BoxSizerIncWtShellNozzleOtherShellApptnces->Add(txtIncWtShellNozzleOtherShellApptnces, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerIncWtShellNozzleOtherShellApptnces->Add(266,20,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls2->Add(BoxSizerIncWtShellNozzleOtherShellApptnces, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT64, _("                                    Rounding-up of thickness: mm"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT64"));
	BoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CmbRoundUpTo = new wxChoice(pnlInputScreen_1, ID_CHOICE18, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE18"));
	CmbRoundUpTo->Append(_("1 mm"));
	CmbRoundUpTo->SetSelection( CmbRoundUpTo->Append(_("0.1 mm")) );
	CmbRoundUpTo->SetMinSize(wxSize(240,-1));
	CmbRoundUpTo->SetMaxSize(wxSize(240,-1));
	BoxSizer1->Add(CmbRoundUpTo, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls2->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText5 = new wxStaticText(pnlInputScreen_1, ID_STATICTEXT65, _("              Use Corroded thickness for stiffener design"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT65"));
	BoxSizer2->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cmbOptionStfr = new wxChoice(pnlInputScreen_1, ID_CHOICE19, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE19"));
	cmbOptionStfr->Append(_("No"));
	cmbOptionStfr->SetSelection( cmbOptionStfr->Append(_("Yes")) );
	cmbOptionStfr->SetMinSize(wxSize(240,-1));
	cmbOptionStfr->SetMaxSize(wxSize(240,-1));
	BoxSizer2->Add(cmbOptionStfr, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerControls2->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerInputScreen_1->Add(BoxSizerControls2, 0, wxALL, 5);
	pnlInputScreen_1->SetSizer(BoxSizerInputScreen_1);
	BoxSizerInputScreen_1->Fit(pnlInputScreen_1);
	BoxSizerInputScreen_1->SetSizeHints(pnlInputScreen_1);
	pnlWindData = new wxPanel(NotebookInputScreen_1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	BoxSizerWindDataMain = new wxBoxSizer(wxVERTICAL);
	BoxSizerCodeWindLoad = new wxBoxSizer(wxVERTICAL);
	pnlCodeWindLoad = new wxPanel(pnlWindData, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	BoxSizerPnlCodeWindLoad = new wxBoxSizer(wxHORIZONTAL);
	lblCodeWindLoad = new wxStaticText(pnlCodeWindLoad, ID_STATICTEXT27, _("Code for Wind Load"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT27"));
	BoxSizerPnlCodeWindLoad->Add(lblCodeWindLoad, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cmbChoiceCodeWindLoad = new wxChoice(pnlCodeWindLoad, ID_CHOICE6, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE6"));
	cmbChoiceCodeWindLoad->Append(_("ASCE 7-05"));
	cmbChoiceCodeWindLoad->Append(_("ASCE 7-10"));
	cmbChoiceCodeWindLoad->Append(_("User Defined Wind Velocity"));
	cmbChoiceCodeWindLoad->SetMinSize(wxSize(240,-1));
	cmbChoiceCodeWindLoad->SetMaxSize(wxSize(240,-1));
	BoxSizerPnlCodeWindLoad->Add(cmbChoiceCodeWindLoad, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlCodeWindLoad->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlCodeWindLoad->SetSizer(BoxSizerPnlCodeWindLoad);
	BoxSizerPnlCodeWindLoad->Fit(pnlCodeWindLoad);
	BoxSizerPnlCodeWindLoad->SetSizeHints(pnlCodeWindLoad);
	BoxSizerCodeWindLoad->Add(pnlCodeWindLoad, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerWindDataMain->Add(BoxSizerCodeWindLoad, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerDummy = new wxBoxSizer(wxHORIZONTAL);
	pnlDummy = new wxPanel(pnlWindData, ID_PANEL12, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL12"));
	BoxSizerDummy->Add(pnlDummy, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerWindDataMain->Add(BoxSizerDummy, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerGustDesignWindSpeed = new wxBoxSizer(wxHORIZONTAL);
	pnlGustDesignWindSpeed = new wxPanel(pnlWindData, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL5"));
	BoxSizerPnlGustDesignWindSpeed = new wxBoxSizer(wxHORIZONTAL);
	lblGustDesignWindSpeed = new wxStaticText(pnlGustDesignWindSpeed, ID_STATICTEXT29, _("3 Second Gust Design Wind Speed  (m / sec)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT29"));
	BoxSizerPnlGustDesignWindSpeed->Add(lblGustDesignWindSpeed, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtGustDesignWindSpeed = new wxTextCtrl(pnlGustDesignWindSpeed, ID_TEXTCTRL17, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL17"));
	txtGustDesignWindSpeed->SetMinSize(wxSize(240,-1));
	txtGustDesignWindSpeed->SetMaxSize(wxSize(240,-1));
	txtGustDesignWindSpeed->SetBackgroundColour(wxColour(100,255,200));
	BoxSizerPnlGustDesignWindSpeed->Add(txtGustDesignWindSpeed, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlGustDesignWindSpeed->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlGustDesignWindSpeed->SetSizer(BoxSizerPnlGustDesignWindSpeed);
	BoxSizerPnlGustDesignWindSpeed->Fit(pnlGustDesignWindSpeed);
	BoxSizerPnlGustDesignWindSpeed->SetSizeHints(pnlGustDesignWindSpeed);
	BoxSizerGustDesignWindSpeed->Add(pnlGustDesignWindSpeed, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerWindDataMain->Add(BoxSizerGustDesignWindSpeed, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerExposureCatgory = new wxBoxSizer(wxHORIZONTAL);
	pnlExposureCatgory = new wxPanel(pnlWindData, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
	BoxSizerPnlExposureCatgory = new wxBoxSizer(wxHORIZONTAL);
	lblExposureCatgory = new wxStaticText(pnlExposureCatgory, ID_STATICTEXT28, _("Exposure Category"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT28"));
	BoxSizerPnlExposureCatgory->Add(lblExposureCatgory, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cmbChoiceExposureCatgory = new wxChoice(pnlExposureCatgory, ID_CHOICE7, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE7"));
	cmbChoiceExposureCatgory->Append(_("B"));
	cmbChoiceExposureCatgory->Append(_("C"));
	cmbChoiceExposureCatgory->Append(_("D"));
	cmbChoiceExposureCatgory->SetMinSize(wxSize(240,-1));
	cmbChoiceExposureCatgory->SetMaxSize(wxSize(240,-1));
	BoxSizerPnlExposureCatgory->Add(cmbChoiceExposureCatgory, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlExposureCatgory->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlExposureCatgory->SetSizer(BoxSizerPnlExposureCatgory);
	BoxSizerPnlExposureCatgory->Fit(pnlExposureCatgory);
	BoxSizerPnlExposureCatgory->SetSizeHints(pnlExposureCatgory);
	BoxSizerExposureCatgory->Add(pnlExposureCatgory, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerWindDataMain->Add(BoxSizerExposureCatgory, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerVelPressureExpCoeff = new wxBoxSizer(wxHORIZONTAL);
	pnlVelPressureExpCoeff = new wxPanel(pnlWindData, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
	BoxSizerPnlVelPressureExpCoeff = new wxBoxSizer(wxHORIZONTAL);
	lblVelPressureExpCoeff = new wxStaticText(pnlVelPressureExpCoeff, ID_STATICTEXT30, _("Velocity Pressure Exposure Coefficient (Kz)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
	BoxSizerPnlVelPressureExpCoeff->Add(lblVelPressureExpCoeff, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtVelPressureExpCoeff = new wxTextCtrl(pnlVelPressureExpCoeff, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	txtVelPressureExpCoeff->SetMinSize(wxSize(240,-1));
	txtVelPressureExpCoeff->SetMaxSize(wxSize(240,-1));
	txtVelPressureExpCoeff->SetBackgroundColour(wxColour("PINK"));
	BoxSizerPnlVelPressureExpCoeff->Add(txtVelPressureExpCoeff, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlVelPressureExpCoeff->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlVelPressureExpCoeff->SetSizer(BoxSizerPnlVelPressureExpCoeff);
	BoxSizerPnlVelPressureExpCoeff->Fit(pnlVelPressureExpCoeff);
	BoxSizerPnlVelPressureExpCoeff->SetSizeHints(pnlVelPressureExpCoeff);
	BoxSizerVelPressureExpCoeff->Add(pnlVelPressureExpCoeff, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerWindDataMain->Add(BoxSizerVelPressureExpCoeff, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerTopographicFactor = new wxBoxSizer(wxHORIZONTAL);
	pnlTopographicFactor = new wxPanel(pnlWindData, ID_PANEL7, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL7"));
	BoxSizerPnlTopographicFactor = new wxBoxSizer(wxHORIZONTAL);
	lblTopographicFactor = new wxStaticText(pnlTopographicFactor, ID_STATICTEXT31, _("Topographic Factor (Kzt)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT31"));
	BoxSizerPnlTopographicFactor->Add(lblTopographicFactor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtTopographicFactor = new wxTextCtrl(pnlTopographicFactor, ID_TEXTCTRL14, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL14"));
	txtTopographicFactor->SetMinSize(wxSize(240,-1));
	txtTopographicFactor->SetMaxSize(wxSize(240,-1));
	txtTopographicFactor->SetBackgroundColour(wxColour("PINK"));
	BoxSizerPnlTopographicFactor->Add(txtTopographicFactor, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlTopographicFactor->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlTopographicFactor->SetSizer(BoxSizerPnlTopographicFactor);
	BoxSizerPnlTopographicFactor->Fit(pnlTopographicFactor);
	BoxSizerPnlTopographicFactor->SetSizeHints(pnlTopographicFactor);
	BoxSizerTopographicFactor->Add(pnlTopographicFactor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerWindDataMain->Add(BoxSizerTopographicFactor, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerDirectionFactor = new wxBoxSizer(wxHORIZONTAL);
	pnlDirectionFactor = new wxPanel(pnlWindData, ID_PANEL8, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL8"));
	BoxSizerPnlDirectionFactor = new wxBoxSizer(wxHORIZONTAL);
	lblDirectionFactor = new wxStaticText(pnlDirectionFactor, ID_STATICTEXT32, _("Directionality Factor (kd)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT32"));
	BoxSizerPnlDirectionFactor->Add(lblDirectionFactor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtDirectionFactor = new wxTextCtrl(pnlDirectionFactor, ID_TEXTCTRL21, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL21"));
	txtDirectionFactor->SetMinSize(wxSize(240,-1));
	txtDirectionFactor->SetMaxSize(wxSize(240,-1));
	txtDirectionFactor->SetBackgroundColour(wxColour("PINK"));
	BoxSizerPnlDirectionFactor->Add(txtDirectionFactor, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlDirectionFactor->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlDirectionFactor->SetSizer(BoxSizerPnlDirectionFactor);
	BoxSizerPnlDirectionFactor->Fit(pnlDirectionFactor);
	BoxSizerPnlDirectionFactor->SetSizeHints(pnlDirectionFactor);
	BoxSizerDirectionFactor->Add(pnlDirectionFactor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerWindDataMain->Add(BoxSizerDirectionFactor, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerImportanceFactor = new wxBoxSizer(wxHORIZONTAL);
	pnlImportanceFactor = new wxPanel(pnlWindData, ID_PANEL9, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL9"));
	BoxSizerPnlImportanceFactor = new wxBoxSizer(wxHORIZONTAL);
	lblImportanceFactor = new wxStaticText(pnlImportanceFactor, ID_STATICTEXT33, _("Importance Factor (I)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT33"));
	BoxSizerPnlImportanceFactor->Add(lblImportanceFactor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cmbChoiceImportanceFactor = new wxChoice(pnlImportanceFactor, ID_CHOICE8, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE8"));
	cmbChoiceImportanceFactor->Append(_("1.00"));
	cmbChoiceImportanceFactor->Append(_("1.15"));
	cmbChoiceImportanceFactor->SetMinSize(wxSize(240,-1));
	cmbChoiceImportanceFactor->SetMaxSize(wxSize(240,-1));
	BoxSizerPnlImportanceFactor->Add(cmbChoiceImportanceFactor, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlImportanceFactor->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlImportanceFactor->SetSizer(BoxSizerPnlImportanceFactor);
	BoxSizerPnlImportanceFactor->Fit(pnlImportanceFactor);
	BoxSizerPnlImportanceFactor->SetSizeHints(pnlImportanceFactor);
	BoxSizerImportanceFactor->Add(pnlImportanceFactor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerWindDataMain->Add(BoxSizerImportanceFactor, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerGustFactor = new wxBoxSizer(wxHORIZONTAL);
	pnlGustFactor = new wxPanel(pnlWindData, ID_PANEL10, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL10"));
	BoxSizerPnlGustFactor = new wxBoxSizer(wxHORIZONTAL);
	lblGustFactor = new wxStaticText(pnlGustFactor, ID_STATICTEXT34, _("Gust Factor (G)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT34"));
	BoxSizerPnlGustFactor->Add(lblGustFactor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtGustFactor = new wxTextCtrl(pnlGustFactor, ID_TEXTCTRL23, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL23"));
	txtGustFactor->SetMinSize(wxSize(240,-1));
	txtGustFactor->SetMaxSize(wxSize(240,-1));
	txtGustFactor->SetBackgroundColour(wxColour("PINK"));
	BoxSizerPnlGustFactor->Add(txtGustFactor, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlGustFactor->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlGustFactor->SetSizer(BoxSizerPnlGustFactor);
	BoxSizerPnlGustFactor->Fit(pnlGustFactor);
	BoxSizerPnlGustFactor->SetSizeHints(pnlGustFactor);
	BoxSizerGustFactor->Add(pnlGustFactor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerWindDataMain->Add(BoxSizerGustFactor, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerDesignWindVel = new wxBoxSizer(wxHORIZONTAL);
	pnlDesignWindVel = new wxPanel(pnlWindData, ID_PANEL11, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL11"));
	BoxSizerPnlDesignWindVel = new wxBoxSizer(wxHORIZONTAL);
	lblDesignWindVel = new wxStaticText(pnlDesignWindVel, ID_STATICTEXT35, _("Design Wind Velocity (km / h)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT35"));
	BoxSizerPnlDesignWindVel->Add(lblDesignWindVel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtDesignWindVel = new wxTextCtrl(pnlDesignWindVel, ID_TEXTCTRL27, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL27"));
	txtDesignWindVel->SetMinSize(wxSize(240,-1));
	txtDesignWindVel->SetMaxSize(wxSize(240,-1));
	txtDesignWindVel->SetBackgroundColour(wxColour("PINK"));
	BoxSizerPnlDesignWindVel->Add(txtDesignWindVel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlDesignWindVel->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlDesignWindVel->SetSizer(BoxSizerPnlDesignWindVel);
	BoxSizerPnlDesignWindVel->Fit(pnlDesignWindVel);
	BoxSizerPnlDesignWindVel->SetSizeHints(pnlDesignWindVel);
	BoxSizerDesignWindVel->Add(pnlDesignWindVel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerWindDataMain->Add(BoxSizerDesignWindVel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	windDataRunButton = new wxButton(pnlWindData, ID_BUTTON1, _("Click here to update design wind velocity"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	windDataRunButton->SetMaxSize(wxSize(-1,40));
	BoxSizerWindDataMain->Add(windDataRunButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerWindDataMain->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlWindData->SetSizer(BoxSizerWindDataMain);
	BoxSizerWindDataMain->Fit(pnlWindData);
	BoxSizerWindDataMain->SetSizeHints(pnlWindData);
	pnlSeismicData = new wxPanel(NotebookInputScreen_1, ID_PANEL13, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL13"));
	BoxSizerSeismicDataMain = new wxBoxSizer(wxHORIZONTAL);
	BoxSizerVariableCtrls = new wxBoxSizer(wxVERTICAL);
	BoxSizerSeismicDesignChoice = new wxBoxSizer(wxHORIZONTAL);
	pnlSeismicDesignChoice = new wxPanel(pnlSeismicData, ID_PANEL14, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL14"));
	BoxSizerPnlSeismicDesignChoice = new wxBoxSizer(wxHORIZONTAL);
	lblSeismicDesignChoice = new wxStaticText(pnlSeismicDesignChoice, ID_STATICTEXT36, _("Seismic Design as per:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT36"));
	BoxSizerPnlSeismicDesignChoice->Add(lblSeismicDesignChoice, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cmbChoiceSeismicDesignChoice = new wxChoice(pnlSeismicDesignChoice, ID_CHOICE9, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE9"));
	cmbChoiceSeismicDesignChoice->Append(_("ASCE 7"));
	cmbChoiceSeismicDesignChoice->Append(_("UBC 97"));
	cmbChoiceSeismicDesignChoice->Append(_("Peak Ground Acceleration"));
	cmbChoiceSeismicDesignChoice->SetMinSize(wxSize(240,-1));
	cmbChoiceSeismicDesignChoice->SetMaxSize(wxSize(240,-1));
	BoxSizerPnlSeismicDesignChoice->Add(cmbChoiceSeismicDesignChoice, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlSeismicDesignChoice->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlSeismicDesignChoice->SetSizer(BoxSizerPnlSeismicDesignChoice);
	BoxSizerPnlSeismicDesignChoice->Fit(pnlSeismicDesignChoice);
	BoxSizerPnlSeismicDesignChoice->SetSizeHints(pnlSeismicDesignChoice);
	BoxSizerSeismicDesignChoice->Add(pnlSeismicDesignChoice, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerVariableCtrls->Add(BoxSizerSeismicDesignChoice, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerDummySeismic = new wxBoxSizer(wxHORIZONTAL);
	pnlDummySeismic = new wxPanel(pnlSeismicData, ID_PANEL15, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL15"));
	BoxSizerDummySeismic->Add(pnlDummySeismic, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerVariableCtrls->Add(BoxSizerDummySeismic, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerGrpPeakGrndAccel = new wxBoxSizer(wxHORIZONTAL);
	pnlGrpPeakGrndAccel = new wxPanel(pnlSeismicData, ID_PANEL16, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL16"));
	BoxSizerGrpPeakGrndAcce = new wxBoxSizer(wxVERTICAL);
	BoxSizerPeakGroundAccel = new wxBoxSizer(wxHORIZONTAL);
	lblPeakGroundAccel = new wxStaticText(pnlGrpPeakGrndAccel, ID_STATICTEXT37, _("Peak Ground Acceleration"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT37"));
	BoxSizerPeakGroundAccel->Add(lblPeakGroundAccel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtPeakGroundAccel = new wxTextCtrl(pnlGrpPeakGrndAccel, ID_TEXTCTRL28, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL28"));
	txtPeakGroundAccel->SetMinSize(wxSize(240,-1));
	txtPeakGroundAccel->SetMaxSize(wxSize(240,-1));
	txtPeakGroundAccel->SetBackgroundColour(wxColour(100,255,200));
	BoxSizerPeakGroundAccel->Add(txtPeakGroundAccel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPeakGroundAccel->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerGrpPeakGrndAcce->Add(BoxSizerPeakGroundAccel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPGASpectralAccelShort = new wxBoxSizer(wxHORIZONTAL);
	lblPGASpectralAccelShort = new wxStaticText(pnlGrpPeakGrndAccel, ID_STATICTEXT38, _("Spectral Acceleration at Short Period (SS)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT38"));
	BoxSizerPGASpectralAccelShort->Add(lblPGASpectralAccelShort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtPGASpectralAccelShort = new wxTextCtrl(pnlGrpPeakGrndAccel, ID_TEXTCTRL29, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL29"));
	txtPGASpectralAccelShort->SetMinSize(wxSize(240,-1));
	txtPGASpectralAccelShort->SetMaxSize(wxSize(240,-1));
	txtPGASpectralAccelShort->Disable();
	BoxSizerPGASpectralAccelShort->Add(txtPGASpectralAccelShort, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPGASpectralAccelShort->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerGrpPeakGrndAcce->Add(BoxSizerPGASpectralAccelShort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPGASpectralAccelOneSec = new wxBoxSizer(wxHORIZONTAL);
	lblPGASpectralAccelOneSec = new wxStaticText(pnlGrpPeakGrndAccel, ID_STATICTEXT39, _("Spectral Acceleration at One second (S1)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT39"));
	BoxSizerPGASpectralAccelOneSec->Add(lblPGASpectralAccelOneSec, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtPGASpectralAccelOneSec = new wxTextCtrl(pnlGrpPeakGrndAccel, ID_TEXTCTRL30, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL30"));
	txtPGASpectralAccelOneSec->SetMinSize(wxSize(240,-1));
	txtPGASpectralAccelOneSec->SetMaxSize(wxSize(240,-1));
	txtPGASpectralAccelOneSec->Disable();
	BoxSizerPGASpectralAccelOneSec->Add(txtPGASpectralAccelOneSec, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPGASpectralAccelOneSec->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerGrpPeakGrndAcce->Add(BoxSizerPGASpectralAccelOneSec, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlGrpPeakGrndAccel->SetSizer(BoxSizerGrpPeakGrndAcce);
	BoxSizerGrpPeakGrndAcce->Fit(pnlGrpPeakGrndAccel);
	BoxSizerGrpPeakGrndAcce->SetSizeHints(pnlGrpPeakGrndAccel);
	BoxSizerGrpPeakGrndAccel->Add(pnlGrpPeakGrndAccel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerVariableCtrls->Add(BoxSizerGrpPeakGrndAccel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerGrpUBC = new wxBoxSizer(wxHORIZONTAL);
	pnlGrpUBC = new wxPanel(pnlSeismicData, ID_PANEL17, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL17"));
	BoxSizerPnlGrpUBC = new wxBoxSizer(wxVERTICAL);
	BoxSizerUBCZoneNo = new wxBoxSizer(wxHORIZONTAL);
	lblUBCZoneNo = new wxStaticText(pnlGrpUBC, ID_STATICTEXT40, _("UBC Zone No."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT40"));
	BoxSizerUBCZoneNo->Add(lblUBCZoneNo, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cmbChoiceUBCZoneNo = new wxChoice(pnlGrpUBC, ID_CHOICE10, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE10"));
	cmbChoiceUBCZoneNo->Append(_("Zone-1"));
	cmbChoiceUBCZoneNo->Append(_("Zone-2A"));
	cmbChoiceUBCZoneNo->Append(_("Zone-2B"));
	cmbChoiceUBCZoneNo->Append(_("Zone-3"));
	cmbChoiceUBCZoneNo->Append(_("Zone-4"));
	cmbChoiceUBCZoneNo->SetMinSize(wxSize(240,-1));
	cmbChoiceUBCZoneNo->SetMaxSize(wxSize(240,-1));
	BoxSizerUBCZoneNo->Add(cmbChoiceUBCZoneNo, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerUBCZoneNo->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlGrpUBC->Add(BoxSizerUBCZoneNo, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerUBCPeakGrndAccel = new wxBoxSizer(wxHORIZONTAL);
	lblUBCPeakGrndAccel = new wxStaticText(pnlGrpUBC, ID_STATICTEXT41, _("Peak Ground Acceleration"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT41"));
	BoxSizerUBCPeakGrndAccel->Add(lblUBCPeakGrndAccel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtUBCPeakGrndAccel = new wxTextCtrl(pnlGrpUBC, ID_TEXTCTRL31, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL31"));
	txtUBCPeakGrndAccel->SetMinSize(wxSize(240,-1));
	txtUBCPeakGrndAccel->SetMaxSize(wxSize(240,-1));
	txtUBCPeakGrndAccel->Disable();
	BoxSizerUBCPeakGrndAccel->Add(txtUBCPeakGrndAccel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerUBCPeakGrndAccel->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlGrpUBC->Add(BoxSizerUBCPeakGrndAccel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerUBCSpectralAccelShort = new wxBoxSizer(wxHORIZONTAL);
	lblUBCSpectralAccelShort = new wxStaticText(pnlGrpUBC, ID_STATICTEXT42, _("Spectral Acceleration at Short Period (SS)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT42"));
	BoxSizerUBCSpectralAccelShort->Add(lblUBCSpectralAccelShort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtUBCSpectralAccelShort = new wxTextCtrl(pnlGrpUBC, ID_TEXTCTRL32, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL32"));
	txtUBCSpectralAccelShort->SetMinSize(wxSize(240,-1));
	txtUBCSpectralAccelShort->SetMaxSize(wxSize(240,-1));
	txtUBCSpectralAccelShort->Disable();
	BoxSizerUBCSpectralAccelShort->Add(txtUBCSpectralAccelShort, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerUBCSpectralAccelShort->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlGrpUBC->Add(BoxSizerUBCSpectralAccelShort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerUBCSpectralAccelOneSec = new wxBoxSizer(wxHORIZONTAL);
	lblUBCSpectralAccelOneSec = new wxStaticText(pnlGrpUBC, ID_STATICTEXT43, _("Spectral Acceleration at One second (S1)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT43"));
	BoxSizerUBCSpectralAccelOneSec->Add(lblUBCSpectralAccelOneSec, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtUBCSpectralAccelOneSec = new wxTextCtrl(pnlGrpUBC, ID_TEXTCTRL33, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL33"));
	txtUBCSpectralAccelOneSec->SetMinSize(wxSize(240,-1));
	txtUBCSpectralAccelOneSec->SetMaxSize(wxSize(240,-1));
	txtUBCSpectralAccelOneSec->Disable();
	BoxSizerUBCSpectralAccelOneSec->Add(txtUBCSpectralAccelOneSec, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerUBCSpectralAccelOneSec->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlGrpUBC->Add(BoxSizerUBCSpectralAccelOneSec, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlGrpUBC->SetSizer(BoxSizerPnlGrpUBC);
	BoxSizerPnlGrpUBC->Fit(pnlGrpUBC);
	BoxSizerPnlGrpUBC->SetSizeHints(pnlGrpUBC);
	BoxSizerGrpUBC->Add(pnlGrpUBC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerVariableCtrls->Add(BoxSizerGrpUBC, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerGrpASCE = new wxBoxSizer(wxHORIZONTAL);
	pnlGrpASCE = new wxPanel(pnlSeismicData, ID_PANEL18, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL18"));
	BoxSizerPnlGrpASCE = new wxBoxSizer(wxVERTICAL);
	BoxSizerASCESpectralAccelShort = new wxBoxSizer(wxHORIZONTAL);
	lblASCESpectralAccelShort = new wxStaticText(pnlGrpASCE, ID_STATICTEXT44, _("Spectral Acceleration at Short Period (SS)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT44"));
	BoxSizerASCESpectralAccelShort->Add(lblASCESpectralAccelShort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtASCESpectralAccelShort = new wxTextCtrl(pnlGrpASCE, ID_TEXTCTRL34, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL34"));
	txtASCESpectralAccelShort->SetMinSize(wxSize(240,-1));
	txtASCESpectralAccelShort->SetMaxSize(wxSize(240,-1));
	txtASCESpectralAccelShort->SetBackgroundColour(wxColour(100,255,200));
	BoxSizerASCESpectralAccelShort->Add(txtASCESpectralAccelShort, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerASCESpectralAccelShort->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlGrpASCE->Add(BoxSizerASCESpectralAccelShort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerASCESpectralAccelOneSec = new wxBoxSizer(wxHORIZONTAL);
	lblASCESpectralAccelOneSec = new wxStaticText(pnlGrpASCE, ID_STATICTEXT45, _("Spectral Acceleration at One second (S1)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT45"));
	BoxSizerASCESpectralAccelOneSec->Add(lblASCESpectralAccelOneSec, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtASCESpectralAccelOneSec = new wxTextCtrl(pnlGrpASCE, ID_TEXTCTRL35, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL35"));
	txtASCESpectralAccelOneSec->SetMinSize(wxSize(240,-1));
	txtASCESpectralAccelOneSec->SetMaxSize(wxSize(240,-1));
	txtASCESpectralAccelOneSec->SetBackgroundColour(wxColour(100,255,200));
	BoxSizerASCESpectralAccelOneSec->Add(txtASCESpectralAccelOneSec, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerASCESpectralAccelOneSec->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlGrpASCE->Add(BoxSizerASCESpectralAccelOneSec, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlGrpASCE->SetSizer(BoxSizerPnlGrpASCE);
	BoxSizerPnlGrpASCE->Fit(pnlGrpASCE);
	BoxSizerPnlGrpASCE->SetSizeHints(pnlGrpASCE);
	BoxSizerGrpASCE->Add(pnlGrpASCE, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerVariableCtrls->Add(BoxSizerGrpASCE, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerVariableCtrls->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CalcFaFvBtn = new wxButton(pnlSeismicData, ID_BUTTON5, _("Run"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	BoxSizerVariableCtrls->Add(CalcFaFvBtn, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerSeismicDataMain->Add(BoxSizerVariableCtrls, 1, wxALL|wxALIGN_TOP, 5);
	BoxSizerFixedCtrls = new wxBoxSizer(wxVERTICAL);
	BoxSizerSpectralAccelTimePeriod0 = new wxBoxSizer(wxHORIZONTAL);
	pnlSpectralAccelTimePeriod0 = new wxPanel(pnlSeismicData, ID_PANEL20, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL20"));
	BoxSizerPnlSpectralAccelTimePeriod0 = new wxBoxSizer(wxHORIZONTAL);
	lblSpectralAccelTimePeriod0 = new wxStaticText(pnlSpectralAccelTimePeriod0, ID_STATICTEXT46, _("Spectral Acceleration at Time Period  0  (S0)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT46"));
	BoxSizerPnlSpectralAccelTimePeriod0->Add(lblSpectralAccelTimePeriod0, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtSpectralAccelTimePeriod0 = new wxTextCtrl(pnlSpectralAccelTimePeriod0, ID_TEXTCTRL36, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL36"));
	txtSpectralAccelTimePeriod0->SetMinSize(wxSize(240,-1));
	txtSpectralAccelTimePeriod0->SetMaxSize(wxSize(240,-1));
	txtSpectralAccelTimePeriod0->Disable();
	BoxSizerPnlSpectralAccelTimePeriod0->Add(txtSpectralAccelTimePeriod0, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlSpectralAccelTimePeriod0->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlSpectralAccelTimePeriod0->SetSizer(BoxSizerPnlSpectralAccelTimePeriod0);
	BoxSizerPnlSpectralAccelTimePeriod0->Fit(pnlSpectralAccelTimePeriod0);
	BoxSizerPnlSpectralAccelTimePeriod0->SetSizeHints(pnlSpectralAccelTimePeriod0);
	BoxSizerSpectralAccelTimePeriod0->Add(pnlSpectralAccelTimePeriod0, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerFixedCtrls->Add(BoxSizerSpectralAccelTimePeriod0, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerGovByASCERules = new wxBoxSizer(wxHORIZONTAL);
	pnlGovByASCERules = new wxPanel(pnlSeismicData, ID_PANEL21, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL21"));
	BoxSizerPnlGovByASCERules = new wxBoxSizer(wxHORIZONTAL);
	lblGovByASCERules = new wxStaticText(pnlGovByASCERules, ID_STATICTEXT47, _("Is the site governed by ASCE Rules"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT47"));
	BoxSizerPnlGovByASCERules->Add(lblGovByASCERules, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cmbChoiceGovByASCERules = new wxChoice(pnlGovByASCERules, ID_CHOICE11, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE11"));
	cmbChoiceGovByASCERules->Append(_("NO"));
	cmbChoiceGovByASCERules->Append(_("YES"));
	cmbChoiceGovByASCERules->SetMinSize(wxSize(240,-1));
	cmbChoiceGovByASCERules->SetMaxSize(wxSize(240,-1));
	BoxSizerPnlGovByASCERules->Add(cmbChoiceGovByASCERules, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlGovByASCERules->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlGovByASCERules->SetSizer(BoxSizerPnlGovByASCERules);
	BoxSizerPnlGovByASCERules->Fit(pnlGovByASCERules);
	BoxSizerPnlGovByASCERules->SetSizeHints(pnlGovByASCERules);
	BoxSizerGovByASCERules->Add(pnlGovByASCERules, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerFixedCtrls->Add(BoxSizerGovByASCERules, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerSeismicScaleFactor = new wxBoxSizer(wxHORIZONTAL);
	pnlSeismicScaleFactor = new wxPanel(pnlSeismicData, ID_PANEL22, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL22"));
	BoxSizerPnlSeismicScaleFactor = new wxBoxSizer(wxHORIZONTAL);
	lblSeismicScaleFactor = new wxStaticText(pnlSeismicScaleFactor, ID_STATICTEXT48, _("Scaling Factor (Q)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT48"));
	BoxSizerPnlSeismicScaleFactor->Add(lblSeismicScaleFactor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtSeismicScaleFactor = new wxTextCtrl(pnlSeismicScaleFactor, ID_TEXTCTRL38, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL38"));
	txtSeismicScaleFactor->SetMinSize(wxSize(240,-1));
	txtSeismicScaleFactor->SetMaxSize(wxSize(240,-1));
	txtSeismicScaleFactor->Disable();
	BoxSizerPnlSeismicScaleFactor->Add(txtSeismicScaleFactor, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlSeismicScaleFactor->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlSeismicScaleFactor->SetSizer(BoxSizerPnlSeismicScaleFactor);
	BoxSizerPnlSeismicScaleFactor->Fit(pnlSeismicScaleFactor);
	BoxSizerPnlSeismicScaleFactor->SetSizeHints(pnlSeismicScaleFactor);
	BoxSizerSeismicScaleFactor->Add(pnlSeismicScaleFactor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerFixedCtrls->Add(BoxSizerSeismicScaleFactor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerSeismicUserGrp = new wxBoxSizer(wxHORIZONTAL);
	pnlSeismicUserGrp = new wxPanel(pnlSeismicData, ID_PANEL23, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL23"));
	BoxSizerPnlSeismicUserGrp = new wxBoxSizer(wxHORIZONTAL);
	lblSeismicUserGrp = new wxStaticText(pnlSeismicUserGrp, ID_STATICTEXT49, _("Seismic User Group"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT49"));
	BoxSizerPnlSeismicUserGrp->Add(lblSeismicUserGrp, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cmbChoiceSeismicUserGrp = new wxChoice(pnlSeismicUserGrp, ID_CHOICE12, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE12"));
	cmbChoiceSeismicUserGrp->Append(_("SUG-1"));
	cmbChoiceSeismicUserGrp->Append(_("SUG-2"));
	cmbChoiceSeismicUserGrp->Append(_("SUG-3"));
	cmbChoiceSeismicUserGrp->SetMinSize(wxSize(240,-1));
	cmbChoiceSeismicUserGrp->SetMaxSize(wxSize(240,-1));
	BoxSizerPnlSeismicUserGrp->Add(cmbChoiceSeismicUserGrp, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlSeismicUserGrp->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlSeismicUserGrp->SetSizer(BoxSizerPnlSeismicUserGrp);
	BoxSizerPnlSeismicUserGrp->Fit(pnlSeismicUserGrp);
	BoxSizerPnlSeismicUserGrp->SetSizeHints(pnlSeismicUserGrp);
	BoxSizerSeismicUserGrp->Add(pnlSeismicUserGrp, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerFixedCtrls->Add(BoxSizerSeismicUserGrp, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerSeismicImportanceFactor = new wxBoxSizer(wxHORIZONTAL);
	pnlSeismicImportanceFactor = new wxPanel(pnlSeismicData, ID_PANEL24, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL24"));
	BoxSizerPnlSeismicImportanceFactor = new wxBoxSizer(wxHORIZONTAL);
	lblSeismicImportanceFactor = new wxStaticText(pnlSeismicImportanceFactor, ID_STATICTEXT50, _("Importance Factor"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT50"));
	BoxSizerPnlSeismicImportanceFactor->Add(lblSeismicImportanceFactor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtSeismicImportanceFactor = new wxTextCtrl(pnlSeismicImportanceFactor, ID_TEXTCTRL40, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL40"));
	txtSeismicImportanceFactor->SetMinSize(wxSize(240,-1));
	txtSeismicImportanceFactor->SetMaxSize(wxSize(240,-1));
	txtSeismicImportanceFactor->Disable();
	BoxSizerPnlSeismicImportanceFactor->Add(txtSeismicImportanceFactor, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlSeismicImportanceFactor->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlSeismicImportanceFactor->SetSizer(BoxSizerPnlSeismicImportanceFactor);
	BoxSizerPnlSeismicImportanceFactor->Fit(pnlSeismicImportanceFactor);
	BoxSizerPnlSeismicImportanceFactor->SetSizeHints(pnlSeismicImportanceFactor);
	BoxSizerSeismicImportanceFactor->Add(pnlSeismicImportanceFactor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerFixedCtrls->Add(BoxSizerSeismicImportanceFactor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerSeismicSiteClass = new wxBoxSizer(wxHORIZONTAL);
	pnlSeismicSiteClass = new wxPanel(pnlSeismicData, ID_PANEL25, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL25"));
	BoxSizerPnlSeismicSiteClass = new wxBoxSizer(wxHORIZONTAL);
	lblSeismicSiteClass = new wxStaticText(pnlSeismicSiteClass, ID_STATICTEXT51, _("Site Class"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT51"));
	BoxSizerPnlSeismicSiteClass->Add(lblSeismicSiteClass, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cmbChoiceSeismicSiteClass = new wxChoice(pnlSeismicSiteClass, ID_CHOICE13, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE13"));
	cmbChoiceSeismicSiteClass->Append(_("A"));
	cmbChoiceSeismicSiteClass->Append(_("B"));
	cmbChoiceSeismicSiteClass->Append(_("C"));
	cmbChoiceSeismicSiteClass->Append(_("D"));
	cmbChoiceSeismicSiteClass->Append(_("E"));
	cmbChoiceSeismicSiteClass->SetMinSize(wxSize(240,-1));
	cmbChoiceSeismicSiteClass->SetMaxSize(wxSize(240,-1));
	BoxSizerPnlSeismicSiteClass->Add(cmbChoiceSeismicSiteClass, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlSeismicSiteClass->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlSeismicSiteClass->SetSizer(BoxSizerPnlSeismicSiteClass);
	BoxSizerPnlSeismicSiteClass->Fit(pnlSeismicSiteClass);
	BoxSizerPnlSeismicSiteClass->SetSizeHints(pnlSeismicSiteClass);
	BoxSizerSeismicSiteClass->Add(pnlSeismicSiteClass, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerFixedCtrls->Add(BoxSizerSeismicSiteClass, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerAccelBaseSiteCoeff = new wxBoxSizer(wxHORIZONTAL);
	pnlAccelBaseSiteCoeff = new wxPanel(pnlSeismicData, ID_PANEL26, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL26"));
	BoxSizerPnlAccelBaseSiteCoeff = new wxBoxSizer(wxHORIZONTAL);
	lblAccelBaseSiteCoeff = new wxStaticText(pnlAccelBaseSiteCoeff, ID_STATICTEXT52, _("Acceleration based site coefficient (Fa)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT52"));
	BoxSizerPnlAccelBaseSiteCoeff->Add(lblAccelBaseSiteCoeff, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtAccelBaseSiteCoeff = new wxTextCtrl(pnlAccelBaseSiteCoeff, ID_TEXTCTRL42, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL42"));
	txtAccelBaseSiteCoeff->SetMinSize(wxSize(240,-1));
	txtAccelBaseSiteCoeff->SetMaxSize(wxSize(240,-1));
	txtAccelBaseSiteCoeff->SetBackgroundColour(wxColour("PINK"));
	BoxSizerPnlAccelBaseSiteCoeff->Add(txtAccelBaseSiteCoeff, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlAccelBaseSiteCoeff->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlAccelBaseSiteCoeff->SetSizer(BoxSizerPnlAccelBaseSiteCoeff);
	BoxSizerPnlAccelBaseSiteCoeff->Fit(pnlAccelBaseSiteCoeff);
	BoxSizerPnlAccelBaseSiteCoeff->SetSizeHints(pnlAccelBaseSiteCoeff);
	BoxSizerAccelBaseSiteCoeff->Add(pnlAccelBaseSiteCoeff, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerFixedCtrls->Add(BoxSizerAccelBaseSiteCoeff, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerVelBasedSiteCoeff = new wxBoxSizer(wxHORIZONTAL);
	pnlVelBasedSiteCoeff = new wxPanel(pnlSeismicData, ID_PANEL27, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL27"));
	BoxSizerPnlVelBasedSiteCoeff = new wxBoxSizer(wxHORIZONTAL);
	lblVelBasedSiteCoeff = new wxStaticText(pnlVelBasedSiteCoeff, ID_STATICTEXT53, _("Velocity based site coefficient (Fv)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT53"));
	BoxSizerPnlVelBasedSiteCoeff->Add(lblVelBasedSiteCoeff, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtVelBasedSiteCoeff = new wxTextCtrl(pnlVelBasedSiteCoeff, ID_TEXTCTRL43, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL43"));
	txtVelBasedSiteCoeff->SetMinSize(wxSize(240,-1));
	txtVelBasedSiteCoeff->SetMaxSize(wxSize(240,-1));
	txtVelBasedSiteCoeff->SetBackgroundColour(wxColour("PINK"));
	BoxSizerPnlVelBasedSiteCoeff->Add(txtVelBasedSiteCoeff, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlVelBasedSiteCoeff->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlVelBasedSiteCoeff->SetSizer(BoxSizerPnlVelBasedSiteCoeff);
	BoxSizerPnlVelBasedSiteCoeff->Fit(pnlVelBasedSiteCoeff);
	BoxSizerPnlVelBasedSiteCoeff->SetSizeHints(pnlVelBasedSiteCoeff);
	BoxSizerVelBasedSiteCoeff->Add(pnlVelBasedSiteCoeff, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerFixedCtrls->Add(BoxSizerVelBasedSiteCoeff, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerTransitionLongGrnd = new wxBoxSizer(wxHORIZONTAL);
	pnlTransitionLongGrnd = new wxPanel(pnlSeismicData, ID_PANEL28, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL28"));
	BoxSizerPnlTransitionLongGrnd = new wxBoxSizer(wxHORIZONTAL);
	lblTransitionLongGrnd = new wxStaticText(pnlTransitionLongGrnd, ID_STATICTEXT54, _("Transition Period for Longer period Ground motion (TL)"), wxDefaultPosition, wxSize(226,38), 0, _T("ID_STATICTEXT54"));
	BoxSizerPnlTransitionLongGrnd->Add(lblTransitionLongGrnd, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtTransitionLongGrnd = new wxTextCtrl(pnlTransitionLongGrnd, ID_TEXTCTRL44, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL44"));
	txtTransitionLongGrnd->SetMinSize(wxSize(240,-1));
	txtTransitionLongGrnd->SetMaxSize(wxSize(240,-1));
	txtTransitionLongGrnd->SetBackgroundColour(wxColour("PINK"));
	BoxSizerPnlTransitionLongGrnd->Add(txtTransitionLongGrnd, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlTransitionLongGrnd->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlTransitionLongGrnd->SetSizer(BoxSizerPnlTransitionLongGrnd);
	BoxSizerPnlTransitionLongGrnd->Fit(pnlTransitionLongGrnd);
	BoxSizerPnlTransitionLongGrnd->SetSizeHints(pnlTransitionLongGrnd);
	BoxSizerTransitionLongGrnd->Add(pnlTransitionLongGrnd, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerFixedCtrls->Add(BoxSizerTransitionLongGrnd, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerCoeffAdjust = new wxBoxSizer(wxHORIZONTAL);
	pnlCoeffAdjust = new wxPanel(pnlSeismicData, ID_PANEL29, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL29"));
	BoxSizerPnlCoeffAdjust = new wxBoxSizer(wxHORIZONTAL);
	lblCoeffAdjust = new wxStaticText(pnlCoeffAdjust, ID_STATICTEXT55, _("Coefficient to adjust 5% damping\nvalue to 0.5% Damping value (K)"), wxDefaultPosition, wxSize(-1,-1), 0, _T("ID_STATICTEXT55"));
	BoxSizerPnlCoeffAdjust->Add(lblCoeffAdjust, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtCoeffAdjust = new wxTextCtrl(pnlCoeffAdjust, ID_TEXTCTRL45, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL45"));
	txtCoeffAdjust->SetMinSize(wxSize(240,-1));
	txtCoeffAdjust->SetMaxSize(wxSize(240,-1));
	txtCoeffAdjust->SetBackgroundColour(wxColour("PINK"));
	BoxSizerPnlCoeffAdjust->Add(txtCoeffAdjust, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlCoeffAdjust->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlCoeffAdjust->SetSizer(BoxSizerPnlCoeffAdjust);
	BoxSizerPnlCoeffAdjust->Fit(pnlCoeffAdjust);
	BoxSizerPnlCoeffAdjust->SetSizeHints(pnlCoeffAdjust);
	BoxSizerCoeffAdjust->Add(pnlCoeffAdjust, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerFixedCtrls->Add(BoxSizerCoeffAdjust, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerSDSQFaSs = new wxBoxSizer(wxHORIZONTAL);
	pnlSDSQFaSs = new wxPanel(pnlSeismicData, ID_PANEL30, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL30"));
	BoxSizerPnlSDSQFaSs = new wxBoxSizer(wxHORIZONTAL);
	lblSDSQFaSs = new wxStaticText(pnlSDSQFaSs, ID_STATICTEXT56, _("SDS = Q * Fa * Ss = "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT56"));
	BoxSizerPnlSDSQFaSs->Add(lblSDSQFaSs, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtSDSQFaSs = new wxTextCtrl(pnlSDSQFaSs, ID_TEXTCTRL46, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL46"));
	txtSDSQFaSs->SetMinSize(wxSize(240,-1));
	txtSDSQFaSs->SetMaxSize(wxSize(240,-1));
	txtSDSQFaSs->Disable();
	BoxSizerPnlSDSQFaSs->Add(txtSDSQFaSs, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlSDSQFaSs->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlSDSQFaSs->SetSizer(BoxSizerPnlSDSQFaSs);
	BoxSizerPnlSDSQFaSs->Fit(pnlSDSQFaSs);
	BoxSizerPnlSDSQFaSs->SetSizeHints(pnlSDSQFaSs);
	BoxSizerSDSQFaSs->Add(pnlSDSQFaSs, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerFixedCtrls->Add(BoxSizerSDSQFaSs, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerSD1QFvS1 = new wxBoxSizer(wxHORIZONTAL);
	pnlSD1QFvS1 = new wxPanel(pnlSeismicData, ID_PANEL31, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL31"));
	BoxSizerPnlSD1QFvS1 = new wxBoxSizer(wxHORIZONTAL);
	lblSD1QFvS1 = new wxStaticText(pnlSD1QFvS1, ID_STATICTEXT57, _("SD1 = Q * Fv * S1 = "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT57"));
	BoxSizerPnlSD1QFvS1->Add(lblSD1QFvS1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtSD1QFvS1 = new wxTextCtrl(pnlSD1QFvS1, ID_TEXTCTRL47, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL47"));
	txtSD1QFvS1->SetMinSize(wxSize(240,-1));
	txtSD1QFvS1->SetMaxSize(wxSize(240,-1));
	txtSD1QFvS1->Disable();
	BoxSizerPnlSD1QFvS1->Add(txtSD1QFvS1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlSD1QFvS1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlSD1QFvS1->SetSizer(BoxSizerPnlSD1QFvS1);
	BoxSizerPnlSD1QFvS1->Fit(pnlSD1QFvS1);
	BoxSizerPnlSD1QFvS1->SetSizeHints(pnlSD1QFvS1);
	BoxSizerSD1QFvS1->Add(pnlSD1QFvS1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerFixedCtrls->Add(BoxSizerSD1QFvS1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerVertSeismicEffect = new wxBoxSizer(wxHORIZONTAL);
	pnlVertSeismicEffect = new wxPanel(pnlSeismicData, ID_PANEL19, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL19"));
	BoxSizerPnlVertSeismicEffect = new wxBoxSizer(wxHORIZONTAL);
	lblVertSeismicEffect = new wxStaticText(pnlVertSeismicEffect, ID_STATICTEXT58, _("Vertical Seismic Effect To Be Considered \?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT58"));
	BoxSizerPnlVertSeismicEffect->Add(lblVertSeismicEffect, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cmbChoiceVertSeismicEffect = new wxChoice(pnlVertSeismicEffect, ID_CHOICE14, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE14"));
	cmbChoiceVertSeismicEffect->Append(_("NO"));
	cmbChoiceVertSeismicEffect->Append(_("YES"));
	cmbChoiceVertSeismicEffect->SetMinSize(wxSize(240,-1));
	cmbChoiceVertSeismicEffect->SetMaxSize(wxSize(240,-1));
	BoxSizerPnlVertSeismicEffect->Add(cmbChoiceVertSeismicEffect, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerPnlVertSeismicEffect->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlVertSeismicEffect->SetSizer(BoxSizerPnlVertSeismicEffect);
	BoxSizerPnlVertSeismicEffect->Fit(pnlVertSeismicEffect);
	BoxSizerPnlVertSeismicEffect->SetSizeHints(pnlVertSeismicEffect);
	BoxSizerVertSeismicEffect->Add(pnlVertSeismicEffect, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerFixedCtrls->Add(BoxSizerVertSeismicEffect, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerSeismicDataMain->Add(BoxSizerFixedCtrls, 1, wxALL|wxALIGN_TOP, 5);
	pnlSeismicData->SetSizer(BoxSizerSeismicDataMain);
	BoxSizerSeismicDataMain->Fit(pnlSeismicData);
	BoxSizerSeismicDataMain->SetSizeHints(pnlSeismicData);
	pnlShlDesMain = new wxPanel(NotebookInputScreen_1, ID_PANEL32, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL32"));
	gridShellDesign = new wxGrid(pnlShlDesMain, ID_GRID1, wxPoint(0,100), wxSize(1260,400), wxSIMPLE_BORDER, _T("ID_GRID1"));
	ButtonRunShell = new wxButton(pnlShlDesMain, ID_BUTTON2, _("Add Shell Course"), wxPoint(264,512), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	ButtonDesignShell = new wxButton(pnlShlDesMain, ID_BUTTON3, _("Design"), wxPoint(464,512), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	gridShellDesignLabel = new wxGrid(pnlShlDesMain, ID_GRID44, wxPoint(0,0), wxSize(1260,100), wxSIMPLE_BORDER|wxVSCROLL|wxHSCROLL, _T("ID_GRID44"));
	StaticText4 = new wxStaticText(pnlShlDesMain, ID_STATICTEXT91, _("NOTE : Please click \'Add Shell Course\' button and then make necessary corrections in the \'Course Material\', \'Course Width\'  and \'Corrosion Allowance\'  of each shell course, if it is different from previous shell course and then click \'Add Shell Course\'  to Auto-Fill,  save changes, and add another Shell Course."), wxPoint(32,576), wxSize(544,64), 0, _T("ID_STATICTEXT91"));
	pnlMainPrimaryWindGirder = new wxPanel(NotebookInputScreen_1, ID_PANEL33, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL33"));
	lblTopWGAsWalkway = new wxStaticText(pnlMainPrimaryWindGirder, ID_STATICTEXT59, _("Is Top Wind Girder used as a Walkway \?"), wxPoint(32,56), wxDefaultSize, 0, _T("ID_STATICTEXT59"));
	lblSpaceTopWGTopTank = new wxStaticText(pnlMainPrimaryWindGirder, ID_STATICTEXT60, _("Spacing of Top Wind Girder from top of Tank"), wxPoint(32,88), wxDefaultSize, 0, _T("ID_STATICTEXT60"));
	lblSizeTopAngle = new wxStaticText(pnlMainPrimaryWindGirder, ID_STATICTEXT61, _("Size of top angle"), wxPoint(32,120), wxDefaultSize, 0, _T("ID_STATICTEXT61"));
	lblMinWidthTopWGAsWalkway = new wxStaticText(pnlMainPrimaryWindGirder, ID_STATICTEXT62, _("Minimum required width of Top WG used as walkway"), wxPoint(32,152), wxDefaultSize, 0, _T("ID_STATICTEXT62"));
	lblDesignTopWGTankDia = new wxStaticText(pnlMainPrimaryWindGirder, ID_STATICTEXT63, _("Design Top Wind Girder Considering the Tank DIA as 61.0 M \?"), wxPoint(32,184), wxSize(264,40), 0, _T("ID_STATICTEXT63"));
	cmbTopWGAsWalkway = new wxChoice(pnlMainPrimaryWindGirder, ID_CHOICE15, wxPoint(336,48), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE15"));
	cmbTopWGAsWalkway->Append(_("NO"));
	cmbTopWGAsWalkway->Append(_("YES"));
	txtSpaceTopWGTopTank = new wxTextCtrl(pnlMainPrimaryWindGirder, ID_TEXTCTRL37, wxEmptyString, wxPoint(336,80), wxSize(128,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL37"));
	txtSpaceTopWGTopTank->SetBackgroundColour(wxColour("PINK"));
	cmblSizeTopAngle = new wxChoice(pnlMainPrimaryWindGirder, ID_CHOICE16, wxPoint(336,112), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE16"));
	cmblSizeTopAngle->Append(_("65 x 65 x 6"));
	cmblSizeTopAngle->Append(_("65 x 65 x 8"));
	cmblSizeTopAngle->Append(_("65 x 65 x 10"));
	cmblSizeTopAngle->Append(_("75 x 75 x 6"));
	cmblSizeTopAngle->Append(_("75 x 75 x 8"));
	cmblSizeTopAngle->Append(_("75 x 75 x 10"));
	cmblSizeTopAngle->Append(_("90 x 90 x 10"));
	txtMinWidthTopWGAsWalkway = new wxTextCtrl(pnlMainPrimaryWindGirder, ID_TEXTCTRL39, wxEmptyString, wxPoint(336,144), wxSize(128,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL39"));
	txtMinWidthTopWGAsWalkway->SetBackgroundColour(wxColour("PINK"));
	cmblDesignTopWGTankDia = new wxChoice(pnlMainPrimaryWindGirder, ID_CHOICE17, wxPoint(336,176), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE17"));
	cmblDesignTopWGTankDia->Append(_("NO"));
	cmblDesignTopWGTankDia->Append(_("YES"));
	Gridpwg = new wxGrid(pnlMainPrimaryWindGirder, ID_GRID6, wxPoint(32,380), wxSize(930,120), wxSIMPLE_BORDER, _T("ID_GRID6"));
	Gridpwg->CreateGrid(3,6);
	Gridpwg->EnableEditing(true);
	Gridpwg->EnableGridLines(true);
	Gridpwg->SetDefaultRowSize(30, true);
	Gridpwg->SetDefaultColSize(150, true);
	Gridpwg->SetColLabelValue(0, _("Width of Web (mm)"));
	Gridpwg->SetColLabelValue(1, _("Thickness of (mm)"));
	Gridpwg->SetColLabelValue(2, _("Height of Flange (mm)"));
	Gridpwg->SetColLabelValue(3, _("Thickness of Flange (mm)"));
	Gridpwg->SetColLabelValue(4, _("Section Modulus Available(CM^3)"));
	Gridpwg->SetColLabelValue(5, _("MOI Required (CM^4)"));
	Gridpwg->SetRowLabelValue(0, _("Default"));
	Gridpwg->SetRowLabelValue(1, _("User"));
	Gridpwg->SetRowLabelValue(2, _("Adopted"));
	Gridpwg->SetDefaultCellFont( Gridpwg->GetFont() );
	Gridpwg->SetDefaultCellTextColour( Gridpwg->GetForegroundColour() );
	RunPWG = new wxButton(pnlMainPrimaryWindGirder, ID_BUTTON6, _("Run"), wxPoint(232,320), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
	lblSectionModRqd = new wxStaticText(pnlMainPrimaryWindGirder, ID_STATICTEXT66, _("Section Modulus Required: Cub Cm"), wxPoint(32,232), wxDefaultSize, 0, _T("ID_STATICTEXT66"));
	TextSectionModRqd = new wxTextCtrl(pnlMainPrimaryWindGirder, ID_TEXTCTRL41, wxEmptyString, wxPoint(336,224), wxSize(128,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL41"));
	TextSectionModRqd->Disable();
	lblMOIRqd = new wxStaticText(pnlMainPrimaryWindGirder, ID_STATICTEXT67, _("Moment of Ineria Required  CM^4"), wxPoint(32,264), wxDefaultSize, 0, _T("ID_STATICTEXT67"));
	TextMOIRqd = new wxTextCtrl(pnlMainPrimaryWindGirder, ID_TEXTCTRL48, wxEmptyString, wxPoint(336,256), wxSize(128,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL48"));
	TextMOIRqd->Disable();
	pnlStiffenerElevation = new wxPanel(NotebookInputScreen_1, ID_PANEL35, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL35"));
	lblHeightTransShell = new wxStaticText(pnlStiffenerElevation, ID_STATICTEXTlblHeightTransShell, _("Total Transposed Height of Shell"), wxPoint(104,32), wxDefaultSize, 0, _T("ID_STATICTEXTlblHeightTransShell"));
	lblT_uniform = new wxStaticText(pnlStiffenerElevation, ID_STATICTEXTlblT_uniform, _("t_uniform considered for design"), wxPoint(104,64), wxDefaultSize, 0, _T("ID_STATICTEXTlblT_uniform"));
	lblHMaxWind = new wxStaticText(pnlStiffenerElevation, ID_STATICTEXTlblHMaxWind, _("Maximum unstiffened height of shell against wind load"), wxPoint(104,96), wxDefaultSize, 0, _T("ID_STATICTEXTlblHMaxWind"));
	lblHMaxPressure = new wxStaticText(pnlStiffenerElevation, ID_STATICTEXT92, _("Maximum Unstiffened height of shell against external pressure"), wxPoint(104,128), wxDefaultSize, 0, _T("ID_STATICTEXT92"));
	lblNumStiff = new wxStaticText(pnlStiffenerElevation, ID_STATICTEXTlblNumStiff, _("Number of stiffeners required"), wxPoint(104,160), wxDefaultSize, 0, _T("ID_STATICTEXTlblNumStiff"));
	lblNumStiffMax = new wxStaticText(pnlStiffenerElevation, ID_STATICTEXTlblNumStiffMax, _("Limit the number of stiffeners to (Minimum 1)"), wxPoint(104,192), wxSize(160,32), 0, _T("ID_STATICTEXTlblNumStiffMax"));
	TextHeightTransShell = new wxTextCtrl(pnlStiffenerElevation, ID_TEXTCTRLTextHeightTransShell, _("No Backend."), wxPoint(464,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRLTextHeightTransShell"));
	TextHeightTransShell->Disable();
	TextT_uniform = new wxTextCtrl(pnlStiffenerElevation, ID_TEXTCTRLTextT_uniform, _("No Backend."), wxPoint(464,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRLTextT_uniform"));
	TextT_uniform->Disable();
	TextHMaxWind = new wxTextCtrl(pnlStiffenerElevation, ID_TEXTCTRLTextHMaxWind, _("No Backend."), wxPoint(464,96), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRLTextHMaxWind"));
	TextHMaxWind->Disable();
	TextHMaxPressure = new wxTextCtrl(pnlStiffenerElevation, ID_TEXTCTRLTextHMaxPressure, _("No Backend."), wxPoint(464,128), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRLTextHMaxPressure"));
	TextHMaxPressure->Disable();
	TextNumStiff = new wxTextCtrl(pnlStiffenerElevation, ID_TEXTCTRLTextNumStiff, _("No backend."), wxPoint(464,160), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRLTextNumStiff"));
	TextNumStiff->Disable();
	TextNumStiffMax = new wxTextCtrl(pnlStiffenerElevation, ID_TEXTCTRLTextNumStiffMax, wxEmptyString, wxPoint(464,192), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRLTextNumStiffMax"));
	TextNumStiffMax->SetBackgroundColour(wxColour("PINK"));
	GridStiffenerElevation = new wxGrid(pnlStiffenerElevation, ID_GRID2, wxPoint(50,478), wxSize(1220,150), wxSIMPLE_BORDER, _T("ID_GRID2"));
	StaticText2 = new wxStaticText(pnlStiffenerElevation, ID_STATICTEXT89, _("M"), wxPoint(580,96), wxSize(28,24), 0, _T("ID_STATICTEXT89"));
	StaticText3 = new wxStaticText(pnlStiffenerElevation, ID_STATICTEXT90, _("M"), wxPoint(580,128), wxSize(28,24), 0, _T("ID_STATICTEXT90"));
	GridStiffenerElevationLabel = new wxGrid(pnlStiffenerElevation, ID_GRID3, wxPoint(50,370), wxSize(1220,108), wxSIMPLE_BORDER, _T("ID_GRID3"));
	ButtonRunStiffenerElevation = new wxButton(pnlStiffenerElevation, ID_BUTTON4, _("Run"), wxPoint(104,288), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	Panel1 = new wxPanel(NotebookInputScreen_1, ID_PANEL37, wxPoint(300,600), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL37"));
	GridStiffenerSizeLabel1 = new wxGrid(Panel1, ID_GRID4, wxPoint(0,0), wxSize(988,95), wxSIMPLE_BORDER, _T("ID_GRID4"));
	GridStiffenerSize = new wxGrid(Panel1, ID_GRID5, wxPoint(0,95), wxSize(988,370), wxSIMPLE_BORDER, _T("ID_GRID5"));
	ButtonRunStiffenerSize = new wxButton(Panel1, ID_BUTTON7, _("RUN"), wxPoint(416,560), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
	pnlRoofData = new wxPanel(NotebookInputScreen_1, ID_PANEL, wxPoint(4,122), wxSize(1738,573), wxTAB_TRAVERSAL, _T("ID_PANEL"));
	lblRoofTypeUser = new wxStaticText(pnlRoofData, ID_STATICTEXTlblRoofTypeUser, _("Roof Type Specified By User"), wxPoint(32,24), wxSize(137,32), 0, _T("ID_STATICTEXTlblRoofTypeUser"));
	cmbRoofType = new wxChoice(pnlRoofData, ID_CHOICEroofTypeUser, wxPoint(200,16), wxSize(248,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICEroofTypeUser"));
	cmbRoofType->Append(_("SELF SUPPORTING CONE ROOF"));
	cmbRoofType->Append(_("SELF SUPPORTING DOME/UMBRELLA ROOF"));
	cmbRoofType->Append(_("SUPPORTED CONE ROOF"));
	cmbRoofType->Append(_("SUPPORTED DOME/UMBRELLA ROOF"));
	cmbRoofType->Append(_("STIFFENED CONE ROOF"));
	cmbRoofType->Append(_("STIFFENED DOME ROOF"));
	cmbRoofType->Append(_("GEODESIC ROOF"));
	cmbRoofType->Append(_("NONE"));
	cmbRoofType->Disable();
	lblRRoof = new wxStaticText(pnlRoofData, ID_STATICTEXTlblRRoof, _("Horizontal radius at the base of roof (M)\t\t\t"), wxPoint(32,120), wxSize(144,40), 0, _T("ID_STATICTEXTlblRRoof"));
	lblFrangible = new wxStaticText(pnlRoofData, ID_STATICTEXTlblFrangible, _("Frangible Roof to Shell Junction Required\?\t\t\t"), wxPoint(32,168), wxSize(136,32), 0, _T("ID_STATICTEXTlblFrangible"));
	lblLiveLoad = new wxStaticText(pnlRoofData, ID_STATICTEXTlblLiveLoad, _("Live Load on Roof (kPa)\t\t"), wxPoint(32,232), wxSize(128,13), 0, _T("ID_STATICTEXTlblLiveLoad"));
	lblBalSL = new wxStaticText(pnlRoofData, ID_STATICTEXTlblBalSL, _("Balanced Design Snow Load -Sb (kPa)*\t\t\t"), wxPoint(32,264), wxSize(128,40), 0, _T("ID_STATICTEXTlblBalSL"));
	lblUnBalSL = new wxStaticText(pnlRoofData, ID_STATICTEXTlblUnBalSL, _("Un-Balanced Design Snow Load -Sb (kPa)*\t\t\t"), wxPoint(32,312), wxSize(128,32), 0, _T("ID_STATICTEXTlblUnBalSL"));
	lblTypeFR = new wxStaticText(pnlRoofData, ID_STATICTEXTtypeFR, _("Type of Floating Roof*\t\t\t\t"), wxPoint(624,336), wxDefaultSize, 0, _T("ID_STATICTEXTtypeFR"));
	lblMaterialRoof = new wxStaticText(pnlRoofData, ID_STATICTEXTlblMaterialRoof, _("Material of Roof"), wxPoint(624,24), wxDefaultSize, 0, _T("ID_STATICTEXTlblMaterialRoof"));
	lblJEff = new wxStaticText(pnlRoofData, ID_STATICTEXTlblJEff, _("Joint Efficiency for Roof Plate Joint*"), wxPoint(32,570), wxSize(112,32), 0, _T("ID_STATICTEXTlblJEff"));
	lblTHickness = new wxStaticText(pnlRoofData, ID_STATICTEXTlblThickness, _("Required Thickness of Roof (mm)*\t\t\t"), wxPoint(624,64), wxSize(128,32), 0, _T("ID_STATICTEXTlblThickness"));
	txtRequiredThickness = new wxTextCtrl(pnlRoofData, ID_TEXTCTRL61, wxEmptyString, wxPoint(784,56), wxSize(248,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL61"));
	txtMaxSpace1 = new wxTextCtrl(pnlRoofData, ID_TEXTCTRLtxtMaxSpace1, wxEmptyString, wxPoint(784,112), wxSize(248,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtMaxSpace1"));
	txtMaxSpace1->Disable();
	txtMaxSpace1->Hide();
	txtMaxSpace2 = new wxTextCtrl(pnlRoofData, ID_TEXTCTRLtxtMaxSpace2, wxEmptyString, wxPoint(784,160), wxSize(248,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtMaxSpace2"));
	txtMaxSpace2->Disable();
	txtMaxSpace2->Hide();
	lblWtNozzle = new wxStaticText(pnlRoofData, ID_STATICTEXTlblWeightNozzle, _("Weight of Roof nozzles and other roof appurtenances*"), wxPoint(624,224), wxSize(160,48), 0, _T("ID_STATICTEXTlblWeightNozzle"));
	lblWeightFR = new wxStaticText(pnlRoofData, ID_STATICTEXTlblWeightFR, _("Weight of Floating Roof (Kg)"), wxPoint(624,376), wxSize(128,32), 0, _T("ID_STATICTEXTlblWeightFR"));
	lblSlopeRoof = new wxStaticText(pnlRoofData, ID_STATICTEXTlblSlopeRoof, _("Slope Of Roof*"), wxPoint(32,360), wxSize(120,24), 0, _T("ID_STATICTEXTlblSlopeRoof"));
	lblSlopeRoof->Hide();
	lblDomeRadius = new wxStaticText(pnlRoofData, ID_STATICTEXTlblDomeRadius, _("Dome Radius (M)*"), wxPoint(32,400), wxDefaultSize, 0, _T("ID_STATICTEXTlblDomeRadius"));
	lblDomeRadius->Hide();
	lblMaxSpace = new wxStaticText(pnlRoofData, ID_STATICTEXTlblMaxSpace, _("Maximum Spacing between rafters (M)*\t\t\t\t"), wxPoint(624,112), wxSize(144,40), 0, _T("ID_STATICTEXTlblMaxSpace"));
	lblMaxSpace->Hide();
	lblMaxSpacePeri = new wxStaticText(pnlRoofData, ID_STATICTEXTlblMaxSPacePeri, _("Maximum Spacing between rafters at Periphery / Centre(M)\t*"), wxPoint(624,160), wxSize(152,40), 0, _T("ID_STATICTEXTlblMaxSPacePeri"));
	lblMaxSpacePeri->Hide();
	txtRRoof = new wxTextCtrl(pnlRoofData, ID_TEXTCTRLtxtRRoof, wxEmptyString, wxPoint(200,120), wxSize(248,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtRRoof"));
	txtRRoof->SetBackgroundColour(wxColour("PINK"));
	lblRoofTypeAdopted = new wxStaticText(pnlRoofData, ID_STATICTEXTlblRoofTypeAdopted, _("Roof Type Adopted"), wxPoint(32,72), wxSize(136,24), 0, _T("ID_STATICTEXTlblRoofTypeAdopted"));
	txtRoofTypeAdopted = new wxTextCtrl(pnlRoofData, ID_TEXTCTRLtxtRoofTypeAdopted, wxEmptyString, wxPoint(200,72), wxSize(248,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtRoofTypeAdopted"));
	txtRoofTypeAdopted->Disable();
	cmbFrangible = new wxChoice(pnlRoofData, ID_CHOICEFrangible, wxPoint(200,168), wxSize(248,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICEFrangible"));
	cmbFrangible->Append(_("NO"));
	cmbFrangible->Append(_("YES"));
	txtLiveLoad = new wxTextCtrl(pnlRoofData, ID_TEXTCTRLtxtLiveLoad, wxEmptyString, wxPoint(200,232), wxSize(248,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtLiveLoad"));
	txtLiveLoad->SetBackgroundColour(wxColour("PINK"));
	txtBalancedSL = new wxTextCtrl(pnlRoofData, ID_TEXTCTRLtxtBalancedSL, wxEmptyString, wxPoint(200,272), wxSize(248,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtBalancedSL"));
	txtBalancedSL->SetBackgroundColour(wxColour("PINK"));
	txtUnBalancedSL = new wxTextCtrl(pnlRoofData, ID_TEXTCTRLtxtUnBalancedSL, wxEmptyString, wxPoint(200,312), wxSize(248,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtUnBalancedSL"));
	txtUnBalancedSL->SetBackgroundColour(wxColour("PINK"));
	txtDomeRadius = new wxTextCtrl(pnlRoofData, ID_TEXTCTRLtxtDomeRadius, wxEmptyString, wxPoint(200,395), wxSize(248,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtDomeRadius"));
	txtDomeRadius->SetBackgroundColour(wxColour(100,255,200));
	lblWeightGeodesicRoof = new wxStaticText(pnlRoofData, ID_STATICTEXTwtGeodesicRoof, _("Weight of Geodesic Roof (Kg)"), wxPoint(32,448), wxSize(128,40), 0, _T("ID_STATICTEXTwtGeodesicRoof"));
	txtWtGeodesicRoof = new wxTextCtrl(pnlRoofData, ID_TEXTCTRLWtGeodesicRoof, wxEmptyString, wxPoint(200,448), wxSize(248,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLWtGeodesicRoof"));
	txtWtGeodesicRoof->SetBackgroundColour(wxColour("PINK"));
	txtMaterialRoof = new wxTextCtrl(pnlRoofData, ID_TEXTCTRLtxtMaterialRoof, wxEmptyString, wxPoint(784,16), wxSize(248,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtMaterialRoof"));
	txtMaterialRoof->SetBackgroundColour(wxColour(100,255,200));
	txtWeightNozzle = new wxTextCtrl(pnlRoofData, ID_TEXTCTRLtxtWeightNozzle, wxEmptyString, wxPoint(784,224), wxSize(248,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtWeightNozzle"));
	txtWeightNozzle->SetBackgroundColour(wxColour("PINK"));
	cmbTypeFloatingRoof = new wxChoice(pnlRoofData, ID_CHOICEFR, wxPoint(784,328), wxSize(248,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICEFR"));
	cmbTypeFloatingRoof->Append(_("Single Deck FLoating Roof"));
	cmbTypeFloatingRoof->Append(_("Double Deck Floating Roof"));
	cmbTypeFloatingRoof->Append(_("Aluminium Floating Roof"));
	cmbTypeFloatingRoof->Append(_("None"));
	txtWeightFloatingRoof = new wxTextCtrl(pnlRoofData, ID_TEXTCTRLtxtWeightFloatingRoof, wxEmptyString, wxPoint(784,376), wxSize(248,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtWeightFloatingRoof"));
	txtWeightFloatingRoof->SetBackgroundColour(wxColour("PINK"));
	cmbJointEff = new wxChoice(pnlRoofData, ID_CHOICE20, wxPoint(200,570), wxSize(248,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE20"));
	cmbJointEff->Append(_("0.35"));
	cmbJointEff->Append(_("0.7"));
	cmbJointEff->Append(_("1"));
	lblCorrWeight = new wxStaticText(pnlRoofData, ID_STATICTEXT68, _("Corroded weight of \nRoof Structure"), wxPoint(32,510), wxDefaultSize, 0, _T("ID_STATICTEXT68"));
	txtCorrWeight = new wxTextCtrl(pnlRoofData, ID_TEXTCTRL20, wxEmptyString, wxPoint(200,510), wxSize(248,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL20"));
	txtCorrWeight->SetBackgroundColour(wxColour("PINK"));
	txtPercWeight = new wxTextCtrl(pnlRoofData, ID_TEXTCTRL49, wxEmptyString, wxPoint(784,448), wxSize(248,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL49"));
	txtPercWeight->SetBackgroundColour(wxColour("PINK"));
	lblPercWeight = new wxStaticText(pnlRoofData, ID_STATICTEXT69, _("% weight of Roof & Structure\nSupported By shell"), wxPoint(624,448), wxDefaultSize, 0, _T("ID_STATICTEXT69"));
	StaticText6 = new wxStaticText(pnlRoofData, ID_STATICTEXT70, _("%"), wxPoint(1032,450), wxSize(16,24), 0, _T("ID_STATICTEXT70"));
	Gauge1 = new wxGauge(pnlRoofData, ID_GAUGE1, 100, wxPoint(199,352), wxSize(70,23), 0, wxDefaultValidator, _T("ID_GAUGE1"));
	Gauge1->Disable();
	txtSlopeNum = new wxTextCtrl(pnlRoofData, ID_TEXTCTRL52, wxEmptyString, wxPoint(200,353), wxSize(32,21), wxTE_RIGHT|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL52"));
	txtSlopeNum->SetBackgroundColour(wxColour(100,255,200));
	StaticTextSlopeSlash = new wxStaticText(pnlRoofData, ID_STATICTEXT72, _("/"), wxPoint(232,353), wxSize(4,21), wxNO_BORDER, _T("ID_STATICTEXT72"));
	wxFont StaticTextSlopeSlashFont(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticTextSlopeSlash->SetFont(StaticTextSlopeSlashFont);
	StaticTextSlopeSlash->SetBackgroundColour(wxColour(100,255,200));
	txtSlopeDen = new wxTextCtrl(pnlRoofData, ID_TEXTCTRL50, wxEmptyString, wxPoint(236,353), wxSize(32,21), wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL50"));
	txtSlopeDen->SetBackgroundColour(wxColour(100,255,200));
	BtnRoofData = new wxButton(pnlRoofData, ID_BUTTON9, _("Design"), wxPoint(552,552), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
	pnlRoofToShell = new wxPanel(NotebookInputScreen_1, ID_PANEL34, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL34"));
	cmbTypeCR = new wxChoice(pnlRoofToShell, ID_CHOICEcmbTypeCR, wxPoint(352,208), wxSize(168,60), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICEcmbTypeCR"));
	cmbTypeCR->SetSelection( cmbTypeCR->Append(_("Type-a")) );
	cmbTypeCR->Append(_("Type-b"));
	cmbTypeCR->Append(_("Type-c"));
	cmbTypeCR->Append(_("Type-d"));
	cmbTypeCR->Append(_("Type-e"));
	cmbTypeCR->Append(_("Type-f"));
	cmbTypeCR->Append(_("Type-g"));
	cmbTypeCR->Append(_("Type-h"));
	cmbTypeCR->Append(_("Type-i"));
	cmbTypeCR->Append(_("Type-k"));
	StaticBitmap1 = new wxStaticBitmap(pnlRoofToShell, ID_STATICBITMAP, wxNullBitmap, wxPoint(896,8), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP"));
	StaticBitmap1->Hide();
	StaticTextud = new wxStaticText(pnlRoofToShell, ID_STATICTEXTud, _("USER DEFINED"), wxPoint(352,24), wxDefaultSize, 0, _T("ID_STATICTEXTud"));
	wxFont StaticTextudFont(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("@Adobe Gothic Std B"),wxFONTENCODING_DEFAULT);
	StaticTextud->SetFont(StaticTextudFont);
	StaticTextreq = new wxStaticText(pnlRoofToShell, ID_STATICTEXT88req, _("Required"), wxPoint(312,56), wxDefaultSize, 0, _T("ID_STATICTEXT88req"));
	wxFont StaticTextreqFont(11,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("@Adobe Gothic Std B"),wxFONTENCODING_DEFAULT);
	StaticTextreq->SetFont(StaticTextreqFont);
	StaticTextaval = new wxStaticText(pnlRoofToShell, ID_STATICTEXTaval, _("Available"), wxPoint(480,56), wxDefaultSize, 0, _T("ID_STATICTEXTaval"));
	wxFont StaticTextavalFont(11,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("@Adobe Gothic Std B"),wxFONTENCODING_DEFAULT);
	StaticTextaval->SetFont(StaticTextavalFont);
	txtCrossSecInternalPressureReq = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtCrossSecInternalPressureReq, wxEmptyString, wxPoint(248,104), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtCrossSecInternalPressureReq"));
	txtCrossSecInternalPressureReq->Disable();
	txtCrossSecExternalPressureReq = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtCrossSecExternalPressureReq, wxEmptyString, wxPoint(248,136), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtCrossSecExternalPressureReq"));
	txtCrossSecExternalPressureReq->Disable();
	txtMIExternalPressureReq = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtMIExternalPressureReq, wxEmptyString, wxPoint(248,168), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtMIExternalPressureReq"));
	txtMIExternalPressureReq->Disable();
	txtCrossSecInternalPressureAvail = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtCrossSecInternalPressureAvail, wxEmptyString, wxPoint(432,104), wxSize(192,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtCrossSecInternalPressureAvail"));
	txtCrossSecInternalPressureAvail->Disable();
	txtCrossSecExternalPressureAvail = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtCrossSecExternalPressureAvail, wxEmptyString, wxPoint(432,136), wxSize(192,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtCrossSecExternalPressureAvail"));
	txtCrossSecExternalPressureAvail->Disable();
	txtMIExternalPressureAvail = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtMIExternalPressureAvail, wxEmptyString, wxPoint(432,168), wxSize(192,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtMIExternalPressureAvail"));
	txtMIExternalPressureAvail->Disable();
	StaticTextlblCrossInt = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblCrossInt, _("Cross sectional Area of Compression Ring  For Internal Pressure"), wxPoint(8,104), wxSize(224,32), 0, _T("ID_STATICTEXTlblCrossInt"));
	lblCrossExt = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblCrossExt, _("Cross sectional Area of Compression Ring  For External Pressure"), wxPoint(8,136), wxSize(224,32), 0, _T("ID_STATICTEXTlblCrossExt"));
	lblMIExt = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblMIExt, _("Moment Of Inertia  of Compression Ring  For External Pressure"), wxPoint(8,168), wxSize(224,32), 0, _T("ID_STATICTEXTlblMIExt"));
	lblTypeCR = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblTypeCR, _("Type of Compression Ring"), wxPoint(32,216), wxSize(184,24), 0, _T("ID_STATICTEXTlblTypeCR"));
	wxFont lblTypeCRFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	lblTypeCR->SetFont(lblTypeCRFont);
	lblThickness = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblThick, _("Thickness"), wxPoint(256,232), wxSize(56,24), 0, _T("ID_STATICTEXTlblThick"));
	lblWidth = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblWidth, _("Total Width"), wxPoint(328,232), wxSize(40,32), 0, _T("ID_STATICTEXTlblWidth"));
	lblProj = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblProj, _("External Projection-L "), wxPoint(384,232), wxSize(72,32), 0, _T("ID_STATICTEXTlblProj"));
	txtCRSize1 = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtCRSize1, wxEmptyString, wxPoint(248,264), wxSize(192,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtCRSize1"));
	txtCRSize2 = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtCRSize2, wxEmptyString, wxPoint(248,288), wxSize(192,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtCRSize2"));
	txtTBar = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtTbar, wxEmptyString, wxPoint(248,320), wxSize(64,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtTbar"));
	txtWBar = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtWBar, wxEmptyString, wxPoint(312,320), wxSize(64,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtWBar"));
	txtLBar = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtLBar, wxEmptyString, wxPoint(376,320), wxSize(64,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtLBar"));
	txtTShell = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtTShell, wxEmptyString, wxPoint(248,352), wxSize(64,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtTShell"));
	txtWShell = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtWShell, wxEmptyString, wxPoint(312,352), wxSize(64,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtWShell"));
	lblUser1 = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblUser1, _("Size of Added Angle"), wxPoint(8,264), wxSize(176,24), 0, _T("ID_STATICTEXTlblUser1"));
	lblUser2 = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblUser2, _("Size of Added Angle Inside"), wxPoint(8,288), wxSize(184,24), 0, _T("ID_STATICTEXTlblUser2"));
	lblUser3 = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblUser3, _("Thickness & Width of Bar welded to shell. mm"), wxPoint(8,320), wxSize(232,32), 0, _T("ID_STATICTEXTlblUser3"));
	lblUser4 = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblUser4, _("Label"), wxPoint(8,352), wxSize(184,13), 0, _T("ID_STATICTEXTlblUser4"));
	lblMaterialCR = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblMaterialCR, _("Material Of Construction"), wxPoint(480,232), wxDefaultSize, 0, _T("ID_STATICTEXTlblMaterialCR"));
	txtCRMaterial0 = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtCRMaterial0, wxEmptyString, wxPoint(456,264), wxSize(176,48), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtCRMaterial0"));
	txtCRMaterial2 = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtCRMaterial2, wxEmptyString, wxPoint(456,320), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtCRMaterial2"));
	txtCRMaterial1 = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtCRMaterial1, wxEmptyString, wxPoint(456,352), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtCRMaterial1"));
	StaticTextad = new wxStaticText(pnlRoofToShell, ID_STATICTEXT88, _("ADOPTED"), wxPoint(928,24), wxDefaultSize, 0, _T("ID_STATICTEXT88"));
	wxFont StaticTextadFont(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("@Adobe Gothic Std B"),wxFONTENCODING_DEFAULT);
	StaticTextad->SetFont(StaticTextadFont);
	cmbTypeCRAD = new wxChoice(pnlRoofToShell, ID_CHOICEcmbTypeCRAD, wxPoint(896,208), wxSize(176,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICEcmbTypeCRAD"));
	cmbTypeCRAD->SetSelection( cmbTypeCRAD->Append(_("Type-a")) );
	cmbTypeCRAD->Append(_("Type-b"));
	cmbTypeCRAD->Append(_("Type-c"));
	cmbTypeCRAD->Append(_("Type-d"));
	cmbTypeCRAD->Append(_("Type-e"));
	cmbTypeCRAD->Append(_("Type-f"));
	cmbTypeCRAD->Append(_("Type-g"));
	cmbTypeCRAD->Append(_("Type-h"));
	cmbTypeCRAD->Append(_("Type-i"));
	cmbTypeCRAD->Append(_("Type-k"));
	cmbTypeCRAD->Disable();
	lblTCR_AD = new wxStaticText(pnlRoofToShell, ID_TCRAD, _("Type of Compression Ring"), wxPoint(688,208), wxDefaultSize, 0, _T("ID_TCRAD"));
	wxFont lblTCR_ADFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	lblTCR_AD->SetFont(lblTCR_ADFont);
	lblThicknessAD = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblThickNessAD, _("Thickness"), wxPoint(888,232), wxDefaultSize, 0, _T("ID_STATICTEXTlblThickNessAD"));
	lblWidthAD = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblWidthAD, _("Total Width"), wxPoint(976,232), wxSize(64,24), 0, _T("ID_STATICTEXTlblWidthAD"));
	lblProjAD = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblProjAD, _("External Projection-L"), wxPoint(1064,232), wxSize(72,32), 0, _T("ID_STATICTEXTlblProjAD"));
	lblUser1AD = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblAD1, _("Size of Added Angle"), wxPoint(680,264), wxSize(120,13), 0, _T("ID_STATICTEXTlblAD1"));
	lblUser2AD = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblAD2, _("Size of Added Angle Inside"), wxPoint(680,296), wxDefaultSize, 0, _T("ID_STATICTEXTlblAD2"));
	lblUser3AD = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblAD3, _("Label"), wxPoint(680,320), wxDefaultSize, 0, _T("ID_STATICTEXTlblAD3"));
	lblUser4AD = new wxStaticText(pnlRoofToShell, ID_STATICTEXTlblAD4, _("Label"), wxPoint(680,352), wxDefaultSize, 0, _T("ID_STATICTEXTlblAD4"));
	txtCRSize1AD = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtTypeCR1AD, wxEmptyString, wxPoint(896,264), wxSize(216,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtTypeCR1AD"));
	txtCRSize1AD->Disable();
	txtCRSize2AD = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtTypeCR2AD, wxEmptyString, wxPoint(896,288), wxSize(216,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtTypeCR2AD"));
	txtCRSize2AD->Disable();
	txtTBarAD = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtTBarAD, wxEmptyString, wxPoint(896,312), wxSize(72,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtTBarAD"));
	txtTBarAD->Disable();
	txtWBarAD = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtWBarAD, wxEmptyString, wxPoint(968,312), wxSize(72,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtWBarAD"));
	txtWBarAD->Disable();
	txtLBarAD = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtLBarAD, wxEmptyString, wxPoint(1040,312), wxSize(72,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtLBarAD"));
	txtLBarAD->Disable();
	txtTShellAD = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLtxtTShellAD, wxEmptyString, wxPoint(896,344), wxSize(72,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtTShellAD"));
	txtTShellAD->Disable();
	txtWShellAD = new wxTextCtrl(pnlRoofToShell, ID_TEXTCTRLWShell, wxEmptyString, wxPoint(968,344), wxSize(72,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLWShell"));
	txtWShellAD->Disable();
	pnlBottomPlateAnchorDesign = new wxPanel(NotebookInputScreen_1, ID_PANEL36, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL36"));
	lblThicknessBottomPlate = new wxStaticText(pnlBottomPlateAnchorDesign, ID_STATICTEXTlblThicknessBottomPlate, _("Thickness of Bottom plate\t\t"), wxPoint(64,40), wxDefaultSize, 0, _T("ID_STATICTEXTlblThicknessBottomPlate"));
	lblReqAnnular = new wxStaticText(pnlBottomPlateAnchorDesign, ID_STATICTEXTlblReqAnnular, _("Requirement of Annular Plate as per code\t\t"), wxPoint(64,88), wxDefaultSize, 0, _T("ID_STATICTEXTlblReqAnnular"));
	lblThicknessAnnularPlate = new wxStaticText(pnlBottomPlateAnchorDesign, ID_STATICTEXTlblThicknessAnnularPlate, _("Thickness of Annular plate\t\t"), wxPoint(64,128), wxSize(149,24), 0, _T("ID_STATICTEXTlblThicknessAnnularPlate"));
	lblWidthAnnularPlate = new wxStaticText(pnlBottomPlateAnchorDesign, ID_STATICTEXTlblWidthAnnularPlate, _("Width of Annular plate\t\t"), wxPoint(64,176), wxSize(131,24), 0, _T("ID_STATICTEXTlblWidthAnnularPlate"));
	lblReqAnchorage = new wxStaticText(pnlBottomPlateAnchorDesign, ID_STATICTEXTlblReqAnchorage, _("Requirement of anchorage as per code\t\t"), wxPoint(64,224), wxSize(210,24), 0, _T("ID_STATICTEXTlblReqAnchorage"));
	lblNumAnchorBolts = new wxStaticText(pnlBottomPlateAnchorDesign, ID_STATICTEXTlblNumAnchorBolts, _("Number of Anchor Bolts \t\t"), wxPoint(64,272), wxSize(139,21), 0, _T("ID_STATICTEXTlblNumAnchorBolts"));
	lblNominalBoltDia = new wxStaticText(pnlBottomPlateAnchorDesign, ID_STATICTEXTlblNominalBoltDia, _("Nominal Bolt Dia\t\t"), wxPoint(64,328), wxSize(99,24), 0, _T("ID_STATICTEXTlblNominalBoltDia"));
	lblCorrosionAllowance = new wxStaticText(pnlBottomPlateAnchorDesign, ID_STATICTEXTlblCorrosionAllowance, _("Corrosion Allowance on Bolt\t\t"), wxPoint(64,376), wxDefaultSize, 0, _T("ID_STATICTEXTlblCorrosionAllowance"));
	lblYeildStrengthBoltMaterial = new wxStaticText(pnlBottomPlateAnchorDesign, ID_STATICTEXTlblYeildStrengthBoltMaterial, _("Yield Strength of Bolt Material\t\t"), wxPoint(64,424), wxSize(165,24), 0, _T("ID_STATICTEXTlblYeildStrengthBoltMaterial"));
	txtThicknessBottomPlate = new wxTextCtrl(pnlBottomPlateAnchorDesign, ID_TEXTCTRLtxtThicknessBottomPlate, wxEmptyString, wxPoint(320,32), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtThicknessBottomPlate"));
	cmbReqAnnular = new wxChoice(pnlBottomPlateAnchorDesign, ID_CHOICEcmbReqAnnular, wxPoint(320,80), wxSize(152,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICEcmbReqAnnular"));
	cmbReqAnnular->SetSelection( cmbReqAnnular->Append(_("YES")) );
	cmbReqAnnular->Append(_("NO"));
	txtThicknessAnnularPlate = new wxTextCtrl(pnlBottomPlateAnchorDesign, ID_TEXTCTRLtxtThicknessAnnularPlate, wxEmptyString, wxPoint(320,128), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtThicknessAnnularPlate"));
	txtWidthAnnularPlate = new wxTextCtrl(pnlBottomPlateAnchorDesign, ID_TEXTCTRLtxtWidthAnnularPlate, wxEmptyString, wxPoint(320,176), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtWidthAnnularPlate"));
	cmbReqAnchorage = new wxChoice(pnlBottomPlateAnchorDesign, ID_CHOICEcmbReqAnchorage, wxPoint(320,224), wxSize(152,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICEcmbReqAnchorage"));
	cmbReqAnchorage->SetSelection( cmbReqAnchorage->Append(_("YES")) );
	cmbReqAnchorage->Append(_("NO"));
	txtNumAnchorBolts = new wxTextCtrl(pnlBottomPlateAnchorDesign, ID_TEXTCTRLtxtNumAnchorBolts, wxEmptyString, wxPoint(320,272), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtNumAnchorBolts"));
	txtNominalBoltDia = new wxTextCtrl(pnlBottomPlateAnchorDesign, ID_TEXTCTRLtxtNominalBoltDia, wxEmptyString, wxPoint(320,320), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtNominalBoltDia"));
	txtCorrosionAllowance = new wxTextCtrl(pnlBottomPlateAnchorDesign, ID_TEXTCTRLtxtCorrosionAllowance, wxEmptyString, wxPoint(320,368), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtCorrosionAllowance"));
	txtYeildStrengthBoltMaterial = new wxTextCtrl(pnlBottomPlateAnchorDesign, ID_TEXTCTRLtxtYeildStrengthBoltMaterial, wxEmptyString, wxPoint(320,416), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtYeildStrengthBoltMaterial"));
	lblPadThickness = new wxStaticText(pnlBottomPlateAnchorDesign, ID_STATICTEXTlblPadThickness, _("Pad Thickness\t\t"), wxPoint(608,40), wxSize(90,24), 0, _T("ID_STATICTEXTlblPadThickness"));
	lblSpacingBetweenGussets = new wxStaticText(pnlBottomPlateAnchorDesign, ID_STATICTEXTlblSpacingBetweenGussets, _("Spacing Between Gussets (g)\t\t"), wxPoint(608,80), wxSize(163,24), 0, _T("ID_STATICTEXTlblSpacingBetweenGussets"));
	lblTopPlateLengthShell = new wxStaticText(pnlBottomPlateAnchorDesign, ID_STATICTEXTlblTopPlateLengthShell, _("Top Plate Length Along Shell (a)\t\t"), wxPoint(608,128), wxSize(176,32), 0, _T("ID_STATICTEXTlblTopPlateLengthShell"));
	lblTopPlateLengthRadial = new wxStaticText(pnlBottomPlateAnchorDesign, ID_STATICTEXTlblTopPlateLengthRadial, _("Top Plate Length Radial (b)\t\t"), wxPoint(608,176), wxSize(153,24), 0, _T("ID_STATICTEXTlblTopPlateLengthRadial"));
	lblTopPlateThickness = new wxStaticText(pnlBottomPlateAnchorDesign, ID_STATICTEXTlblTopPlateThickness, _("Top Plate Thickness\t\t"), wxPoint(608,232), wxSize(117,24), 0, _T("ID_STATICTEXTlblTopPlateThickness"));
	lblBoltEccentricity = new wxStaticText(pnlBottomPlateAnchorDesign, ID_STATICTEXTlblBoltEccentricity, _("Bolt Eccentricity (e)\t\t"), wxPoint(608,272), wxSize(116,24), 0, _T("ID_STATICTEXTlblBoltEccentricity"));
	lblAnchorChairHeight = new wxStaticText(pnlBottomPlateAnchorDesign, ID_STATICTEXTlblAnchorChairHeight, _("Anchor Chair height (h)\t\t"), wxPoint(608,328), wxSize(135,24), 0, _T("ID_STATICTEXTlblAnchorChairHeight"));
	lblVerticalPlateThickness = new wxStaticText(pnlBottomPlateAnchorDesign, ID_STATICTEXTlblVerticalPlateThickness, _("Vertical Plate Thickness (j)\t\t"), wxPoint(608,376), wxSize(148,24), 0, _T("ID_STATICTEXTlblVerticalPlateThickness"));
	lblAvgVerticalPlateWidth = new wxStaticText(pnlBottomPlateAnchorDesign, ID_STATICTEXTlblAvgVerticalPlateWidth, _("Average Vertical Plate Width (k)\t\t"), wxPoint(608,416), wxSize(176,24), 0, _T("ID_STATICTEXTlblAvgVerticalPlateWidth"));
	txtPadThickness = new wxTextCtrl(pnlBottomPlateAnchorDesign, ID_TEXTCTRLtxtPadThickness, wxEmptyString, wxPoint(808,32), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtPadThickness"));
	txtSpacingBetweenGussets = new wxTextCtrl(pnlBottomPlateAnchorDesign, ID_TEXTCTRLtxtSpacingBetweenGussets, wxEmptyString, wxPoint(808,80), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtSpacingBetweenGussets"));
	txtTopPlateLengthShell = new wxTextCtrl(pnlBottomPlateAnchorDesign, ID_TEXTCTRLtxtTopPlateLengthShell, wxEmptyString, wxPoint(808,128), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtTopPlateLengthShell"));
	txtTopPlateLengthRadial = new wxTextCtrl(pnlBottomPlateAnchorDesign, ID_TEXTCTRLtxtTopPlateLengthRadial, wxEmptyString, wxPoint(808,176), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtTopPlateLengthRadial"));
	txtTopPlateThickness = new wxTextCtrl(pnlBottomPlateAnchorDesign, ID_TEXTCTRLtxtTopPlateThickness, wxEmptyString, wxPoint(808,224), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtTopPlateThickness"));
	txtBoltEccentricity = new wxTextCtrl(pnlBottomPlateAnchorDesign, ID_TEXTCTRLtxtBoltEccentricity, wxEmptyString, wxPoint(808,272), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtBoltEccentricity"));
	txtAnchorChairHeight = new wxTextCtrl(pnlBottomPlateAnchorDesign, ID_TEXTCTRLtxtAnchorChairHeight, wxEmptyString, wxPoint(808,320), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtAnchorChairHeight"));
	txtVerticalPlateThickness = new wxTextCtrl(pnlBottomPlateAnchorDesign, ID_TEXTCTRLtxtVerticalPlateThickness, wxEmptyString, wxPoint(808,368), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtVerticalPlateThickness"));
	txtAvgVerticalPlateWidth = new wxTextCtrl(pnlBottomPlateAnchorDesign, ID_TEXTCTRLtxtAvgVerticalPlateWidth, wxEmptyString, wxPoint(808,416), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRLtxtAvgVerticalPlateWidth"));
	NotebookInputScreen_1->AddPage(pnlInputScreen_1, _("Design Data"), false);
	NotebookInputScreen_1->AddPage(pnlWindData, _("Wind Data"), false);
	NotebookInputScreen_1->AddPage(pnlSeismicData, _("Seismic Data"), false);
	NotebookInputScreen_1->AddPage(pnlShlDesMain, _("Shell Design"), false);
	NotebookInputScreen_1->AddPage(pnlMainPrimaryWindGirder, _("Primary Wind Girder Design"), false);
	NotebookInputScreen_1->AddPage(pnlStiffenerElevation, _("Stiffener Elevation"), false);
	NotebookInputScreen_1->AddPage(Panel1, _("Stiffener Size"), false);
	NotebookInputScreen_1->AddPage(pnlRoofData, _("Roof Data"), false);
	NotebookInputScreen_1->AddPage(pnlRoofToShell, _("Roof to Shell Junction"), false);
	NotebookInputScreen_1->AddPage(pnlBottomPlateAnchorDesign, _("Bottom Plate and Anchor Design"), false);
	BoxSizerControlsMain->Add(NotebookInputScreen_1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerMain->Add(BoxSizerControlsMain, 1, wxALL, 5);
	BoxSizerDlgButtons = new wxBoxSizer(wxHORIZONTAL);
	btnOk = new wxButton(this, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	btnOk->SetMaxSize(wxSize(60,25));
	BoxSizerDlgButtons->Add(btnOk, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	btnCancel = new wxButton(this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	btnCancel->SetMaxSize(wxSize(60,25));
	BoxSizerDlgButtons->Add(btnCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ButtonGenReport = new wxButton(this, ID_BUTTON8, _("Generate Report"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
	ButtonGenReport->SetMaxSize(wxSize(140,25));
	BoxSizerDlgButtons->Add(ButtonGenReport, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerMain->Add(BoxSizerDlgButtons, 0, wxALL|wxALIGN_LEFT|wxSHAPED, 5);
	SetSizer(BoxSizerMain);
	BoxSizerMain->Fit(this);
	BoxSizerMain->SetSizeHints(this);
	Center();

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&InputScreensDlg::OntxtDiaTankText);
	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbChoiceDiaTypeSelect);
	Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbChoiceAddDesignLqdHeadSelect);
	Connect(ID_CHOICE3,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbChoiceAppendixShellDesignSelect);
	Connect(ID_CHOICE21,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbJointEffcncyShellVertSeamsSelect);
	Connect(ID_CHOICE4,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbChoiceMethodShellThickCalcSelect);
	Connect(ID_CHOICE5,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbChoiceTypeFixedRoofSelect);
	Connect(ID_CHOICE18,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OnCmbRoundUpToSelect);
	Connect(ID_CHOICE19,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbOptionStfrSelect);
	Connect(ID_CHOICE6,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbChoiceCodeWindLoadSelect);
	Connect(ID_CHOICE7,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbChoiceExposureCatgorySelect);
	Connect(ID_CHOICE8,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbChoiceImportanceFactorSelect);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InputScreensDlg::OnwindDataRunButtonClick);
	Connect(ID_CHOICE9,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbChoiceSeismicDesignChoiceSelect);
	Connect(ID_CHOICE10,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbChoiceUBCZoneNoSelect);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InputScreensDlg::OnCalcFaFvBtnClick);
	Connect(ID_CHOICE11,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbChoiceGovByASCERulesSelect);
	Connect(ID_CHOICE12,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbChoiceSeismicUserGrpSelect);
	Connect(ID_CHOICE13,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbChoiceSeismicSiteClassSelect);
	Connect(ID_CHOICE14,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbChoiceVertSeismicEffectSelect);
	Connect(ID_GRID1,wxEVT_GRID_CELL_LEFT_CLICK,(wxObjectEventFunction)&InputScreensDlg::OnGrid1CellLeftClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InputScreensDlg::OnButtonRunShellClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InputScreensDlg::OnButtonDesignShellClick);
	Connect(ID_GRID44,wxEVT_GRID_CELL_LEFT_CLICK,(wxObjectEventFunction)&InputScreensDlg::OngridShellDesignLabelCellLeftClick);
	Connect(ID_CHOICE15,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbTopWGAsWalkwaySelect);
	Connect(ID_CHOICE16,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmblSizeTopAngleSelect);
	Connect(ID_CHOICE17,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmblDesignTopWGTankDiaSelect);
	Connect(ID_GRID6,wxEVT_GRID_CELL_LEFT_CLICK,(wxObjectEventFunction)&InputScreensDlg::OnGrid1CellLeftClick1);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InputScreensDlg::OnRunPWGClick1);
	Connect(ID_GRID2,wxEVT_GRID_CELL_LEFT_CLICK,(wxObjectEventFunction)&InputScreensDlg::OnGridStiffenerElevationCellLeftClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InputScreensDlg::OnButtonRunStiffenerElevationClick);
	Connect(ID_GRID5,wxEVT_GRID_CELL_LEFT_CLICK,(wxObjectEventFunction)&InputScreensDlg::OnGridStiffenerSizeCellLeftClick);
	Connect(ID_GRID5,wxEVT_GRID_CELL_CHANGED,(wxObjectEventFunction)&InputScreensDlg::OnGridStiffenerSizeCellChanged);
	Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InputScreensDlg::OnButtonRunStiffenerSizeClick);
	Connect(ID_CHOICEFrangible,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbFrangibleSelect2);
	Connect(ID_CHOICEFR,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbTypeFloatingRoofSelect1);
	Connect(ID_CHOICE20,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OnChoice1Select);
	Connect(ID_TEXTCTRL52,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&InputScreensDlg::OntxtSlopeNumText);
	Connect(ID_TEXTCTRL50,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&InputScreensDlg::OntxtSlopeDenText);
	Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InputScreensDlg::OnButton1Click1);
	pnlRoofData->Connect(wxEVT_PAINT,(wxObjectEventFunction)&InputScreensDlg::OnpnlRoofDataPaint,0,this);
	Connect(ID_CHOICEcmbTypeCR,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&InputScreensDlg::OncmbTypeCRSelect);
	Connect(ID_TEXTCTRLtxtCrossSecInternalPressureAvail,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&InputScreensDlg::OntxtCrossSecInternalPressureAvailText);
	Connect(ID_TEXTCTRLtxtCRMaterial0,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&InputScreensDlg::OntxtCRMaterial0Text);
	Connect(ID_TEXTCTRLtxtCRMaterial2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&InputScreensDlg::OntxtCRMaterial2Text);
	Connect(ID_NOTEBOOK1,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&InputScreensDlg::OnNotebookInputScreen_1PageChanged);
	Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InputScreensDlg::OnbtnOkClick);
	Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InputScreensDlg::OnButtonGenReportClick);
	//*)
	txtDiaTank->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtDiaTankKillFocus, 0, this);
	txtTankHeight->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtTankHeightKillFocus, 0, this);
	txtDesignPrdLvl->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtDesignPrdLvlKillFocus, 0, this);
	txtTestWaterLvl->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtTestWaterLvlKillFocus, 0, this);
	txtNormalLiqdLvl->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtNormalLiqdLvlKillFocus, 0, this);
	txtLiqdLvlSesDesign->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtLiqdLvlSesDesignKillFocus, 0, this);
	txtSpecificGrvtyHydroTest->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtSpecificGrvtyHydroTestKillFocus, 0, this);
	txtSpecificGrvtyStrdPrd->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtSpecificGrvtyStrdPrdKillFocus, 0, this);
	txtDesignTemp->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtDesignTempKillFocus, 0, this);
	txtDesignInternalPressure->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtDesignInternalPressureKillFocus, 0, this);
	txtPressureCmbFact->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtPressureCmbFactKillFocus, 0, this);
	txtDesignExtPressure->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtDesignExtPressureKillFocus, 0, this);
	txtCourseWidthFirstShellBtm->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtCourseWidthFirstShellBtmKillFocus, 0, this);
	txtCorrosionAllowanceFirstShllBtm->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtCorrosionAllowanceFirstShllBtmKillFocus, 0, this);
	txtCorrosionAllowanceBtmPlate->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtCorrosionAllowanceBtmPlateKillFocus, 0, this);
	txtCorrosionAllowanceFixedRoof->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtCorrosionAllowanceFixedRoofKillFocus, 0, this);


	txtExtPressureCmbFactor->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtExtPressureCmbFactorKillFocus, 0, this);
	txtPeakGroundAccel->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtPeakGroundAccelKillFocus, 0, this);
	txtASCESpectralAccelShort->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtASCESpectralAccelShortKillFocus, 0, this);
    txtASCESpectralAccelOneSec->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtASCESpectralAccelOneSecKillFocus, 0, this);
    txtTransitionLongGrnd->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtTransitionLongGrndKillFocus, 0, this);
    txtCoeffAdjust->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtCoeffAdjustKillFocus, 0, this);
    txtAccelBaseSiteCoeff->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtAccelBaseSiteCoeffKillFocus, 0, this);
    txtVelBasedSiteCoeff->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtVelBasedSiteCoeffKillFocus, 0, this);
    txtDesignWindVel->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtDesignWindVelKillFocus, 0, this);
    txtGustDesignWindSpeed->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtGustDesignWindSpeedKillFocus, 0, this);
    txtVelPressureExpCoeff->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtVelPressureExpCoeffKillFocus, 0, this);
    txtTopographicFactor->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtTopographicFactorKillFocus, 0, this);
    txtDirectionFactor->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtDirectionFactorKillFocus, 0, this);
    txtGustFactor->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtGustFactorKillFocus, 0, this);
    txtVelBasedSiteCoeff->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtVelBaseSiteCoeffKillFocus, 0, this);



    txtRRoof->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtRRoofKillFocus, 0, this);
    txtLiveLoad->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtLiveLoadKillFocus, 0, this);
    txtBalancedSL->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtBalancedSLKillFocus, 0, this);
    txtUnBalancedSL->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtUnBalancedSLKillFocus, 0, this);
    txtWeightFloatingRoof->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtWeightFloatingRoofKillFocus, 0, this);
    txtWeightNozzle->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtWeightNozzleKillFocus, 0, this);
    //txtWeightPlatform->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtWeightPlatformKillFocus, 0, this);
    //txtSlopeRoof->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtSlopeRoofKillFocus, 0, this);
    txtWtGeodesicRoof->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtWtGeodesicRoofKillFocus, 0, this);

    txtMaterialRoof->Connect(wxEVT_LEFT_DOWN, (wxObjectEventFunction)&InputScreensDlg::OntxtMaterialRoofLeftDClick, 0, this);
    txtCRMaterial0->Connect(wxEVT_LEFT_DOWN, (wxObjectEventFunction)&InputScreensDlg::OntxtCRMaterial0LeftDClick, 0, this);
    txtCRMaterial1->Connect(wxEVT_LEFT_DOWN, (wxObjectEventFunction)&InputScreensDlg::OntxtCRMaterial1LeftDClick, 0, this);
    txtCRMaterial2->Connect(wxEVT_LEFT_DOWN, (wxObjectEventFunction)&InputScreensDlg::OntxtCRMaterial2LeftDClick, 0, this);
    txtCRSize1->Connect(wxEVT_LEFT_DOWN, (wxObjectEventFunction)&InputScreensDlg::OntxtCRSize1LeftDClick, 0, this);
    txtCRSize2->Connect(wxEVT_LEFT_DOWN, (wxObjectEventFunction)&InputScreensDlg::OntxtCRSize2LeftDClick, 0, this);
    txtTBar->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtTBarKillFocus, 0, this);
    txtWBar->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtWBarKillFocus, 0, this);
    txtLBar->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtLBarKillFocus, 0, this);
    txtTShell->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtTShellKillFocus, 0, this);
    txtWShell->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtWShellKillFocus, 0, this);

    txtSpaceTopWGTopTank->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtSpaceTopWGTopTankKillFocus, 0, this);
    txtMinWidthTopWGAsWalkway->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtMinWidthTopWGAsWalkwayKillFocus, 0, this);


    TextNumStiffMax->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtNumStiffMaxKillFocus, 0, this);
    txtRequiredThickness->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtRequiredThicknessKillFocus, 0, this);

    txtCorrWeight->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtCorrWeightKillFocus, 0, this);
    txtPercWeight->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtPercWeightKillFocus, 0, this);

    txtSlopeDen->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtSlopeDenKillFocus, 0, this);
    txtSlopeNum->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtSlopeNumKillFocus, 0, this);

    txtDomeRadius->Connect(wxEVT_KILL_FOCUS, (wxObjectEventFunction)&InputScreensDlg::OntxtDomeRadiusKillFocus, 0, this);

    txtSlopeNum->MoveAfterInTabOrder(txtUnBalancedSL);
    txtSlopeDen->MoveAfterInTabOrder(txtSlopeNum);
    txtDomeRadius->MoveAfterInTabOrder(txtSlopeDen);
    txtCorrWeight->MoveAfterInTabOrder(txtWtGeodesicRoof);
    cmbJointEff->MoveAfterInTabOrder(txtCorrWeight);
    txtMaterialRoof->MoveAfterInTabOrder(cmbJointEff);
    txtRequiredThickness->MoveAfterInTabOrder(txtMaterialRoof);
    txtWeightNozzle->MoveAfterInTabOrder(txtRequiredThickness);

}

InputScreensDlg::~InputScreensDlg()
{
	//(*Destroy(InputScreensDlg)
	//*)
}


void InputScreensDlg::SetupValidators()
{
    setupInputScreen_1Validators();
    setupWindDataValidators();
    setupSeismicDataValidators();
    setupShellDesignValidators();
    setupPrimaryWindGirderDesignValidators();
    setupRoofDataValidators();
    setupRoofToShellValidators();
    setupStiffenerElevationValidators();
    setupStiffenerSizeValidators();
}

void InputScreensDlg::setupInputScreen_1Validators()
{

    wxFloatingPointValidator<double> validatorDoubleDiaTank(2, &(m_inputData->D_User), wxNUM_VAL_ZERO_AS_BLANK);
    txtDiaTank->SetValidator(validatorDoubleDiaTank);

    wxFloatingPointValidator<double> validatorDoubleTankHeight(2, &(m_inputData->H), wxNUM_VAL_ZERO_AS_BLANK);
    txtTankHeight->SetValidator(validatorDoubleTankHeight);

    wxFloatingPointValidator<double> validatorDoubleDesignPrdLvl(2, &(m_inputData->H_td_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtDesignPrdLvl->SetValidator(validatorDoubleDesignPrdLvl);

    wxFloatingPointValidator<double> validatorDoubleTestWaterLvl(2, &(m_inputData->H_tt_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtTestWaterLvl->SetValidator(validatorDoubleTestWaterLvl);

    wxFloatingPointValidator<double> validatorDoubleNormalLiqdLvl(2, &(m_inputData->H_Norm_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtNormalLiqdLvl->SetValidator(validatorDoubleNormalLiqdLvl);

    wxFloatingPointValidator<double> validatorDoubleLiqdLvlSesDesign(2, &(m_inputData->H_Seis_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtLiqdLvlSesDesign->SetValidator(validatorDoubleLiqdLvlSesDesign);

    wxFloatingPointValidator<double> validatorDoubleSpecificGrvtyStrdPrd(2, &(m_inputData->G), wxNUM_VAL_ZERO_AS_BLANK);
    txtSpecificGrvtyStrdPrd->SetValidator(validatorDoubleSpecificGrvtyStrdPrd);

    wxFloatingPointValidator<double> validatorDoubleSpecificGrvtyHydroTest(2, &(m_inputData->Gw), wxNUM_VAL_ZERO_AS_BLANK);
    //validatorDoubleSpecificGrvtyHydroTest.SetMin(1.0);
    txtSpecificGrvtyHydroTest->SetValidator(validatorDoubleSpecificGrvtyHydroTest);

    wxFloatingPointValidator<double> validatorDoubleDesignTemp(2, &(m_inputData->T), wxNUM_VAL_ZERO_AS_BLANK);
    //validatorDoubleDesignTemp.SetMax(260);
    txtDesignTemp->SetValidator(validatorDoubleDesignTemp);

    wxFloatingPointValidator<double> validatorDoubleMinDesignMetalTemp(2, &(m_inputData->MDMT));
    txtMinDesignMetalTemp->SetValidator(validatorDoubleMinDesignMetalTemp);

    wxFloatingPointValidator<double> validatorDoubleDesignInternalPressure(2, &(m_inputData->P), wxNUM_VAL_ZERO_AS_BLANK);
    //validatorDoubleDesignInternalPressure.SetMax(18.00);
    txtDesignInternalPressure->SetValidator(validatorDoubleDesignInternalPressure);

    wxFloatingPointValidator<double> validatorDoublePressureCmbFact(2, &(m_inputData->Fp), wxNUM_VAL_ZERO_AS_BLANK);
    //validatorDoublePressureCmbFact.SetMin(0.4);
    txtPressureCmbFact->SetValidator(validatorDoublePressureCmbFact);

    wxFloatingPointValidator<double> validatorDoubleDesignExtPressure(2, &(m_inputData->Pe), wxNUM_VAL_ZERO_AS_BLANK);
    //validatorDoubleDesignExtPressure.SetMax(6.9);
    txtDesignExtPressure->SetValidator(validatorDoubleDesignExtPressure);

    wxFloatingPointValidator<double> validatorDoubleExtPressureCmbFactor(2, &(m_inputData->Fpe), wxNUM_VAL_ZERO_AS_BLANK);
    //validatorDoubleExtPressureCmbFactor.SetMin(0.4);
    txtExtPressureCmbFactor->SetValidator(validatorDoubleExtPressureCmbFactor);

    wxFloatingPointValidator<double> validatorDoubleCourseWidthFirstShellBtm(2, &(m_inputData->shell_detail_user[0][1]), wxNUM_VAL_ZERO_AS_BLANK);
    txtCourseWidthFirstShellBtm->SetValidator(validatorDoubleCourseWidthFirstShellBtm);

    wxFloatingPointValidator<double> validatorDoubleCorrosionAllowanceFirstShllBtm(2, &(m_inputData->shell_detail_user[0][2]), wxNUM_VAL_ZERO_AS_BLANK);
    txtCorrosionAllowanceFirstShllBtm->SetValidator(validatorDoubleCorrosionAllowanceFirstShllBtm);


    wxFloatingPointValidator<double> validatorDoubleCorrosionAllowanceBtmPlate(2, &(m_inputData->CA_Bot), wxNUM_VAL_ZERO_AS_BLANK);
    txtCorrosionAllowanceBtmPlate->SetValidator(validatorDoubleCorrosionAllowanceBtmPlate);

    wxFloatingPointValidator<double> validatorDoubleCorrosionAllowanceFixedRoof(2, &(m_inputData->CA_Roof), wxNUM_VAL_ZERO_AS_BLANK);
    txtCorrosionAllowanceFixedRoof->SetValidator(validatorDoubleCorrosionAllowanceFixedRoof);

    wxFloatingPointValidator<double> validatorDoubleWtSpiralStairway(2, &(m_inputData->weight_stair_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtWtSpiralStairway->SetValidator(validatorDoubleWtSpiralStairway);

    wxFloatingPointValidator<double> validatorDoubleIncWtShellNozzleOtherShellApptnces(2, &(m_inputData->weight_adder_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtIncWtShellNozzleOtherShellApptnces->SetValidator(validatorDoubleIncWtShellNozzleOtherShellApptnces);
}

void InputScreensDlg::OnNotebookInputScreen_1PageChanged(wxNotebookEvent& event)
{
    int currentlySelectedPage = event.GetSelection();
    int previouslySelectedPage = event.GetOldSelection();
    MaterialSelection materialSelectDlg(this);

    if(ItemUIUtils::NB_PAGE_INPUT_SCREEN_1 == previouslySelectedPage)
    {
        transferInputScreen_1WindowData();
    }
    else if(ItemUIUtils::NB_PAGE_WIND_DATA == previouslySelectedPage)
    {
        transferWindDataWindowData();
    }
    else if(ItemUIUtils::NB_PAGE_SHELL_DESIGN == previouslySelectedPage)
    {
        wxCommandEvent event;
        OnButtonDesignShellClick(event);
    }
    else if(ItemUIUtils::NB_PAGE_ROOF_DATA==previouslySelectedPage)
    {
        if(validateRoofDataEntries())//later this should be moved to generate report, cause we don't care whether the user has saved each and evey data or not
        {                            // but surely, we are concerned about having everything before report generation
            ReadVariables(*m_inputData);
            Roof_Data();
            PopulateVariables(*m_inputData);
        }
    }

    if(ItemUIUtils::NB_PAGE_SHELL_DESIGN == currentlySelectedPage)
    {
        //validate if data from input screen 1 is available
        if(validateInputScreen_1Entries())
        {
            //call the functions
            // InitVariables();
            ReadVariables(*m_inputData);
            Input_Screen_1();
            Wind_Data();
            Seismic_Data();
            PopulateVariables(*m_inputData);

            double courseWidth = 0.0F;
            txtCourseWidthFirstShellBtm->GetValue().ToDouble(&courseWidth);

            m_inputData->shell_detail_user[0][1] = courseWidth;
            m_inputData->shell_detail[0][0] = m_inputData->shell_detail_user[0][1];

            string material_name;
            m_inputData->H_Remaining = m_inputData->H;
            for(int i=0;i<m_inputData->No_of_ShellCourses;i++)
            {
                gridShellDesign->SetCellValue(i,2,wxString::Format("%.3f",m_inputData->shell_detail_user[i][1]));
                gridShellDesign->SetCellValue(i,5,wxString::Format("%.3f",m_inputData->shell_detail_user[i][1]));
                m_inputData->H_Remaining -= m_inputData->shell_detail_user[i][1];

                m_inputData->shell_detail[i][9] = m_inputData->shell_detail_user[i][2];

                if(i>0)
                {
                    ChangeReadabilityShellDesign(i,false);
                    double CA = 0.0F;
                    CA = m_inputData->shell_detail_user[i][2];
                    if (CA < 0.001)
                        m_inputData->shell_detail[i][9] = m_inputData->shell_detail[(i - 1)][9];
                    else if (CA < 0.1)
                        m_inputData->shell_detail[i][9] = 0;
                    else
                        m_inputData->shell_detail[i][9] = m_inputData->shell_detail_user[i][2];
                }
                gridShellDesign->SetCellValue(i,3,wxString::Format("%.2f",m_inputData->shell_detail_user[i][2]));
                gridShellDesign->SetCellValue(i,6,wxString::Format("%.2f",m_inputData->shell_detail[i][9]));

                if(m_inputData->Shell_Material_No[i][0]==0)
                    gridShellDesign->SetCellValue(i,1, material_name);
                else
                {
                        material_name = materialSelectDlg.radioBoxMaterial->GetString(materialSelectDlg.materialNumberToIndex(m_inputData->Shell_Material_No[i][0]));
                        gridShellDesign->SetCellValue(i,1, materialSelectDlg.radioBoxMaterial->GetString(materialSelectDlg.materialNumberToIndex(m_inputData->Shell_Material_No[i][0])));
                }

                //setting up user defined thickness
                gridShellDesign->SetCellValue(i,10,wxString::Format("%.2f",m_inputData->shell_detail_user[i][3]));
            }
            wxCommandEvent event;
            OnButtonDesignShellClick(event);
        }

    }
    else if(ItemUIUtils::NB_PAGE_PRIMARY_WIND_GIRDER_DESIGN == currentlySelectedPage)
    {
        if (m_inputData->Roof_Type_No > 6)
        {
            Gridpwg->Enable();
            pnlMainPrimaryWindGirder->Show();
            if(validateshelldesignwindow())
            {
                //call pwg_properties function
                // InitVariables();
                ReadVariables(*m_inputData);
                Input_Screen_1();
                Wind_Data();
                Seismic_Data();
                shell_Details();
                PWG_Data();
                PopulateVariables(*m_inputData);
                updatePrimaryWindGirderScreen();
                stretchLastCol(Gridpwg);
                setPrimaryWindGirderDesignInitialControlValues();
            }
        }
        else
        {
            pnlMainPrimaryWindGirder->Show(false);
            Gridpwg->Disable();
        }
    }

    else if(ItemUIUtils::NB_PAGE_ROOF_TO_SHELL == currentlySelectedPage)
    {

        if(!m_isNewData && m_inputData->CR_Type_No[1]>0)
        {
        wxString image_num = wxString::Format(wxT("%d"), (int)m_inputData->CR_Type_No[1]);
        StaticBitmap = new wxStaticBitmap(this, ID_STATICBITMAP, wxBitmap(wxImage(_T("Images/"+image_num+".PNG"),wxBITMAP_TYPE_PNG)), wxPoint(300,430),wxSize(270,200));
        }

        else
        {
        StaticBitmap = new wxStaticBitmap(this, ID_STATICBITMAP, wxBitmap(wxImage(_T("Images/1.PNG"),wxBITMAP_TYPE_PNG)), wxPoint(300,430),wxSize(270,200));
        }

    }
    else if(ItemUIUtils::NB_PAGE_STIFFENER_ELEVATION == currentlySelectedPage)
    {
        if((m_inputData->Roof_Type_No > 6 && validatePwgDataWindow())||(m_inputData->Roof_Type_No <= 6 && validateshelldesignwindow()))
        {
            InitVariables();
            ReadVariables(*m_inputData);
            Input_Screen_1();
            Wind_Data();
            Seismic_Data();
            shell_Details();

            if (m_inputData->Roof_Type_No > 6)
            {    PWG_Data();
            }
            else
                shell_Stiffener_Location();

            shell_Stfr_User_EL_Data();

            PopulateVariables(*m_inputData);

            setStiffenerElevationControlStates();
            setStiffenerElevationInitialControlValues();
        }
    }
    else if(ItemUIUtils::NB_PAGE_STIFFENER_SIZE == currentlySelectedPage)
    {
        if((m_inputData->Roof_Type_No > 6 && validatePwgDataWindow())||(m_inputData->Roof_Type_No <= 6 && validateshelldesignwindow()))
        {
            // InitVariables();
            ReadVariables(*m_inputData);
            Input_Screen_1();
            Wind_Data();
            Seismic_Data();
            shell_Details();
            if (m_inputData->Roof_Type_No > 6)
                PWG_Data();
            else
                shell_Stiffener_Location();

            shell_Stfr_User_EL();
            shell_Stiffener_Properties();
            Stiffener_Prop_User_Data();
            PopulateVariables(*m_inputData);
            setStiffenerSizeControlStates();
            setStiffenerSizeInitialControlValues();
        }
    }
    else if(ItemUIUtils::NB_PAGE_SEISMIC_DATA == currentlySelectedPage)
    {
        if(validateInputScreen_1Entries())
        {
            ReadVariables(*m_inputData);
            Input_Screen_1();
            Wind_Data();
            PopulateVariables(*m_inputData);
        }
    }
    else if(ItemUIUtils::NB_PAGE_WIND_DATA == currentlySelectedPage)
    {
        validateInputScreen_1Entries();
    }
    else if(ItemUIUtils::NB_PAGE_ROOF_DATA == currentlySelectedPage)
    {
        if(validateshelldesignwindow())
        {
            ReadVariables(*m_inputData);
            Input_Screen_1();
            Wind_Data();
            Seismic_Data();
            shell_Details();
            if (m_inputData->Roof_Type_No_user > 6)
                PWG_Data();
            else
                shell_Stiffener_Location();

            shell_Stfr_User_EL();
            shell_Stiffener_Properties();
            Stiffener_Prop_User_Data();
            weight_cal();
            if(validateRoofDataEntries())
                Roof_Data();
            PopulateVariables(*m_inputData);
            setRoofDataInitialControlStates();
            setRoofDataInitialControlValues();
        }
    }
    event.Skip();
}


void InputScreensDlg::stretchLastCol(wxGrid *myGrid)
{
    int colWidths = 0;
    int n;
    n = m_inputData->D_User>61?myGrid->GetNumberCols():(myGrid->GetNumberCols()-1);
    for (int i = 0; i < n - 1; i++)
        colWidths += myGrid->GetColSize (i);

    colWidths+=myGrid->GetRowLabelSize();

    int finalColWidth = myGrid->GetSize().x - colWidths;
    myGrid->SetColSize (n - 1, finalColWidth);
}

bool InputScreensDlg::validateshelldesignwindow()
{
    if(!validateInputScreen_1Entries())
        return false;

    if(!validateSeismicWindow())
        return false;
    m_inputData->H_Remaining = m_inputData->H;
    for(int i=0;i<m_inputData->No_of_ShellCourses;i++)
    {
        m_inputData->H_Remaining-=m_inputData->shell_detail_user[i][1];
    }

    if(!(m_inputData->H_Remaining<=0.0001))
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_SHELL_DESIGN);
        wxMessageBox("Please add the shell courses first.", "Shell Design");
        wxNotebookEvent event;
        event.SetSelection(ItemUIUtils::NB_PAGE_SHELL_DESIGN);
        event.SetOldSelection(-1);
        OnNotebookInputScreen_1PageChanged(event);
        return false;
    }
    return true;
}

bool InputScreensDlg::validateSeismicWindow()
{
    if(txtAccelBaseSiteCoeff->GetValue().empty())
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_SEISMIC_DATA);
        wxMessageBox("Please click on run button to update values.", "Seismic Data");
        return false;
    }
    return true;
}

bool InputScreensDlg::validatePwgDataWindow()
{
    if(!validateshelldesignwindow())
        return false;

    for(int i=11;i<15;i++)
    {
        if(m_inputData->PWG_details[i]>0)
            return true;
    }
    changeActiveNotebookPage(ItemUIUtils::NB_PAGE_PRIMARY_WIND_GIRDER_DESIGN);
    wxMessageBox("Please design primary wind girder first", "PWG");
    wxNotebookEvent event;
    event.SetSelection(ItemUIUtils::NB_PAGE_PRIMARY_WIND_GIRDER_DESIGN);
    event.SetOldSelection(-1);
    OnNotebookInputScreen_1PageChanged(event);
    return false;
}
void InputScreensDlg::SetInitialControlValues()
{
    setInputScreen1InitialControlValues();
    setWindDataInitialControlValues();
    setSeismicDataInitialControlValues();
    setShellDesignInitialControlValues();
    setPrimaryWindGirderDesignInitialControlValues();
    setRoofDataInitialControlValues();
    setRoofToShellInitialControlValues();
    setStiffenerElevationInitialControlValues();
    setStiffenerSizeInitialControlValues();
}

void InputScreensDlg::setInputScreen1InitialControlValues()
{
	//DISABLING A PAGE
	//NotebookInputScreen_1->GetPage(4)->Disable();

    const int FLOAT_VALUE_PRECISION = 2;
    txtDiaTank->ChangeValue("");
    cmbChoiceDiaType->SetSelection(diameterMappingToUI[m_inputData->D_Type]);
    txtTankHeight->ChangeValue("");
    txtDesignPrdLvl->ChangeValue("");
    txtTestWaterLvl->ChangeValue("");
    txtNormalLiqdLvl->ChangeValue("");
    txtLiqdLvlSesDesign->ChangeValue("");
    txtSpecificGrvtyStrdPrd->ChangeValue("");
    txtSpecificGrvtyHydroTest->ChangeValue(wxString().FromDouble(m_inputData->Gw, FLOAT_VALUE_PRECISION));
    txtDesignTemp->ChangeValue("");
    txtMinDesignMetalTemp->ChangeValue(wxString().FromDouble(m_inputData->MDMT, FLOAT_VALUE_PRECISION));
    txtDesignInternalPressure->ChangeValue(wxString::Format("%.f",m_inputData->P,2));
    txtPressureCmbFact->ChangeValue(wxString().FromDouble(m_inputData->Fp, FLOAT_VALUE_PRECISION));
    cmbChoiceAddDesignLqdHead->SetSelection(m_inputData->Option_P);
    txtDesignExtPressure->ChangeValue(wxString().FromDouble(m_inputData->Pe, FLOAT_VALUE_PRECISION));
    txtExtPressureCmbFactor->ChangeValue(wxString().FromDouble(m_inputData->Fpe, FLOAT_VALUE_PRECISION));
    cmbChoiceAppendixShellDesign->SetSelection(shellAppendixNoMappingToUI[m_inputData->Shell_Appendx_No_user]);
    txtCourseWidthFirstShellBtm->ChangeValue(wxString().FromDouble(m_inputData->shell_detail_user[0][1], FLOAT_VALUE_PRECISION));
    txtCorrosionAllowanceFirstShllBtm->ChangeValue(wxString().FromDouble(m_inputData->shell_detail_user[0][2], FLOAT_VALUE_PRECISION));
    cmbChoiceMethodShellThickCalc->SetSelection(shellCalcMethodMappingToUI[m_inputData->Shell_Des_Method_No]);
    txtCorrosionAllowanceBtmPlate->ChangeValue("");
    cmbChoiceTypeFixedRoof->SetSelection(fixedRoofTypeMappingToUI[m_inputData->Roof_Type_No_user]);
    txtCorrosionAllowanceFixedRoof->ChangeValue("");
    txtWtSpiralStairway->ChangeValue(wxString().FromDouble(m_inputData->weight_stair_user, FLOAT_VALUE_PRECISION));
    txtIncWtShellNozzleOtherShellApptnces->ChangeValue(wxString().FromDouble(m_inputData->weight_adder_user, FLOAT_VALUE_PRECISION));
    cmbOptionStfr->SetSelection(m_inputData->option_Stfr);
    CmbRoundUpTo->SetSelection(m_inputData->RoundUP_to);

    if(m_inputData->JE_user<0.71)
        cmbJointEffcncyShellVertSeams->SetSelection(0);
    else if(m_inputData->JE_user<0.86)
        cmbJointEffcncyShellVertSeams->SetSelection(1);
    else
        cmbJointEffcncyShellVertSeams->SetSelection(2);

    if(!m_isNewData)
    {
        txtDiaTank->ChangeValue(wxString().FromDouble(m_inputData->D_User, FLOAT_VALUE_PRECISION));

        cmbChoiceDiaType->SetSelection(diameterMappingToUI[m_inputData->D_Type]);

        txtTankHeight->ChangeValue(wxString().FromDouble(m_inputData->H, FLOAT_VALUE_PRECISION));
        txtDesignPrdLvl->ChangeValue(wxString().FromDouble(m_inputData->H_td_user, FLOAT_VALUE_PRECISION));
        txtTestWaterLvl->ChangeValue(wxString().FromDouble(m_inputData->H_tt_user, FLOAT_VALUE_PRECISION));
        txtNormalLiqdLvl->ChangeValue(wxString().FromDouble(m_inputData->H_Norm_user, FLOAT_VALUE_PRECISION));
        txtLiqdLvlSesDesign->ChangeValue(wxString().FromDouble(m_inputData->H_Seis_user, FLOAT_VALUE_PRECISION));
        txtSpecificGrvtyStrdPrd->ChangeValue(wxString().FromDouble(m_inputData->G, FLOAT_VALUE_PRECISION));
        txtSpecificGrvtyHydroTest->ChangeValue(wxString().FromDouble(m_inputData->Gw, FLOAT_VALUE_PRECISION));
        txtDesignTemp->ChangeValue(wxString().FromDouble(m_inputData->T, FLOAT_VALUE_PRECISION));
        txtMinDesignMetalTemp->ChangeValue(wxString().FromDouble(m_inputData->MDMT, FLOAT_VALUE_PRECISION));
        txtPressureCmbFact->ChangeValue(wxString().FromDouble(m_inputData->Fp, FLOAT_VALUE_PRECISION));

        cmbChoiceAddDesignLqdHead->SetSelection(m_inputData->Option_P);

        txtDesignExtPressure->ChangeValue(wxString().FromDouble(m_inputData->Pe, FLOAT_VALUE_PRECISION));
        txtExtPressureCmbFactor->ChangeValue(wxString().FromDouble(m_inputData->Fpe, FLOAT_VALUE_PRECISION));

        cmbChoiceAppendixShellDesign->SetSelection(shellAppendixNoMappingToUI[m_inputData->Shell_Appendx_No_user]);

        txtCourseWidthFirstShellBtm->ChangeValue(wxString().FromDouble(m_inputData->shell_detail_user[0][1], FLOAT_VALUE_PRECISION));
        txtCorrosionAllowanceFirstShllBtm->ChangeValue(wxString().FromDouble(m_inputData->shell_detail_user[0][2], FLOAT_VALUE_PRECISION));

        cmbChoiceMethodShellThickCalc->SetSelection(shellCalcMethodMappingToUI[m_inputData->Shell_Des_Method_No]);

        txtCorrosionAllowanceBtmPlate->ChangeValue(wxString().FromDouble(m_inputData->CA_Bot, FLOAT_VALUE_PRECISION));

        cmbChoiceTypeFixedRoof->SetSelection(fixedRoofTypeMappingToUI[m_inputData->Roof_Type_No_user]);

        txtCorrosionAllowanceFixedRoof->ChangeValue(wxString().FromDouble(m_inputData->CA_Roof, FLOAT_VALUE_PRECISION));
        txtWtSpiralStairway->ChangeValue(wxString().FromDouble(m_inputData->weight_stair_user, FLOAT_VALUE_PRECISION));
        txtIncWtShellNozzleOtherShellApptnces->ChangeValue(wxString().FromDouble(m_inputData->weight_adder_user, FLOAT_VALUE_PRECISION));
    }
}

void InputScreensDlg::SetInitialControlStates()
{
    setInputScreen_1InitialControlStates();
    setWindDataInitialControlStates();
    setSeismicDataInitialControlStates();
    setShellDesignInitialControlStates();
    setPrimaryWindGirderDesignInitialControlStates();
    setRoofDataInitialControlStates();
    setRoofToShellInitialControlStates();
    setStiffenerElevationControlStates(true);
    setStiffenerSizeControlStates(true);
}

void InputScreensDlg::setInputScreen_1InitialControlStates()
{
    if(0.0 < m_inputData->P
       && m_inputData->P <= 1.0)
    {
        cmbChoiceAddDesignLqdHead->Enable();
    }
    else
    {
        cmbChoiceAddDesignLqdHead->Disable();
    }

    if(7 == m_inputData->Shell_Appendx_No_user)
    {
        cmbJointEffcncyShellVertSeams->Disable();
    }
    else
    {
        cmbJointEffcncyShellVertSeams->Enable();
    }

    //setting colours
    cmbChoiceDiaType->SetBackgroundColour(wxColour(100,255,200));
    txtTankHeight->SetBackgroundColour(wxColour(100,255,200));
}

void InputScreensDlg::OnbtnOkClick(wxCommandEvent& event)
{
    if(transferDataFromWindowData())// && validateEntries())
    {
        Close();
        this->SetReturnCode(wxID_OK);
    }
}

bool InputScreensDlg::validateEntries()
{
    bool validationSuccess = true;
    validationSuccess = validateInputScreen_1Entries();
    if(validationSuccess)
    {
        validationSuccess = validateWindDataEntries();
    }

    if(validationSuccess)
    {
        validationSuccess = validateSeismicDataEntries();
    }

    if(validationSuccess)
    {
        validationSuccess = validateRoofDataEntries();
    }
    if(validationSuccess)
    {
        validationSuccess = validateRoofToShellEntries();
    }

    return validationSuccess;
}

bool InputScreensDlg::validateInputScreen_1Entries()
{
    const double DOUBLE_ZERO = 0.0F;
    bool validationSuccess = true;

    if(m_inputData->D_User<=0 && txtDiaTank->GetValue().empty())
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_INPUT_SCREEN_1);
        wxMessageBox("Diameter of Tank (M) is mandatory", "InputScreen_1 Validation");
        validationSuccess = false;
        txtDiaTank->SetFocus();
    }
    else if(m_inputData->H<=0 && txtTankHeight->GetValue().empty())
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_INPUT_SCREEN_1);
        wxMessageBox("Height of Tank (M) is mandatory", "InputScreen_1 Validation");
        validationSuccess = false;
        txtTankHeight->SetFocus();
    }
    else if(m_inputData->G<=0 && txtSpecificGrvtyStrdPrd->GetValue().empty())
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_INPUT_SCREEN_1);
        wxMessageBox("Specific gravity of stored product is mandatory", "InputScreen_1 Validation");
        validationSuccess = false;
        txtSpecificGrvtyStrdPrd->SetFocus();
    }
    else if(m_inputData->T <=0 && txtDesignTemp->GetValue().empty())
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_INPUT_SCREEN_1);
        wxMessageBox("Design Temperature (Deg.C) is mandatory", "InputScreen_1 Validation");
        validationSuccess = false;
        txtDesignTemp->SetFocus();
    }
    else if(m_inputData->MDMT <=0 && txtMinDesignMetalTemp->GetValue().empty())
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_INPUT_SCREEN_1);
        wxMessageBox("Minimum design metal temperature (Deg.C) is mandatory", "InputScreen_1 Validation");
        validationSuccess = false;
        txtMinDesignMetalTemp->SetFocus();
    }
    // else if(m_inputData->P <=0 && txtDesignInternalPressure->GetValue().empty())
    // {
    //     changeActiveNotebookPage(ItemUIUtils::NB_PAGE_INPUT_SCREEN_1);
    //     wxMessageBox("Design internal pressure (kPa) is mandatory", "InputScreen_1 Validation");
    //     validationSuccess = false;
    //     txtDesignInternalPressure->SetFocus();
    // }
    else if(cmbChoiceAppendixShellDesign->GetSelection()<0)
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_INPUT_SCREEN_1);
        wxMessageBox("Applicable Appendix for shell design is mandatory", "InputScreen_1 Validation");
        validationSuccess = false;
        cmbChoiceAppendixShellDesign->SetFocus();
    }
    else if(cmbChoiceMethodShellThickCalc->GetSelection()<0)
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_INPUT_SCREEN_1);
        wxMessageBox("Method for Shell Thickness Calculation is mandatory", "InputScreen_1 Validation");
        validationSuccess = false;
        cmbChoiceMethodShellThickCalc->SetFocus();
    }
    else if(cmbChoiceTypeFixedRoof->GetSelection()<0)
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_INPUT_SCREEN_1);
        wxMessageBox("Type of Fixed Roof is mandatory", "InputScreen_1 Validation");
        validationSuccess = false;
        cmbChoiceTypeFixedRoof->SetFocus();
    }

    return validationSuccess;
}

bool InputScreensDlg::transferDataFromWindowData()
{
    bool transferSuccess = false;

    if(transferInputScreen_1WindowData()
       && transferWindDataWindowData()
       && transferSeismicDataWindowData()
       && transferRoofDataWindowData()
       && transferRoofToShellWindowData())
    {
        transferSuccess = true;
    }
    cout<<transferInputScreen_1WindowData()<<" "<<transferWindDataWindowData()<<" "<<transferSeismicDataWindowData()<<" "<<
    transferRoofDataWindowData()<<" "<<transferRoofToShellWindowData()<<endl;
    return transferSuccess;

}

bool InputScreensDlg::transferInputScreen_1WindowData()
{
    bool transferSuccess = false;
    if(txtDiaTank->GetValidator()->TransferFromWindow()
       && txtTankHeight->GetValidator()->TransferFromWindow()
       && txtDesignPrdLvl->GetValidator()->TransferFromWindow()
       && txtTestWaterLvl->GetValidator()->TransferFromWindow()
       && txtNormalLiqdLvl->GetValidator()->TransferFromWindow()
       && txtLiqdLvlSesDesign->GetValidator()->TransferFromWindow()
       && txtSpecificGrvtyStrdPrd->GetValidator()->TransferFromWindow()
       && txtSpecificGrvtyHydroTest->GetValidator()->TransferFromWindow()
       && txtDesignTemp->GetValidator()->TransferFromWindow()
       && txtMinDesignMetalTemp->GetValidator()->TransferFromWindow()
       && txtDesignInternalPressure->GetValidator()->TransferFromWindow()
       && txtPressureCmbFact->GetValidator()->TransferFromWindow()
       && txtDesignExtPressure->GetValidator()->TransferFromWindow()
       && txtExtPressureCmbFactor->GetValidator()->TransferFromWindow()
       && txtCourseWidthFirstShellBtm->GetValidator()->TransferFromWindow()
       && txtCorrosionAllowanceFirstShllBtm->GetValidator()->TransferFromWindow()
       && txtCorrosionAllowanceBtmPlate->GetValidator()->TransferFromWindow()
       && txtCorrosionAllowanceFixedRoof->GetValidator()->TransferFromWindow()
       && txtWtSpiralStairway->GetValidator()->TransferFromWindow()
       && txtIncWtShellNozzleOtherShellApptnces->GetValidator()->TransferFromWindow()
       )
    {
        transferSuccess = true;
    }
    cout<<"input transfer "<<transferSuccess<<endl;
    return transferSuccess;
}

void InputScreensDlg::OncmbChoiceDiaTypeSelect(wxCommandEvent& event)
{
    m_inputData->D_Type = diameterMappingFromUI[cmbChoiceDiaType->GetSelection()];
}

void InputScreensDlg::OncmbChoiceAddDesignLqdHeadSelect(wxCommandEvent& event)
{
    m_inputData->Option_P = cmbChoiceAddDesignLqdHead->GetSelection();
}

void InputScreensDlg::OncmbChoiceAppendixShellDesignSelect(wxCommandEvent& event)
{
    m_inputData->Shell_Appendx_No_user = shellAppendixNoMappingFromUI[cmbChoiceAppendixShellDesign->GetSelection()];
    if(m_inputData->Shell_Appendx_No_user==7)
    {
        cmbJointEffcncyShellVertSeams->Disable();
    }
    else
    {
        cmbJointEffcncyShellVertSeams->Enable();
    }

    if(m_inputData->Shell_Appendx_No_user<3)
    {
    	cmbChoiceMethodShellThickCalc->SetSelection(0);
    	inputScreen1Calculations();
    }

	if (m_inputData->Shell_Appendx_No_user == 7||(m_inputData->Shell_Appendx_No_user == 3 && m_inputData->D_User > 60.0))
	{
        m_inputData->JE_user = 1.0;
        cmbJointEffcncyShellVertSeams->SetSelection(2);
    }

    if(m_inputData->Shell_Appendx_No_user!=1 && m_inputData->Shell_Appendx_No_user!=2)
    {
        m_inputData->JE_user = 1.0;
        cmbJointEffcncyShellVertSeams->SetSelection(2);
    }

	m_inputData->Spacing_Min = 0.160;
    if(m_inputData->Shell_Appendx_No_user==4)
    {
        cmbChoiceMethodShellThickCalc->SetSelection(0);
        m_inputData->Shell_Des_Method_No=1;
    }

}

double round_up(double x, int n)

{
	x = (ceil(x * pow(10, n)) / pow(10, n));
	return x;
}

void InputScreensDlg::inputScreen1Calculations()
{
			int RoundUP_to = 0;
			if (m_inputData->D_Type == 1)
				m_inputData->D = m_inputData->D_User;
			else
				m_inputData->D = m_inputData->D_User + 0.013;
			if (m_inputData->G < m_inputData->Gw)
				m_inputData->Gd = m_inputData->Gw;
			else
				m_inputData->Gd = m_inputData->G;

			double temp1 = (4.9 * m_inputData->D * ((m_inputData->H_td_user + ((m_inputData->P*m_inputData->Option_P) / (9.8*m_inputData->Gd))) - 0.3) * m_inputData->Gd / (0.85 * 145)) + m_inputData->shell_detail_user[0][2];
			double temp2 = (4.9 * m_inputData->D * ((m_inputData->H_td_user + ((m_inputData->P*m_inputData->Option_P) / (9.8*m_inputData->Gd))) - 0.3) * m_inputData->Gd / (m_inputData->JE_user * 145)) + m_inputData->shell_detail_user[0][2];
			//cout<<temp1<<"----"<<temp2<<endl;
			temp1 = round_up(temp1, RoundUP_to);
			temp2 = round_up(temp2, RoundUP_to);

			if (temp1 > 13.0)
			{

				m_inputData->Shell_Appendx_No = 7;
				m_inputData->JE = 1.0;

			}
			else
				if (temp2 > 13.0)
					m_inputData->JE = 0.85;

}

void InputScreensDlg::OncmbChoiceMethodShellThickCalcSelect(wxCommandEvent& event)
{
    m_inputData->Shell_Des_Method_No = shellCalcMethodMappingFromUI[cmbChoiceMethodShellThickCalc->GetSelection()];
    if(m_inputData->Shell_Appendx_No_user<=4)
    	cmbChoiceMethodShellThickCalc->SetSelection(0);
    else  if(m_inputData->D_User>61)
    {
    	cmbChoiceMethodShellThickCalc->SetSelection(1);
    }
}

void InputScreensDlg::OncmbChoiceTypeFixedRoofSelect(wxCommandEvent& event)
{
    m_inputData->Roof_Type_No_user = fixedRoofTypeMappingFromUI[cmbChoiceTypeFixedRoof->GetSelection()];
    m_inputData->Roof_Type_No = m_inputData->Roof_Type_No_user;
    if(m_inputData->Roof_Type_No>=7)
    {
        pnlMainPrimaryWindGirder->Enable();
    }
    else
    {
        pnlMainPrimaryWindGirder->Disable();
    }
    setRoofDataInitialControlValues();
    setRoofDataInitialControlStates();
}

void InputScreensDlg::OntxtDiaTankKillFocus(wxFocusEvent& event)
{
    double dia = 0.0F;
    txtDiaTank->GetValue().ToDouble(&dia);
    m_inputData->D_User= dia;
    if(dia>61)
    {
    	cmbChoiceMethodShellThickCalc->SetSelection(1);
    }

    event.Skip();

}

void InputScreensDlg::OntxtTankHeightKillFocus(wxFocusEvent& event)
{
    double tankHeight = 0.0F;
    txtTankHeight->GetValue().ToDouble(&tankHeight);
    if(tankHeight==0)
    {
    	tankHeight=22;
    	txtTankHeight->SetValue(wxString::Format("%.3f",tankHeight));
    }

    if(m_inputData->H != tankHeight)
    {
        m_inputData->H = tankHeight;
        txtDesignPrdLvl->SetValue(wxString::Format("%.3f",tankHeight));
        txtTestWaterLvl->SetValue(wxString::Format("%.3f",tankHeight));
        txtNormalLiqdLvl->ChangeValue(wxString::Format("%.3f",tankHeight-0.5));
        m_inputData->No_of_ShellCourses = 1;
    }

    event.Skip();
}


void InputScreensDlg::OntxtDesignPrdLvlKillFocus(wxFocusEvent& event)
{
    double designPrdLvl = 0.0F;
    txtDesignPrdLvl->GetValue().ToDouble(&designPrdLvl);
    if(designPrdLvl==0)
    {
    	txtTankHeight->GetValue().ToDouble(&designPrdLvl);
    	txtDesignPrdLvl->SetValue(wxString::Format("%.3f",designPrdLvl));
    }
    if(m_inputData->H_td_user != designPrdLvl)
    {
        m_inputData->H_td_user = designPrdLvl;
        txtTestWaterLvl->SetValue(txtDesignPrdLvl->GetValue());
        txtNormalLiqdLvl->ChangeValue(wxString::Format("%.3f",designPrdLvl-0.5));
    }

    event.Skip();
}

void InputScreensDlg::OntxtTestWaterLvlKillFocus(wxFocusEvent& event)
{
    double testWaterLvl = 0.0F;
    txtTestWaterLvl->GetValue().ToDouble(&testWaterLvl);
    if(testWaterLvl==0)
    {
    	txtDesignPrdLvl->GetValue().ToDouble(&testWaterLvl);
    	txtTestWaterLvl->SetValue(wxString::Format("%.3f",testWaterLvl));
    }

    event.Skip();
}


void InputScreensDlg::OntxtNormalLiqdLvlKillFocus(wxFocusEvent& event)
{
    double normalLiqdLvl = 0.0F;
    txtNormalLiqdLvl->GetValue().ToDouble(&normalLiqdLvl);
    if(normalLiqdLvl==0)
    {
    	txtDesignPrdLvl->GetValue().ToDouble(&normalLiqdLvl);
    	normalLiqdLvl-=0.5;
    	txtNormalLiqdLvl->SetValue(wxString::Format("%.3f",normalLiqdLvl));
    }
    if(m_inputData->H_Norm_user != normalLiqdLvl)
    {
        m_inputData->H_Norm_user = normalLiqdLvl;
        txtLiqdLvlSesDesign->SetValue(txtNormalLiqdLvl->GetValue());
    }

    event.Skip();
}


void InputScreensDlg::OntxtLiqdLvlSesDesignKillFocus(wxFocusEvent& event)
{
    double hSeismic = 0.0F;
    txtLiqdLvlSesDesign->GetValue().ToDouble(&hSeismic);
    if(hSeismic==0)
    {
    	txtNormalLiqdLvl->GetValue().ToDouble(&hSeismic);
    	txtLiqdLvlSesDesign->SetValue(wxString::Format("%.3f",hSeismic));
    }

    event.Skip();
}


void InputScreensDlg::OntxtSpecificGrvtyStrdPrdKillFocus(wxFocusEvent& event)
{
    double temp = 0.0F;
    txtSpecificGrvtyStrdPrd->GetValue().ToDouble(&temp);
    if(temp==0)
    {
    	txtSpecificGrvtyStrdPrd->SetValue(wxString::Format("%.3f",0.85));
    	m_inputData->G=0.85;
    }
    else
    	m_inputData->G = temp;

    event.Skip();
}

void InputScreensDlg::OntxtSpecificGrvtyHydroTestKillFocus(wxFocusEvent& event)
{
    double temp = 0.0F;
    txtSpecificGrvtyHydroTest->GetValue().ToDouble(&temp);
    if(temp<1.0)
    {
    	txtSpecificGrvtyHydroTest->SetValue(wxString::Format("%.2f",1.0));
    	m_inputData->Gw=1.0;
    }
    else
    	m_inputData->Gw = temp;

    event.Skip();
}

void InputScreensDlg::OntxtDesignTempKillFocus(wxFocusEvent& event)
{
    double temp = 0.0F;
    txtDesignTemp->GetValue().ToDouble(&temp);

    if(temp<0.05)
    {
    	txtDesignTemp->SetValue(wxString::Format("%.2f",85.0));
    	m_inputData->T=85.0;
    }

    else if(temp>260.0)
    {
    	txtDesignTemp->SetValue(wxString::Format("%.2f",260.0));
    	m_inputData->T=260.0;
    }
    else
    	m_inputData->T=temp;
    event.Skip();
}

void InputScreensDlg::OntxtDesignInternalPressureKillFocus(wxFocusEvent& event)
{
    double internalPressure = 0.0F;
    txtDesignInternalPressure->GetValue().ToDouble(&internalPressure);

    if(internalPressure<0.05)
    {
    	txtDesignInternalPressure->SetValue(wxString::Format("%.2f",0.0));
    	m_inputData->P=0.0;
    	internalPressure=0.0;
    }

	else if(internalPressure>18.0)
    {
    	txtDesignInternalPressure->SetValue(wxString::Format("%.2f",18.0));
    	m_inputData->P=18.0;
    	internalPressure=18.0;

    }



    if(0.0 < internalPressure
       && 1.0 >= internalPressure)
    {
        cmbChoiceAddDesignLqdHead->Enable();
        cmbChoiceAddDesignLqdHead->SetSelection(0); //NO
        m_inputData->Option_P = cmbChoiceAddDesignLqdHead->GetSelection();
    }
    else
    {
        cmbChoiceAddDesignLqdHead->Disable();
        if(0.0 == internalPressure)
        {
            cmbChoiceAddDesignLqdHead->SetSelection(0); //NO
        }
        else
        {
            cmbChoiceAddDesignLqdHead->SetSelection(1); //YES
        }


    }

    event.Skip();
}

void InputScreensDlg::OntxtPressureCmbFactKillFocus(wxFocusEvent& event)
{
    double pressureCmbFact = 0.0F;
    txtPressureCmbFact->GetValue().ToDouble(&pressureCmbFact);
    if(pressureCmbFact<0.4)
    {
    	m_inputData->Fp = 0.4;
        txtPressureCmbFact->ChangeValue(wxString().FromDouble(0.40F));
    }
    else
    	m_inputData->Fp = pressureCmbFact;

    m_inputData->Po_user = m_inputData->P*m_inputData->Fp;

    event.Skip();
}

void InputScreensDlg::OntxtDesignExtPressureKillFocus(wxFocusEvent& event)
{
    double extPressure = 0.0F;
    txtDesignExtPressure->GetValue().ToDouble(&extPressure);
    if(extPressure<0.05)
    {
        txtDesignExtPressure->ChangeValue(wxString().FromDouble(0.25));
        m_inputData->Pe = 0.25;
    }

    else if(extPressure>6.9)
    {
        txtDesignExtPressure->ChangeValue(wxString().FromDouble(6.9));
        m_inputData->Pe = 6.9;
    }
    else
    	m_inputData->Pe = extPressure;


    event.Skip();
}

void InputScreensDlg::OntxtExtPressureCmbFactorKillFocus(wxFocusEvent& event)
{
    double extPressureCmbFactor = 0.0F;
    txtExtPressureCmbFactor->GetValue().ToDouble(&extPressureCmbFactor);
    if(extPressureCmbFactor<0.4)
    {
        txtExtPressureCmbFactor->ChangeValue(wxString().FromDouble(0.40F));
        extPressureCmbFactor = 0.4;

    }
    m_inputData->Fpe = extPressureCmbFactor;
    event.Skip();
}

void InputScreensDlg::OntxtCourseWidthFirstShellBtmKillFocus(wxFocusEvent& event)
{
    double temp = 0.0F;
    txtCourseWidthFirstShellBtm->GetValue().ToDouble(&temp);
    if(temp==0.0)
    {
        txtCourseWidthFirstShellBtm->ChangeValue(wxString().FromDouble(2.5));
        temp = 2.5;

    }
    if(m_inputData->shell_detail_user[0][1]!=temp)
    {
    	m_inputData->No_of_ShellCourses = 1;
    }
    m_inputData->shell_detail_user[0][1]=temp;
    m_inputData->shell_detail[0][0]=temp;

    event.Skip();
}

void InputScreensDlg::OntxtCorrosionAllowanceFirstShllBtmKillFocus(wxFocusEvent& event)
{
    double temp = 0.0F;
    txtCorrosionAllowanceFirstShllBtm->GetValue().ToDouble(&temp);
    if(temp==0.0)
    {
        txtCorrosionAllowanceFirstShllBtm->ChangeValue(wxString().FromDouble(3.0));
        temp = 3.0;

    }
    m_inputData->shell_detail_user[0][2]=temp;
    event.Skip();
}


void InputScreensDlg::OntxtCorrosionAllowanceBtmPlateKillFocus(wxFocusEvent& event)
{
    double temp = 0.0F;
    txtCorrosionAllowanceBtmPlate->GetValue().ToDouble(&temp);
    if(temp < 0.1)
    {
        txtCorrosionAllowanceBtmPlate->SetValue(wxString::Format("%.2f",2.0));
        temp = 2.0;

    }
    m_inputData->CA_Bot=temp;
    event.Skip();
}

void InputScreensDlg::OntxtCorrosionAllowanceFixedRoofKillFocus(wxFocusEvent& event)
{
    double temp = 0.0F;
    txtCorrosionAllowanceFixedRoof->GetValue().ToDouble(&temp);
    if(temp == 0)
    {
        txtCorrosionAllowanceFixedRoof->SetValue(wxString::Format("%.2f",1.0));
        temp = 1.0;

    }
    m_inputData->CA_Roof=temp;
    event.Skip();
}
//WIND DATA WINDOW
void InputScreensDlg::setupWindDataValidators()
{
    wxFloatingPointValidator<double> validatorDoubleGustDesignWindSpeed(3, &(m_inputData->basic_v_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtGustDesignWindSpeed->SetValidator(validatorDoubleGustDesignWindSpeed);

    wxFloatingPointValidator<double> validatorDoubleVelPressureExpCoeff(2, &(m_inputData->kz_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtVelPressureExpCoeff->SetValidator(validatorDoubleVelPressureExpCoeff);

    wxFloatingPointValidator<double> validatorDoubleTopographicFactor(2, &(m_inputData->kzt_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtTopographicFactor->SetValidator(validatorDoubleTopographicFactor);

    wxFloatingPointValidator<double> validatorDoubleDirectionFactor(2, &(m_inputData->kd_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtDirectionFactor->SetValidator(validatorDoubleDirectionFactor);

    wxFloatingPointValidator<double> validatorDoubleGustFactor(2, &(m_inputData->gust_factor_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtGustFactor->SetValidator(validatorDoubleGustFactor);

    wxFloatingPointValidator<double> validatorDoubleDesignWindVel(2, &(m_inputData->V_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtDesignWindVel->SetValidator(validatorDoubleDesignWindVel);

}

void InputScreensDlg::setWindDataInitialControlValues()
{
    const int FLOAT_VALUE_PRECISION = 2;
    cmbChoiceCodeWindLoad->SetSelection(m_inputData->wind_design_code - 1);

    txtGustDesignWindSpeed->ChangeValue(wxString().FromDouble(m_inputData->basic_v_user, FLOAT_VALUE_PRECISION));

    cmbChoiceExposureCatgory->SetSelection(m_inputData->wind_exp_cat - 1);

    txtVelPressureExpCoeff->ChangeValue(wxString().FromDouble(m_inputData->kz_user, FLOAT_VALUE_PRECISION));

    txtTopographicFactor->ChangeValue(wxString().FromDouble(m_inputData->kzt_user, FLOAT_VALUE_PRECISION));

    txtDirectionFactor->ChangeValue(wxString().FromDouble(m_inputData->kd_user, FLOAT_VALUE_PRECISION));

    cmbChoiceImportanceFactor->SetSelection( (m_inputData->imp_factorW_user == 1.00 ? 0 : 1) );

    txtGustFactor->ChangeValue(wxString().FromDouble(m_inputData->gust_factor_user, FLOAT_VALUE_PRECISION));

    // txtDesignWindVel->ChangeValue("");

    if(!m_isNewData)
    {
        cmbChoiceCodeWindLoad->SetSelection(m_inputData->wind_design_code - 1);
        updateCodeWindowLoadSelectionChange();
        updateDesignWindVel();

        if(m_inputData->V_user>0)
            txtDesignWindVel->ChangeValue(wxString().FromDouble(m_inputData->V_user, FLOAT_VALUE_PRECISION));
    }
    else
    {
        //This is done to update v_default when we have a default value for wind load code
        //TODO: Consider the actual case when default value is not set and the data is obviously new
        int code = m_inputData->wind_design_code;
        if(code>=1&&code<=3)
        {
            updateCodeWindowLoadSelectionChange();
            updateDesignWindVel();
            m_inputData->V_user = m_inputData->V_default;
        }
    }
}

void InputScreensDlg::setWindDataInitialControlStates()
{
    updateCodeWindowLoadSelectionChange();
}

bool InputScreensDlg::validateWindDataEntries()
{
    const double DOUBLE_ZERO = 0.0F;
    bool validationSuccess = true;

    if(DOUBLE_ZERO >= m_inputData->V_user
            && txtDesignWindVel->GetValue().empty()
            && cmbChoiceCodeWindLoad->GetSelection()==2)
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_WIND_DATA);
        wxMessageBox("Design Wind Velocity (km / h) is mandatory", "Wind Data Validation");
        validationSuccess = false;
        txtDesignWindVel->SetFocus();
    }
    return validationSuccess;
    //only checking till ^here right now
    if(cmbChoiceCodeWindLoad->GetSelection()<0)
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_WIND_DATA);
        wxMessageBox("Code for Wind Load is mandatory", "Wind Data Validation");
        validationSuccess = false;
        cmbChoiceCodeWindLoad->SetFocus();
    }
    else if(DOUBLE_ZERO >= m_inputData->basic_v_user
            && txtGustDesignWindSpeed->GetValue().empty()
            && WND_DATA_DESIGN_CODE_USER_DEF != cmbChoiceCodeWindLoad->GetSelection())
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_WIND_DATA);
        wxMessageBox("3 Second Gust Design Wind Speed  (m / sec) is mandatory", "Wind Data Validation");
        validationSuccess = false;
        txtGustDesignWindSpeed->SetFocus();
    }
    else if(DOUBLE_ZERO >= m_inputData->V_user
            && txtDesignWindVel->GetValue().empty()
            && cmbChoiceCodeWindLoad->GetSelection()==2)
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_WIND_DATA);
        wxMessageBox("Design Wind Velocity (km / h) is mandatory", "Wind Data Validation");
        validationSuccess = false;
        txtDesignWindVel->SetFocus();
    }

    return validationSuccess;

}

bool InputScreensDlg::transferWindDataWindowData()
{
    bool transferSuccess = false;
    if(txtGustDesignWindSpeed->GetValidator()->TransferFromWindow()
       && txtVelPressureExpCoeff->GetValidator()->TransferFromWindow()
       && txtTopographicFactor->GetValidator()->TransferFromWindow()
       && txtDirectionFactor->GetValidator()->TransferFromWindow()
       && txtGustFactor->GetValidator()->TransferFromWindow()
       && txtDesignWindVel->GetValidator()->TransferFromWindow())
    {
        transferSuccess = true;
    }

    return transferSuccess;
}

void InputScreensDlg::updateCodeWindowLoadSelectionChange()
{
    int currentSelection = cmbChoiceCodeWindLoad->GetSelection();
    if(WND_DATA_DESIGN_CODE_ASCE_7_10 == currentSelection )
    {
        cmbChoiceImportanceFactor->SetSelection(0);
        cmbChoiceImportanceFactor->Disable();
    }
    else
    {
        cmbChoiceImportanceFactor->Enable();
    }
    //If option 3 - User defined wind velocity is selected hide relevant fields
    if(WND_DATA_DESIGN_CODE_USER_DEF == cmbChoiceCodeWindLoad->GetSelection())
    {
        changeVisibleWindDataFields();
    }
    else
    {
        changeVisibleWindDataFields(true);
    }
}

void InputScreensDlg::OnwindDataRunButtonClick(wxCommandEvent& event)
{
    double val1 = ((0.613 * m_inputData->kz_user * m_inputData->kzt_user * m_inputData->kd_user * m_inputData->gust_factor_user * m_inputData->imp_factorW_user * (pow(m_inputData->basic_v_user,2)))/1000) + 0.24;
    double val2 = 190 * pow((val1/1.72),0.5);
    m_inputData->V_default = val2;
    m_inputData->V_user = val2;
    txtDesignWindVel->ChangeValue(wxString().FromDouble(val2,2));
}

void InputScreensDlg::OncmbChoiceCodeWindLoadSelect(wxCommandEvent& event)
{
    m_inputData->wind_design_code = cmbChoiceCodeWindLoad->GetSelection() + 1;
    updateCodeWindowLoadSelectionChange();
    updateDesignWindVel();
}

void InputScreensDlg::updateDesignWindVel()
{
    if(m_inputData->wind_design_code==3)
        m_inputData->V_default=190;
    else
    {
        double val1 = ((0.613 * m_inputData->kz_user * m_inputData->kzt_user * m_inputData->kd_user * m_inputData->gust_factor_user * m_inputData->imp_factorW_user * (pow(m_inputData->basic_v_user,2)))/1000)+0.24;
        double val2 = 190 * pow((val1/1.72),0.5);
        m_inputData->V_default = val2;
    }

    txtDesignWindVel->ChangeValue(wxString().FromDouble(m_inputData->V_default,2));

}

void InputScreensDlg::changeVisibleWindDataFields(bool bShow)
{
    if(bShow)
    {
        pnlGustDesignWindSpeed->Show();
        pnlExposureCatgory->Show();
        pnlVelPressureExpCoeff->Show();
        pnlTopographicFactor->Show();
        pnlDirectionFactor->Show();
        pnlImportanceFactor->Show();
        pnlGustFactor->Show();
        windDataRunButton->Show();
    }
    else
    {
        pnlGustDesignWindSpeed->Hide();
        pnlExposureCatgory->Hide();
        pnlVelPressureExpCoeff->Hide();
        pnlTopographicFactor->Hide();
        pnlDirectionFactor->Hide();
        pnlImportanceFactor->Hide();
        pnlGustFactor->Hide();
        windDataRunButton->Hide();

    }

    BoxSizerWindDataMain->Layout();
}


void InputScreensDlg::OntxtDesignWindVelKillFocus(wxFocusEvent& event)
{
	double windVel = 0.0F;
    txtDesignWindVel->GetValue().ToDouble(&windVel);
	m_inputData->V_user=windVel;

	if(m_inputData->V_user<=0.01)
	{
		txtDesignWindVel->ChangeValue(wxString().FromDouble(m_inputData->V_default, 2));
		m_inputData->V_user=m_inputData->V_default;

	}
	event.Skip();
}


void InputScreensDlg::OntxtGustDesignWindSpeedKillFocus(wxFocusEvent& event)
{
    double basicV = 0.0F;
    txtGustDesignWindSpeed->GetValue().ToDouble(&basicV);
	m_inputData->basic_v_user=basicV;

	if(m_inputData->basic_v_user<=0.01)
	{
		txtGustDesignWindSpeed->ChangeValue(wxString().FromDouble(51.610, 3));
		m_inputData->basic_v_user=51.610;

	}
	event.Skip();

}

void InputScreensDlg::OntxtVelPressureExpCoeffKillFocus(wxFocusEvent& event)
{
    double velPressure = 0.0F;
    txtVelPressureExpCoeff->GetValue().ToDouble(&velPressure);
	m_inputData->kz_user=velPressure;

	if(m_inputData->kz_user<=0.01)
	{
		m_inputData->kz_user=m_inputData->kz_default;
		txtVelPressureExpCoeff->ChangeValue(wxString().FromDouble(m_inputData->kz_user, 2));

	}
	event.Skip();

}

void InputScreensDlg::OntxtTopographicFactorKillFocus(wxFocusEvent& event)
{
    double velPressure = 0.0F;
    txtTopographicFactor->GetValue().ToDouble(&velPressure);
	m_inputData->kzt_user=velPressure;

	if(m_inputData->kzt_user<=0.01)
	{
		m_inputData->kzt_user=1;
		txtTopographicFactor->ChangeValue(wxString().FromDouble(1, 2));

	}
	event.Skip();
}

void InputScreensDlg::OntxtDirectionFactorKillFocus(wxFocusEvent& event)
{
    double velPressure = 0.0F;
    txtDirectionFactor->GetValue().ToDouble(&velPressure);
	m_inputData->kd_user=velPressure;

	if(m_inputData->kd_user<=0.01)
	{
		m_inputData->kd_user=0.95;
		txtDirectionFactor->ChangeValue(wxString().FromDouble(0.95, 2));

	}
	event.Skip();
}

void InputScreensDlg::OntxtGustFactorKillFocus(wxFocusEvent& event)
{
    double velPressure = 0.0F;
    txtGustFactor->GetValue().ToDouble(&velPressure);
	m_inputData->gust_factor_user=velPressure;

	if(m_inputData->gust_factor_user<=0.01)
	{
		m_inputData->gust_factor_user=0.85;
		txtGustFactor->ChangeValue(wxString().FromDouble(0.85, 2));

	}
	event.Skip();
}


void InputScreensDlg::OncmbChoiceImportanceFactorSelect(wxCommandEvent& event)
{
    m_inputData->imp_factorW_user = windDataImpFactorMappingFromUI[cmbChoiceImportanceFactor->GetSelection()];
}

void InputScreensDlg::OncmbChoiceExposureCatgorySelect(wxCommandEvent& event)
{
	double kz_default;
    m_inputData->wind_exp_cat = cmbChoiceExposureCatgory->GetSelection() + 1;
    if(m_inputData->wind_exp_cat==1)
    {
    	kz_default=0.76;
    }
    else if(m_inputData->wind_exp_cat==2)
    {
    	kz_default=1.04;
    }
    else
    {
    	kz_default=1.22;
    }

    m_inputData->kz_user=kz_default;
    m_inputData->kz_default=kz_default;
    txtVelPressureExpCoeff->ChangeValue(wxString().FromDouble(kz_default, 2));

}


void InputScreensDlg::changeActiveNotebookPage(size_t pageID)
{
    if(static_cast<size_t>(NotebookInputScreen_1->GetSelection()) != pageID)
    {
        NotebookInputScreen_1->ChangeSelection(pageID);
    }

}

void InputScreensDlg::setupSeismicDataValidators()
{
    wxFloatingPointValidator<double> validatorDoublePeakGrndAccel(4, &(m_inputData->S0_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtPeakGroundAccel->SetValidator(validatorDoublePeakGrndAccel);
    txtUBCPeakGrndAccel->SetValidator(validatorDoublePeakGrndAccel);

    wxFloatingPointValidator<double> validatorDoubleSpectralAccelShort(4, &(m_inputData->Ss_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtPGASpectralAccelShort->SetValidator(validatorDoubleSpectralAccelShort);
    txtUBCSpectralAccelShort->SetValidator(validatorDoubleSpectralAccelShort);
    txtASCESpectralAccelShort->SetValidator(validatorDoubleSpectralAccelShort);

    wxFloatingPointValidator<double> validatorDoubleSpectralAccelOneSec(4, &(m_inputData->S1_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtPGASpectralAccelOneSec->SetValidator(validatorDoubleSpectralAccelOneSec);
    txtUBCSpectralAccelOneSec->SetValidator(validatorDoubleSpectralAccelOneSec);
    txtASCESpectralAccelOneSec->SetValidator(validatorDoubleSpectralAccelOneSec);

    //Fixed controls
    wxFloatingPointValidator<double> validatorDoubleSeismicScaleFactor(2, &(m_inputData->Factor_Q), wxNUM_VAL_ZERO_AS_BLANK);
    txtSeismicScaleFactor->SetValidator(validatorDoubleSeismicScaleFactor);

    wxFloatingPointValidator<double> validatorDoubleSeismicImportanceFactor(2, &(m_inputData->imp_factorS), wxNUM_VAL_ZERO_AS_BLANK);
    txtSeismicImportanceFactor->SetValidator(validatorDoubleSeismicImportanceFactor);

    wxFloatingPointValidator<double> validatorDoubleTopographicFactor(2, &(m_inputData->kzt_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtTopographicFactor->SetValidator(validatorDoubleTopographicFactor);

    wxFloatingPointValidator<double> validatorDoubletxtAccelBaseSiteCoeff(2, &(m_inputData->Fa_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtAccelBaseSiteCoeff->SetValidator(validatorDoubletxtAccelBaseSiteCoeff);

    wxFloatingPointValidator<double> validatorDoubleVelBasedSiteCoeff(2, &(m_inputData->Fv_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtVelBasedSiteCoeff->SetValidator(validatorDoubleVelBasedSiteCoeff);

    wxFloatingPointValidator<double> validatorDoubleTransitionLongGrnd(2, &(m_inputData->TL_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtTransitionLongGrnd->SetValidator(validatorDoubleTransitionLongGrnd);

    wxFloatingPointValidator<double> validatorDoubleCoeffAdjust(2, &(m_inputData->K_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtCoeffAdjust->SetValidator(validatorDoubleCoeffAdjust);

    wxFloatingPointValidator<double> validatorDoubleSDSQFaSs(4, &(m_inputData->Sds), wxNUM_VAL_ZERO_AS_BLANK);
    txtSDSQFaSs->SetValidator(validatorDoubleSDSQFaSs);

    wxFloatingPointValidator<double> validatorDoubleSD1QFvS1(4, &(m_inputData->Sd1), wxNUM_VAL_ZERO_AS_BLANK);
    txtSD1QFvS1->SetValidator(validatorDoubleSD1QFvS1);

}
void InputScreensDlg::setSeismicDataInitialControlValues()
{
    const int FLOAT_VALUE_PRECISION_TWO = 2;

    cmbChoiceSeismicDesignChoice->SetSelection(m_inputData->Seismic_design_code - 1);
    txtPGASpectralAccelShort->ChangeValue(wxString().FromDouble(m_inputData->Ss_user, 4));
    txtPGASpectralAccelOneSec->ChangeValue(wxString().FromDouble(m_inputData->S1_user, 4));

    txtSeismicScaleFactor->ChangeValue(wxString().FromDouble(m_inputData->Factor_Q, FLOAT_VALUE_PRECISION_TWO));

    cmbChoiceGovByASCERules->SetSelection(m_inputData->ASCE_rule);

    cmbChoiceSeismicUserGrp->SetSelection(m_inputData->SUG - 1);

    txtSeismicImportanceFactor->ChangeValue(wxString().FromDouble(m_inputData->imp_factorS, FLOAT_VALUE_PRECISION_TWO));

    cmbChoiceSeismicSiteClass->SetSelection(m_inputData->site_class - 1);


    txtAccelBaseSiteCoeff->ChangeValue(wxString().FromDouble(m_inputData->Fa_user, FLOAT_VALUE_PRECISION_TWO));
    txtVelBasedSiteCoeff->ChangeValue(wxString().FromDouble(m_inputData->Fv_user, FLOAT_VALUE_PRECISION_TWO));

    txtTransitionLongGrnd->ChangeValue(wxString().FromDouble(m_inputData->TL_user, FLOAT_VALUE_PRECISION_TWO));
    txtCoeffAdjust->ChangeValue(wxString().FromDouble(m_inputData->K_user, FLOAT_VALUE_PRECISION_TWO));
    txtSDSQFaSs->ChangeValue(wxString().FromDouble(m_inputData->Sds, 4));
    txtSD1QFvS1->ChangeValue(wxString().FromDouble(m_inputData->Sd1, 4));
    cout<<"look at Sd1 "<<m_inputData->Sd1<<endl;
    cmbChoiceVertSeismicEffect->SetSelection(m_inputData->option_Av);

    if(!m_isNewData)
    {
        cmbChoiceSeismicDesignChoice->SetSelection(m_inputData->Seismic_design_code - 1);
        updateSeismicDesignDataAndControls(m_inputData->Seismic_design_code - 1, false);
    }
    updateSeismicDesignDataAndControls(m_inputData->Seismic_design_code - 1,false);
}

void InputScreensDlg::setSeismicDataInitialControlStates()
{
    if(m_isNewData)
    {
        pnlGrpPeakGrndAccel->Hide();
        pnlGrpUBC->Hide();
        pnlGrpASCE->Hide();
    }
    else
    {

    }
}

bool InputScreensDlg::validateSeismicDataEntries()
{
    bool validationSuccess = true;
    if(0 > cmbChoiceSeismicDesignChoice->GetSelection())
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_SEISMIC_DATA);
        wxMessageBox("Seismic Design as per is mandatory", "Seismic Data Validation");
        validationSuccess = false;
        cmbChoiceSeismicDesignChoice->SetFocus();
    }
    else if(2 == m_inputData->Seismic_design_code
            && 0 > cmbChoiceUBCZoneNo->GetSelection())
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_SEISMIC_DATA);
        wxMessageBox("UBC Zone No. is mandatory", "Seismic Data Validation");
        validationSuccess = false;
        cmbChoiceUBCZoneNo->SetFocus();
    }

    return validationSuccess;
}

bool InputScreensDlg::transferSeismicDesignControlsData()
{
    bool transferSuccess = true;

    if(3 == m_inputData->Seismic_design_code) //Peak Ground Acceleration
    {
        transferSuccess = txtPeakGroundAccel->GetValidator()->TransferFromWindow();
    }
    else if(2 == m_inputData->Seismic_design_code)
    {
        //Currently no transfer required
    }
    else
    {
        transferSuccess = ( (txtASCESpectralAccelShort->GetValidator()->TransferFromWindow())
                            && (txtASCESpectralAccelOneSec->GetValidator()->TransferFromWindow()) );
    }

    return transferSuccess;
}

bool InputScreensDlg::transferSeismicDataWindowData()
{
    bool transferSuccess = false;
    if(transferSeismicDesignControlsData()
       && txtAccelBaseSiteCoeff->GetValidator()->TransferFromWindow()
       && txtVelBasedSiteCoeff->GetValidator()->TransferFromWindow()
       && txtTransitionLongGrnd->GetValidator()->TransferFromWindow()
       && txtCoeffAdjust->GetValidator()->TransferFromWindow())
    {
        transferSuccess = true;
    }

    return transferSuccess;


}

void InputScreensDlg::OncmbChoiceGovByASCERulesSelect(wxCommandEvent& event)
{
    int currentSelection = cmbChoiceGovByASCERules->GetSelection();
    if(1 == currentSelection) //YES selected
    {
        m_inputData->Factor_Q = 0.667;
    }
    else
    {
        m_inputData->Factor_Q = 1.00;
    }

    m_inputData->Sds = m_inputData->Factor_Q * m_inputData->Fa_user * m_inputData->Ss_user;
    txtSDSQFaSs->ChangeValue(wxString().FromDouble(m_inputData->Sds, 4));

    m_inputData->Sd1 = m_inputData->Factor_Q * m_inputData->Fv_user * m_inputData->S1_user;
        txtSD1QFvS1->ChangeValue(wxString().FromDouble(m_inputData->Sd1, 4)); cout<<"llok at Sd1 "<<m_inputData->Sd1<<endl;

    txtSeismicScaleFactor->ChangeValue(wxString().FromDouble(m_inputData->Factor_Q, 2));
}

void InputScreensDlg::OncmbChoiceSeismicUserGrpSelect(wxCommandEvent& event)
{
    m_inputData->SUG = cmbChoiceSeismicUserGrp->GetSelection() + 1;

    if(1 == m_inputData->SUG)
    {
        m_inputData->imp_factorS = 1.00;
    }
    else if(2 == m_inputData->SUG)
    {
        m_inputData->imp_factorS = 1.25;
    }
    else
    {
        m_inputData->imp_factorS = 1.50;
    }

    txtSeismicImportanceFactor->ChangeValue(wxString().FromDouble(m_inputData->imp_factorS, 2));
}

void InputScreensDlg::OncmbChoiceVertSeismicEffectSelect(wxCommandEvent& event)
{
    m_inputData->option_Av = cmbChoiceVertSeismicEffect->GetSelection();

    if(1 == m_inputData->option_Av)
    {
        m_inputData->Av = 0.47 * m_inputData->Sds;
    }
    else
    {
        m_inputData->Av = 0.00;
    }
}

void InputScreensDlg::OncmbChoiceSeismicDesignChoiceSelect(wxCommandEvent& event)
{
    int currentDesignCode = cmbChoiceSeismicDesignChoice->GetSelection();
    updateSeismicDesignDataAndControls(currentDesignCode,false);

}

void InputScreensDlg::updateSeismicDesignDataAndControls(int currentDesignCode, bool setDefault)
{
    m_inputData->Seismic_design_code = currentDesignCode + 1;

    if(3 == m_inputData->Seismic_design_code) //Peak Ground Acceleration
    {
        pnlGrpPeakGrndAccel->Show();
        pnlGrpUBC->Hide();
        pnlGrpASCE->Hide();

        if(setDefault)
        {
            m_inputData->S0_user = 0.0750F;
            m_inputData->Ss_user = 2.5 * m_inputData->S0_user;
            m_inputData->S1_user = m_inputData->Ss_user / 2;
        }
        txtSpectralAccelTimePeriod0->ChangeValue(wxString().FromDouble(m_inputData->S0_user, 4));
        txtPeakGroundAccel->ChangeValue(wxString().FromDouble(m_inputData->S0_user, 4));
        txtPGASpectralAccelShort->ChangeValue(wxString().FromDouble(m_inputData->Ss_user, 4));
        txtPGASpectralAccelOneSec->ChangeValue(wxString().FromDouble(m_inputData->S1_user, 4));
    }
    else if(2 == m_inputData->Seismic_design_code) //UBC 97
    {
        pnlGrpPeakGrndAccel->Hide();
        pnlGrpUBC->Show();
        pnlGrpASCE->Hide();

        if(setDefault)
        {
            cmbChoiceUBCZoneNo->SetSelection(0); //Zone 1
            m_inputData->Zone_Number = 1;
            m_inputData->S0_user = 0.0750F;
            m_inputData->Ss_user = 2.5 * m_inputData->S0_user;
            m_inputData->S1_user = m_inputData->Ss_user / 2;
        }
        txtSpectralAccelTimePeriod0->ChangeValue(wxString().FromDouble(m_inputData->S0_user, 4));
        cmbChoiceUBCZoneNo->SetSelection(m_inputData->Zone_Number - 1);
        txtUBCPeakGrndAccel->ChangeValue(wxString().FromDouble(m_inputData->S0_user, 4));
        txtUBCSpectralAccelShort->ChangeValue(wxString().FromDouble(m_inputData->Ss_user, 4));
        txtUBCSpectralAccelOneSec->ChangeValue(wxString().FromDouble(m_inputData->S1_user, 4));
    }
    else //ASCE 7-05
    {
        pnlGrpPeakGrndAccel->Hide();
        pnlGrpUBC->Hide();
        pnlGrpASCE->Show();

        if(setDefault)
        {
            m_inputData->Ss_user = 0.1875F;
            m_inputData->S1_user = m_inputData->Ss_user / 2;
        }
        m_inputData->S0_user = 0.4*m_inputData->Ss_user;
        txtSpectralAccelTimePeriod0->ChangeValue(wxString().FromDouble(m_inputData->S0_user, 4));
        txtASCESpectralAccelShort->ChangeValue(wxString().FromDouble(m_inputData->Ss_user, 4));
        txtASCESpectralAccelOneSec->ChangeValue(wxString().FromDouble(m_inputData->S1_user, 4));
    }

    BoxSizerSeismicDataMain->Layout();
}

void InputScreensDlg::OncmbChoiceUBCZoneNoSelect(wxCommandEvent& event)
{
    int currentSelection = cmbChoiceUBCZoneNo->GetSelection();
    m_inputData->Zone_Number = currentSelection + 1;

    if(1 == m_inputData->Zone_Number) //Zone 1
    {
        m_inputData->S0_user = 0.0750F;
    }
    else if(2 == m_inputData->Zone_Number) //Zone 2A
    {
        m_inputData->S0_user = 0.15F;
    }
    else if(3 == m_inputData->Zone_Number) //Zone 2B
    {
        m_inputData->S0_user = 0.2F;
    }
    else if(4 == m_inputData->Zone_Number) //Zone 3
    {
        m_inputData->S0_user = 0.3F;
    }
    else //Zone 4
    {
        m_inputData->S0_user = 0.4F;
    }

    txtUBCPeakGrndAccel->ChangeValue(wxString().FromDouble(m_inputData->S0_user, 4));

    m_inputData->Ss_user = 2.5 * m_inputData->S0_user;
    txtUBCSpectralAccelShort->ChangeValue(wxString().FromDouble(m_inputData->Ss_user, 4));

    m_inputData->S1_user = m_inputData->Ss_user / 2;
    txtUBCSpectralAccelOneSec->ChangeValue(wxString().FromDouble(m_inputData->S1_user, 4));

    m_inputData->Sds = m_inputData->Factor_Q * m_inputData->Fa_user * m_inputData->Ss_user;
    txtSDSQFaSs->ChangeValue(wxString().FromDouble(m_inputData->Sds, 4));

    m_inputData->Sd1 = m_inputData->Factor_Q * m_inputData->Fv_user * m_inputData->S1_user;
    txtSD1QFvS1->ChangeValue(wxString().FromDouble(m_inputData->Sd1, 4));// cout<<"llok at Sd1 "<<m_inputData->Sd1<<endl;
}

void InputScreensDlg::OntxtPeakGroundAccelKillFocus(wxFocusEvent& event)
{
    double peakGroundAccel = 0.0F;
    txtPeakGroundAccel->GetValue().ToDouble(&peakGroundAccel);
    if(m_inputData->S0_user != peakGroundAccel)
    {
        if(peakGroundAccel<0.01)
        {
            peakGroundAccel = 0.0750F;
            txtPeakGroundAccel->ChangeValue(wxString().FromDouble(peakGroundAccel, 4));
        }
        m_inputData->S0_user = peakGroundAccel;
        txtSpectralAccelTimePeriod0->ChangeValue(wxString().FromDouble(m_inputData->S0_user, 4));

        m_inputData->Ss_user = 2.5 * m_inputData->S0_user;
        txtPGASpectralAccelShort->ChangeValue(wxString().FromDouble(m_inputData->Ss_user, 4));

        m_inputData->S1_user = m_inputData->Ss_user / 2;
        txtPGASpectralAccelOneSec->ChangeValue(wxString().FromDouble(m_inputData->S1_user, 4));

        m_inputData->Sds = m_inputData->Factor_Q * m_inputData->Fa_user * m_inputData->Ss_user;
        txtSDSQFaSs->ChangeValue(wxString().FromDouble(m_inputData->Sds, 4));

        m_inputData->Sd1 = m_inputData->Factor_Q * m_inputData->Fv_user * m_inputData->S1_user;
        txtSD1QFvS1->ChangeValue(wxString().FromDouble(m_inputData->Sd1, 4)); cout<<"llok at Sd1 "<<m_inputData->Sd1<<endl;
    }

    event.Skip();
}

void InputScreensDlg::OntxtASCESpectralAccelShortKillFocus(wxFocusEvent& event)
{
    double asceSpectralAccelShort = 0.0F;
    txtASCESpectralAccelShort->GetValue().ToDouble(&asceSpectralAccelShort);

    if (asceSpectralAccelShort<0.01)
    	asceSpectralAccelShort=0.2;

    if(m_inputData->Ss_user != asceSpectralAccelShort)
    {
        txtASCESpectralAccelShort->ChangeValue(wxString().FromDouble(asceSpectralAccelShort, 4));

        m_inputData->Ss_user = asceSpectralAccelShort;

        m_inputData->S1_user = m_inputData->Ss_user / 2;
        txtASCESpectralAccelOneSec->ChangeValue(wxString().FromDouble(m_inputData->S1_user, 4));

        m_inputData->Sds = m_inputData->Factor_Q * m_inputData->Fa_user * m_inputData->Ss_user;
        txtSDSQFaSs->ChangeValue(wxString().FromDouble(m_inputData->Sds, 4));

        m_inputData->Sd1 = m_inputData->Factor_Q * m_inputData->Fv_user * m_inputData->S1_user;
        txtSD1QFvS1->ChangeValue(wxString().FromDouble(m_inputData->Sd1, 4)); cout<<"llok at Sd1 "<<m_inputData->Sd1<<endl;
    }

    event.Skip();
}

void InputScreensDlg::OntxtASCESpectralAccelOneSecKillFocus(wxFocusEvent& event)
{
    double asceSpectralAccelOneSec = 0.0F;

    txtASCESpectralAccelOneSec->GetValue().ToDouble(&asceSpectralAccelOneSec);

    if(asceSpectralAccelOneSec<0.01)
    	asceSpectralAccelOneSec=0.1;
    if(m_inputData->S1_user != asceSpectralAccelOneSec)
    {
        txtASCESpectralAccelOneSec->ChangeValue(wxString().FromDouble(asceSpectralAccelOneSec, 4));

        m_inputData->S1_user = asceSpectralAccelOneSec;

        m_inputData->Sds = m_inputData->Factor_Q * m_inputData->Fa_user * m_inputData->Ss_user;
        txtSDSQFaSs->ChangeValue(wxString().FromDouble(m_inputData->Sds, 4));

        m_inputData->Sd1 = m_inputData->Factor_Q * m_inputData->Fv_user * m_inputData->S1_user;
        txtSD1QFvS1->ChangeValue(wxString().FromDouble(m_inputData->Sd1,4 )); cout<<"llok at Sd1 "<<m_inputData->Sd1<<endl;
    }

    event.Skip();
}


void InputScreensDlg::OntxtVelBaseSiteCoeffKillFocus(wxFocusEvent& event)
{
    double VelBaseSiteCoeff = 0.0F;

    txtVelBasedSiteCoeff->GetValue().ToDouble(&VelBaseSiteCoeff);
    m_inputData->Fv_user = VelBaseSiteCoeff;

    if(VelBaseSiteCoeff<0.01)
    {
    	VelBaseSiteCoeff=m_inputData->Fv_default;
    	m_inputData->Fv_user = VelBaseSiteCoeff;
    	txtVelBasedSiteCoeff->ChangeValue(wxString().FromDouble(VelBaseSiteCoeff, 2));
    }

    event.Skip();
}



void InputScreensDlg::OncmbChoiceSeismicSiteClassSelect(wxCommandEvent& event)
{
    int currentSelection = cmbChoiceSeismicSiteClass->GetSelection();

    m_inputData->site_class = currentSelection + 1;
}

void InputScreensDlg::OntxtTransitionLongGrndKillFocus(wxFocusEvent& event)
{
    double transitionLongGrnd = 0.0F;

    txtTransitionLongGrnd->GetValue().ToDouble(&transitionLongGrnd);

    if(0.0F == transitionLongGrnd)
    {
        transitionLongGrnd = 0.40F;
        txtTransitionLongGrnd->ChangeValue(wxString().FromDouble(transitionLongGrnd, 2));
    }

    event.Skip();
}

void InputScreensDlg::OntxtCoeffAdjustKillFocus(wxFocusEvent& event)
{
    double coeffAdjust = 0.0F;

    txtCoeffAdjust->GetValue().ToDouble(&coeffAdjust);

    if(0.0F == coeffAdjust)
    {
        coeffAdjust = 1.50F;
        txtCoeffAdjust->ChangeValue(wxString().FromDouble(coeffAdjust, 2));
    }

    event.Skip();
}

void InputScreensDlg::OntxtAccelBaseSiteCoeffKillFocus(wxFocusEvent& event)
{
    double accelBaseSiteCoeff = 0.0F;

    txtAccelBaseSiteCoeff->GetValue().ToDouble(&accelBaseSiteCoeff);

    m_inputData->Fa_user = accelBaseSiteCoeff;

    if(accelBaseSiteCoeff<0.01)
    {
    	accelBaseSiteCoeff=m_inputData->Fa_default;
    	m_inputData->Fa_user = accelBaseSiteCoeff;
    	txtAccelBaseSiteCoeff->ChangeValue(wxString().FromDouble(accelBaseSiteCoeff, 2));
    }

    m_inputData->Sds = m_inputData->Factor_Q * m_inputData->Fa_user * m_inputData->Ss_user;

    txtSDSQFaSs->ChangeValue(wxString().FromDouble(m_inputData->Sds, 4));

    event.Skip();
}

void InputScreensDlg::OntxtVelBasedSiteCoeffKillFocus(wxFocusEvent& event)
{
    double velBasedSiteCoeff = 0.0F;

    txtVelBasedSiteCoeff->GetValue().ToDouble(&velBasedSiteCoeff);

    m_inputData->Fv_user = velBasedSiteCoeff;
    m_inputData->Sd1 = m_inputData->Factor_Q * m_inputData->Fv_user * m_inputData->S1_user;

        txtSD1QFvS1->ChangeValue(wxString().FromDouble(m_inputData->Sd1, 4)); cout<<"llok at Sd1 "<<m_inputData->Sd1<<endl;

    event.Skip();
}

void InputScreensDlg::OnGrid1CellLeftClick(wxGridEvent& event)
{
	int i = event.GetRow();
    if(event.GetCol() == 1 && event.GetRow() != gridShellDesign->GetNumberRows() - 1 && event.GetRow()<m_inputData->No_of_ShellCourses)
    {
        MaterialSelection materialSelectDlg(this);
        materialSelectDlg.SetLayoutAdaptationMode(wxDIALOG_ADAPTATION_MODE_ENABLED);
        materialSelectDlg.SetInitialValues(m_inputData->Shell_Appendx_No_user,m_inputData->Shell_Material_No[i][0]);
        materialSelectDlg.ShowModal();

        unsigned int temp = materialSelectDlg.GetSelectedMaterialSerialNumber();
    	gridShellDesign->SetCellValue(event.GetRow(),event.GetCol(),materialSelectDlg.radioBoxMaterial->GetString(materialSelectDlg.materialNumberToIndex(temp)));
    	m_inputData->Shell_Material_No[i][0]=temp;
    	m_inputData->shell_detail_user[i][0]=materialSelectDlg.utsValue;
    }
    //gridShellDesign->SetCellValue(0,4,wxString::Format(" ns %d %d",m_inputData->No_of_ShellCourses,event.GetCol()));

    if(event.GetCol()==2 && (event.GetRow()>0&&event.GetRow()<=m_inputData->No_of_ShellCourses-1))
    {
        double courseWidth;
        gridShellDesign->GetCellValue(event.GetRow(),2).ToDouble(&courseWidth);
        if(m_inputData->shell_detail_user[event.GetRow()][1]!=courseWidth)
    	{
            m_inputData->No_of_ShellCourses = event.GetRow()+1;
            cout<<"shell courses changed\n";
        }
    	//gridShellDesign->SetCellValue(0,4,wxString::Format(" ns %d",m_inputData->No_of_ShellCourses));
    }

    event.Skip();
}

void InputScreensDlg::setupShellDesignValidators()
{
    gridShellDesign->SetColFormatNumber(0);

    gridShellDesign->SetColFormatFloat(2, 4, 3);
    gridShellDesign->SetColFormatFloat(3, 3, 2);
    gridShellDesign->SetColFormatFloat(5, 4, 3);
    gridShellDesign->SetColFormatFloat(6, 3, 2);
    gridShellDesign->SetColFormatFloat(7, 4, 2);
    gridShellDesign->SetColFormatFloat(8, 4, 2);
    gridShellDesign->SetColFormatFloat(9, 4, 2);
    gridShellDesign->SetColFormatFloat(10, 3, 1);
    gridShellDesign->SetColFormatFloat(11, 3, 1);
    gridShellDesign->SetColFormatFloat(12, 4, 2);
    gridShellDesign->SetColFormatFloat(13, 4, 2);
}

void InputScreensDlg::setShellDesignInitialControlValues()
{
    for(int rowIndex = 0; rowIndex < gridShellDesign->GetNumberRows(); ++rowIndex)
    {
        gridShellDesign->SetCellValue(rowIndex, 0, wxString::Format("%d", rowIndex + 1) );
    }
}

void InputScreensDlg::setShellDesignInitialControlStates()
{
	// Create grid for labels
	gridShellDesignLabel->CreateGrid(1,14);
	gridShellDesignLabel->HideRowLabels();
	gridShellDesignLabel->HideColLabels();
	gridShellDesignLabel->SetDefaultColSize(110, true);
	gridShellDesignLabel->SetCellValue(0,0, _("Shell\nCourse\nNumber\n(n)"));
	gridShellDesignLabel->SetCellValue(0,1, _("Course Material  "));
	gridShellDesignLabel->SetCellValue(0,2, _("Course Width\n(User Defined)\nM."));
	gridShellDesignLabel->SetCellValue(0,3, _("Corrosion\nAllowance\nmm"));
	gridShellDesignLabel->SetCellValue(0,4, _(""));
	gridShellDesignLabel->SetCellValue(0,5, _("Course\nWidth\n(Adopted)\nM"));
	gridShellDesignLabel->SetCellValue(0,6, _("Corrosion\nAllowance\nAdopted\nmm"));
	gridShellDesignLabel->SetCellValue(0,7, _("Required\nthickness for\nProduct design\ncondition\nmm"));
	gridShellDesignLabel->SetCellValue(0,8, _("Required\nthickness\nfor Hydro\ntest\nCondition\nmm"));
	gridShellDesignLabel->SetCellValue(0,9, _("Required\nthickness\nagainst\nseismic\nload mm"));
	gridShellDesignLabel->SetCellValue(0,10, _("User\ndefined\nthickness\nmm"));
	gridShellDesignLabel->SetCellValue(0, 11, _("Adopted\nthickness\nmm"));
	gridShellDesignLabel->SetCellValue(0, 12, _("Maximum\npermitted\nthickness for\nthe selected\nmaterial\nmm"));
	gridShellDesignLabel->SetCellValue(0, 13, _("Thickness\nabove\nwhich Impact\ntest is\nrequired\nmm"));

	wxFont font(10,wxFONTFAMILY_MODERN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD);
    gridShellDesignLabel->ShowScrollbars(wxSHOW_SB_NEVER,wxSHOW_SB_NEVER);
	for(int i=0;i<14;i++)
	{
		gridShellDesignLabel->SetCellFont(0,i,font);
		gridShellDesignLabel->SetCellAlignment(0,i,wxALIGN_CENTER,wxALIGN_TOP);
        gridShellDesignLabel->SetCellBackgroundColour(0, i, wxColour(225,225,225));

	}

	gridShellDesignLabel->AutoSizeRows();
	gridShellDesignLabel->AutoSizeColumns();
	gridShellDesignLabel->SetColSize(4,0);

    int n,colWidths=0;
    n = gridShellDesignLabel->GetNumberCols();
    for (int i = 0; i < n - 1; i++)
        colWidths += gridShellDesignLabel->GetColSize (i);

    int finalColWidth = gridShellDesignLabel->GetSize().x - colWidths;
    gridShellDesignLabel->SetColSize (n - 1, finalColWidth);

	for(int rowIndex = 0; rowIndex < gridShellDesignLabel->GetNumberRows(); ++rowIndex)
    {
        for(int colIndex = 0; colIndex < gridShellDesignLabel->GetNumberCols(); ++colIndex)
        {
            gridShellDesignLabel->SetReadOnly(rowIndex, colIndex, true);
        }
    }

	gridShellDesign->CreateGrid(16,14);
	gridShellDesign->EnableEditing(true);
	gridShellDesign->EnableGridLines(true);
	gridShellDesign->SetColLabelSize(30);
	gridShellDesign->SetDefaultRowSize(25, true);
	gridShellDesign->SetDefaultColSize(100, true);

	gridShellDesign->SetDefaultCellFont( gridShellDesign->GetFont() );
	gridShellDesign->SetDefaultCellTextColour( gridShellDesign->GetForegroundColour() );

	gridShellDesign->HideRowLabels();
	gridShellDesign->HideColLabels();

    for(int i=0;i<14;i++)
    {
        gridShellDesign->SetColSize(i,gridShellDesignLabel->GetColSize(i));
    }

    gridShellDesign->SetColSize(13,gridShellDesignLabel->GetColSize(13)-18);

	for(int rowIndex = 0; rowIndex < gridShellDesign->GetNumberRows(); ++rowIndex)
    {
        for(int colIndex = 0; colIndex < gridShellDesign->GetNumberCols(); ++colIndex)
        {
            gridShellDesign->SetReadOnly(rowIndex, colIndex, true);
            if(colIndex==1||colIndex==2||colIndex==3||colIndex==10)
                gridShellDesign->SetCellBackgroundColour(rowIndex, colIndex, wxColour("PINK"));
            else
                gridShellDesign->SetCellBackgroundColour(rowIndex, colIndex, wxColour("LIGHT GREY"));
        }
    }
    //->SetBackgroundColour(wxColour(100,255,200));
    gridShellDesign->ShowScrollbars(wxSHOW_SB_NEVER,wxSHOW_SB_ALWAYS);
    gridShellDesign->SetCellBackgroundColour(0, 1, wxColour(100,255,200));
    gridShellDesign->SetCellBackgroundColour(0, 2, wxColour("LIGHT GREY"));
    gridShellDesign->SetCellBackgroundColour(0, 3, wxColour("LIGHT GREY"));
    gridShellDesign->SetGridLineColour(wxColour("BLACK"));
    gridShellDesignLabel->SetGridLineColour(wxColour("BLACK"));
    gridShellDesign->SetReadOnly(0, 10, false);
}
void InputScreensDlg::ChangeReadabilityShellDesign(int row, bool readOnly)
{
	gridShellDesign->SetReadOnly(row, 1, readOnly);
    gridShellDesign->SetReadOnly(row, 2, readOnly);
    gridShellDesign->SetReadOnly(row, 3, readOnly);
    gridShellDesign->SetReadOnly(row, 10, readOnly);
}

void InputScreensDlg::OnButtonRunShellClick(wxCommandEvent& event)
{
	if(m_inputData->No_of_ShellCourses==0)
		return;

    //check if anything changed on upper rows
    for(int i=1;i<m_inputData->No_of_ShellCourses-1;i++)
    {
        double H_Course;
        gridShellDesign->GetCellValue(i,2).ToDouble(&H_Course);
        if(m_inputData->shell_detail_user[i][1]!=H_Course)
        {
            m_inputData->No_of_ShellCourses = i+1;
            cout<<"hehe "<<m_inputData->shell_detail_user[i][1]<<" "<<H_Course<<endl;
            break;
        }
    }
	int i = m_inputData->No_of_ShellCourses;
	int n = m_inputData->No_of_ShellCourses-1;
	double sum=0;
	for(int j=0;j<n;j++)
	{
        sum+=m_inputData->shell_detail_user[j][1];
        //cout<<m_inputData->shell_detail_user[j][1]<<" ";
    }

	m_inputData->H_Remaining=m_inputData->H-sum;

    for(int row=0;row<=n;row++)
    {
        for(int col=7;col<gridShellDesign->GetNumberCols();col++)
            gridShellDesign->SetCellValue(row,col, wxString::Format(""));
    }
	while(!gridShellDesign->IsReadOnly(i,2))
	{
		//clear the stuff for other columns too
        for(int j=1;j<gridShellDesign->GetNumberCols();j++)
            gridShellDesign->SetCellValue(i, j, wxString::Format(""));

        for(int col=7;col<gridShellDesign->GetNumberCols();col++)
            gridShellDesign->SetCellValue(i,col, wxString::Format(""));

		ChangeReadabilityShellDesign(i,true);
		i++;
	}
	double H_Course;
    gridShellDesign->GetCellValue(n,2).ToDouble(&H_Course);


    if (H_Course < 0.001)
    	H_Course = m_inputData->shell_detail_user[n-1][1]; // making it equal to the previous row

    if (H_Course <= (m_inputData->H_Remaining - 0.5))
		m_inputData->shell_detail_user[n][1] = H_Course; // accept what the user has input
	else
		m_inputData->shell_detail_user[n][1] = m_inputData->H_Remaining;
	//shell_detail[n][0] = m_inputData->shell_detail_user[n][1];

	gridShellDesign->SetCellValue(n,2,wxString::Format("%.3f",m_inputData->shell_detail_user[n][1]));
	gridShellDesign->SetCellValue(n,5,wxString::Format("%.3f",m_inputData->shell_detail_user[n][1]));

	m_inputData->H_Remaining -=m_inputData->shell_detail_user[n][1];
	// gridShellDesign->SetCellValue(1, 3, wxString::Format("h %f",m_inputData->H_Remaining));

	//corrosion allowance
	double CA = 0.0F;
	gridShellDesign->GetCellValue(n,3).ToDouble(&CA);
	m_inputData->shell_detail_user[n][2] = CA;
	if (CA < 0.001)
		m_inputData->shell_detail[n][9] = m_inputData->shell_detail[n-1][9];
	else if (CA < 0.1)
		m_inputData->shell_detail[n][9] = 0;
	else
		m_inputData->shell_detail[n][9] = m_inputData->shell_detail_user[n][2];

	gridShellDesign->SetCellValue(n,6,wxString::Format("%.2f",m_inputData->shell_detail[n][9]));
	gridShellDesign->SetCellValue(n,3,wxString::Format("%.2f",m_inputData->shell_detail_user[n][2]));

	if(m_inputData->H_Remaining>0.0005)
    {
    	ChangeReadabilityShellDesign(n+1,false);
    	m_inputData->No_of_ShellCourses++;
        wxString t = gridShellDesign->GetCellValue(n,1);
        gridShellDesign->SetCellValue(n+1, 1, t);
        m_inputData->Shell_Material_No[n+1][0] = m_inputData->Shell_Material_No[n][0];
        // wxMessageBox(wxString::Format("Edit the course width and then click on Add Shell Course button\nRemaining height is %.2f",m_inputData->H_Remaining),"Note");
    }
    //incase someone updates corrosion allowance
    for(n=1;n<m_inputData->No_of_ShellCourses;n++)
    {
        double CA = 0.0F;
        gridShellDesign->GetCellValue(n,3).ToDouble(&CA);
        if(CA!=m_inputData->shell_detail_user[n][2])
        {
            m_inputData->shell_detail_user[n][2] = CA;
            if (CA < 0.001)
                m_inputData->shell_detail[n][9] = m_inputData->shell_detail[(n - 1)][9];
            else if (CA < 0.1)
                m_inputData->shell_detail[n][9] = 0;
            else
                m_inputData->shell_detail[n][9] = m_inputData->shell_detail_user[n][2];

            gridShellDesign->SetCellValue(n,6,wxString::Format("%.2f",m_inputData->shell_detail[n][9]));
            gridShellDesign->SetCellValue(n,3,wxString::Format("%.2f",m_inputData->shell_detail_user[n][2]));
        }

    }
    event.Skip();
}

void InputScreensDlg::OnButtonDesignShellClick(wxCommandEvent& event)
{
	int n = m_inputData->No_of_ShellCourses;

    if(m_inputData->H_Remaining>0)
    {
        // wxMessageBox(wxString::Format("Please Add all the shells first. Remaining height is %.2f",m_inputData->H_Remaining),"Note");
        event.Skip();
        return;
    }

    ButtonDesignShell->SetFocus();//random focus set

    //read user defined thickness
    for(int i=0;i<m_inputData->No_of_ShellCourses;i++)
    {
        double val=0.0f;
        gridShellDesign->GetCellValue(i,10).ToDouble(&val);
        if(gridShellDesign->GetCellValue(i,10)=="")
            val=0.;
        m_inputData->shell_detail_user[i][3] = val;
    }
    //call shell_details() function
    InitVariables();
    ReadVariables(*m_inputData);
    //edit_option=1;
    Input_Screen_1();
    Wind_Data();
    Seismic_Data();
    shell_Details();
    if (m_inputData->Roof_Type_No > 6)
    {    PWG_Data();
    }
    else
        shell_Stiffener_Location();

    shell_Stfr_User_EL();


    PopulateVariables(*m_inputData);
    for(int i=0;i<m_inputData->No_of_Stiffeners_R;i++)
    {
        cout<<m_inputData->user_EL_detail[i][9]<<" "<<m_inputData->user_EL_detail[i][10]<<endl;
    }
	for(int i=0;i<n;i++)
	{

		//call the shell design function here
		if(m_inputData->Shell_Des_Method_No==1){
			gridShellDesign->SetCellValue(i,7,wxString::Format("%.2f",m_inputData->shell_detail[i][10]));
			gridShellDesign->SetCellValue(i,8,wxString::Format("%.2f",m_inputData->shell_detail[i][11]));
		}
		else{
			gridShellDesign->SetCellValue(i,7,wxString::Format("%.2f", m_inputData->shell_detail[i][12]));
			gridShellDesign->SetCellValue(i,8,wxString::Format("%.2f", m_inputData->shell_detail[i][13]));
		}
		gridShellDesign->SetCellValue(i,9,wxString::Format("%.2f",max( m_inputData->shell_detail[i][14], m_inputData->shell_detail[i][15])));
		gridShellDesign->SetCellValue(i,10,wxString::Format("%.1f", m_inputData->shell_detail_user[i][3]));
        gridShellDesign->SetCellValue(i,11,wxString::Format("%.2f", m_inputData->shell_detail[i][18]));
		gridShellDesign->SetCellValue(i,12,wxString::Format("%.2f", m_inputData->shell_detail[i][27]));
		gridShellDesign->SetCellValue(i,13,wxString::Format("%.2f", m_inputData->shell_detail[i][28]));

	}
}

void InputScreensDlg::setupPrimaryWindGirderDesignValidators()
{
    wxFloatingPointValidator<double> validatorDoubleSpaceTopWGTopTank(2, &(m_inputData->Spacing_Top_WG_User), wxNUM_VAL_ZERO_AS_BLANK);
    txtSpaceTopWGTopTank->SetValidator(validatorDoubleSpaceTopWGTopTank);

    wxFloatingPointValidator<double> validatorDoubleMinWidthTopWGAsWalkway(2, &(m_inputData->PWG_width_min_user), wxNUM_VAL_ZERO_AS_BLANK);
    txtMinWidthTopWGAsWalkway->SetValidator(validatorDoubleMinWidthTopWGAsWalkway);

    Gridpwg->SetColFormatFloat(1, 6, 1);
    Gridpwg->SetColFormatFloat(3, 6, 1);
}

void InputScreensDlg::setPrimaryWindGirderDesignInitialControlValues()
{
    const int FLOAT_VALUE_PRECISION_TWO = 2;

    cmbTopWGAsWalkway->SetSelection(m_inputData->Option_walkway);

    txtSpaceTopWGTopTank->ChangeValue(wxString().FromDouble(m_inputData->Spacing_Top_WG_User, FLOAT_VALUE_PRECISION_TWO));

    cmblSizeTopAngle->SetSelection(m_inputData->curb_angle_No_user-1);

    txtMinWidthTopWGAsWalkway->ChangeValue(wxString().FromDouble(m_inputData->PWG_width_min_user, FLOAT_VALUE_PRECISION_TWO));

    cmblDesignTopWGTankDia->SetSelection(m_inputData->Option_PWG);

    TextSectionModRqd->ChangeValue(wxString().FromDouble(m_inputData->PWG_details[0], FLOAT_VALUE_PRECISION_TWO));

    TextMOIRqd->ChangeValue(wxString().FromDouble(m_inputData->PWG_details[16], FLOAT_VALUE_PRECISION_TWO));

     for(int i=0;i<3;i++)
    {
    	for(int j=0;j<5;j++)
    	{
    		Gridpwg->SetCellValue(i,j,wxString().FromDouble(m_inputData->PWG_details[i*5+j+1],FLOAT_VALUE_PRECISION_TWO));
    	}
        Gridpwg->SetCellValue(i,5,wxString().FromDouble(m_inputData->PWG_details[i+17],2));
    }

    Gridpwg->SetCellValue(1,0,wxString().FromDouble(m_inputData->PWG_Width_Web_User,2));
    Gridpwg->SetCellValue(1,1,wxString().FromDouble(m_inputData->PWG_Thick_Web,2));
    Gridpwg->SetCellValue(1,2,wxString().FromDouble(m_inputData->PWG_Height_Flange,2));
    Gridpwg->SetCellValue(1,3,wxString().FromDouble(m_inputData->PWG_Thick_Flange,2));


    //Gridpwg->SetCellValue(0,5,wxString::Format("%.2f",m_inputData->PWG_details[]));

}

void InputScreensDlg::setPrimaryWindGirderDesignInitialControlStates()
{
    changeWalkwayRelatedControlsVisibility(m_inputData->Option_walkway);
    updatePrimaryWindGirderScreen();

    Gridpwg->AutoSizeColumns();
    Gridpwg->SetGridLineColour(wxColour("BLACK"));
    for(int rowIndex = 0; rowIndex < Gridpwg->GetNumberRows(); ++rowIndex)
    {
    	for (int j=0;j<Gridpwg->GetNumberCols();j++){
        	Gridpwg->SetReadOnly(rowIndex, j, true);
        	Gridpwg->SetCellAlignment(rowIndex,j,wxALIGN_CENTER,wxALIGN_TOP);
            Gridpwg->SetCellBackgroundColour(rowIndex, j, wxColour("LIGHT GREY"));
        }
    }

    for (int j=0;j<4;j++)
    {
        Gridpwg->SetReadOnly(1, j, false);
        Gridpwg->SetCellBackgroundColour(1, j, wxColour("PINK"));
    }

    // Gridpwg->SetCellSize(0,5,3,1);
    Gridpwg->SetCellAlignment(0,5,wxALIGN_CENTER,wxALIGN_CENTER);
    Gridpwg->EnableGridLines(true);
    Gridpwg->EnableEditing(true);

    Gridpwg->ShowScrollbars(wxSHOW_SB_NEVER,wxSHOW_SB_NEVER);

    TextMOIRqd->SetBackgroundColour(wxColor("PINK"));
}

void InputScreensDlg::OncmbTopWGAsWalkwaySelect(wxCommandEvent& event)
{
    // wxMessageBox(wxString::Format("%f %f",m_inputData->PWG_details[5],m_inputData->PWG_details[6]));
    m_inputData->Option_walkway = cmbTopWGAsWalkway->GetSelection();
    changeWalkwayRelatedControlsVisibility(m_inputData->Option_walkway);
    if(m_inputData->Option_walkway==1)
    {
        cmblSizeTopAngle->SetSelection(m_inputData->curb_angle_No_user-1);
        double angle_section_width[7] = {65, 65, 65, 75, 75, 75, 90 };
        double PWG_width_min_default = 710+angle_section_width[m_inputData->curb_angle_No_user-1];
        txtMinWidthTopWGAsWalkway->SetValue(wxString::Format("%.2f",PWG_width_min_default));
        m_inputData->PWG_width_min_user=PWG_width_min_default;
    }
}

void InputScreensDlg::changeWalkwayRelatedControlsVisibility(int selection)
{
    if(1 == selection)
    {
        m_inputData->Spacing_Top_WG_User = 1.1;

        lblSpaceTopWGTopTank->Show(false);
        txtSpaceTopWGTopTank->Show(false);
        //lblUnitSpaceTopWGTopTank->Show(false);

        lblMinWidthTopWGAsWalkway->Show();
        txtMinWidthTopWGAsWalkway->Show();
        //lblUnitMinWidthTopWGAsWalkway->Show();
    }
    else
    {
        lblSpaceTopWGTopTank->Show();
        txtSpaceTopWGTopTank->Show();
       // lblUnitSpaceTopWGTopTank->Show();

        lblMinWidthTopWGAsWalkway->Show(false);
        txtMinWidthTopWGAsWalkway->Show(false);
        //lblUnitMinWidthTopWGAsWalkway->Show(false);
    }
}

void InputScreensDlg::OncmblDesignTopWGTankDiaSelect(wxCommandEvent& event)
{
    m_inputData->Option_PWG = cmblDesignTopWGTankDia->GetSelection();
}

void InputScreensDlg::updatePrimaryWindGirderScreen()
{
    cout<<"inupdate pwg\n";
    if(m_inputData->D_User > 61)
    {
        lblDesignTopWGTankDia->Show();
        cmblDesignTopWGTankDia->Show();
        lblMOIRqd->Show();
        TextMOIRqd->Show();
        Gridpwg->AutoSizeColumns();
        cout<<"d user is \n";
//        lblDummyUnit3->Show();
    }
    else
    {
        lblDesignTopWGTankDia->Show(false);
        cmblDesignTopWGTankDia->Show(false);
        lblMOIRqd->Show(false);
        TextMOIRqd->Show(false);
        Gridpwg->SetColSize(5,0);
        //lblDummyUnit3->Show(false);
    }
    cout<<"returning\n";
}

void InputScreensDlg::setupRoofDataValidators()
{
    wxFloatingPointValidator<double> validatorDoubleRRoof(3, &(m_inputData->R_Roof_user));
    txtRRoof->SetValidator(validatorDoubleRRoof);

    wxFloatingPointValidator<double> validatorDoubleLiveLoad(2, &(m_inputData->live_load_user));
    txtLiveLoad->SetValidator(validatorDoubleLiveLoad);

    wxFloatingPointValidator<double> validatorDoubleSnowLoadBal(2, &(m_inputData->snow_load_bal));
    txtBalancedSL->SetValidator(validatorDoubleSnowLoadBal);

    wxFloatingPointValidator<double> validatorDoubleSnowLoadUnBal(2, &(m_inputData->snow_load_unbal));
    txtUnBalancedSL->SetValidator(validatorDoubleSnowLoadUnBal);

    wxFloatingPointValidator<double> validatorDoubleWeightFloatingRoof(2, &(m_inputData->Weight_FR));
    txtWeightFloatingRoof->SetValidator(validatorDoubleWeightFloatingRoof);

    wxFloatingPointValidator<double> validatorDomeRadius(2, &(m_inputData->dome_radius_user));
    txtDomeRadius->SetValidator(validatorDomeRadius);

    wxFloatingPointValidator<double> validatorDoubleWeightNozzle(2, &(m_inputData->WeightAdder_roof_user));
    txtWeightNozzle->SetValidator(validatorDoubleWeightNozzle);

    wxFloatingPointValidator<double> validatorDoubleWeightPlatform(2, &(m_inputData->weight_platform_user));
    //txtWeightPlatform->SetValidator(validatorDoubleWeightPlatform);

    wxFloatingPointValidator<double> validatorDoubleGeodesicRoof(2, &(m_inputData->Wt_Roof_Str_user));
    txtWtGeodesicRoof->SetValidator(validatorDoubleGeodesicRoof);

    wxFloatingPointValidator<double> validatorDoubleCorrWeight(2, &(m_inputData->Wt_Roof_Str_cor));
    txtCorrWeight->SetValidator(validatorDoubleCorrWeight);

    wxFloatingPointValidator<double> validatorDoublePercWeight(2, &(m_inputData->fraction_roof_weight));
    txtPercWeight->SetValidator(validatorDoublePercWeight);

    wxIntegerValidator<int> validatorDoubleSlopeNum(&(m_inputData->roof_slope_user_numerator));
    txtSlopeNum->SetValidator(validatorDoubleSlopeNum);

    wxIntegerValidator<int> validatorDoubleSlopeDen(&(m_inputData->roof_slope_user_denominator));
    txtSlopeDen->SetValidator(validatorDoubleSlopeDen);
}

void InputScreensDlg::setRoofDataInitialControlValues()
{

    const int FLOAT_VALUE_PRECISION = 2;
    string Roof_type[9] = { "Fixed Roof type", "SELF SUPPORTING CONE ROOF", "SELF SUPPORTING DOME / UMBRELLA ROOF", "SUPPORTED CONE ROOF", "SUPPORTED DOME / UMBRELLA ROOF", "STIFFENED CONE ROOF", "STIFFENED DOME ROOF", "GEODESIC ROOF", "No Fixed Roof" };

    cmbRoofType->SetSelection(fixedRoofTypeMappingToUI[m_inputData->Roof_Type_No_user]);
    txtRoofTypeAdopted->ChangeValue(wxString(Roof_type[(int)m_inputData->Roof_Type_No]));

    txtLiveLoad->ChangeValue(wxString().FromDouble(m_inputData->live_load_user, FLOAT_VALUE_PRECISION));
    txtBalancedSL->ChangeValue(wxString().FromDouble(m_inputData->snow_load_bal, FLOAT_VALUE_PRECISION));
    txtUnBalancedSL->ChangeValue(wxString().FromDouble(m_inputData->snow_load_unbal, FLOAT_VALUE_PRECISION));

    txtMaxSpace1->ChangeValue(wxString().FromDouble(m_inputData->Rafter_spacing, FLOAT_VALUE_PRECISION));
    txtMaxSpace2->ChangeValue(wxString().FromDouble(m_inputData->Rafter_spacing_cent, FLOAT_VALUE_PRECISION));
    cmbTypeFloatingRoof->SetSelection(m_inputData->FR_Type_No-1);
    txtWeightFloatingRoof->ChangeValue(wxString().FromDouble(m_inputData->Weight_FR,2));

    txtWeightNozzle->ChangeValue(wxString().FromDouble(m_inputData->WeightAdder_roof_default, FLOAT_VALUE_PRECISION));
    txtWtGeodesicRoof->ChangeValue(wxString().FromDouble(m_inputData->Wt_Roof_Str_defaut, FLOAT_VALUE_PRECISION));
    cmbJointEff->SetSelection(m_inputData->JE_roof_user);

    txtRequiredThickness->ChangeValue(wxString().FromDouble(m_inputData->Roof_Thk[8],FLOAT_VALUE_PRECISION));
    if(m_inputData->Wt_Roof_Str_cor>0)
    {
        txtCorrWeight->ChangeValue(wxString().FromDouble(m_inputData->Wt_Roof_Str_cor,2));
    }
    else
    {
        txtCorrWeight->ChangeValue(wxString().FromDouble(m_inputData->Wt_Roof_Str_defaut*0.85,2));
        m_inputData->Wt_Roof_Str_cor=m_inputData->Wt_Roof_Str_defaut*0.85;
    }

    txtPercWeight->ChangeValue(wxString().FromDouble(m_inputData->fraction_roof_weight*100,2));
    setRoofDataDefaultValues();
    if(!m_isNewData)
    {
        cmbFrangible->SetSelection(m_inputData->option_frangible_roof);

        cmbTypeFloatingRoof->SetSelection(m_inputData->FR_Type_No - 1);

        if(m_inputData->Weight_FR_user>0)
        {
            txtWeightFloatingRoof->ChangeValue(wxString().FromDouble(m_inputData->Weight_FR_user, FLOAT_VALUE_PRECISION));
        }
        else
            txtWeightFloatingRoof->ChangeValue(wxString().FromDouble(m_inputData->Weight_FR, FLOAT_VALUE_PRECISION));
        m_inputData->WeightAdder_roof = m_inputData->WeightAdder_roof_user;
        m_inputData->weight_platform = m_inputData->weight_platform_user;
        m_inputData->Wt_Roof_Str=m_inputData->Wt_Roof_Str_user;
        txtWtGeodesicRoof->ChangeValue(wxString().FromDouble(m_inputData->Wt_Roof_Str_user, FLOAT_VALUE_PRECISION));
        txtWeightNozzle->ChangeValue(wxString().FromDouble(m_inputData->WeightAdder_roof_user, FLOAT_VALUE_PRECISION));
        //txtWeightPlatform->ChangeValue(wxString().FromDouble(m_inputData->weight_platform_user, FLOAT_VALUE_PRECISION));
        MaterialSelection materialSelectDlg(this);
        if(m_inputData->Roof_Material_No>0&&m_inputData->Roof_Material_No<130)
        txtMaterialRoof->ChangeValue(materialSelectDlg.radioBoxMaterial->GetString(materialSelectDlg.materialNumberToIndex(m_inputData->Roof_Material_No)));
        if(m_inputData->roof_slope_user_numerator>0)
            txtSlopeNum->ChangeValue(wxString::Format("%d",(int)m_inputData->roof_slope_user_numerator));
        if(m_inputData->roof_slope_user_denominator>0)
            txtSlopeDen->ChangeValue(wxString::Format("%d",(int)m_inputData->roof_slope_user_denominator));
        if(m_inputData->dome_radius_user>0.0){
            txtDomeRadius->ChangeValue(wxString::Format("%.2f",(int)m_inputData->dome_radius_user));
        }
    }
    updateRoofSlopeValues();

}

void InputScreensDlg::setRoofDataInitialControlStates()
{
    if(m_inputData->Roof_Type_No==-1)
        m_inputData->Roof_Type_No=m_inputData->Roof_Type_No_user;
    txtSlopeNum->SetBackgroundColour(wxColour(100,255,200));
    txtSlopeDen->SetBackgroundColour(wxColour(100,255,200));
    StaticTextSlopeSlash->SetBackgroundColour(wxColour(100,255,200));
    if(m_inputData->Roof_Type_No==7)
    {
        //show/hide required things
        lblWtNozzle->Hide();
        txtWeightNozzle->Hide();
        txtRequiredThickness->Hide();
        lblTHickness->Hide();
        lblMaterialRoof->Hide();
        txtMaterialRoof->Hide();
        lblRRoof->Hide();
        txtRRoof->Hide();
        lblFrangible->Hide();
        cmbFrangible->Hide();
        txtLiveLoad->Hide();
        lblLiveLoad->Hide();
        lblBalSL->Hide();
        txtBalancedSL->Hide();
        lblUnBalSL->Hide();
        txtUnBalancedSL->Hide();
        updateRoofSlope(false);
        lblJEff->Hide();
        cmbJointEff->Hide();

        lblTypeFR->SetPosition(wxPoint(32,100));
        lblWeightFR->SetPosition(wxPoint(32,140));
        cmbTypeFloatingRoof->SetPosition(wxPoint(200,100));
        txtWeightFloatingRoof->SetPosition(wxPoint(200,140));
    }
    else
    {
        //same
        lblTypeFR->SetPosition(wxPoint(624,336));
        lblWeightFR->SetPosition(wxPoint(624,376));
        cmbTypeFloatingRoof->SetPosition(wxPoint(784,336));
        txtWeightFloatingRoof->SetPosition(wxPoint(784,376));

        lblWtNozzle->Show();
        txtWeightNozzle->Show();
        lblTHickness->Show();
        txtRequiredThickness->Show();
        lblMaterialRoof->Show();
        txtMaterialRoof->Show();
        lblRRoof->Show();
        txtRRoof->Show();
        lblFrangible->Show();
        cmbFrangible->Show();
        txtLiveLoad->Show();
        lblLiveLoad->Show();
        lblBalSL->Show();
        txtBalancedSL->Show();
        txtUnBalancedSL->Show();
        lblUnBalSL->Show();
        updateRoofSlope(true);
        lblJEff->Show();
        cmbJointEff->Show();
    }
	if(m_inputData->Roof_Type_No<=6)
		txtCorrosionAllowanceFixedRoof->Enable();
	else
		txtCorrosionAllowanceFixedRoof->Disable();


    if(m_inputData->Roof_Type_No==2||m_inputData->Roof_Type_No==4||m_inputData->Roof_Type_No==6)
    {
        lblDomeRadius->Show();
        txtDomeRadius->Show();
        //m_inputData->roof_slope_user="";
        lblDomeRadius->SetLabelText("Dome Radius (M)*");

    }
    else if(m_inputData->Roof_Type_No==7)
    {
        lblDomeRadius->Show();
        txtDomeRadius->Show();
        lblDomeRadius->SetLabelText("Dome Radius of\nGeodesic Roof (M)*");
    }
    else
    {
        lblDomeRadius->Hide();
        txtDomeRadius->Hide();
    }

    if(m_inputData->Roof_Type_No==1||m_inputData->Roof_Type_No==3||m_inputData->Roof_Type_No==5)
    {
        lblSlopeRoof->Show();
        updateRoofSlope(true);
        //m_inputData->roof_slope_user="";
    }
    else
    {
        lblSlopeRoof->Hide();
        updateRoofSlope(false);
    }



    if(m_inputData->Roof_Type_No==3||m_inputData->Roof_Type_No==5)
    {
        lblMaxSpace->Show();
        txtMaxSpace1->Show();
    }
    else
    {
        lblMaxSpace->Hide();
        txtMaxSpace1->Hide();

    }

    if(m_inputData->Roof_Type_No==4||m_inputData->Roof_Type_No==6)
    {
        lblMaxSpacePeri->Show();
        txtMaxSpace2->Show();
    }

    else{
        lblMaxSpacePeri->Hide();
        txtMaxSpace2->Hide();
    }

    //FOR WEIGHT FLOATING ROOF
    if(m_inputData->FR_Type_No==4)
     {
         txtWeightFloatingRoof->Disable();
     }
     else
        txtWeightFloatingRoof->Enable();

   //FOR GEODESIC
    if(m_inputData->Roof_Type_No==3||m_inputData->Roof_Type_No==4||m_inputData->Roof_Type_No==5||m_inputData->Roof_Type_No==6)
    {
        lblWeightGeodesicRoof->Show();
        txtWtGeodesicRoof->Show();
        lblWeightGeodesicRoof->SetLabelText("Weight of Roof Structure (Kg)*");

        lblCorrWeight->Show();
        txtCorrWeight->Show();
    }
    else if(m_inputData->Roof_Type_No==7)
    {
        lblWeightGeodesicRoof->Show();
        txtWtGeodesicRoof->Show();
        lblWeightGeodesicRoof->SetLabelText("Weight of Geodesic Roof(Kg)*");

        lblCorrWeight->Hide();
        txtCorrWeight->Hide();
    }
    else
    {
        lblWeightGeodesicRoof->Hide();
        txtWtGeodesicRoof->Hide();

        lblCorrWeight->Hide();
        txtCorrWeight->Hide();
    }

    if(m_inputData->Roof_Type_No==3||m_inputData->Roof_Type_No==4)
    {
        lblPercWeight->Show();
        txtPercWeight->Show();
        StaticText6->Show();
    }
    else
    {
        lblPercWeight->Hide();
        txtPercWeight->Hide();
        StaticText6->Hide();
    }
}

void InputScreensDlg::updateRoofSlope(bool show)
{
    if(show)
    {
        txtSlopeDen->Show();
        txtSlopeNum->Show();
        StaticTextSlopeSlash->Show();
        Gauge1->Show();
    }
    else
    {
        txtSlopeDen->Hide();
        txtSlopeNum->Hide();
        StaticTextSlopeSlash->Hide();
        Gauge1->Hide();
    }
}

bool InputScreensDlg::validateRoofDataEntries()
{

    const double DOUBLE_ZERO = 0.0F;
    bool validationSuccess = true;

    if(DOUBLE_ZERO >= m_inputData->live_load_user
       && txtLiveLoad->GetValue().empty())
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_ROOF_DATA);
        wxMessageBox("Live Load is mandatory", "InputScreen_1 Validation");
        validationSuccess = false;
        txtLiveLoad->SetFocus();
    }

     else if(DOUBLE_ZERO >= m_inputData->snow_load_bal
       && txtBalancedSL->GetValue().empty())
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_ROOF_DATA);
        wxMessageBox("Balanced Design Snow Load is mandatory", "InputScreen_1 Validation");
        validationSuccess = false;
        txtBalancedSL->SetFocus();
    }
    else if(DOUBLE_ZERO >= m_inputData->snow_load_unbal
       && txtUnBalancedSL->GetValue().empty())
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_ROOF_DATA);
        wxMessageBox("Un-Balanced Design Snow Load is mandatory", "InputScreen_1 Validation");
        validationSuccess = false;
        txtUnBalancedSL->SetFocus();
    }

     else if(DOUBLE_ZERO >= m_inputData->dome_radius_user
       && txtDomeRadius->GetValue().empty()
        && (m_inputData->Roof_Type_No==2||m_inputData->Roof_Type_No==4||m_inputData->Roof_Type_No==6)    )
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_ROOF_DATA);
        wxMessageBox("Dome Radius is mandatory", "InputScreen_1 Validation");
        validationSuccess = false;
        txtUnBalancedSL->SetFocus();
    }

     else if((m_inputData->Roof_Type_No==1||m_inputData->Roof_Type_No==3||m_inputData->Roof_Type_No==5))
    {
        double temp;
        txtSlopeDen->GetValue().ToDouble(&temp);
        if((txtSlopeNum->GetValue().empty()||txtSlopeDen->GetValue().empty()))
        {
            changeActiveNotebookPage(ItemUIUtils::NB_PAGE_ROOF_DATA);
            wxMessageBox("Slope of is mandatory", "InputScreen_1 Validation");
            validationSuccess = false;
            txtSlopeNum->SetFocus();
        }
        //make sure denominator is not zero
        if(temp==0)
        {
            changeActiveNotebookPage(ItemUIUtils::NB_PAGE_ROOF_DATA);
            wxMessageBox("Denominator can't be zero", "Roof Data Validation");
            validationSuccess = false;
            txtSlopeDen->SetFocus();
        }

    }


     else if(DOUBLE_ZERO >= m_inputData->Wt_Roof_Str
       && txtWtGeodesicRoof->GetValue().empty())
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_ROOF_DATA);
        wxMessageBox("Weight of Roof structure is mandatory", "InputScreen_1 Validation");
        validationSuccess = false;
        txtWtGeodesicRoof->SetFocus();
    }


    else if(0 > cmbTypeFloatingRoof->GetSelection())
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_ROOF_DATA);
        wxMessageBox("Type of Floating Roof is mandatory", "InputScreen_1 Validation");
        validationSuccess = false;
        cmbTypeFloatingRoof->SetFocus();
    }




    else if(m_inputData->WeightAdder_roof_default == m_inputData->WeightAdder_roof_user
       && txtWeightNozzle->GetValue().empty())
    {
        changeActiveNotebookPage(ItemUIUtils::NB_PAGE_ROOF_DATA);
        wxMessageBox("Weight of roof nozzle is mandatory", "InputScreen_1 Validation");
        validationSuccess = false;
        txtWeightNozzle->SetFocus();
    }

    return validationSuccess;
}


bool InputScreensDlg::transferRoofDataWindowData()
{
    bool transferSuccess = false;
    if(txtRRoof->GetValidator()->TransferFromWindow()
       && txtLiveLoad->GetValidator()->TransferFromWindow()
       && txtBalancedSL->GetValidator()->TransferFromWindow()
       && txtUnBalancedSL->GetValidator()->TransferFromWindow()
       && txtWeightFloatingRoof->GetValidator()->TransferFromWindow()
       && txtWeightNozzle->GetValidator()->TransferFromWindow()
       && txtWtGeodesicRoof->GetValidator()->TransferFromWindow()
       && txtSlopeNum->GetValidator()->TransferFromWindow()
       && txtSlopeDen->GetValidator()->TransferFromWindow()
       )
    {
        transferSuccess = true;
    }
    if(transferSuccess)
    {
        if(m_inputData->Roof_Type_No==2||m_inputData->Roof_Type_No==4||m_inputData->Roof_Type_No==6)
        {
            if(!txtDomeRadius->GetValidator()->TransferFromWindow())
                transferSuccess=false;
        }
    }
    return transferSuccess;
}


void InputScreensDlg::OntxtRRoofKillFocus(wxFocusEvent& event)
{
    double roof = 0.0F;
    double R_Roof_default =  (m_inputData->D / 2 + (m_inputData->shell_detail[(m_inputData->No_of_ShellCourses - 1)][18] / 2000) + 0.012);
    txtRRoof->GetValue().ToDouble(&roof);
    if(m_inputData->R_Roof_user != roof)
    {
        if(roof>=((m_inputData->D / 2) - 0.012))
            m_inputData->R_Roof_user = roof;
        else
            m_inputData->R_Roof_user = R_Roof_default;
    }

    txtRRoof->ChangeValue(wxString().FromDouble(m_inputData->R_Roof_user,3));

    event.Skip();
}

void InputScreensDlg::OntxtLiveLoadKillFocus(wxFocusEvent& event)
{
    double liveload = 0.0F;
    txtLiveLoad->GetValue().ToDouble(&liveload);
    if(m_inputData->live_load_user != liveload)
    {
        if(liveload<0.72)
            m_inputData->live_load_user = 1.0;
        else
            m_inputData->live_load_user = liveload;
    }
    txtLiveLoad->ChangeValue(wxString().FromDouble(m_inputData->live_load_user,1));
    event.Skip();
}

void InputScreensDlg::OntxtDomeRadiusKillFocus(wxFocusEvent& event)
{
    double dr = 0.0F;
    txtDomeRadius->GetValue().ToDouble(&dr);

    if(m_inputData->dome_radius_user != dr)
    {
        if(dr>1.2*m_inputData->D)
            m_inputData->dome_radius_user = 1.2*m_inputData->D;
        else if(dr<0.8*m_inputData->D)
            m_inputData->dome_radius_user = 0.8*m_inputData->D;
        else
            m_inputData->dome_radius_user = dr;
    }
    txtDomeRadius->ChangeValue(wxString().FromDouble(m_inputData->dome_radius_user,2));
    event.Skip();
}

void InputScreensDlg::OntxtBalancedSLKillFocus(wxFocusEvent& event)
{
    double balanced = 0.0F;
    txtBalancedSL->GetValue().ToDouble(&balanced);
    if(m_inputData->snow_load_bal != balanced)
    {
        m_inputData->snow_load_bal = balanced;
    }
    event.Skip();
}

void InputScreensDlg::OntxtUnBalancedSLKillFocus(wxFocusEvent& event)
{
    double unbalanced = 0.0F;
    txtUnBalancedSL->GetValue().ToDouble(&unbalanced);
    if(m_inputData->snow_load_unbal != unbalanced)
    {
        m_inputData->snow_load_unbal = unbalanced;
    }
    event.Skip();
}

void InputScreensDlg::OntxtWeightFloatingRoofKillFocus(wxFocusEvent& event)
{
    double weightFR = 0.0F;
    txtWeightFloatingRoof->GetValue().ToDouble(&weightFR);
    if(m_inputData->Weight_FR != weightFR)
    {
        m_inputData->Weight_FR = weightFR;
        m_inputData->Weight_FR_user = weightFR;
    }
    event.Skip();
}

void InputScreensDlg::OntxtWeightNozzleKillFocus(wxFocusEvent& event)
{
    double weightN = 0.0F;
    txtWeightNozzle->GetValue().ToDouble(&weightN);
    if(m_inputData->WeightAdder_roof != weightN)
    {
        m_inputData->WeightAdder_roof = weightN;
        m_inputData->WeightAdder_roof_user = weightN;
    }
    event.Skip();
}


void InputScreensDlg::OntxtWtGeodesicRoofKillFocus(wxFocusEvent& event)
{
    double weightG= 0.0F;
    txtWtGeodesicRoof->GetValue().ToDouble(&weightG);
    if(m_inputData->Wt_Roof_Str != weightG)
    {
        m_inputData->Wt_Roof_Str = weightG;
        m_inputData->Wt_Roof_Str_user = weightG;
    }
    event.Skip();
}
//TODO
//Add for cmbJointEff.  Variable not known now.

void InputScreensDlg::OnPanel1Paint(wxPaintEvent& event)
{
}


void InputScreensDlg::OncmbTypeFloatingRoofSelect1(wxCommandEvent& event)
{
     m_inputData->FR_Type_No = cmbTypeFloatingRoof->GetSelection()+1;
     if(m_inputData->FR_Type_No==4)
     {
         txtWeightFloatingRoof->Disable();
     }
     else
        txtWeightFloatingRoof->Enable();

    ReadVariables(*m_inputData);
    weight_cal();
    PopulateVariables(*m_inputData);
    txtWeightFloatingRoof->ChangeValue(wxString().FromDouble(m_inputData->Weight_FR,2));
    m_inputData->Weight_FR_user = m_inputData->Weight_FR;
}

void InputScreensDlg::OncmbFrangibleSelect2(wxCommandEvent& event)
{
    m_inputData->option_frangible_roof = cmbFrangible->GetSelection();
}

void InputScreensDlg::OntxtMaterialRoofLeftDClick(wxMouseEvent& event)
{
    MaterialSelection materialSelectDlg(this);
    materialSelectDlg.SetLayoutAdaptationMode(wxDIALOG_ADAPTATION_MODE_ENABLED);
    materialSelectDlg.SetInitialValues(m_inputData->Shell_Appendx_No_user);
    materialSelectDlg.ShowModal();

    unsigned int temp = materialSelectDlg.GetSelectedMaterialSerialNumber();
    txtMaterialRoof->ChangeValue(materialSelectDlg.radioBoxMaterial->GetString(materialSelectDlg.materialNumberToIndex(temp)));
    m_inputData->Roof_Material_No = temp;
}


bool InputScreensDlg::is_fraction1(std::string str)
{
    std::size_t a = str.find("/");
    if(a==-1||a==(str.size()-1))
        return false;
    std::string before, after;
    before = str.substr(0, a);
    after = str.substr(a+1);

    for(size_t i=0;i<before.size();i++)
    {
        if(!isdigit(before[i]))
            return false;

    }


    for(size_t i=0;i<after.size();i++)
    {
        if(!isdigit(after[i]))
            return false;
    }

    m_inputData->roof_slope_user_numerator = wxAtoi(before);
    m_inputData->roof_slope_user_denominator = wxAtoi(after);

    return true;

}


void InputScreensDlg::OntxtSlopeNumKillFocus(wxFocusEvent& event)
{
    int temp;
    temp = wxAtoi(txtSlopeNum->GetValue());
    m_inputData->roof_slope_user_numerator = temp;
    if(m_inputData->roof_slope_user_denominator>0)
    {
        updateRoofSlopeValues();
    }
    event.Skip();
}

void InputScreensDlg::OntxtSlopeDenKillFocus(wxFocusEvent& event)
{
    int temp;
    temp = wxAtoi(txtSlopeDen->GetValue());
    if(temp>0)
    {
        m_inputData->roof_slope_user_denominator = temp;
        if(m_inputData->roof_slope_user_numerator>0)
            updateRoofSlopeValues();
    }
    else
        txtSlopeDen->ChangeValue(wxString::Format("%d",m_inputData->roof_slope_user_denominator));
    event.Skip();
}

void InputScreensDlg::updateRoofSlopeValues()
{
    if(m_inputData->Roof_Type_No==1)
    {
        double roof_slope_user = (double)m_inputData->roof_slope_user_numerator/(double)m_inputData->roof_slope_user_denominator;

        if(roof_slope_user<0.166667){
            m_inputData->roof_slope_user = 0.166667;
            m_inputData->roof_slope_user_numerator=2;
            m_inputData->roof_slope_user_denominator=12;
        }
        else if(roof_slope_user>0.75){
            m_inputData->roof_slope_user = 0.75;
            m_inputData->roof_slope_user_numerator=9;
            m_inputData->roof_slope_user_denominator=12;
        }
        else
            m_inputData->roof_slope_user = roof_slope_user;
    }
    else if(m_inputData->Roof_Type_No==3 || m_inputData->Roof_Type_No==5)
    {
        double roof_slope_user = (double)m_inputData->roof_slope_user_numerator/(double)m_inputData->roof_slope_user_denominator;
        if(roof_slope_user<0.0625){
            m_inputData->roof_slope_user = 0.0625;
            m_inputData->roof_slope_user_numerator=1;
            m_inputData->roof_slope_user_denominator=16;
        }
    }
    txtSlopeNum->ChangeValue(wxString::Format("%d",m_inputData->roof_slope_user_numerator));
    txtSlopeDen->ChangeValue(wxString::Format("%d",m_inputData->roof_slope_user_denominator));

}

//-----------------------ROOF TO SHELL SCREEN-----------------------------------

void InputScreensDlg::setupRoofToShellValidators()
{
    wxFloatingPointValidator<double> validatorDoubleTBar(2, &(m_inputData->t_bar[1]), wxNUM_VAL_ZERO_AS_BLANK);
    txtTBar->SetValidator(validatorDoubleTBar);
    wxFloatingPointValidator<double> validatorDoubleWBar(2, &(m_inputData->w_bar[1]), wxNUM_VAL_ZERO_AS_BLANK);
    txtWBar->SetValidator(validatorDoubleWBar);
    wxFloatingPointValidator<double> validatorDoubleLBar(2, &(m_inputData->l_bar[1]), wxNUM_VAL_ZERO_AS_BLANK);
    txtLBar->SetValidator(validatorDoubleLBar);
    wxFloatingPointValidator<double> validatorDoubleTShell(2, &(m_inputData->t_shell[1]), wxNUM_VAL_ZERO_AS_BLANK);
    txtTShell->SetValidator(validatorDoubleTShell);
    wxFloatingPointValidator<double> validatorDoubleWShell(2, &(m_inputData->w_shell[1]), wxNUM_VAL_ZERO_AS_BLANK);
    txtWShell->SetValidator(validatorDoubleWShell);

}

void InputScreensDlg::setRoofToShellInitialControlValues()
{
    const int FLOAT_VALUE_PRECISION = 2;

    //txtGustDesignWindSpeed->ChangeValue(wxString().FromDouble(m_inputData->basic_v_user, FLOAT_VALUE_PRECISION));

    cmbTypeCR->SetSelection(0);

    //txtGustFactor->ChangeValue(wxString().FromDouble(m_inputData->gust_factor_user, FLOAT_VALUE_PRECISION));
   // txtDesignWindVel->ChangeValue("");
    txtTBar->ChangeValue("");
    txtWBar->ChangeValue("");
    txtLBar->ChangeValue("");
    txtTShell->ChangeValue("");
    txtWShell->ChangeValue("");
    updateVisibleFieldsRoofToShellUser(1);
    if(!m_isNewData)
    {
        cmbTypeCR->SetSelection(m_inputData->CR_Type_No[1] - 1);
        MaterialSelection materialSelectDlg(this);
        AngleSelection angleSelectDlg(this);
        if(m_inputData->CR_Material_No[0]>0&&m_inputData->CR_Material_No[0]<130)
        txtCRMaterial0->ChangeValue(materialSelectDlg.radioBoxMaterial->GetString(materialSelectDlg.materialNumberToIndex(m_inputData->CR_Material_No[0])));
        if(m_inputData->CR_Material_No[1]>0&&m_inputData->CR_Material_No[1]<130)
        txtCRMaterial1->ChangeValue(materialSelectDlg.radioBoxMaterial->GetString(materialSelectDlg.materialNumberToIndex(m_inputData->CR_Material_No[1])));
        if(m_inputData->CR_Material_No[2]>0&&m_inputData->CR_Material_No[2]<130)
        txtCRMaterial2->ChangeValue(materialSelectDlg.radioBoxMaterial->GetString(materialSelectDlg.materialNumberToIndex(m_inputData->CR_Material_No[2])));
        if(m_inputData->CR_Size[2]>0&&m_inputData->CR_Size[2]<76)
        txtCRSize2->ChangeValue(angleSelectDlg.radioBoxAngle->GetString(m_inputData->CR_Size[2]-1));
        if(m_inputData->CR_Size[1]>0&&m_inputData->CR_Size[1]<76)
        txtCRSize1->ChangeValue(angleSelectDlg.radioBoxAngle->GetString(m_inputData->CR_Size[1]-1));

        txtTBar->ChangeValue(wxString().FromDouble(m_inputData->t_bar[1], FLOAT_VALUE_PRECISION));
        txtWBar->ChangeValue(wxString().FromDouble(m_inputData->w_bar[1], FLOAT_VALUE_PRECISION));
        txtLBar->ChangeValue(wxString().FromDouble(m_inputData->t_bar[1], FLOAT_VALUE_PRECISION));
        txtTShell->ChangeValue(wxString().FromDouble(m_inputData->t_shell[1], FLOAT_VALUE_PRECISION));
        txtWShell->ChangeValue(wxString().FromDouble(m_inputData->w_shell[1], FLOAT_VALUE_PRECISION));
        updateVisibleFieldsRoofToShellUser(m_inputData->CR_Type_No[1]);
    }
}

void InputScreensDlg::setRoofToShellInitialControlStates()
{

}

bool InputScreensDlg::validateRoofToShellEntries()
{
    //const double DOUBLE_ZERO = 0.0F;
    bool validationSuccess = true;
    return validationSuccess;

}

bool InputScreensDlg::transferRoofToShellWindowData()
{

    //make it false
    bool transferSuccess = true;
    if(txtTBar->GetValidator()->TransferFromWindow()
       && txtWBar->GetValidator()->TransferFromWindow()
       && txtLBar->GetValidator()->TransferFromWindow()
       && txtTShell->GetValidator()->TransferFromWindow()
       && txtWShell->GetValidator()->TransferFromWindow())
    {
        transferSuccess = true;
    }

    return transferSuccess;
}

void InputScreensDlg::OncmbTypeCRSelect(wxCommandEvent& event)
{

    m_inputData->CR_Type_No[1] = cmbTypeCR->GetSelection()+1;
    m_inputData->CR_Type_No[0] = cmbTypeCR->GetSelection()+1;
    updateVisibleFieldsRoofToShellUser(m_inputData->CR_Type_No[1]);
    delete(StaticBitmap);
    wxString image_num = wxString::Format(wxT("%d"), (int)m_inputData->CR_Type_No[1]);
    StaticBitmap = new wxStaticBitmap(this, ID_STATICBITMAP, wxBitmap(wxImage(_T("Images/"+image_num+".PNG"),wxBITMAP_TYPE_PNG)), wxPoint(300,430),wxSize(270,200));

}

void InputScreensDlg::OntxtCRMaterial0LeftDClick(wxMouseEvent& event)
{
    MaterialSelection materialSelectDlg(this);
    materialSelectDlg.SetLayoutAdaptationMode(wxDIALOG_ADAPTATION_MODE_ENABLED);
    materialSelectDlg.SetInitialValues(m_inputData->Shell_Appendx_No_user);
    materialSelectDlg.ShowModal();

    unsigned int temp = materialSelectDlg.GetSelectedMaterialSerialNumber();
    std::cout<<"now material number "<<temp<<std::endl;

    txtCRMaterial0->ChangeValue(materialSelectDlg.radioBoxMaterial->GetString(materialSelectDlg.materialNumberToIndex(temp)));
    m_inputData->CR_Material_No[0] = temp;
}

void InputScreensDlg::OntxtCRMaterial2LeftDClick(wxMouseEvent& event)
{
    MaterialSelection materialSelectDlg(this);
    materialSelectDlg.setIndextoNumber();
    materialSelectDlg.SetLayoutAdaptationMode(wxDIALOG_ADAPTATION_MODE_ENABLED);
    materialSelectDlg.SetInitialValues(m_inputData->Shell_Appendx_No_user);
    materialSelectDlg.ShowModal();

    unsigned int temp = materialSelectDlg.GetSelectedMaterialSerialNumber();
    txtCRMaterial2->ChangeValue(materialSelectDlg.radioBoxMaterial->GetString(materialSelectDlg.materialNumberToIndex(temp)));
    m_inputData->CR_Material_No[2] = temp;
}
void InputScreensDlg::OntxtCRMaterial1LeftDClick(wxMouseEvent& event)
{
    MaterialSelection materialSelectDlg(this);
    materialSelectDlg.SetLayoutAdaptationMode(wxDIALOG_ADAPTATION_MODE_ENABLED);
    materialSelectDlg.SetInitialValues(m_inputData->Shell_Appendx_No_user);
    materialSelectDlg.ShowModal();

    unsigned int temp = materialSelectDlg.GetSelectedMaterialSerialNumber();
    txtCRMaterial1->ChangeValue(materialSelectDlg.radioBoxMaterial->GetString(materialSelectDlg.materialNumberToIndex(temp)));
    m_inputData->CR_Material_No[1] = temp;
}

void InputScreensDlg::OntxtCRSize1LeftDClick(wxMouseEvent& event)
{
    AngleSelection angleSelectDlg(this);
    angleSelectDlg.SetLayoutAdaptationMode(wxDIALOG_ADAPTATION_MODE_ENABLED);
    angleSelectDlg.ShowModal();

    unsigned int temp = angleSelectDlg.GetSelectedAngleNumber();
    std::cout<<"angle temp "<<temp<<std::endl;
    if(temp<1||temp>73)
        temp=1;
    txtCRSize1->ChangeValue(angleSelectDlg.radioBoxAngle->GetString(temp-1));
    m_inputData->CR_Size[1] = temp;
}

void InputScreensDlg::OntxtCRSize2LeftDClick(wxMouseEvent& event)
{
     AngleSelection angleSelectDlg(this);
    angleSelectDlg.SetLayoutAdaptationMode(wxDIALOG_ADAPTATION_MODE_ENABLED);
    angleSelectDlg.ShowModal();

    unsigned int temp = angleSelectDlg.GetSelectedAngleNumber();
   // std::cout<<"angle temp "<<temp<<std::endl;
    if(temp<1||temp>73)
        temp=1;
    txtCRSize2->ChangeValue(angleSelectDlg.radioBoxAngle->GetString(temp-1));
    m_inputData->CR_Size[2] = temp;

}


void InputScreensDlg::OntxtTBarKillFocus(wxFocusEvent& event)
{
    double tb = 0.0F;
    txtTBar->GetValue().ToDouble(&tb);
    if(m_inputData->t_bar[1] != tb)
    {
        m_inputData->t_bar[1] = tb;
    }

    event.Skip();
}

void InputScreensDlg::OntxtWBarKillFocus(wxFocusEvent& event)
{
    double tb = 0.0F;
    txtWBar->GetValue().ToDouble(&tb);
    if(m_inputData->w_bar[1] != tb)
    {
        m_inputData->w_bar[1] = tb;
    }

    event.Skip();
}

void InputScreensDlg::OntxtLBarKillFocus(wxFocusEvent& event)
{
    double tb = 0.0F;
    txtLBar->GetValue().ToDouble(&tb);
    if(m_inputData->l_bar[1] != tb)
    {
        m_inputData->l_bar[1] = tb;
    }

    event.Skip();
}

void InputScreensDlg::OntxtTShellKillFocus(wxFocusEvent& event)
{
    double tb = 0.0F;
    txtTShell->GetValue().ToDouble(&tb);
    if(m_inputData->t_shell[1] != tb)
    {
        m_inputData->t_shell[1] = tb;
    }

    event.Skip();
}

void InputScreensDlg::OntxtWShellKillFocus(wxFocusEvent& event)
{
    double tb = 0.0F;
    txtWShell->GetValue().ToDouble(&tb);
    if(m_inputData->w_shell[1] != tb)
    {
        m_inputData->w_shell[1] = tb;
    }

    event.Skip();
}


void InputScreensDlg::updateVisibleFieldsRoofToShellUser(int selection)
{
    if(selection==1 || selection==2 || selection==3 || selection==4 || selection==5 || selection==6 )
    {
        lblUser1->Show();
        lblUser2->Hide();
        lblUser3->Hide();
        lblUser4->Hide();
        txtCRSize1->Show();
        txtCRSize2->Hide();
        txtTBar->Hide();
        txtWBar->Hide();
        txtLBar->Hide();
        txtTShell->Hide();
        txtWShell->Hide();
        lblThickness->Hide();
        lblWidth->Hide();
        lblProj->Hide();
        txtCRMaterial0->Show();
        txtCRMaterial2->Hide();
        txtCRMaterial1->Hide();

    }

    else if(selection == 7)
    {
        lblUser1->Show();
        lblUser2->Show();
        lblUser3->Hide();
        lblUser4->Hide();
        txtCRSize1->Show();
        txtCRSize2->Show();
        txtTBar->Hide();
        txtWBar->Hide();
        txtLBar->Hide();
        txtTShell->Hide();
        txtWShell->Hide();
        lblThickness->Hide();
        lblWidth->Hide();
        txtCRMaterial0->Show();
        txtCRMaterial2->Hide();
        txtCRMaterial1->Hide();


    }

    else if(selection == 8)
    {
        lblUser1->Hide();
        lblUser2->Hide();
        lblUser3->Show();
        lblUser4->Hide();
        txtCRSize1->Hide();
        txtCRSize2->Hide();
        txtTBar->Show();
        txtWBar->Show();
        txtLBar->Hide();
        txtTShell->Hide();
        txtWShell->Hide();
        lblThickness->Show();
        lblWidth->Show();
        lblProj->Hide();
        txtCRMaterial0->Hide();
        txtCRMaterial2->Show();
        txtCRMaterial1->Hide();
        lblUser3->SetLabel("Thickness & Width of Bar welded to shell.  mm");
    }

    else if(selection == 9)
    {
        lblUser1->Hide();
        lblUser2->Hide();
        lblUser3->Show();
        lblUser4->Hide();
        txtCRSize1->Hide();
        txtCRSize2->Hide();
        txtTBar->Show();
        txtWBar->Show();
        txtLBar->Show();
        txtTShell->Hide();
        txtWShell->Hide();
        lblThickness->Show();
        lblWidth->Show();
        lblProj->Show();
        txtCRMaterial0->Hide();
        txtCRMaterial2->Show();
        txtCRMaterial1->Hide();
        lblUser3->SetLabel("Thickness & Width of Thicker Roof. mm");
    }

    else{
        lblUser1->Hide();
        lblUser2->Hide();
        lblUser3->Show();
        lblUser4->Show();
        txtCRSize1->Hide();
        txtCRSize2->Hide();
        txtTBar->Show();
        txtWBar->Show();
        txtLBar->Hide();
        txtTShell->Show();
        txtWShell->Show();
        lblThickness->Show();
        lblWidth->Show();
        lblProj->Hide();
        txtCRMaterial0->Hide();
        txtCRMaterial2->Show();
        txtCRMaterial1->Show();
        lblUser3->SetLabel("Thickness & Width of Bar welded to shell mm");
        lblUser4->SetLabel("Thickness & Width of Thicker Shell at top mm");

    }


}


//TODO : call this function when the "run" button on roof to shell screen checks whether the input cofig is acceptable or not.

void InputScreensDlg::updateVisibleFieldsRoofToShellUserAD(int selection)
{
    if(selection==1 || selection==2 || selection==3 || selection==4 || selection==5 || selection==6 )
    {
        lblUser1AD->Show();
        lblUser2AD->Hide();
        lblUser3AD->Hide();
        lblUser4AD->Hide();
        txtCRSize1AD->Show();
        txtCRSize2AD->Hide();
        txtTBarAD->Hide();
        txtWBarAD->Hide();
        txtLBarAD->Hide();
        txtTShellAD->Hide();
        txtWShellAD->Hide();
        lblThicknessAD->Hide();
        lblWidthAD->Hide();
        lblProjAD->Hide();

    }

    else if(selection == 7)
    {
        lblUser1AD->Show();
        lblUser2AD->Show();
        lblUser3AD->Hide();
        lblUser4AD->Hide();
        txtCRSize1AD->Show();
        txtCRSize2AD->Show();
        txtTBarAD->Hide();
        txtWBarAD->Hide();
        txtLBarAD->Hide();
        txtTShellAD->Hide();
        txtWShellAD->Hide();
        lblThicknessAD->Hide();
        lblWidthAD->Hide();


    }

    else if(selection == 8)
    {
        lblUser1AD->Hide();
        lblUser2AD->Hide();
        lblUser3AD->Show();
        lblUser4AD->Hide();
        txtCRSize1AD->Hide();
        txtCRSize2AD->Hide();
        txtTBarAD->Show();
        txtWBarAD->Show();
        txtLBarAD->Hide();
        txtTShellAD->Hide();
        txtWShellAD->Hide();
        lblThicknessAD->Show();
        lblWidthAD->Show();
        lblProjAD->Hide();
        lblUser3AD->SetLabel("Thickness & Width of Bar welded to shell.  mm");
    }

    else if(selection == 9)
    {
        lblUser1AD->Hide();
        lblUser2AD->Hide();
        lblUser3AD->Show();
        lblUser4AD->Hide();
        txtCRSize1AD->Hide();
        txtCRSize2AD->Hide();
        txtTBarAD->Show();
        txtWBarAD->Show();
        txtLBarAD->Show();
        txtTShellAD->Hide();
        txtWShellAD->Hide();
        lblThicknessAD->Show();
        lblWidthAD->Show();
        lblProjAD->Show();
        lblUser3AD->SetLabel("Thickness & Width of Thicker Roof. mm");
    }

    else{
        lblUser1AD->Hide();
        lblUser2AD->Hide();
        lblUser3AD->Show();
        lblUser4AD->Show();
        txtCRSize1AD->Hide();
        txtCRSize2AD->Hide();
        txtTBarAD->Show();
        txtWBarAD->Show();
        txtLBarAD->Hide();
        txtTShellAD->Show();
        txtWShellAD->Show();
        lblThicknessAD->Show();
        lblWidthAD->Show();
        lblProjAD->Hide();
        lblUser3AD->SetLabel("Thickness & Width of Bar welded to shell mm");
        lblUser4AD->SetLabel("Thickness & Width of Thicker Shell at top mm");

    }


}


//IGNORE THESE FOR NOW

void InputScreensDlg::OnTextCtrl1Text(wxCommandEvent& event)
{
}
void InputScreensDlg::OntxtDiaTankText(wxCommandEvent& event)
{
}



void InputScreensDlg::OntxtMaterialRoofLeftClick(wxCommandEvent& event)
{

}


void InputScreensDlg::OnpnlRoofDataPaint(wxPaintEvent& event)
{
}




void InputScreensDlg::OntxtCrossSecInternalPressureAvailText(wxCommandEvent& event)
{
}

void InputScreensDlg::OntxtCRMaterial0Text(wxCommandEvent& event)
{
}

void InputScreensDlg::OntxtCRMaterial2Text(wxCommandEvent& event)
{
}

void InputScreensDlg::setStiffenerElevationInitialControlValues()
{
	// The values for the grid cells will be dealt with later, once user_EL_detail[][] is defined

    for(int rowIndex = 0; rowIndex < GridStiffenerElevation->GetNumberRows(); ++rowIndex)
    {
        GridStiffenerElevation->SetCellValue(rowIndex, 0, wxString::Format("%d", rowIndex+1) );
    }

    // These values are supposed to be some fixed values. Can be initialised with some fixed value later on.
    TextHeightTransShell->ChangeValue(wxString().FromDouble(m_inputData->H_Ts, 2));
    TextT_uniform->ChangeValue(wxString().FromDouble(m_inputData->t_uniform, 2));
    TextHMaxWind->ChangeValue(wxString().FromDouble(m_inputData->H_Max_W, 2));
    TextHMaxPressure->ChangeValue(wxString().FromDouble(m_inputData->H_Max_Ps, 2));
    TextNumStiff->ChangeValue(wxString::Format("%d",m_inputData->No_of_Stiffeners_R));

    if(m_inputData->No_of_Stiffeners_Max_user>0)
        TextNumStiffMax->ChangeValue(wxString::Format("%d",m_inputData->No_of_Stiffeners_Max_user));
    else
        TextNumStiffMax->ChangeValue(wxString("20"));


   	for(int j=0;j<m_inputData->No_of_Stiffeners_R;j++)
	{
		GridStiffenerElevation->SetCellValue(j, 1, wxString::Format("%.3f", m_inputData->user_EL_detail[j][6]));
		GridStiffenerElevation->SetCellValue(j, 2, wxString::Format("%.3f", m_inputData->user_EL_detail[j][4]));
		GridStiffenerElevation->SetCellValue(j, 3, wxString::Format("%.3f", m_inputData->user_EL_detail[j][2]));
		GridStiffenerElevation->SetCellValue(j, 4, wxString::Format("%.3f", m_inputData->user_EL_detail[j][8]));
        GridStiffenerElevation->SetCellValue(j, 5, wxString::Format("%.3f", m_inputData->user_EL_detail[j][10]));
		GridStiffenerElevation->SetCellValue(j, 6, wxString::Format("%.3f", m_inputData->user_EL_detail[j][9]));
		GridStiffenerElevation->SetCellValue(j, 7, wxString::Format("%.3f", m_inputData->stfr_detail[j][16]));
		GridStiffenerElevation->SetCellValue(j, 8, wxString::Format("%.3f", m_inputData->stfr_detail[j][14]));
		GridStiffenerElevation->SetCellValue(j, 9, wxString::Format("%.3f", m_inputData->stfr_detail[j][15]));
        GridStiffenerElevation->SetCellValue(j, 11, wxString::Format("RUN"));
	}
    for(int j=m_inputData->No_of_Stiffeners_R;j<GridStiffenerElevation->GetNumberRows();j++)
	{
		GridStiffenerElevation->SetCellValue(j, 1, wxString(""));
		GridStiffenerElevation->SetCellValue(j, 2, wxString(""));
		GridStiffenerElevation->SetCellValue(j, 3, wxString(""));
		GridStiffenerElevation->SetCellValue(j, 4, wxString(""));
        GridStiffenerElevation->SetCellValue(j, 5, wxString(""));
		GridStiffenerElevation->SetCellValue(j, 6, wxString(""));
		GridStiffenerElevation->SetCellValue(j, 7, wxString(""));
		GridStiffenerElevation->SetCellValue(j, 8, wxString(""));
		GridStiffenerElevation->SetCellValue(j, 9, wxString(""));
        GridStiffenerElevation->SetCellValue(j, 11, wxString(""));
	}
}

void InputScreensDlg::setStiffenerElevationControlStates(bool label)
{
    // Create grid for labels
    if(label==true)
	{
        GridStiffenerElevationLabel->CreateGrid(2,12);
        GridStiffenerElevationLabel->HideRowLabels();
        GridStiffenerElevationLabel->HideColLabels();
        GridStiffenerElevationLabel->SetDefaultColSize(110, true);
        GridStiffenerElevationLabel->SetCellSize(1,0,1,8);
        GridStiffenerElevationLabel->SetCellSize(1,8,1,3);
        GridStiffenerElevationLabel->SetCellValue(0,0, _("Sl.No of\nStiffener\n(n)"));
        GridStiffenerElevationLabel->SetCellValue(0,1, _("Elevation of\nStiffener on\nactual shell\n(M)"));
        GridStiffenerElevationLabel->SetCellValue(0,2, _("Highest\npossible\nelevation\n(M)"));
        GridStiffenerElevationLabel->SetCellValue(0,3, _("Lowest\npossible\nelevation\n(M)"));
        GridStiffenerElevationLabel->SetCellValue(0,4, _("User defined\nelevation\n(M)"));
        GridStiffenerElevationLabel->SetCellValue(0,5, _("Spacing between\nthe stiffener\nand the shell\nseam below\n(M)"));
        GridStiffenerElevationLabel->SetCellValue(0,6, _("Spacing between\nthe stiffener\nand the shell\nseam above\n(M)"));
        GridStiffenerElevationLabel->SetCellValue(0,7, _("Adopted\nElevation\n(M)"));
        GridStiffenerElevationLabel->SetCellValue(0,8, _("Elevation of\nStiffener on\nTransposed shell\n(M)"));
        GridStiffenerElevationLabel->SetCellValue(0,9, _("Height of\nun-stiffened\nshell above\n the stiffener\n(M)"));
        GridStiffenerElevationLabel->SetCellValue(0,10, _("Material of\nstiffener\nring"));
        GridStiffenerElevationLabel->SetCellValue(0, 11, _("        "));

        GridStiffenerElevationLabel->SetCellValue(1, 0, _("On Actual Shell"));
        GridStiffenerElevationLabel->SetCellValue(1, 8, _("On Transposed Shell"));

        wxFont font(10,wxFONTFAMILY_MODERN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD);
        GridStiffenerElevationLabel->ShowScrollbars(wxSHOW_SB_NEVER,wxSHOW_SB_NEVER);
        for(int i=0;i<12;i++)
        {
            GridStiffenerElevationLabel->SetCellFont(0,i,font);
            GridStiffenerElevationLabel->SetCellAlignment(0,i,wxALIGN_CENTER,wxALIGN_TOP);
            GridStiffenerElevationLabel->SetCellBackgroundColour(0, i, wxColour(225,225,225));
            GridStiffenerElevationLabel->SetCellBackgroundColour(1, i, wxColour("LIGHT GREY"));
        }

        GridStiffenerElevationLabel->SetCellFont(1,0,font);
        GridStiffenerElevationLabel->SetCellFont(1,8,font);
        GridStiffenerElevationLabel->SetCellAlignment(1,0,wxALIGN_CENTER,wxALIGN_TOP);
        GridStiffenerElevationLabel->SetCellAlignment(1,8,wxALIGN_CENTER,wxALIGN_TOP);

        GridStiffenerElevationLabel->AutoSizeRows();
        GridStiffenerElevationLabel->AutoSizeColumns();

        int n,colWidths=0;
        n = GridStiffenerElevationLabel->GetNumberCols();
        for (int i = 0; i < n - 1; i++)
            colWidths += GridStiffenerElevationLabel->GetColSize (i);

        int finalColWidth = GridStiffenerElevationLabel->GetSize().x - colWidths;
        GridStiffenerElevationLabel->SetColSize (n - 1, finalColWidth);

        for(int rowIndex = 0; rowIndex < GridStiffenerElevationLabel->GetNumberRows(); ++rowIndex)
        {
            for(int colIndex = 0; colIndex < GridStiffenerElevationLabel->GetNumberCols(); ++colIndex)
            {
                GridStiffenerElevationLabel->SetReadOnly(rowIndex, colIndex, true);
            }
        }
    }

	int num_rows = max(5,m_inputData->No_of_Stiffeners_R);

    if(num_rows != GridStiffenerElevation->GetNumberRows())
	{
        delete GridStiffenerElevation;
        GridStiffenerElevation = new wxGrid(pnlStiffenerElevation, ID_GRID2, wxPoint(50,478), wxSize(1220,150), wxSIMPLE_BORDER, _T("ID_GRID2"));

        GridStiffenerElevation->CreateGrid(num_rows,12);
        GridStiffenerElevation->EnableEditing(true);
        GridStiffenerElevation->EnableGridLines(true);
        GridStiffenerElevation->SetColLabelSize(30);
        GridStiffenerElevation->SetDefaultRowSize(30, true);
        GridStiffenerElevation->SetDefaultColSize(100, true);

        GridStiffenerElevation->SetDefaultCellFont( GridStiffenerElevation->GetFont() );
        GridStiffenerElevation->SetDefaultCellTextColour( GridStiffenerElevation->GetForegroundColour() );

        GridStiffenerElevation->HideRowLabels();
        GridStiffenerElevation->HideColLabels();

        for(int i=0;i<12;i++)
        {
            GridStiffenerElevation->SetColSize(i,GridStiffenerElevationLabel->GetColSize(i));
        }
        GridStiffenerElevation->SetColSize(10,GridStiffenerElevationLabel->GetColSize(10)-18);
        for(int rowIndex = 0; rowIndex < GridStiffenerElevation->GetNumberRows(); ++rowIndex)
        {
            for(int colIndex = 0; colIndex < GridStiffenerElevation->GetNumberCols(); ++colIndex)
            {
                GridStiffenerElevation->SetReadOnly(rowIndex, colIndex, true);
                if(colIndex!=4&&colIndex!=10)
                    GridStiffenerElevation->SetCellBackgroundColour(rowIndex, colIndex, wxColour("LIGHT GREY"));
                else
                    GridStiffenerElevation->SetCellBackgroundColour(rowIndex, colIndex, wxColour("PINK"));

            }
        }
        GridStiffenerElevation->SetGridLineColour(wxColour("BLACK"));
        GridStiffenerElevationLabel->SetGridLineColour(wxColour("BLACK"));
        for(int rowIndex = 0; rowIndex < GridStiffenerElevation->GetNumberRows(); ++rowIndex)
        {
            GridStiffenerElevation->SetReadOnly(rowIndex, 4, false);
            GridStiffenerElevation->SetReadOnly(rowIndex, 10, false);
        }

        GridStiffenerElevation->ShowScrollbars(wxSHOW_SB_NEVER,wxSHOW_SB_ALWAYS);
    }

}

void InputScreensDlg::setupStiffenerElevationValidators()
{
	wxIntegerValidator<int> validatorNumStiffMax(&(m_inputData->No_of_Stiffeners_Max_user));
    TextNumStiffMax->SetValidator(validatorNumStiffMax);

    wxGridCellTextEditor* *editor1 = new wxGridCellTextEditor*[GridStiffenerElevation->GetNumberRows()-1];
    wxGridCellTextEditor* *editor2 = new wxGridCellTextEditor*[GridStiffenerElevation->GetNumberRows()-1];
    // These arrays will be replaced by the array from the design file
    double x[GridStiffenerElevation->GetNumberRows()-1];
    double y[GridStiffenerElevation->GetNumberRows()-1];

    for(int i=0;i<GridStiffenerElevation->GetNumberRows(); i++)
    {
    	editor1[i-1] = new wxGridCellTextEditor;
    	editor2[i-1] = new wxGridCellTextEditor;
        wxFloatingPointValidator<double> validatorCells1(3,&x[i-1]);
        wxFloatingPointValidator<double> validatorCells2(3,&y[i-1]);
        editor1[i-1]->SetValidator(validatorCells1);
        editor2[i-1]->SetValidator(validatorCells2);
        GridStiffenerElevation->SetCellEditor(i,4,editor1[i-1]);
        GridStiffenerElevation->SetCellEditor(i,10,editor2[i-1]);
    }
}

void InputScreensDlg::OntxtNumStiffMaxKillFocus(wxFocusEvent& event)
{
    int NumStiffMax = 0;
    wxString temp = TextNumStiffMax->GetValue();
    NumStiffMax = wxAtoi(temp);

    if(m_inputData->No_of_Stiffeners_Max_user != NumStiffMax)
    {
        m_inputData->No_of_Stiffeners_Max_user = NumStiffMax;
    }
    // InitVariables();
    ReadVariables(*m_inputData);
    Input_Screen_1();
    Wind_Data();
    call_test_tu_min();
    // Seismic_Data();
    shell_Design();

    if (m_inputData->Roof_Type_No > 6)
    {    PWG_Data();
    }
    else
        shell_Stiffener_Location();

    shell_Stfr_User_EL();

    PopulateVariables(*m_inputData);

    // ReadVariables(*m_inputData);
    // shell_Stfr_User_EL_Data();
    // PopulateVariables(*m_inputData);
    setStiffenerElevationControlStates();
    setStiffenerElevationInitialControlValues();
    event.Skip();
}

void InputScreensDlg::OntxtSpaceTopWGTopTankKillFocus(wxFocusEvent& event)
{
    double SpaceTopWGTopTank = 0.0F;
    txtSpaceTopWGTopTank->GetValue().ToDouble(&SpaceTopWGTopTank);

    if (SpaceTopWGTopTank < 0.5) SpaceTopWGTopTank = 1.1;   //  to be taken from "Form For Primary Wind Girder Design".

    if(m_inputData->Spacing_Top_WG_User != SpaceTopWGTopTank)
        m_inputData->Spacing_Top_WG_User = SpaceTopWGTopTank;

    event.Skip();
}

void InputScreensDlg::OncmblSizeTopAngleSelect(wxCommandEvent& event)
{
	m_inputData->curb_angle_No_user = cmblSizeTopAngle->GetSelection()+1;
	double angle_section_width[7] = {65, 65, 65, 75, 75, 75, 90 };
	double PWG_width_min_default = 710+angle_section_width[m_inputData->curb_angle_No_user-1];
	txtMinWidthTopWGAsWalkway->SetValue(wxString::Format("%.2f",PWG_width_min_default));
	m_inputData->PWG_width_min_user=PWG_width_min_default;
}

void InputScreensDlg::OntxtMinWidthTopWGAsWalkwayKillFocus(wxFocusEvent& event)
{
    double angle_section_width[7] = {65, 65, 65, 75, 75, 75, 90 };
	double PWG_width_min_default = 710+angle_section_width[m_inputData->curb_angle_No_user-1];
    double MinWidth = 0.0F;
    txtMinWidthTopWGAsWalkway->GetValue().ToDouble(&MinWidth);
    if(MinWidth > PWG_width_min_default)
    {
        m_inputData->PWG_width_min_user = MinWidth;
    }
    else
    {
        m_inputData->PWG_width_min_user=PWG_width_min_default;
        txtMinWidthTopWGAsWalkway->SetValue(wxString::Format("%.2f",PWG_width_min_default));

    }

    event.Skip();
}



void InputScreensDlg::OnGridStiffenerElevationCellLeftClick(wxGridEvent& event)
{
     if(event.GetCol() == 10)// && event.GetRow() != gridShellDesign->GetNumberRows() - 1 && event.GetRow()<m_inputData->No_of_ShellCourses)
    {
        MaterialSelection materialSelectDlg(this);
        materialSelectDlg.SetLayoutAdaptationMode(wxDIALOG_ADAPTATION_MODE_ENABLED);
        materialSelectDlg.SetInitialValues(m_inputData->Shell_Appendx_No_user);

        materialSelectDlg.ShowModal();
        unsigned int temp = materialSelectDlg.GetSelectedMaterialSerialNumber();
    	GridStiffenerElevation->SetCellValue(event.GetRow(),event.GetCol(),materialSelectDlg.radioBoxMaterial->GetString(materialSelectDlg.materialNumberToIndex(temp)));
        //TODO: Save it in appropriate variable
        m_inputData->stfr_Mat_No[event.GetRow()] = temp;
        // stfr_Mat_No[event.GetRow()] = temp;
        ReadVariables(*m_inputData);
        shell_Stfr_User_EL();
        PopulateVariables(*m_inputData);

    }
    else if(event.GetCol() == 11)
    {
        double ele = 0.0F;
        int n = event.GetRow();
	    GridStiffenerElevation->GetCellValue(n,4).ToDouble(&ele);
        m_inputData->user_EL_detail[n][8] = ele;
        // user_EL_detail[n][8] = ele;

        if (((int)(m_inputData->user_EL_detail[n][8]*1000.) > (int)(m_inputData->user_EL_detail[n][4]*1000.) || ((int)(m_inputData->user_EL_detail[n][8]*1000.) < (int)(m_inputData->user_EL_detail[n][2]*1000.)))&&m_inputData->user_EL_detail[n][8] > 0.16)
        {
                cout<<endl;
                cout<<m_inputData->user_EL_detail[n][8]*1000<<" "<<m_inputData->user_EL_detail[n][4]*1000<<" "<<m_inputData->user_EL_detail[n][2]*1000<<endl;
                //TODO: Can be improved
                wxMessageBox("User defined elevation is not within the specified range. Revise the elevation of siffener.", "Information");
                event.Skip();
                return;
                // GridStiffenerElevation->SetCellValue(n,4,"");
        }
        else
        {
            ReadVariables(*m_inputData);
            shell_Stfr_User_EL();
            PopulateVariables(*m_inputData);
            // m_inputData->user_EL_detail[n][9] = user_EL_detail[n][9];
            // m_inputData->user_EL_detail[n][10] = user_EL_detail[n][10];
            GridStiffenerElevation->SetCellValue(n,5,wxString::Format("%.3f", m_inputData->user_EL_detail[n][10]));
            GridStiffenerElevation->SetCellValue(n,6,wxString::Format("%.3f", m_inputData->user_EL_detail[n][9]));

            if ((m_inputData->user_EL_detail[n][9] < m_inputData->Spacing_Min) || (m_inputData->user_EL_detail[n][10] < m_inputData->Spacing_Min))
            {
                wxMessageBox("The Spacing between the Proposed Elevation of stiffener and a shell joint is less than permissible. Revise the elevation of siffener", "Information");
                // GridStiffenerElevation->SetCellValue(n,4,"");
                event.Skip();
                return;
            }
            // m_inputData->stfr_detail[n][16] = stfr_detail[n][16];
            GridStiffenerElevation->SetCellValue(n, 7, wxString::Format("%.3f", m_inputData->stfr_detail[n][16]));
            setStiffenerElevationControlStates();
            setStiffenerElevationInitialControlValues();
        }
    }
    event.Skip();
}

void InputScreensDlg::setStiffenerSizeControlStates(bool label)
{
    //create grid of labels
    if(label==true)
    {
        GridStiffenerSizeLabel1->CreateGrid(2,11);
        GridStiffenerSizeLabel1->HideRowLabels();
        GridStiffenerSizeLabel1->HideColLabels();
        GridStiffenerSizeLabel1->SetDefaultColSize(110, true);
        GridStiffenerSizeLabel1->SetCellSize(0,2,1,4);
        GridStiffenerSizeLabel1->SetCellSize(0,0,2,1);
        GridStiffenerSizeLabel1->SetCellSize(0,1,2,1);
        GridStiffenerSizeLabel1->SetCellSize(0,6,2,1);
        GridStiffenerSizeLabel1->SetCellSize(0,7,2,1);
        GridStiffenerSizeLabel1->SetCellSize(0,8,2,1);
        GridStiffenerSizeLabel1->SetCellSize(0,9,2,1);
        GridStiffenerSizeLabel1->SetCellSize(0,10,2,1);
        GridStiffenerSizeLabel1->SetCellValue(0,0, _("Stiffener\nserial\nnumber"));
        GridStiffenerSizeLabel1->SetCellValue(0,1, _("Type of\nstiffener"));
        GridStiffenerSizeLabel1->SetCellValue(0,2, _("Size of Built-up Section of Built-up Stiffener\nor Size of angle for Angle Type Stiffener"));
        GridStiffenerSizeLabel1->SetCellValue(0,6, _("Status\n(Available/\nRequired)"));
        GridStiffenerSizeLabel1->SetCellValue(0,7, _("Section Modulus\n(Cub. CM)"));
        GridStiffenerSizeLabel1->SetCellValue(0,8, _("C.S Area of\nRing alone\n(Sq. CM)"));
        GridStiffenerSizeLabel1->SetCellValue(0,9, _("C.S Area of\nStiffener\nassembly\n(Sq. CM)"));
        GridStiffenerSizeLabel1->SetCellValue(0,10, _("   MOI   \n(CM^4)"));
        GridStiffenerSizeLabel1->SetCellValue(1,2, _("Width of\nWeb\n(mm)"));
        GridStiffenerSizeLabel1->SetCellValue(1,3, _("Thickness of\nWeb\n(mm)"));
        GridStiffenerSizeLabel1->SetCellValue(1,4, _("Width of\nFlange\n(mm)"));
        GridStiffenerSizeLabel1->SetCellValue(1,5, _("Thickness of\nFlange\n(mm)"));

        wxFont font(10,wxFONTFAMILY_MODERN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD);
        GridStiffenerSizeLabel1->ShowScrollbars(wxSHOW_SB_NEVER,wxSHOW_SB_NEVER);

        for(int i=0;i<11;i++)
        {
            GridStiffenerSizeLabel1->SetCellFont(0,i,font);
            GridStiffenerSizeLabel1->SetCellAlignment(0,i,wxALIGN_CENTER,wxALIGN_TOP);
            GridStiffenerSizeLabel1->SetCellBackgroundColour(0, i, wxColour(225,225,225));

            GridStiffenerSizeLabel1->SetCellFont(1,i,font);
            GridStiffenerSizeLabel1->SetCellAlignment(1,i,wxALIGN_CENTER,wxALIGN_TOP);
            GridStiffenerSizeLabel1->SetCellBackgroundColour(1, i, wxColour(225,225,225));

        }

        GridStiffenerSizeLabel1->AutoSizeRows();
        GridStiffenerSizeLabel1->AutoSizeColumns();
        GridStiffenerSizeLabel1->SetColSize(6,0);

        for(int rowIndex = 0; rowIndex < GridStiffenerSizeLabel1->GetNumberRows(); ++rowIndex)
        {
            for(int colIndex = 0; colIndex < GridStiffenerSizeLabel1->GetNumberCols(); ++colIndex)
            {
                GridStiffenerSizeLabel1->SetReadOnly(rowIndex, colIndex, true);
            }
        }
    }

	// m_inputData->No_of_Stiffeners_R = 5;
	int num_rows = m_inputData->No_of_Stiffeners_R*3;
    if(num_rows!=GridStiffenerSize->GetNumberRows())
    {
        delete GridStiffenerSize;
        GridStiffenerSize = new wxGrid(Panel1, ID_GRID5, wxPoint(0,95), wxSize(988,370), wxSIMPLE_BORDER, _T("ID_GRID5"));
        GridStiffenerSize->CreateGrid(num_rows,11);
        GridStiffenerSize->EnableEditing(true);
        GridStiffenerSize->EnableGridLines(true);
        GridStiffenerSize->SetDefaultCellAlignment(wxALIGN_CENTER,wxALIGN_CENTER);
        GridStiffenerSize->SetDefaultRowSize(30,true);
        GridStiffenerSize->HideRowLabels();
        GridStiffenerSize->HideColLabels();
        GridStiffenerSize->ShowScrollbars(wxSHOW_SB_NEVER,wxSHOW_SB_ALWAYS);
        for(int i=0;i<GridStiffenerSize->GetNumberCols();i++)
        {
            GridStiffenerSize->SetColSize(i,GridStiffenerSizeLabel1->GetColSize(i));
        }
        if(m_inputData->No_of_Stiffeners_R>4)
            GridStiffenerSize->SetColSize(GridStiffenerSize->GetNumberCols()-1,GridStiffenerSizeLabel1->GetColSize(GridStiffenerSize->GetNumberCols()-1)-18);
        for(int rowIndex = 0; rowIndex < GridStiffenerSize->GetNumberRows(); ++rowIndex)
        {
            for(int colIndex = 0; colIndex < GridStiffenerSize->GetNumberCols(); ++colIndex)
            {
                GridStiffenerSize->SetReadOnly(rowIndex, colIndex, true);
                if(rowIndex%3==0)
                    GridStiffenerSize->SetCellBackgroundColour(rowIndex, colIndex, wxColour(135,200,235));
                if(rowIndex%3==2||(colIndex>5&&rowIndex%3!=0) || colIndex<1)
                    GridStiffenerSize->SetCellBackgroundColour(rowIndex, colIndex, wxColour("LIGHT GREY"));
                else if(rowIndex%3==1)
                    GridStiffenerSize->SetCellBackgroundColour(rowIndex, colIndex, wxColour("PINK"));
            }
        }

        for(int i = 0;i<m_inputData->No_of_Stiffeners_R;i++)
        {
            for(int j = 1;j<6;j++)
                GridStiffenerSize->SetReadOnly(i*3+1,j, false);
        }
        wxString choices[2] = {wxT("ANGLE"),wxT("BUILT UP")};
        for(int rowIndex = 0; rowIndex < GridStiffenerSize->GetNumberRows(); rowIndex+=3)
        {
            GridStiffenerSize->SetCellSize(rowIndex,0,3,1);
            GridStiffenerSize->SetCellSize(rowIndex,1,1,5);
            GridStiffenerSize->SetCellValue(rowIndex,1,wxString("Required Properties of Stiffener Ring -------->"));
            GridStiffenerSize->SetCellEditor(rowIndex+1,1,new wxGridCellChoiceEditor(2, choices, false));
            // GridStiffenerSize->GetCellEditor(rowIndex+2,1)->Disable();
        }
        GridStiffenerSize->EnableGridLines(true);
        GridStiffenerSize->SetGridLineColour(wxColour("BLACK"));
        GridStiffenerSizeLabel1->SetGridLineColour(wxColour("BLACK"));
    }
}

void InputScreensDlg::setStiffenerSizeInitialControlValues()
{
    //TODO: something different needed for new data
	AngleSelection angleSelectDlg(this);
    //cout<<"stiffener details\n";
    for(int rowIndex = 0; rowIndex < m_inputData->No_of_Stiffeners_R; ++rowIndex)
    {
        //cout<<rowIndex<<" "<<m_inputData->stfr_detail_user[rowIndex][1]<<endl;
        GridStiffenerSize->SetCellValue(rowIndex*3, 0, wxString::Format("%d", rowIndex+1) );
        if(m_inputData->stfr_detail_user[rowIndex][1]==0)
        {
        	GridStiffenerSize->SetCellValue(rowIndex*3+1, 1, "ANGLE" );
            GridStiffenerSize->SetCellValue(rowIndex*3+1, 2,angleSelectDlg.radioBoxAngle->GetString(m_inputData->stfr_Sec_No[rowIndex][1]-1));
            GridStiffenerSize->SetCellSize(rowIndex*3+1, 2,1,4);
        }
        else
        {
            GridStiffenerSize->SetCellValue(rowIndex*3+1, 1, "BUILT UP" );
            GridStiffenerSize->SetCellValue(rowIndex*3+1, 2, wxString::Format("%.2f",m_inputData->stfr_Prop_user[rowIndex][0]));
            GridStiffenerSize->SetCellValue(rowIndex*3+1, 3, wxString::Format("%.2f",m_inputData->stfr_Prop_user[rowIndex][1]));
            GridStiffenerSize->SetCellValue(rowIndex*3+1, 4, wxString::Format("%.2f",m_inputData->stfr_Prop_user[rowIndex][2]));
            GridStiffenerSize->SetCellValue(rowIndex*3+1, 5, wxString::Format("%.2f",m_inputData->stfr_Prop_user[rowIndex][3]));
            GridStiffenerSize->SetCellSize(rowIndex*3+1, 2,1,1);
        }

        //check for adopted type
        if(m_inputData->stfr_detail[rowIndex][65]==0)
        {
            GridStiffenerSize->SetCellValue(rowIndex*3+2, 1, "ANGLE");
            GridStiffenerSize->SetCellSize(rowIndex*3+2, 2,1,4);
            GridStiffenerSize->SetCellValue(rowIndex*3+2, 2, angleSelectDlg.radioBoxAngle->GetString(m_inputData->stfr_Sec_No[rowIndex][2]-1));
            cout<<rowIndex<<" "<<m_inputData->stfr_Sec_No[rowIndex][2]<<endl;
        }
        else
        {
            GridStiffenerSize->SetCellValue(rowIndex*3+2, 1, "BUILT UP");
            GridStiffenerSize->SetCellSize(rowIndex*3+2, 2,1,1);
            GridStiffenerSize->SetCellValue(rowIndex*3+2, 2, wxString::Format("%.2f",m_inputData->stfr_detail[rowIndex][70]));
            GridStiffenerSize->SetCellValue(rowIndex*3+2, 3, wxString::Format("%.2f",m_inputData->stfr_detail[rowIndex][71]));
            GridStiffenerSize->SetCellValue(rowIndex*3+2, 4, wxString::Format("%.2f",m_inputData->stfr_detail[rowIndex][72]));
            GridStiffenerSize->SetCellValue(rowIndex*3+2, 5, wxString::Format("%.2f",m_inputData->stfr_detail[rowIndex][73]));

            // GridStiffenerSize->SetCellValue(rowIndex*3+2, 7, wxString::Format("%.2f", m_inputData->stfr_detail[rowIndex][77]));
            // GridStiffenerSize->SetCellValue(rowIndex*3+2, 8, wxString::Format("%.2f", m_inputData->stfr_detail[rowIndex][69]) );
            // GridStiffenerSize->SetCellValue(rowIndex*3+2, 9, wxString::Format("%.2f", m_inputData->stfr_detail[rowIndex][75]) );
            // GridStiffenerSize->SetCellValue(rowIndex*3+2, 10, wxString::Format("%.2f", m_inputData->stfr_detail[rowIndex][76]) );

        }

        GridStiffenerSize->SetCellValue(rowIndex*3, 7, wxString::Format("%.2f", m_inputData->stfr_detail[rowIndex][23]));
        GridStiffenerSize->SetCellValue(rowIndex*3, 8, wxString::Format("%.2f", m_inputData->stfr_detail[rowIndex][34]) );
        GridStiffenerSize->SetCellValue(rowIndex*3, 9, wxString::Format("%.2f", m_inputData->stfr_detail[rowIndex][30]) );
        GridStiffenerSize->SetCellValue(rowIndex*3, 10, wxString::Format("%.2f", m_inputData->stfr_detail[rowIndex][29]) );

        GridStiffenerSize->SetCellValue(rowIndex*3+1, 7, wxString::Format("%.2f", m_inputData->stfr_detail[rowIndex][62]));
        GridStiffenerSize->SetCellValue(rowIndex*3+1, 8, wxString::Format("%.2f", m_inputData->stfr_detail[rowIndex][54]) );
        GridStiffenerSize->SetCellValue(rowIndex*3+1, 9, wxString::Format("%.2f", m_inputData->stfr_detail[rowIndex][60]) );
        GridStiffenerSize->SetCellValue(rowIndex*3+1, 10, wxString::Format("%.2f", m_inputData->stfr_detail[rowIndex][61]) );

        GridStiffenerSize->SetCellValue(rowIndex*3+2, 7, wxString::Format("%.2f", m_inputData->stfr_detail[rowIndex][77]));
        GridStiffenerSize->SetCellValue(rowIndex*3+2, 8, wxString::Format("%.2f", m_inputData->stfr_detail[rowIndex][69]) );
        GridStiffenerSize->SetCellValue(rowIndex*3+2, 9, wxString::Format("%.2f", m_inputData->stfr_detail[rowIndex][75]) );
        GridStiffenerSize->SetCellValue(rowIndex*3+2, 10, wxString::Format("%.2f", m_inputData->stfr_detail[rowIndex][76]) );

    }

    // for(int rowIndex = 0; rowIndex < GridStiffenerSize->GetNumberRows(); ++rowIndex)
    // {
    //     if(rowIndex%3 == 1)
    //     {
    //         wxString temp;
    //         temp = GridStiffenerSize->GetCellValue(rowIndex,1);
    //         if(temp=="BUILT UP")
    //         {
    //             int i = rowIndex/3;
    //             for(int colIndex = 2; colIndex < 6; ++colIndex)
    //             {
    //                 GridStiffenerSize->SetCellValue(rowIndex,colIndex,wxString::Format("%.2f",m_inputData->stfr_Prop_user[i][colIndex-2]));
    //             }
    //         }
    //     }
    //     else if(rowIndex%3==2)
    //     {
    //         int i = rowIndex/3;
    //         if(m_inputData->stfr_detail[i][50]==1)
    //         {
    //             for(int colIndex = 2; colIndex < 6; ++colIndex)
    //             {
    //                 GridStiffenerSize->SetCellValue(rowIndex,colIndex,wxString::Format("%.2f",m_inputData->stfr_Prop_user[i][colIndex+68]));
    //             }
    //         }
    //         else
    //         {
    //             GridStiffenerSize->SetCellSize(rowIndex,2,1,4);
    //             GridStiffenerSize->SetCellValue(rowIndex, 2,angleSelectDlg.radioBoxAngle->GetString(max(m_inputData->stfr_Sec_No[i][2]-1,0)));

    //         }
    //     }
    // }
}


void InputScreensDlg::OnGridStiffenerSizeCellLeftClick(wxGridEvent& event)
{
    if(event.GetCol() == 1 && event.GetRow()%3 == 1)
    {
        GridStiffenerSize->SetGridCursor(event.GetRow(), event.GetCol());
        GridStiffenerSize->EnableCellEditControl(true);
        GridStiffenerSize->ShowCellEditControl();
        GridStiffenerSize->HideCellEditControl();
        GridStiffenerSize->EnableCellEditControl(false);
    }
    else if(event.GetCol() == 2 && event.GetRow()%3 == 1 && m_inputData->stfr_detail_user[event.GetRow()/3][1]==0)
    {
    	AngleSelection AngleSelectDlg(this);
        AngleSelectDlg.SetLayoutAdaptationMode(wxDIALOG_ADAPTATION_MODE_ENABLED);
        //cerr<<(int)m_inputData->stfr_Sec_No[event.GetRow()/3][1]<<"BT";
        int angle_num = (int)m_inputData->stfr_Sec_No[event.GetRow()/3][1];
        cout<<"Angle number: "<<(int)m_inputData->stfr_Sec_No[event.GetRow()/3][1];
        if(angle_num>=1&&angle_num<=73)
            AngleSelectDlg.SetInitialValues(angle_num-1);
        else
            AngleSelectDlg.SetInitialValues(0);
        AngleSelectDlg.ShowModal();

        wxString type = AngleSelectDlg.GetSelectedAngleDesc();
        int num = AngleSelectDlg.GetSelectedAngleNumber();
        m_inputData->stfr_Sec_No[event.GetRow()/3][1] = num;
        GridStiffenerSize->SetCellValue(wxGridCellCoords(event.GetRow(), event.GetCol()),type);
        cout<<"selected angle"<<m_inputData->stfr_Sec_No[event.GetRow()/3][1]<<endl;
    }

    event.Skip();
    cout<<"coming out";
}

void InputScreensDlg::setupStiffenerSizeValidators()
{
    //TODO: Change x by actual array
    double x[m_inputData->No_of_Stiffeners_R][4];
    wxGridCellTextEditor* *editor = new wxGridCellTextEditor*[m_inputData->No_of_Stiffeners_R*4];

    wxString choices[2] = {wxT("ANGLE"),wxT("BUILT UP")};
    for(int i=0;i<m_inputData->No_of_Stiffeners_R;i++)
    {
        for(int j=2;j<6;j++)
        {
            editor[i*4+j-2] = new wxGridCellTextEditor;
            wxFloatingPointValidator<double> validatorCellStiffenerSize(2,&x[i][j-2]);
            editor[i*4+j-2]->SetValidator(validatorCellStiffenerSize);
            GridStiffenerSize->SetCellEditor(i*3+1,j,editor[i*4+j-2]);
        }

    }

}

void InputScreensDlg::OnCalcFaFvBtnClick(wxCommandEvent& event)
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


	m = m_inputData->site_class;

	if (m_inputData->Ss_user >= Fa_Data[0][5])
	{
		m_inputData->Fa_default = Fa_Data[m][5];
	}
	else
	{
		for (i = 0; i <= 4; i++)
		{


			if ((m_inputData->Ss_user > Fa_Data[0][i]) && (m_inputData->Ss_user <= Fa_Data[0][(i + 1)]))
			{
				j = i;
			}


		}


		Ss_low = Fa_Data[0][j];
		Ss_high = Fa_Data[0][(j + 1)];
		Fa_low = Fa_Data[m][j];
		Fa_high = Fa_Data[m][(j + 1)];
		m_inputData->Fa_default = Fa_low - ((Fa_low - Fa_high) * (m_inputData->Ss_user - Ss_low) / (Ss_high - Ss_low));

	}



	// Calculation of Fv.


	if (m_inputData->S1_user >= Fv_Data[0][5])
		m_inputData->Fv_default = Fv_Data[m][5];

	else
	{


		for (i = 0; i <= 4; i++)
		{


			if ((m_inputData->S1_user > Fv_Data[0][i]) && (m_inputData->S1_user <= Fv_Data[0][(i + 1)]))
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

		m_inputData->Fv_default = Fv_low - ((Fv_low - Fv_high) * (m_inputData->S1_user - S1_low) / (S1_high - S1_low));

	}

    txtAccelBaseSiteCoeff->SetValue(wxString::Format("%.2f",m_inputData->Fa_default));
    txtVelBasedSiteCoeff->SetValue(wxString::Format("%.2f",m_inputData->Fv_default));

    m_inputData->Fa_user = m_inputData->Fa_default;
    m_inputData->Fv_user = m_inputData->Fv_default;

    m_inputData->Sds = m_inputData->Factor_Q * m_inputData->Fa_user * m_inputData->Ss_user;
    txtSDSQFaSs->ChangeValue(wxString().FromDouble(m_inputData->Sds, 4));

    m_inputData->Sd1 = m_inputData->Factor_Q * m_inputData->Fv_user * m_inputData->S1_user;
    txtSD1QFvS1->ChangeValue(wxString().FromDouble(m_inputData->Sd1, 4));// cout<<"llok at Sd1 "<<m_inputData->Sd1<<endl;
}



void InputScreensDlg::OnGrid1CellLeftClick1(wxGridEvent& event)
{
    event.Skip();
}

void InputScreensDlg::OnRunPWGClick1(wxCommandEvent& event)
{
    for(int i=0;i<4;i++)
    {
        double temp;
        Gridpwg->GetCellValue(1,i).ToDouble(&temp);
        m_inputData->PWG_details[i+6] = temp;
    }
    cout<<endl;
    m_inputData->PWG_Width_Web_User = m_inputData->PWG_details[6];
    m_inputData->PWG_Thick_Web = m_inputData->PWG_details[7];
    m_inputData->PWG_Height_Flange = m_inputData->PWG_details[8];
    m_inputData->PWG_Thick_Flange = m_inputData->PWG_details[9];
	//call pwg_properties function
    ReadVariables(*m_inputData);
    PWG_Data();
    PopulateVariables(*m_inputData);
	//setting new values
    TextSectionModRqd->ChangeValue(wxString().FromDouble(m_inputData->PWG_details[0],2));
    TextMOIRqd->ChangeValue(wxString().FromDouble(m_inputData->PWG_details[16],2));

	for(int i=0;i<3;i++)
    {
    	for(int j=0;j<5;j++)
    	{
    		Gridpwg->SetCellValue(i,j,wxString().FromDouble(m_inputData->PWG_details[i*5+j+1],2));
    	}
        Gridpwg->SetCellValue(i,5,wxString().FromDouble(m_inputData->PWG_details[i+17],2));
    }

    Gridpwg->SetCellValue(1,0,wxString().FromDouble(m_inputData->PWG_Width_Web_User,2));
    Gridpwg->SetCellValue(1,1,wxString().FromDouble(m_inputData->PWG_Thick_Web,2));
    Gridpwg->SetCellValue(1,2,wxString().FromDouble(m_inputData->PWG_Height_Flange,2));
    Gridpwg->SetCellValue(1,3,wxString().FromDouble(m_inputData->PWG_Thick_Flange,2));

    event.Skip();
}

void InputScreensDlg::OngridShellDesignLabelCellLeftClick(wxGridEvent& event)
{
}

void InputScreensDlg::OnButtonRunStiffenerElevationClick(wxCommandEvent& event)
{
    double ele = 0.0F;
    for(int n = 0;n<m_inputData->No_of_Stiffeners_R;n++)
    {
        GridStiffenerElevation->GetCellValue(n,4).ToDouble(&ele);
        m_inputData->user_EL_detail[n][8] = ele;
        ReadVariables(*m_inputData);
        shell_Stfr_User_EL();
        PopulateVariables(*m_inputData);
    }
    setStiffenerElevationControlStates();
    setStiffenerElevationInitialControlValues();
    event.Skip();
}

void InputScreensDlg::OnButtonRunStiffenerSizeClick(wxCommandEvent& event)
{
    for(int rowIndex = 0; rowIndex < GridStiffenerSize->GetNumberRows(); ++rowIndex)
    {
        if(rowIndex%3 == 1)
        {
            wxString temp;
            temp = GridStiffenerSize->GetCellValue(rowIndex,1);

            if(temp=="BUILT UP")
            {
                //cout<<temp<<endl;
                int i = rowIndex/3;
                for(int colIndex = 2; colIndex < 6; ++colIndex)
                {
                    double t;
                    GridStiffenerSize->GetCellValue(rowIndex,colIndex).ToDouble(&t);
                    m_inputData->stfr_Prop_user[i][colIndex-2]=t;
                    //cout<<"val "<<m_inputData->stfr_Prop_user[i][colIndex-2]<<endl;
                }
            }
        }
    }
    //edit_option = 1;
    ReadVariables(*m_inputData);
    Stiffener_Prop_User_Data();
    PopulateVariables(*m_inputData);
    //cout<<"\nfirst stfr section "<<m_inputData->stfr_Sec_No[0][1]<<" "<<m_inputData->stfr_Sec_No[0][2]<<endl;
    setStiffenerSizeInitialControlValues();
}

void InputScreensDlg::OnButtonDesignClick(wxCommandEvent& event)
{
    if(transferDataFromWindowData())// && validateEntries())
    {
        Close();
        //this->SetEscapeID(wxID_DESIGN);
    }
}

void InputScreensDlg::OnCmbRoundUpToSelect(wxCommandEvent& event)
{
    m_inputData->RoundUP_to = CmbRoundUpTo->GetSelection();
}

void InputScreensDlg::OncmbOptionStfrSelect(wxCommandEvent& event)
{
    m_inputData->option_Stfr = cmbOptionStfr->GetSelection();
    // call_test_tu_min();
}

void InputScreensDlg::OnGridtestCellLeftClick(wxGridEvent& event)
{
}


void InputScreensDlg::OnGridStiffenerSizeCellChanged(wxGridEvent& event)
{
    if(event.GetCol()==1&&event.GetRow()%3==1)
    {
        int type_number = GridStiffenerSize->GetCellValue(event.GetRow(),event.GetCol())==wxT("ANGLE")?0:1;
        m_inputData->stfr_detail_user[event.GetRow()/3][1] = type_number;

        if(type_number<0.5)
        {
            GridStiffenerSize->SetCellSize(event.GetRow(), 2,1,4);
            AngleSelection AngleSelectDlg(this);
            GridStiffenerSize->SetCellValue(event.GetRow(), 2,AngleSelectDlg.radioBoxAngle->GetString(m_inputData->stfr_Sec_No[event.GetRow()/3-1][1]));
        }
        else
        {
            int i = event.GetRow();
            GridStiffenerSize->SetCellSize(i, 2,1,1);
            GridStiffenerSize->SetCellValue(i, 2,wxString::Format("%.2f",m_inputData->stfr_Prop_user[i/3][0]));
            GridStiffenerSize->SetCellValue(i, 3,wxString::Format("%.2f",m_inputData->stfr_Prop_user[i/3][1]));
            GridStiffenerSize->SetCellValue(i, 4,wxString::Format("%.2f",m_inputData->stfr_Prop_user[i/3][2]));
            GridStiffenerSize->SetCellValue(i, 5,wxString::Format("%.2f",m_inputData->stfr_Prop_user[i/3][3]));
        }
    }
}

void InputScreensDlg::OnGrid1CellChanged(wxGridEvent& event)
{
}

void InputScreensDlg::OnChoice1Select(wxCommandEvent& event)
{
    int temp = cmbJointEff->GetSelection();
    m_inputData->JE_roof_user = temp;
    event.Skip();
}

void InputScreensDlg::OntxtRequiredThicknessKillFocus(wxFocusEvent& event)
{
    double thickness = 0.0F;
    txtRequiredThickness->GetValue().ToDouble(&thickness);
    m_inputData->Roof_Thk[7] = thickness;
    if(thickness>m_inputData->Roof_Thk[8])
    {
        m_inputData->Roof_Thk[8]=thickness;
    }
    else
    {
        txtRequiredThickness->ChangeValue(wxString().FromDouble(m_inputData->Roof_Thk[8],2));
    }
    event.Skip();
}

void InputScreensDlg::OnButtonGenReportClick(wxCommandEvent& event)
{
    InitVariables();
    ReadVariables(*m_inputData);
    Input_Screen_1();
	Wind_Data();
	Seismic_Data();
	shell_Details();
	if (m_inputData->Roof_Type_No > 6)
	{
		PWG_Data();
	}
	else
		shell_Stiffener_Location();

	shell_Stfr_User_EL_Data();
	shell_Stfr_User_EL();
	shell_Stiffener_Properties();
	Stiffener_Prop_User_Data();

	if (m_inputData->Roof_Type_No != 8)
		Roof_Data();

	// CompRing_Data();
	//CompRing_Design();
    weight_cal();
    // generateReport(resultFileName);
    print(resultFileName);
    wxMessageBox("Report generated "+resultFileName+"Result.txt","Info");
    event.Skip();
}

void InputScreensDlg::OncmbJointEffcncyShellVertSeamsSelect(wxCommandEvent& event)
{
    int sel = cmbJointEffcncyShellVertSeams->GetSelection();
    double eff_arr[3] = {0.7,0.85,1.0};
    m_inputData->JE_user = eff_arr[sel];
    event.Skip();
}


void InputScreensDlg::OntxtCorrWeightKillFocus(wxFocusEvent& event)
{
    double temp;
    txtCorrWeight->GetValue().ToDouble(&temp);
    m_inputData->Wt_Roof_Str_cor = temp;
    event.Skip();
}


void InputScreensDlg::OntxtPercWeightKillFocus(wxFocusEvent& event)
{
    double temp;
    txtPercWeight->GetValue().ToDouble(&temp);
    m_inputData->fraction_roof_weight = temp/100.0;
    event.Skip();
}

void InputScreensDlg::OntxtSlopeNumText(wxCommandEvent& event)
{
}

void InputScreensDlg::OntxtSlopeDenText(wxCommandEvent& event)
{
}

void InputScreensDlg::setRoofDataDefaultValues()
{
    double R_Roof_default =  (m_inputData->D / 2 + (m_inputData->shell_detail[(m_inputData->No_of_ShellCourses - 1)][18] / 2000) + 0.012);
    if(m_inputData->R_Roof_user==0.0){
        txtRRoof->ChangeValue(wxString::Format("%.3f",R_Roof_default));
        m_inputData->R_Roof_user = R_Roof_default;
    }

    if(m_inputData->Roof_Type_No==1)
    {
        if(m_inputData->roof_slope_user_numerator==0||m_inputData->roof_slope_user_denominator==0){
            txtSlopeNum->ChangeValue(wxString::Format("%d",2));
            txtSlopeDen->ChangeValue(wxString::Format("%d",12));
            m_inputData->roof_slope_user_numerator=2;
            m_inputData->roof_slope_user_denominator=12;
        }
    }
    else if(m_inputData->Roof_Type_No==3 || m_inputData->Roof_Type_No==5)
    {
        if(m_inputData->roof_slope_user_numerator==0||m_inputData->roof_slope_user_denominator==0){
            txtSlopeNum->ChangeValue(wxString::Format("%d",1));
            txtSlopeDen->ChangeValue(wxString::Format("%d",12));
            m_inputData->roof_slope_user_numerator=1;
            m_inputData->roof_slope_user_denominator=12;
        }
    }
    else if(m_inputData->Roof_Type_No==2 || m_inputData->Roof_Type_No==4 || m_inputData->Roof_Type_No==6){
        if(m_inputData->dome_radius_user==0)
            txtDomeRadius->ChangeValue(wxString().FromDouble(1.2*m_inputData->D,2));
    }
}

//roofdata
void InputScreensDlg::OnButton1Click1(wxCommandEvent& event)
{
    transferRoofDataWindowData();
    ReadVariables(*m_inputData);
    Roof_Data();
    PopulateVariables(*m_inputData);
    setRoofDataInitialControlStates();
    setRoofDataInitialControlValues();
}
