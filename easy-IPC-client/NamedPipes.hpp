#include "stdafx.h"

void Onrecieve( const HANDLE& hPipe, CString& strReceive )
{
    char buf[100];
    DWORD dwRead;
    if( !ReadFile( hPipe, buf, 100, &dwRead, NULL ) )
    {
        return;
    }
    strReceive = buf;
}

void OnPipeConnect()
{
    if ( !WaitNamedPipe( L"\\\\.\\pipe\\MyPipe", NMPWAIT_WAIT_FOREVER ) )
    {
        return;
    }

    HANDLE hPipe = CreateFile( L"\\\\.\\pipe\\MyPipe", GENERIC_READ | GENERIC_WRITE,
        0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if( INVALID_HANDLE_VALUE == hPipe )
    {
        hPipe = NULL;
        return;
    }

    CString strReceive;
    Onrecieve( hPipe, strReceive );
    ::MessageBox( NULL, strReceive, L"", 0 );
}