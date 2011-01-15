/** \page main
<h1>Synodos Filos</h1>
<p>Simple GUI with bindings to perl

<pre>
 *************************************************************
 * Name:      vtiguiFrame
 * Purpose:   Code for Application Frame
 * Author:    Monsenhor (filipo@kobkob.com.br)
 * Created:   2010-12-30
 * Copyright: Monsenhor (www.kobkob.com.br)
 * License:   Artistic Licence as perl is
 *************************************************************
 </pre>

 */

#include "vtiguiMain.h"
#include <wx/msgdlg.h>
#include <wx/splash.h>
#include <wx/textdlg.h>
#include "version.h"



//(*InternalHeaders(vtiguiFrame)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format) {
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f ) {
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

//(*IdInit(vtiguiFrame)
const long vtiguiFrame::ID_TREECTRLPROJECTS = wxNewId();
const long vtiguiFrame::ID_BITMAPBUTTON1 = wxNewId();
const long vtiguiFrame::ID_BITMAPBUTTON2 = wxNewId();
const long vtiguiFrame::ID_BITMAPBUTTON12 = wxNewId();
const long vtiguiFrame::ID_BITMAPBUTTON13 = wxNewId();
const long vtiguiFrame::ID_STATICTEXT3 = wxNewId();
const long vtiguiFrame::ID_BITMAPBUTTON3 = wxNewId();
const long vtiguiFrame::ID_BITMAPBUTTON4 = wxNewId();
const long vtiguiFrame::ID_BITMAPBUTTON5 = wxNewId();
const long vtiguiFrame::ID_BITMAPBUTTON6 = wxNewId();
const long vtiguiFrame::ID_BITMAPBUTTON7 = wxNewId();
const long vtiguiFrame::ID_BITMAPBUTTON8 = wxNewId();
const long vtiguiFrame::ID_LISTBOX1 = wxNewId();
const long vtiguiFrame::ID_BITMAPBUTTON9 = wxNewId();
const long vtiguiFrame::ID_BITMAPBUTTON10 = wxNewId();
const long vtiguiFrame::ID_BITMAPBUTTON11 = wxNewId();
const long vtiguiFrame::ID_HTMLWINDOW1 = wxNewId();
const long vtiguiFrame::ID_STATICTEXT1 = wxNewId();
const long vtiguiFrame::ID_CHOICE1 = wxNewId();
const long vtiguiFrame::ID_STATICTEXT2 = wxNewId();
const long vtiguiFrame::ID_CHOICE2 = wxNewId();
const long vtiguiFrame::ID_HTMLWINDOW2 = wxNewId();
const long vtiguiFrame::ID_STATICTEXT4 = wxNewId();
const long vtiguiFrame::ID_TEXTCTRL1 = wxNewId();
const long vtiguiFrame::ID_STATICTEXT14 = wxNewId();
const long vtiguiFrame::ID_STATICTEXT6 = wxNewId();
const long vtiguiFrame::ID_STATICTEXT5 = wxNewId();
const long vtiguiFrame::ID_DATEPICKERCTRL4 = wxNewId();
const long vtiguiFrame::ID_DATEPICKERCTRL1 = wxNewId();
const long vtiguiFrame::ID_DATEPICKERCTRL2 = wxNewId();
const long vtiguiFrame::ID_STATICTEXT9 = wxNewId();
const long vtiguiFrame::ID_STATICTEXT8 = wxNewId();
const long vtiguiFrame::ID_STATICTEXT10 = wxNewId();
const long vtiguiFrame::ID_CHOICE4 = wxNewId();
const long vtiguiFrame::ID_CHOICE3 = wxNewId();
const long vtiguiFrame::ID_CHOICE5 = wxNewId();
const long vtiguiFrame::ID_STATICTEXT11 = wxNewId();
const long vtiguiFrame::ID_CHOICE6 = wxNewId();
const long vtiguiFrame::ID_STATICTEXT12 = wxNewId();
const long vtiguiFrame::ID_TEXTCTRL2 = wxNewId();
const long vtiguiFrame::ID_STATICTEXT13 = wxNewId();
const long vtiguiFrame::ID_TEXTCTRL3 = wxNewId();
const long vtiguiFrame::ID_STATICTEXT7 = wxNewId();
const long vtiguiFrame::ID_TEXTCTRL4 = wxNewId();
const long vtiguiFrame::ID_PANEL6 = wxNewId();
const long vtiguiFrame::ID_PANEL3 = wxNewId();
const long vtiguiFrame::ID_PANEL4 = wxNewId();
const long vtiguiFrame::ID_PANEL5 = wxNewId();
const long vtiguiFrame::ID_NOTEBOOK1 = wxNewId();
const long vtiguiFrame::ID_PANEL1 = wxNewId();
const long vtiguiFrame::idMenuQuit = wxNewId();
const long vtiguiFrame::idMenuAbout = wxNewId();
const long vtiguiFrame::ID_STATUSBAR1 = wxNewId();
const long vtiguiFrame::login = wxNewId();
const long vtiguiFrame::ID_TOOLBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(vtiguiFrame,wxFrame)
    //(*EventTable(vtiguiFrame)
    //*)
END_EVENT_TABLE()

vtiguiFrame::vtiguiFrame(wxWindow* parent,wxWindowID id) {
    wxString version = wxString::FromAscii(AutoVersion::FULLVERSION_STRING)+
                       wxString::FromAscii(AutoVersion::STATUS);

    wxBitmap bitmap;
    if (bitmap.LoadFile(_T("img/splash.png"), wxBITMAP_TYPE_PNG))
    {
        wxSplashScreen* splash = new wxSplashScreen(bitmap,
          wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
          3000, NULL, -1, wxDefaultPosition, wxDefaultSize,
          wxSIMPLE_BORDER|wxSTAY_ON_TOP);
    }
    wxYield();

    //(*Initialize(vtiguiFrame)
    wxBoxSizer* BoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer9;
    wxMenuBar* MenuBar1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU|wxCLOSE_BOX|wxFRAME_SHAPED|wxDOUBLE_BORDER, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Projects"));
    TreeCtrlProjects = new wxTreeCtrl(Panel1, ID_TREECTRLPROJECTS, wxDefaultPosition, wxSize(225,506), wxTR_HAS_BUTTONS|wxTR_HIDE_ROOT|wxSUNKEN_BORDER, wxDefaultValidator, _T("ID_TREECTRLPROJECTS"));
    StaticBoxSizer1->Add(TreeCtrlProjects, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    BitmapButton1 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("/media/SQ004224P01/estudos/wx/vtiger/vtigui/img/folder-new.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton1->SetDefault();
    BoxSizer3->Add(BitmapButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton2 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("/media/SQ004224P01/estudos/wx/vtiger/vtigui/img/edit-delete.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BoxSizer3->Add(BitmapButton2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton12 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON12, wxBitmap(wxImage(_T("/media/SQ004224P01/estudos/wx/vtiger/vtigui/img/go-previous32.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON12"));
    BitmapButton12->SetDefault();
    BoxSizer3->Add(BitmapButton12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton13 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON13, wxBitmap(wxImage(_T("/media/SQ004224P01/estudos/wx/vtiger/vtigui/img/go-next32.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON13"));
    BitmapButton13->SetDefault();
    BoxSizer3->Add(BitmapButton13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Details"));
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Stakeholders"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer5->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer7 = new wxBoxSizer(wxVERTICAL);
    BitmapButton3 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON3, wxBitmap(wxImage(_T("/media/SQ004224P01/estudos/wx/vtiger/vtigui/img/contact-new.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
    BitmapButton3->SetDefault();
    BoxSizer7->Add(BitmapButton3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton4 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON4, wxBitmap(wxImage(_T("/media/SQ004224P01/estudos/wx/vtiger/vtigui/img/process-stop.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
    BoxSizer7->Add(BitmapButton4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton5 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON5, wxBitmap(wxImage(_T("/media/SQ004224P01/estudos/wx/vtiger/vtigui/img/go-next.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
    BoxSizer7->Add(BitmapButton5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton6 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON6, wxBitmap(wxImage(_T("/media/SQ004224P01/estudos/wx/vtiger/vtigui/img/go-previous.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
    BoxSizer7->Add(BitmapButton6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton7 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON7, wxBitmap(wxImage(_T("/media/SQ004224P01/estudos/wx/vtiger/vtigui/img/mail-forward.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON7"));
    BitmapButton7->SetDefault();
    BoxSizer7->Add(BitmapButton7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton8 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON8, wxBitmap(wxImage(_T("/media/SQ004224P01/estudos/wx/vtiger/vtigui/img/appointment-new.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON8"));
    BitmapButton8->SetDefault();
    BoxSizer7->Add(BitmapButton8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6->Add(BoxSizer7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ListBox1 = new wxListBox(Panel1, ID_LISTBOX1, wxDefaultPosition, wxSize(191,232), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    ListBox1->Append(_("Hounds auto"));
    ListBox1->Append(_("Studio Design 88"));
    ListBox1->Append(_("Ana Paula Dias Garcia"));
    ListBox1->Append(_("Inez Oliveira"));
    ListBox1->Append(_("Ricardo Filipo"));
    ListBox1->Append(_("Carol Larson"));
    BoxSizer6->Add(ListBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(BoxSizer6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer9 = new wxBoxSizer(wxVERTICAL);
    BitmapButton9 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON9, wxBitmap(wxImage(_T("/media/SQ004224P01/estudos/wx/vtiger/vtigui/img/edit-find-replace.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON9"));
    BitmapButton9->SetDefault();
    BoxSizer9->Add(BitmapButton9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton10 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON10, wxBitmap(wxImage(_T("/media/SQ004224P01/estudos/wx/vtiger/vtigui/img/go-home.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON10"));
    BitmapButton10->SetDefault();
    BoxSizer9->Add(BitmapButton10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton11 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON11, wxBitmap(wxImage(_T("/media/SQ004224P01/estudos/wx/vtiger/vtigui/img/internet-web-browser.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON11"));
    BoxSizer9->Add(BitmapButton11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8->Add(BoxSizer9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    HtmlWindow1 = new wxHtmlWindow(Panel1, ID_HTMLWINDOW1, wxDefaultPosition, wxSize(195,181), wxHW_SCROLLBAR_AUTO, _T("ID_HTMLWINDOW1"));
    BoxSizer8->Add(HtmlWindow1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(BoxSizer8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Relationship"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice1 = new wxChoice(Panel1, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->Append(_("client"));
    Choice1->Append(_("vendor"));
    Choice1->Append(_("member"));
    FlexGridSizer1->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice2 = new wxChoice(Panel1, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    FlexGridSizer1->Add(Choice2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(FlexGridSizer1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4->Add(BoxSizer5, 0, wxALL|wxEXPAND|wxSHAPED|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    Notebook1 = new wxNotebook(Panel1, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
    HtmlWindow2 = new wxHtmlWindow(Notebook1, ID_HTMLWINDOW2, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO, _T("ID_HTMLWINDOW2"));
    HtmlWindow2->LoadPage(_("http://127.0.0.1:9090/"));
    Panel6 = new wxPanel(Notebook1, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
    staticText4 = new wxStaticText(Panel6, ID_STATICTEXT4, _("Project Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer2->Add(staticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    projectName = new wxTextCtrl(Panel6, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    projectName->SetMaxLength(80);
    FlexGridSizer2->Add(projectName, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText12 = new wxStaticText(Panel6, ID_STATICTEXT14, _("Start Date"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    FlexGridSizer2->Add(StaticText12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(Panel6, ID_STATICTEXT6, _("Target end date"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer2->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    staticText5 = new wxStaticText(Panel6, ID_STATICTEXT5, _("End Date"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer2->Add(staticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    startDate = new wxDatePickerCtrl(Panel6, ID_DATEPICKERCTRL4, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL4"));
    FlexGridSizer2->Add(startDate, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    targetEndDate = new wxDatePickerCtrl(Panel6, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
    FlexGridSizer2->Add(targetEndDate, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    endDate = new wxDatePickerCtrl(Panel6, ID_DATEPICKERCTRL2, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL2"));
    FlexGridSizer2->Add(endDate, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(Panel6, ID_STATICTEXT9, _("Project type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    FlexGridSizer2->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(Panel6, ID_STATICTEXT8, _("Project status"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    FlexGridSizer2->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(Panel6, ID_STATICTEXT10, _("Link"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    FlexGridSizer2->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    projectType = new wxChoice(Panel6, ID_CHOICE4, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
    projectType->SetSelection( projectType->Append(_("Prospect")) );
    projectType->Append(_("Sale"));
    projectType->Append(_("Account"));
    projectType->Append(_("Legal"));
    projectType->Append(_("Other"));
    FlexGridSizer2->Add(projectType, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    projectStatus = new wxChoice(Panel6, ID_CHOICE3, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
    projectStatus->SetSelection( projectStatus->Append(_("Plan")) );
    projectStatus->Append(_("Inited"));
    projectStatus->Append(_("Active"));
    projectStatus->Append(_("End"));
    FlexGridSizer2->Add(projectStatus, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    projectLink = new wxChoice(Panel6, ID_CHOICE5, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
    projectLink->SetSelection( projectLink->Append(_("Account")) );
    projectLink->Append(_("Contact"));
    FlexGridSizer2->Add(projectLink, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText9 = new wxStaticText(Panel6, ID_STATICTEXT11, _("Owner"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    FlexGridSizer2->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    projectOwner = new wxChoice(Panel6, ID_CHOICE6, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE6"));
    projectOwner->SetSelection( projectOwner->Append(_("user1")) );
    projectOwner->Append(_("user2"));
    projectOwner->Append(_("user3"));
    FlexGridSizer2->Add(projectOwner, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText10 = new wxStaticText(Panel6, ID_STATICTEXT12, _("Target budget"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    FlexGridSizer2->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    projectTargetBudget = new wxTextCtrl(Panel6, ID_TEXTCTRL2, _("US$ 0.00"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer2->Add(projectTargetBudget, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText11 = new wxStaticText(Panel6, ID_STATICTEXT13, _("Website"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    FlexGridSizer2->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    projectUrl = new wxTextCtrl(Panel6, ID_TEXTCTRL3, _("http://"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer2->Add(projectUrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(Panel6, ID_STATICTEXT7, _("Description"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    FlexGridSizer2->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    projectDescription = new wxTextCtrl(Panel6, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(200,230), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    FlexGridSizer2->Add(projectDescription, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel6->SetSizer(FlexGridSizer2);
    FlexGridSizer2->Fit(Panel6);
    FlexGridSizer2->SetSizeHints(Panel6);
    Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    Panel4 = new wxPanel(Notebook1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    Panel5 = new wxPanel(Notebook1, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    Notebook1->AddPage(HtmlWindow2, _("Journal"), false);
    Notebook1->AddPage(Panel6, _("Project Details"), false);
    Notebook1->AddPage(Panel3, _("Comunication"), false);
    Notebook1->AddPage(Panel4, _("Events"), false);
    Notebook1->AddPage(Panel5, _("Sales"), false);
    BoxSizer4->Add(Notebook1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(BoxSizer4, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer2->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_TOP, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    ToolBar1 = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxNO_BORDER, _T("ID_TOOLBAR1"));
    ToolBarItem1 = ToolBar1->AddTool(login, _("login"), wxBitmap(wxImage(_T("/media/SQ004224P01/estudos/wx/vtiger/vtigui/img/network-transmit-receive.png"))), wxBitmap(wxImage(_T("/media/SQ004224P01/estudos/wx/vtiger/vtigui/img/network-offline.png"))), wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBar1->Realize();
    SetToolBar(ToolBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_TREECTRLPROJECTS,wxEVT_COMMAND_TREE_ITEM_ACTIVATED,(wxObjectEventFunction)&vtiguiFrame::OnTreeCtrlProjectsItemActivated);
    Connect(ID_TREECTRLPROJECTS,wxEVT_COMMAND_TREE_ITEM_MENU,(wxObjectEventFunction)&vtiguiFrame::OnTreeCtrlProjectsItemMenu);
    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&vtiguiFrame::OnCreateProjectClick);
    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&vtiguiFrame::OnCreateStakeHolderClick);
    Connect(ID_NOTEBOOK1,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&vtiguiFrame::OnNotebook1PageChanged);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&vtiguiFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&vtiguiFrame::OnAbout);
    Connect(login,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&vtiguiFrame::OnClickLogin);
    //*)

    // Instance a WXPerl interpreter object
    myPerl = new WXPerl();

}

vtiguiFrame::~vtiguiFrame() {
    //(*Destroy(vtiguiFrame)
    //*)
}



void vtiguiFrame::OnQuit(wxCommandEvent& event) {
    system ("killall httpd.pl");
    Close();
}

void vtiguiFrame::OnAbout(wxCommandEvent& event) {
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to vtgui ..."));
}

void vtiguiFrame::OnNotebook1PageChanged(wxNotebookEvent& event) {
}

void vtiguiFrame::OnClickLogin(wxCommandEvent& event)
{
    this->SetCursor(* wxHOURGLASS_CURSOR);

    wxString myStatus;
    myStatus = _("Logando ... ");
    StatusBar1->SetStatusText(myStatus);
    if (! mySession){
        mySession = new wxString(myPerl->login());
        myStatus += _("Efetuado! Sessão: ");
        StatusBar1->PushStatusText(myStatus);
        ToolBar1->EnableTool(login, FALSE);
    }
    myStatus += * mySession;
    StatusBar1->PushStatusText(myStatus);
    //wxMessageBox(_("Login efetuado no vtiger!!!"),_("---VTGUI---"));

    loadProjects();
    this->SetCursor(* wxSTANDARD_CURSOR);
}

void vtiguiFrame::OnCreateProjectClick(wxCommandEvent& event)
{
    wxSetCursor(* wxHOURGLASS_CURSOR);

    wxString myPrjName = wxGetTextFromUser(_("Project name"), _("Create new project"), _(""), NULL,
       wxDefaultCoord, wxDefaultCoord, true);
    myPerl->createProject(myPrjName);
    wxSetCursor(* wxSTANDARD_CURSOR);
}

void vtiguiFrame::OnCreateStakeHolderClick(wxCommandEvent& event)
{
    wxMessageBox(_("Criando novo stakeholder!!!"),_("---VTGUI---"));

    Panel1->SetCursor(* wxHOURGLASS_CURSOR);
    Panel1->SetCursor(* wxSTANDARD_CURSOR);
}

void vtiguiFrame::loadProjects() {
    Panel1->SetCursor(* wxHOURGLASS_CURSOR);
    if (mySession){
        root = TreeCtrlProjects->AddRoot(_("Projects")); //not shown
        wxArrayString prj = myPerl->loadProjects( * mySession );
        for (int i = 0; i < prj.Count() ; i++){
            treeItem[i] = TreeCtrlProjects->AppendItem(root, prj.Item(i), 1);
        }
        //treeItem[1] = TreeCtrlProjects->AppendItem(root, _("Hounds auto"), 1);
        //TreeCtrlProjects->AppendItem(treeItem[0], _("Orçamentos"), 1);
    } else {
            wxMessageBox(_("Erro ... :P"),_("---VTGUI---"));
    }
    Panel1->SetCursor(* wxSTANDARD_CURSOR);
}

void vtiguiFrame::loadProjectDetails (wxTreeItemId &id){
    wxString theProjectName = TreeCtrlProjects->GetItemText(id);
    StatusBar1->SetStatusText(theProjectName);

    projectDetails   =  myPerl->loadProjectDetails(theProjectName);

    // clean tree item to populate
    TreeCtrlProjects->DeleteChildren(id);
    // iterate over all the project elements
    wxProjectStructure::iterator it;
    for( it = projectDetails.begin(); it != projectDetails.end(); ++it )
    {
        wxString key = it->first, value = it->second;
        // do something useful with key and value
        TreeCtrlProjects->AppendItem(id, key+_(": ")+value);
    }
}
void vtiguiFrame::loadProjectEditor(wxTreeItemId &id)
{
    wxString theProjectName = TreeCtrlProjects->GetItemText(id);
    StatusBar1->SetStatusText(theProjectName);
    //load details from tree
    wxProjectStructure::iterator it;
    for( it = projectDetails.begin(); it != projectDetails.end(); ++it )
    {
        wxString key = it->first, value = it->second;
        //put details in editor

        if (key.IsSameAs( _T("projectname") ))
        {
            projectName->SetValue(value);
        }
        if (key.IsSameAs( _T("startdate") ))
        {
            size_t len = value.length();
            char* tmp = new char [ len + 1 ];
            strcpy( tmp, value.mb_str() );
            time_t rawtime = atoi(tmp);
            time ( &rawtime );
            wxString myTime = wxString::FromAscii(ctime (&rawtime));

            wxDateTime t = wxDateTime(time_t (rawtime));
            startDate-> SetValue(t);
        }
        if (key.IsSameAs( _T("targetenddate") ))
        {
//            targetEndDate->SetValue(value);
        }
        if (key.IsSameAs( _T("actualenddate") ))
        {
//            endDate->SetValue(value);
        }
        if (key.IsSameAs( _T("projectstatus") ))
        {
//            projectStatus->SetValue(value);
        }
        if (key.IsSameAs( _T("projecttype") ))
        {
//            ProjectName->SetValue(value);
        }
        if (key.IsSameAs( _T("linktoaccountscontacts") ))
        {
//            ProjectName->SetValue(value);
        }
        if (key.IsSameAs( _T("assigned_user_id") ))
        {
//            ProjectName->SetValue(value);
        }
        if (key.IsSameAs( _T("targetbudget") ))
        {
            projectTargetBudget->SetValue(value);
        }
        if (key.IsSameAs( _T("projecturl") ))
        {
            projectUrl->SetValue(value);
        }
        if (key.IsSameAs( _T("projectpriority") ))
        {
//            ProjectName->SetValue(value);
        }
        if (key.IsSameAs( _T("progress") ))
        {
//            ProjectName->SetValue(value);
        }
        if (key.IsSameAs( _T("description") ))
        {
            projectDescription->SetValue(value);
        }
    }

}

void vtiguiFrame::OnTreeCtrlProjectsItemActivated(wxTreeEvent& event)
{
    wxTreeItemId myId = TreeCtrlProjects->GetSelection();
    loadProjectDetails(myId);
    Notebook1->ChangeSelection(1);

    loadProjectEditor(myId);

}

void vtiguiFrame::OnTreeCtrlProjectsItemMenu(wxTreeEvent& event)
{
    wxMessageBox(_("Menu?!!!"),_("---VTGUI---"));
}
