#include "stdafx.h"

class EasyIPCMapFileClient
{
public:
    EasyIPCMapFileClient();

    BOOL EasyMapFilesStart();

protected:
    BOOL _MapFileReceive( HANDLE& m_hShareMemory, CString& strBuffer );

private:
    HANDLE m_hShareMemory;
};

EasyIPCMapFileClient::EasyIPCMapFileClient()
{
    m_hShareMemory = NULL;
}

BOOL EasyIPCMapFileClient::EasyMapFilesStart()
{
    m_hShareMemory = OpenFileMapping( FILE_MAP_READ, false, L"firstmapfilesharedmemory" );
    if ( !m_hShareMemory )
    {
        return FALSE;
    }
    
    CString strBuffer;
    _MapFileReceive( m_hShareMemory, strBuffer );

    MessageBox( NULL, strBuffer, L"", 0 );

    CloseHandle( m_hShareMemory );
    m_hShareMemory = NULL;

    return TRUE;
}

BOOL EasyIPCMapFileClient::_MapFileReceive( HANDLE& m_hShareMemory, CString& strBuffer )
{
    CHAR* lpcBuffer = NULL;
    lpcBuffer = ( CHAR* )MapViewOfFile( m_hShareMemory, FILE_MAP_READ, 0, 0, 100 );
    if ( !lpcBuffer )
    {
        return FALSE;
    }

    strBuffer = lpcBuffer;
    UnmapViewOfFile( lpcBuffer );
    lpcBuffer = NULL;

    return TRUE;
}
