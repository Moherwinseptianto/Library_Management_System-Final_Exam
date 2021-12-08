//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>
#include <string>
#pragma hdrstop
#include <IdHashMessageDigest.hpp>

#include "RegistrationForm.h"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyRegistrationForm *MyRegistrationForm;
//---------------------------------------------------------------------------
__fastcall TMyRegistrationForm::TMyRegistrationForm(TComponent* Owner)
	: TForm(Owner){}
//---------------------------------------------------------------------------
void __fastcall TMyRegistrationForm::saveButtonClick(TObject *Sender)
{
	fstream myFile;
	myFile.open("registeredUser.txt",ios::app);

	if(myFile.is_open())
	{
			if(passwordEdit!=reTypeEdit)
				{
					notifPass->Text = "Your password is Wrong";
					saveButton->Enabled = False;
					restart->Visible = True;
				}
			else
				{
					AnsiString name = nameEdit->Text;
					AnsiString username  = usernameEdit->Text;
					AnsiString pass = passwordEdit->Text;

					myFile<<name<<","<<username<<","<<pass<<"\n";
					myFile.close();
					this->Close();
					MyMainForm->Show();
				}
	}
}
//---------------------------------------------------------------------------
void __fastcall TMyRegistrationForm::backNavClick(TObject *Sender)
{   nameEdit->Text=EmptyStr;
	usernameEdit->Text=EmptyStr;
	passwordEdit->Text=EmptyStr;
	reTypeEdit->Text=EmptyStr;
	notifPass->Text=" ";
	saveButton->Enabled = True;
	restart->Visible = False;
	MyRegistrationForm->Close();
	MyMainForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMyRegistrationForm::restartClick(TObject *Sender)
{   nameEdit->Text=EmptyStr;
	usernameEdit->Text=EmptyStr;
	passwordEdit->Text=EmptyStr;
	reTypeEdit->Text=EmptyStr;
	notifPass->Text=" ";
	saveButton->Enabled = True;
	restart->Visible = False;
}
//---------------------------------------------------------------------------
