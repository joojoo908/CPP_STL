// ------------------------------------------------------------
//  - 3 / 27 -
// ------------------------------------------------------------
// callable types - 호출 가능한 타입
// 1. 함수
// 2. 함수 포인터
// 3. 람다 - 이름없는 함수 (프로그래머가 부를 일이 없기때문에 이름이 없다)
// ------------------------------------------------------------

#include <iostream>
#include <array>
#include <random>
#include <ranges>
#include <algorithm>
#include <print>
#include <chrono>

#include "save.h"
using namespace std;

// 문제 랜덤 int 1000만개를 메모리에 저장하라
// stl의 sort를 이용하여 정렬하라
// 정렬결과를 앞에서부터 1000개를 화면 출력하라

default_random_engine dre{};
uniform_int_distribution uid{0,999'9999};

array<int, 1000'0000> a;

bool 오름차순(int a, int b) {
	return a < b;
}

//--------
int main()
//--------
{
	// (*main)(); //가 맞는 표기법


	{
		for (int& val : a) {
			val = uid(dre);
		}

		auto b = chrono::high_resolution_clock::now(); //스톱워치 시작
		sort(a.begin(), a.end(), 오름차순);
		auto end = chrono::high_resolution_clock::now();//스톱워치 끝

		cout << "걸린시간 - " << end - b << endl;
		cout << "걸린시간(초) - " << chrono::duration_cast<chrono::seconds>(end - b) << endl;
	}

	{
		for (int& val : a) {
			val = uid(dre);
		}

		auto b = chrono::high_resolution_clock::now(); //스톱워치 시작
		sort(a.begin(), a.end(), [](int a, int b) {return a < b; }); //람다: 이름없는 함수 
		auto end = chrono::high_resolution_clock::now(); //스톱워치 끝

		cout << "걸린시간 - " << end - b << endl;
		cout << "걸린시간(초) - " << chrono::duration_cast<chrono::seconds>(end - b) << endl;
	}

	//save("main.cpp");
	
	
}