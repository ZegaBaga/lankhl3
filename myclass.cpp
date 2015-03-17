//---------------------------------------------------------------------------

#pragma hdrstop

#include "myclass.h"
telements::telements()
{
	randomize();
	id ="EL"+IntToStr(100000 + random(899999));
}
void __fastcall telements::Save(TADOQuery *ado)
{
	ado->Close();
	UnicodeString query="select id from elements where id='"+id+"'";
	ado->SQL->Clear();
	ado->SQL->Add(query);
	ado->Open();
	int count=ado->RecordCount;
	ado->Close();
	if(count)
	{
		query="update elements set parentid='"+parentid+"'";
		query+=",chaildid='"+chaildid+"'";
		query+=",groupid='"+groupid+"'";
		query+=",tip="+IntToStr(tip)+"";
		query+=" where id='"+id+"'";
	}
	else
	{
	 query="insert into elements (id,parentid,chaildid,groupid,tip)";
	 query+=" values('"+id+"','"+parentid+"','"+chaildid+"','"+groupid+"',"+IntToStr(tip)+")";
	 //",'"+iconpath+"',"+IntToStr(tipgroop);
	 //query+=",'"+fio+"','"+phone+"','"+email+"','"+adress+"','"+ip+"','"+fullname+"')" ;
	}
	ado->SQL->Clear();
	ado->SQL->Add(query);
	ado->ExecSQL();

}
void __fastcall telements::Delete(TADOQuery *ado)
{
	ado->Close();
	UnicodeString query="delete from elements where id='"+id+"'";
	ado->SQL->Clear();
	ado->SQL->Add(query);
	ado->ExecSQL();
}

void __fastcall tsys::loadsys(TADOQuery *ado)
{
	width=760;height=560;
	int lf=Screen->Width/2-width/2;
	int hg=Screen->Height/3-height/2;
	left=lf>0?lf:0;top=hg>0?hg:0;
	ado->Close();
	UnicodeString query="select * from sys";
	ado->SQL->Clear();
	ado->SQL->Add(query);
	ado->Open();
	ado->First();
	while(!ado->Eof)
	{
		if(ado->FieldByName("key")->AsAnsiString=="left") left=ado->FieldByName("valuee")->AsInteger;
		if(ado->FieldByName("key")->AsAnsiString=="top") top=ado->FieldByName("valuee")->AsInteger;
		if(ado->FieldByName("key")->AsAnsiString=="width") width=ado->FieldByName("valuee")->AsInteger;
		if(ado->FieldByName("key")->AsAnsiString=="height") height=ado->FieldByName("valuee")->AsInteger;
		ado->Next();
	}
}
bool __fastcall tsys::keyexists(TADOQuery *ado,UnicodeString keyy)
{
	ado->Close();
	UnicodeString query="select key from sys where key='"+keyy+"'";
	ado->SQL->Clear();
	ado->SQL->Add(query);
	ado->Open();
	int count=ado->RecordCount;

	return count;

}
void __fastcall tsys::setkey(TADOQuery *ado,UnicodeString keyy,UnicodeString val)
{
	UnicodeString query="update sys set valuee='"+val+"' where key='"+keyy+"'";
	if(!keyexists(ado,keyy))
		query="insert into sys ([key],valuee) values('"+keyy+"','"+val+"')";

	ado->Close();
	ado->SQL->Clear();
	ado->SQL->Add(query);
	ado->ExecSQL();
}
void __fastcall tsys::savesys(TADOQuery *ado)
{
   setkey(ado,"left",left);
   setkey(ado,"top",top);
   setkey(ado,"width",width);
   setkey(ado,"height",height);

}
tgroops::tgroops()
{
	randomize();
	id ="DT"+IntToStr(100000 + random(899999));
}
void tgroops::Save(TADOQuery *ado)
{
	ado->Close();
	UnicodeString query="select id from groops where id='"+id+"'";
	ado->SQL->Clear();
	ado->SQL->Add(query);
	ado->Open();
	int count=ado->RecordCount;
	ado->Close();
	if(count)
	{
		query="update groops set gname='"+gname+"'";
		query+=",parentid='"+parentid+"'";
		query+=",fullpath='"+fullpath+"'";
		query+=",comm='"+comm+"'";
		query+=",iconpath='"+iconpath+"'";
		query+=",fio='"+fio+"'";
		query+=",phone='"+phone+"'";
		query+=",email='"+email+"'";
		query+=",adress='"+adress+"'";
		query+=",fullname='"+fullname+"'";
		query+=",ip='"+ip+"'";
		query+=" where id='"+id+"'";
	}
	else
	{
	 query="insert into groops (gname,id,parentid,fullpath,comm,iconpath,tipgroop,fio,phone,email,ip,adress,fullname)";
	 query+=" values('"+gname+"','"+id+"','"+parentid+"','"+fullpath+"','"+comm+"','"+iconpath+"',"+IntToStr(tipgroop);
	 query+=",'"+fio+"','"+phone+"','"+email+"','"+adress+"','"+ip+"','"+fullname+"')" ;
	}
	ado->SQL->Clear();
	ado->SQL->Add(query);
	ado->ExecSQL();

}
void tgroops::Delete(TADOQuery *ado)
{
	ado->Close();
	UnicodeString query="delete from groops where id='"+id+"'";
	ado->SQL->Clear();
	ado->SQL->Add(query);
	ado->ExecSQL();
}
UnicodeString GetShortPath(UnicodeString way)
{
	UnicodeString apppath=ExtractFilePath(Application->ExeName);
	int pos=way.Pos(apppath);
	UnicodeString shortway=way;
	if(pos==1)
			shortway=way.SubString(apppath.Length()+1,way.Length());

	return shortway;
}
UnicodeString GetLongName(UnicodeString way)
{
	UnicodeString apppath=ExtractFilePath(Application->ExeName);
	UnicodeString longway=way;
	if(FileExists(way) || way.IsEmpty()) return longway;
	longway=apppath+way;
	return longway;


}

//---------------------------------------------------------------------------
#pragma package(smart_init)
