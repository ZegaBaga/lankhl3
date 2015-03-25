// ---------------------------------------------------------------------------

#include <vcl.h>
#include "mmsystem.h"
#pragma hdrstop

#include "object.h"
#include "mainform.h"
#include "MyClass.h"
#include "netapi.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

// ---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender) {
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action) {
	Form3->Tag = 0;
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender) {
  /*	TDataTV *dt;
	if (isnew)
		dt = new TDataTV();
	else
		dt = (TDataTV*)Form1->TreeView1->Selected->Data;

	//int curindex = Form1->TabControl1->TabIndex;

	TTreeNode *Node1;
	Node1 = Form1->TreeView1->Selected;

	dt->IP = Edit4->Text;
	dt->Name = Edit6->Text;
	dt->Psevd = Edit1->Text;
	dt->Coment = Memo1->Text;
	dt->NoCheck = CheckBox2->Checked;
	if (Edit3->Text.Trim().IsEmpty())
		Edit3->Text = "0";
	dt->Port = StrToInt(Edit3->Text.Trim());

	dt->Login = Edit7->Text;
	if(Edit8->Text!="/HIDE/" && !Edit8->Text.IsEmpty())
		dt->Pass =XOR_Crypt(Edit8->Text,true);

	dt->Domen = Edit9->Text;
	dt->Wid=Wid;
	dt->CheckW = !dt->Wid.IsEmpty();
	dt->ExIP=CBexip->Checked;
	dt->SoundOnPath = OnLine->Text;
	dt->SoundOffPath = OffLine->Text;
	dt->OnLineMess=EditOnLineMess->Text;
	dt->OffLineMess=EditOffLineMess->Text;

	dt->NoCheckR = CheckBox1->Checked;
	dt->TipItems=ComboBoxEx1->ItemIndex;
	dt->imageIndex=1;
	if (CheckBox1->Tag == 0) {
		if (Node1 != NULL) {
			TDataTV *dtr = (TDataTV*)Form1->TreeView1->Selected->Data;
			dt->ParentID = dtr->id;
			Node1 = Form1->TreeView1->Items->AddChild(Node1, dt->SetPsevd());

		}
		else
			Node1 = Form1->TreeView1->Items->Add(NULL, dt->SetPsevd());
		Form1->TreeView1->Selected = Node1;
	}
	else {
		Form1->TreeView1->Selected->Text = dt->SetPsevd();
		Form2->CheckBox1->Tag = 0;
	}

	dt->NameTab =((TTabs*)Form1->TabControl1->Tabs->Objects[Form1->TabControl1->TabIndex])->ID;
	//int indextab=Form1->TabControl1->TabIndex;
	//dt->SharePath=(TStringList*)ListBox1->Items;
	dt->SharePath->Clear();
	for(int i=0;i<ListBox1->Items->Count;i++)
	{
		QuikList *ql=(QuikList*)ListBox1->Items->Objects[i];
		dt->SharePath->AddObject(ql->Name,(TObject*)ql);
	}
	if(dt->TipItems==2)
	{
		TEQui *equ;
		if(dt->EquipList->Count>0)
			equ=(TEQui*)dt->EquipList->Objects[0];
		else
			equ=new TEQui;

		equ->Tip="�������";
		equ->Model=Model->Text;
		equ->SN=SN->Text;
		equ->Inv=Inv->Text;
		equ->DataV=DataV->Text;
		equ->Dop=Dop->Text;
		equ->mainid=dt->id;
		if(dt->EquipList->Count==0)
			dt->EquipList->AddObject(L"",(TObject*)equ);
    }
	//dt->OldStatus=0;
	dt->functions=functions;
	dt->SaveINI(Form1->ADOQuery1);
	dt->IPex=dt->GetExIP(Form1->ADOQuery1);
	Node1->Data = (void*)dt;
	*/
}
// ---------------------------------------------------------------------------



