#include "UTSDlg.h"

#include <wx/msgdlg.h>

//(*InternalHeaders(UTSDlg)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(UTSDlg)
const long UTSDlg::ID_STATICTEXT1 = wxNewId();
const long UTSDlg::ID_SPINCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(UTSDlg,wxDialog)
	//(*EventTable(UTSDlg)
	//*)
END_EVENT_TABLE()

UTSDlg::UTSDlg(wxWindow* parent,int materialNum, wxWindowID id,const wxPoint& pos,const wxSize& size):m_materialNum(materialNum), m_valueUTS(0)
{
	//(*Initialize(UTSDlg)
	wxBoxSizer* BoxSizerDlgBtns;
	wxBoxSizer* BoxSizerEditControls;
	wxBoxSizer* BoxSizerMain;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizerMain = new wxBoxSizer(wxVERTICAL);
	BoxSizerEditControls = new wxBoxSizer(wxHORIZONTAL);
	lblUTSValue = new wxStaticText(this, ID_STATICTEXT1, _("Enter the Ultimate Tensile Strength (UTS) of the selected material in kPa. (It should be between %d and %d Kpa)"), wxDefaultPosition, wxSize(250,45), 0, _T("ID_STATICTEXT1"));
	BoxSizerEditControls->Add(lblUTSValue, 1, wxALL|wxEXPAND, 5);
	spinCtrlUTSValue = new wxSpinCtrl(this, ID_SPINCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 100, 0, _T("ID_SPINCTRL1"));
	BoxSizerEditControls->Add(spinCtrlUTSValue, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerMain->Add(BoxSizerEditControls, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerDlgBtns = new wxBoxSizer(wxHORIZONTAL);
	btnOk = new wxButton(this, wxID_OK, _("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	btnOk->SetDefault();
	BoxSizerDlgBtns->Add(btnOk, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerMain->Add(BoxSizerDlgBtns, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizerMain);
	BoxSizerMain->Fit(this);
	BoxSizerMain->SetSizeHints(this);
	//*)

	setupControls();
	setupUTSRange();
}

UTSDlg::~UTSDlg()
{
	//(*Destroy(UTSDlg)
	//*)
}

void UTSDlg::setupUTSRange()
{
    if(71 == m_materialNum
       || 74 == m_materialNum
       || 77 == m_materialNum)
    {
        spinCtrlUTSValue->SetValue(LBOUND_RANGE_71_74_77);
        spinCtrlUTSValue->SetRange(LBOUND_RANGE_71_74_77, UBOUND_RANGE_71_74_77);

    }
    else if(66 < m_materialNum && 93 > m_materialNum)
    {
        spinCtrlUTSValue->SetValue(LBOUND_RANGE_BETWEEN_66_93);
        spinCtrlUTSValue->SetRange(LBOUND_RANGE_BETWEEN_66_93, UBOUND_RANGE_BETWEEN_66_93);
    }
}

void UTSDlg::setupControls()
{
    if(71 == m_materialNum
       || 74 == m_materialNum
       || 77 == m_materialNum)
    {
        lblUTSValue->SetLabel(wxString::Format(lblUTSValue->GetLabel(), LBOUND_RANGE_71_74_77, UBOUND_RANGE_71_74_77));
    }
    else if(66 < m_materialNum && 93 > m_materialNum)
    {
        lblUTSValue->SetLabel(wxString::Format(lblUTSValue->GetLabel(), LBOUND_RANGE_BETWEEN_66_93, UBOUND_RANGE_BETWEEN_66_93));
    }

}

int UTSDlg::GetUTSValue()
{
    m_valueUTS = spinCtrlUTSValue->GetValue();
    return m_valueUTS;
}
