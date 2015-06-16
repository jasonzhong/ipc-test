#include "stdafx.h"

class EasyIPCNamePipesService
{
public:
    EasyIPCNamePipesService();

    BOOL EasyPipeStart();

protected:
    BOOL _PipeCreate( HANDLE& hPipe, HANDLE& hEvent );
    BOOL _Send( HANDLE& hPipe );

private:
    HANDLE m_hPipe;
    HANDLE m_hEvent;
};

EasyIPCNamePipesService::EasyIPCNamePipesService()
{
    m_hPipe = NULL;
    m_hEvent = NULL;
}

BOOL EasyIPCNamePipesService::EasyPipeStart()
{
    BOOL bRet = FALSE;
    m_hEvent = CreateEvent( NULL, TRUE, FALSE, NULL );
    if ( !m_hEvent )
    {
        goto Exit0;
    }

    bRet = _PipeCreate( m_hPipe, m_hEvent );
    if ( !bRet )
    {
        goto Exit0;
    }

    _Send( m_hPipe );

    Sleep( 10 * 1000 * 60 );

Exit0:
    if ( m_hPipe )
    {
        CloseHandle( m_hPipe );
    }

    if ( m_hEvent )
    {
        CloseHandle( m_hEvent );
    }
    m_hPipe = NULL;
    m_hEvent = NULL;

    return TRUE;
}

BOOL EasyIPCNamePipesService::_PipeCreate( HANDLE& hPipe, HANDLE& hEvent )
{
    hPipe = CreateNamedPipe( L"\\\\.\\pipe\\MyPipe",
                             PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED,
                             0, 1, 1024, 1024, 0, NULL );
    if ( INVALID_HANDLE_VALUE == hPipe )
    {
        return FALSE;
    }

    OVERLAPPED ovlap = {0};
    ovlap.hEvent = hEvent;
    if ( !ConnectNamedPipe( hPipe, &ovlap ) )
    {
        if ( ERROR_IO_PENDING != GetLastError() )
        {
            return FALSE;
        }
    }

    if( WAIT_FAILED == WaitForSingleObject( hEvent, INFINITE ) )
    {
        return FALSE;
    }

    return TRUE;
}

BOOL EasyIPCNamePipesService::_Send( HANDLE& hPipe )
{
    CHAR buf[50] = {0};
    strcpy_s( buf, 50, "hello my first ipc" );

    CHAR* pbuf = buf;
    DWORD dwWrite;
    if( !WriteFile( hPipe, pbuf, (DWORD)strlen(pbuf)+1, &dwWrite, NULL ) )
    {
        return FALSE;
    }

    return TRUE;
}