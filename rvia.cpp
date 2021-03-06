//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "rvia.h"
#include "myclass.h"
#include "mainform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TrViaForm *rViaForm;
//---------------------------------------------------------------------------
__fastcall TrViaForm::TrViaForm(TComponent* Owner)
	: TForm(Owner)
{
}
void __fastcall TrViaForm::LoadGroops()
{
   //TTreeNode *Node1,*ParentNode=NULL;
   TreeView1->Items->Clear();
   ADOQuery1->Close();
   ADOQuery1->SQL->Clear();
   ADOQuery1->SQL->Add("select * from groops order by cod");
   ADOQuery1->Open();
   ADOQuery1->First();
   int sk=0;
   int kk=0;
   while(!ADOQuery1->Eof)
   {
		   tgroops *gr=new tgroops();
		   gr->id=ADOQuery1->FieldByName("id")->AsAnsiString;
		   if(gr->id==groopid) sk=kk;

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
			   int k=Form1->SerechNode(gr->parentid);
			   if(k>=0)
				   TreeView1->Items->AddChildObject(TreeView1->Items->Item[k],gr->gname,(void*)gr);
				else
					ShowMessage("����� �������");
		   }
		   else
			   TreeView1->Items->AddObject(NULL,gr->gname,(void*)gr);
		   kk++;
		   ADOQuery1->Next();
   }
   ADOQuery1->Close();
   if(TreeView1->Items->Count>0) TreeView1->Selected=TreeView1->Items->Item[sk];
   TreeView1Click(rViaForm);
   SetIcons();
}
void __fastcall TrViaForm::SetIcons()
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

//---------------------------------------------------------------------------
void __fastcall TrViaForm::FormShow(TObject *Sender)
{
	//UnicodeString pathbase=ExtractFilePath(Application->ExeName)+"base.mdb";
	//ADOConnection1->ConnectionString="Provider=Microsoft.ACE.OLEDB.12.0;Data Source="+pathbase+";Persist Security Info=False";
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

	Caption="";//abov->nameapp+" "+abov->version;

}
//---------------------------------------------------------------------------
void __fastcall TrViaForm::TreeView1Click(TObject *Sender)
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
   ADOQuery1->SQL->Add("select elements.* from elements where elements.groupid='"+parentid+"' and elements.id<>'"+elementid+"' order by elements.cod");
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
			   int k=Form1->SerechNodeObject(elm->parentid);
			   if(k>=0)
				   TreeView2->Items->AddChildObject(TreeView2->Items->Item[k],elm->name,(void*)elm);
				else
					TreeView2->Items->AddObject(NULL,elm->name,(void*)elm);

		   }
		   else
			   TreeView2->Items->AddObject(NULL,elm->name,(void*)elm);
		   ADOQuery1->Next();
   }
   ADOQuery1->Close();
   if(TreeView2->Items->Count>0)
   {
	 TreeView2->Selected=TreeView2->Items->Item[0];
	 wid=((telements*)TreeView2->Selected->Data)->chaildid;
	 //TreeView2Click(Form1);
   }
   //TreeView1Click(Form1);
   SetIconsOjects();
}
void __fastcall TrViaForm::SetIconsOjects()
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
//---------------------------------------------------------------------------
void __fastcall TrViaForm::TreeView2Click(TObject *Sender)
{
	wid=((telements*)TreeView2->Selected->Data)->chaildid;
}
//---------------------------------------------------------------------------
