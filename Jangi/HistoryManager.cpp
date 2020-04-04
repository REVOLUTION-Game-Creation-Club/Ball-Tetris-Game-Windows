#include "HistroyManager.h"

HistoryManager::HistoryManager()
{
	m_mapHistory.clear();
}

HistoryManager::~HistoryManager()
{
	m_mapHistory.clear();
}

void HistoryManager::SetRecord(wchar_t* _word)
{
	int no = m_mapHistory.size();
	m_mapHistory[no] = _word;
}

wchar_t* HistoryManager::GetRecord(int _no)
{
	return m_mapHistory[_no];
}
