#include "ImCrain.h"
#include "Define.h"
#include "ImColor.h"
#include "ImSandBox.h"

ImCrain::ImCrain()
{	
}

ImCrain::~ImCrain()
{
	Destroy();
}

bool ImCrain::InitBallName()
{
	wcscpy_s(name[0][0],L"아");
	wcscpy_s(name[1][0],L"카");
	wcscpy_s(name[2][0],L"사");
	wcscpy_s(name[3][0],L"타");
	wcscpy_s(name[4][0],L"나");
	wcscpy_s(name[5][0],L"하");
	wcscpy_s(name[6][0],L"마");
	wcscpy_s(name[7][0],L"야");
	wcscpy_s(name[8][0],L"라");
	wcscpy_s(name[9][0],L"와");
	wcscpy_s(name[10][0],L"응");
	
	wcscpy_s(name[0][1],L"이");
	wcscpy_s(name[1][1],L"키");
	wcscpy_s(name[2][1],L"시");
	wcscpy_s(name[3][1],L"치");
	wcscpy_s(name[4][1],L"니");
	wcscpy_s(name[5][1],L"히");
	wcscpy_s(name[6][1],L"미");
	wcscpy_s(name[7][1],L"");
	wcscpy_s(name[8][1],L"리");
	wcscpy_s(name[9][1],L"");
	wcscpy_s(name[10][1],L"");
	
	wcscpy_s(name[0][2],L"우");
	wcscpy_s(name[1][2],L"쿠");
	wcscpy_s(name[2][2],L"스");
	wcscpy_s(name[3][2],L"쯔");
	wcscpy_s(name[4][2],L"누");
	wcscpy_s(name[5][2],L"후");
	wcscpy_s(name[6][2],L"무");
	wcscpy_s(name[7][2],L"유");
	wcscpy_s(name[8][2],L"루");
	wcscpy_s(name[9][2],L"");
	wcscpy_s(name[10][2],L"");
	
	wcscpy_s(name[0][3],L"에");
	wcscpy_s(name[1][3],L"케");
	wcscpy_s(name[2][3],L"세");
	wcscpy_s(name[3][3],L"테");
	wcscpy_s(name[4][3],L"네");
	wcscpy_s(name[5][3],L"헤");
	wcscpy_s(name[6][3],L"메");
	wcscpy_s(name[7][3],L"");
	wcscpy_s(name[8][3],L"레");
	wcscpy_s(name[9][3],L"");
	wcscpy_s(name[10][3],L"");
	
	wcscpy_s(name[0][4],L"오");
	wcscpy_s(name[1][4],L"코");
	wcscpy_s(name[2][4],L"소");
	wcscpy_s(name[3][4],L"토");
	wcscpy_s(name[4][4],L"노");
	wcscpy_s(name[5][4],L"호");
	wcscpy_s(name[6][4],L"모");
	wcscpy_s(name[7][4],L"요");
	wcscpy_s(name[8][4],L"로");
	wcscpy_s(name[9][4],L"오");
	wcscpy_s(name[10][4],L"");

	wcscpy_s(sound_name[0][0],L"a");
	wcscpy_s(sound_name[1][0],L"ka");
	wcscpy_s(sound_name[2][0],L"sa");
	wcscpy_s(sound_name[3][0],L"ta");
	wcscpy_s(sound_name[4][0],L"na");
	wcscpy_s(sound_name[5][0],L"ha");
	wcscpy_s(sound_name[6][0],L"ma");
	wcscpy_s(sound_name[7][0],L"ya");
	wcscpy_s(sound_name[8][0],L"ra");
	wcscpy_s(sound_name[9][0],L"wa");
	wcscpy_s(sound_name[10][0],L"n");
	
	wcscpy_s(sound_name[0][1],L"i");
	wcscpy_s(sound_name[1][1],L"ki");
	wcscpy_s(sound_name[2][1],L"si");
	wcscpy_s(sound_name[3][1],L"zi");
	wcscpy_s(sound_name[4][1],L"ni");
	wcscpy_s(sound_name[5][1],L"hi");
	wcscpy_s(sound_name[6][1],L"mi");
	wcscpy_s(sound_name[7][1],L"");
	wcscpy_s(sound_name[8][1],L"ri");
	wcscpy_s(sound_name[9][1],L"");
	wcscpy_s(sound_name[10][1],L"");
	
	wcscpy_s(sound_name[0][2],L"u");
	wcscpy_s(sound_name[1][2],L"ku");
	wcscpy_s(sound_name[2][2],L"su");
	wcscpy_s(sound_name[3][2],L"tsu");
	wcscpy_s(sound_name[4][2],L"nu");
	wcscpy_s(sound_name[5][2],L"hu");
	wcscpy_s(sound_name[6][2],L"mu");
	wcscpy_s(sound_name[7][2],L"yu");
	wcscpy_s(sound_name[8][2],L"ru");
	wcscpy_s(sound_name[9][2],L"");
	wcscpy_s(sound_name[10][2],L"");
	
	wcscpy_s(sound_name[0][3],L"e");
	wcscpy_s(sound_name[1][3],L"ke");
	wcscpy_s(sound_name[2][3],L"se");
	wcscpy_s(sound_name[3][3],L"te");
	wcscpy_s(sound_name[4][3],L"ne");
	wcscpy_s(sound_name[5][3],L"he");
	wcscpy_s(sound_name[6][3],L"me");
	wcscpy_s(sound_name[7][3],L"");
	wcscpy_s(sound_name[8][3],L"re");
	wcscpy_s(sound_name[9][3],L"");
	wcscpy_s(sound_name[10][3],L"");

	wcscpy_s(sound_name[0][4],L"o");
	wcscpy_s(sound_name[1][4],L"ko");
	wcscpy_s(sound_name[2][4],L"so");
	wcscpy_s(sound_name[3][4],L"to");
	wcscpy_s(sound_name[4][4],L"no");
	wcscpy_s(sound_name[5][4],L"ho");
	wcscpy_s(sound_name[6][4],L"mo");
	wcscpy_s(sound_name[7][4],L"yo");
	wcscpy_s(sound_name[8][4],L"ro");
	wcscpy_s(sound_name[9][4],L"ou");
	wcscpy_s(sound_name[10][4],L"");

	return true;
}

