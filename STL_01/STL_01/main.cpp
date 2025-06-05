// ------------------------------------------------------------
//  - 6 / 05 -
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
#include <algorithm>
#include <fstream>
#include <map>
#include <random>
#include <array>

#include "STRING.h"
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 0,99'9999 };
normal_distribution nd{ 0.0, 1.0 };

extern bool 관찰;           //관찰하고 싶으면 true 로

array<int, 10'0000> a;

// a의 원소값은 노말한 분포인가?
//a의 값을 10등분 해서 개수를 센 후 출력하라

int main()
//--------
{
  
	for (int& i : a) {
		double d = nd(dre);
		d += 4;
		d *= 12'5000;
		i = (int)d;
	}

	/*for (int i : a) {
		cout << i << " ";
	}*/

	map<int, int> m;

	for (int i : a) {
		m[{i / 5'0000}]++;
	}

	for (auto [i1, i2] : m) {
		cout << i1 << ":" << i2 << endl;
	}

	//save("main.cpp");
}