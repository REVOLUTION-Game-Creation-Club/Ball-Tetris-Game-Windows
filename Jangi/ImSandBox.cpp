#include "ImSandBox.h"
#include "ImBall.h"
#include "ImColor.h"

ImSandBox::ImSandBox()
{
}

ImSandBox::~ImSandBox()
{
	Destroy();
}

bool ImSandBox::Init()
{
	m_pNewBall = NULL;

	m_Size.left = 100;
	m_Size.right = 640 - 100;
	m_Size.top = 100;
	m_Size.bottom = 960 - 100;

	m_array_ball_h = (int)((m_Size.bottom - m_Size.top) / (BALL_RADIUS*2));
	m_array_ball_w = (int)((m_Size.right - m_Size.left) / (BALL_RADIUS*2));

	m_ppBall = new ImBall*[m_array_ball_h];

	for(int h = 0; h < m_array_ball_h; h++)
	{
		m_ppBall[h] = new ImBall[m_array_ball_w];
	}

	for(int h = 0; h < m_array_ball_h; h++)
	{
		for(int w = 0; w < m_array_ball_w; w++)
		{
			m_ppBall[h][w].Init();

			float r = m_ppBall[h][w].GetRadius();
			float x = (float)TheSandBox->GetSize().left;
			float y = (float)TheSandBox->GetSize().bottom;

			switch(h%2)
			{
			case 0:
				m_ppBall[h][w].SetX(x+w*r*2);
				break;
			case 1:
				m_ppBall[h][w].SetX(x+w*r*2+r);
				break;
			}
			m_ppBall[h][w].SetY(y-h*r*2-r*2);

			m_ppBall[h][w].SetExist(false);
		}
	}

	m_fLimitTime = 0.0f;
	m_iScore = 0;

	return true;
}

bool ImSandBox::Load(wchar_t* _file_name)
{

	return true;
}

void ImSandBox::UpBallLine()
{

	//for(int h = (m_array_ball_h - 1); h > 0; h--)
	//{
	//	for(int w = 0; w < m_array_ball_w; w++)
	//	{
	//		float r = m_ppBall[h][w].GetRadius();
	//		float x = (float)TheSandBox->GetSize().left;
	//		float y = (float)TheSandBox->GetSize().bottom;

	//		switch(h%2)
	//		{
	//		case 0:
	//			m_ppBall[h][w].SetX(x+w*r*2+r);
	//			break;
	//		case 1:
	//			m_ppBall[h][w].SetX(x+w*r*2);
	//			break;
	//		}

	//		Color c = m_ppBall[h-1][w].GetColor();
	//		m_ppBall[h][w].SetColor(c);

	//		bool bExist = m_ppBall[h-1][w].GetExist();
	//		m_ppBall[h][w].SetExist(bExist);
	//	}
	//}

	//for(int w = 0; w < m_array_ball_w; w++)
	//{
	//	float r = m_ppBall[0][w].GetRadius();
	//	float x = (float)TheSandBox->GetSize().left;

	//	m_ppBall[0][w].SetX(x+w*r*2+r);
	//	Color c = TheColor->GetRandomColor();
	//	m_ppBall[0][w].SetColor(c);
	//	m_ppBall[0][w].SetExist(true);
	//}
}
bool ImSandBox::CheckGameEnd()
{
	for(int w = 0; w < m_array_ball_w; w++)
	{
		if(m_ppBall[m_array_ball_h-1][w].GetExist() == true)
		{
			return true;
		}
	}

	return false;
}
// 아래선과 충돌
bool ImSandBox::CollisionLine()
{
	if(m_pNewBall == NULL)
		return false;

	float end_line_y = (float)(GetSize().bottom - BALL_RADIUS);

	if(m_pNewBall->GetY() >= end_line_y)
	{
		m_pNewBall->SetY(end_line_y);

		int tile_x = m_pNewBall->GetTileX();
		if(tile_x < 0)
		{
			tile_x = 0;
		}
		int tile_y = m_pNewBall->GetTileY();
		if(tile_y < 0)
		{
			tile_y = 0;
		}

		Color c = m_pNewBall->GetColor();
		if(c.GetValue() == Color::Black) // bomb
		{
			BombBall(tile_x,tile_y);
		}
		else if(m_ppBall[tile_y][tile_x].GetExist()== false)
		{
			m_ppBall[tile_y][tile_x] = *m_pNewBall;
			m_ppBall[tile_y][tile_x].SetExist(true);
		}

		delete m_pNewBall;
		m_pNewBall = NULL;
		return true;
	}

	return false;
}

// 볼 충돌체크