bool ImCrain::SetRandomBall()
{
	int name_x = rand()%11;
	int name_y = rand()%5;
	while(_tcscmp(name[name_x][name_y],L"") == 0)
	{
		name_x = rand()%11;
		name_y = rand()%5;
	}
	m_pBall->SetNameX(name_x);
	m_pBall->SetNameY(name_y);
	m_pBall->SetName(name[name_x][name_y]);
	m_pBall->SetSoundName(sound_name[name_x][name_y]);

	return 0;
}

bool ImCrain::Init()
{
	m_pBall = new ImBall();
	m_pBall->Init();
	m_pBall->SetExist(true);
	InitBallName();
	SetRandomBall();

	return true;
}

bool ImCrain::Load(wchar_t* _file_name)
{
	return true;
}

bool ImCrain::Update(float _fElapsedTime)
{
	return true;
}

bool ImCrain::Draw(Graphics& g)
{
	m_pBall->Draw(g);
	
	return true;
}

bool ImCrain::Destroy()
{
	if(m_pBall != NULL)
	{
		delete m_pBall;
		m_pBall = NULL;
	}
	return true;
}

void ImCrain::SetBallX(float _x)
{	
	float box_left = (float)TheSandBox->GetSize().left;
	float box_right = (float)TheSandBox->GetSize().right - BALL_RADIUS*2;
	if( _x <= box_left)
	{
		m_pBall->SetX(box_left);
	}
	else if( box_right <= _x)
	{
		m_pBall->SetX(box_right);
	}
	else
	{
		m_pBall->SetX(_x);
	}
}

ImBall* ImCrain::CloneBall()
{
	ImBall* result_ball = new ImBall();

	float x = m_pBall->GetX();
	float y = m_pBall->GetY();
	*result_ball = *m_pBall;
	result_ball->SetX(x);
	result_ball->SetY(y);
	
	Color new_c = TheColor->GetRandomColor();
	m_pBall->SetColor(new_c);
	SetRandomBall();

	return result_ball;
}

