// ------------------------------------------------------------
//  - 5 / 29 -
// ------------------------------------------------------------
// 6월 19일 목요일 - 15주 2일 - 기말
// ------------------------------------------------------------
// associative container (key 값을 기준으로 항상 정렬하는 컨테이너)
// set / multiset - key==value   --동등성 관계를 이용하여 (< >)유니크함을 판단   /+상등성 관계(==)
// map / multimap - pair<key,value>
// ------------------------------------------------------------


//set 에서 원소의 개수 구하기
		//pair<multiset<STRING>::iterator, auto> pos = ms.equal_range(ss);
		//distance(pos.first,pos.second);
		// auto [s,e] = ms.equal_range(ss); //structured binding
		// distance(s,e);


#include <iostream>

#include <set>
#include <ranges>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>

#include "STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;           //관찰하고 싶으면 true 로

// 문제 : 가장 많이 사용된 단어와 사용 횟수 순서대로 출력하시오
// 

int main()
//--------
{
	ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in)
		return 0;

	
	multiset<STRING> ms{ istream_iterator<STRING>{in},{} };
	cout << ms.size() << endl;

	//for (const STRING& word : ms)cout << word << " ";
	cout << endl;

	
	map<STRING,size_t> m;
	multimap<size_t,STRING,greater<size_t>> m_r;
	
	for (const STRING& word : ms) {
		m[word]++; // 연관배열 - associative array
	}
	
	for (auto [s, i] : m) {
		cout << s << "-" << i << endl;
	}

	for (const auto& [key, value] : m) {
		m_r.insert({ value, key });
	}

	for (auto [i, s] : m_r) {
		cout << s << "-" << i << endl;
	}
  
	//save("main.cpp");
}