bool ImSandBox::CollisionBall()
{
	for(int h = 0; h < m_array_ball_h; h++)
	{
		for(int w = 0; w < m_array_ball_w; w++)
		{
			bool ret = m_pNewBall->CollisionBall(&m_ppBall[h][w]);
			if(ret== false)
				continue;

			if(w < 0)
			{
				w = 0;
			}

			if(w > (m_array_ball_w-1))
			{
				w = m_array_ball_w-1;
			}

			Color c = m_pNewBall->GetColor();

			if(c.GetValue() == Color::Black) // Bomb
			{
				BombBall(h,w);
			}
			else if(m_ppBall[h][w].GetExist() == false)
			{
				m_ppBall[h][w] = *m_pNewBall;
				m_ppBall[h][w].SetExist(true);
			}
			else if(m_ppBall[h+1][w].GetExist() == false)
			{
				m_ppBall[h+1][w] = *m_pNewBall;
				m_ppBall[h+1][w].SetExist(true);
			}
			else if(m_ppBall[h+1][w-1].GetExist() == false)
			{
				m_ppBall[h+1][w-1] = *m_pNewBall;
				m_ppBall[h+1][w-1].SetExist(true);
			}
			else if(m_ppBall[h+1][w+1].GetExist() == false)
			{
				m_ppBall[h+1][w+1] = *m_pNewBall;
				m_ppBall[h+1][w+1].SetExist(true);
			}

			delete m_pNewBall;
			m_pNewBall = NULL;
				
			return true;
		}
	}

	return false;
}

bool ImSandBox::Update(float _fElapsedTime)
{
	m_fLimitTime += _fElapsedTime;
	if(m_fLimitTime >= 10.0f)
	{
		m_fLimitTime = 0.0f;
		//UpBallLine();
	}


	// 위에 쌓인 볼 아래로 떨어뜨리기
	DropBallAll();
	RemoveSameColorBallAll();

	if(m_pNewBall == NULL)
		return true;

	m_pNewBall->Update(_fElapsedTime);

	CollisionBall();
	CollisionLine();
	
	if(CheckGameEnd() == true)
	{
		Init();
	}

	return true;
}

void ImSandBox::DebugView(Graphics& g)
{
	int r = (int)BALL_RADIUS;

	for(int h = 0; h < m_array_ball_h; h++)
	{
		for(int w = 0; w < m_array_ball_w; w++)
		{
			Pen myPen(Color::Pink, 5);

			Font font(&FontFamily(L"Arial"), 12);
			LinearGradientBrush brush(Rect(0,0,100,100), Color::Red, Color::Yellow, LinearGradientModeHorizontal);

			wchar_t buff[32];			
			wsprintf(buff,L"%d,%d",h,w);
			float x = m_ppBall[h][w].GetX();
			float y = m_ppBall[h][w].GetY();
			if(h%2 == 0)
			{
				g.DrawEllipse(&myPen,(int)x,(int)y,80,80);

				g.DrawString(buff, -1, &font, PointF(x,y), &brush);
			}
			else
			{
				//REAL long_x = (REAL)(m_Size.left+w*r*2+r);
				//REAL long_y = (REAL)(m_Size.bottom-h*r*2-r*2);
				g.DrawEllipse(&myPen,(int)x, (int)y, 80,80);
				
				g.DrawString(buff, -1, &font, PointF(x, y), &brush);
			}
		}
	}
}
bool ImSandBox::Draw(Graphics& g)
{
	DebugView(g);
	DrawBoxLine(g);
	for(int h = 0; h < m_array_ball_h; h++)
	{
		for(int w = 0; w < m_array_ball_w; w++)
		{
			if(m_ppBall[h][w].GetExist() == false)
				continue;

			m_ppBall[h][w].Draw(g);
		}
	}

	if(m_pNewBall != NULL)
	{
		m_pNewBall->Draw(g);
	}

	Font font(&FontFamily(L"Arial"), 12);
	LinearGradientBrush brush(Rect(0,0,100,100), Color::Red, Color::Yellow, LinearGradientModeHorizontal);

	wchar_t buff[32];

	wsprintf(buff,L"%d",m_iScore);
	g.DrawString(buff, -1, &font, PointF(100, 100), &brush);
	return true;
}

bool ImSandBox::Destroy()
{
	for(int h = 0; h < m_array_ball_h; h++)
	{
		delete [] m_ppBall[h];
	}
	
	delete [] m_ppBall;

	if(m_pNewBall != NULL)
	{
		delete m_pNewBall;
		m_pNewBall = NULL;
	}

	return true;
}

void ImSandBox::SetBall(ImBall* _pBall)
{
	m_pNewBall = _pBall;
	m_pNewBall->SetExist(true);
}

ImBall* ImSandBox::GetBall(int _tile_x, int _tile_y)
{
	if(_tile_x < 0)
		return NULL;
	if(_tile_y < 0)
		return NULL;
	if(_tile_x >= GetArrayW())
		return NULL;
	if(_tile_y >= GetArrayH())
		return NULL;

	return &m_ppBall[_tile_y][_tile_x];
}

bool ImSandBox::DropBallAll()
{
	for(int h = m_array_ball_h-1; h > 0 ; h--)
	{
		for(int w = 0; w < m_array_ball_w; w++)
		{
			if(m_ppBall[h][w].GetExist() == false)
				continue;

			DropBall(h,w);
		}
	}

	return true;
}

