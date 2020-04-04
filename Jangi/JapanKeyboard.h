#pragma once

class JapanKeyboard
{
public:
	JapanKeyboard();
	virtual ~JapanKeyboard();
	
	bool InputJapanease(wchar_t _wChar);

	wchar_t* a();
	wchar_t* ka();
	wchar_t* ga();
	wchar_t* sa();
	wchar_t* za();
	wchar_t* ta();
	wchar_t* da();
	wchar_t* na();
	wchar_t* ha();
	wchar_t* ma();
	wchar_t* ya();
	wchar_t* ra();
	wchar_t* wa();
	wchar_t* n();

	wchar_t* i();
	wchar_t* ki();
	wchar_t* si();
	wchar_t* zi();
	wchar_t* ni();
	wchar_t* hi();
	wchar_t* mi();
	wchar_t* ri();

	wchar_t* u();
	wchar_t* ku();
	wchar_t* su();
	wchar_t* tsu();
	wchar_t* nu();
	wchar_t* hu();
	wchar_t* mu();
	wchar_t* yu();
	wchar_t* ru();

	wchar_t* e();
	wchar_t* ke();
	wchar_t* se();
	wchar_t* te();
	wchar_t* ne();
	wchar_t* he();
	wchar_t* me();
	wchar_t* re();

	wchar_t* o();
	wchar_t* ko();
	wchar_t* so();
	wchar_t* to();
	wchar_t* no();
	wchar_t* ho();
	wchar_t* mo();
	wchar_t* yo();
	wchar_t* ro();
	wchar_t* wo();

private:
	bool PlaySound();
};