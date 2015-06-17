// easy-IPC-client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NamedPipes.hpp"
#include "MapFile.hpp"
#include "Clipboard.hpp"

int _tmain(int argc, _TCHAR* argv[])
{
//    OnPipeConnect();

//     EasyIPCMapFileClient easyIpc;
//     easyIpc.EasyMapFilesStart();

    EasyIPCClipboardClient easyIpc;
    easyIpc.EasyClipboardStart();

	return 0;
}

