#include "stdafx.h"

class EasyIPCMessageService
{
public:
    EasyIPCMessageService();

    BOOL EasyMessageStart();

protected:
    BOOL _MessageSend( HWND& hSendWindow, HWND& hRecvWindow, WCHAR* lpBuffer );

};

EasyIPCMessageService::EasyIPCMessageService()
{

}

BOOL EasyIPCMessageService::EasyMessageStart()
{
    const WCHAR szDlgTitle[] = L"easy-IPC-Win32-Client";

    HWND hSendWindow = GetConsoleWindow();
    if ( !hSendWindow )
    {
        return FALSE;
    }

    HWND hRecvWindow = FindWindow( NULL, szDlgTitle );
    if ( !hRecvWindow )
    {
        return FALSE;
    }

    WCHAR szSendBuf[100] = L"hello, my first message ipc";
    _MessageSend( hSendWindow, hRecvWindow, szSendBuf );

    return TRUE;
}

BOOL EasyIPCMessageService::_MessageSend( HWND& hSendWindow, HWND& hRecvWindow, WCHAR* lpBuffer )
{
    COPYDATASTRUCT CopyData = {0};

    CopyData.dwData = 0;
    CopyData.cbData = 100;
    CopyData.lpData = lpBuffer;

    SendMessage( hRecvWindow, WM_COPYDATA, (WPARAM)hSendWindow, (LPARAM)&CopyData );
    return TRUE;
}
