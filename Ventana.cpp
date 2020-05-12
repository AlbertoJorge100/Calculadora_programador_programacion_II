#include "Ventana.h"
#include "VentanaCliente.h"
#include <wx/textctrl.h>
#include <wx/button.h>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <cmath>
using namespace std;

Ventana::Ventana(const wxString& title): wxFrame(NULL, wxID_ANY, title){   ///+  ESTE ES EL MENU QUE APARECE ARRIBA 
    wxMenuBar* mbar = new wxMenuBar();
    wxMenu* ArchMenu = new wxMenu(_T(""));
    ArchMenu->Append(idAbrir, _T("Calculadora Binaria"));
    ArchMenu->AppendSeparator();
    ArchMenu->Append(idCerrar, _T("Cerrar"));
    mbar->Append(ArchMenu, _T("Ver"));

    wxMenu* Cliente = new wxMenu(_T(""));
    Cliente->Append(idCliente, _T("Cliente"));                             ///+ ESTA ES LA BARRA DE MENU LAS OPCIONES OCULTAS
    mbar->Append(Cliente, _T("Edicion"));

    wxMenu* ayuda=new wxMenu(_T(""));
    ayuda->Append(idAyuda,_T("ayu"));
    mbar->Append(ayuda,_T("Ayuda"));

    SetMenuBar(mbar);

    panel= new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);      ///+ ESTE ES EL PANEL
    this->panel->SetBackgroundColour(wxColour(* wxBLACK));



    fv=new wxTextCtrl(panel,id_Pr," ",wxPoint(80,180),wxSize(230,50));        ///+ ESTE ES EL TEXTCONTROL O LA PANTALLA PRINCIPAL
    fv1=new wxTextCtrl(panel,id_111, " ", wxPoint(120,24),wxSize(188,30));    ///+ ESTA ES LA PANTALLA DE BINARIOS
    fv2=new wxTextCtrl(panel,id_222, " ", wxPoint(120,88),wxSize(188,30));    ///+ ESTA ES LA PANTALLA DE HEXADECIMALES
    fv3=new wxTextCtrl(panel,id_333, " ", wxPoint(120,56),wxSize(188,30));    ///+ ESTA ES LA PANTALLA DE DECIMALES
    fv4=new wxTextCtrl(panel,id_444, " ", wxPoint(120,120),wxSize(188,30));   ///+ ESTA ES LA PANTALLA DE OCTALES
    this->fv->Enable(false);                ///+ ESTA ES LA OPCION PARA BLOQUEAR LA PANTALLA PARA Q SOLO INGRESEMOS DATOS A TRAVEZ DE LAS TECLAS CREADAS
    this->fv1->Enable(false);               ///+ ESTA ES LA OPCION PARA BLOQUEAR LA PANTALLA PARA Q SOLO INGRESEMOS DATOS A TRAVEZ DE LAS TECLAS CREADAS
    this->fv2->Enable(false);               ///+ ESTA ES LA OPCION PARA BLOQUEAR LA PANTALLA PARA Q SOLO INGRESEMOS DATOS A TRAVEZ DE LAS TECLAS CREADAS
    this->fv3->Enable(false);               ///+ ESTA ES LA OPCION PARA BLOQUEAR LA PANTALLA PARA Q SOLO INGRESEMOS DATOS A TRAVEZ DE LAS TECLAS CREADAS
    this->fv4->Enable(false);               ///+ ESTA ES LA OPCION PARA BLOQUEAR LA PANTALLA PARA Q SOLO INGRESEMOS DATOS A TRAVEZ DE LAS TECLAS CREADAS
    wxFont myFont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT );    ///+ ESTA ES PARA DARLE TAMAÑO ALA LETRA 
    wxFont myFont2(17,wxFONTFAMILY_MODERN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT);    ///+ ESTA TAMBIEN 
   this->fv->SetFont(myFont);                            ///+ AQUI ENVIA LA CONFIGURACION DE LA LETRA ALOS TEXTCONTROL
   this->fv1->SetFont(myFont2);                                ///+ AQUI ENVIA LA CONFIGURACION DE LA LETRA ALOS TEXTCONTROL
   this->fv2->SetFont(myFont);                                  ///+ AQUI ENVIA LA CONFIGURACION DE LA LETRA ALOS TEXTCONTROL
   this->fv3->SetFont(myFont);                                  ///+ AQUI ENVIA LA CONFIGURACION DE LA LETRA ALOS TEXTCONTROL
   this->fv4->SetFont(myFont);                                   ///+ AQUI ENVIA LA CONFIGURACION DE LA LETRA ALOS TEXTCONTROL



    wxButton *btn11=new wxButton(panel,id_11,wxT("binarios"),wxPoint(20,24),wxSize(95,30));    ///+  BOTONES
    wxButton *btn12=new wxButton(panel,id_12,wxT("hexadecimales"),wxPoint(20,88),wxSize(95,30));  
    wxButton *btn13=new wxButton(panel,id_13,wxT("decimales"),wxPoint(20,56),wxSize(95,30));
    wxButton *btn14=new wxButton(panel,id_14,wxT("octales"),wxPoint(20,120),wxSize(95,30));
    wxButton *btnA=new wxButton(panel,id_LetraA,wxT("A"),wxPoint(20,180),wxSize(50,50));
    wxButton *btnB=new wxButton(panel,id_LetraB,wxT("B"),wxPoint(20,240),wxSize(50,50));
    wxButton *btnC2=new wxButton(panel,id_LetraC2,wxT("C"),wxPoint(20,300),wxSize(50,50));
    wxButton *btnD=new wxButton(panel,id_LetraD,wxT("D"),wxPoint(20,360),wxSize(50,50));
    wxButton *btnE=new wxButton(panel,id_LetraE,wxT("E"),wxPoint(20,420),wxSize(50,50));
    wxButton *btnF=new wxButton(panel,id_LetraF,wxT("F"),wxPoint(20,480),wxSize(50,50));



    wxButton *btnBr=new wxButton(panel,id_LetraC,wxT("<-"),wxPoint(80,240),wxSize(50,50));      ///+ BOTONES 
    wxButton *btnCE=new wxButton(panel,id_LetraCE,wxT("x!"),wxPoint(140,240),wxSize(50,50));
    wxButton *btnC=new wxButton(panel,id_LetraR,wxT("^"),wxPoint(200,240),wxSize(50,50));
    wxButton *btn1=new wxButton(panel,id_Numero1,wxT("1"),wxPoint(80,420),wxSize(50,50));
    wxButton *btn2=new wxButton(panel,id_Numero2,wxT("2"),wxPoint(140,420),wxSize(50,50));
    wxButton *btn3=new wxButton(panel,id_Numero3,wxT("3"),wxPoint(200,420),wxSize(50,50));
    wxButton *btn4=new wxButton(panel,id_Numero4,wxT("4"),wxPoint(80,360),wxSize(50,50));
    wxButton *btn5=new wxButton(panel,id_Numero5,wxT("5"),wxPoint(140,360),wxSize(50,50));
    wxButton *btn6=new wxButton(panel,id_Numero6,wxT("6"),wxPoint(200,360),wxSize(50,50));
    wxButton *btn7=new wxButton(panel,id_Numero7,wxT("7"),wxPoint(80,300),wxSize(50,50));
    wxButton *btn8=new wxButton(panel,id_Numero8,wxT("8"),wxPoint(140,300),wxSize(50,50));
    wxButton *btn9=new wxButton(panel,id_Numero9,wxT("9"),wxPoint(200,300),wxSize(50,50));
    wxButton *btn0=new wxButton(panel,id_Numero0,wxT("0"),wxPoint(80,480),wxSize(110,50));
    wxButton *btnPto=new wxButton(panel,id_Punto,wxT("."),wxPoint(200,480),wxSize(50,50));
    wxButton *btnMas=new wxButton(panel,id_Mas,wxT("+"),wxPoint(260,240),wxSize(50,50));
    wxButton *btnMns=new wxButton(panel,id_Mns,wxT("-"),wxPoint(260,300),wxSize(50,50));
    wxButton *btnPor=new wxButton(panel,id_Por,wxT("*"),wxPoint(260,360),wxSize(50,50));
    wxButton *btnEtr=new wxButton(panel,id_Etr,wxT("/"),wxPoint(260,420),wxSize(50,50));
    wxButton *btnIgl=new wxButton(panel,id_Igl,wxT("="),wxPoint(260,480),wxSize(50,50));



     btn11->SetBackgroundColour(wxColour(* wxGREEN));                     ///+ COLOR DE BOTONES
     btn12->SetBackgroundColour(wxColour(* wxGREEN));
     btn13->SetBackgroundColour(wxColour(* wxGREEN));
     btn14->SetBackgroundColour(wxColour(* wxGREEN));
     btnA->SetBackgroundColour(wxColour(* wxGREEN));
     btnB->SetBackgroundColour(wxColour(* wxGREEN));
     btnC2->SetBackgroundColour(wxColour(* wxGREEN));
     btnD->SetBackgroundColour(wxColour(* wxGREEN));
     btnE->SetBackgroundColour(wxColour(* wxGREEN));
     btnF->SetBackgroundColour(wxColour(* wxGREEN));
     btn0->SetBackgroundColour(wxColour(* wxGREEN));
     btn1->SetBackgroundColour(wxColour(* wxGREEN));
     btnMas->SetBackgroundColour(wxColour(* wxYELLOW));
     btnMns->SetBackgroundColour(wxColour(* wxYELLOW));
     btnPor->SetBackgroundColour(wxColour(* wxYELLOW));
     btnEtr->SetBackgroundColour(wxColour(* wxYELLOW));
     btnBr->SetBackgroundColour(wxColour(* wxYELLOW));
     btnCE->SetBackgroundColour(wxColour(* wxYELLOW));
     btnC->SetBackgroundColour(wxColour(* wxYELLOW));
     btnIgl->SetBackgroundColour(wxColour(* wxGREEN));

}



