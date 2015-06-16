// easy-IPC-client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NamedPipes.hpp"
#include "MapFile.hpp"

int _tmain(int argc, _TCHAR* argv[])
{
//    OnPipeConnect();

    EasyIPCMapFileClient easyIpc;
    easyIpc.EasyMapFilesStart();

	return 0;
}

