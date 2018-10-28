#include "StiffenerSelection.h"

//(*InternalHeaders(StiffenerSelection)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(StiffenerSelection)
const long StiffenerSelection::ID_RADIOBOX1 = wxNewId();
const long StiffenerSelection::ID_BUTTON1 = wxNewId();
const long StiffenerSelection::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(StiffenerSelection,wxDialog)
	//(*EventTable(StiffenerSelection)
	//*)
END_EVENT_TABLE()

StiffenerSelection::StiffenerSelection(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(StiffenerSelection)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizerStiffener;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizerStiffener = new wxBoxSizer(wxVERTICAL);
	wxString __wxRadioBoxChoices_1[2] =
	{
		_("ANGLE"),
		_("BUILTUP")
	};
	RadioBoxType = new wxRadioBox(this, ID_RADIOBOX1, _("Stiffener Type"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
	BoxSizerStiffener->Add(RadioBoxType, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	OkButton = new wxButton(this, ID_BUTTON1, _("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer1->Add(OkButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CancelButton = new wxButton(this, ID_BUTTON2, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer1->Add(CancelButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizerStiffener->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizerStiffener);
	BoxSizerStiffener->Fit(this);
	BoxSizerStiffener->SetSizeHints(this);

	Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&StiffenerSelection::OnRadioBoxTypeSelect);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&StiffenerSelection::OnOkButtonClick2);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&StiffenerSelection::OnCancelButtonClick1);
	//*)
}

StiffenerSelection::~StiffenerSelection()
{
	//(*Destroy(StiffenerSelection)
	//*)
}


int StiffenerSelection::GetSelectedTypeNumber()
{
    return m_selectedTypeNumber;
}

wxString StiffenerSelection::GetSelectedTypeDesc()
{
    return m_selectedTypeDesc;
}

void StiffenerSelection::OnOkButtonClick2(wxCommandEvent& event)
{
    int selectedRadioButton = RadioBoxType->GetSelection();
    m_selectedTypeDesc = RadioBoxType->GetString(selectedRadioButton);
    m_selectedTypeNumber = selectedRadioButton;
    Close();
}

void StiffenerSelection::OnCancelButtonClick1(wxCommandEvent& event)
{
    Close();
}

void StiffenerSelection::SetInitialValues(int num)
{
	RadioBoxType->SetSelection(num);
	m_selectedTypeDesc = RadioBoxType->GetString(num);
    m_selectedTypeNumber = num;
}

void StiffenerSelection::OnRadioBoxTypeSelect(wxCommandEvent& event)
{
    int selectedRadioButton = RadioBoxType->GetSelection();
    m_selectedTypeDesc = RadioBoxType->GetString(selectedRadioButton);
    m_selectedTypeNumber = selectedRadioButton;

    event.Skip();
}
