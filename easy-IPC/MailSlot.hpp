#include "stdafx.h"

class EasyIPCMailslotService
{
public:
    EasyIPCMailslotService();

    BOOL EasyMailslotStart();

protected:
    BOOL _MailslotReceive( HANDLE& m_hMailSolt, CString& strBuffer );

private:
    HANDLE m_hMailSlot;
};

EasyIPCMailslotService::EasyIPCMailslotService()
{
    m_hMailSlot = NULL;
}

BOOL EasyIPCMailslotService::EasyMailslotStart()
{
    m_hMailSlot = CreateMailslot( L"\\\\.\\Mailslot\\myslot", 0, MAILSLOT_WAIT_FOREVER, NULL );
    if ( m_hMailSlot == INVALID_HANDLE_VALUE )
    {
        return FALSE;
    }

    CString strBuffer;
    INT nTime = 0;
    while ( nTime < 1000000 )
    {
        _MailslotReceive( m_hMailSlot, strBuffer );
        ++nTime;
        if ( !strBuffer.IsEmpty() )
        {
            break;
        }
        Sleep( 1000 );
    }

    MessageBox( NULL, strBuffer, L"", 0 );
    
    return TRUE;
}

BOOL EasyIPCMailslotService::_MailslotReceive( HANDLE& m_hMailSolt, CString& strBuffer )
{
    BOOL bReadFile = FALSE;
    WCHAR szBuffer[256] = {0};
    DWORD dwNumberOfBytesRead = 0;
    bReadFile = ReadFile( m_hMailSlot, szBuffer, 256, &dwNumberOfBytesRead, NULL );

    if ( !bReadFile )
    {
        return FALSE;
    }

    strBuffer = szBuffer;
    return TRUE;
}
