// ------------------------------------------------------------
//  - 6 / 05 -
// ------------------------------------------------------------
// 6월 19일 목요일 - 15주 2일 - 기말
// ------------------------------------------------------------
// associative container (key 값을 기준으로 항상 정렬하는 컨테이너)
// set / multiset - key==value   --동등성 관계를 이용하여 (< >)유니크함을 판단   /+상등성 관계(==)
// map / multimap - pair<key,value>
// 
// Unordered Associative container - Hash 구조
// ------------------------------------------------------------


//set 에서 원소의 개수 구하기
		//pair<multiset<STRING>::iterator, auto> pos = ms.equal_range(ss);
		//distance(pos.first,pos.second);
		// auto [s,e] = ms.equal_range(ss); //structured binding
		// distance(s,e);


#include <iostream>

#include <unordered_set>
#include <string>
#include <print>

#include "STRING.h"
#include "save.h"
using namespace std;


extern bool 관찰;           //관찰하고 싶으면 true 로

template<>
struct hash<STRING> {
	size_t operator()(const STRING& s) const {
		//이미 잘 정의되어 있는 타입으로 바꿔 hash 값을 결정하면 된다.
		//STRING을 std::string으로 바꾸면 가능
		std::string str(s.begin(), s.end());
		return hash<string>{}(str);
	}
};


int main()
//--------
{
	unordered_set<STRING, std::hash<STRING> > us = { "1","22","333","4444" };

	while (1) {
		
		//언오더드 셋의 메모리를 그대로 화면 출력한다
		for (size_t i = 0; i < us.bucket_count(); ++i) {
			print("[{:>3}] - ", i);
			for (auto bi = us.begin(i); bi != us.end(i); ++bi) {
				cout << " - " << *bi;
			}
			cout << endl;
		}

		cout << "추가할 string을 입력하시오";
		STRING s;
		cin >> s;
		us.insert(s);

	}

	
	//save("main.cpp");
}