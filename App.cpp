#include "App.h"
#include "Ventana.h"
IMPLEMENT_APP(App)

bool App::OnInit(){
    Ventana *ejemplo=new Ventana(wxT("Calculadora"));
    ejemplo->SetSize(350,620);
    ejemplo->SetPosition(wxDefaultPosition);
    ejemplo->SetIcon(wxICON(e));
    ejemplo->Show();
    return true;
}

