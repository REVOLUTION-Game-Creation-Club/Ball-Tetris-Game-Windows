#pragma once

#include "Define.h"

class ImBall;

/*
* �ٱ���
*/
class ImSandBox
{
public:
	/*
	* ����Ŭ����
	*/
	static ImSandBox* GetInstance()
	{
		static ImSandBox g_box;
		return &g_box;
	}

	/*
	* �ʱ�ȭ �Լ�
	*/
	bool Init();
	/*
	* �̹����ε� �Լ�(���� ������� ����)
	*/
	bool Load(wchar_t* _file_name);

	/*
	* ������ ������Ʈ ó�� �Լ�
	*/
	bool Update(float _fElapsedTime);

	/*
	* �̹��� �׸��� �Լ�
	*/
	bool Draw(Graphics& g);

	/*
	* �Ҵ�� ��������� �����ϴ� �Լ�
	*/
	bool Destroy();

	/*
	* ũ�������� ���� ����� �Լ� 
	* ���� ������ �޾Ƽ� ȭ�鿡 ǥ���ϰ� ������Ʈ�Ѵ�.
	*/
	void SetBall(ImBall* _pBall);

	/*
	* �ٱ����� ������ ���´�.
	*/
	RECT GetSize(){ return m_Size; }

	/*
	* �ٱ����� ����, ���ο� ���� ���� ����
	*/
	int GetArrayW(){ return m_array_ball_w;}
	int GetArrayH(){ return m_array_ball_h;}	

	/*
	* ��(��⸻)�� �迭���� ���� ������ ���´�.
	*/
	ImBall* GetBall(int _tile_x, int _tile_y);

	/*
	* �������� ��(NewBall)�� ���´�.
	*/ 
	ImBall* GetNewBall(){ return m_pNewBall; }

	/*
	* ������ ��ġ�� ���� �Ʒ��� �������� �Ѵ�.
	*/
	bool DropBallAll();

	/*
	* ���� ���� 3���̻� �ִٸ� 3���� ���� ������� �Ѵ�.
	* ���������� �������� ������ ���������� ������ ������� �Ѵ�.
	* �Ͼ�������� ���������� ���� ���� �ƴϸ� ���ӵǴ��� ������� �ʴ´�.
	*/
	bool RemoveSameColorBallAll();

	/*
	* �Ʒ����� ������ ���پ� �ö�´�.(���� ������� ����)
	*/
	void UpBallLine();
private: // �����Լ� 
	ImSandBox();
	virtual ~ImSandBox();

	/*
	* h,w: ���� ���� ��ǥ
	* DropBallAll()�� �����Լ� 
	* ������ ��ǥ ������ ���� �Ʒ��� �������� �Ѵ�.
	*/
	bool DropBall(int h, int w);

	/*
	* h, w: ���� ���� ��ǥ
	* RemoveSameColorBallAll()�� �����Լ�
	* SameColorBall()���� ã�� ���� ������
	* ����Ʈ(m_vecSameBalls)�� Ȯ���ؼ� 
	* ���� ������� �Ѵ�.
	*/
	bool RemoveSameColorBall(int h, int w);

	/*
	* h, w: ���� ���� ��ǥ
	* RemoveSameColorBallAll()�� �����Լ�
	* ������ �˻��Ͽ� ���� ���� ��������� ã�´�.
	*/
	int SameColorBall(int h, int w, int count);

	/*
	* �� �迭�� ��ġ�� ������ ǥ���Ѵ�.
	* ����� �뵵�� ���ȴ�.
	*/
	void DebugView(Graphics& g);

	/*
	* ���� �� ����(m_Size)�� ǥ���Ѵ�.
	*/
	void DrawBoxLine(Graphics& g);

	/*
	* ���ο� ���� �׿��� ���� �浹�ߴ��� ���θ�
	* ó���Ѵ�.
	*/
	bool CollisionBall();

	/*
	* ���ο� ���� �Ʒ������� �浹�ߴ��� ���θ�
	* ó���Ѵ�.
	*/
	bool CollisionLine();

	/*
	* ���� �����ο� ���� ���̸� ������ ������.
	* ���� ���� ������� Ȯ���Ѵ�.
	*/
	bool CheckGameEnd();

	/*
	* h,w: �� �迭�� ��ǥ
	* ������ ��(��ź ��)�� ������ 
	* ��ġ ������ ������ ������� �Ѵ�.
	*/
	int BombBall(int h, int w);

	RECT m_Size; // �ٱ����� ������
	ImBall* m_pNewBall; // �������� ��
	ImBall** m_ppBall; // ���� �迭(���� ���� �ְ� �Ⱥ��� ���� ����)
	int m_array_ball_w; // �ٱ��� �ȿ� ���� �ִ� ���� ���� ����
	int m_array_ball_h; // �ٱ��� �ȿ� ���� �ִ� ���� ���� ����
	vector<ImBall*> m_vecSameBalls; // ���� ���� ���� ����Ʈ
	float m_fLimitTime; // ���ѽð��� ������ �Ʒ����� ���� �ö��(���� �������� ����)
	// ���� ������� �� �� ���� 1��. 
	// �������� 3���̻� ���������� 
	// ������� �� ���� ������ ��������� �� 
	int m_iScore; 
};

#define TheSandBox ImSandBox::GetInstance()