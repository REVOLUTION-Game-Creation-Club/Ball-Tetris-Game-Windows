#pragma once
#include "Define.h"
#include "ImBall.h"

/*
* ũ����: �ٱ��� ������ �����̴� ��⸻
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
	* �ʱ�ȭ�Լ�
	*/
	bool Init();

	/*
	* �̹������� �ε� �Լ�
	*/
	bool Load(wchar_t* _file_name);

	/*
	* ������ ������Ʈ �Լ�
	*/
	bool Update(float _fElapsedTime);

	/*
	* �̹����� �׸��� �Լ�
	*/
	bool Draw(Graphics& g);

	/*
	* �Ҵ�� ��������� �����ϴ� �Լ�
	*/
	bool Destroy();

	/*
	* ���콺 ��ǥ�� ���� ũ������ ��⸻�� 
	* x���� �������ش�.
	*/
	void SetBallX(float _x);

	/*
	* ũ������ ���� �����Ͽ� �����Ѵ�.
	*/
	ImBall* CloneBall();

	/*
	* ũ������ ���� �̸��� ���� �����ϰ� �������ش�.
	*/
	bool SetRandomBall();

private: // ���� �Լ�
	/*
	* ������
	*/
	ImCrain();

	/*
	* �ı���
	*/
	virtual ~ImCrain();

	/* 
	 * ���� �̸��迭�� �̸� ���� �ִ´�.
	 */
	bool InitBallName();

	wchar_t name[11][5][8]; // ���� �̸� �迭
	wchar_t sound_name[11][5][8];// ���� ���� �迭

	ImBall* m_pBall;
};

#define TheCrain ImCrain::GetInstance()