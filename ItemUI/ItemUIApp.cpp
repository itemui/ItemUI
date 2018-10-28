/***************************************************************
 * Name:      ItemUIApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Raghav ()
 * Created:   2018-05-01
 * Copyright: Raghav ()
 * License:
 **************************************************************/

#include "ItemUIApp.h"

//(*AppHeaders
#include "ItemUIMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ItemUIApp);

bool ItemUIApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ItemUIDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    wxImage::AddHandler(new wxPNGHandler);
    wxInitAllImageHandlers();
    return wxsOK;

}
