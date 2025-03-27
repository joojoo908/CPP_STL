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

// ���� ���� int 1000������ �޸𸮿� �����϶�
// qsort�� �̿��Ͽ� �������� �����Ѵ�
// ���İ���� �տ������� 1000���� ȭ�� ����϶�

default_random_engine dre{};
uniform_int_distribution uid{0,999'9999};

array<int, 1000'0000> a;

int ��������(const void* a, const void* b) {
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

	int (*���ı���)(const void* a, const void* b);
	���ı��� = ��������;
	qsort(a.data(), a.size(), sizeof(array<int,a.size()>::value_type), ���ı��� );

	for (int num : a | views::take(100) ) {  //   | : ��Ƽ�� ��    //�پ��� ���Ͱ� �ִ�
		print("{:8}", num);
	}

	//save("main.cpp");
	
	
}