BEGIN_EVENT_TABLE(Ventana, wxFrame)
    EVT_CLOSE(Ventana::OnCloseForm)                                  ///+ TABLA DE EVENTOS
    EVT_BUTTON(id_Numero1,Ventana::OnButtonClick1)
    EVT_BUTTON(id_Numero2,Ventana::OnButtonClick2)
    EVT_BUTTON(id_Numero3,Ventana::OnButtonClick3)
    EVT_BUTTON(id_Numero4,Ventana::OnButtonClick4)
    EVT_BUTTON(id_Numero5,Ventana::OnButtonClick5)
    EVT_BUTTON(id_Numero6,Ventana::OnButtonClick6)
    EVT_BUTTON(id_Numero7,Ventana::OnButtonClick7)
    EVT_BUTTON(id_Numero8,Ventana::OnButtonClick8)
    EVT_BUTTON(id_Numero9,Ventana::OnButtonClick9)
    EVT_BUTTON(id_Numero0,Ventana::OnButtonClick0)
    EVT_BUTTON(id_Mas,Ventana::OnButtonClickMas)
    EVT_BUTTON(id_Mns,Ventana::OnButtonClickMns)
    EVT_BUTTON(id_Por,Ventana::OnButtonClickPor)
    EVT_BUTTON(id_Igl,Ventana::OnButtonClickIgl)
    EVT_BUTTON(id_Punto,Ventana::OnButtonClickPto)
    EVT_BUTTON(id_Etr,Ventana::OnButtonClickEtr)
    EVT_BUTTON(id_LetraC,Ventana::OnButtonClickC)
    EVT_BUTTON(id_LetraCE,Ventana::OnButtonClickCE)
    EVT_BUTTON(id_LetraR,Ventana::OnButtonClickR)
    EVT_BUTTON(id_LetraA,Ventana::OnButtonClickA)
    EVT_BUTTON(id_LetraB,Ventana::OnButtonClickB)
    EVT_BUTTON(id_LetraC2,Ventana::OnButtonClickC2)
    EVT_BUTTON(id_LetraD,Ventana::OnButtonClickD)
    EVT_BUTTON(id_LetraE,Ventana::OnButtonClickE)
    EVT_BUTTON(id_LetraF,Ventana::OnButtonClickF)
    EVT_BUTTON(id_11,Ventana::OnButtonClick11)
    EVT_BUTTON(id_12,Ventana::OnButtonClick12)
    EVT_BUTTON(id_13,Ventana::OnButtonClick13)
    EVT_BUTTON(id_14,Ventana::OnButtonClick14)
    EVT_MENU(idAbrir, Ventana::OnClickAbrir)
    EVT_MENU(idCerrar, Ventana::OnClose)
    EVT_MENU(idCliente, Ventana::OnClickMenuCliente)

