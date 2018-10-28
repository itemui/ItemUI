#include "MaterialSelection.h"

#include <wx/msgdlg.h>
#include <iostream>
#include "UTSDlg.h"

//(*InternalHeaders(MaterialSelection)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(MaterialSelection)
const long MaterialSelection::ID_RADIOBOX1 = wxNewId();
const long MaterialSelection::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MaterialSelection,wxDialog)
	//(*EventTable(MaterialSelection)
	//*)
END_EVENT_TABLE()

MaterialSelection::MaterialSelection(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
:m_selectedMaterialSerialNumber(-1)
{
	//(*Initialize(MaterialSelection)
	wxBoxSizer* BoxSizerRadioBox;
	wxBoxSizer* BoxSizerSelection;

	Create(parent, wxID_ANY, _("Material Selection"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(1000,800));
	BoxSizerMain = new wxBoxSizer(wxVERTICAL);
	BoxSizerSelection = new wxBoxSizer(wxHORIZONTAL);
	pnlRadioBox = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizerRadioBox = new wxBoxSizer(wxHORIZONTAL);
	wxString __wxRadioBoxChoices_1[100] =
	{
		_("None"),
		_("A283M-Gr.C(2)"),
		_("A 285M-Gr.C(2)"),
		_("A 131M-Gr.A(2)"),
		_("A 131M-Gr. B(6)"),
		_("A 131M-Gr.EH 36"),
		_("A36M(2,5)"),
		_("A 573M-Gr. 400"),
		_("A 573M-Gr. 400(9)"),
		_("A 573M-GR. 450"),
		_("A 573M-GR. 485"),
		_("A 573M-GR. 485(10)"),
		_("A 573M-GR. 485(9)"),
		_("A 516M-Gr. 380"),
		_("A 516M-Gr. 380(9)"),
		_("A 516M-Gr. 415"),
		_("A 516M-Gr. 415(9)"),
		_("A 516M -Gr. 450"),
		_("A 516M -Gr. 450(9)"),
		_("A 516M -Gr. 485"),
		_("A 516M -Gr. 485(9)"),
		_("A 662M-GR.B"),
		_("A 662M-GR.C"),
		_("A 537M CL-1"),
		_("A 537M CL-2(12)"),
		_("A 633M-GR. C"),
		_("A 633M-GR. D"),
		_("A 678M-Gr.A"),
		_("A 678M-Gr.B(12)"),
		_("A 737M-Gr. B"),
		_("A 841M GR.A CL.1(11,12,13)"),
		_("A 841M GR.B.CL.2(11,12,13)"),
		_("CSA G 40.21M Gr.260W"),
		_("CSA G 40.21M Gr.260W(8)"),
		_("CSA G 40.21M Gr.260WT(8,9)"),
		_("CSA G 40.21M Gr.300W(8)"),
		_("CSA G 40.21M Gr.300W(8,10)"),
		_("CSA G 40.21M Gr.300WT(8, 9)"),
		_("CSA G 40.21M Gr.350W(8)"),
		_("CSA G 40.21M Gr.350W(8,10)"),
		_("CSA G 40.21M Gr.350WT(8,9)"),
		_("National Standard Gr. 235(3)"),
		_("National Standard Gr. 250(5)"),
		_("National Standard Gr. 250(7)"),
		_("National Standard Gr. 250(8)"),
		_("National Standard Gr. 250(8,9)"),
		_("National Standard Gr. 275(8)"),
		_("ISO 630 E 275C  (t < = 16)(8)"),
		_("ISO 630 E 275C  (t > 16)(8)"),
		_("ISO 630 E 275D  (t < = 16)(8)"),
		_("ISO 630 E 275D  (t > 16)(8)"),
		_("ISO 630 E 355C  (t <=16)(8)"),
		_("ISO 630 E 355C  (16< t <=40)(8)"),
		_("ISO 630 E 355C  (t > 40)(8)"),
		_("ISO 630 E 355D  (t <=16)(8)"),
		_("ISO 630 E 355D  (16< t <=40)(8)"),
		_("ISO 630 E 355D  (t > 40)(8)"),
		_("EN 10025 S275 J0 (T < = 16)(8)"),
		_("EN 10025 S275 J0 (T > 16)(8)"),
		_("EN 10025 S275 J2 (T < = 16)(8)"),
		_("EN 10025 S275 J2 (t > 16)(8)"),
		_("EN 10025 S355 J0 (T < = 16)(8)"),
		_("EN 10025 S355 J0 (16 <= T < 40) (8)"),
		_("EN 10025 S355 J0 (T > 40) (8)"),
		_("EN 10025 S355 J2, k2 (t <= 16) (8)"),
		_("EN 10025 S355 J2, k2 (16 < t <= 40)(8)"),
		_("EN 10025 S355 J2, k2 (t > 40) (8)"),
		_("A 131M-Gr.EH 36__(High UTS)"),
		_("A 573M-GR. 485_(High UTS)"),
		_("A 662M-GR.C_(High UTS)"),
		_("A 537M CL-1 _(High UTS)"),
		_("A 537M CL-2 _(High UTS)(12)"),
		_("A 633M-GR. C,D) _(High UTS)"),
		_("A 678M-GR.A)_(High UTS)"),
		_("A 678M-GR.B) _(High UTS)(12)"),
		_("A 737M-GR. B) GROUP (VI)_(High UTS)"),
		_("A 841M GR.A CL.1_(High UTS) (11,12,13)"),
		_("A 841M GR.B.CL.2_(High UTS) (11,12,13)"),
		_("CSA G 40.21M Gr.350W _(High UTS)(8,9)"),
		_("ISO 630 E 355C  (t > 40)_(High UTS) (8)"),
		_("ISO 630 E 355D  (t > 40) _(High UTS)(8)"),
		_("EN 10025 S355 J0 (T > 40) _(High UTS)(8)"),
		_("EN 10025 S355 J2, k2 (t > 40) _(High UTS)(8)"),
		_("A 240 (Type 201-1)"),
		_("A 240 (Type 201LN)"),
		_("A 240 TYPE 304"),
		_("A 240 TYPE 304L"),
		_("A 240 TYPE 316"),
		_("A 240 TYPE 316L"),
		_("SA 240 TYPE 317"),
		_("SA 240 TYPE 317L"),
		_("SA 240 S31803"),
		_("SA 240 S32003"),
		_("SA 240 S32101"),
		_("SA 240 S32202"),
		_("SA 240 S32205"),
		_("SA 240 S32304"),
		_("SA 240 S32520"),
		_("SA 240 S32750"),
		_("SA 240 S32760")
	};
	radioBoxMaterial = new wxRadioBox(pnlRadioBox, ID_RADIOBOX1, _("Material"), wxDefaultPosition, wxDefaultSize, 100, __wxRadioBoxChoices_1, 4, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
	BoxSizerRadioBox->Add(radioBoxMaterial, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	pnlRadioBox->SetSizer(BoxSizerRadioBox);
	BoxSizerRadioBox->Fit(pnlRadioBox);
	BoxSizerRadioBox->SetSizeHints(pnlRadioBox);
	BoxSizerSelection->Add(pnlRadioBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerMain->Add(BoxSizerSelection, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerDlgBtns = new wxBoxSizer(wxHORIZONTAL);
	btnOk = new wxButton(this, wxID_OK, _("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	BoxSizerDlgBtns->Add(btnOk, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	btnCancel = new wxButton(this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	BoxSizerDlgBtns->Add(btnCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerMain->Add(BoxSizerDlgBtns, 0, wxALIGN_CENTER_HORIZONTAL, 0);
	SetSizer(BoxSizerMain);
	SetSizer(BoxSizerMain);
	Layout();

	Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&MaterialSelection::OnradioBoxMaterialSelect);
	Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MaterialSelection::OnbtnOkClick);
	Connect(wxID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MaterialSelection::OnbtnCancelClick);
	//*)

	int serialNum = 0;
    int currentIndex = 0;
    std::cout<<"hi arya bhai\n";
	for(int index = 0; index < 83; ++index)
    {
        m_materialIndexToSerialNumberMapping[currentIndex] = serialNum;
        ++currentIndex;
        ++serialNum;
    }

    serialNum += 18; //next material serial number starts with 101

    for(int index = 0; index < 8; ++index)
    {
        m_materialIndexToSerialNumberMapping[currentIndex++] = serialNum;
        ++serialNum;
    }

    serialNum += 12; //next material serial number starts with 121

    for(int index = 0; index < 9; ++index)
    {
        m_materialIndexToSerialNumberMapping[currentIndex++] = serialNum;
        ++serialNum;
    }
/*
    std::cout<<"before map\n";

    for(int index = 0; index < 100; ++index)
    {
       std::cout<<"yay\n";
        std::cout<<index<<" "<<m_materialIndexToSerialNumberMapping[index]<<std::endl;
    }
   std::cout<<"after map\n";
*/
    wxString tootlipPrefix = "Notes (API 650, Table 4.4a) - ";
    wxString __wxRadioBoxChoices_ToolTips[100] =
    {
        _(""),
		_(tootlipPrefix + "2"),
		_(tootlipPrefix + "2"),
		_(tootlipPrefix + "2"),
		_(tootlipPrefix + "6"),
		_(""),
		_(tootlipPrefix + "2,5"),
		_(""),
		_(tootlipPrefix + "9"),
		_(""),
		_(""),
		_(tootlipPrefix + "10"),
		_(tootlipPrefix + "9"),
		_(""),
		_(tootlipPrefix + "9"),
		_(""),
		_(tootlipPrefix + "9"),
		_(""),
		_(tootlipPrefix + "9"),
		_(""),
		_(tootlipPrefix + "9"),
		_(""),
		_(""),
		_(""),
		_(tootlipPrefix + "12"),
		_(""),
		_(""),
		_(""),
		_(tootlipPrefix + "12"),
		_(""),
		_(tootlipPrefix + "11,12,13"),
		_(tootlipPrefix + "11,12,13"),
		_(""),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8,9"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8,10"),
		_(tootlipPrefix + "8,9"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8,10"),
		_(tootlipPrefix + "8,9"),
		_(tootlipPrefix + "3"),
		_(tootlipPrefix + "5"),
		_(tootlipPrefix + "7"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8,9"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(""),
		_(""),
		_(""),
		_(""),
		_(tootlipPrefix + "12"),
		_(""),
		_(""),
		_(tootlipPrefix + "12"),
		_(""),
		_(tootlipPrefix + "11,12,13"),
		_(tootlipPrefix + "11,12,13"),
		_(tootlipPrefix + "8,9"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(tootlipPrefix + "8"),
		_(""),
		_(""),
		_(""),
		_(""),
		_(""),
		_(""),
		_(""),
		_(""),
		_(""),
		_(""),
		_(""),
		_(""),
		_(""),
		_(""),
		_(""),
		_(""),
		_("")
	};

    for(int idx = 0; idx < 99; ++idx)
    {
        if(!__wxRadioBoxChoices_ToolTips[idx].empty())
        {
            radioBoxMaterial->SetItemToolTip(idx, __wxRadioBoxChoices_ToolTips[idx]);
        }

    }
}

MaterialSelection::~MaterialSelection()
{
	//(*Destroy(MaterialSelection)
	//*)
}

void MaterialSelection::SetInitialValues(int appendixNumber, int materialSNo)
{
    m_shellAppendixNumber = appendixNumber;
    for(int index = 0; index < 100; ++index)
    {
        radioBoxMaterial->Enable(index, false);
    }

    if(1 == m_shellAppendixNumber
       || 2 == m_shellAppendixNumber
       || 7 == m_shellAppendixNumber)
    {
        for(int index = 1; index < 83; ++index)
        {
            radioBoxMaterial->Enable(index, true);
        }

        (materialSNo > -1) && (materialSNo >= 1) && (materialSNo < 83)
        ? radioBoxMaterial->SetSelection(materialSNo)
        : radioBoxMaterial->SetSelection(1);

    }
    else if (3 == m_shellAppendixNumber)
    {
        for(int index = 83; index < 91; ++index)
        {
            radioBoxMaterial->Enable(index, true);
        }

        (materialSNo > -1) && (materialSNo >= 83) && (materialSNo < 91)
        ? radioBoxMaterial->SetSelection(materialSNo)
        : radioBoxMaterial->SetSelection(83);
    }
    else if (4 == m_shellAppendixNumber)
    {
        for(int index = 1; index < 91; ++index)
        {
            radioBoxMaterial->Enable(index, true);
        }

        (materialSNo > -1) && (materialSNo >= 1) && (materialSNo < 91)
        ? radioBoxMaterial->SetSelection(materialSNo)
        : radioBoxMaterial->SetSelection(1);
    }
    else if (5 == m_shellAppendixNumber)
    {
        for(int index = 91; index < 100; ++index)
        {
            radioBoxMaterial->Enable(index, true);
        }

        (materialSNo > -1) && (materialSNo >= 91) && (materialSNo < 100)
        ? radioBoxMaterial->SetSelection(materialSNo)
        : radioBoxMaterial->SetSelection(91);
    }

    m_selectedMaterialSerialNumber = radioBoxMaterial->GetSelection();
}

int MaterialSelection::GetSelectedMaterialSerialNumber()
{
    return m_selectedMaterialSerialNumber;
}

void MaterialSelection::OnradioBoxMaterialSelect(wxCommandEvent& event)
{
    int selectedRadioButton = radioBoxMaterial->GetSelection();
    m_selectedMaterialDesc = radioBoxMaterial->GetString(selectedRadioButton);
    //wxMessageBox(m_selectedMaterialDesc, "Information");
    m_selectedMaterialSerialNumber = m_materialIndexToSerialNumberMapping[selectedRadioButton];

    event.Skip();
}

int MaterialSelection::materialNumberToIndex(int m)
{
    for(int i = 0;i<100;i++)
    {
        //std::cout<<i<<" "<<m_materialIndexToSerialNumberMapping[i]<<std::endl;
        if(m_materialIndexToSerialNumberMapping[i]==m)
            return i;

    }
    return m;
}

wxString MaterialSelection::GetSelectedMaterialDesc()
{
    return m_selectedMaterialDesc;
}

void  MaterialSelection::OnbtnOkClick(wxCommandEvent& event)
{
    if(m_selectedMaterialSerialNumber == 71
       || m_selectedMaterialSerialNumber == 74
       || m_selectedMaterialSerialNumber == 77
       || (66 < m_selectedMaterialSerialNumber && 93 > m_selectedMaterialSerialNumber))
    {
        UTSDlg utsDlg(this, m_selectedMaterialSerialNumber);
        utsDlg.ShowModal();
        utsValue = utsDlg.GetUTSValue();
    }


    //selected_material_number = m_selectedMaterialSerialNumber;
    Close();
    //return m_selectedMaterialSerialNumber;
    //this->SetReturnCode(wxID_OK);
}

void MaterialSelection::setIndextoNumber()
{

    int serialNum = 0;
    int currentIndex = 0;
	for(int index = 0; index < 83; ++index)
    {
        m_materialIndexToSerialNumberMapping[currentIndex] = serialNum;
        ++currentIndex;
        ++serialNum;
    }

    serialNum += 18; //next material serial number starts with 101

    for(int index = 0; index < 8; ++index)
    {
        m_materialIndexToSerialNumberMapping[currentIndex++] = serialNum;
        ++serialNum;
    }

    serialNum += 12; //next material serial number starts with 121

    for(int index = 0; index < 9; ++index)
    {
        m_materialIndexToSerialNumberMapping[currentIndex++] = serialNum;
        ++serialNum;
    }
}

void MaterialSelection::OnbtnCancelClick(wxCommandEvent& event)
{
    Close();
    event.Skip();
}
