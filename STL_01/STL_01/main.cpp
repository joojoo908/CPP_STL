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

// 문제 : 찾는 단어를 포함한 단어가 모두 몇개나 있는지

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

	cout << "셋의 크기 - " << sizeof(s);

	while (true) {
		cout << "찾을단어?";
		STRING ss;
		cin >> ss;
		int i =count_if(s.begin(), s.end(), [ss](const STRING& word) { //[ss] 람다 캡쳐 ,[=]모든걸 가져와라, [&]모든걸 래퍼런스로
			auto p = search(word.begin(), word.end(), ss.begin(), ss.end());
			if (p != word.end()) {
				return true;
			}
			return false;
		});
		cout << i << "개" << endl;
	}



	//save("main.cpp");
}