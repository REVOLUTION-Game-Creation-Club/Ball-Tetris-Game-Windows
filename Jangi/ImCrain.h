#pragma once
#include "Define.h"
#include "ImBall.h"

/*
* 크래인: 바구니 위에서 움직이는 장기말
*/
class ImCrain
{
public:
	static ImCrain* GetInstance()
	{
		static ImCrain g_Crain;
		return &g_Crain;
	}
	/*
	* 초기화함수
	*/
	bool Init();

	/*
	* 이미지파일 로드 함수
	*/
	bool Load(wchar_t* _file_name);

	/*
	* 데이터 업데이트 함수
	*/
	bool Update(float _fElapsedTime);

	/*
	* 이미지를 그리는 함수
	*/
	bool Draw(Graphics& g);

	/*
	* 할당된 멤버변수를 해제하는 함수
	*/
	bool Destroy();

	/*
	* 마우스 좌표에 따라 크레인의 장기말의 
	* x값을 설정해준다.
	*/
	void SetBallX(float _x);

	/*
	* 크래인의 볼을 복사하여 리턴한다.
	*/
	ImBall* CloneBall();

	/*
	* 크래인의 볼의 이름과 색을 랜덤하게 설정해준다.
	*/
	bool SetRandomBall();

private: // 내부 함수
	/*
	* 생성자
	*/
	ImCrain();

	/*
	* 파괴자
	*/
	virtual ~ImCrain();

	/* 
	 * 볼의 이름배열에 미리 값을 넣는다.
	 */
	bool InitBallName();

	wchar_t name[11][5][8]; // 볼의 이름 배열
	wchar_t sound_name[11][5][8];// 볼의 사운드 배열

	ImBall* m_pBall;
};

#define TheCrain ImCrain::GetInstance()