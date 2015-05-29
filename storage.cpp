//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "storage.h"
#include "storageedit.h"
#include "mainform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormStorage *FormStorage;
//---------------------------------------------------------------------------
__fastcall TFormStorage::TFormStorage(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormStorage::FormCreate(TObject *Sender)
{
	StringGrid1->ColWidths[0]=18;
	StringGrid1->ColWidths[1]=100;
	StringGrid1->ColWidths[2]=284;
	StringGrid1->ColWidths[3]=90;
	StringGrid1->ColWidths[4]=90;
	StringGrid1->ColWidths[5]=60;
	StringGrid1->ColWidths[6]=60;
	StringGrid1->ColWidths[7]=0;
	StringGrid1->Cells[1][0]="��� ������������";
	StringGrid1->Cells[2][0]="�������� ������";
	StringGrid1->Cells[3][0]="�������� �";
	StringGrid1->Cells[4][0]="����������� �";
	StringGrid1->Cells[5][0]="���� ������";
	StringGrid1->Cells[6][0]="���������";
	Left=Screen->Width/2-Width/2;
	Top=Screen->Height/2-Height;

}
//---------------------------------------------------------------------------
void __fastcall TFormStorage::NewEquipTip(UnicodeString tipname, UnicodeString fname)
{
   ADOQuery1->Close();
   ADOQuery1->SQL->Clear();
   ADOQuery1->SQL->Add(L"select * from tipequip where tipname='"+tipname+L"'");
   ADOQuery1->Open();
   int count=ADOQuery1->RecordCount;
   ADOQuery1->Close();
   if(!count)
   {
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("insert into tipequip(tipname) values('"+tipname+"')");
		ADOQuery1->ExecSQL();
		ADOQuery1->Close();

   }
   ADOQuery1->Close();
   ADOQuery1->SQL->Clear();
   ADOQuery1->SQL->Add(L"select * from equip where tip='"+tipname+L"' and fname='"+fname+L"'");
   ADOQuery1->Open();
   count=ADOQuery1->RecordCount;
   ADOQuery1->Close();
   if(!count)
   {
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("insert into equip(tip,fname) values('"+tipname+L"','"+fname+L"')");
		ADOQuery1->ExecSQL();
		ADOQuery1->Close();

   }
}

void __fastcall TFormStorage::SpeedButton1Click(TObject *Sender)
{
	FormStorageEdit->Left=Left+Width-FormStorageEdit->Width;
	FormStorageEdit->Top=Top-20;
	FormStorageEdit->ComboBox1->Text="";
	FormStorageEdit->ComboBox2->Text="";
	FormStorageEdit->Edit2->Text="";
	FormStorageEdit->Edit3->Text="";
	FormStorageEdit->Edit4->Text="";
	FormStorageEdit->opennew=1;
	FormStorageEdit->ShowModal();
	int mr=FormStorageEdit->BitBtn1->ModalResult;

	if(mr==mrOk)
	{
		 UnicodeString tipepuip=FormStorageEdit->ComboBox1->Text;
		 UnicodeString fname=FormStorageEdit->ComboBox2->Text;
		 UnicodeString snamber=FormStorageEdit->Edit2->Text;
		 UnicodeString inamber=FormStorageEdit->Edit3->Text;
		 UnicodeString year=FormStorageEdit->Edit4->Text;
		 NewEquipTip(tipepuip,fname);

		 ADOQuery1->SQL->Clear();
		 ADOQuery1->SQL->Add("insert into storage(tipname,equipname,sn,inv,daterelease) values('"+tipepuip+"','"+fname+"','"+snamber+"','"+inamber+"','"+year+"')");
		 //ADOQuery1->SQL->Add("insert into storage(tipname,equipname) values('�������','HP LaserJet')");
		 ADOQuery1->ExecSQL();
		 ADOQuery1->Close();
		 FormShow(FormStorage);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormStorage::FormShow(TObject *Sender)
{
   StringGrid1->RowCount=2;
   for(int i=0;i<StringGrid1->ColCount;i++)
       StringGrid1->Cells[i][1]="";
   ADOQuery1->Close();
   ADOQuery1->SQL->Clear();
   ADOQuery1->SQL->Add("select * from storage ");
   ADOQuery1->Open();
   ADOQuery1->First();
   int k=1;
   while(!ADOQuery1->Eof)
   {

		 if(StringGrid1->RowCount-1<k)StringGrid1->RowCount++;
		StringGrid1->Cells[1][k]=ADOQuery1->FieldByName("tipname")->AsAnsiString;
		StringGrid1->Cells[2][k]=ADOQuery1->FieldByName("equipname")->AsAnsiString;
		StringGrid1->Cells[3][k]=ADOQuery1->FieldByName("sn")->AsAnsiString;
		StringGrid1->Cells[4][k]=ADOQuery1->FieldByName("inv")->AsAnsiString;
		StringGrid1->Cells[5][k]=ADOQuery1->FieldByName("daterelease")->AsAnsiString;
		StringGrid1->Cells[6][k]="";
		StringGrid1->Cells[7][k]=ADOQuery1->FieldByName("cod")->AsAnsiString;
		k++;
	   ADOQuery1->Next();
   }
   SpeedButton2->Enabled=(k>1 && StringGrid1->Row>0 && !StringGrid1->Cells[1][1].IsEmpty());
   SpeedButton3->Enabled=(k>1 && StringGrid1->Row>0 && !StringGrid1->Cells[1][1].IsEmpty());

}
//---------------------------------------------------------------------------


void __fastcall TFormStorage::SpeedButton2Click(TObject *Sender)
{
	int row=StringGrid1->Row;
	if(StringGrid1->Cells[1][1].IsEmpty()) return;
	FormStorageEdit->Left=Left+Width-FormStorageEdit->Width;
	FormStorageEdit->Top=Top-20;


	FormStorageEdit->ComboBox1->Text=StringGrid1->Cells[1][row];
	FormStorageEdit->ComboBox2->Text=StringGrid1->Cells[2][row];
	FormStorageEdit->Edit2->Text=StringGrid1->Cells[3][row];
	FormStorageEdit->Edit3->Text=StringGrid1->Cells[4][row];
	FormStorageEdit->Edit4->Text=StringGrid1->Cells[5][row];
	UnicodeString cod=StringGrid1->Cells[7][row];
	FormStorageEdit->opennew=0;
	FormStorageEdit->ShowModal();
	int mr=FormStorageEdit->BitBtn1->ModalResult;
	if(mr==mrOk)
	{
		 UnicodeString tipepuip=FormStorageEdit->ComboBox1->Text;
		 UnicodeString fname=FormStorageEdit->ComboBox2->Text;
		 UnicodeString snamber=FormStorageEdit->Edit2->Text;
		 UnicodeString inamber=FormStorageEdit->Edit3->Text;
		 UnicodeString year=FormStorageEdit->Edit4->Text;
		 NewEquipTip(tipepuip,fname);

		 ADOQuery1->SQL->Clear();
		 UnicodeString query="update storage set tipname='"+tipepuip+"',";
		 query+="equipname='"+fname+"',";
		 query+="sn='"+snamber+"',";
		 query+="inv='"+inamber+"',";
		 query+="daterelease='"+year+"'";
		 query+=" where cod="+cod;
		 ADOQuery1->SQL->Add(query);

		 ADOQuery1->ExecSQL();
		 ADOQuery1->Close();
		 FormShow(FormStorage);
	}

}
//---------------------------------------------------------------------------

void __fastcall TFormStorage::BitBtn1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormStorage::SpeedButton3Click(TObject *Sender)
{
	int row=StringGrid1->Row;
	if(row<1) return;
	UnicodeString tip=StringGrid1->Cells[1][row];
	UnicodeString fname=StringGrid1->Cells[2][row];
	UnicodeString cod=StringGrid1->Cells[7][row];

	UnicodeString qu=L"������� ���, ������ ������� "+tip+L":"+fname;
	UnicodeString cap=L"��������";
	int otv=Application->MessageBox(qu.w_str(),cap.w_str(),MB_YESNO);
	if(otv==6)
	{
		 ADOQuery1->SQL->Clear();
		 UnicodeString query="delete from storage";
		 query+=" where cod="+cod;
		 ADOQuery1->SQL->Add(query);

		 ADOQuery1->ExecSQL();
		 ADOQuery1->Close();
		 FormShow(FormStorage);
    }
}
//---------------------------------------------------------------------------
