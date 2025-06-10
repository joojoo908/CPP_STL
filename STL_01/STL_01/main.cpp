// ------------------------------------------------------------
//  - 6 / 10 -
// ------------------------------------------------------------
// 6월 19일 목요일 - 15주 2일 - 기말
// ------------------------------------------------------------
// 컨테이너의 찾기 실력을 비교/평가해 본다. N (1000만개)
// 1.vector
// 2.set
// 3.unordered_set
// ------------------------------------------------------------


#include <iostream>

#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <chrono>
#include <random>

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

//천만개의 랜덤 int 를 준비한다
//만개의 찾을 random int를 따로 준비한다

default_random_engine dre;
uniform_int_distribution uid{ 1,1000'0000 };

const int NUM{ 1000'0000 };
const int FNUM{ 1'0000 };
array<int, NUM>   a; //컨테이너의 데이터
array<int, FNUM> fa; //찾아볼 데이터



int main()
//--------
{
	//save("main.cpp");

	for (int& n :  a)n = uid(dre);
	for (int& n : fa)n = uid(dre);

	{
		cout << "vector에서 찾기" << endl;
		vector<int>v(a.begin(),a.end());
		cout << "벡터의 원소 수" << v.size() << endl;

		size_t cnt{};
		cout << "찾는중 ...";
		auto startTime = chrono::steady_clock::now();
		for (int num : fa) {
			auto p = find(v.begin(), v.end(), num);
			if (p != v.end())cnt++;
		}
		auto endTime = chrono::steady_clock::now() - startTime;
		cout << endl;
		cout << "경과시간 -" << chrono::duration_cast<chrono::microseconds>(endTime) << endl;//14518675us
		cout << "찾은갯수 -" << cnt << endl; //6290
	}
	cout << endl;
	{
		cout << "multiset에서 찾기" << endl;
		cout << "데이터를 set에 넣는 중...";
		multiset<int>ms(a.begin(), a.end());
		cout << endl;
		cout << "multi셋의 원소 수" << ms.size() << endl;

		size_t cnt{};
		cout << "찾는중 ...";
		auto startTime = chrono::steady_clock::now();
		for (int num : fa) {
			if (ms.contains(num))cnt++;
		}
		auto endTime = chrono::steady_clock::now() - startTime;
		cout << endl;
		cout << "경과시간 -" << chrono::duration_cast<chrono::microseconds>(endTime) << endl;//22875us
		cout << "찾은갯수 -" << cnt << endl; //6290
	}
	cout << endl;
	{
		cout << "unordered_multiset에서 찾기" << endl;
		cout << "데이터를 set에 넣는 중...";
		unordered_multiset<int>ums(a.begin(), a.end());
		cout << endl;
		cout << "unordered_multi셋의 원소 수" << ums.size() << endl;

		size_t cnt{};
		cout << "찾는중 ...";
		auto startTime = chrono::steady_clock::now();
		for (int num : fa) {
			if (ums.contains(num))cnt++;
		}
		auto endTime = chrono::steady_clock::now() - startTime;
		cout << endl;
		cout << "경과시간 -" << chrono::duration_cast<chrono::microseconds>(endTime) << endl;//791us
		cout << "찾은갯수 -" << cnt << endl; //6290
	}
}