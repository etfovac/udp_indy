//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TClientForm *ClientForm;
//---------------------------------------------------------------------------
__fastcall TClientForm::TClientForm(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TClientForm::ClientTimerTimer(TObject *Sender)
{
	if(IdUDPClient1->Active){

	   IdUDPClient1->SendBuffer(IdUDPClient1->Host, IdUDPClient1->Port, ToBytes(Memo1->Text));
	}
	else{

	}
}

void __fastcall TClientForm::EnableClick(TObject *Sender)
{
	IdUDPClient1->Active = (Enable->State == cbChecked);
	if(IdUDPClient1->Active){
		Status->Text = IdUDPClient1->Port;
		Memo1->Color = clWindow;
	}
	else{
	   Status->Text = "Stopped";
	   Memo1->Color = clSilver;
       Memo1->Clear();
	}
}

void __fastcall TClientForm::StatusChange(TObject *Sender)
{
     IdUDPClient1->Active = False;
	 Status->Text = IdUDPClient1->Port;
}
//---------------------------------------------------------------------------

void __fastcall TClientForm::AddressChange(TObject *Sender)
{
	IdUDPClient1->Active = False;
	IdUDPClient1->Host = Address->Text;
}
//---------------------------------------------------------------------------

void __fastcall TClientForm::FormCreate(TObject *Sender)
{
	IdUDPClient1->Active = False;
	IdUDPClient1->Host = Address->Text;
}
//---------------------------------------------------------------------------

