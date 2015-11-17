/***************************************************************
 * Name:      npcproApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Jake Gardner (gardnertechllc+jake@gmail.com)
 * Created:   2014-07-02
 * Copyright: Jake Gardner ()
 * License:
 **************************************************************/

#include "npcproApp.h"

//(*AppHeaders
#include "npcproMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(npcproApp);

bool npcproApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	npcproFrame* Frame = new npcproFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
