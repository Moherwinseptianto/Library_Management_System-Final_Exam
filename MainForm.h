//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Ani.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.ScrollBox.hpp>
#include <System.Rtti.hpp>
#include <FMX.Dialogs.hpp>
//---------------------------------------------------------------------------
class TMyMainForm : public TForm
{
__published:	// IDE-managed Components
	TButton *loginNavButton;
	TButton *registrationNavButton;
	TBitmapAnimation *BitmapAnimation1;
	TColorAnimation *ColorAnimation1;
	TLabel *Welcome;
	void __fastcall loginNavButtonClick(TObject *Sender);
	void __fastcall registrationNavButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMyMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMyMainForm *MyMainForm;
//---------------------------------------------------------------------------
#endif
