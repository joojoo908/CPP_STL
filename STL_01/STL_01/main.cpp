// ------------------------------------------------------------
//  - 3 / 27 -
// ------------------------------------------------------------
// callable type - 
// ------------------------------------------------------------

#include <iostream>
#include <array>
#include <random>
#include <ranges>
#include <algorithm>
#include <print>

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

bool 내림차순(int a, int b) {
	return a > b;
}

//--------
int main()
//--------
{
	// (*main)(); //가 맞는 표기법

	for (int& val : a) {
		val = uid(dre);
	}


	bool (*정렬기준)(int, int) = 오름차순;
	sort(a.begin(), a.end() , 정렬기준 ); 
	//sort(a.end(), a.begin());

	for (int num : a | views::take(100) ) {  //   | : 버티컬 바    //다양한 필터가 있다
		print("{:8}", num);
	}

	//save("main.cpp");
	
	
}