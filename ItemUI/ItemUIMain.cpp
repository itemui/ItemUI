/***************************************************************
 * Name:      ItemUIMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Raghav ()
 * Created:   2018-05-01
 * Copyright: Raghav ()
 * License:
 **************************************************************/

#include "ItemUIMain.h"
#include <wx/msgdlg.h>
#include <wx/filename.h>

#include <fstream>
#include <iostream>
#include "include/CommonUtilities.h"

void maintest();

//(*InternalHeaders(ItemUIDialog)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//declaration of functions defined in source file
void InitVariables();

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(ItemUIDialog)
const long ItemUIDialog::ID_BUTTON3 = wxNewId();
const long ItemUIDialog::ID_BUTTON4 = wxNewId();
const long ItemUIDialog::ID_BUTTON6 = wxNewId();
const long ItemUIDialog::ID_BUTTON1 = wxNewId();
const long ItemUIDialog::ID_BUTTON2 = wxNewId();
const long ItemUIDialog::ID_BUTTON5 = wxNewId();
const long ItemUIDialog::ID_STATICTEXT1 = wxNewId();
const long ItemUIDialog::ID_STATICTEXT2 = wxNewId();
const long ItemUIDialog::ID_TEXTCTRL1 = wxNewId();
const long ItemUIDialog::ID_STATICTEXT3 = wxNewId();
const long ItemUIDialog::ID_TEXTCTRL2 = wxNewId();
bool file_selected = false;
wxString folderPath;
wxString fileName;
//*)

BEGIN_EVENT_TABLE(ItemUIDialog,wxDialog)
    //(*EventTable(ItemUIDialog)
    //*)
END_EVENT_TABLE()

