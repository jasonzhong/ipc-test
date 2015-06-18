#include "stdafx.h"

class EasyIPCMailslotClient
{
public:
    EasyIPCMailslotClient();

    BOOL EasyMailslotStart();

protected:
    BOOL _MailslotSend( HANDLE& m_hMailSolt, WCHAR* lpBuffer );

private:
    HANDLE m_hMailSlot;
};

EasyIPCMailslotClient::EasyIPCMailslotClient()
{
    m_hMailSlot = NULL;
}

BOOL EasyIPCMailslotClient::EasyMailslotStart()
{
    m_hMailSlot = CreateFile( L"\\\\.\\Mailslot\\myslot", GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
    if ( m_hMailSlot == INVALID_HANDLE_VALUE )
    {
        return FALSE;
    }

    _MailslotSend( m_hMailSlot, L"hello, my first mailslot ipc" );
    return TRUE;
}

BOOL EasyIPCMailslotClient::_MailslotSend( HANDLE& m_hMailSolt, WCHAR* lpBuffer )
{
    DWORD bytesWritten;
    while ( WriteFile( m_hMailSlot, lpBuffer, 100, &bytesWritten, NULL ) == 0 )
    {
        return FALSE;
    }
    return TRUE;
}
