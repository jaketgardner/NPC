/***************************************************************
 * Name:      npcproOneAdv.cpp
 * Purpose:   Contains One Advanced Menu Functions
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

void npcproFrame::OnAdvancedChoiceSelected(wxCommandEvent& event) //One Advanced
{
    std::string systemRep(std::string cmd);
    wxString wout = AdvancedChoice->GetStringSelection();
    int outi = AdvancedChoice->GetCurrentSelection();

    if (outi == 1) //Service Failure Status
    {
        TextLog->AppendText("\nOne Board Service Failure Check\n");
        SetStatusText("Running - Do NOT Touch ANYTHING",0);
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
                out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe ", array[f][1], " ", array[f][2], "-MIB::serviceFailureLog.0");
                outn = atof(out.c_str());
                wxString outw = wxString::Format(wxT("%ld"),outn);
                if ( outn == 1)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[f][0]);
                    TextLog->AppendText(" returns Normal.\n");
                }
                if ( outn == 2)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[f][0]);
                    TextLog->AppendText(" returns OverTemp.\n");
                }
                if ( outn == 3)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[f][0]);
                    TextLog->AppendText(" returns FanLock.\n");
                }
                if ( outn == 4)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[f][0]);
                    TextLog->AppendText(" returns FanCW.\n");
                }
                if ( outn == 5)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[f][0]);
                    TextLog->AppendText(" returns FanBlower.\n");
                }
                if ( outn == 6)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[f][0]);
                    TextLog->AppendText(" returns FanSystem.\n");
                }
                if ( outn == 7)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[f][0]);
                    TextLog->AppendText(" returns LampError.\n");
                }
                if ( outn == 8)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[f][0]);
                    TextLog->AppendText(" returns ColorWheelBreak.\n");
                }
                if ( outn == 9)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[f][0]);
                    TextLog->AppendText(" returns LampOverheat.\n");
                }
                if ( outn == 10)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[f][0]);
                    TextLog->AppendText(" returns LampDriver.\n");
                }
                if ( outn == 11)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[f][0]);
                    TextLog->AppendText(" returns LampOverHours.\n");
                }
                if ( outn == 12)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[f][0]);
                    TextLog->AppendText(" returns LampIgniteError.\n");
                }
                if ( outn == 0)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[f][0]);
                    TextLog->AppendText(" did Not respond.\n");
                }
            }
        }

        else
        {
            TextLog->AppendText("Password Incorrect.\n");
        }
        SetStatusText("Done",0);
    }
    if (outi == 2) //Get any Value
    {
        TextLog->AppendText("\nOne Board Get any Value\n");
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
        std::string cmd1;
        std::string cmd2;
        std::string ip;
        std::string ids = "1";
        wxString id = "1";
        std::string out;
        std::string space = " ";
        std::string model;
        std::string idout;
        std::string line, field;
        std::vector< std::vector<std::string> > array;
        std::vector<std::string> v;
        wxString pass = TextPass->GetValue();
        //long int outn;
        std::string realpass;
        getline(conftext,realpass);
        if ( pass == realpass)
        {
            wxTextEntryDialog TextEntryDialog1(this, _("Variable: "), _("Variable Input Panel"), _("powerState"));
            //ids = std::string(id.mb_str());
            wxString room = TextRoom->GetValue();
            if ( TextEntryDialog1.ShowModal() == wxID_OK )
            {
                id = TextEntryDialog1.GetValue();
                TextLog->AppendText("Variable '");
                TextLog->AppendText(id);
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
                idout = "-MIB::" + id + ".0";
                out = GetStdoutFromCommand("snmpget -v 2c -c public ", array[f][1], " ", array[f][2], idout);
                if (out.find("No log handling") != std::string::npos)
                {
                    TextLog->AppendText("Bad variable received.\n");
                }
                if (out.find("No log handling") == std::string::npos)
                {
                    if (out.find("Timeout") != std::string::npos)
                    {
                        TextLog->AppendText("The board in ");
                        TextLog->AppendText(array[f][0]);
                        TextLog->AppendText(" did Not respond\n");
                    }
                    if (out.find("Timeout") == std::string::npos)
                    {
                        TextLog->AppendText(id);
                        TextLog->AppendText(" on ");
                        TextLog->AppendText(array[f][0]);
                        TextLog->AppendText(" Returns-> ");
                        TextLog->AppendText(out);
                        TextLog->AppendText("\n");
                    }
                }
            }
        }


        else
        {
            TextLog->AppendText("Password Incorrect.\n");
        }
        SetStatusText("Done",0);
    }
    if (outi == 3) //Set any Value
    {
        TextLog->AppendText("\nOne Board Set any Value\n");
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
        std::string cmd1;
        std::string cmd2;
        std::string message;
        std::string messout;
        std::string ip;
        std::string ids = "1";
        wxString id = "1";
        std::string out;
        std::string space = " ";
        std::string model;
        std::string value;
        std::string line, field;
        std::vector< std::vector<std::string> > array;
        std::vector<std::string> v;
        wxString pass = TextPass->GetValue();
        //long int outn;
        std::string realpass;
        getline(conftext,realpass);
        if ( pass == realpass)
        {
            //ids = std::string(id.mb_str());
            wxString room = TextRoom->GetValue();
            wxTextEntryDialog TextEntryDialog2(this, _("Variable: "), _("Message Input Panel"), _("powerState"));
            if ( TextEntryDialog2.ShowModal() == wxID_OK )
            {
                message = TextEntryDialog2.GetValue();
                TextLog->AppendText("Variable '");
                TextLog->AppendText(message);
                TextLog->AppendText("' set.\n");
            }
            wxTextEntryDialog TextEntryDialog3(this, _("Value: "), _("Message Input Panel"), _("i 1"));
            if ( TextEntryDialog3.ShowModal() == wxID_OK )
            {
                value = TextEntryDialog3.GetValue();
                TextLog->AppendText("Variable '");
                TextLog->AppendText(value);
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
                messout = "-MIB::" + message + ".0 " + value;
                out = GetStdoutFromCommand("snmpset -v 2c -c public ", array[f][1], " ", array[f][2], messout);
                if (out.find("No log handling") != std::string::npos)
                {
                    TextLog->AppendText("Bad variable received.\n");
                }
                if (out.find("No log handling") == std::string::npos)
                {
                    if (out.find("Timeout") != std::string::npos)
                    {
                        TextLog->AppendText("The board in ");
                        TextLog->AppendText(array[f][0]);
                        TextLog->AppendText(" did Not respond\n");
                    }
                    if (out.find("Timeout") == std::string::npos)
                    {
                        TextLog->AppendText(message);
                        TextLog->AppendText(" on ");
                        TextLog->AppendText(array[f][0]);
                        TextLog->AppendText(" Returns-> ");
                        TextLog->AppendText(out);
                        TextLog->AppendText("\n");
                    }
                }
            }
        }


        else
        {
            TextLog->AppendText("Password Incorrect.\n");
        }
        SetStatusText("Done",0);
    }
    if (outi == 4) //Serial Number to Log
    {
        TextLog->AppendText("\nOne Board Get Serial Number\n");
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
                out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe ", array[f][1], " ", array[f][2], "-MIB::sysInfoSerialNumber.0");
                if (out.find("Timeout") != std::string::npos)
                {
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[f][0]);
                    TextLog->AppendText(" did Not respond\n");
                }
                if (out.find("Timeout") == std::string::npos)
                {
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[f][0]);
                    TextLog->AppendText(" has serial number ");
                    TextLog->AppendText(out);
                    //TextLog->AppendText(".\n");
                }
            }
        }
        else
        {
            TextLog->AppendText("Password Incorrect.\n");
        }
        SetStatusText("Done",0);
    }
    if (outi == 5) //Set Projector ID
    {
        TextLog->AppendText("\nOne Board Set Projector ID\n");
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
        std::string cmd1;
        std::string cmd2;
        std::string ip;
        std::string ids = "1";
        wxString id = "1";
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
            wxTextEntryDialog TextEntryDialog1(this, _("ID: "), _("ID Input Panel"), _("1"));
            if ( TextEntryDialog1.ShowModal() == wxID_OK )
            {
                ids = TextEntryDialog1.GetValue();
                id = TextEntryDialog1.GetValue();
            }
            //ids = std::string(id.mb_str());
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
                cmd1 = "snmpset -v 2c -c public -O vqe ";
                ip = array[f][1];
                model = array[f][2];
                cmd2 =  "-MIB::sysProjectorID.0 i ";
                out = cmd1 + ip + space + model + cmd2 + ids;
                //std::cout << out << std::endl;
                TextLog->AppendText("Setting ID.\n");
                systemRep(out.c_str());
            }
        }


        else
        {
            TextLog->AppendText("Password Incorrect.\n");
        }
        SetStatusText("Done",0);
    }
    if (outi == 6) //Mute On
    {
            TextLog->AppendText("\nOne Board Mute On Set\n");
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
                    out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe ", array[f][1], " ", array[f][2], "-MIB::audioMute.0");
                    outn = atof(out.c_str());
                    wxString outw = wxString::Format(wxT("%ld"),outn);
                    if ( outn == 2)
                    {
                        TextLog->AppendText("The board in ");
                        TextLog->AppendText(array[f][0]);
                        TextLog->AppendText(" is muted.\n");
                    }
                    if ( outn == 0)
                    {
                        TextLog->AppendText("The board in ");
                        TextLog->AppendText(array[f][0]);
                        TextLog->AppendText(" did Not respond.\n");
                    }
                    if ( (outn != 2) & (outn != 0))
                    {
                        TextLog->AppendText("The board in ");
                        TextLog->AppendText(array[f][0]);
                        TextLog->AppendText(" is Muting.\n");
                        cmd1 = "snmpset -v 2c -c public -O vqe -t 0.2 ";
                        ip = array[e][1];
                        model = array[e][2];
                        cmd2 =  "-MIB::audioMute.0 i 2";
                        out = cmd1 + ip + space + model + cmd2;
                        systemRep(out.c_str());
                    }
                }
            }

            else
            {
                TextLog->AppendText("Password Incorrect.\n");
            }
            SetStatusText("Done",0);
        }
    if (outi == 7) //Mute Off
    {
            TextLog->AppendText("\nOne Board Mute Off Set\n");
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
                    out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe ", array[f][1], " ", array[f][2], "-MIB::audioMute.0");
                    outn = atof(out.c_str());
                    wxString outw = wxString::Format(wxT("%ld"),outn);
                    if ( outn == 1)
                    {
                        TextLog->AppendText("The board in ");
                        TextLog->AppendText(array[f][0]);
                        TextLog->AppendText(" is not muted.\n");
                    }
                    if ( outn == 0)
                    {
                        TextLog->AppendText("The board in ");
                        TextLog->AppendText(array[f][0]);
                        TextLog->AppendText(" did Not respond.\n");
                    }
                    if ( (outn != 1) & (outn != 0))
                    {
                        TextLog->AppendText("The board in ");
                        TextLog->AppendText(array[f][0]);
                        TextLog->AppendText(" is Un-Muting.\n");
                        cmd1 = "snmpset -v 2c -c public -O vqe -t 0.2 ";
                        ip = array[e][1];
                        model = array[e][2];
                        cmd2 =  "-MIB::audioMute.0 i 1";
                        out = cmd1 + ip + space + model + cmd2;
                        systemRep(out.c_str());
                    }
                }
            }

            else
            {
                TextLog->AppendText("Password Incorrect.\n");
            }
            SetStatusText("Done",0);
        }
    if (outi == 8) //Auto Signal Enable
    {

            TextLog->AppendText("\nOne Board Auto Signal On Set\n");
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
                    out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe ", array[f][1], " ", array[f][2], "-MIB::sysAutoSignal.0");
                    outn = atof(out.c_str());
                    wxString outw = wxString::Format(wxT("%ld"),outn);
                    if ( outn == 1)
                    {
                        ;
                        TextLog->AppendText("The board in ");
                        TextLog->AppendText(array[f][0]);
                        TextLog->AppendText(" has AutoSignal On.\n");
                    }
                    if ( outn == 0)
                    {
                        TextLog->AppendText("The board in ");
                        TextLog->AppendText(array[f][0]);
                        TextLog->AppendText(" did Not respond.\n");
                    }
                    if ( (outn != 1) & (outn != 0))
                    {
                        TextLog->AppendText("The board in ");
                        TextLog->AppendText(array[f][0]);
                        TextLog->AppendText(" is Setting AutoSignal.\n");
                        cmd1 = "snmpset -v 2c -c public -O vqe -t 0.2 ";
                        ip = array[f][1];
                        model = array[f][2];
                        cmd2 =  "-MIB::sysAutoSignal.0 i 1";
                        out = cmd1 + ip + space + model + cmd2;
                        systemRep(out.c_str());
                    }
                }
            }

            else
            {
                TextLog->AppendText("Password Incorrect.\n");
            }
            SetStatusText("Done",0);
        }
    if (outi == 9) //Input Select
    {
            TextLog->AppendText("\nOne Board Auto Signal On Set\n");
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
            std::string message;
            std::string line, field;
            std::vector< std::vector<std::string> > array;
            std::vector<std::string> v;
            wxString pass = TextPass->GetValue();
            long int outn;
            std::string realpass;
            getline(conftext,realpass);
            if ( pass == realpass)
            {
            wxTextEntryDialog TextEntryDialog1(this, _("Number (from manual): "), _("Input Number Panel"), _("1"));
            if ( TextEntryDialog1.ShowModal() == wxID_OK )
            {
                message = TextEntryDialog1.GetValue();
                TextLog->AppendText("Variable '");
                TextLog->AppendText(message);
                TextLog->AppendText("' set.\n");
            }
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
                    out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe ", array[f][1], " ", array[f][2], "-MIB::inputSource.0");
                    outn = atof(out.c_str());
                    wxString outw = wxString::Format(wxT("%ld"),outn);
                    long int messagen = atof(message.c_str());
                if ( outn == messagen)
                {
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[f][0]);
                    TextLog->AppendText(" is already set.\n");
                }
                if ( outn == 0)
                {
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[f][0]);
                    TextLog->AppendText(" did Not respond.\n");
                }
                if ( (outn != 1) & (outn == 0))
                {
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[f][0]);
                    TextLog->AppendText(" is Setting Input.\n");
                    cmd1 = "snmpset -v 2c -c public -O vqe -t 0.2 ";
                    ip = array[f][1];
                    model = array[f][2];
                    cmd2 =  "-MIB::inputSource.0 i " + message;
                    out = cmd1 + ip + space + model + cmd2;
                    systemRep(out.c_str());
                }
                }
            }

            else
            {
                TextLog->AppendText("Password Incorrect.\n");
            }
            SetStatusText("Done",0);
        }
    if (outi == 10) //Powerdown time
        {

            TextLog->AppendText("\nOne Board Auto Signal On Set\n");
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
            std::string cm1;
            std::string ip;
            std::string out;
            std::string space = " ";
            std::string model;
            std::string message;
            std::string line, field;
            std::vector< std::vector<std::string> > array;
            std::vector<std::string> v;
            wxString pass = TextPass->GetValue();
            long int outn;
            std::string realpass;
            getline(conftext,realpass);
            if ( pass == realpass)
            {
            wxTextEntryDialog TextEntryDialog1(this, _("Time in minutes: "), _("Input Number Panel"), _("1"));
            if ( TextEntryDialog1.ShowModal() == wxID_OK )
            {
                message = TextEntryDialog1.GetValue();
                TextLog->AppendText("Variable '");
                TextLog->AppendText(message);
                TextLog->AppendText("' set.\n");
            }
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
                    out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe ", array[f][1], " ", array[f][2], "-MIB::sysAutoPowerOff.0");
                    outn = atof(out.c_str());
                    wxString outw = wxString::Format(wxT("%ld"),outn);
                    if ( outn == 0)
                    {
                        TextLog->AppendText("The board in ");
                        TextLog->AppendText(array[f][0]);
                        TextLog->AppendText(" did Not respond.\n");
                    }
                    if (outn != 0)
                    {
                        TextLog->AppendText("The board in ");
                        TextLog->AppendText(array[f][0]);
                        TextLog->AppendText(" is Setting.\n");
                        cmd1 = "snmpset -v 2c -c public -O vqe -t 0.2 ";
                        ip = array[f][1];
                        model = array[f][2];
                        cm1 =  "-MIB::sysAutoPowerOff.0 i ";
                        cmd2 = cm1 + message;
                        out = cmd1 + ip + space + model + cmd2;
                        systemRep(out.c_str());
                    }
                }
            }

            else
            {
                TextLog->AppendText("Password Incorrect.\n");
            }
            SetStatusText("Done",0);
        }
}
