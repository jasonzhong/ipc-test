// easy-IPC-client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NamedPipes.hpp"
#include "MapFile.hpp"
#include "Clipboard.hpp"
#include <wtypes.h>
#include "MailSlot.hpp"

DWORD g_dwMainThreadId;

BOOL WINAPI ConsoleCtrlhandler( DWORD dwCtrlType )
{
    if ( dwCtrlType == CTRL_CLOSE_EVENT )
    {
        PostThreadMessage( g_dwMainThreadId, WM_QUIT, 0 , 0 );
        return TRUE;
    }
    else if ( dwCtrlType == WM_COPYDATA )
    {
    }
    return FALSE;
}

int _tmain(int argc, _TCHAR* argv[])
{
//    OnPipeConnect();

//     EasyIPCMapFileClient easyIpc;
//     easyIpc.EasyMapFilesStart();

//     EasyIPCClipboardClient easyIpc;
//     easyIpc.EasyClipboardStart();

    EasyIPCMailslotClient easyIpc;
    easyIpc.EasyMailslotStart();


//     HWND hWnd = GetConsoleWindow();
// 
//     g_dwMainThreadId = GetCurrentThreadId();
//     SetConsoleCtrlHandler( ConsoleCtrlhandler, TRUE );
// 
//     MSG msg;
//     while ( GetMessage( &msg, NULL, 0, 0 ) )
//     {
//         TranslateMessage( &msg );
//         DispatchMessage( &msg );
//     }
// 
//     SetConsoleCtrlHandler( ConsoleCtrlhandler, FALSE );

	return 0;
}

