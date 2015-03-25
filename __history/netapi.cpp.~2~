//---------------------------------------------------------------------------

#pragma hdrstop

#include "netapi.h"
//---------------------------------------------------------------------------
UnicodeString GetIPName(UnicodeString IP)
{
 WORD wVersionRequested;
 WSADATA wsaData;
 UnicodeString NameComp="";
 AnsiString ip=IP;
 wVersionRequested = MAKEWORD( 2, 2 );

 WSAStartup( wVersionRequested, &wsaData );

 struct hostent *_host;
 ULONG uIPAddr=inet_addr(ip.c_str());
 _host=gethostbyaddr((char*)&uIPAddr,4,AF_INET);
 if (_host!=NULL)
 {

	//printf("%s",_host->h_name);
	NameComp=_host->h_name;

 }
 WSACleanup( );
 return NameComp;

}
#pragma package(smart_init)

