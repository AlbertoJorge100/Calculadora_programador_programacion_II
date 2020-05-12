#ifndef VENTANA_H_INCLUDED
#define VENTANA_H_INCLUDED

#include <wx/wx.h>
#include <wx/textctrl.h>
#include <wx/button.h>

class Ventana : public wxFrame{
    public:
        Ventana(const wxString& title);
        ~Ventana(){};

    private:
        wxPanel *panel=NULL;
        wxTextCtrl *fv;
        wxTextCtrl *fv1;
        wxTextCtrl *fv2;
        wxTextCtrl *fv3;
        wxTextCtrl *fv4;

        bool fv11=false;
        bool fv12=false;
        bool fv13=false;
        bool fv14=false;
        bool fv10=true;
        int op1;
        int op2;
        std::string op3;
        int opc=0;
        wxButton *btn01;

        enum{
            wxFONTWEIGHT_BOLD,
            idAbrir,
            idCerrar,
            idCliente,
            idAyuda,
            id_Numero1,
            id_Numero2,
            id_Numero3,
            id_Numero4,
            id_Numero5,
            id_Numero6,
            id_Numero7,
            id_Numero8,
            id_Numero9,
            id_Numero0,
            id_Punto,
            id_Mas,
            id_Mns,
            id_Por,
            id_Etr,
            id_Igl,
            id_LetraC,
            id_LetraCE, //potencias
            id_LetraR,
            id_11,
            id_12,
            id_13,
            id_14,
            id_LetraA,
            id_LetraB,
            id_LetraC2,
            id_LetraD,
            id_LetraE,
            id_LetraF,
            id_111,
            id_222,
            id_333,
            id_444,
            id_Pr
        };

        void OnClickAbrir(wxCommandEvent& event);
        void OnClose(wxCommandEvent& event);
        void OnButtonClick(wxCommandEvent& event);
        void OnCloseForm(wxCloseEvent& event);
        void OnClickMenuCliente(wxCommandEvent& event);
        void OnButtonClick1(wxCommandEvent& event);
        void OnButtonClick2(wxCommandEvent& event);
        void OnButtonClick3(wxCommandEvent& event);
        void OnButtonClick4(wxCommandEvent& event);
        void OnButtonClick5(wxCommandEvent& event);
        void OnButtonClick6(wxCommandEvent& event);
        void OnButtonClick7(wxCommandEvent& event);
        void OnButtonClick8(wxCommandEvent& event);
        void OnButtonClick9(wxCommandEvent& event);
        void OnButtonClick0(wxCommandEvent& event);
        void OnButtonClickPto(wxCommandEvent& event);
        void OnButtonClickMas(wxCommandEvent& event);
        void OnButtonClickMns(wxCommandEvent& event);
        void OnButtonClickPor(wxCommandEvent& event);
        void OnButtonClickEtr(wxCommandEvent& event);
        void OnButtonClickIgl(wxCommandEvent& event);
        void OnButtonClickCE(wxCommandEvent& event);
        void OnButtonClickC(wxCommandEvent& event);
        void OnButtonClickR(wxCommandEvent& event);
        void OnButtonClickA(wxCommandEvent& event);
        void OnButtonClickB(wxCommandEvent& event);
        void OnButtonClickC2(wxCommandEvent& event);
        void OnButtonClickD(wxCommandEvent& event);
        void OnButtonClickE(wxCommandEvent& event);
        void OnButtonClickF(wxCommandEvent& event);
        void OnButtonClick11(wxCommandEvent& event);
        void OnButtonClick12(wxCommandEvent& event);
        void OnButtonClick13(wxCommandEvent& event);
        void OnButtonClick14(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // VENTANA_H_INCLUDED
