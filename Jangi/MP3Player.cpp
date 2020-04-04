#include "MP3Player.h"
#include "vfw.h"

MP3Player::MP3Player()
{

}

MP3Player::~MP3Player()
{

}

bool MP3Player::Load(HWND _hWnd,HINSTANCE _hInstance)
{
	m_hWnd = _hWnd;
	m_hInstance = _hInstance;
	m_hVideo = NULL;
	m_bPause = false;

	return true;
}

bool MP3Player::Play(WCHAR* _pPath)
{
	m_hVideo = NULL;

	if(m_hVideo == NULL)
	{
		m_hVideo = MCIWndCreate(m_hWnd,
			m_hInstance,
			WS_CHILD,_pPath);
			/*WS_CHILD | WS_VISIBLE|MCIWNDF_NOMENU,_pPath);*/
	}
	else
	{
		MCIWndHome(m_hVideo);
	}

	MCIWndPlay(m_hVideo);
	m_bPause = false;

	return true;
}

bool MP3Player::Stop()
{
	MCIWndStop(m_hVideo);
	if(m_hVideo !=NULL)
	{
		MCIWndDestroy(m_hVideo);
	}

	return true;
}

bool MP3Player::Cancel()
{
	if(m_hVideo !=NULL)
	{
		MCIWndDestroy(m_hVideo);
	}

	return true;
}

bool MP3Player::Pause()
{
	if(m_bPause == true)
	{
		MCIWndResume(m_hVideo);
		m_bPause = false;
	}
	else
	{
		MCIWndPause(m_hVideo);
		m_bPause = true;
	}

	return true;
}