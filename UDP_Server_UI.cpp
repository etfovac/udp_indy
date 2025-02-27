//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDP_Server_UI.h"
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
		Memo1->Color = clWindow;
		StatusBar1->SimpleText = "Started";
	}
	else{
		StatusBar1->SimpleText = "Stopped";
	    Memo1->Color = clSilver;
	}
}
//---------------------------------------------------------------------------


void __fastcall TServer::IdUDPServer1UDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
          TIdSocketHandle *ABinding)
{
	TDateTime new_ts = Now();
	__int64 dt = MilliSecondsBetween(new_ts,timestamp_ms);

	AnsiString line = Format("%0:s@%1:d << %2:s@%3:d",ABinding->IP, ABinding->Port, ABinding->PeerIP, ABinding->PeerPort);
	Memo1->Lines->Add(line);
	line = FormatDateTime("dddd, mmmm d, yyyy ', ' hh:mm:ss.zzz", new_ts);
	line += Format(" Refresh: Period [ms] = %d", dt);
	if (dt){
		line += Format(", Rate [Hz] = %s", FormatFloat("0.000",1000.0f/dt));
	}
	Memo1->Lines->Add(line);
	/*{if you actually sent a string encoded in utf-8}
	Msg := TEncoding.UTF8.GetString(AData);*/
	AnsiString Received = BytesToUInt32(AData);
	Memo1->Lines->Add(Format("UInt32: %d: %s", Received.Length(), Received));
    Received = BytesToString(AData);
	Memo1->Lines->Add(Format("String : %d: %s", Received.Length(), Received));

    if((AData[0]==0x01) && ( AData[1]==0x02))
	{
		 IntToHex(AData[1]);
         /* processing... or copy to buffer*/
	}
	timestamp_ms = new_ts;
}
//---------------------------------------------------------------------------

void __fastcall TServer::IdUDPServer1Status(TObject *ASender, const TIdStatus AStatus,
          const UnicodeString AStatusText)
{
	StatusBar1->SimpleText = AStatusText;
}
//---------------------------------------------------------------------------


void __fastcall TServer::FormCreate(TObject *Sender)
{
	Memo1->Clear(); //Status->Clear();
	//IPs->Clear(); DefaultPort->Clear();
	//Enable->State = cbUnchecked;
	IdUDPServer1->Active = False;
	IdUDPServer1->ThreadedEvent = False;
    IdUDPServer1->BroadcastEnabled = False;
	IdUDPServer1->BufferSize = 100*1500;
	IdUDPServer1->OnUDPRead = this->IdUDPServer1UDPRead;
	//IdUDPServer1->OnStatus = this->IdUDPServer1Status;
	IdUDPServer1->DefaultPort = 50000;
	IdUDPServer1->Bindings->Clear();
	TIdSocketHandle *pBinding = IdUDPServer1->Bindings->Add();
	//pBinding->IP = "127.0.0.1";  // Listen on loopback
	pBinding->IP = "0.0.0.0";   // Listen on all interfaces
	pBinding->Port = IdUDPServer1->DefaultPort;

	IPs->Text = pBinding->IP;
	DefaultPort->Text = pBinding->Port;
	BufferSize->Text = IdUDPServer1->BufferSize;
	StatusBar1->SimplePanel = True;
	StatusBar1->SimpleText = "Initialized";
    Memo1->Color = clSilver;
}
//---------------------------------------------------------------------------

void __fastcall TServer::DefaultPortChange(TObject *Sender)
{
	IdUDPServer1->Active = False;
    Enable->State = cbUnchecked;
	DefaultPort->Color = clHighlight;
	if(!DefaultPort->Text.IsEmpty()){
		IdUDPServer1->DefaultPort = DefaultPort->Text.ToInt();
	}
	IdUDPServer1->Bindings->Clear();
	TIdSocketHandle *pBinding = IdUDPServer1->Bindings->Add();
	pBinding->IP = IPs->Text;
	pBinding->Port = IdUDPServer1->DefaultPort;
	IPs->Text = pBinding->IP;
	DefaultPort->Text = pBinding->Port;
	DefaultPort->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TServer::BufferSizeChange(TObject *Sender)
{
	IdUDPServer1->BufferSize = BufferSize->Text.ToInt();
}
//---------------------------------------------------------------------------

void __fastcall TServer::IPsChange(TObject *Sender)
{
	IdUDPServer1->Active = False;
	Enable->State = cbUnchecked;
	IPs->Color = clHighlight;
	IdUDPServer1->Bindings->Clear();
	TIdSocketHandle *pBinding = IdUDPServer1->Bindings->Add();
	pBinding->IP = IPs->Text;
	pBinding->Port = IdUDPServer1->DefaultPort;
	IPs->Text = pBinding->IP;
	DefaultPort->Text = pBinding->Port;
	IPs->Color = clWindow;
}
//---------------------------------------------------------------------------

