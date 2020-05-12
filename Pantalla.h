#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
class MainFrame:public wxFrame{
public:
    MainFrame( const wxString &title, const wxPoint &pos, const wxSize &size );
    wxTextCtrl *MainEditBox;

};


#endif // PANTALLA_H_INCLUDED
