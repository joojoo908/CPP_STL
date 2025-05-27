// ------------------------------------------------------------
//  - 5 / 27 -
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
#include <fstream>
#include <vector>

#include "STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;           //관찰하고 싶으면 true 로

// 문제 : 찾는 단어가 있는지

int main()
//--------
{
	ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in)
		return 0;

	
	vector<STRING> v;
	v.reserve(10000);

	STRING str;
	int i{ 0 };
	while (in >> str) {
		v.push_back(str);
	}
	cout << v.size() << endl;

	set<STRING> s{ v.begin(), v.end() };
	
	for (const STRING& str : s)
		cout << str << endl;
	cout << s.size() << endl;

	while (true) {
		cout << "찾을단어?";
		STRING ss;
		cin >> ss;
		auto f = find(s.begin(), s.end(), ss);
		cout << *f << endl;

	}

	//save("main.cpp");
}