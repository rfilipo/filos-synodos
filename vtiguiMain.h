/***************************************************************
 * Name:      vtiguiMain.h
 * Purpose:   Defines Application Frame
 * Author:    Monsenhor (filipo@kobkob.com.br)
 * Created:   2010-12-30
 * Copyright: Monsenhor (www.kobkob.com.br)
 * License:
 **************************************************************/

#ifndef VTIGUIMAIN_H
#define VTIGUIMAIN_H

//(*Headers(vtiguiFrame)
#include <wx/treectrl.h>
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/datectrl.h>
#include <wx/listbox.h>
#include <wx/toolbar.h>
#include <wx/panel.h>
#include <wx/dateevt.h>
#include <wx/choice.h>
#include <wx/bmpbuttn.h>
#include <wx/frame.h>
#include <wx/html/htmlwin.h>
#include <wx/statusbr.h>
//*)

#include "wxperl.h"
/** \class vtiguiFrame
Implements a easy GUI to Vtiger CRM.

<p>Uses WXPerl, a glue to perl that handles all hooks to Vtiger and others tools.

see <a href="../../Vtiger/docs/index.html">Vtiger Perl SOA</a>

<p>Perform 3 working areas:
<h3>Projects Tree</h3>
<p>To load the projects from vtiger click on login icon on toolbar.
<p>A double click open tre project detais
<h3>Stakeholders pane</h3>
<h3>Details pane</h3>

*/
class vtiguiFrame: public wxFrame
{
    public:

        vtiguiFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~vtiguiFrame();

    private:

        //(*Handlers(vtiguiFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnNotebook1PageChanged(wxNotebookEvent& event);
        void OnClickLogin(wxCommandEvent& event);
        void OnCreateProjectClick(wxCommandEvent& event);
        void OnCreateStakeHolderClick(wxCommandEvent& event);
        void OnTreeCtrlProjectsItemActivated(wxTreeEvent& event);
        void OnTreeCtrlProjectsItemMenu(wxTreeEvent& event);
        //*)

        // Util functions
        void loadProjects();
        void loadProjectDetails (wxTreeItemId &id);
        void loadProjectEditor(wxTreeItemId &id);

        //(*Identifiers(vtiguiFrame)
        static const long ID_TREECTRLPROJECTS;
        static const long ID_BITMAPBUTTON1;
        static const long ID_BITMAPBUTTON2;
        static const long ID_BITMAPBUTTON12;
        static const long ID_BITMAPBUTTON13;
        static const long ID_STATICTEXT3;
        static const long ID_BITMAPBUTTON3;
        static const long ID_BITMAPBUTTON4;
        static const long ID_BITMAPBUTTON5;
        static const long ID_BITMAPBUTTON6;
        static const long ID_BITMAPBUTTON7;
        static const long ID_BITMAPBUTTON8;
        static const long ID_LISTBOX1;
        static const long ID_BITMAPBUTTON9;
        static const long ID_BITMAPBUTTON10;
        static const long ID_BITMAPBUTTON11;
        static const long ID_HTMLWINDOW1;
        static const long ID_STATICTEXT1;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT2;
        static const long ID_CHOICE2;
        static const long ID_HTMLWINDOW2;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT14;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT5;
        static const long ID_DATEPICKERCTRL4;
        static const long ID_DATEPICKERCTRL1;
        static const long ID_DATEPICKERCTRL2;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT8;
        static const long ID_STATICTEXT10;
        static const long ID_CHOICE4;
        static const long ID_CHOICE3;
        static const long ID_CHOICE5;
        static const long ID_STATICTEXT11;
        static const long ID_CHOICE6;
        static const long ID_STATICTEXT12;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT13;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT7;
        static const long ID_TEXTCTRL4;
        static const long ID_PANEL6;
        static const long ID_PANEL3;
        static const long ID_PANEL4;
        static const long ID_PANEL5;
        static const long ID_NOTEBOOK1;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long login;
        static const long ID_TOOLBAR1;
        //*)

        //(*Declarations(vtiguiFrame)
        wxStaticText* StaticText10;
        wxStaticText* StaticText9;
        wxPanel* Panel5;
        wxToolBar* ToolBar1;
        wxDatePickerCtrl* startDate;
        wxBitmapButton* BitmapButton5;
        wxNotebook* Notebook1;
        wxStaticText* StaticText2;
        wxPanel* Panel4;
        wxTreeCtrl* TreeCtrlProjects;
        wxTextCtrl* projectName;
        wxTextCtrl* projectUrl;
        wxStaticText* StaticText6;
        wxStaticText* staticText5;
        wxStaticText* staticText4;
        wxBitmapButton* BitmapButton9;
        wxBitmapButton* BitmapButton10;
        wxStaticText* StaticText8;
        wxStaticText* StaticText11;
        wxTextCtrl* projectTargetBudget;
        wxPanel* Panel1;
        wxBitmapButton* BitmapButton2;
        wxStaticText* StaticText1;
        wxBitmapButton* BitmapButton8;
        wxBitmapButton* BitmapButton13;
        wxStaticText* StaticText3;
        wxTextCtrl* projectDescription;
        wxBitmapButton* BitmapButton1;
        wxPanel* Panel6;
        wxPanel* Panel3;
        wxBitmapButton* BitmapButton12;
        wxToolBarToolBase* ToolBarItem1;
        wxStaticText* StaticText5;
        wxChoice* projectStatus;
        wxStaticText* StaticText7;
        wxChoice* projectOwner;
        wxHtmlWindow* HtmlWindow1;
        wxStatusBar* StatusBar1;
        wxBitmapButton* BitmapButton6;
        wxBitmapButton* BitmapButton7;
        wxBitmapButton* BitmapButton4;
        wxChoice* projectLink;
        wxStaticText* StaticText12;
        wxHtmlWindow* HtmlWindow2;
        wxBitmapButton* BitmapButton3;
        wxDatePickerCtrl* endDate;
        wxChoice* projectType;
        wxStaticText* StaticText4;
        wxChoice* Choice1;
        wxBitmapButton* BitmapButton11;
        wxChoice* Choice2;
        wxDatePickerCtrl* targetEndDate;
        wxListBox* ListBox1;
        //*)

        DECLARE_EVENT_TABLE()

        // Other components
        WXPerl * myPerl;
        wxString * mySession;
        wxTreeItemId  root;
        wxTreeItemId treeItem[20];
        wxProjectStructure projectDetails;
        wxArrayString describeProject;
};

#endif // VTIGUIMAIN_H
