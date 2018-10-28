#ifndef UTSDLG_H
#define UTSDLG_H

//(*Headers(UTSDlg)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
//*)

class UTSDlg: public wxDialog
{
	public:

		UTSDlg(wxWindow* parent, int materialNum = -1, wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~UTSDlg();

		//(*Declarations(UTSDlg)
		wxButton* btnOk;
		wxSpinCtrl* spinCtrlUTSValue;
		wxStaticText* lblUTSValue;
		//*)

	protected:

		//(*Identifiers(UTSDlg)
		static const long ID_STATICTEXT1;
		static const long ID_SPINCTRL1;
		//*)

	private:

		DECLARE_EVENT_TABLE()

    private:
        const int LBOUND_RANGE_71_74_77 = 585;
        const int UBOUND_RANGE_71_74_77 = 690;
        const int LBOUND_RANGE_BETWEEN_66_93 = 515;
        const int UBOUND_RANGE_BETWEEN_66_93 = 620;

        int m_materialNum;
        int m_valueUTS;


        void setupControls();
        void setupUTSRange();

    public:
        int GetUTSValue();
};

#endif
