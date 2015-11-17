/***************************************************************
 * Name:      npcproOneAdv.cpp
 * Purpose:   Contains All Board Functions
 * Author:    Jake Gardner (gardnertechllc+jake@gmail.com)
 * Created:   2014-07-02
 * Copyright: Jake Gardner ()
 * License:
 **************************************************************/

#include "npcproMain.h"
#include <wx/msgdlg.h>
#include <wx/textctrl.h>
#include <wx/textdlg.h>
#include <wx/combobox.h>
#include <wx/evtloop.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <unistd.h>
//#include <thread>

#ifdef _WIN32
#include <windows.h>
#endif

//(*InternalHeaders(npcproFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

void npcproFrame::OnEBroadButtonClick(wxCommandEvent& event)
{
    wxWindow::Enable(false);
    TextLog->AppendText("\n All Board Emergency Broadcast Set\n");
    SetStatusText("Running, Please Wait",0);
    int msleep(unsigned long milisec, std::string os);
    std::string systemRep(std::string cmd);
    std::string GetStdoutFromCommand(std::string cmd, std::string ip, std::string space, std::string model, std::string cmd2);
    std::string os ="unk";
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    os="win";
#else
    os="uni";
#endif
    std::ifstream conftext;
    std::ifstream in;
    std::string homepath;
    if (os == "win")
    {
        homepath = getenv("APPDATA");
        in.open((homepath + "/npc/rooms.csv").c_str());
        conftext.open((homepath + "/npc/pass.txt").c_str());
    }
    if (os == "uni")
    {
        homepath = getenv("HOME");
        in.open((homepath + "/.npc/rooms.csv").c_str());
        conftext.open((homepath + "/.npc/pass.txt").c_str());
    }
    unsigned int e = 0;
    //float f = 1.1;
    std::string out;
    std::string q;
    std::string cmd1;
    std::string cmd2;
    std::string ip;
    std::string on;
    std::string space = " ";
    std::string model;
    std::string message = "Undefined Emergency";
    std::string line, field;
    std::vector< std::vector<std::string> > array;
    std::vector<std::string> v;
    wxString pass = TextPass->GetValue();
    long int outn;
    std::string realpass;
    getline(conftext,realpass);
    if ( pass == realpass)
    {
        //TextLog->AppendText("Password Correct\n");
        wxTextEntryDialog TextEntryDialog1(this, _("Emergency Message: "), _("Message Input Panel"), _("Emergency"));
        if ( TextEntryDialog1.ShowModal() == wxID_OK )
        {
            message = TextEntryDialog1.GetValue();
            TextLog->AppendText("Emergency Message '");
            TextLog->AppendText(message);
            TextLog->AppendText("' set.\n");
        }
        while ( getline(in,line) )
        {
            v.clear();
            std::stringstream ss(line);

            while (getline(ss,field,','))
            {
                v.push_back(field);
            }
            array.push_back(v);
        }
        while (e < array.size())
        {
            wxYield();
            out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe -t 0.2 ", array[e][1], " ", array[e][2], "-MIB::powerState.0");
            outn = atof(out.c_str());
            if ( outn > 1)
            {
                cmd1 = "snmpset -v 2c -c public -t 0.2 ";
                space = " ";
                model = array[e][2];
                cmd2 = "-MIB::powerState.0 i 1";
                ip = array[e][1];
                on = cmd1 + ip + space + model + cmd2;
                systemRep(on.c_str());
            }
            if ( outn == 0)
            {
                TextLog->AppendText("The board in ");
                TextLog->AppendText(array[e][0]);
                TextLog->AppendText(" did Not respond.\n");
            }
            e++;
        }
        e = 0;
        //msleep(30000, os);
        TextLog->AppendText("Start.\n");
        while (e < 30) {
            wxSleep(1);
            wxYield();
            e++;
        }
        TextLog->AppendText("End.\n");
        e = 0;
        while (e < array.size())
        {
            cmd1 = "snmpset -v 2c -c public ";
            cmd2 = "-MIB::emergencyAlertMsg.0 s ";
            space = " ";
            model = array[e][2];
            ip = array[e][1];
            q = "\"";
            on = cmd1 + ip + space + model + cmd2 + q + message + q;
            systemRep(on.c_str());
            cmd2 = "-MIB::emergencyDisplay.0 i 1";
            on = cmd1 + ip + space + model + cmd2;
            systemRep(on.c_str());
            e++;
            wxYield();
        }
    }


    else
    {
        TextLog->AppendText("Password Incorrect.\n");
    }
    SetStatusText("Done",0);
    wxWindow::Enable(true);
}

