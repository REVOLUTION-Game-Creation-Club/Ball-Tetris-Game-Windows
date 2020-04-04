#pragma once

#include "Define.h"

/*
* ��ŷó�� Ŭ����
*/
class ImRanking
{
public:
	/*
	* ���� Ŭ����
	*/
	static ImRanking* GetInstance()
	{
		static ImRanking g_ranking;
		return &g_ranking;
	}

	bool Init();
	bool Load(wchar_t* _file_name);
	bool Update(float _fElapsedTime);
	bool Draw(Graphics& g);
	bool Destroy();

	/* 
	* _pName �̸�
	* _iScore ���ھ�
	* ��ŷ������ �Է��Ѵ�.
	*/
	int PushRank(wchar_t* _pName, int _iScore);
	
	/*
	* rank.txt�� �Էµ� �����̸��� ���ھ������� 
	* �޸𸮷� �о���δ�.
	*/
	bool ReadFromFile();

	/*
	* �޸𸮿� �ִ� �����̸��� ���ھ�����(m_vecRank)��
	* ���Ͽ��� ����Ѵ�.
	*/
	bool WriteToFile();

private:
	ImRanking();
	virtual ~ImRanking();

	vector<pair<const wchar_t*,int>> m_vecRank; // ��ŷ ���� 
	FILE* m_pFile; // ���� ������
};

#define TheRank ImRanking::GetInstance()