ItemUIDialog::ItemUIDialog(wxWindow* parent,wxWindowID id) : m_uiData(NULL)
{
    //(*Initialize(ItemUIDialog)
    wxBoxSizer* BoxSizerFileDisplay;
    wxBoxSizer* BoxSizerFileOpen;

    Create(parent, wxID_ANY, _("File"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
    SetClientSize(wxSize(600,300));
    BoxSizerMain = new wxBoxSizer(wxHORIZONTAL);
    BoxSizerFileFolderMain = new wxBoxSizer(wxVERTICAL);
    BoxSizerFileOpen = new wxBoxSizer(wxHORIZONTAL);
    btnNewFile = new wxButton(this, ID_BUTTON3, _("Start a new File"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizerFileOpen->Add(btnNewFile, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnOpenExisting = new wxButton(this, ID_BUTTON4, _("Open an existing file"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizerFileOpen->Add(btnOpenExisting, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON6, _("Continue"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    BoxSizerFileOpen->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizerSave = new wxBoxSizer(wxVERTICAL);
    btnSave = new wxButton(this, ID_BUTTON1, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizerSave->Add(btnSave, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnSaveAs = new wxButton(this, ID_BUTTON2, _("Save As"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizerSave->Add(btnSaveAs, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonDesign = new wxButton(this, ID_BUTTON5, _("Design"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    BoxSizerSave->Add(ButtonDesign, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizerFileOpen->Add(BoxSizerSave, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizerFileFolderMain->Add(BoxSizerFileOpen, 1, wxALL|wxEXPAND, 5);
    BoxSizerFileDisplay = new wxBoxSizer(wxVERTICAL);
    lblSelectLocation = new wxStaticText(this, ID_STATICTEXT1, _("Location and Name of the file"), wxDefaultPosition, wxSize(184,20), 0, _T("ID_STATICTEXT1"));
    wxFont lblSelectLocationFont(11,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    lblSelectLocation->SetFont(lblSelectLocationFont);
    BoxSizerFileDisplay->Add(lblSelectLocation, 1, wxALL|wxEXPAND, 5);
    BoxSizerFolder = new wxBoxSizer(wxHORIZONTAL);
    lblFolder = new wxStaticText(this, ID_STATICTEXT2, _("Folder"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    lblFolder->SetMaxSize(wxSize(60,25));
    BoxSizerFolder->Add(lblFolder, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    txtFolder = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizerFolder->Add(txtFolder, 1, wxALL, 5);
    BoxSizerFileDisplay->Add(BoxSizerFolder, 1, wxALL|wxEXPAND, 5);
    BoxSizerFile = new wxBoxSizer(wxHORIZONTAL);
    lblFileName = new wxStaticText(this, ID_STATICTEXT3, _("File Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    lblFileName->SetMaxSize(wxSize(60,25));
    BoxSizerFile->Add(lblFileName, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    txtFileName = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizerFile->Add(txtFileName, 1, wxALL, 5);
    BoxSizerFileDisplay->Add(BoxSizerFile, 1, wxALL|wxEXPAND, 5);
    BoxSizerFileFolderMain->Add(BoxSizerFileDisplay, 1, wxALL|wxEXPAND, 5);
    BoxSizerMain->Add(BoxSizerFileFolderMain, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizerMain);
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("*.bin"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    DirDialog1 = new wxDirDialog(this, _("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxDirDialog"));
    saveAsFileDialog = new wxFileDialog(this, _("Save As"), wxEmptyString, wxEmptyString, _("*.bin"), wxFD_SAVE|wxFD_OVERWRITE_PROMPT, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    SetSizer(BoxSizerMain);
    Layout();
    Center();

    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ItemUIDialog::OnbtnNewFileClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ItemUIDialog::OnbtnOpenExistingClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ItemUIDialog::OnButton1Click);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ItemUIDialog::OnbtnSaveClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ItemUIDialog::OnbtnSaveAsClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ItemUIDialog::OnButtonDesignClick);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&ItemUIDialog::OnInit);
    //*)
}

ItemUIDialog::~ItemUIDialog()
{
    //(*Destroy(ItemUIDialog)
    //*)
}

void ItemUIDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void ItemUIDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void ItemUIDialog::OnbtnNewFileClick(wxCommandEvent& event)
{
    int retDlg = DirDialog1->ShowModal();
    if(wxID_OK == retDlg)
    {
        wxString fileName = "untitled.bin";
        FileManip_ItemUi::appendStringBeforeExt(fileName, "Data");
        resetControls(ITEMUI_FILE_EDIT_MODE_NEW);
        folderPath = DirDialog1->GetPath();
        //wxMessageBox(folderPath);
        txtFolder->SetValue(folderPath);
        txtFileName->SetValue(fileName);
        initialiseItemUIData(folderPath + "\\" + fileName, true);
        file_selected = true;
        //launchInputScreensDlg(folderPath+"\\"+fileName);
    }

}

void ItemUIDialog::resetControls(ItemUIFileEditMode editMode)
{
    txtFileName->Clear();
    switch(editMode)
    {
    case ITEMUI_FILE_EDIT_MODE_NEW:
    {
        txtFileName->SetEditable(true);
        break;
    }
    case ITEMUI_FILE_EDIT_MODE_EXISTING:
    {
        txtFileName->SetEditable(false);
        break;
    }
    default:
    {
        txtFolder->Clear();
        txtFileName->SetEditable(false);
        txtFolder->SetEditable(false);
    }
    }

}

void ItemUIDialog::OnInit(wxInitDialogEvent& event)
{
    resetControls(ITEMUI_FILE_EDIT_MODE_DLGINIT);
}

void ItemUIDialog::OnbtnOpenExistingClick(wxCommandEvent& event)
{
    int retDlg = FileDialog1->ShowModal();
    wxString fileFullPath;
    if(wxID_OK == retDlg)
    {
        resetControls(ITEMUI_FILE_EDIT_MODE_NEW);//ITEMUI_FILE_EDIT_MODE_EXISTING);
        fileFullPath = FileDialog1->GetPath();
        wxString fileName = wxFileNameFromPath(fileFullPath);
        wxFileName inputFile(fileFullPath);

        txtFolder->SetValue(inputFile.GetPath());
        txtFileName->SetValue(fileName);
        initialiseItemUIData(fileFullPath);
        launchInputScreensDlg(fileFullPath);
    }
    event.Skip();
}

int ItemUIDialog::launchInputScreensDlg(wxString fileName)
{
    //initialise the global variables
    InitVariables();
    InputScreensDlg inputScreenDlg(this);

    inputScreenDlg.SetLayoutAdaptationMode(wxDIALOG_ADAPTATION_MODE_ENABLED);
    InputData currentInputData;
    m_uiData->GetInputData(currentInputData);
    inputScreenDlg.SetInputData(&currentInputData);
    inputScreenDlg.SetIsNewData(m_uiData->IsNewData());

    inputScreenDlg.SetInitialControlStates();
    inputScreenDlg.SetInitialControlValues();
    inputScreenDlg.SetupValidators();
    inputScreenDlg.setResultFileName(std::string(fileName));

    //initialising global variables in Tank.cpp
    InitVariables();
    int resultInputScreenDlg = inputScreenDlg.ShowModal();
    if(wxID_OK == resultInputScreenDlg)
    {
        m_uiData->SetUpdatedInputData(currentInputData);
        m_uiData->SetDataSaveState(ItemUIData::DATA_SAVE_STATE_GOOD);
    }

    else if(wxID_OK == resultInputScreenDlg)
    {
        std::cout<<"design button working";
    }


    return resultInputScreenDlg;
}

void ItemUIDialog::initialiseItemUIData(const wxString &uiDataFileFullPath, bool isNewData)
{
    if(NULL == m_uiData)
    {
        m_uiData = new ItemUIData();
    }

    m_uiData->Intialise(uiDataFileFullPath, isNewData);
}

void ItemUIDialog::saveDataToFile(const wxString &fullFilePath)
{
    std::fstream data_file(fullFilePath, std::ios::out | std::ios::binary);
    data_file.write(reinterpret_cast<char *>(m_uiData->GetUpdateUIData()), sizeof(InputData));
    data_file.flush();
    data_file.close();
}

void ItemUIDialog::OnbtnSaveClick(wxCommandEvent& event)
{
    //if(ItemUIData::DATA_SAVE_STATE_GOOD == m_uiData->GetDataSaveState())
    {
        wxString fileName = txtFileName->GetValue();

        if(!fileName.IsEmpty())
        {
            if(!FileManip_ItemUi::hasExtension(fileName, "bin"))
            {
                fileName.Append(".bin");
            }

            txtFileName->SetValue(fileName);

            wxString fullSaveFilePath = txtFolder->GetValue() + "/" + fileName;

            saveDataToFile(fullSaveFilePath);
            wxMessageBox("File Saved", "File Save", wxICON_INFORMATION | wxOK);
            m_uiData->SetDataSaveState(ItemUIData::DATA_SAVE_STATE_SAVED);
        }
        else
        {
            std::cout<<"empty file"<<std::endl;
            wxMessageBox("File name cannot be empty!", "File Name", wxICON_INFORMATION | wxOK);
        }
    }
}

void ItemUIDialog::OnbtnSaveAsClick(wxCommandEvent& event)
{
    wxString fileFullPath;
    saveAsFileDialog->SetDirectory(txtFolder->GetValue());
    saveAsFileDialog->SetFilename(txtFileName->GetValue());

    int retSaveAsDialog = saveAsFileDialog->ShowModal();

    if(wxID_OK == retSaveAsDialog)
    {
        fileFullPath = saveAsFileDialog->GetPath();
        wxString fileName = wxFileNameFromPath(fileFullPath);
        wxFileName inputFile(fileFullPath);

        txtFolder->SetValue(inputFile.GetPath());
        txtFileName->SetValue(fileName);
        if(ItemUIData::DATA_SAVE_STATE_SAVED == m_uiData->GetDataSaveState())
        {
            m_uiData->SetDataSaveState(ItemUIData::DATA_SAVE_STATE_GOOD);
        }

        OnbtnSaveClick(event);
    }
}


void ItemUIDialog::OnButtonDesignClick(wxCommandEvent& event)
{
    wxString fileName = "temporaryFile";
    if(!FileManip_ItemUi::hasExtension(fileName, "bin"))
    {
        fileName.Append(".bin");
    }

    FileManip_ItemUi::appendStringBeforeExt(fileName, "Data");

    txtFileName->SetValue(fileName);

    wxString fullSaveFilePath = txtFolder->GetValue() + "/" + fileName;

    saveDataToFile(fullSaveFilePath);
    wxMessageBox("File Saved", "File Save", wxICON_INFORMATION | wxOK);
    m_uiData->SetDataSaveState(ItemUIData::DATA_SAVE_STATE_SAVED);

}

void ItemUIDialog::OntxtFolderText(wxCommandEvent& event)
{
}

void ItemUIDialog::OnButton1Click(wxCommandEvent& event)
{
   if(file_selected)
    launchInputScreensDlg(folderPath+"\\"+fileName);
    else
    wxMessageBox(wxT("Folder name can't be blank!"));

}
