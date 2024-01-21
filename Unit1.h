//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
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
//---------------------------------------------------------------------------
class TClientForm : public TForm
{
__published:	// IDE-managed Components
	TIdUDPClient *IdUDPClient1;
	TTimer *ClientTimer;
	TMemo *Memo1;
	TEdit *Status;
	TCheckBox *Enable;
	TEdit *Address;
	void __fastcall ClientTimerTimer(TObject *Sender);
	void __fastcall EnableClick(TObject *Sender);
	void __fastcall StatusChange(TObject *Sender);
	void __fastcall AddressChange(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TClientForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TClientForm *ClientForm;
//---------------------------------------------------------------------------
#endif
