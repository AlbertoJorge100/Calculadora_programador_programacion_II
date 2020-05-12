#ifndef VENTANACLIENTE_H_INCLUDED
#define VENTANACLIENTE_H_INCLUDED
#include <wx/wx.h>

class VentanaCliente : public wxDialog{
    public:
        VentanaCliente(wxFrame *frame, const wxString& title);
        ~VentanaCliente() {};

    private:
        wxPanel *pad;
        enum{


        };
};


#endif // VENTANACLIENTE_H_INCLUDED