void npcproFrame::OnAllStatButtonClick(wxCommandEvent& event)
{
    wxWindow::Enable(false);
    TextLog->AppendText("\nAll Board Status Check\n");
    SetStatusText("Running, Please Wait",0);
    std::string GetStdoutFromCommand(std::string cmd, std::string ip, std::string space, std::string model, std::string cmd2);
    std::string os ="unk";
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    os="win";
#else
    os="uni";
#endif

    std::ifstream conftext;
    std::ifstream in;
    std::string homepath;
    if (os == "win")
    {
        homepath = getenv("APPDATA");
        in.open((homepath + "/npc/rooms.csv").c_str());
        conftext.open((homepath + "/npc/pass.txt").c_str());
    }
    if (os == "uni")
    {
        homepath = getenv("HOME");
        in.open((homepath + "/.npc/rooms.csv").c_str());
        conftext.open((homepath + "/.npc/pass.txt").c_str());
    }
    unsigned int e = 0;
    //float f = 1.1;
    std::string room;
    std::string out;
    std::string line, field;
    std::vector< std::vector<std::string> > array;
    std::vector<std::string> v;
    wxString pass = TextPass->GetValue();
    long int outn;
    std::string realpass;
    getline(conftext,realpass);
    if ( pass == realpass)
    {
        wxString room = TextRoom->GetValue();
        //TextLog->AppendText("Password Correct\n");
        while ( getline(in,line) )
        {
            v.clear();
            std::stringstream ss(line);

            while (getline(ss,field,','))
            {
                v.push_back(field);
            }
            array.push_back(v);
        }
        while (e < array.size())
        {


            out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe -t 0.2 ", array[e][1], " ", array[e][2], "-MIB::powerState.0");
            outn = atof(out.c_str());
            wxString outw = wxString::Format(wxT("%ld"),outn);
            if ( outn == 1)
            {
                //TextLog->AppendText("Status code ");
                //TextLog->AppendText(outw);
                TextLog->AppendText("The board in ");
                TextLog->AppendText(array[e][0]);
                TextLog->AppendText(" is On.\n");
            }
            if ( outn == 2)
            {
                //TextLog->AppendText("Status code ");
                //TextLog->AppendText(outw);
                TextLog->AppendText("The board in ");
                TextLog->AppendText(array[e][0]);
                TextLog->AppendText(" is Off.\n");
            }
            if ( outn == 3)
            {
                //TextLog->AppendText("Status code ");
                //TextLog->AppendText(outw);
                TextLog->AppendText("The board in ");
                TextLog->AppendText(array[e][0]);
                TextLog->AppendText(" is Powering On.\n");
            }
            if ( outn == 4)
            {
                //TextLog->AppendText("Status code ");
                //TextLog->AppendText(outw);
                TextLog->AppendText("The board in ");
                TextLog->AppendText(array[e][0]);
                TextLog->AppendText(" is in Cooling State.\n");
            }
            if ( outn == 5)
            {
                //TextLog->AppendText("Status code ");
                //TextLog->AppendText(outw);
                TextLog->AppendText("The board in ");
                TextLog->AppendText(array[e][0]);
                TextLog->AppendText(" is in Confirm Off State.\n");
            }
            if ( outn == 0)
            {
                //TextLog->AppendText("Status code ");
                //TextLog->AppendText(outw);
                TextLog->AppendText("The Board in ");
                TextLog->AppendText(array[e][0]);
                TextLog->AppendText(" did Not respond.\n");
            }
            e++;
            wxYield();
        }

    }

    else
    {
        TextLog->AppendText("Password Incorrect.\n");
    }
    SetStatusText("Done",0);
    wxWindow::Enable(true);
}

