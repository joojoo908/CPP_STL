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

//이전에는 operator<() 가 기본 비교함수였다면 , set은 비교함수를 이용하여 원소들의 정렬상태를 유지한다.
//현재는 less<>가 기본 비교함수이다.
//less를 특수화 해서 STRING으로 스페셜라이즈



int main()
//--------
{
	set<STRING> s{ "2025년","5월","22일","연관컨테이너", "셋" ,"asdfa" };
	for (const STRING& str : s)
		cout << str << endl;

	//save("main.cpp");
}