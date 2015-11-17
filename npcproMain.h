/***************************************************************
 * Name:      npcproMain.h
 * Purpose:   Defines Application Frame
 * Author:    Jake Gardner (gardnertechllc+jake@gmail.com)
 * Created:   2014-07-02
 * Copyright: Jake Gardner ()
 * License:
 **************************************************************/

#ifndef npcproMAIN_H
#define npcproMAIN_H

//(*Headers(npcproFrame)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/textdlg.h>
#include <wx/gbsizer.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/combobox.h>
#include <wx/statusbr.h>
//*)

class npcproFrame: public wxFrame
{
public:

    npcproFrame(wxWindow* parent,wxWindowID id = -1);
    virtual ~npcproFrame();

private:

    //(*Handlers(npcproFrame)
    //void OnQuit(wxCommandEvent& event);
    //void OnAbout(wxCommandEvent& event);
    void OnButton1Click(wxCommandEvent& event);
    void OnTextCtrl1Text(wxCommandEvent& event);
    void OnTextCtrl3Text(wxCommandEvent& event);
    void OnEBroadButtonClick(wxCommandEvent& event);
    void OnOneStatButtonClick(wxCommandEvent& event);
    void OnAllStatButtonClick(wxCommandEvent& event);
    void OnOneBulbButtonClick(wxCommandEvent& event);
    void OnAllBulbButtonClick(wxCommandEvent& event);
    void OnOneOffButtonClick(wxCommandEvent& event);
    void OnAllOffButtonClick(wxCommandEvent& event);
    void OnConfButtonClick(wxCommandEvent& event);
    void OnUnEBroadButtonClick(wxCommandEvent& event);
    void OnRunAdvancedClick(wxCommandEvent& event);
    void OnAdvancedChoiceSelected(wxCommandEvent& event);
    void OnComboBox1Selected(wxCommandEvent& event);
    void OnAdvancedChoiceAllSelected(wxCommandEvent& event);
    void OnTextRoomText(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);
    //*)

    //(*Identifiers(npcproFrame)
    static const long ID_TEXTCTRL1;
    static const long ID_TEXTCTRL2;
    static const long ID_BUTTON1;
    static const long ID_STATICTEXT1;
    static const long ID_STATICTEXT2;
    static const long ID_STATICTEXT3;
    static const long ID_BUTTON2;
    static const long ID_BUTTON3;
    static const long ID_BUTTON4;
    static const long ID_BUTTON5;
    static const long ID_BUTTON6;
    static const long ID_BUTTON7;
    static const long ID_BUTTON8;
    static const long ID_BUTTON9;
    static const long ID_COMBOBOX1;
    static const long ID_COMBOBOX2;
    static const long ID_BUTTON10;
    static const long ID_TEXTCTRL3;
    static const long ID_TEXTENTRYDIALOG1;
    static const long ID_STATUSBAR1;
    //*)

    //(*Declarations(npcproFrame)
    wxComboBox* AdvancedChoice;
    wxStaticText* StaticText2;
    wxButton* CheckPass;
    wxButton* UnEBroadButton;
    wxButton* OneStatButton;
    wxStaticText* StaticText1;
    wxStaticText* StaticText3;
    wxComboBox* AdvancedChoiceAll;
    wxButton* AllStatButton;
    wxButton* AllBulbButton;
    wxStatusBar* StatusBar1;
    wxTextEntryDialog* TextEntryDialog1;
    wxTextCtrl* TextLog;
    wxButton* AllOffButton;
    wxButton* EBroadButton;
    wxButton* OneBulbButton;
    wxTextCtrl* TextPass;
    wxButton* OneOffButton;
    wxTextCtrl* TextRoom;
    wxButton* ConfButton;
    //*)

    DECLARE_EVENT_TABLE()
};

#endif // npcproMAIN_H
