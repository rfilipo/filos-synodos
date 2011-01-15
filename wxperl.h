#ifndef WXPERL_H
#define WXPERL_H

WX_DECLARE_STRING_HASH_MAP( wxString, wxProjectStructure );

class WXPerl {
public:
    WXPerl();
    virtual ~WXPerl();
    void testes();
    wxString login();
    wxProjectStructure createProject(wxString &name);
    wxArrayString loadProjects(wxString &session);
    wxProjectStructure loadProjectDetails(wxString &name);
    wxArrayString describeProject(wxString &name);
protected:
private:
};

#endif // WXPERL_H
