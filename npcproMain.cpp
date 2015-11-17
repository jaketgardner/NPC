/***************************************************************
 * Name:      npcproMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Jake Gardner (gardnertechllc+jake@gmail.com)
 * Created:   2014-07-02
 * Copyright: Jake Gardner (gardnertechllc+jake@gmail.com)
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
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

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

//(*IdInit(npcproFrame)
const long npcproFrame::ID_TEXTCTRL1 = wxNewId();
const long npcproFrame::ID_TEXTCTRL2 = wxNewId();
const long npcproFrame::ID_BUTTON1 = wxNewId();
const long npcproFrame::ID_STATICTEXT1 = wxNewId();
const long npcproFrame::ID_STATICTEXT2 = wxNewId();
const long npcproFrame::ID_STATICTEXT3 = wxNewId();
const long npcproFrame::ID_BUTTON2 = wxNewId();
const long npcproFrame::ID_BUTTON3 = wxNewId();
const long npcproFrame::ID_BUTTON4 = wxNewId();
const long npcproFrame::ID_BUTTON5 = wxNewId();
const long npcproFrame::ID_BUTTON6 = wxNewId();
const long npcproFrame::ID_BUTTON7 = wxNewId();
const long npcproFrame::ID_BUTTON8 = wxNewId();
const long npcproFrame::ID_BUTTON9 = wxNewId();
const long npcproFrame::ID_COMBOBOX1 = wxNewId();
const long npcproFrame::ID_COMBOBOX2 = wxNewId();
const long npcproFrame::ID_BUTTON10 = wxNewId();
const long npcproFrame::ID_TEXTCTRL3 = wxNewId();
const long npcproFrame::ID_TEXTENTRYDIALOG1 = wxNewId();
const long npcproFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(npcproFrame,wxFrame)
    //(*EventTable(npcproFrame)
    //*)
END_EVENT_TABLE()

npcproFrame::npcproFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(npcproFrame)
    wxGridBagSizer* GridBagSizer1;

    Create(parent, wxID_ANY, _("Networked Projector Control"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_WARNING")),wxART_FRAME_ICON));
    	SetIcon(FrameIcon);
    }
    GridBagSizer1 = new wxGridBagSizer(0, 0);
    TextPass = new wxTextCtrl(this, ID_TEXTCTRL1, _("password"), wxDefaultPosition, wxSize(120,25), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    wxFont TextPassFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !TextPassFont.Ok() ) TextPassFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    TextPassFont.SetPointSize(8);
    TextPass->SetFont(TextPassFont);
    GridBagSizer1->Add(TextPass, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextRoom = new wxTextCtrl(this, ID_TEXTCTRL2, _("Room #"), wxDefaultPosition, wxSize(120,25), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    wxFont TextRoomFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !TextRoomFont.Ok() ) TextRoomFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    TextRoomFont.SetPointSize(8);
    TextRoom->SetFont(TextRoomFont);
    GridBagSizer1->Add(TextRoom, wxGBPosition(3, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    CheckPass = new wxButton(this, ID_BUTTON1, _("Check"), wxDefaultPosition, wxSize(120,25), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    CheckPass->SetDefault();
    wxFont CheckPassFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !CheckPassFont.Ok() ) CheckPassFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    CheckPassFont.SetPointSize(8);
    CheckPass->SetFont(CheckPassFont);
    GridBagSizer1->Add(CheckPass, wxGBPosition(1, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Networked Projector Control Pro 0.1"), wxDefaultPosition, wxSize(250,25), 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !StaticText1Font.Ok() ) StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText1Font.SetPointSize(11);
    StaticText1->SetFont(StaticText1Font);
    GridBagSizer1->Add(StaticText1, wxGBPosition(0, 0), wxGBSpan(1, 2), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("  One Board Config"), wxDefaultPosition, wxSize(120,15), 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !StaticText2Font.Ok() ) StaticText2Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText2Font.SetPointSize(8);
    StaticText2->SetFont(StaticText2Font);
    GridBagSizer1->Add(StaticText2, wxGBPosition(2, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("    All Board Config"), wxDefaultPosition, wxSize(120,15), 0, _T("ID_STATICTEXT3"));
    wxFont StaticText3Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !StaticText3Font.Ok() ) StaticText3Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText3Font.SetPointSize(8);
    StaticText3->SetFont(StaticText3Font);
    GridBagSizer1->Add(StaticText3, wxGBPosition(2, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    OneStatButton = new wxButton(this, ID_BUTTON2, _("Board Status"), wxDefaultPosition, wxSize(120,25), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    wxFont OneStatButtonFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !OneStatButtonFont.Ok() ) OneStatButtonFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    OneStatButtonFont.SetPointSize(8);
    OneStatButton->SetFont(OneStatButtonFont);
    GridBagSizer1->Add(OneStatButton, wxGBPosition(4, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    OneBulbButton = new wxButton(this, ID_BUTTON3, _("Board Bulb Life"), wxDefaultPosition, wxSize(120,25), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    wxFont OneBulbButtonFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !OneBulbButtonFont.Ok() ) OneBulbButtonFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    OneBulbButtonFont.SetPointSize(8);
    OneBulbButton->SetFont(OneBulbButtonFont);
    GridBagSizer1->Add(OneBulbButton, wxGBPosition(5, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    OneOffButton = new wxButton(this, ID_BUTTON4, _("Board Off"), wxDefaultPosition, wxSize(120,25), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    wxFont OneOffButtonFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !OneOffButtonFont.Ok() ) OneOffButtonFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    OneOffButtonFont.SetPointSize(8);
    OneOffButton->SetFont(OneOffButtonFont);
    GridBagSizer1->Add(OneOffButton, wxGBPosition(6, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    EBroadButton = new wxButton(this, ID_BUTTON5, _("Emergency Broadcast"), wxDefaultPosition, wxSize(120,25), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    EBroadButton->SetForegroundColour(wxColour(255,0,0));
    wxFont EBroadButtonFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !EBroadButtonFont.Ok() ) EBroadButtonFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    EBroadButtonFont.SetPointSize(8);
    EBroadButton->SetFont(EBroadButtonFont);
    GridBagSizer1->Add(EBroadButton, wxGBPosition(3, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    AllStatButton = new wxButton(this, ID_BUTTON6, _("All Status"), wxDefaultPosition, wxSize(120,25), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    wxFont AllStatButtonFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !AllStatButtonFont.Ok() ) AllStatButtonFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    AllStatButtonFont.SetPointSize(8);
    AllStatButton->SetFont(AllStatButtonFont);
    GridBagSizer1->Add(AllStatButton, wxGBPosition(4, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    AllBulbButton = new wxButton(this, ID_BUTTON7, _("All Bulb Life"), wxDefaultPosition, wxSize(120,25), 0, wxDefaultValidator, _T("ID_BUTTON7"));
    wxFont AllBulbButtonFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !AllBulbButtonFont.Ok() ) AllBulbButtonFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    AllBulbButtonFont.SetPointSize(8);
    AllBulbButton->SetFont(AllBulbButtonFont);
    GridBagSizer1->Add(AllBulbButton, wxGBPosition(5, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    AllOffButton = new wxButton(this, ID_BUTTON8, _("All Off"), wxDefaultPosition, wxSize(120,25), 0, wxDefaultValidator, _T("ID_BUTTON8"));
    wxFont AllOffButtonFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !AllOffButtonFont.Ok() ) AllOffButtonFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    AllOffButtonFont.SetPointSize(8);
    AllOffButton->SetFont(AllOffButtonFont);
    GridBagSizer1->Add(AllOffButton, wxGBPosition(6, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    UnEBroadButton = new wxButton(this, ID_BUTTON9, _("Undo Emergency"), wxDefaultPosition, wxSize(120,25), 0, wxDefaultValidator, _T("ID_BUTTON9"));
    UnEBroadButton->SetForegroundColour(wxColour(255,0,0));
    wxFont UnEBroadButtonFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !UnEBroadButtonFont.Ok() ) UnEBroadButtonFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    UnEBroadButtonFont.SetPointSize(8);
    UnEBroadButton->SetFont(UnEBroadButtonFont);
    GridBagSizer1->Add(UnEBroadButton, wxGBPosition(7, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    AdvancedChoice = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxSize(250,25), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    AdvancedChoice->SetSelection( AdvancedChoice->Append(_("One Advanced Menu")) );
    AdvancedChoice->Append(_("Get Service Failure Status"));
    AdvancedChoice->Append(_("Get Any Value"));
    AdvancedChoice->Append(_("Set Any Value"));
    AdvancedChoice->Append(_("Get Serial Number to Log"));
    AdvancedChoice->Append(_("Set Projector ID"));
    AdvancedChoice->Append(_("Set Mute On"));
    AdvancedChoice->Append(_("Set Mute Off"));
    AdvancedChoice->Append(_("Set Autosignal On"));
    AdvancedChoice->Append(_("Set Input Selection"));
    AdvancedChoice->Append(_("Set Auto Powerdown Time"));
    wxFont AdvancedChoiceFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !AdvancedChoiceFont.Ok() ) AdvancedChoiceFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    AdvancedChoiceFont.SetPointSize(8);
    AdvancedChoice->SetFont(AdvancedChoiceFont);
    GridBagSizer1->Add(AdvancedChoice, wxGBPosition(9, 0), wxGBSpan(1, 2), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    AdvancedChoiceAll = new wxComboBox(this, ID_COMBOBOX2, wxEmptyString, wxDefaultPosition, wxSize(250,25), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
    AdvancedChoiceAll->SetSelection( AdvancedChoiceAll->Append(_("All Advanced Menu")) );
    AdvancedChoiceAll->Append(_("Get Service Failure Status"));
    AdvancedChoiceAll->Append(_("Get Any Value"));
    AdvancedChoiceAll->Append(_("Get Serial Number to CSV"));
    AdvancedChoiceAll->Append(_("Set Projector IDs"));
    AdvancedChoiceAll->Append(_("Set Mute On"));
    AdvancedChoiceAll->Append(_("Set Mute Off"));
    AdvancedChoiceAll->Append(_("Set Autosignal On"));
    AdvancedChoiceAll->Append(_("Set Input Selection"));
    AdvancedChoiceAll->Append(_("Set Auto Powerdown Time"));
    wxFont AdvancedChoiceAllFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !AdvancedChoiceAllFont.Ok() ) AdvancedChoiceAllFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    AdvancedChoiceAllFont.SetPointSize(8);
    AdvancedChoiceAll->SetFont(AdvancedChoiceAllFont);
    GridBagSizer1->Add(AdvancedChoiceAll, wxGBPosition(8, 0), wxGBSpan(1, 2), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ConfButton = new wxButton(this, ID_BUTTON10, _("Config Editor"), wxDefaultPosition, wxSize(120,25), wxDOUBLE_BORDER, wxDefaultValidator, _T("ID_BUTTON10"));
    ConfButton->SetForegroundColour(wxColour(28,169,158));
    wxFont ConfButtonFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !ConfButtonFont.Ok() ) ConfButtonFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    ConfButtonFont.SetPointSize(8);
    ConfButton->SetFont(ConfButtonFont);
    GridBagSizer1->Add(ConfButton, wxGBPosition(7, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextLog = new wxTextCtrl(this, ID_TEXTCTRL3, _("To Prevent Freezes please check all installed config files.\n"), wxDefaultPosition, wxSize(400,328), wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    wxFont TextLogFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !TextLogFont.Ok() ) TextLogFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    TextLogFont.SetPointSize(8);
    TextLog->SetFont(TextLogFont);
    GridBagSizer1->Add(TextLog, wxGBPosition(0, 2), wxGBSpan(10, 1), wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    SetSizer(GridBagSizer1);
    TextEntryDialog1 = new wxTextEntryDialog(this, wxEmptyString, wxEmptyString, wxEmptyString, wxOK|wxCANCEL|wxCENTRE|wxWS_EX_VALIDATE_RECURSIVELY, wxDefaultPosition);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -10 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    GridBagSizer1->Fit(this);
    GridBagSizer1->SetSizeHints(this);

    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&npcproFrame::OnTextCtrl1Text);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&npcproFrame::OnTextRoomText);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&npcproFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&npcproFrame::OnOneStatButtonClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&npcproFrame::OnOneBulbButtonClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&npcproFrame::OnOneOffButtonClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&npcproFrame::OnEBroadButtonClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&npcproFrame::OnAllStatButtonClick);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&npcproFrame::OnAllBulbButtonClick);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&npcproFrame::OnAllOffButtonClick);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&npcproFrame::OnUnEBroadButtonClick);
    Connect(ID_COMBOBOX1,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&npcproFrame::OnAdvancedChoiceSelected);
    Connect(ID_COMBOBOX2,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&npcproFrame::OnAdvancedChoiceAllSelected);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&npcproFrame::OnConfButtonClick);
    Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&npcproFrame::OnTextCtrl3Text);
    //*)
}

npcproFrame::~npcproFrame()
{
    //(*Destroy(npcproFrame)
    //*)
    exit(0);
}

void npcproFrame::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void npcproFrame::OnTextCtrl3Text(wxCommandEvent& event)
{
}
void npcproFrame::OnButton1Click(wxCommandEvent& event) //password checker
{
    //TextLog->AppendText("\nWritten by Jake Gardner.\n");
    SetStatusText("Running, Please Wait",0);
    wxString pass = TextPass->GetValue();
    std::string os ="unk";
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    os="win";
#else
    os="uni";
#endif

    std::ifstream conftext;
    std::string homepath;
    if (os == "win")
    {
        homepath = getenv("APPDATA");
        conftext.open((homepath + "/npc/pass.txt").c_str());
    }
    if (os == "uni")
    {
        homepath = getenv("HOME");
        conftext.open((homepath + "/.npc/pass.txt").c_str());
    }
    std::string realpass;
    getline(conftext,realpass);
    if ( pass == realpass)
    {
        TextLog->AppendText("Password Correct.\n");
    }
    else
    {
        TextLog->AppendText("Password Incorrect.\n");
    }
    SetStatusText("Done",0);
}

void npcproFrame::OnConfButtonClick(wxCommandEvent& event)
{
    SetStatusText("Running, Please Wait",0);
    std::string GetStdoutFromCommand(std::string cmd, std::string ip, std::string space, std::string model, std::string cmd2);
    std::string systemRep(std::string cmd);
    std::string os ="unk";
#ifdef _WIN64
    //define something for Windows (64-bit)
    os = "win";
#elif _WIN32
    //define something for Windows (32-bit)
    os = "win";
#elif __APPLE__
#include "TargetConditionals.h"
#if TARGET_IPHONE_SIMULATOR
    // iOS Simulator
    os = "osx";
#elif TARGET_OS_IPHONE
    // iOS device
    os = "osx";
#elif TARGET_OS_MAC
    // Other kinds of Mac OS
    os = "osx";
#else
    // Unsupported platform
    os = "osx";
#endif
#elif __linux
    os = "uni";
#elif __unix // all unices not caught above
    os = "uni";
#elif __posix
    os = "uni";
#endif

    std::ifstream conftext;
    std::ifstream in;
    std::string homepath;
    if (os == "win")
    {
        TextLog->AppendText("\nOpening configuration files with start command.\n");
        homepath = getenv("APPDATA");
        std::string command = "start \"\" \"" + homepath + "\\npc\\rooms.csv\"";
        systemRep(command.c_str());
        command =  "start \"\" \"" + homepath + "\\npc\\pass.txt\"";
        systemRep(command.c_str());
    }
    if (os == "uni")
    {
        homepath = getenv("HOME");
        TextLog->AppendText("\nOpening configuration files with xdg-open command.\n");
        TextLog->AppendText("Run 'npcconfig' in terminal if nothing happens.\n");
        std::string command = "xdg-open " + homepath + "/.npc/rooms.csv";
        systemRep(command.c_str());
        command =  "xdg-open " + homepath + "/.npc/pass.txt";
        systemRep(command.c_str());
    }
    if (os == "osx")
    {
        homepath = getenv("HOME");
        TextLog->AppendText("\nOpening configuration files with the open command.\n");
        //TextLog->AppendText("Run npcconfig in terminal if nothing happens.\n");
        std::string command = "open " + homepath + "/.npc/rooms.csv";
        systemRep(command.c_str());
        command =  "open " + homepath + "/.npc/pass.txt";
        systemRep(command.c_str());
    }
    SetStatusText("Done",0);
}



std::string GetStdoutFromCommand(std::string cmd1, std::string ip, std::string space, std::string model, std::string cmd2)
{

    std::string out;
    FILE * stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    std::string cmd = cmd1 + ip + space + model + cmd2;
    cmd.append(" 2>&1");
    std::cout << cmd << std::endl;

    stream = popen(cmd.c_str(), "r");
    if (stream)
    {
        while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != NULL) out.append(buffer);
        pclose(stream);
    }
    std::cout << out << std::endl;
    return out;
}

std::string systemRep(std::string cmd)
{

    std::string out;
    FILE * stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");
    std::cout << cmd << std::endl;
    stream = popen(cmd.c_str(), "r");
    if (stream)
    {
        while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != NULL) out.append(buffer);
        pclose(stream);
    }
    std::cout << out << std::endl;
    return out;
}
int msleep(unsigned long milisec, std::string os)
{
    if (os == "win")
    {
#ifdef _WIN32
        Sleep(milisec);
#endif
        milisec++;
    }
    else
    {
        int microsec = milisec * 1000;
        usleep(microsec);
    }
    return 1;
}

void npcproFrame::OnTextRoomText(wxCommandEvent& event)
{
}
