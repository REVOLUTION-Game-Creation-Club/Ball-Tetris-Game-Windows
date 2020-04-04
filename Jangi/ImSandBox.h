#pragma once

#include "Define.h"

class ImBall;

/*
* 바구니
*/
class ImSandBox
{
public:
	/*
	* 전역클래스
	*/
	static ImSandBox* GetInstance()
	{
		static ImSandBox g_box;
		return &g_box;
	}

	/*
	* 초기화 함수
	*/
	bool Init();
	/*
	* 이미지로드 함수(아직 사용하지 않음)
	*/
	bool Load(wchar_t* _file_name);

	/*
	* 데이터 업데이트 처리 함수
	*/
	bool Update(float _fElapsedTime);

	/*
	* 이미지 그리기 함수
	*/
	bool Draw(Graphics& g);

	/*
	* 할당된 멤버변수를 해제하는 함수
	*/
	bool Destroy();

	/*
	* 크래인으로 부터 복사된 함수 
	* 볼의 정보를 받아서 화면에 표시하고 업데이트한다.
	*/
	void SetBall(ImBall* _pBall);

	/*
	* 바구니의 영역을 얻어온다.
	*/
	RECT GetSize(){ return m_Size; }

	/*
	* 바구니의 가로, 세로에 들어가는 볼의 갯수
	*/
	int GetArrayW(){ return m_array_ball_w;}
	int GetArrayH(){ return m_array_ball_h;}	

	/*
	* 볼(장기말)의 배열에서 볼의 정보를 얻어온다.
	*/
	ImBall* GetBall(int _tile_x, int _tile_y);

	/*
	* 낙하중인 볼(NewBall)을 얻어온다.
	*/ 
	ImBall* GetNewBall(){ return m_pNewBall; }

	/*
	* 지정된 위치의 볼을 아래로 내려가게 한다.
	*/
	bool DropBallAll();

	/*
	* 같은 색이 3개이상 있다면 3개의 볼을 사라지게 한다.
	* 검은색볼은 검은색볼 주위의 일정영역의 볼들을 사라지게 한다.
	* 하얀색볼들은 검은색볼에 의한 것이 아니면 연속되더라도 사라지지 않는다.
	*/
	bool RemoveSameColorBallAll();

	/*
	* 아래에서 볼들이 한줄씩 올라온다.(아직 사용하지 않음)
	*/
	void UpBallLine();
private: // 내부함수 
	ImSandBox();
	virtual ~ImSandBox();

	/*
	* h,w: 현재 볼의 좌표
	* DropBallAll()의 내부함수 
	* 지정된 좌표 주위의 볼이 아래로 떨어지게 한다.
	*/
	bool DropBall(int h, int w);

	/*
	* h, w: 현재 볼의 좌표
	* RemoveSameColorBallAll()의 내부함수
	* SameColorBall()에서 찾은 같은 색볼의
	* 리스트(m_vecSameBalls)를 확인해서 
	* 볼을 사라지게 한다.
	*/
	bool RemoveSameColorBall(int h, int w);

	/*
	* h, w: 현재 볼의 좌표
	* RemoveSameColorBallAll()의 내부함수
	* 주위를 검색하여 같은 색을 재귀적으로 찾는다.
	*/
	int SameColorBall(int h, int w, int count);

	/*
	* 볼 배열의 위치와 영역을 표시한다.
	* 디버그 용도로 사용된다.
	*/
	void DebugView(Graphics& g);

	/*
	* 볼이 들어갈 영역(m_Size)을 표시한다.
	*/
	void DrawBoxLine(Graphics& g);

	/*
	* 새로운 볼이 쌓여진 볼과 충돌했는지 여부를
	* 처리한다.
	*/
	bool CollisionBall();

	/*
	* 새로운 볼이 아래끝선과 충돌했는지 여부를
	* 처리한다.
	*/
	bool CollisionLine();

	/*
	* 가장 윗라인에 볼이 쌓이면 게임이 끝난다.
	* 게임 종료 모드인지 확인한다.
	*/
	bool CheckGameEnd();

	/*
	* h,w: 볼 배열의 좌표
	* 검은색 볼(폭탄 볼)이 지정된 
	* 위치 주위의 볼들을 사라지게 한다.
	*/
	int BombBall(int h, int w);

	RECT m_Size; // 바구니의 사이즈
	ImBall* m_pNewBall; // 낙하중인 볼
	ImBall** m_ppBall; // 볼의 배열(보일 수도 있고 안보일 수도 있음)
	int m_array_ball_w; // 바구니 안에 들어가는 최대 볼의 가로 갯수
	int m_array_ball_h; // 바구니 안에 들어가는 최대 볼의 세로 갯수
	vector<ImBall*> m_vecSameBalls; // 같은 볼이 들어가는 리스트
	float m_fLimitTime; // 제한시간이 지나면 아래에서 볼이 올라옴(아직 구현하지 않음)
	// 볼을 사라지게 할 때 마다 1점. 
	// 같은색이 3개이상 연속적으로 
	// 사라지게 할 수록 점수가 누적계산이 됨 
	int m_iScore; 
};

#define TheSandBox ImSandBox::GetInstance()