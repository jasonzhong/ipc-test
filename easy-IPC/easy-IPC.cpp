// easy-IPC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NamedPipes.hpp"
#include "MapFile.hpp"
#include "Clipboard.hpp"
#include "MessageIpc.hpp"
#include "MailSlot.hpp"

int _tmain(int argc, _TCHAR* argv[])
{
    BOOL bRet = FALSE;

//     EasyIPCNamePipesService easyIpc;
//     easyIpc.EasyPipeStart();

//     EasyIPCMapFileService easyIpc;
//     easyIpc.EasyMapFilesStart();

//     EasyIPCClipboardService easyIpc;
//     easyIpc.EasyClipboardStart();

//     EasyIPCMessageService easyIpc;
//     easyIpc.EasyMessageStart();

    EasyIPCMailslotService easyIpc;
    easyIpc.EasyMailslotStart();
	
    return 0;
}