END_EVENT_TABLE()


void Ventana::OnButtonClickA(wxCommandEvent& event){                        ///+ METODO DE TECLAS   PARA HEXADECIMALES
    if(this->fv12==true){
wxString valor=this->fv2->GetValue();
this->fv2->SetValue(valor + "A");
    }
}
void Ventana::OnButtonClickB(wxCommandEvent& event){
if(this->fv12==true){
wxString valor=this->fv2->GetValue();
this->fv2->SetValue(valor + "B");
    }
}
void Ventana::OnButtonClickC2(wxCommandEvent& event){
if(this->fv12==true){
wxString valor=this->fv2->GetValue();
this->fv2->SetValue(valor + "C");
    }
}
void Ventana::OnButtonClickD(wxCommandEvent& event){
if(this->fv12==true){
wxString valor=this->fv2->GetValue();
this->fv2->SetValue(valor + "D");
    }
}
void Ventana::OnButtonClickE(wxCommandEvent& event){
if(this->fv12==true){
wxString valor=this->fv2->GetValue();
this->fv2->SetValue(valor + "E");
    }
}
void Ventana::OnButtonClickF(wxCommandEvent& event){
if(this->fv12==true){
wxString valor=this->fv2->GetValue();
this->fv2->SetValue(valor + "F");
    }
}
void Ventana::OnButtonClick11(wxCommandEvent& event){    ///-------------------- TECLA DE BINARIOS   
this->fv11=true;
this->fv10=false;
this->opc=8;

 }
void Ventana::OnButtonClick12(wxCommandEvent& event){    ///------------- TECLA DE HEXADECIMALES   FV3  BOOL=  FV12
this->fv12=true;
this->fv10=false;
this->opc=10;
}
void Ventana::OnButtonClick13(wxCommandEvent& event){    ///-------------TECLA DE DECIMALES      FV2   BOOL=  FV13
this->fv13=true;
this->fv10=false;
this->opc=7;
}
void Ventana::OnButtonClick14(wxCommandEvent& event){    ///-------------------------TECLA DE OCTALES
this->fv14=true;
this->fv10=false;
this->opc=9;
}


