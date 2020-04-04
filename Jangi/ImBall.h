#pragma once

#include "Define.h"
/*
* ImBall ��⸻
*/
class ImBall
{
public:
	ImBall();

	/*
	* ���������: ��ǥ�� �������� �ʴ´�.(��ǥ�� �������� �����Ѵ�.)
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
	* ���Կ�����: ��ǥ�� �������� �ʴ´�.(��ǥ�� �������� �����Ѵ�.)
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
	* �Ҹ���
	*/
	virtual ~ImBall();
	
	/*
	* �ʱ�ȭ �Լ�: �������� �ʱ�ȭ�Ѵ�./
	*/
	bool Init();
	
	/*
	* �̹��������� �ε��Ѵ�.(���� ������� ����)
	* _file_name: �ε��� ���ϸ�
	* return bool: ������ true, ������ ��� false
	*/
	bool Load(wchar_t* _file_name);

	/*
	* ������Ʈ �Լ�: ��ǥ�� �����͵��� �����Ѵ�.
	* return bool: ������ true, ������ ��� false
	*/
	bool Update(float _fElapsedTime);

	/*
	* ��ο� �Լ�: �̹����� �׸���.
	* return bool: ������ true, ������ ��� false
	*/
	bool Draw(Graphics& g);

	/*
	* �ı��� �Լ�: ������ �Ҵ��� ���� ������ �� ����.
	* return bool: ������ true, ������ ��� false
	*/
	bool Destroy();

	/*
	* ���� ������ �����ų� �����Ѵ�. 
	*/
	Color GetColor(){ return m_color; }
	void SetColor(Color _color){ m_color = _color;}

	/*
	* ���� x.y��ǥ�� �����ų� �����Ѵ�. 
	*/
	float GetX(){ return m_x; }
	void SetX(float _x){ m_x = _x; }
	float GetY(){ return m_y; }
	void SetY(float _y){ m_y = _y; }

	/*
	* ���� �������� ũ�⸦ �����ų� �����Ѵ�. 
	*/
	float GetRadius(){ return m_radius; }

	/*
	* ������ǥ�� ����ũ��� ���� Ÿ����ǥ�� �����ų� �����Ѵ�. 
	*/
	int GetTileX();
	int GetTileY();

	/*
	* ���� ���� ���ڷ� ���� ���� ���� �浹�ߴ��� Ȯ���Ѵ�.
	* return bool: �浹�� true, �浹���� ��� false
	*/
	bool CollisionBall(ImBall* _pBall);

	/* ���� ���� ȭ�鿡 ���̸� �����ϴ��� ����
	* return bool: ������ ��� true, �������� ���� ��� false
	*/
	bool GetExist(){return m_bExist;}
	void SetExist(bool _bExist){ m_bExist = _bExist; }

	/*
	* ���� ���� ������� ���鶧, 
	* �̹� Ȯ���� ���� ��� true, 
	* Ȯ������ ���� ��� false
	*/
	bool GetCheck(){return m_bCheck;}
	void SetCheck(bool _bCheck){ m_bCheck = _bCheck; }
	/*
	* ��⸻(��)�� �̸��� �����Ѵ�.
	*/
	void SetName(wchar_t* _name);

	/*
	* ��⸻�� �̸��� �ش��ϴ� mp3���� ���� �����ϰų� 
	* ���´�.
	*/
	void SetSoundName(wchar_t* _sound_name);
	wchar_t* GetSoundName(){ return sound_name; }
	
	/*
	*��⸻�� �̸����� �� mp3������ �����Ѵ�.
	*/
	bool PlaySound();
	
	/*
	* ��⸻ �̸��� �迭 ��ǥ�� �����Ѵ�.
	*/
	void SetNameX(int _name_x){m_name_x = _name_x; }
	void SetNameY(int _name_y){m_name_y = _name_y; }
private:
	// ��⸻�� ȸ����Ų��.(���� ������� ����)
	bool Rotate();

	float m_x; // ��⸻�� x��ǥ
	float m_y;	// ��⸻�� y��ǥ
	float m_radius; // ��⸻�� ������
	Color m_color; // ��⸻�� ��
	bool m_bExist; // ��⸻�� ��������
	bool m_bCheck; // ���� ���� Ȯ������
	wchar_t name[64]; // ��⸻�� �̸�
	wchar_t sound_name[64]; // ��⸻�� ���� �̸�
	int m_name_x; // ��⸻ �̸��迭�� x��
	int m_name_y; // ��⸻ �̸��迭�� y��
};