#include "ImBall.h"
#include "Define.h"
#include "ImSandBox.h"
#include "ImColor.h"
#include "MP3Player.h"


ImBall::ImBall()
{
}

ImBall::~ImBall()
{
}
	
bool ImBall::Init()
{
	m_x = 0.0f;
	m_y = 0.0f;
	m_radius = BALL_RADIUS;
	m_color = TheColor->GetRandomColor();
	m_bExist = false;
	m_bCheck = false;
	m_name_x = 0;
	m_name_y = 0;
	memset(name,0,64*sizeof(wchar_t));
	memset(sound_name,0,64*sizeof(wchar_t));

	return true;
}

bool ImBall::Load(wchar_t* _file_name)
{

	return true;
}

bool ImBall::Update(float _fElapsedTime)
{
	if(m_bExist == false)
		return true;

	m_y += _fElapsedTime*500.0f;

	return true;
}

bool ImBall::Draw(Graphics& g)
{
	if(m_bExist == false)
		return true;

	REAL src_width = 80;
	REAL src_height = 80;
	REAL src_x = m_name_x*src_width;
	REAL src_y = m_name_y*src_height;

	Image imgHira(L"hira.png");
	
	float r = GetRadius();
	RectF destRect(m_x, m_y, 80.0f, 80.0f);
	ImageAttributes img_att;

	//g.DrawImage(&imgHira,srcRect);
	g.DrawImage(
	&imgHira,
	destRect,
	src_x, src_y,       // upper-left corner of source rectangle
	src_width,      // width of source rectangle
	src_height,     // height of source rectangle
	UnitPixel,
	&img_att);

	Pen myPen(m_color);
	myPen.SetWidth(5);

	g.DrawEllipse(&myPen , m_x, m_y, m_radius*2, m_radius*2);

	return true;
}

bool ImBall::Destroy()
{

	return true;
}

bool ImBall::CollisionBall(ImBall* _pBall)
{
	if(_pBall->GetExist() == false)
	{
		return false;
	}

	float dx = this->GetX() - _pBall->GetX();
	float dy = this->GetY() - _pBall->GetY();
	float r = GetRadius();

	if(dx*dx+dy*dy < r*2*r*2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int ImBall::GetTileX()
{ 
	return (int)((m_x-TheSandBox->GetSize().left)/(m_radius*2)); 
}

int ImBall::GetTileY()
{ 
	return (int)((TheSandBox->GetSize().bottom-m_y)/(m_radius*2)); 
}


bool ImBall::PlaySound()
{
	wchar_t* fileName = GetSoundName();
	wchar_t path[128];
	GetCurrentDirectory(128,path);
	wcscat_s(path,L"\\sound\\");
	wcscat_s(path,fileName);
	TheMP3Player->Play(path);

	return true;
}

void ImBall::SetName(wchar_t* _name)
{
	memset(name,0,sizeof(wchar_t)*64);
	wcscpy_s(name,_name);
}

void ImBall::SetSoundName(wchar_t* _sound_name)
{
	memset(sound_name,0,sizeof(wchar_t)*64);
	wcscpy_s(sound_name,_sound_name);
	wcscat_s(sound_name,L".mp3");
}
