#include "AngleSelection.h"

//(*InternalHeaders(AngleSelection)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include<iostream>

//(*IdInit(AngleSelection)
const long AngleSelection::ID_RADIOBOX1 = wxNewId();
const long AngleSelection::ID_BUTTONangleOK = wxNewId();
const long AngleSelection::ID_BUTTONangleCancel = wxNewId();
const long AngleSelection::ID_STATICTEXT1 = wxNewId();
const long AngleSelection::ID_STATICTEXT2 = wxNewId();
const long AngleSelection::ID_STATICTEXT3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(AngleSelection,wxDialog)
	//(*EventTable(AngleSelection)
	//*)
END_EVENT_TABLE()

AngleSelection::AngleSelection(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(AngleSelection)
	Create(parent, wxID_ANY, _("Angle Selection"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(464,535));
	wxString __wxRadioBoxChoices_1[75] =
	{
		_("200x200x24"),
		_("200x200x20"),
		_("200x200x18"),
		_("180x180x18"),
		_("200x200x16"),
		_("200x150x18"),
		_("180x180x16"),
		_("150x150x18"),
		_("200x150x15"),
		_("160x160x15"),
		_("150x150x15"),
		_("200x100x15"),
		_("200x150x12"),
		_("200x100x12"),
		_("150x150x12"),
		_("150x90x15"),
		_("120x120x15"),
		_("150x75x15"),
		_("130x130x12"),
		_("150x150x10"),
		_("200x100x10"),
		_("150x100x12"),
		_("120x120x12"),
		_("150x100x10"),
		_("100x100x15"),
		_("150x90x12"),
		_("150x75x12"),
		_("150x90x10"),
		_("120x120x10"),
		_("150x75x10"),
		_("100x75x12"),
		_("150x75x9"),
		_("125x75x10"),
		_("135x65x10"),
		_("120x120x8"),
		_("90x90x10"),
		_("135x65x8"),
		_("100x100x8"),
		_("90x90x9"),
		_("125x75x12"),
		_("100x100x12"),
		_("90x90x12"),
		_("100x100x10"),
		_("100x65x10"),
		_("125x75x8"),
		_("120x80x12"),
		_("120x80x10"),
		_("100x75x10"),
		_("120x80x8"),
		_("90x90x8"),
		_("100x75x8"),
		_("80x80x10"),
		_("70x70x10"),
		_("100x65x8"),
		_("80x80x8"),
		_("90x90x7"),
		_("100x50x8"),
		_("75x75x8"),
		_("100x65x7"),
		_("100x50x6"),
		_("80x60x8"),
		_("90x90x6"),
		_("70x70x8"),
		_("75x50x8"),
		_("70x70x7"),
		_("80x60x7"),
		_("80x80x6"),
		_("80x40x8"),
		_("75x75x6"),
		_("70x70x6"),
		_("80x60x6"),
		_("65x65x7"),
		_("65x65x6"),
		_("1"),
		_("2")
	};
	radioBoxAngle = new wxRadioBox(this, ID_RADIOBOX1, _("Angle"), wxPoint(16,88), wxSize(440,360), 75, __wxRadioBoxChoices_1, 5, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
	angleOKButton = new wxButton(this, ID_BUTTONangleOK, _("OK"), wxPoint(104,464), wxSize(104,23), 0, wxDefaultValidator, _T("ID_BUTTONangleOK"));
	angleCancelButton = new wxButton(this, ID_BUTTONangleCancel, _("Cancel"), wxPoint(248,464), wxSize(104,23), 0, wxDefaultValidator, _T("ID_BUTTONangleCancel"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Angle Selection Designation"), wxPoint(104,16), wxSize(133,24), 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("@Adobe Gothic Std B"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("a x b x c"), wxPoint(192,40), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(11,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("@Adobe Gothic Std B"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("mm"), wxPoint(208,56), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(9,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("@Adobe Gothic Std B"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);

	Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&AngleSelection::OnradioBoxAngleSelect);
	Connect(ID_BUTTONangleOK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AngleSelection::OnangleOKButtonClick);
	Connect(ID_BUTTONangleCancel,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AngleSelection::OnangleCancelButtonClick);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&AngleSelection::OnInit1);
	//*)
}

AngleSelection::~AngleSelection()
{
	//(*Destroy(AngleSelection)
	//*)
}

int AngleSelection::GetSelectedAngleNumber()
{
    return m_selectedAngleNumber;
}
wxString AngleSelection::GetSelectedAngleDesc()
{
    return m_selectedAngleDesc;
}

void AngleSelection::OnradioBoxAngleSelect(wxCommandEvent& event)
{
    int selectedRadioButton = radioBoxAngle->GetSelection();
    m_selectedAngleDesc = radioBoxAngle->GetString(selectedRadioButton);
    //wxMessageBox(m_selectedMaterialDesc, "Information");
    m_selectedAngleNumber = selectedRadioButton+1;

    event.Skip();
}

void AngleSelection::SetInitialValues(int num)
{
	radioBoxAngle->SetSelection(num);
	m_selectedAngleDesc = radioBoxAngle->GetString(num);
    m_selectedAngleNumber = num+1;
	radioBoxAngle->Show(73,false);
	radioBoxAngle->Show(74,false);
}

void AngleSelection::OnangleOKButtonClick(wxCommandEvent& event)
{
    int selectedRadioButton = radioBoxAngle->GetSelection();
    m_selectedAngleDesc = radioBoxAngle->GetString(selectedRadioButton);
    m_selectedAngleNumber = selectedRadioButton+1;
    Close();
}

void AngleSelection::OnangleCancelButtonClick(wxCommandEvent& event)
{
    Close();
}

void AngleSelection::OnInit(wxInitDialogEvent& event)
{
}

void AngleSelection::OnInit1(wxInitDialogEvent& event)
{
}
