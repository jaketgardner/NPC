/***************************************************************
 * Name:      npcproAllAdv.cpp
 * Purpose:   Contains All Advanced Menu Functions
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


void npcproFrame::OnAdvancedChoiceAllSelected(wxCommandEvent& event)
{
    std::string systemRep(std::string cmd);
    wxString wout = AdvancedChoiceAll->GetStringSelection();
    int outi = AdvancedChoiceAll->GetCurrentSelection();

    if (outi == 1) //Service Failure Status
    {
        TextLog->AppendText("\nAll Board Service Failure Check\n");
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


                out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe ", array[e][1], " ", array[e][2], "-MIB::serviceFailureLog.0");
                outn = atof(out.c_str());
                wxString outw = wxString::Format(wxT("%ld"),outn);
                if ( outn == 1)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" returns Normal.\n");
                }
                if ( outn == 2)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" returns OverTemp.\n");
                }
                if ( outn == 3)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" returns FanLock.\n");
                }
                if ( outn == 4)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" returns FanCW.\n");
                }
                if ( outn == 5)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" returns FanBlower.\n");
                }
                if ( outn == 6)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" returns FanSystem.\n");
                }
                if ( outn == 7)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" returns LampError.\n");
                }
                if ( outn == 8)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" returns ColorWheelBreak.\n");
                }
                if ( outn == 9)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" returns LampOverheat.\n");
                }
                if ( outn == 10)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" returns LampDriver.\n");
                }
                if ( outn == 11)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" returns LampOverHours.\n");
                }
                if ( outn == 12)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" returns LampIgniteError.\n");
                }
                if ( outn == 0)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
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
    }
    if (outi == 2) //Get Any Value
    {
        TextLog->AppendText("\nAll Board Value Check\n");
        SetStatusText("Running, Please Wait",0);
        int msleep(unsigned long milisec, std::string os);
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
        std::string message = "powerState";
        std::string messout;
        std::string line, field;
        std::vector< std::vector<std::string> > array;
        std::vector<std::string> v;
        wxString pass = TextPass->GetValue();
        //long int outn;
        std::string realpass;
        getline(conftext,realpass);
        if ( pass == realpass)
        {
            //TextLog->AppendText("Password Correct\n");
            wxTextEntryDialog TextEntryDialog1(this, _("Variable: "), _("Message Input Panel"), _("powerState"));
            if ( TextEntryDialog1.ShowModal() == wxID_OK )
            {
                message = TextEntryDialog1.GetValue();
                TextLog->AppendText("Variable '");
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
                messout = "-MIB::" + message + ".0";
                out = GetStdoutFromCommand("snmpget -v 2c -c public ", array[e][1], " ", array[e][2], messout);
                if (out.find("No log handling") != std::string::npos)
                {
                    TextLog->AppendText("Bad variable received.\n");
                }
                if (out.find("No log handling") == std::string::npos)
                {
                    if (out.find("Timeout") != std::string::npos)
                    {
                        TextLog->AppendText("The board in ");
                        TextLog->AppendText(array[e][0]);
                        TextLog->AppendText(" did Not respond\n");
                    }
                    if (out.find("Timeout") == std::string::npos)
                    {
                        TextLog->AppendText(message);
                        TextLog->AppendText(" on ");
                        TextLog->AppendText(array[e][0]);
                        TextLog->AppendText(" Returns-> ");
                        TextLog->AppendText(out);
                        //TextLog->AppendText("\n");
                    }
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
    }
    if (outi == 3) //Serial Number
    {
        TextLog->AppendText("\nAll Board Serial Number to CSV\n");
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
            std::ofstream bulblife((userpath + "/Desktop/serialnum.csv").c_str());
        }
        if (os == "uni")
        {
            homepath = getenv("HOME");
            userpath = getenv("HOME");
            in.open((homepath + "/.npc/rooms.csv").c_str());
            conftext.open((homepath + "/.npc/pass.txt").c_str());
            std::ofstream bulblife((userpath + "/Desktop/serialnum.csv").c_str());
        }
        unsigned int e = 0;
        //float f = 1.1;
        std::string room;
        std::string out;
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
                out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe ", array[e][1], " ", array[e][2], "-MIB::sysInfoSerialNumber.0");
                if (out.find("Timeout") != std::string::npos)
                {
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" did Not respond\n");
                }
                if (out.find("Timeout") == std::string::npos)
                {
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" has serial number ");
                    TextLog->AppendText(out);
                    //TextLog->AppendText("\n");
                    bulblife.open ((userpath + "/Desktop/serialnum.csv").c_str(), std::ios_base::app);
                    bulblife << array[e][0] << "," << array[e][2] << "," << out;
                    bulblife.close();
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
    }
    if (outi == 4) //Set Projector IDs from CSV file
    {
        TextLog->AppendText("\nAll Board Projector ID Set\n");
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
        std::string cmd1;
        std::string cmd2;
        std::string ip;
        std::string on;
        std::string out;
        long int outn;
        std::string space = " ";
        std::string model;
        std::string id;
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
                cmd2 = "-MIB::sysProjectorID.0 i ";
                id = array[e][3];
                ip = array[e][1];
                TextLog->AppendText("Setting ");
                TextLog->AppendText(array[e][0]);
                TextLog->AppendText(" to ");
                TextLog->AppendText(array[e][3]);
                TextLog->AppendText(".\n");
                on = cmd2 + id;
                out = GetStdoutFromCommand(cmd1, ip, space, model, on);
                outn = atof(out.c_str());
                if ( outn == 0)
                {
                    //TextLog->AppendText("Status code ");
                    //TextLog->AppendText(outw);
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
    }
    if (outi == 5) //Mute On
    {
        TextLog->AppendText("\nAll Board Mute On Set\n");
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


                out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe ", array[e][1], " ", array[e][2], "-MIB::audioMute.0");
                outn = atof(out.c_str());
                wxString outw = wxString::Format(wxT("%ld"),outn);

                if ( outn == 2)
                {
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" is muted.\n");
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
                    TextLog->AppendText(" is Muting.\n");
                    cmd1 = "snmpset -v 2c -c public -O vqe -t 0.2 ";
                    ip = array[e][1];
                    model = array[e][2];
                    cmd2 =  "-MIB::audioMute.0 i 2";
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
    }
    if (outi == 6) //Mute Off
    {
        TextLog->AppendText("\nAll Board Mute Off Set\n");
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


                out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe ", array[e][1], " ", array[e][2], "-MIB::audioMute.0");
                outn = atof(out.c_str());
                wxString outw = wxString::Format(wxT("%ld"),outn);

                if ( outn == 1)
                {
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" is not muted.\n");
                }
                if ( outn == 0)
                {
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" did Not respond.\n");
                }
                if ( (outn != 1) & (outn != 0))
                {
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" is Un-Muting.\n");
                    cmd1 = "snmpset -v 2c -c public -O vqe -t 0.2 ";
                    ip = array[e][1];
                    model = array[e][2];
                    cmd2 =  "-MIB::audioMute.0 i 1";
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
    }
    if (outi == 7) //Autosignal
    {
        TextLog->AppendText("\nAll Board AutoSignal Set\n");
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


                out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe ", array[e][1], " ", array[e][2], "-MIB::sysAutoSignal.0");
                outn = atof(out.c_str());
                wxString outw = wxString::Format(wxT("%ld"),outn);

                if ( outn == 1)
                {
                    ;
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" has AutoSignal On.\n");
                }
                if ( outn == 0)
                {
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" did Not respond.\n");
                }
                if ( (outn != 1) & (outn != 0))
                {
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" is Setting AutoSignal.\n");
                    cmd1 = "snmpset -v 2c -c public -O vqe -t 0.2 ";
                    ip = array[e][1];
                    model = array[e][2];
                    cmd2 =  "-MIB::sysAutoSignal.0 i 1";
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
    }
    if (outi == 8) //input Select
    {
        TextLog->AppendText("\nAll Board Input Set\n");
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
        std::string cmd1;
        std::string cmd2;
        std::string ip;
        std::string space = " ";
        std::string model;
        std::string out;
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


                out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe ", array[e][1], " ", array[e][2], "-MIB::inputSource.0");
                outn = atof(out.c_str());
                wxString outw = wxString::Format(wxT("%ld"),outn);
                long int messagen = atof(message.c_str());
                if ( outn == messagen)
                {
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" is already set.\n");
                }
                if ( outn == 0)
                {
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" did Not respond.\n");
                }
                if ( (outn != 1) & (outn != 0))
                {
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" is Setting Input.\n");
                    cmd1 = "snmpset -v 2c -c public -O vqe -t 0.2 ";
                    ip = array[e][1];
                    model = array[e][2];
                    std::cout << message << std::endl;
                    cmd2 =  "-MIB::inputSource.0 i " + message;
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
    }
    if (outi == 9) //Power Off Time
    {
        TextLog->AppendText("\nAll Board auto Power Off Time Set\n");
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
        std::string cmd1;
        std::string cmd2;
        std::string ip;
        std::string space = " ";
        std::string model;
        std::string out;
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
            wxTextEntryDialog TextEntryDialog1(this, _("Time in Minutes: "), _("Input Number Panel"), _("60"));
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


                out = GetStdoutFromCommand("snmpget -v 2c -c public -O tvqe ", array[e][1], " ", array[e][2], "-MIB::sysAutoPowerOff.0");
                outn = atof(out.c_str());
                wxString outw = wxString::Format(wxT("%ld"),outn);
                long int messagen = atof(message.c_str());
                if ( outn == messagen)
                {
                    ;
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" is already set.\n");
                }
                if ( outn == 0)
                {
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" did Not respond.\n");
                }
                if ( (outn != 1) & (outn != 0))
                {
                    TextLog->AppendText("The board in ");
                    TextLog->AppendText(array[e][0]);
                    TextLog->AppendText(" is Setting Time.\n");
                    cmd1 = "snmpset -v 2c -c public -O vqe -t 0.2 ";
                    ip = array[e][1];
                    model = array[e][2];
                    cmd2 =  "-MIB::sysAutoPowerOff.0 i " + message;
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
    }
}

