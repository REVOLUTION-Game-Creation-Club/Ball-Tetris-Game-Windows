#pragma once

#include "Define.h"
/*
* 색깔처리 클래스
*/
class ImColor
{
public:
	ImColor();
	virtual ~ImColor();
	static ImColor* GetInstance()
	{
		static ImColor g_color;
		return &g_color;
	}

	/*
	* 9가지 색깔 중 랜덤하게 색을 얻어온다.
	* Color : 색깔클래스
	*/
	Color GetRandomColor();

	/*
	* 색깔의 인덱스를 넣으면 컬러를 얻는다.
	* idx: 0에서 9까지의 숫자를 넣는다.
	*/
	Color GetIndexColor(int idx);
};

#define TheColor ImColor::GetInstance()