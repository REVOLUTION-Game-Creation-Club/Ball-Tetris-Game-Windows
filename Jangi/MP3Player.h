#pragma once

#include <Windows.h>

class MP3Player
{
public:
	MP3Player();
	virtual ~MP3Player();

	static MP3Player* GetInstance()
	{
		static MP3Player g_MP3Player;
		return &g_MP3Player;
	}

	bool Load(HWND _hWnd,HINSTANCE _hInstance);
	bool Play(WCHAR* _pPath);
	bool Stop();
	bool Cancel();
	bool Pause();
	
private:
	HWND m_hWnd;
	HINSTANCE m_hInstance;
	HWND m_hVideo;
	bool m_bPause;
};

#define TheMP3Player MP3Player::GetInstance()