void npcproFrame::OnAllBulbButtonClick(wxCommandEvent& event)
{
    wxWindow::Enable(false);
    TextLog->AppendText("\nAll Board Bulb Life Status Check\n");
    SetStatusText("Running, Please Wait",0);
    std::string GetStdoutFromCommand(std::string cmd, std::string ip, std::string space, std::string model, std::string cmd2);
    std::string os ="unk";
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    os="win";
#else
    os="uni";
#endif

    std::ofstream bulblife;
    std::ifstream conftext;
    std::ifstream in;
    std::string homepath;
    std::string userpath;
    if (os == "win")
    {
        homepath = getenv("APPDATA");
        userpath = getenv("UserProfile");
        in.open((homepath + "/npc/rooms.csv").c_str());
        conftext.open((homepath + "/npc/pass.txt").c_str());
        std::ofstream bulblife((userpath + "/Desktop/bulblife.csv").c_str());
    }
    if (os == "uni")
    {
        homepath = getenv("HOME");
        userpath = getenv("HOME");
        in.open((homepath + "/.npc/rooms.csv").c_str());
        conftext.open((homepath + "/.npc/pass.txt").c_str());
        std::ofstream bulblife((userpath + "/Desktop/bulblife.csv").c_str());
    }
    unsigned int e = 0;
    //float f = 1.1;
    std::string room;
    std::string out;
    std::string line, field;
    std::vector< std::vector<std::string> > array;
    std::vector<std::string> v;
    wxString pass = TextPass->GetValue();
    long int outn;
    std::string realpass;
    getline(conftext,realpass);
    if ( pass == realpass)
    {
        wxString room = TextRoom->GetValue();
        //TextLog->AppendText("Password Correct\n");
        while ( getline(in,line) )
        {
            v.clear();
            std::stringstream ss(line);

            while (getline(ss,field,','))
            {
                v.push_back(field);
            }
            array.push_back(v);
        }
        while (e < array.size())
        {
            out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe -t 0.2 ", array[e][1], " ", array[e][2], "-MIB::sysInfoLampHour.0");
            outn = atof(out.c_str());
            wxString outw = wxString::Format(wxT("%ld"),outn);
            if ( outn != 0)
            {
                TextLog->AppendText("The board in ");
                TextLog->AppendText(array[e][0]);
                TextLog->AppendText(" has been on for ");
                TextLog->AppendText(outw);
                TextLog->AppendText(" Hours.\n");
                bulblife.open ((userpath + "/Desktop/bulblife.csv").c_str(), std::ios_base::app);
                bulblife << array[e][0] << "," << outn << std::endl;
                bulblife.close();
            }
            if ( outn == 0)
            {
                TextLog->AppendText("The board in ");
                TextLog->AppendText(array[e][0]);
                TextLog->AppendText(" did Not respond.\n");
            }
            e++;
            wxYield();
        }
    }

    else
    {
        TextLog->AppendText("Password Incorrect.\n");
    }
    SetStatusText("Done",0);
    wxWindow::Enable(true);
}

