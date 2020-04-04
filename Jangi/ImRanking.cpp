#include "ImRanking.h"
#include "Define.h"

struct compare_greater
{
    bool operator()(pair<const wchar_t*,int> left, pair<const wchar_t*,int> right) 
	{
        return left.second > right.second;
    }
};

struct compare_less 
{
    bool operator()(pair<const wchar_t*,int> left, pair<const wchar_t*,int> right) 
	{
        return left.second < right.second;
    }
};

ImRanking::ImRanking()
{
	Init();
}

ImRanking::~ImRanking()
{
	Destroy();
}

bool ImRanking::Init()
{
	m_pFile = NULL;
	m_vecRank.clear();	
	
	return true;
}

bool Load(wchar_t* _file_name)
{
	return true;
}
bool Update(float _fElapsedTime)
{
	return true;
}

bool Draw(Graphics& g)
{
	return true;
}

bool ImRanking::Destroy()
{
	for(int i = 0; i < (int)m_vecRank.size(); i++)
	{
		delete m_vecRank[i].first;
	}

	return true;
}

int ImRanking::PushRank(wchar_t* _pName, int _iScore)
{
	wchar_t* pName = new wchar_t[32];
	_tcscpy_s(pName,sizeof(wchar_t),_pName);

	m_vecRank.push_back(pair<wchar_t*,int>(pName,_iScore));
	
	sort(m_vecRank.begin(),m_vecRank.end(),compare_greater());
	
	return true;
}

bool ImRanking::ReadFromFile()
{
	errno_t e;
	e = _wfopen_s(&m_pFile,L"rank.txt",L"r");
	if(e !=0)
	{
		return false;
	}

	while(feof(m_pFile) == 0)
	{
		wchar_t pName[32];
		int iScore = 0;
		fwscanf_s(m_pFile,L"%ls",pName,32);
		fwscanf_s(m_pFile,L"%d",&iScore);
		PushRank(pName,iScore);
	}
	
	fclose(m_pFile);

	return true;
}

bool ImRanking::WriteToFile()
{
	errno_t e;
	e = _wfopen_s(&m_pFile,L"rank.txt",L"w");
	if(e !=0)
	{
		return false;
	}
	
	vector<pair<const wchar_t*,int>>::iterator itr;
	for(itr = m_vecRank.begin(); itr != m_vecRank.end(); itr++)
	{
		wchar_t buff[32] = {0};
		swprintf_s(buff,32,L"%ls %d\n",itr->first,itr->second);
		fwprintf_s(m_pFile,buff);
	}
	
	fclose(m_pFile);

	return true;
}