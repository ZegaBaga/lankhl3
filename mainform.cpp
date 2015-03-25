//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#pragma hdrstop

#include "mainform.h"
#include "groops.h"
#include "myclass.h"
#include "abov.h"
#include "object.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
const int CountImage = 5;
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int __fastcall TForm1::SerechNode(UnicodeString Pernt)
{
	int ret = -1;
	for (int i = 0; i < TreeView1->Items->Count; i++) {
		if (Pernt == ((tgroops*)TreeView1->Items->Item[i]->Data)->id) {
			ret = i;
			break;
		}
	}
	return ret;
}

int __fastcall TForm1::SerechNodeObject(UnicodeString Pernt)
{
	int ret = -1;
	for (int i = 0; i < TreeView2->Items->Count; i++) {
		if (Pernt == ((telements*)TreeView2->Items->Item[i]->Data)->id) {
			ret = i;
			break;
		}
	}
	return ret;
}

void __fastcall TForm1::LoadGroops()
{
   //TTreeNode *Node1,*ParentNode=NULL;
   TreeView1->Items->Clear();
   ADOQuery1->Close();
   ADOQuery1->SQL->Clear();
   ADOQuery1->SQL->Add("select * from groops order by cod");
   ADOQuery1->Open();
   ADOQuery1->First();
   while(!ADOQuery1->Eof)
   {
		   tgroops *gr=new tgroops();
		   gr->id=ADOQuery1->FieldByName("id")->AsAnsiString;
		   gr->tipgroop=ADOQuery1->FieldByName("tipgroop")->AsInteger;
		   gr->gname=ADOQuery1->FieldByName("gname")->AsAnsiString;
		   gr->parentid=ADOQuery1->FieldByName("parentid")->AsAnsiString;
		   gr->fullpath=ADOQuery1->FieldByName("fullpath")->AsAnsiString;
		   gr->comm=ADOQuery1->FieldByName("comm")->AsAnsiString;
		   gr->iconpath=ADOQuery1->FieldByName("iconpath")->AsAnsiString;
		   gr->fio=ADOQuery1->FieldByName("fio")->AsAnsiString;
		   gr->phone=ADOQuery1->FieldByName("phone")->AsAnsiString;
		   gr->email=ADOQuery1->FieldByName("email")->AsAnsiString;
		   gr->ip=ADOQuery1->FieldByName("ip")->AsAnsiString;
		   gr->fullname=ADOQuery1->FieldByName("fullname")->AsAnsiString;
		   gr->adress=ADOQuery1->FieldByName("adress")->AsAnsiString;
		   if(!gr->parentid.IsEmpty())
		   {
			   int k=SerechNode(gr->parentid);
			   if(k>=0)
				   TreeView1->Items->AddChildObject(TreeView1->Items->Item[k],gr->gname,(void*)gr);
				else
					ShowMessage("����� �������");
		   }
		   else
			   TreeView1->Items->AddObject(NULL,gr->gname,(void*)gr);
		   ADOQuery1->Next();
   }
   ADOQuery1->Close();
   if(TreeView1->Items->Count>0) TreeView1->Selected=TreeView1->Items->Item[0];
   TreeView1Click(Form1);
   SetIcons();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	UnicodeString pathbase=ExtractFilePath(Application->ExeName)+"base.mdb";
	ADOConnection1->ConnectionString="Provider=Microsoft.ACE.OLEDB.12.0;Data Source="+pathbase+";Persist Security Info=False";
	LoadGroops();
	TTreeNode *Node1 = TreeView1->Items->GetFirstNode();
	while (Node1)
	{
		Node1->StateIndex=-1;
		Node1->SelectedIndex=Node1->ImageIndex;
		Node1->Expanded=true;
		Node1 = Node1->GetNext();
	}
	Node1 = TreeView2->Items->GetFirstNode();
	//int alli=0;
	//int alll=0;
	while (Node1)
	{
		Node1->StateIndex=-1;
		Node1->SelectedIndex=Node1->ImageIndex;
		Node1->Expanded=true;
		Node1 = Node1->GetNext();
	}
	tabov *abov=new tabov();
	Caption=abov->nameapp+" "+abov->version;

	tsys *sys=new tsys;
	sys->loadsys(ADOQuery1);
	Form1->Left=sys->left;
	Top=sys->top;
	Width=sys->width;
	Height=sys->height;
	delete sys;
	delete abov;

	TADOQuery *ado=Form1->ADOQuery1;
	ado->SQL->Clear();
	UnicodeString query0="select * from func";
	ado->SQL->Add(query0);
	ado->Open();
	ado->First();
	while(!ado->Eof)
	{
				   func *fn=new func;
				   UnicodeString cod=ado->FieldByName("shname")->AsAnsiString;
				   UnicodeString capt=ado->FieldByName("fname")->AsAnsiString;

				   fn->shname=cod;
				   fn->name=capt;
				   funclist.push_back(fn);
				   ado->Next();
	}
    ado->Close();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::SQLChange(UnicodeString query0)
{
		   ADOQuery1->SQL->Clear();
		   ADOQuery1->SQL->Add(query0);
		   ADOQuery1->ExecSQL();
		   ADOQuery1->Close();
}
void __fastcall TForm1::SetIcons()
{
		   int C = ImageList1->Count;
		   for (int i = C - 1; i >= CountImage; i--) ImageList1->Delete(i);

		   TTreeNode *Node1 = TreeView1->Items->GetFirstNode();

		   while (Node1)
		   {
				tgroops *gr=(tgroops*)Node1->Data;
				UnicodeString iconpath=GetLongName(gr->iconpath);
				int tipgroop=gr->tipgroop;
				int ind=tipgroop;
				if(FileExists(iconpath))
				{
						UnicodeString Ext = ExtractFileExt(iconpath).UpperCase();
						if (Ext == ".BMP")
						{
							Graphics::TBitmap *bm1 = new Graphics::TBitmap;
							bm1->LoadFromFile(iconpath);
							ind = ImageList1->AddMasked(bm1, clFuchsia); // >Add(bm1,bm1);
							ind = ImageList1->Count - 1;
							delete bm1;
						}
						else if (Ext == ".ICO")
						{
							Graphics::TIcon *ic1 = new Graphics::TIcon;
							ic1->LoadFromFile(iconpath);
							ind = ImageList1->AddIcon(ic1);
							ind = ImageList1->Count - 1;
							delete ic1;
						}
				}
                gr->imgindex=ind;
				Node1->ImageIndex=ind;
				Node1->SelectedIndex=ind;
				Node1 = Node1->GetNext();
		   }
}
void __fastcall TForm1::RindexGroop()
{
		   TTreeNode *Node1 = TreeView1->Items->GetFirstNode();
		   int cod=1;
		   while (Node1)
		   {
				tgroops *gr=(tgroops*)Node1->Data;
				UnicodeString query0="update groops set cod="+IntToStr(cod)+" where id='"+gr->id+"'";
				SQLChange(query0);
				cod++;
				Node1 = Node1->GetNext();
		   }
}

void __fastcall TForm1::RindexObjects()
{
		   TTreeNode *Node1 = TreeView2->Items->GetFirstNode();
		   int cod=1;
		   while (Node1)
		   {
				telements *elm=(telements*)Node1->Data;
				UnicodeString query0="update elements set cod="+IntToStr(cod)+" where id='"+elm->id+"'";
				SQLChange(query0);
				cod++;
				Node1 = Node1->GetNext();
		   }
}

void __fastcall TForm1::VisiblControlGroop(int tipgroop)
{
	Form2->Panel1->Visible=false;
	Form2->Panel2->Visible=false;
	Form2->Label1->Caption="�������� ������:";
	Form2->Width=224;
	Form2->GroupBox1->Enabled=true;
	if(tipgroop==1)
	{

	   Form2->Panel1->Visible=true;
	   Form2->Panel2->Visible=true;
	   Form2->Label1->Caption="������� �������� ���:";
	   Form2->GroupBox1->Enabled=false;
		Form2->Width=454;
	}
	else
	if(tipgroop==2)
	 {
	   Form2->Panel1->Visible=true;
	   Form2->Label1->Caption="������� �������� ������:";
	   Form2->GroupBox1->Enabled=false;
	   Form2->Width=454;
	 }

}
void __fastcall TForm1::N1Click(TObject *Sender)
{
	int tipgroop=((TMenuItem*)Sender)->Tag;
	if(tipgroop==0)
		Form2->Caption="����� ������";
	if(tipgroop==1)
		Form2->Caption="����� ���";
	if(tipgroop==2)
		Form2->Caption="����� �����";

	VisiblControlGroop(tipgroop);
	Form2->Edit1->Text="";
	Form2->Edit2->Text="";
	Form2->Memo1->Text="";
	Form2->EAdress->Text="";
	Form2->EBoss->Text="";
	Form2->EEmail->Text="";
	Form2->EIP->Text="";
	Form2->EName->Text="";
	Form2->EPhone->Text="";


	Form2->Left=Left;
	Form2->Top=Top;
	Form2->Image1->Picture->Bitmap=NULL;
	ImageList1->GetBitmap(tipgroop,Form2->Image1->Picture->Bitmap);

	bool newnew=TreeView1->Selected!=NULL?false:true;
	if(Form2->ShowModal()==mrOk)
	{
			//UnicodeString sql="insert groops (,)";
			//ADOQuery1->Close();
			//ADOQuery1->SQL->Add(sql);
		   tgroops *gr=new tgroops();
		   gr->tipgroop=tipgroop;
		   gr->gname=Form2->Edit1->Text;
		   gr->iconpath=Form2->Edit2->Text;
		   gr->comm=Form2->Memo1->Text;

		   gr->adress=Form2->EAdress->Text;
		   gr->fio=Form2->EBoss->Text;
		   gr->email=Form2->EEmail->Text;
		   gr->ip=Form2->EIP->Text;
		   gr->fullname=Form2->EName->Text;
		   gr->phone=Form2->EPhone->Text;

		   TTreeNode *Node1;
		   if(!newnew)
		   {
				Node1 = TreeView1->Items->AddChild(TreeView1->Selected, Form2->Edit1->Text);
				gr->parentid=((tgroops*)TreeView1->Selected->Data)->id;
		   }
		   else
		   {
				Node1 = TreeView1->Items->Add(NULL, Form2->Edit1->Text);
				gr->parentid="";
		   }
		   gr->Save(ADOQuery1);
		   Node1->Data=(void*)gr;
		   Node1->Selected=true;
		   RindexGroop();
		   SetIcons();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TreeView1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{

	TreeView1->Selected = TreeView1->GetNodeAt(X, Y);
	if (Button == mbRight)
	{

		PMGroops->Popup(TreeView1->Left + Left + X,TreeView1->Top + Top + Y);

	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::TreeView1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	//TTreeNode *Node = TreeView1->GetNodeAt(X, Y);
}
//---------------------------------------------------------------------------
int __fastcall TForm1::OutputDiscription(int start,UnicodeString title,UnicodeString text,TColor color)
{

		//UnicodeString alltext=RichEdit1->Lines->Text;
		int ltext=text.Length();
		int ltitl=title.Length();
		RichEdit1->SelStart=start;
		RichEdit1->SelLength=ltitl;
		RichEdit1->SelAttributes->Style=TFontStyles() << fsBold << fsUnderline;
		RichEdit1->SelAttributes->Color=color;
		return start+ltitl+ltext;
}
int __fastcall TForm1::OutputDiscription2(int start,UnicodeString title,UnicodeString text,TColor color)
{

		//UnicodeString alltext=RichEdit1->Lines->Text;
		int ltext=text.Length();
		int ltitl=title.Length();
		RichEdit2->SelStart=start;
		RichEdit2->SelLength=ltitl;
		RichEdit2->SelAttributes->Style=TFontStyles() << fsBold << fsUnderline;
		RichEdit2->SelAttributes->Color=color;
		return start+ltitl+ltext;
}

void __fastcall TForm1::TreeView1Click(TObject *Sender)
{
	RichEdit1->Lines->Clear();
	tgroops *gt;
	if(!TreeView1->Selected)
	{
	  gt=new tgroops();
	  gt->fullname="��� �����";
	}
	else
	  gt=((tgroops*)TreeView1->Selected->Data);
	int tipgroop=gt->tipgroop;
	if(tipgroop==0)
	{
		RichEdit1->Lines->Add("��������: "+gt->comm) ;
		RichEdit1->SelStart=0;
		RichEdit1->SelLength=9;
		RichEdit1->SelAttributes->Style=TFontStyles() << fsBold << fsUnderline;
		RichEdit1->SelAttributes->Color=clGreen;

	}
	if(tipgroop==1)
	{
	   RichEdit1->Lines->Add("�������� ���: "+gt->fullname);
	   RichEdit1->Lines->Add("���������: "+gt->fio);
	   RichEdit1->Lines->Add("�����: "+gt->adress);
	   RichEdit1->Lines->Add("�������: "+gt->phone);
	   RichEdit1->Lines->Add("Email: "+gt->email);
	   RichEdit1->Lines->Add("IP: "+gt->ip);
	   RichEdit1->Lines->Add("��������: "+gt->comm);
	   int start=OutputDiscription(0,"�������� ���: ",gt->fullname,clMaroon);
	   start=OutputDiscription(start+1,"���������: ",gt->fio,clMaroon);
	   start=OutputDiscription(start+1,"�����: ",gt->adress,clMaroon);
	   start=OutputDiscription(start+1,"�������: ",gt->phone,clMaroon);
	   start=OutputDiscription(start+1,"Email: ",gt->email,clMaroon);
	   start=OutputDiscription(start+1,"IP: ",gt->ip,clMaroon);
	   start=OutputDiscription(start+1,"��������: ",gt->comm,clMaroon);
	}
	if(tipgroop==2)
	{

	   RichEdit1->Lines->Add("�������� ������: "+gt->fullname);
	   RichEdit1->Lines->Add("���������: "+gt->fio);
	   RichEdit1->Lines->Add("�������: "+gt->phone);
	   RichEdit1->Lines->Add("Email: "+gt->email);
	   RichEdit1->Lines->Add("��������: "+gt->comm);

	   int start=OutputDiscription(0,"�������� ������: ",gt->fullname,clMaroon);
	   start=OutputDiscription(start+1,"���������: ",gt->fio,clMaroon);
	   start=OutputDiscription(start+1,"�������: ",gt->phone,clMaroon);
	   start=OutputDiscription(start+1,"Email: ",gt->email,clMaroon);
	   start=OutputDiscription(start+1,"��������: ",gt->comm,clMaroon);

	}
	LoadObjects();
}
UnicodeString __fastcall TForm1::GetFunctionLong(UnicodeString str)
{
		UnicodeString strret="";
		for(int i=0;i<Form1->funclist.size();i++)
			{

				   UnicodeString cod=Form1->funclist[i]->shname;
				   UnicodeString capt=Form1->funclist[i]->name;
				   if(str.Pos(cod+";")>0)
						strret+=strret.IsEmpty()?capt:", "+capt;


			}
		   return strret;
}

void __fastcall TForm1::TreeView2Click(TObject *Sender)
{
	RichEdit2->Lines->Clear();
	if(!TreeView2->Selected) return;
		telements *elm=((telements*)TreeView2->Selected->Data);
	int tip=elm->tip;
	UnicodeString idchaild=elm->chaildid;
	if(tip==0)
	{
	   tkomp *kmp=new tkomp();
	   kmp->id=idchaild;
	   kmp->Load(ADOQuery1);
	   UnicodeString naz=GetFunctionLong(kmp->naz);
	   RichEdit2->Lines->Add("���: ���");
	   RichEdit2->Lines->Add("������� ���: "+kmp->nname);
	   RichEdit2->Lines->Add("IP: "+kmp->ip);
	   RichEdit2->Lines->Add("����������: "+naz);
	   TColor orange=RGB(179,89,0);
	   int start=OutputDiscription2(0,"���: ","���",orange);
	   start=OutputDiscription2(start+1,"������� ���: ",kmp->nname,orange);
	   start=OutputDiscription2(start+1,"IP: ",kmp->ip,orange);

	   start=OutputDiscription2(start+1,"����������: ",naz,orange);
	   //start=OutputDiscription(start+1,"Email: ",gt->email,clMaroon);
	   //start=OutputDiscription(start+1,"IP: ",gt->ip,clMaroon);
	   //start=OutputDiscription(start+1,"��������: ",gt->comm,clMaroon);
	   delete kmp;
	}
	if(tip==1)
	{
	   tkomp *kmp=new tkomp();
	   kmp->id=idchaild;
	   kmp->Load(ADOQuery1);
	   UnicodeString naz=GetFunctionLong(kmp->naz);
	   RichEdit2->Lines->Add("���: ������");
	   RichEdit2->Lines->Add("������� ���: "+kmp->nname);
	   RichEdit2->Lines->Add("IP: "+kmp->ip);
	   RichEdit2->Lines->Add("����������: "+naz);
	   //RichEdit1->Lines->Add("��������: "+elm->com);
	   TColor orange=RGB(179,89,0);
	   int start=OutputDiscription2(0,"���: ","������",orange);
	   start=OutputDiscription2(start+1,"������� ���: ",kmp->nname,orange);
	   start=OutputDiscription2(start+1,"IP: ",kmp->ip,orange);
	   start=OutputDiscription2(start+1,"����������: ",naz,orange);
	   //start=OutputDiscription(start+1,"Email: ",gt->email,clMaroon);
	   //start=OutputDiscription(start+1,"IP: ",gt->ip,clMaroon);
	   //start=OutputDiscription(start+1,"��������: ",gt->comm,clMaroon);
	   delete kmp;
	}
	if(tip==2)
	{

		//
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{

	TTreeNode *Node1=TreeView1->Selected;
	if(Node1==NULL) return;
	tgroops *gr=(tgroops *)Node1->Data;
	Form2->Caption=gr->gname;
	Form2->Edit1->Text=gr->gname;
	Form2->Edit2->Text=gr->iconpath;
	Form2->Memo1->Text=gr->comm;
	Form2->EName->Text=gr->gname;
	Form2->EAdress->Text=gr->adress;
	Form2->EBoss->Text=gr->fio;
	Form2->EEmail->Text=gr->email;
	Form2->EIP->Text=gr->ip;
	Form2->EName->Text=gr->fullname;
	Form2->EPhone->Text=gr->phone;

	int tipgr=gr->tipgroop;
	Form2->Image1->Picture->Bitmap=NULL;
	ImageList1->GetBitmap(gr->imgindex,Form2->Image1->Picture->Bitmap);


	Form2->Left=Left;
	Form2->Top=Top;
	VisiblControlGroop(tipgr);
	if(Form2->ShowModal()==mrOk)
	{
		   gr->gname=Form2->Edit1->Text;
		   gr->iconpath=Form2->Edit2->Text;
		   gr->comm=Form2->Memo1->Text;
		   gr->adress=Form2->EAdress->Text;
		   gr->fio=Form2->EBoss->Text;
		   gr->email=Form2->EEmail->Text;
		   gr->ip=Form2->EIP->Text;
		   gr->fullname=Form2->EName->Text;
		   gr->phone=Form2->EPhone->Text;

		   Node1->Text=gr->gname;
		   gr->Save(ADOQuery1);
		   SetIcons();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender)
{
	TTreeNode *Node1=TreeView1->Selected;
	if(Node1==NULL) return;
	if (Node1->Count > 0)
	{
			ShowMessage("������� ������� ��� ���������� ����������� ��������");
			return;
	}
	tgroops *gr=(tgroops *)Node1->Data;
	UnicodeString Ask = "������� " + gr->gname + "?";
	UnicodeString dell = "��������";
	int Q = Application->MessageBox(Ask.w_str(), dell.w_str(), MB_YESNO);
	if (Q == 6)
	{
			gr->Delete(ADOQuery1);
			delete gr;
			Node1->Data = NULL;
			TreeView1->Items->Delete(Node1);
	}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::TreeView1DragOver(TObject *Sender, TObject *Source, int X,
		  int Y, TDragState State, bool &Accept)
{
	Accept = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TreeView1DragDrop(TObject *Sender, TObject *Source, int X,
		  int Y)
{

	if ( TreeView1->Selected == NULL)
	{

		//return;

	}
	if(Source == (TObject*)TreeView2)
	{
		THitTests HT = TreeView1->GetHitTestInfoAt(X, Y);
		TNodeAttachMode AttachMode;
		TTreeNode *pItem = TreeView1->GetNodeAt(X, Y);
		//groopid=((tgroops*)pItem->Data)->id;
		//if(pItem==TreeView1->Selected) return;
		tgroops* grnew;//=(TDataTV*)pItem->Data;
		telements* grold=(telements*)TreeView2->Selected->Data;

		if (HT.Contains(htOnItem) || HT.Contains(htOnIcon))
		{
			AttachMode = naAddChild;
			grnew=(tgroops*)pItem->Data;
			grold->groupid =grnew->id;
			grold->parentid="";
		}
		else if (HT.Contains(htNowhere))
		{
			AttachMode = naAdd;
			grold->groupid = "";
			grold->parentid="";
		}
		else if (HT.Contains(htOnIndent))
		{
			AttachMode = naInsert;
			grnew=(tgroops*)pItem->Data;
			grold->groupid =grnew->parentid;
		}
		else
			return;

		//TreeView2->Selected->MoveTo(pItem, AttachMode);
		grold->Save(ADOQuery1);
		LoadObjects();
		//RindexObjects();
    }
	else
	{
		THitTests HT = TreeView1->GetHitTestInfoAt(X, Y);
		TNodeAttachMode AttachMode;
		TTreeNode *pItem = TreeView1->GetNodeAt(X, Y);
		if(pItem==TreeView1->Selected) return;
		tgroops* grnew;//=(TDataTV*)pItem->Data;
		tgroops* grold=(tgroops*)TreeView1->Selected->Data;

		if (HT.Contains(htOnItem) || HT.Contains(htOnIcon))
		{
			AttachMode = naAddChild;
			grnew=(tgroops*)pItem->Data;
			grold->parentid =grnew->id;
		}
		else if (HT.Contains(htNowhere))
		{
			AttachMode = naAdd;
			grold->parentid = "";
		}
		else if (HT.Contains(htOnIndent))
		{
			AttachMode = naInsert;
			grnew=(tgroops*)pItem->Data;
			grold->parentid =grnew->parentid;
		}
		else
			return;

		TreeView1->Selected->MoveTo(pItem, AttachMode);
		grold->Save(ADOQuery1);

		RindexGroop();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	tsys *sys=new tsys();
	sys->left=Left;
	sys->top=Top;
	sys->width=Width;
	sys->height=Height;
	sys->savesys(ADOQuery1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
	Panel1->Visible=!Panel1->Visible;
	//Panel2->Visible=!Panel2->Visible;
	Form1->AutoSize=!Panel1->Visible;
	//Form1->Width=Width+265;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SetIconsOjects()
{
	TTreeNode *Node1 = TreeView2->Items->GetFirstNode();
	while (Node1)
	{

		int tip = ((telements*)Node1->Data)->tip;

		Node1->ImageIndex = tip;
		Node1->StateIndex = tip;
		Node1->SelectedIndex = tip;
		Node1 = Node1->GetNext();
	}
}
void __fastcall TForm1::LoadObjects()
{
	TTreeNode *Node1=TreeView1->Selected;
	UnicodeString parentid="";
	if(Node1!=NULL)
		parentid=((tgroops*)Node1->Data)->id;
	else
		parentid="";

   TreeView2->Items->Clear();
   ADOQuery1->Close();
   ADOQuery1->SQL->Clear();
   ADOQuery1->SQL->Add("select elements.* from elements where elements.groupid='"+parentid+"' order by elements.cod");
   ADOQuery1->Open();
   ADOQuery1->First();
   while(!ADOQuery1->Eof)
   {
		   telements *elm=new telements();
		   elm->id=ADOQuery1->FieldByName("id")->AsAnsiString;
		   elm->tip=ADOQuery1->FieldByName("tip")->AsInteger;
		   elm->parentid=ADOQuery1->FieldByName("parentid")->AsAnsiString;
		   elm->chaildid=ADOQuery1->FieldByName("chaildid")->AsAnsiString;
		   elm->groupid=parentid;
		   elm->name=ADOQuery1->FieldByName("fname")->AsAnsiString;
		   if(!elm->parentid.IsEmpty())
		   {
			   int k=SerechNodeObject(elm->parentid);
			   if(k>=0)
				   TreeView2->Items->AddChildObject(TreeView2->Items->Item[k],elm->name,(void*)elm);
				else
					ShowMessage("����� �������");

		   }
		   else
			   TreeView2->Items->AddObject(NULL,elm->name,(void*)elm);
		   ADOQuery1->Next();
   }
   ADOQuery1->Close();
   if(TreeView2->Items->Count>0)
   {
	 TreeView2->Selected=TreeView2->Items->Item[0];
	 TreeView2Click(Form1);
   }
   //TreeView1Click(Form1);
   SetIconsOjects();
}
void __fastcall TForm1::N9Click(TObject *Sender)
{
	UnicodeString groopid="";
	if(TreeView1->Selected)
		groopid=((tgroops*)TreeView1->Selected->Data)->id;
	bool newnew=TreeView2->Selected!=NULL?false:true;
	Form3->EditFullName->Text="";
	Form3->EditIP->Text="";
	Form3->EditName->Text="";

	int tip=0;
	if(((TMenuItem*)Sender)->Name=="N10") tip=1;
	Form3->Caption=tip?"����� ������":"����� ���������";
	MenuIcon->GetIcon(tip,Form3->Icon);
	//Form3->PageControl1->ActivePage=Form3->Komp;
	Form3->Left=Left+TreeView2->Left-10;
	Form3->Top=Top;
	Form3->functions="";
	if(Form3->ShowModal()==mrOk)
	{
		telements *elm=new telements();
		elm->groupid=groopid;
		elm->chaildid="";
		elm->tip=tip;
		elm->name=Form3->EditFullName->Text;
		TTreeNode *Node1;
		if(!newnew)
		{
				Node1 = TreeView2->Items->AddChild(TreeView2->Selected,elm->name);
				elm->parentid=((telements*)TreeView2->Selected->Data)->id;
		}
		else
		{
				Node1 = TreeView2->Items->Add(NULL, elm->name);
				elm->parentid="";
		}

		tkomp *kmp=new tkomp();
		kmp->tip=elm->tip;
		kmp->ip=Form3->EditIP->Text;
		kmp->nname=Form3->EditName->Text;
		kmp->naz="";
		kmp->Save(ADOQuery1);
		elm->chaildid=kmp->id;
		elm->Save(ADOQuery1);
		delete kmp;
		Node1->Data=(void*)elm;
		Node1->Selected=true;
		Node1->ImageIndex=elm->tip;
		RindexObjects();
		//SetIcons();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TreeView2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if (Button == mbRight)
	{
		TreeView2->Selected = TreeView2->GetNodeAt(X, Y);
		PMObjects->Popup(TreeView2->Left + Left + X,TreeView2->Top + Top + Y);

	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TreeView2DragOver(TObject *Sender, TObject *Source, int X,
          int Y, TDragState State, bool &Accept)
{
		Accept = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TreeView2DragDrop(TObject *Sender, TObject *Source, int X,
          int Y)
{
	if (Source != (TObject*)TreeView2 || TreeView2->Selected == NULL)
	{

		return;

	}
	else
	{
		THitTests HT = TreeView2->GetHitTestInfoAt(X, Y);
		TNodeAttachMode AttachMode;
		TTreeNode *pItem = TreeView2->GetNodeAt(X, Y);
		if(pItem==TreeView2->Selected) return;
		telements* grnew;//=(TDataTV*)pItem->Data;
		telements* grold=(telements*)TreeView2->Selected->Data;

		if (HT.Contains(htOnItem) || HT.Contains(htOnIcon))
		{
			AttachMode = naAddChild;
			grnew=(telements*)pItem->Data;
			grold->parentid =grnew->id;
		}
		else if (HT.Contains(htNowhere))
		{
			AttachMode = naAdd;
			grold->parentid = "";
		}
		else if (HT.Contains(htOnIndent))
		{
			AttachMode = naInsert;
			grnew=(telements*)pItem->Data;
			grold->parentid =grnew->parentid;
		}
		else
			return;

		TreeView2->Selected->MoveTo(pItem, AttachMode);
		grold->Save(ADOQuery1);

		RindexObjects();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N8Click(TObject *Sender)
{
	TTreeNode *Node1=TreeView2->Selected;
	if(Node1==NULL) return;
	if (Node1->Count > 0)
	{
			ShowMessage("������� ������� ��� ���������� ����������� ��������");
			return;
	}
	telements *gr=(telements *)Node1->Data;
	UnicodeString Ask = "������� " + gr->name + "?";
	UnicodeString dell = "��������";
	int Q = Application->MessageBox(Ask.w_str(), dell.w_str(), MB_YESNO);
	if (Q == 6)
	{
			Node1->Data = NULL;
			gr->Delete(ADOQuery1);
			if(gr->tip<2)
			{
				tkomp *kmp=new tkomp();
				kmp->id=gr->chaildid;
				kmp->Delete(ADOQuery1);
				delete kmp;
			}
			delete gr;
			TreeView2->Items->Delete(Node1);
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N7Click(TObject *Sender)
{
	if(TreeView2->Selected==NULL) return;


	telements *elm=(telements*)TreeView2->Selected->Data;
	if(elm->tip<2)
	{
		int tip=elm->tip;
		Form3->Caption=tip?"C����� "+elm->name:"��������� "+elm->name;
		MenuIcon->GetIcon(tip+5,Form3->Icon);

		tkomp *kmp=new tkomp();
		kmp->id=elm->chaildid;
		kmp->Load(ADOQuery1);
		Form3->EditFullName->Text=elm->name;
		Form3->EditIP->Text=kmp->ip;
		Form3->EditName->Text=kmp->nname;
		Form3->Left=Left+TreeView2->Left-10;
		Form3->Top=Top;
		Form3->functions=kmp->naz;
		if(Form3->ShowModal()==mrOk)
		{
			elm->name=Form3->EditFullName->Text;
			TreeView2->Selected->Text=elm->name;
			kmp->ip=Form3->EditIP->Text;
			kmp->nname=Form3->EditName->Text;
			elm->Save(ADOQuery1);
			kmp->naz=Form3->functions;
			kmp->Save(ADOQuery1);
			delete kmp;
		}
	}
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------




