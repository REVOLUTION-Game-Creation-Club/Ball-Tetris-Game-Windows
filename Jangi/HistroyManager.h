#pragma once

#include "Define.h"

using namespace std;

class HistoryManager
{
public:
	HistoryManager();
	virtual ~HistoryManager();

	void SetRecord(wchar_t* _word);
	wchar_t* GetRecord(int _no);
private:
	map<int,wchar_t*> m_mapHistory;
}