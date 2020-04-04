#pragma once

#include "Define.h"

/*
* 랭킹처리 클래스
*/
class ImRanking
{
public:
	/*
	* 전역 클래스
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
	* _pName 이름
	* _iScore 스코어
	* 랭킹정보를 입력한다.
	*/
	int PushRank(wchar_t* _pName, int _iScore);
	
	/*
	* rank.txt에 입력된 유저이름과 스코어정보를 
	* 메모리로 읽어들인다.
	*/
	bool ReadFromFile();

	/*
	* 메모리에 있는 유저이름과 스코어정보(m_vecRank)를
	* 파일에다 기록한다.
	*/
	bool WriteToFile();

private:
	ImRanking();
	virtual ~ImRanking();

	vector<pair<const wchar_t*,int>> m_vecRank; // 랭킹 정보 
	FILE* m_pFile; // 파일 포인터
};

#define TheRank ImRanking::GetInstance()