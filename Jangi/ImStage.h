#pragma once

#include "Define.h"

class ImStage
{
public:
	ImStage();
	virtual ~ImStage();

	bool Init();
	bool Load(wchar_t* _file_name);
	bool Update(float _fElapsedTime);
	bool Draw(Graphics& g);
	bool Destroy();
private:
	int m_iStageNo;
}