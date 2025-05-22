// ------------------------------------------------------------
//  - 5 / 22 -
// ------------------------------------------------------------
// 6월 19일 목요일 - 15주 2일 - 기말
// ------------------------------------------------------------
// associative container (key 값을 기준으로 항상 정렬하는 컨테이너)
// set / multiset - key==value   --동등성 관계를 이용하여 (< >)유니크함을 판단   /+상등성 관계(==)
// map / multimap - pair<key,value>
// ------------------------------------------------------------

#include <iostream>

#include <set>
#include <ranges>
#include <algorithm>

#include "STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;           //관찰하고 싶으면 true 로

int main()
//--------
{
	//문제 : set<STRING>을 사용하여 키보드의 입력을 모두 저장하라
	// 저장 이후에 컨테이너의 원소를 모두 출력하라
	set<STRING> s{ istream_iterator<STRING>{cin} , {} }; //ctrl +z로 끝

	for (const STRING& str : s)
		cout << str << endl;

	//save("main.cpp");
}