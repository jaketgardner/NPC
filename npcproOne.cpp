/***************************************************************
 * Name:      npcproOneAdv.cpp
 * Purpose:   Contains One Board Functions
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


void npcproFrame::OnOneStatButtonClick(wxCommandEvent& event)
{
    SetStatusText("Running, Please Wait",0);
    TextLog->AppendText("\nOne Board Status Check\n");
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
    float f = 1.1;
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
        //TextLog->AppendText("Password Correct\n");
        wxString room = TextRoom->GetValue();
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
            if (array[e][0] == room)
            {
                f = e;
            }
            e++;
        }
        e=0;

        if (f == 1.1f)
        {
            TextLog->AppendText("The room number does Not exist.\n");
        }
        if (f != 1.1f)
        {
            out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe ", array[f][1], " ", array[f][2], "-MIB::powerState.0");
            outn = atof(out.c_str());
            wxString outw = wxString::Format(wxT("%ld"),outn);
            if ( outn == 1)
            {
                //TextLog->AppendText("Status code ");
                //TextLog->AppendText(outw);
                TextLog->AppendText("The board is On.\n");
            }
            if ( outn == 2)
            {
                //TextLog->AppendText("Status code ");
                //TextLog->AppendText(outw);
                TextLog->AppendText("The board is Off.\n");
            }
            if ( outn == 3)
            {
                //TextLog->AppendText("Status code ");
                //TextLog->AppendText(outw);
                TextLog->AppendText("The board is Powering On.\n");
            }
            if ( outn == 4)
            {
                //TextLog->AppendText("Status code ");
                //TextLog->AppendText(outw);
                TextLog->AppendText("The board is in Cooling State.\n");
            }
            if ( outn == 5)
            {
                //TextLog->AppendText("Status code ");
                //TextLog->AppendText(outw);
                TextLog->AppendText("The board is in Confirm Off State.\n");
            }
            if ( outn == 0)
            {
                //TextLog->AppendText("Status code ");
                //TextLog->AppendText(outw);
                TextLog->AppendText("The board did Not respond.\n");
            }
        }
    }

    else
    {
        TextLog->AppendText("Password Incorrect.\n");
    }
    SetStatusText("Done",0);
}

void npcproFrame::OnOneBulbButtonClick(wxCommandEvent& event)
{
    TextLog->AppendText("\nOne Board Bulb Life Check\n");
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
    float f = 1.1;
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
            if (array[e][0] == room)
            {
                f = e;
            }
            e++;
        }
        e=0;

        if (f == 1.1f)
        {
            TextLog->AppendText("The room number does Not exist.\n");
        }
        if (f != 1.1f)
        {
            out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe ", array[f][1], " ", array[f][2], "-MIB::sysInfoLampHour.0");
            outn = atof(out.c_str());
            wxString outw = wxString::Format(wxT("%ld"),outn);
            if (outn == 0)
                TextLog->AppendText("The board did Not respond.\n");
            if(outn != 0)
            {
                TextLog->AppendText("This Bulb has been On for ");
                TextLog->AppendText(outw);
                TextLog->AppendText(" Hours.\n");
            }
        }
    }

    else
    {
        TextLog->AppendText("Password Incorrect.\n");
    }
    SetStatusText("Done",0);
}

void npcproFrame::OnOneOffButtonClick(wxCommandEvent& event)
{
    TextLog->AppendText("\nOne Board Shut Off\n");
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
    float f = 1.1;
    std::string room;
    std::string cmd1;
    std::string cmd2;
    std::string ip;
    std::string out;
    std::string space = " ";
    std::string model;
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
            if (array[e][0] == room)
            {
                f = e;
            }
            e++;
        }
        e=0;

        if (f == 1.1f)
        {
            TextLog->AppendText("The room number does Not exist.\n");
        }
        if (f != 1.1f)
        {
            out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe ", array[f][1], " ", array[f][2], "-MIB::powerState.0");
            outn = atof(out.c_str());
            wxString outw = wxString::Format(wxT("%ld"),outn);
            if ( (outn != 2) & (outn != 0))
            {
                cmd1 = "snmpset -v 2c -c public -O vqe ";
                ip = array[f][1];
                model = array[f][2];
                cmd2 =  "-MIB::powerState.0 i 2";
                out = cmd1 + ip + space + model + cmd2;
                TextLog->AppendText("The board is Shutting Off.\n");
                systemRep(out.c_str());
            }
            if (outn == 2)
                TextLog->AppendText("The board is already Off.\n");
            if (outn == 0)
                TextLog->AppendText("The board did Not respond.\n");
        }
    }

    else
    {
        TextLog->AppendText("Password Incorrect.\n");
    }
    SetStatusText("Done",0);
}
