#pragma once

#include "Define.h"
/*
* ImBall 장기말
*/
class ImBall
{
public:
	ImBall();

	/*
	* 복사생성자: 좌표는 복사하지 않는다.(좌표는 수동으로 조절한다.)
	*/
	ImBall(ImBall& _ball)
	{
		//m_x = _ball.m_x;
		//m_y = _ball.m_y;
		//m_radius = _ball.m_radius;
		m_color = _ball.m_color;
		//m_bExist = _ball.m_bExist;
		//m_bCheck = _ball.m_bCheck;
		memset(name,0,64);
		_tcscpy_s(name,_ball.name);
		memset(sound_name,0,64);
		_tcscpy_s(sound_name,_ball.sound_name);
		m_name_x = _ball.m_name_x;
		m_name_y = _ball.m_name_y;
	}

	/*
	* 대입연산자: 좌표는 복사하지 않는다.(좌표는 수동으로 조절한다.)
	*/
	ImBall& operator=(const ImBall& _ball)
    { 
		//m_x = _ball.m_x;
		//m_y = _ball.m_y;
		m_radius = _ball.m_radius;
		m_color = _ball.m_color;

		memset(name,0,64*sizeof(wchar_t));
		_tcscpy_s(name,_ball.name);
		memset(sound_name,0,64*sizeof(wchar_t));
		_tcscpy_s(sound_name,_ball.sound_name);
		m_name_x = _ball.m_name_x;
		m_name_y = _ball.m_name_y;

		return *this; 
    }

	/*
	* 소멸자
	*/
	virtual ~ImBall();
	
	/*
	* 초기화 함수: 변수들을 초기화한다./
	*/
	bool Init();
	
	/*
	* 이미지파일을 로드한다.(아직 사용하지 않음)
	* _file_name: 로드할 파일명
	* return bool: 성공시 true, 실패할 경우 false
	*/
	bool Load(wchar_t* _file_name);

	/*
	* 업데이트 함수: 좌표나 데이터등을 변경한다.
	* return bool: 성공시 true, 실패할 경우 false
	*/
	bool Update(float _fElapsedTime);

	/*
	* 드로우 함수: 이미지를 그린다.
	* return bool: 성공시 true, 실패할 경우 false
	*/
	bool Draw(Graphics& g);

	/*
	* 파괴자 함수: 변수를 할당한 것을 해제할 때 쓴다.
	* return bool: 성공시 true, 실패할 경우 false
	*/
	bool Destroy();

	/*
	* 공의 색깔을 얻어오거나 설정한다. 
	*/
	Color GetColor(){ return m_color; }
	void SetColor(Color _color){ m_color = _color;}

	/*
	* 공의 x.y좌표을 얻어오거나 설정한다. 
	*/
	float GetX(){ return m_x; }
	void SetX(float _x){ m_x = _x; }
	float GetY(){ return m_y; }
	void SetY(float _y){ m_y = _y; }

	/*
	* 공의 반지름의 크기를 얻어오거나 설정한다. 
	*/
	float GetRadius(){ return m_radius; }

	/*
	* 현재좌표를 공의크기로 나눈 타일좌표를 얻어오거나 설정한다. 
	*/
	int GetTileX();
	int GetTileY();

	/*
	* 현재 공과 인자로 들어온 공이 서로 충돌했는지 확인한다.
	* return bool: 충돌시 true, 충돌안한 경우 false
	*/
	bool CollisionBall(ImBall* _pBall);

	/* 현재 공이 화면에 보이며 존재하는지 여부
	* return bool: 존재할 경우 true, 존재하지 않을 경우 false
	*/
	bool GetExist(){return m_bExist;}
	void SetExist(bool _bExist){ m_bExist = _bExist; }

	/*
	* 같은 색을 사라지게 만들때, 
	* 이미 확인한 공의 경우 true, 
	* 확인하지 않은 경우 false
	*/
	bool GetCheck(){return m_bCheck;}
	void SetCheck(bool _bCheck){ m_bCheck = _bCheck; }
	/*
	* 장기말(공)의 이름을 설정한다.
	*/
	void SetName(wchar_t* _name);

	/*
	* 장기말의 이름에 해당하는 mp3파일 명을 지정하거나 
	* 얻어온다.
	*/
	void SetSoundName(wchar_t* _sound_name);
	wchar_t* GetSoundName(){ return sound_name; }
	
	/*
	*장기말의 이름으로 된 mp3파일을 연주한다.
	*/
	bool PlaySound();
	
	/*
	* 장기말 이름의 배열 좌표을 설정한다.
	*/
	void SetNameX(int _name_x){m_name_x = _name_x; }
	void SetNameY(int _name_y){m_name_y = _name_y; }
private:
	// 장기말이 회전시킨다.(아직 사용하지 않음)
	bool Rotate();

	float m_x; // 장기말의 x좌표
	float m_y;	// 장기말의 y좌표
	float m_radius; // 장기말의 반지름
	Color m_color; // 장기말의 색
	bool m_bExist; // 장기말의 존재유무
	bool m_bCheck; // 같은 색의 확인유무
	wchar_t name[64]; // 장기말의 이름
	wchar_t sound_name[64]; // 장기말의 사운드 이름
	int m_name_x; // 장기말 이름배열의 x값
	int m_name_y; // 장기말 이름배열의 y값
};