#ifndef MATERIALSELECTION_H
#define MATERIALSELECTION_H

//(*Headers(MaterialSelection)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/radiobox.h>
#include <wx/sizer.h>
//*)



class MaterialSelection: public wxDialog
{
	public:

		MaterialSelection(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~MaterialSelection();


		//(*Declarations(MaterialSelection)
		wxBoxSizer* BoxSizerDlgBtns;
		wxBoxSizer* BoxSizerMain;
		wxButton* btnCancel;
		wxButton* btnOk;
		wxPanel* pnlRadioBox;
		wxRadioBox* radioBoxMaterial;
		//*)

	protected:

		//(*Identifiers(MaterialSelection)
		static const long ID_RADIOBOX1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(MaterialSelection)
		void OnradioBoxMaterialSelect(wxCommandEvent& event);
		void OnbtnOkClick(wxCommandEvent& event);
		void OnbtnCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()


    private:
        int m_materialIndexToSerialNumberMapping[100];
        int m_shellDesignAppendixNum;
        int m_selectedMaterialSerialNumber;


        wxString m_selectedMaterialDesc;
        int m_shellAppendixNumber;

    public:
        void SetInitialValues(int appendixNumber, int materialSNo = -1);
        int GetSelectedMaterialSerialNumber();
        int utsValue;
        wxString GetSelectedMaterialDesc();
        int materialNumberToIndex(int m);
        void setIndextoNumber();

};

#endif
