//---------------------------------------------------------------------------

#ifndef LoginFormH
#define LoginFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TMyLoginForm : public TForm
{
__published:	// IDE-managed Components
	TButton *loginButton;
	TEdit *id_loginEdit;
	TLabel *id_loginLabel;
	TEdit *pass_loginEdit;
	TLabel *pass_loginLabel;
	TLabel *notifLabel;
	TClearEditButton *ClearEditButton1;
	TClearEditButton *ClearEditButton2;
	TButton *BackNavi;
	TSwitch *Switch1;
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall loginButtonClick(TObject *Sender);
	void __fastcall BackNaviClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMyLoginForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMyLoginForm *MyLoginForm;
//---------------------------------------------------------------------------
#endif
