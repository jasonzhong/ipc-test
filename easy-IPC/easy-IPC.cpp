// easy-IPC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NamedPipes.hpp"
#include "MapFile.hpp"
#include "Clipboard.hpp"

int _tmain(int argc, _TCHAR* argv[])
{
    BOOL bRet = FALSE;

//     EasyIPCNamePipesService easyIpc;
//     easyIpc.EasyPipeStart();

//     EasyIPCMapFileService easyIpc;
//     easyIpc.EasyMapFilesStart();

    EasyIPCClipboardService easyIpc;
    easyIpc.EasyClipboardStart();

	return 0;
}

