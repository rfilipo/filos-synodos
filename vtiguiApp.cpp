/***************************************************************
 * Name:      vtiguiApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Monsenhor (filipo@kobkob.com.br)
 * Created:   2010-12-30
 * Copyright: Monsenhor (www.kobkob.com.br)
 * License:
 **************************************************************/

#include "vtiguiApp.h"

//(*AppHeaders
#include "vtiguiMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(vtiguiApp);

bool vtiguiApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	vtiguiFrame* Frame = new vtiguiFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
