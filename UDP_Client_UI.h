//---------------------------------------------------------------------------

#ifndef UDP_Client_UIH
#define UDP_Client_UIH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPClient.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TClientForm : public TForm
{
__published:	// IDE-managed Components
	TIdUDPClient *IdUDPClient1;
	TTimer *ClientTimer;
	TMemo *Memo1;
	TCheckBox *Enable;
	TEdit *Address;
	TEdit *Port;
	TEdit *Period;
	TCheckBox *Broadcast;
	TEdit *BufferSize;
	TGroupBox *BroadcastProperties;
	TEdit *BPort;
	TGroupBox *ServerProperties;
	TStatusBar *StatusBar1;
	TGroupBox *RepeatProperties;
	TGroupBox *BufferProperties;
	TLabel *Label1;
	TLabel *ms;
	TGroupBox *Controls;
	void __fastcall ClientTimer_Timeout(TObject *Sender);
	void __fastcall EnableClick(TObject *Sender);
	void __fastcall AddressChange(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Memo1Change(TObject *Sender);
	void __fastcall PeriodChange(TObject *Sender);
	void __fastcall PortChange(TObject *Sender);
	void __fastcall BroadcastClick(TObject *Sender);
	void __fastcall BufferSizeChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TClientForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TClientForm *ClientForm;
//---------------------------------------------------------------------------
#endif
