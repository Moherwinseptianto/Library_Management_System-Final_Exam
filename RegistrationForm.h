//---------------------------------------------------------------------------

#ifndef RegistrationFormH
#define RegistrationFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TMyRegistrationForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *nameEdit;
	TLabel *nameLabel;
	TEdit *usernameEdit;
	TLabel *idLabel;
	TEdit *passwordEdit;
	TEdit *reTypeEdit;
	TLabel *passwordLabel;
	TButton *saveButton;
	TLabel *RetypePassword;
	TLabel *notifPass;
	TClearEditButton *ClearEditButton1;
	TClearEditButton *ClearEditButton2;
	TClearEditButton *ClearEditButton3;
	TClearEditButton *ClearEditButton4;
	TButton *backNav;
	TButton *restart;
	void __fastcall saveButtonClick(TObject *Sender);
	void __fastcall backNavClick(TObject *Sender);
	void __fastcall restartClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMyRegistrationForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMyRegistrationForm *MyRegistrationForm;
//---------------------------------------------------------------------------
#endif
