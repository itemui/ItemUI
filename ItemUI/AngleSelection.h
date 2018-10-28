#ifndef ANGLESELECTION_H
#define ANGLESELECTION_H

//(*Headers(AngleSelection)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/radiobox.h>
#include <wx/stattext.h>
//*)

class AngleSelection: public wxDialog
{
	public:

		AngleSelection(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~AngleSelection();

		//(*Declarations(AngleSelection)
		wxButton* angleCancelButton;
		wxButton* angleOKButton;
		wxRadioBox* radioBoxAngle;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		//*)

		int GetSelectedAngleNumber();
		wxString GetSelectedAngleDesc();
		void SetInitialValues(int num);

	protected:

		//(*Identifiers(AngleSelection)
		static const long ID_RADIOBOX1;
		static const long ID_BUTTONangleOK;
		static const long ID_BUTTONangleCancel;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		//*)

	private:

		//(*Handlers(AngleSelection)
		void OnradioBoxAngleSelect(wxCommandEvent& event);
		void OnangleOKButtonClick(wxCommandEvent& event);
		void OnangleCancelButtonClick(wxCommandEvent& event);
		void OnInit(wxInitDialogEvent& event);
		void OnInit1(wxInitDialogEvent& event);
		//*)
		int m_selectedAngleNumber;
		wxString m_selectedAngleDesc;



		DECLARE_EVENT_TABLE()
};

#endif