bool ImSandBox::DropBall(int h, int w)
{
	// 바로 아래가 비었다면
	if(m_ppBall[h-1][w].GetExist() == false)
	{
		m_ppBall[h][w].SetExist(false);
		m_ppBall[h-1][w] = m_ppBall[h][w];
		m_ppBall[h-1][w].SetExist(true);
			
		return true;
	}

	if((w-1) >= 0)
	{
		// 아래 왼쪽이 비었다면
		if(m_ppBall[h-1][w-1].GetExist() == false)
		{
			m_ppBall[h][w].SetExist(false);
			m_ppBall[h-1][w-1] = m_ppBall[h][w];
			m_ppBall[h-1][w-1].SetExist(true);

			return true;
		}
	}
	// 아래 오른쪽이 비었다면
	if(m_ppBall[h-1][w+1].GetExist() == false)
	{
		m_ppBall[h][w].SetExist(false);
		m_ppBall[h-1][w+1] = m_ppBall[h][w];
		m_ppBall[h-1][w+1].SetExist(true);

		return true;
	}

	return false;
}

bool ImSandBox::RemoveSameColorBallAll()
{
	for(int h = m_array_ball_h-1; h >= 0 ; h--)
	{
		for(int w = 0; w < m_array_ball_w; w++)
		{
			if(m_ppBall[h][w].GetExist() == false)
				continue;

			RemoveSameColorBall(h, w);
		}
	}

	return true;
}

bool ImSandBox::RemoveSameColorBall(int h, int w)
{

	int count = SameColorBall(h,w,0);
	if( count <= 2)
	{
		vector<ImBall*>::iterator itr;
		for(itr = m_vecSameBalls.begin(); itr != m_vecSameBalls.end(); itr++ )
		{
			(*itr)->SetCheck(false);
		}
		m_vecSameBalls.clear();
	}
	else
	{
		vector<ImBall*>::iterator itr;
		for(itr = m_vecSameBalls.begin(); itr != m_vecSameBalls.end(); itr++ )
		{
			(*itr)->SetCheck(false);
			(*itr)->SetExist(false);
			(*itr)->PlaySound();
			m_iScore += 1;
		}
		
		if(count > 3)
		{
			m_iScore += count*count;
		}

		m_vecSameBalls.clear();
	}
	return true;
}

int ImSandBox::BombBall(int h, int w)
{
	for(int i = -1; i < 2; i++)
	{
		for(int k = -1; k < 2; k++)
		{
			if((h+i < 0)||(h+i > m_array_ball_h-1))
				continue;
			if((w+k < 0)||(w+k > m_array_ball_w-1))
				continue;

			if(m_ppBall[h+i][w+k].GetExist() == false)
				continue;

			m_ppBall[h+i][w+k].SetExist(false);
			m_iScore += 1;
		}
	}

	return 0;
}

int ImSandBox::SameColorBall(int h, int w, int count)
{
	if(m_ppBall[h][w].GetExist() == false)
		return -1;

	for(int i = -1; i < 2; i++)
	{
		for(int k = -1; k < 2; k++)
		{
			if(( i == 0 )&&(k == 0))
				continue;
			if(h%2 == 0)
			{
				if(( i == 1 )&&(k == 1))
					continue;
				if(( i == -1 )&&(k == 1))
					continue;
			}
			else
			{
				if(( i == 1 )&&(k == -1))
					continue;
				if(( i == -1 )&&(k == -1))
					continue;
			}

			if((h+i < 0)||(h+i > m_array_ball_h-1))
				continue;
			if((w+k < 0)||(w+k > m_array_ball_w-1))
				continue;

			if(m_ppBall[h+i][w+k].GetExist() == false)
				continue;
			if(m_ppBall[h+i][w+k].GetCheck() == true)
				continue;
			
			Color cc1 = m_ppBall[h][w].GetColor();
			Color cc2 = m_ppBall[h+i][w+k].GetColor();

			if(cc1.GetValue() == Color::White)
				continue;
			if(cc2.GetValue() == Color::White)
				continue;

			if(cc1.GetValue() == cc2.GetValue())
			{
				if(count == 0)
				{
					m_vecSameBalls.push_back(&m_ppBall[h][w]);
					m_ppBall[h][w].SetCheck(true);
				}

				m_vecSameBalls.push_back(&m_ppBall[h+i][w+k]);
				m_ppBall[h+i][w+k].SetCheck(true);

				SameColorBall(h+i,w+k,count+1);
			}
		}
	}

	return (int)m_vecSameBalls.size();
}

void ImSandBox::DrawBoxLine(Graphics& g)
{
	Pen myPen(Color::Green);
	myPen.SetWidth(4);

	g.DrawLine(&myPen,Point(m_Size.left,m_Size.top),Point(m_Size.left,m_Size.bottom));
	g.DrawLine(&myPen,Point(m_Size.right,m_Size.top),Point(m_Size.right,m_Size.bottom));
	g.DrawLine(&myPen,Point(m_Size.left,m_Size.bottom),Point(m_Size.right,m_Size.bottom));
}