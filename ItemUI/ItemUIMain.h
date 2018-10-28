/***************************************************************
 * Name:      ItemUIMain.h
 * Purpose:   Defines Application Frame
 * Author:    Raghav ()
 * Created:   2018-05-01
 * Copyright: Raghav ()
 * License:
 **************************************************************/

#ifndef ITEMUIMAIN_H
#define ITEMUIMAIN_H

//(*Headers(ItemUIDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/dirdlg.h>
#include <wx/filedlg.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include "InputScreensDlg.h"
#include "include/ItemUIData.h"

class ItemUIDialog: public wxDialog
{
    public:

        ItemUIDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~ItemUIDialog();

    private:

        //(*Handlers(ItemUIDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnbtnNewFileClick(wxCommandEvent& event);
        void OnInit(wxInitDialogEvent& event);
        void OnbtnOpenExistingClick(wxCommandEvent& event);
        void OnbtnSaveClick(wxCommandEvent& event);
        void OnbtnSaveAsClick(wxCommandEvent& event);
        void OnButtonDesignClick(wxCommandEvent& event);
        void OntxtFolderText(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(ItemUIDialog)
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_BUTTON6;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON5;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL2;
        //*)

        //(*Declarations(ItemUIDialog)
        wxBoxSizer* BoxSizerFile;
        wxBoxSizer* BoxSizerFileFolderMain;
        wxBoxSizer* BoxSizerFolder;
        wxBoxSizer* BoxSizerMain;
        wxBoxSizer* BoxSizerSave;
        wxButton* Button1;
        wxButton* ButtonDesign;
        wxButton* btnNewFile;
        wxButton* btnOpenExisting;
        wxButton* btnSave;
        wxButton* btnSaveAs;
        wxDirDialog* DirDialog1;
        wxFileDialog* FileDialog1;
        wxFileDialog* saveAsFileDialog;
        wxStaticText* lblFileName;
        wxStaticText* lblFolder;
        wxStaticText* lblSelectLocation;
        wxTextCtrl* txtFileName;
        wxTextCtrl* txtFolder;
        //*)

        DECLARE_EVENT_TABLE()

    private:
        enum ItemUIFileEditMode {ITEMUI_FILE_EDIT_MODE_DLGINIT, ITEMUI_FILE_EDIT_MODE_NEW, ITEMUI_FILE_EDIT_MODE_EXISTING};
        ItemUIData *m_uiData;
    private:
        void resetControls(ItemUIFileEditMode editMode);
        int launchInputScreensDlg(wxString);
        void initialiseItemUIData(const wxString &uiDataFileFullPath, bool isNewData = false);

        void saveDataToFile(const wxString &fullFilePath);
};

#endif // ITEMUIMAIN_H

