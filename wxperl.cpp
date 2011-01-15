#include <wx/string.h>
#include <wx/arrstr.h>
#include <wx/treectrl.h>
#include <wx/msgdlg.h>
#include <string>
#include "perlxsi.c"

#include "wxperl.h"

/** \class WXPerl
Glue from the Perl distribution.

Perl works around C.
Its the guts to C environment.

myargs
embed
my_perl
my_script

*/

extern "C" {
char *myargs[] = { NULL };          /*!< argv to perl script */
char *embed[] = { "", "-e", "\0" } ;/*!< argv to perl interpreter */

/** \var my_perl
The honorable Perl interpreter
*/
static PerlInterpreter *my_perl;

/** \var my_script
The main script my_perl will run
*/
static char *my_script;
}

/**
Perl glue to script vtiger.pl

*/
WXPerl::WXPerl() {
    //ctor
    my_perl = perl_alloc();
    perl_construct(my_perl);

    perl_parse(my_perl, xs_init, 3, embed, NULL);
    PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
    perl_run(my_perl);
    dSP;
    eval_pv("require('scripts/vtiger.pl');", TRUE);

    SPAGAIN;
    if (SvTRUE(ERRSV))
    {
        wxString erro = wxString::FromUTF8(SvPV_nolen(ERRSV));
        wxMessageBox( erro ,_T("---VTGUI---"));
        printf ("Uh oh - %s\n", SvPV_nolen(ERRSV));
        POPs;
    }
}

WXPerl::~WXPerl() {
    //dtor
    perl_destruct(my_perl);
    perl_free(my_perl);
}

wxString WXPerl::login() {
    dSP;
    ENTER;
    SAVETMPS;
    char *myargs[] = { NULL };
    call_argv("getSession", G_KEEPERR | G_EVAL | G_DISCARD | G_NOARGS, myargs);
    SPAGAIN;
        if (SvTRUE(ERRSV))
        {
            wxString erro = wxString::FromUTF8(SvPV_nolen(ERRSV));
            wxMessageBox( erro ,_T("---VTGUI---"));
            printf ("Uh oh - %s\n", SvPV_nolen(ERRSV));
            POPs;
        }
    char *session = SvPV_nolen(get_sv("session", 0));
    return wxString::FromAscii(session) ;
}

wxArrayString WXPerl::loadProjects(wxString& session) {
    dSP;
    //const char * ch =  session.mb_str();
    size_t len = session.length();
    char* tmp = new char [ len + 1 ];
    strcpy( tmp, session.mb_str() );
    char *myargs[] = { tmp , NULL };
    // chama sub &loadProjects($sessao)
    call_argv("getProjectNames", G_EVAL | G_DISCARD, myargs);
    SPAGAIN;
        if (SvTRUE(ERRSV))
        {
            wxString erro = wxString::FromUTF8(SvPV_nolen(ERRSV));
            wxMessageBox( erro ,_T("---VTGUI---"));
            printf ("Uh oh - %s\n", SvPV_nolen(ERRSV));
            POPs;
        }
    AV* avPrj   = get_av("projectNames", 0);
    int ln = av_len(avPrj);
    wxArrayString * prjNames = new wxArrayString();
    SV** svPrj;
    wxString name;
    for (int i = 0; i < ln + 1; i++){
        svPrj  = av_fetch(avPrj, i, 0);
        name = wxString::FromAscii(SvPV_nolen(* svPrj));
        prjNames->Add(name);
    }
    return * prjNames;
}