void Ventana::OnClickAbrir(wxCommandEvent &event){      ///+ ESTOS SON DEL SISTEMA LOS TRAE X DEFECTO
}
void Ventana::OnClose(wxCommandEvent &event){
    Destroy();
}
void Ventana::OnCloseForm(wxCloseEvent &event){
   Destroy();
}
void Ventana::OnButtonClick(wxCommandEvent &event){
    wxMessageBox(_T("Hola "),_T("Saludo"));
}
void Ventana::OnClickMenuCliente(wxCommandEvent &event){
        VentanaCliente* v=new VentanaCliente(this, _T("Advertencia"));
        v->Show();

}


  void Ventana::OnButtonClick1(wxCommandEvent& event){       ///+ TECLA DE NUMEROS 1 EN DELANTE
    wxString v1=this->fv1->GetValue();
    wxString v2=this->fv2->GetValue();
    wxString v3=this->fv3->GetValue();
    wxString v4=this->fv4->GetValue();

      if(this->fv10==true){
    wxString valor=this->fv->GetValue();
    this->fv->SetValue(valor +"1");
      }
       if(this->fv11==true){
            this->fv1->SetValue(v1 +"1");
            this->fv12=false;
            this->fv13=false;
            this->fv14=false;
        }
        if(this->fv12==true){
            this->fv2->SetValue(v2 +"1");
               this->fv11=false;
               this->fv13=false;
               this->fv14=false;
                }
        if(this->fv13==true){
             this->fv3->SetValue(v3 + "1");
             this->fv11=false;
             this->fv12=false;
             this->fv14=false;
                   }
        if(this->fv14==true){
            this->fv4->SetValue(v4 +"1");
            this->fv11=false;
            this->fv12=false;
            this->fv13=false;
             }

}


 void Ventana::OnButtonClick2(wxCommandEvent& event){     ///+ TECLA NUMERO 2
    wxString v2=this->fv2->GetValue();
    wxString v3=this->fv3->GetValue();
    wxString v4=this->fv4->GetValue();
    if(this->fv10==true){
    wxString valor=this->fv->GetValue();
    this->fv->SetValue(valor +"2");
      }

        if(this->fv12==true){
            this->fv2->SetValue(v2 +"2");
               this->fv11=false;
               this->fv13=false;
               this->fv14=false;
                }
        if(this->fv13==true){
             this->fv3->SetValue(v3 + "2");
             this->fv11=false;
             this->fv12=false;
             this->fv14=false;
               }
        if(this->fv14==true){
            this->fv4->SetValue(v4 +"2");
            this->fv11=false;
            this->fv12=false;
            this->fv13=false;
             }
             if(this->fv11==true){
    wxMessageBox(_T("ingrese un numero valido"),_T("Error"));
             }


 }


 void Ventana::OnButtonClick3(wxCommandEvent& event){     ///+ TECLA NUMERO 3
    wxString v2=this->fv2->GetValue();
    wxString v3=this->fv3->GetValue();
    wxString v4=this->fv4->GetValue();
    if(this->fv10==true){
    wxString valor=this->fv->GetValue();
    this->fv->SetValue(valor +"3");
      }
     if(this->fv12==true){
            this->fv2->SetValue(v2 +"3");
               this->fv11=false;
               this->fv13=false;
               this->fv14=false;
                }
        if(this->fv13==true){
             this->fv3->SetValue(v3 + "3");
             this->fv11=false;
             this->fv12=false;
             this->fv14=false;
              }
        if(this->fv14==true){
            this->fv4->SetValue(v4 +"3");
            this->fv11=false;
            this->fv12=false;
            this->fv13=false;
             }
             if(this->fv11==true){
    wxMessageBox(_T("ingrese un numero valido"),_T("Error"));
             }



 }


 void Ventana::OnButtonClick4(wxCommandEvent& event){             ///+ TECLA NUMERO 4
    wxString v2=this->fv2->GetValue();
    wxString v3=this->fv3->GetValue();
    wxString v4=this->fv4->GetValue();
    if(this->fv10==true){
        wxString valor=this->fv->GetValue();
        fv->SetValue(valor + "4");
    }
        if(this->fv12==true){
            this->fv2->SetValue(v2 +"4");
               this->fv11=false;
               this->fv13=false;
               this->fv14=false;
                   }
        if(this->fv13==true){
             this->fv3->SetValue(v3 + "4");
             this->fv11=false;
             this->fv12=false;
             this->fv14=false;
                }
        if(this->fv14==true){
            this->fv4->SetValue(v4 +"4");
            this->fv11=false;
            this->fv12=false;
            this->fv13=false;
                }
         if(this->fv11==true){
    wxMessageBox(_T("ingrese un numero valido"),_T("Error"));
             }

 }


 void Ventana::OnButtonClick5(wxCommandEvent& event){           ///+ TECLA NUMERO 5
    wxString v2=this->fv2->GetValue();
    wxString v3=this->fv3->GetValue();
    wxString v4=this->fv4->GetValue();
    if(this->fv10==true){
        wxString valor=this->fv->GetValue();
        fv->SetValue(valor + "5");

    }
          if(this->fv12==true){
            this->fv2->SetValue(v2 +"5");
               this->fv11=false;
               this->fv13=false;
               this->fv14=false;
                 }
        if(this->fv13==true){
             this->fv3->SetValue(v3 + "5");
             this->fv11=false;
             this->fv12=false;
             this->fv14=false;
                }
        if(this->fv14==true){
            this->fv4->SetValue(v4 +"5");
            this->fv11=false;
            this->fv12=false;
            this->fv13=false;
            }
            if(this->fv11==true){
    wxMessageBox(_T("ingrese un numero valido"),_T("Error"));
             }

 }


 void Ventana::OnButtonClick6(wxCommandEvent& event){                    ///+ TECLA NUMERO 6
    wxString v2=this->fv2->GetValue();
    wxString v3=this->fv3->GetValue();
    wxString v4=this->fv4->GetValue();
    if(this->fv10==true){
        wxString valor=this->fv->GetValue();
        fv->SetValue(valor + "6");
        }

        if(this->fv12==true){
            this->fv2->SetValue(v2 +"6");
               this->fv11=false;
               this->fv13=false;
               this->fv14=false;
                }
        if(this->fv13==true){
             this->fv3->SetValue(v3 + "6");
             this->fv11=false;
             this->fv12=false;
             this->fv14=false;
               }
        if(this->fv14==true){
            this->fv4->SetValue(v4 +"6");
            this->fv11=false;
            this->fv12=false;
            this->fv13=false;
               }
               if(this->fv11==true){
    wxMessageBox(_T("ingrese un numero valido"),_T("Error"));
             }


 }


 void Ventana::OnButtonClick7(wxCommandEvent& event){              ///+ TECLA NUMERO 7
    wxString v2=this->fv2->GetValue();
    wxString v3=this->fv3->GetValue();
    wxString v4=this->fv4->GetValue();
    if(this->fv10==true){
        wxString valor=this->fv->GetValue();
        fv->SetValue(valor + "7");
        }

        if(this->fv12==true){
            this->fv2->SetValue(v2 +"7");
               this->fv11=false;
               this->fv13=false;
               this->fv14=false;
                  }
        if(this->fv13==true){
             this->fv3->SetValue(v3 + "7");
             this->fv11=false;
             this->fv12=false;
             this->fv14=false;
             }
        if(this->fv14==true){
            this->fv4->SetValue(v4 +"7");
            this->fv11=false;
            this->fv12=false;
            this->fv13=false;
             }
        if(this->fv11==true){
    wxMessageBox(_T("ingrese un numero valido"),_T("Error"));
             }

 }


 void Ventana::OnButtonClick8(wxCommandEvent& event){              ///+ TECLA NUMERO 8
    wxString v2=this->fv2->GetValue();
    wxString v3=this->fv3->GetValue();
    wxString v4=this->fv4->GetValue();
    if(this->fv10==true){
        wxString valor=this->fv->GetValue();
        fv->SetValue(valor + "8");
        }
         if(this->fv12==true){
            this->fv2->SetValue(v2 +"8");
               this->fv11=false;
               this->fv13=false;
               this->fv14=false;
                }
        if(this->fv13==true){
             this->fv3->SetValue(v3 + "8");
             this->fv11=false;
             this->fv12=false;
             this->fv14=false;
                 }
        if(this->fv14==true){
            this->fv4->SetValue(v4 +"8");
            this->fv11=false;
            this->fv12=false;
            this->fv13=false;
               }
        if(this->fv11==true){
    wxMessageBox(_T("ingrese un numero valido"),_T("Error"));
             }

 }


 void Ventana::OnButtonClick9(wxCommandEvent& event){                      ///+ TECLA NUMERO 9
    wxString v2=this->fv2->GetValue();
    wxString v3=this->fv3->GetValue();
    wxString v4=this->fv4->GetValue();
    if(this->fv10==true){
        wxString valor=this->fv->GetValue();
        fv->SetValue(valor + "9");
        }
          if(this->fv12==true){
            this->fv2->SetValue(v2 +"9");
               this->fv11=false;
               this->fv13=false;
               this->fv14=false;
                }
        if(this->fv13==true){
             this->fv3->SetValue(v3 + "9");
             this->fv11=false;
             this->fv12=false;
             this->fv14=false;
               }
        if(this->fv14==true){
            this->fv4->SetValue(v4 +"9");
            this->fv11=false;
            this->fv12=false;
            this->fv13=false;
                 }
      if(this->fv11==true){
            wxMessageBox(_T("ingrese un numero valido"),_T("Error"));
             }


 }


 void Ventana::OnButtonClick0(wxCommandEvent& event){                            ///+ TECLA NUMERO 0
    wxString v1=this->fv1->GetValue();
    wxString v2=this->fv2->GetValue();
    wxString v3=this->fv3->GetValue();
    wxString v4=this->fv4->GetValue();
    if(this->fv10==true){
        wxString valor=this->fv->GetValue();
        fv->SetValue(valor + "0");
        }
        if(this->fv11==true){
            this->fv1->SetValue(v1 + "0");
            this->fv12=false;
            this->fv13=false;
            this->fv14=false;
             }
        if(this->fv12==true){
            this->fv2->SetValue(v2 +"0");
               this->fv11=false;
               this->fv13=false;
               this->fv14=false;
                  }
        if(this->fv13==true){
             this->fv3->SetValue(v3 + "0");
             this->fv11=false;
             this->fv12=false;
             this->fv14=false;
              }
        if(this->fv14==true){
            this->fv4->SetValue(v4 +"0");
            this->fv11=false;
            this->fv12=false;
            this->fv13=false;
                }

    }


 void Ventana::OnButtonClickMas(wxCommandEvent& event){                      ///+ TECLA MAS
    wxString valor = this->fv->GetValue();
    this->op1 = wxAtoi(valor);
        this->fv->SetValue("");
        this->opc=1;
 }


 void Ventana::OnButtonClickMns(wxCommandEvent& event){                    ///+ TECLA MENOS
    wxString valor = this->fv->GetValue();
    this->op1=wxAtoi(valor);
    this->fv->SetValue("");
    this->opc=2;
 }


 void Ventana::OnButtonClickPor(wxCommandEvent& event){                      ///+ TECLA POR
    wxString valor = this->fv->GetValue();
    this->op1=wxAtoi(valor);
    this->fv->SetValue("");
    this->opc=3;
}


 void Ventana::OnButtonClickIgl(wxCommandEvent& event){                    ///+ TECLA IGUAL
     int rem,dec, r,rs,num,x,r1,r2,r3;


    switch(opc){
case 1:{                                                                  ///+ OPERACION SUMA
    if(this->fv10){
    wxString valor = this->fv->GetValue();
    this->op2 = wxAtoi(valor);
     r= this->op1 + this->op2;
    this->fv->SetValue(wxString::Format(wxT("%i"), r));
    }
    break;
    }
case 2:                                                                ///+ OPERACION RESTA
    {
        if(this->fv10){
    wxString valor = this->fv->GetValue();
    this->op2=wxAtoi(valor);
    r=this->op1-this->op2;
     this->fv->SetValue(wxString::Format(wxT("%i"),r));
        }
    break;
    }
case 3:                                                                 ///+ OPERACION MULTIPLICACION
    {
        if(this->fv10){
    wxString valor = this->fv->GetValue();
    this->op2=wxAtoi(valor);
    r=this->op1*this->op2;
    this->fv->SetValue(wxString::Format(wxT("%i"),r));
        }
break;
}
case 4:{                                                                ///+ OPERACION DIVISION
    if(this->fv10){
       wxString valor = this->fv->GetValue();
      this->op2=wxAtoi(valor);
       r=this->op1/this->op2;
       this->fv->SetValue(wxString::Format(wxT("%i"),r));
          }
  break;
}
case 5:                                                                  ///+ OPERACION EXPONENTE O POTENCIA
    {  //POTENCIA
        if(this->fv10){
        wxString valor=this->fv->GetValue();
        this->op2=wxAtoi(valor);
        r=(rs=pow(this->op1,this->op2));
        this->fv->SetValue(wxString::Format(wxT("%i"),r));
        }
      break;
    }
case 6:                                                                  ///+ OPERACION FACTORIAL
    {  //FACTORIAL  METODO CE
        if(this->fv10){
        int ft=1;
        wxString valor=this->fv->GetValue();
        this->op2=wxAtoi(valor);
       for (int b=1 ; b<=this->op1 ; b++)
    {
         ft=b*ft;
    }
     r=ft;
     this->fv->SetValue(wxString::Format(wxT("%i"),r));
        }
        break;
    }
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

case 7:                                                                   ///+ CONVERSION DECIMAL A BINARIO
    {
if(this->fv13==true){
wxString valor=this->fv3->GetValue();
this->op1=wxAtoi(valor);

///+///////////////////////////////////////////////////////////////////////////////////////////////////

int num, div, res,r,r1,r2,r3,r4, divs=2, dN=0, conv, i=1, oN=0;
long dec;
num=op1;

std :: string bin = "";
 div = num;
 while(div >= divs){
 res = div % 2;
  if(res == 1){
   bin = "1" + bin;
  }
   else
   {
   bin = "0" + bin;
   }
   div = div/divs;
   }
  if(div == 1){
   bin = "1" + bin;
        }
   else
   {
   bin = "0" + bin;
   }
  r=wxAtoi(bin);
   this->fv1->SetValue(wxString::Format(wxT("%i"),r));

///+//////////////////////////////////////////////////////////////////////////////////////////////////decimal a hexadecimal

dec=op1;                                                                                ///+ CONVERSION DECIMAL A HEXADECIMAL
string s = "";
while (dec > 0)
{
  rem = dec % 16;
  if (rem > 9)
  {

    switch (rem)
    {
      case 10: s = "A" + s; break;
      case 11: s = "B" + s; break;
      case 12: s = "C" + s; break;
      case 13: s = "D" + s; break;
      case 14: s = "E" + s; break;
      case 15: s = "F" + s; break;

    }


  }
  else
  {
    s = char(rem + 48) + s;
  }
  dec = dec/16;
 }

 if (s == ""){
   cout << "0";
 }
 else{
this->fv2->SetValue(wxString::Format(wxT("%s"),s));
 }
///+/////////////////////////////////////////////////////////////////////////////////////////////////////
    dN=op1;                                                                                 ///+ CONVERSION DECIMAL A OCTAL
    while (dN != 0)
    {
        conv = dN % 8;
        dN /= 8;
        oN += conv * i;
        i *= 10;
    }
  this->fv4->SetValue(wxString::Format(wxT("%i"),oN));

    }
        break;
    }

    ///+/++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

      case 8:
        {
if(this->fv11==true){                              ///DE BINARIO  A DECIMAL.............
wxString valor=this->fv1->GetValue();
this->op1=wxAtoi(valor);
 ///+////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 int exp,dig,binn,dem,digit2, place2, i,index3, digit3;
 int octalConstant[] = {0, 1, 10, 11, 100, 101, 110, 111};
  long long binry2, ocl2, tempBinary2,binary3, tempBinary3;
   int hexConstant3[] = {0, 1, 10, 11, 100, 101, 110, 111, 1000,1001, 1010, 1011, 1100, 1101, 1110, 1111};
   char hex3[20];



   binn=op1;
   exp=0;
   dem=0;
   while(((binn/10))!=0)
   {
           dig = binn % 10;
           dem = dem+ dig * pow(2,exp);
           exp++;
           binn=(binn/10);
   }
   dem=dem + binn * pow(2,exp);

   this->fv3->SetValue(wxString::Format(wxT("%i"),dem));
   ///+/////////////////////////////////////////////////////////////BINARIO A OCTAL////////////////////////////////////////////////////
   ocl2 = 0;
    place2= 1;

    binry2=op1;
    tempBinary2 = binry2;


    while(tempBinary2 != 0)
    {
           digit2 = tempBinary2 % 1000;
             for(i=0; i<8; i++)
        {
            if(octalConstant[i] == digit2)
            {
                 ocl2 = (i * place2) + ocl2;
                break;
            }
        }

         tempBinary2 /= 1000;

        place2*= 10;
    }

    std::string numb;
   std::stringstream strstream;
    strstream << ocl2;
      strstream >> numb;
      this->fv4->SetValue(wxString::Format(wxT("%s"),numb));
   ///*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                                                  ///+ CONVERSION DE BINARIO A HEXADECIMAL

     binary3=op1;
     tempBinary3 = binary3;
    index3 = 0;

    while(tempBinary3!=0)
    {
         digit3 = tempBinary3 % 10000;

         for(int i=0; i<16; i++)
        {
            if(hexConstant3[i] == digit3)
            {
                if(i<10)
                {
                     hex3[index3] = (char)(i + 48);
                }
                else
                {
                    hex3[index3] = (char)((i-10) + 65);
                }

                index3++;
                break;
            }
        }


        tempBinary3 /= 10000;
    }
    hex3[index3] = '\0';

    strrev(hex3);
    string str3(hex3);

    this->fv2->SetValue(wxString::Format(wxT("%s"),str3));

    }
        break;
        }
      case 9:
        {
            if(this->fv14==true){                              ///OCTAL  A DECIMAL.......
             wxString valor=this->fv4->GetValue();
             this->op1=wxAtoi(valor);
   int dNm=0,i=0,rm,oNm=0,octal, tempOctal, binary, place,rem11;
   int OVALUE[] = {0, 1, 10, 11, 100, 101, 110, 111};
    long long ocl, templ, binry, plc, in;

   string envi;
   oNm=op1;
   char hex[65] = "";
    while (oNm != 0)
    {
        rm = oNm % 10;
        oNm /= 10;
        dNm += rm * pow(8, i);
        ++i;
    }

   this->fv3->SetValue(wxString::Format(wxT("%i"),dNm));

///+//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int OCTALVALUES[] = {0, 1, 10, 11, 100, 101, 110, 111};                          ///+ CONVERSION DE OCTAL A HEXADECIMAL

    place = 1;
    binary = 0;
     octal=op1;
    tempOctal = octal;

    while(tempOctal > 0)
    {
        rem11 = tempOctal % 10;
        binary = (OCTALVALUES[rem11] * place) + binary;
        tempOctal /= 10;

        place *= 1000;
    }


    while(binary > 0)
    {
        rem11 = binary % 10000;
        switch(rem11)
        {
            case 0:
                strcat(hex, "0");
                break;
            case 1:
                strcat(hex, "1");
                break;
            case 10:
                strcat(hex, "2");
                break;
            case 11:
                strcat(hex, "3");
                break;
            case 100:
                strcat(hex, "4");
                break;
            case 101:
                strcat(hex, "5");
                break;
            case 110:
                strcat(hex, "6");
                break;
            case 111:
                strcat(hex, "7");
                break;
            case 1000:
                strcat(hex, "8");
                break;
            case 1001:
                strcat(hex, "9");
                break;
            case 1010:
                strcat(hex, "A");
                break;
            case 1011:
                strcat(hex, "B");
                break;
            case 1100:
                strcat(hex, "C");
                break;
            case 1101:
                strcat(hex, "D");
                break;
            case 1110:
                strcat(hex, "E");
                break;
            case 1111:
                strcat(hex, "F");
            break;
        }

        binary /= 10000;
    }

    strrev(hex);
    string str(hex);
    stringstream ss;
    ss<<octal;
    envi=(ss.str()+str);
    this->fv2->SetValue(wxString::Format(wxT("%s"),str));
  ///+///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                                                                               ///+ CONVERSION DE OCTAL A BINARIO

    ocl=op1;
    templ = ocl;
    binry = 0;
    plc  = 1;

     while(templ > 0)
    {
         in = templ % 10;
        binry = (OVALUE[in] * plc) + binry;
         templ /= 10;

        plc *= 1000;
    }

    std::string number;
std::stringstream strstream;
strstream << binry;
strstream >> number;

this->fv1->SetValue(wxString::Format(wxT("%s"),number));

///+////////////////////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            }
            break;
        }


            case 10:                                                                           ///+ CONVERSION DE HEXADECIMAL A BINARIO
               {
  if(this->fv12==true){
        wxString valor=this->fv2->GetValue();
        long long decimal5, place5,octal6, bin6, place6;
        int i = 0, val5, len5,rem6, val6;
        char hex4[17], bin4[65] = "";
        char hex5[17];
        char hex6[17];

std :: string cadena = std :: string ( valor. mb_str ( ) ) ;
strcpy(hex4,cadena.c_str());
strcpy(hex5,cadena.c_str());
strcpy(hex6,cadena.c_str());


    for(i=0; hex4[i]!='\0'; i++)
    {
        switch(hex4[i])
        {
            case '0':
                strcat(bin4, "0000");
                break;
            case '1':
                strcat(bin4, "0001");
                break;
            case '2':
                strcat(bin4, "0010");
                break;
            case '3':
                strcat(bin4, "0011");
                break;
            case '4':
                strcat(bin4, "0100");
                break;
            case '5':
                strcat(bin4, "0101");
                break;
            case '6':
                strcat(bin4, "0110");
                break;
            case '7':
                strcat(bin4, "0111");
                break;
            case '8':
                strcat(bin4, "1000");
                break;
            case '9':
                strcat(bin4, "1001");
                break;
            case 'a':
            case 'A':
                strcat(bin4, "1010");
                break;
            case 'b':
            case 'B':
                strcat(bin4, "1011");
                break;
            case 'c':
            case 'C':
                strcat(bin4, "1100");
                break;
            case 'd':
            case 'D':
                strcat(bin4, "1101");
                break;
            case 'e':
            case 'E':
                strcat(bin4, "1110");
                break;
            case 'f':
            case 'F':
                strcat(bin4, "1111");
                break;


        }
    }
     string d(bin4);
     this->fv1->SetValue(wxString::Format(wxT("%s"),d));
     ///+/////////////////////////////////////////////////////////////////////////////////////////////////////////

                                                                                          ///+ CONVERSION DE HEXADECIMAL A DECIMAL
    decimal5 = 0;
    place5 = 1;


    len5 = strlen(hex5);
    len5--;

     for(int i=0; hex5[i]!='\0'; i++)
    {


        if(hex5[i]>='0' && hex5[i]<='9')
        {
            val5 = hex5[i] - 48;
        }
        else if(hex5[i]>='a' && hex5[i]<='f')
        {
            val5 = hex5[i] - 97 + 10;
        }
        else if(hex5[i]>='A' && hex5[i]<='F')
        {
            val5 = hex5[i] - 65 + 10;
        }

        decimal5 += val5 * pow(16, len5);
        len5--;
    }
    std::string number22;
std::stringstream strstream22;
strstream22 << decimal5;
strstream22 >> number22;

this->fv3->SetValue(wxString::Format(wxT("%s"),number22));
///+/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                                                        ///+ CONVERSION DE HEXADECIMAL A OCTAL
    octal6 = 0ll;
    bin6 = 0ll;
    place6 = 0ll;


    for(int i=0; hex6[i]!='\0'; i++)
    {
        bin6 = bin6* place6;

        switch(hex6[i])
        {
            case '0':
                bin6 += 0;
                break;
            case '1':
                bin6 += 1;
                break;
            case '2':
                bin6 += 10;
                break;
            case '3':
                bin6 += 11;
                break;
            case '4':
                bin6 += 100;
                break;
            case '5':
                bin6 += 101;
                break;
            case '6':
                bin6 += 110;
                break;
            case '7':
                bin6 += 111;
                break;
            case '8':
                bin6 += 1000;
                break;
            case '9':
                bin6 += 1001;
                break;
            case 'a':
            case 'A':
                bin6 += 1010;
                break;
            case 'b':
            case 'B':
                bin6 += 1011;
                break;
            case 'c':
            case 'C':
                bin6 += 1100;
                break;
            case 'd':
            case 'D':
                bin6 += 1101;
                break;
            case 'e':
            case 'E':
                bin6 += 1110;
                break;
            case 'f':
            case 'F':
                bin6 += 1111;
                break;

        }

        place6 = 10000;
    }

    place6 = 1;


    while(bin6 > 0)
    {
        rem6 = bin6 % 1000;

        switch(rem6)
        {
            case 0:
                val6 = 0;
                break;
            case 1:
                val6 = 1;
                break;
            case 10:
                val6 = 2;
                break;
            case 11:
                val6 = 3;
                break;
            case 100:
                val6 = 4;
                break;
            case 101:
                val6 = 5;
                break;
            case 110:
                val6 = 6;
                break;
            case 111:
                val6 = 7;
                break;
        }

        octal6 = (val6 * place6) + octal6;
        bin6 /= 1000;

        place6 *= 10;
    }


std::string number6;
std::stringstream strstream6;
strstream6 << octal6;
strstream6 >> number6;
this->fv4->SetValue(wxString::Format(wxT("%s"),number6));
    }
     break;
   }



  }

 }



 void Ventana::OnButtonClickPto(wxCommandEvent& event){                              ///+ TECLA PUNTO
    wxString valor = this->fv->GetValue();
    fv->SetValue(valor + ".");
 }

 
 void Ventana::OnButtonClickEtr(wxCommandEvent& event){                                 ///+ TECLA ENTRE
    wxString valor = this->fv->GetValue();
    this->op1=wxAtoi(valor);
    this->fv->SetValue("");
    this->opc=4;

 }


 void Ventana::OnButtonClickR(wxCommandEvent& event){                                      ///+ TECLA POTENCIA
   wxString valor = this->fv->GetValue();
      this->op1 = wxAtoi(valor);
        this->fv->SetValue("");
        this->opc=5;

 }


 void Ventana::OnButtonClickC(wxCommandEvent& event){                                       ///+ TECLA BORRAR O RESETEAR
  this->fv->SetValue("");
  this->fv1->SetValue("");
  this->fv2->SetValue("");
  this->fv3->SetValue("");
  this->fv4->SetValue("");
  this->fv10=true;
  this->fv11=false;
  this->fv12=false;
  this->fv13=false;
  this->fv14=false;
 }


void Ventana::OnButtonClickCE(wxCommandEvent& event){                                           ///+ TECLA FACTORIAL
 wxString valor = this->fv->GetValue();
    this->op1=wxAtoi(valor);
    this->fv->SetValue("");
    this->opc=6;

}


