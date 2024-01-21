//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
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
//---------------------------------------------------------------------------
class TServer : public TForm
{
__published:	// IDE-managed Components
	TIdUDPServer *IdUDPServer1;
	TCheckBox *Enable;
	TEdit *Status;
	TMemo *Memo1;
	TEdit *IPs;
	TEdit *Ports;
	void __fastcall EnableClick(TObject *Sender);
	void __fastcall IdUDPServer1UDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
          TIdSocketHandle *ABinding);
	void __fastcall IdUDPServer1Status(TObject *ASender, const TIdStatus AStatus, const UnicodeString AStatusText);
	void __fastcall FormCreate(TObject *Sender);

private:	// User declarations
    TDateTime timestamp_ms;
public:		// User declarations
	__fastcall TServer(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TServer *Server;
//---------------------------------------------------------------------------
#endif
