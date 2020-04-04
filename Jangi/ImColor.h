#pragma once

#include "Define.h"
/*
* ����ó�� Ŭ����
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
	* 9���� ���� �� �����ϰ� ���� ���´�.
	* Color : ����Ŭ����
	*/
	Color GetRandomColor();

	/*
	* ������ �ε����� ������ �÷��� ��´�.
	* idx: 0���� 9������ ���ڸ� �ִ´�.
	*/
	Color GetIndexColor(int idx);
};

#define TheColor ImColor::GetInstance()