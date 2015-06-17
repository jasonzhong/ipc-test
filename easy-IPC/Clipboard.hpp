#include "stdafx.h"

class EasyIPCClipboardService
{
public:
    EasyIPCClipboardService();

    BOOL EasyClipboardStart();

protected:
    BOOL _ClipboardSend( HANDLE& hClipboard, CHAR* lpBuffer );

private:
    HANDLE m_hClipboard;
};

EasyIPCClipboardService::EasyIPCClipboardService()
{
    m_hClipboard = NULL;
}

BOOL EasyIPCClipboardService::EasyClipboardStart()
{
    BOOL bRetOpenClip = FALSE;
    bRetOpenClip = OpenClipboard( NULL );
    if ( !bRetOpenClip )
    {
        return FALSE;
    }

    CHAR* pBuffer = NULL;
    EmptyClipboard();
    _ClipboardSend( m_hClipboard, pBuffer );

    Sleep( 10 * 1000 * 1000 * 60 );

    CloseClipboard();
    return TRUE;
}

BOOL EasyIPCClipboardService::_ClipboardSend( HANDLE& hClipboard, CHAR* lpBuffer )
{
    hClipboard = GlobalAlloc( GMEM_MOVEABLE, 100 );
    lpBuffer = ( CHAR* )GlobalLock( hClipboard );

    strcpy_s( lpBuffer, 100, "Hello this is my first clipboard ipc" );
    GlobalUnlock( hClipboard );
    SetClipboardData( CF_TEXT, hClipboard );

    return TRUE;
}