void npcproFrame::OnAllOffButtonClick(wxCommandEvent& event)
{
    wxWindow::Enable(false);
    TextLog->AppendText("\nAll Board Shut Off\n");
    SetStatusText("Running, Please Wait",0);
    std::string GetStdoutFromCommand(std::string cmd, std::string ip, std::string space, std::string model, std::string cmd2);
    std::string systemRep(std::string cmd);
    std::string os ="unk";
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    os="win";
#else
    os="uni";
#endif

    std::ifstream conftext;
    std::ifstream in;
    std::string homepath;
    if (os == "win")
    {
        homepath = getenv("APPDATA");
        in.open((homepath + "/npc/rooms.csv").c_str());
        conftext.open((homepath + "/npc/pass.txt").c_str());
    }
    if (os == "uni")
    {
        homepath = getenv("HOME");
        in.open((homepath + "/.npc/rooms.csv").c_str());
        conftext.open((homepath + "/.npc/pass.txt").c_str());
    }
    unsigned int e = 0;
    //float f = 1.1;
    std::string room;
    std::string cmd1;
    std::string cmd2;
    std::string ip;
    std::string space = " ";
    std::string model;
    std::string out;
    std::string line, field;
    std::vector< std::vector<std::string> > array;
    std::vector<std::string> v;
    wxString pass = TextPass->GetValue();
    long int outn;
    std::string realpass;
    getline(conftext,realpass);
    if ( pass == realpass)
    {
        wxString room = TextRoom->GetValue();
        //TextLog->AppendText("Password Correct\n");
        while ( getline(in,line) )
        {
            v.clear();
            std::stringstream ss(line);

            while (getline(ss,field,','))
            {
                v.push_back(field);
            }
            array.push_back(v);
        }
        while (e < array.size())
        {


            out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe ", array[e][1], " ", array[e][2], "-MIB::powerState.0");
            outn = atof(out.c_str());
            wxString outw = wxString::Format(wxT("%ld"),outn);

            if ( outn == 2)
            {
                TextLog->AppendText("The board in ");
                TextLog->AppendText(array[e][0]);
                TextLog->AppendText(" is already Off.\n");
            }
            if ( outn == 0)
            {
                TextLog->AppendText("The board in ");
                TextLog->AppendText(array[e][0]);
                TextLog->AppendText(" did Not respond.\n");
            }
            if ( (outn != 2) & (outn != 0))
            {
                TextLog->AppendText("The board in ");
                TextLog->AppendText(array[e][0]);
                TextLog->AppendText(" is Turning Off.\n");
                cmd1 = "snmpset -v 2c -c public -O vqe -t 0.2 ";
                ip = array[e][1];
                model = array[e][2];
                cmd2 =  "-MIB::powerState.0 i 2";
                out = cmd1 + ip + space + model + cmd2;
                systemRep(out.c_str());
            }
            e++;
            wxYield();
        }
    }

    else
    {
        TextLog->AppendText("Password Incorrect.\n");
    }
    SetStatusText("Done",0);
    wxWindow::Enable(true);
}

void npcproFrame::OnUnEBroadButtonClick(wxCommandEvent& event)
{
    wxWindow::Enable(false);
    TextLog->AppendText("\nAll Board Emergency Broadcast Un-set\n");
    SetStatusText("Running, Please Wait",0);
    std::string GetStdoutFromCommand(std::string cmd, std::string ip, std::string space, std::string model, std::string cmd2);
    std::string systemRep(std::string cmd);
    std::string os ="unk";
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    os="win";
#else
    os="uni";
#endif

    std::ifstream conftext;
    std::ifstream in;
    std::string homepath;
    if (os == "win")
    {
        homepath = getenv("APPDATA");
        in.open((homepath + "/npc/rooms.csv").c_str());
        conftext.open((homepath + "/npc/pass.txt").c_str());
    }
    if (os == "uni")
    {
        homepath = getenv("HOME");
        in.open((homepath + "/.npc/rooms.csv").c_str());
        conftext.open((homepath + "/.npc/pass.txt").c_str());
    }
    unsigned int e = 0;
    //float f = 1.1;
    std::string room;
    std::string cmd1;
    std::string cmd2;
    std::string ip;
    std::string on;
    std::string out;
    std::string space = " ";
    std::string model;
    std::string line, field;
    std::vector< std::vector<std::string> > array;
    std::vector<std::string> v;
    wxString pass = TextPass->GetValue();
    //long int outn;
    std::string realpass;
    getline(conftext,realpass);
    if ( pass == realpass)
    {
        wxString room = TextRoom->GetValue();
        //TextLog->AppendText("Password Correct\n");
        while ( getline(in,line) )
        {
            v.clear();
            std::stringstream ss(line);

            while (getline(ss,field,','))
            {
                v.push_back(field);
            }
            array.push_back(v);
        }
        while (e < array.size())
        {
            cmd1 = "snmpset -v 2c -c public -t 0.5 ";
            space = " ";
            model = array[e][2];
            cmd2 = "-MIB::emergencyDisplay.0 i 2";
            ip = array[e][1];
            on = cmd1 + ip + space + model + cmd2;
            systemRep(on.c_str());
            e++;
            wxYield();
        }
        TextLog->AppendText("The boards have been Set.\n");
    }

    else
    {
        TextLog->AppendText("Password Incorrect.\n");
    }
    SetStatusText("Done",0);
    wxWindow::Enable(true);
}
