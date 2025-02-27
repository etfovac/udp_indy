//---------------------------------------------------------------------------

#ifndef UDP_Server_UIH
#define UDP_Server_UIH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPServer.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <IdGlobal.hpp>
#include <IdSocketHandle.hpp>
#include <System.DateUtils.hpp>
#include <System.SysUtils.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TServer : public TForm
{
__published:	// IDE-managed Components
	TIdUDPServer *IdUDPServer1;
	TCheckBox *Enable;
	TMemo *Memo1;
	TEdit *IPs;
	TEdit *DefaultPort;
	TEdit *BufferSize;
	TStatusBar *StatusBar1;
	TGroupBox *Controls;
	void __fastcall EnableClick(TObject *Sender);
	void __fastcall IdUDPServer1UDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
          TIdSocketHandle *ABinding);
	void __fastcall IdUDPServer1Status(TObject *ASender, const TIdStatus AStatus, const UnicodeString AStatusText);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DefaultPortChange(TObject *Sender);
	void __fastcall BufferSizeChange(TObject *Sender);
	void __fastcall IPsChange(TObject *Sender);

private:	// User declarations
    TDateTime timestamp_ms;
public:		// User declarations
	__fastcall TServer(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TServer *Server;
//---------------------------------------------------------------------------
#endif