wxArrayString WXPerl::describeProject(wxString &name) {
    dSP;
    //const char * ch =  session.mb_str();

    size_t len = name.length();
    char* tmp = new char [ len + 1 ];
    strcpy( tmp, name.mb_str() );
    char *myargs[] = {"", tmp , NULL };
    // chama sub &describeProject($name)
    call_argv("describeProject", G_EVAL | G_DISCARD, myargs);
    SPAGAIN;
        if (SvTRUE(ERRSV))
        {
            wxString erro = wxString::FromUTF8(SvPV_nolen(ERRSV));
            wxMessageBox( erro ,_T("---VTGUI---"));
            printf ("Uh oh - %s\n", SvPV_nolen(ERRSV));
            POPs;
        }

    AV* avPrj   = get_av("projectDescription", 0);
    int ln = av_len(avPrj);

    wxArrayString * prjDesc = new wxArrayString();
    SV** svPrj;
    wxString desc;
    for (int i = 0; i < ln + 1; i++){
        svPrj  = av_fetch(avPrj, i, 0);
        desc = wxString::FromAscii(SvPV_nolen(* svPrj));
        prjDesc->Add(desc);
    }

    return * prjDesc;
}

wxProjectStructure WXPerl::loadProjectDetails(wxString &name) {

    dSP;
    // preparing the stack for perl sub call
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);

    size_t len = name.length();
    char* tmp = new char [ len + 1 ];
    strcpy( tmp, name.mb_str() );
    // push parameters to perl
    XPUSHs(sv_2mortal(newSVpv(tmp, 0)));
    PUTBACK;
    call_pv("loadProjectDetails", G_EVAL | G_DISCARD);
    SPAGAIN;
        if (SvTRUE(ERRSV))
        {
            wxString erro = wxString::FromUTF8(SvPV_nolen(ERRSV));
            wxMessageBox( erro ,_T("---VTGUI---"));
            printf ("Uh oh - %s\n", SvPV_nolen(ERRSV));
            POPs;
        }
    // load the hash from perl environment to wxHashMap prjDetails
    HV* hvPrj   = get_hv("projectDetails", 0);
    wxProjectStructure prjDetails;
    SV*  val;
    I32  retlen;
    char * key;
    int h = hv_iterinit(hvPrj);
    while (val = hv_iternextsv(hvPrj, &key, &retlen) ){
        wxString wxsVal;
        wxString wxsKey;
        wxsVal = wxString::FromAscii(SvPV_nolen( val ));
        wxsKey = wxString::FromAscii( key );
        prjDetails[wxsKey] = wxsVal;
    }

    // clear perl context memory space
    FREETMPS;
    LEAVE;

    return prjDetails;
}

wxProjectStructure WXPerl::createProject(wxString &name) {

    dSP;
    // preparing the stack for perl sub call
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);

    size_t len = name.length();
    char* tmp = new char [ len + 1 ];
    strcpy( tmp, name.mb_str() );
    // push parameters to perl
    XPUSHs(sv_2mortal(newSVpv(tmp, 0)));
    PUTBACK;
    call_pv("createProject", G_EVAL | G_DISCARD);
    SPAGAIN;
        if (SvTRUE(ERRSV))
        {
            wxString erro = wxString::FromUTF8(SvPV_nolen(ERRSV));
            wxMessageBox( erro ,_T("---VTGUI---"));
            printf ("Uh oh - %s\n", SvPV_nolen(ERRSV));
            POPs;
        }
    // load the hash from perl environment to wxHashMap prjDetails
    HV* hvPrj   = get_hv("projectDetails", 0);
    wxProjectStructure prjDetails;
    SV*  val;
    I32  retlen;
    char * key;
    int h = hv_iterinit(hvPrj);
    while (val = hv_iternextsv(hvPrj, &key, &retlen) ){
        wxString wxsVal;
        wxString wxsKey;
        wxsVal = wxString::FromAscii(SvPV_nolen( val ));
        wxsKey = wxString::FromAscii( key );
        prjDetails[wxsKey] = wxsVal;
    }

    // clear perl context memory space
    FREETMPS;
    LEAVE;

    return prjDetails;
}


void WXPerl::testes() {

    eval_pv("\
            $testevar = 98;\
            $testebar = 97;\
            ", TRUE);

    int teste = SvIV(get_sv("testevar", 0));
    printf(" = %d\n",teste);

    char *myargs[] = { NULL };
    eval_pv("require('test.pl');", TRUE);
    call_argv("test_all", G_DISCARD | G_NOARGS, myargs);

}
