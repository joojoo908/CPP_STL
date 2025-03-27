// ------------------------------------------------------------
//  - 3 / 27 -
// ------------------------------------------------------------
// callable type - 
// ------------------------------------------------------------

#include <iostream>
#include <array>
#include <random>
#include <ranges>
//#include <cstdlib>
#include <print>

#include "save.h"
using namespace std;

// 문제 랜덤 int 1000만개를 메모리에 저장하라
// qsort를 이용하여 오름차순 정렬한다
// 정렬결과를 앞에서부터 1000개를 화면 출력하라

default_random_engine dre{};
uniform_int_distribution uid{0,999'9999};

array<int, 1000'0000> a;

int 오름차순(const void* a, const void* b) {
	int* p = (int*)a;
	int* q = (int*)b;
	if (*p > *q)
		return 1;
	else if (*p < *q)
		return -1;
	return 0;
}

//--------
int main()
//--------
{
	for (int& val : a) {
		val = uid(dre);
	}

	int (*정렬기준)(const void* a, const void* b);
	정렬기준 = 오름차순;
	qsort(a.data(), a.size(), sizeof(array<int,a.size()>::value_type), 정렬기준 );

	for (int num : a | views::take(100) ) {  //   | : 버티컬 바    //다양한 필터가 있다
		print("{:8}", num);
	}

	//save("main.cpp");
	
	
}