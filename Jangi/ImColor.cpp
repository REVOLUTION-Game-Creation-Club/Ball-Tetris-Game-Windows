#include "ImColor.h"

ImColor::ImColor()
{

}

ImColor::~ImColor()
{

}

Color ImColor::GetRandomColor()
{
	return GetIndexColor(rand()%9);
}

Color ImColor::GetIndexColor(int idx)
{
	Color c; 
	switch(idx)
	{
	case 0:
		c = Color::White;
		break;
	case 1:
		c = Color::Black;
		break;
	case 2:
		c = Color::Red;
		break;
	case 3:
		c = Color::Orange;
		break;
	case 4:
		c = Color::Yellow;
		break;
	case 5:
		c = Color::Green;
		break;
	case 6:
		c = Color::Blue;
		break;
	case 7:
		c = Color::DarkBlue;
		break;
	case 8:
		c = Color::Violet;
		break;
	default:
		break;
	}

	return c;
}