#include "stdafx.h"

class EasyIPCClipboardClient
{
public:
    EasyIPCClipboardClient();

    BOOL EasyClipboardStart();

protected:
    BOOL _ClipboardReceive( CString& strBuffer );
};

EasyIPCClipboardClient::EasyIPCClipboardClient()
{
}

BOOL EasyIPCClipboardClient::EasyClipboardStart()
{
    BOOL bRetOpenClip = FALSE;
    bRetOpenClip = OpenClipboard( NULL );
    if ( !bRetOpenClip )
    {
        return FALSE;
    }

    BOOL bRetIsAvailabe = IsClipboardFormatAvailable( CF_TEXT );
    if ( !bRetIsAvailabe )
    {
        CloseClipboard();
        return FALSE;
    }

    CString strBuffer;
    _ClipboardReceive( strBuffer );

    MessageBox( NULL, strBuffer, L"", 0 );

    CloseClipboard();
    return TRUE;
}

BOOL EasyIPCClipboardClient::_ClipboardReceive( CString& strBuffer )
{
    HANDLE hClip = NULL;
    CHAR* pBuf = NULL;
    hClip = GetClipboardData( CF_TEXT );
    if ( !hClip )
    {
        return FALSE;
    }
    pBuf = ( CHAR* )GlobalLock( hClip );
    GlobalUnlock( hClip );
    strBuffer = pBuf;

    return TRUE;
}
