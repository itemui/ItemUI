#ifndef STIFFENERSELECTION_H
#define STIFFENERSELECTION_H

//(*Headers(StiffenerSelection)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/radiobox.h>
#include <wx/sizer.h>
//*)

class StiffenerSelection: public wxDialog
{
	public:

		StiffenerSelection(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~StiffenerSelection();

		//(*Declarations(StiffenerSelection)
		wxButton* CancelButton;
		wxButton* OkButton;
		wxRadioBox* RadioBoxType;
		//*)
        int GetSelectedTypeNumber();
		wxString GetSelectedTypeDesc();
		void SetInitialValues(int type_no);
	protected:

		//(*Identifiers(StiffenerSelection)
		static const long ID_RADIOBOX1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(StiffenerSelection)
		void OnOkButtonClick(wxCommandEvent& event);
		void OnCancelButtonClick(wxCommandEvent& event);
		void OnOkButtonClick1(wxCommandEvent& event);
		void OnOkButtonClick2(wxCommandEvent& event);
		void OnCancelButtonClick1(wxCommandEvent& event);
		void OnRadioBoxTypeSelect(wxCommandEvent& event);
		//*)
        int m_selectedTypeNumber;
		wxString m_selectedTypeDesc;

		DECLARE_EVENT_TABLE()
};

#endif
