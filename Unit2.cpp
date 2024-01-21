//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TServer *Server;
//---------------------------------------------------------------------------
__fastcall TServer::TServer(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TServer::EnableClick(TObject *Sender)
{
   IdUDPServer1->Active = (Enable->State == cbChecked) ;
   if(IdUDPServer1->Active){
		timestamp_ms = Now();
		Memo1->Clear();
		Ports->Text = Ports->Text + " Def: " + IdUDPServer1->DefaultPort;
		Memo1->Color = clWindow;
        Status->Text = "Started";
	}
	else{
	   Status->Text = "Stopped";
	   Memo1->Color = clSilver;
	}
}
//---------------------------------------------------------------------------


void __fastcall TServer::IdUDPServer1UDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
          TIdSocketHandle *ABinding)
{
	TDateTime new_ts = Now();
	__int64 dt = MilliSecondsBetween(new_ts,timestamp_ms);
	if((AData[0]==0x01) && ( AData[1]==0x02))
	  {

	  }
	//{if you actually sent a string encoded in utf-8}
	//Msg := TEncoding.UTF8.GetString(AData);
	AnsiString Received = BytesToString(AData);

	AnsiString line = Format("%0:s@%1:d << %2:s@%3:d",ABinding->IP, ABinding->Port, ABinding->PeerIP, ABinding->PeerPort);
	Memo1->Lines->Add(line);
	line = FormatDateTime("dddd, mmmm d, yyyy ', ' hh:mm:ss.zzz", new_ts);
	line += Format(" Refresh: Period [ms] = %d", dt);
	if (dt){
		line += Format(", Rate [Hz] = %s", FormatFloat("0.000",1000.0f/dt));
	}
	Memo1->Lines->Add(line);
	Memo1->Lines->Add(Format("%d: %s", Received.Length(), Received));
	timestamp_ms = new_ts;
}
//---------------------------------------------------------------------------

void __fastcall TServer::IdUDPServer1Status(TObject *ASender, const TIdStatus AStatus,
          const UnicodeString AStatusText)
{
		Status->Text = AStatusText;
}
//---------------------------------------------------------------------------



void __fastcall TServer::FormCreate(TObject *Sender)
{
	Memo1->Clear(); Status->Clear();
	IPs->Clear(); Ports->Clear();
	Enable->State = cbUnchecked;
	IdUDPServer1->Active = False;
	IdUDPServer1->ThreadedEvent = False;
    IdUDPServer1->BroadcastEnabled = False;
	IdUDPServer1->BufferSize = 1024;
	IdUDPServer1->OnUDPRead = this->IdUDPServer1UDPRead;
	//IdUDPServer1->OnStatus = this->IdUDPServer1Status;
    IdUDPServer1->DefaultPort = 50000;
	IdUDPServer1->Bindings->Clear();
	TIdSocketHandle *pBinding = IdUDPServer1->Bindings->Add();
	pBinding->IP = "127.0.0.1";
	pBinding->Port = IdUDPServer1->DefaultPort;

	IPs->Text = pBinding->IP;
	Ports->Text = pBinding->Port;
}
//---------------------------------------------------------------------------