void __fastcall TForm3::Label7MouseDown(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y) {
	Screen->Cursor = crHourGlass;

	if(!EditIP->Text.IsEmpty())
		EditName->Text =GetIPName(EditIP->Text);
	Screen->Cursor = crDefault;
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::BitBtn1Click(TObject *Sender)
{
	Button1Click(Form3);
	// Close();
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::SpeedButton1Click(TObject *Sender) {
 /*	Form7->Edit1->Text ="";// "\\\\" + Edit4->Text + "\\";
	Form7->Edit2->Text ="";
	Form7->Edit3->Text ="";
	Form7->Caption = Edit4->Text;
	Form7->FormStyle = FormStyle;
	Form7->Left=Screen->Width/2-Form7->Width/2;
	Form7->Top=Screen->Height/2-Form7->Height;
	Form7->FileIcon->Text="";
	if (Form7->ShowModal() == mrOk)
	{
		QuikList *lstq=new QuikList;
		lstq->Cod=1+random(32000);
		lstq->Name=Form7->Edit3->Text;
		lstq->Path=Form7->Edit1->Text;
		lstq->Param=Form7->Edit2->Text;
		lstq->Icon=Form7->FileIcon->Text;
		lstq->Check=true;

		ListBox1->Items->AddObject(Form7->Edit3->Text,(TObject*)lstq);
		ListBox1->Checked[ListBox1->Items->Count - 1] = true;
		ListBox1->ItemIndex=ListBox1->Items->Count - 1;
	}
	*/
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::Label2MouseDown(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y) {
	if (Label2->Tag == 1) {
		EditFullName->Text = EditIP->Text + "(" + EditName->Text + ")";
		Label2->Tag++;
	}
	else {
		EditFullName->Text = EditName->Text + "(" + EditIP->Text + ")";
		Label2->Tag--;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::BitBtn4Click(TObject *Sender) {

	if (((TBitBtn*)Sender)->Name == "BitBtn4")
	{
		OpenDialog1->FileName = GetLongName(OnLine->Text);
		OpenDialog1->Execute();
		OnLine->Text = GetShortPath(OpenDialog1->FileName);
	}
	else
	{
		OpenDialog1->FileName = GetLongName(OffLine->Text);
		OpenDialog1->Execute();
		OffLine->Text = GetShortPath(OpenDialog1->FileName);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::BitBtn6Click(TObject *Sender) {
	DWORD fdwSound = SND_ASYNC | SND_FILENAME;
	UnicodeString SoundFile = GetLongName(OnLine->Text);
	if (((TBitBtn*)Sender)->Name != "BitBtn6")
		SoundFile = GetLongName(OffLine->Text);
	if (FileExists(SoundFile))
		PlaySound(SoundFile.w_str(), NULL, fdwSound);
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::SpeedButton2Click(TObject *Sender) {
 /*	int index=ListBox1->ItemIndex;
	if (index >= 0) {


		QuikList *lstq=(QuikList*)ListBox1->Items->Objects[index];
		Form7->Edit1->Text = lstq->Path;
		Form7->Edit2->Text= lstq->Param;
		Form7->Edit3->Text= lstq->Name;
		Form7->Caption = Edit4->Text;
		Form7->FormStyle = FormStyle;
		Form7->Left=Screen->Width/2-Form7->Width/2;
		Form7->Top=Screen->Height/2-Form7->Height;
		Form7->FileIcon->Text=lstq->Icon;
		UnicodeString ext=ExtractFileExt(lstq->Icon);
		if(ext.UpperCase()==".EXE" || ext.UpperCase()==".DLL")
			Form7->ChangeIcon(GetLongName(lstq->Icon));
		else
		if(FileExists(GetLongName(lstq->Icon)))
			Form7->Image1->Picture->LoadFromFile(GetLongName(lstq->Icon));
		if (Form7->ShowModal() == mrOk)
		{
			  lstq->Name=Form7->Edit3->Text;
			  lstq->Path=Form7->Edit1->Text;
			  lstq->Param=Form7->Edit2->Text;
			  lstq->Icon=Form7->FileIcon->Text;
			  ListBox1->Items->Strings[index] = lstq->Name;

		}
	}
	*/
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::SpeedButton3Click(TObject *Sender) {
	if (ListBox1->ItemIndex >= 0) {
		ListBox1->DeleteSelected();

	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::CheckBox2Click(TObject *Sender) {
	if (CheckBox2->Checked)
		CheckBox1->Checked = true;
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::FormShow(TObject *Sender)
{
	PageControl1->ActivePage = TabSheet1;
	Form3->ActiveControl=EditIP;
	ListBox1->ItemIndex=0;
	ShowTabs();
	ShowWid();
	FillFunc();
	//LoadPrinter();
}
void __fastcall TForm3::FillFunc()
{
			FuncCheckBox->Clear();
		
			for(int i=0;i<Form1->funclist.size();i++)
			{
				   func *fn=new func;
				   UnicodeString cod=Form1->funclist[i]->shname;
				   UnicodeString capt=Form1->funclist[i]->name;
				   fn->shname=cod;
				   fn->name=capt;
				   FuncCheckBox->AddItem(capt,(TObject*)fn);
				   if(functions.Pos(cod+";")>0)
                      FuncCheckBox->Checked[FuncCheckBox->Count-1]=true;

			}

}
// ---------------------------------------------------------------------------
void __fastcall TForm3::ListBox1ClickCheck(TObject *Sender)
{
   //	((QuikList*)ListBox1->Items->Objects[ListBox1->ItemIndex])->Check=ListBox1->Checked[ListBox1->ItemIndex];
}
//---------------------------------------------------------------------------

void __fastcall TForm3::WidEditRightButtonClick(TObject *Sender)
{
   /*	TTreeNode *Node1;
	Node1 = Form1->TreeView1->Selected;
	Form1->SaveExpend();
	if(Node1!=NULL)
	{
		FormW->Pid=((TDataTV *)Node1->Data)->id;
		FormW->id=Wid;
	}
	else
	{
		FormW->Pid="";
		FormW->id=Wid;
	}
	FormW->FormStyle = FormStyle;

	if(FormW->ShowModal()==mrOk)
	{


		Wid=FormW->id;
		ShowWid();
	}     */
}
//---------------------------------------------------------------------------
void TForm3::ShowWid()
{

	 /*	if(Wid.IsEmpty())
		{
			WidEdit->Text="";//dt->Psevd.IsEmpty()?(dt->Name+"("+dt->IP+")"):dt->Psevd;
			Label5->Caption="IP: ";//+dt->IP;
			Label6->Caption="���: ";//+dt->Name;
			Label11->Caption="����: ";//+IntToStr(dt->Port);
			Label12->Caption="�����: ";//+dt->Login;
		}
		else
		{
			TDataTV *dt=new TDataTV();
			dt->id=Wid;
			dt->LoadINI(Form1->ADOQuery1);
			WidEdit->Text=dt->Psevd.IsEmpty()?(dt->Name+"("+dt->IP+")"):dt->Psevd;
			Label5->Caption="IP: "+dt->IP;
			Label6->Caption="���: "+dt->Name;
			Label11->Caption="����: "+IntToStr(dt->Port);
			Label12->Caption="�����: "+dt->Login;
			delete dt;
		}      */
}



void __fastcall TForm3::WidEditLeftButtonClick(TObject *Sender)
{

	Wid="";
	ShowWid();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit3Exit(TObject *Sender)
{
	try
	{
		int mumtr=StrToInt(Edit3->Text);
		if(mumtr<0 || mumtr>65536)
		{
			ShowMessage("�� ������ ����.");
			Form3->ActiveControl=Edit3;
		}

	}
	catch (Exception &exception) {
		ShowMessage("�� ������ ����.");
		Form3->ActiveControl=Edit3;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key==13)
	{
		TWinControl* tabU = ActiveControl;
		if(ActiveControl->Name!="Memo1")
		FindNextControl(tabU,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm3::HTTP1Click(TObject *Sender)
{
	 /*	QuikList *lstq=new QuikList;
		lstq->Cod=1+random(32000);
		lstq->Name="HTTP";
		lstq->Path="http://$IP";
		lstq->Param="";
		lstq->Icon="resurs\\http1.bmp";
		lstq->Check=true;

		ListBox1->Items->AddObject("HTTP",(TObject*)lstq);
		ListBox1->Checked[ListBox1->Items->Count - 1] = true;
		ListBox1->ItemIndex=ListBox1->Items->Count - 1;
			 */
}
//---------------------------------------------------------------------------

void __fastcall TForm3::HTTPS1Click(TObject *Sender)
{
   /*		QuikList *lstq=new QuikList;
		lstq->Cod=1+random(32000);
		lstq->Name="HTTPS";
		lstq->Path="https://$IP";
		lstq->Param="";
		lstq->Icon="resurs\\https.bmp";
		lstq->Check=true;

		ListBox1->Items->AddObject("HTTPS",(TObject*)lstq);
		ListBox1->Checked[ListBox1->Items->Count - 1] = true;
		ListBox1->ItemIndex=ListBox1->Items->Count - 1;
   */
}
//---------------------------------------------------------------------------

void __fastcall TForm3::telnet1Click(TObject *Sender)
{
   /*		QuikList *lstq=new QuikList;
		lstq->Cod=1+random(32000);
		lstq->Name="FTP";
		lstq->Path="FTP://$IP";
		lstq->Param="";
		lstq->Icon="resurs\\ftp.bmp";
		lstq->Check=true;

		ListBox1->Items->AddObject("FTP",(TObject*)lstq);
		ListBox1->Checked[ListBox1->Items->Count - 1] = true;
		ListBox1->ItemIndex=ListBox1->Items->Count - 1;      */
}
//---------------------------------------------------------------------------


void __fastcall TForm3::SpeedButton4Click(TObject *Sender)
{
	TPoint cPt;
	GetCursorPos(&cPt);

	PopupMenu2->Popup(cPt.x,cPt.y);
}
//---------------------------------------------------------------------------




void __fastcall TForm3::FuncCheckBoxClickCheck(TObject *Sender)
{
	UnicodeString tfunc="";
	for(int i=0;i<FuncCheckBox->Count;i++)
	{
		if(!FuncCheckBox->Checked[i]) continue;
		UnicodeString fn;
		fn=((func*)FuncCheckBox->Items->Objects[i])->shname;
		tfunc+=fn+";";

	}
	functions=tfunc;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ShowTabs()
{
  TabSheet1->TabVisible=true;
  TabSheet2->TabVisible=true;
  TabSheet3->TabVisible=true;
  TabSheet4->TabVisible=true;
  TabSheet5->TabVisible=true;
  TabSheet6->TabVisible=true;


  /*if(ComboBoxEx1->ItemIndex>1)
  {
	  TabSheet3->TabVisible=false;
	  TabSheet5->TabVisible=false;
  }
  if(ComboBoxEx1->ItemIndex==2)
  {
	CheckBox2->Caption="��������� ��������";

  }
  else
  {
	CheckBox2->Caption="��������� �������� �� ������� � ����";
	TabSheet6->TabVisible=false;
  }   */
}
void __fastcall TForm3::ComboBoxEx1Change(TObject *Sender)
{
	ShowTabs();
}
//---------------------------------------------------------------------------


void __fastcall TForm3::SpeedButton6Click(TObject *Sender)
{
  /*	Form9->Left=Screen->Width/2-Form9->Width/2;
	Form9->Top=Screen->Height/2-Form9->Height;
	if(Form9->ShowModal()==mrOk)
	{
		//LoadPrinter();
		Model->Text=Form9->Model;
		Dop->Lines->Text=Form9->Rash;
	}
	*/
}
//---------------------------------------------------------------------------

