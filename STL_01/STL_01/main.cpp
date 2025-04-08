// ------------------------------------------------------------
//  - 4 / 8 -
// ------------------------------------------------------------
// 중간고사(30) 4/24 목
// 과제(30) 4/10 과제설명
// ------------------------------------------------------------
// class STRING - STL 정식 컨테이너처럼 동작하는 자료구조
// ------------------------------------------------------------

/*
oop -> 특정 타입을위한 코딩
generic -> 타입과 관련없는 코딩
*/

#include <iostream>
#include <memory>
#include "STRING.h"

#include "save.h"
using namespace std;

extern bool 관찰;                  //관찰하고 싶으면 true 로

STRING s{ "이제 준비가 되었다" };
//--------
int main()
//--------
{
	관찰 = true;
	cout << "메인시작" << endl;

	new STRING{"1234567"};

	STRING t;

	t = s;

	cout << "메인 끝" << endl;

	

	save("main.cpp");
}