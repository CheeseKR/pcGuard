//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
bool permission=false;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormDestroy(TObject *Sender)
{
	if(permission==false)
	{

		ShowMessage("cannot exit because of no permission");
		system("Project1.exe");

	}
	else
	{
        ShowMessage("Exiting with administrator permission.....");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(Edit1->Text=="admin1234")
	{
		permission=true;
		Edit1->Enabled=false;
		Button1->Enabled=false;
		ShowMessage("correct password");
	}
	else
	{
		ShowMessage("wrong password");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItem1Click(TObject *Sender)
{
    ShowMessage("Trying to exit program....");
	Form1->Close();

}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y)
{
	if(Button==TMouseButton::mbRight)
	{
        PopupMenu1->Popup(X,Y);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    system("\"C:\\WINDOWS\\system32\\notepad.exe\"");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    system("\"C:\\WINDOWS\\system32\\mspaint.exe\"");
}
//---------------------------------------------------------------------------

