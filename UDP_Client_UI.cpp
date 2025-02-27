//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDP_Client_UI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TClientForm *ClientForm;
//---------------------------------------------------------------------------
__fastcall TClientForm::TClientForm(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TClientForm::ClientTimer_Timeout(TObject *Sender)
{
	if(IdUDPClient1->Active){


	   if(IdUDPClient1->BroadcastEnabled){
		IdUDPClient1->Broadcast(ToBytes(Memo1->Text),  BPort->Text.ToInt());
	   } else {
		  IdUDPClient1->SendBuffer(IdUDPClient1->Host, IdUDPClient1->Port, ToBytes(Memo1->Text));
	   }

	}
	else{
		Enable->State = cbUnchecked;
	}
}

void __fastcall TClientForm::EnableClick(TObject *Sender)
{
	IdUDPClient1->Active = (Enable->State == cbChecked);
	if(IdUDPClient1->Active){
		StatusBar1->SimpleText = "Started";
		Memo1->Color = clWindow;
	}
	else{
	   StatusBar1->SimpleText = "Stopped";
	   Memo1->Color = clSilver;
	   //Memo1->Clear();
	}
}
//---------------------------------------------------------------------------


void __fastcall TClientForm::FormCreate(TObject *Sender)
{
	IdUDPClient1->Active = False;
	IdUDPClient1->Host = "127.0.0.1";
	//IdUDPClient1->BoundIP = "127.0.0.1";
	IdUDPClient1->BroadcastEnabled = false;
	IdUDPClient1->Port = 50000;
	//IdUDPClient1->BoundPort = 50000;
	IdUDPClient1->BufferSize = 10*1500;
	ClientTimer->Interval = 1000;
	//ClientTimer->Enabled = True;
	Address->Text = IdUDPClient1->Host;
	Port->Text = IdUDPClient1->Port;
	//https://en.delphipraxis.net/topic/6941-idudpclient-send-packet-to-broadcast-address-how-to-avoid-getting-the-data-back/
	//BoundAddress->Text = IdUDPClient1->BoundIP;
	//BoundPort->Text = IdUDPClient1->BoundPort;
	BPort->Text = IdUDPClient1->Port;
	Period->Text = ClientTimer->Interval;
	BufferSize->Text = IdUDPClient1->BufferSize;
	Memo1->TextHint = "Periodical Test Message";
	Memo1->Text = "Test Message";
	Memo1->Color = clSilver;
	StatusBar1->SimpleText = "Initialized";
}
//---------------------------------------------------------------------------

void __fastcall TClientForm::AddressChange(TObject *Sender)
{
	IdUDPClient1->Active = False;
	Address->Color = clHighlight;
	// add check for valid addr
	IdUDPClient1->Host = Address->Text;
	Address->Color = clWindow;
	Address->Text = IdUDPClient1->Host;
}
//---------------------------------------------------------------------------

void __fastcall TClientForm::Memo1Change(TObject *Sender)
{
	if(Memo1->Lines->Count < 1){
		Memo1->Lines->Add("");
	}
}
//---------------------------------------------------------------------------

void __fastcall TClientForm::PeriodChange(TObject *Sender)
{
	ClientTimer->Interval = Period->Text.ToInt();
}
//---------------------------------------------------------------------------

void __fastcall TClientForm::PortChange(TObject *Sender)
{
	 IdUDPClient1->Active = False;
	 Port->Color = clHighlight;
	 IdUDPClient1->Port = Port->Text.ToInt();
	 Port->Text = IdUDPClient1->Port;
	 Port->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TClientForm::BroadcastClick(TObject *Sender)
{
	IdUDPClient1->Active = False;
	Address->Color = clHighlight;
	// add check for valid addr
	//Address->Text = "255.255.255.255";
	IdUDPClient1->Host = Address->Text;
	Address->Color = clWindow;
	Address->Text = IdUDPClient1->Host;
    IdUDPClient1->BroadcastEnabled = Broadcast->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TClientForm::BufferSizeChange(TObject *Sender)
{
	IdUDPClient1->BufferSize = BufferSize->Text.ToInt();
}
//---------------------------------------------------------------------------

