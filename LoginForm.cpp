//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#pragma hdrstop

#include "LoginForm.h"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyLoginForm *MyLoginForm;
//---------------------------------------------------------------------------
__fastcall TMyLoginForm::TMyLoginForm(TComponent* Owner)
	: TForm(Owner){}
//---------------------------------------------------------------------------
std::vector<std::string> parseCommaDelimitedString(std::string line){
	std::vector<std::string> result;
	std::stringstream s_stream(line);

	while(s_stream.good()){
		std::string substr;
		getline(s_stream, substr,',');
		result.push_back(substr);
	}
	return result;
}
//---------------------------------------------------------------------------
const char* converToChartPtr(AnsiString ansiStr){
	return ansiStr.c_str();
}
//---------------------------------------------------------------------------
void __fastcall TMyLoginForm::loginButtonClick(TObject *Sender)
{
	fstream myFile;
	myFile.open("registeredUser.txt",ios::in);

	if(myFile.is_open()){
		std::string line;

		while(getline(myFile,line)){
			std::vector<std::string> parsingLine = parseCommaDelimitedString(line);
			const char* username = parsingLine.at(1).c_str();

			if(std::strcmp(username, converToChartPtr(id_loginEdit->Text))==0){
			   const char* password = parsingLine.at(2).c_str();

			   if(std::strcmp(password, converToChartPtr(pass_loginEdit->Text))==0){
					notifLabel->Text = "Success";
					if(Switch1->IsChecked){
                        MyLoginForm->Close();
						MyMainForm->Close();
						int resultA;
						resultA = system("C:\\Users\\septi\\Desktop\\DONE\\Librarian.exe");
					}
					else
					{
                        MyLoginForm->Close();
						MyMainForm->Close();
						int resultB;
						resultB = system("C:\\Users\\septi\\Desktop\\DONE\\Student.exe");
					}
			   }
			   else
					notifLabel->Text = "Wrong Password";
			}
			else
				notifLabel->Text = "Wrong Username/Password!";
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TMyLoginForm::BackNaviClick(TObject *Sender)
{
	MyLoginForm->Close();
	MyMainForm->Show();
}
//---------------------------------------------------------------------------


