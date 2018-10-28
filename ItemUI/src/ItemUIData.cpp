#include "../include/ItemUIData.h"

#include <fstream>

int diameterMappingFromUI[2] = {2, 1};
int diameterMappingToUI[3] = {-1, 1, 0};

int shellAppendixNoMappingFromUI[6] = {1, 2, 3, 4, 5, 7};
int shellAppendixNoMappingToUI[8] = {-1, 0, 1, 2, 3, 4, -1, 5};

int shellCalcMethodMappingFromUI[2] = {1, 2};
int shellCalcMethodMappingToUI[3] = {-1, 0, 1};

int fixedRoofTypeMappingFromUI[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int fixedRoofTypeMappingToUI[9] = {-1, 0, 1, 2, 3, 4, 5, 6, 7};

double windDataImpFactorMappingFromUI[2] = {1.00, 1.15};

ItemUIData::ItemUIData() : m_newData(false)
                            , m_dataSaveState(DATA_SAVE_STATE_UNKNOWN)
{
    //ctor
}

ItemUIData::~ItemUIData()
{
    //dtor
}

void ItemUIData::Intialise(const wxString &fileFullPath, bool isNewData)
{
    m_newData = isNewData;
    m_uiDataFileFullPath = fileFullPath;
    m_dataSaveState = DATA_SAVE_STATE_UNKNOWN;
    if(m_newData)
    {
        memset(&m_inputData, 0x00, sizeof(InputData));
        m_inputData.D_Type = 2;
        m_inputData.Gw = 1.00;
        m_inputData.Fp = 0.40;
        m_inputData.Option_P = 1;
        m_inputData.P = 0.0;
        m_inputData.Pe = 0.25;
        m_inputData.Fpe = 0.40;
        m_inputData.Shell_Appendx_No_user = 7;
        m_inputData.shell_detail_user[0][1] = 2.5;
        m_inputData.shell_detail_user[0][2] = 3; //CA for first shell bottom
        m_inputData.JE_user = 1.0F;
        m_inputData.Shell_Des_Method_No = 1;
        m_inputData.Roof_Type_No_user = 3;
        m_inputData.Roof_Type_No = -1;
        m_inputData.weight_stair_user = 2300.00;
        m_inputData.weight_adder_user = 2.00;

        //Wind Data
        m_inputData.basic_v_user = 53.617;
        m_inputData.kz_user = 1.04;
        m_inputData.kz_default=1.04;
        m_inputData.kzt_user = 1.00;
        m_inputData.kd_user = 0.95;
        m_inputData.gust_factor_user = 0.85;
        m_inputData.wind_exp_cat = 2;
        m_inputData.imp_factorW_user = 1.00;
        m_inputData.V_user = -1;

        //Seismic Data
        m_inputData.Seismic_design_code = 1;
        m_inputData.Ss_user = 0.2;
        m_inputData.S1_user = 0.1;
        m_inputData.ASCE_rule = 1;
        m_inputData.SUG = 1;
        m_inputData.imp_factorS = 1.00;
        m_inputData.Factor_Q = 0.667;
        m_inputData.site_class = 2;
        m_inputData.TL_user = 0.40;
        m_inputData.K_user = 1.50;
        m_inputData.option_Av = 0;
        m_inputData.Av = 0.00;
        m_inputData.Sds = 0.00;
        m_inputData.Sd1 = 0.00;

        m_inputData.Spacing_Top_WG_User = 1.1;
        m_inputData.PWG_width_min_user = 750.0;

        //m_inputData.stfr_detail_user[0][1]=1;
        //m_inputData.roof_slope_user_str="";
        m_inputData.No_of_ShellCourses = 1;
        m_inputData.wind_design_code = 1;
        // m_inputData.No_of_Stiffeners_R = 0;
        m_inputData.No_of_Stiffeners_Max_user = 20;
        //default values for stiffener size window
        for(int i=0;i<45;i++)
        {
            m_inputData.stfr_Sec_No[i][1]=73;//smallest stiffener
            m_inputData.stfr_detail_user[i][1]=0;//Angle type
        }

        //making adopted pwg values to be zero
        for(int i=11;i<15;i++)
            m_inputData.PWG_details[i]=0;

        m_inputData.live_load_user = 1.0;
        m_inputData.snow_load_bal = 0.0;
        m_inputData.snow_load_unbal = 0.0;
        m_inputData.Wt_Roof_Str_user = 0.0;
        m_inputData.JE_roof_user = 0.0;
        m_inputData.fraction_roof_weight=1.0;
        m_inputData.FR_Type_No=4;
        m_inputData.R_Roof_user=0.0;
        m_inputData.dome_radius_user=0.0;
    }
    else
    {
        std::fstream data_file(m_uiDataFileFullPath, std::ios::in | std::ios::binary);
		data_file.read(reinterpret_cast<char *>(&m_inputData), sizeof(InputData));
    }
}

void ItemUIData::SetUpdatedInputData(const InputData &updatedData)
{
    m_updatedInputData = updatedData;
}
