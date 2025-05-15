// ------------------------------------------------------------
//  - 5 / 15 -
// ------------------------------------------------------------
// 6월 19일 목요일 - 15주 2일 - 기말
// ------------------------------------------------------------
// iterator(반복자) - Iterators are a generalization of pointers // 포인터를 일반화 한것 but 포인터는 아님
//			that allow a C++ program to work with different data structures(for example, containers and ranges) in a uniform manner. 
//			서로 다른 자료구조에 대해 일관된 방식으로 작동하도록
// 
// 표준 반복자가 되고 싶다면 지켜야할 약속들이 있다.
// **, ++, ==
// 제공해야할 타입 5가지
// iterator_category등 5가지
// 
// ------------------------------------------------------------

#include <iostream>

#include <algorithm>

#include "STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;           //관찰하고 싶으면 true 로

int main()
//--------
{
	STRING s{ "2025 5 15" };
	sort(s.begin(), s.end());
	cout << s << endl;


	//save("main.cpp");
}