#include "stdafx.h"

class EasyIPCMapFileService
{
public:
    EasyIPCMapFileService();

    BOOL EasyMapFilesStart();

protected:
    BOOL _MapFileSend( HANDLE& m_hShareMemory, CHAR* lpBuffer );

private:
    HANDLE m_hShareMemory;
};

EasyIPCMapFileService::EasyIPCMapFileService()
{
    m_hShareMemory = NULL;
}

BOOL EasyIPCMapFileService::EasyMapFilesStart()
{
    CHAR* lpBuffer = NULL;

    m_hShareMemory = ::CreateFileMapping( HANDLE(0xFFFFFFFF), NULL, PAGE_READWRITE, 0, 100, L"firstmapfilesharedmemory" );
    if ( !m_hShareMemory )
    {
        if ( GetLastError() == ERROR_ALREADY_EXISTS )
        {
            return FALSE;
        }
        return FALSE;
    }

    _MapFileSend( m_hShareMemory, lpBuffer );
    Sleep( 10 * 1000 * 1000 * 60 );

    return TRUE;
}

BOOL EasyIPCMapFileService::_MapFileSend( HANDLE& m_hShareMemory, CHAR* lpBuffer )
{
    lpBuffer = ( CHAR* )MapViewOfFile( m_hShareMemory, FILE_MAP_WRITE, 0, 0, 100 );
    if ( !lpBuffer )
    {
        return FALSE;
    }

    strcpy_s( lpBuffer, 100, "hello my first ipc" );
    UnmapViewOfFile( lpBuffer );
    lpBuffer = NULL;

    return TRUE;
}
