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

// ���� ���� int 1000������ �޸𸮿� �����϶�
// stl�� sort�� �̿��Ͽ� �����϶�
// ���İ���� �տ������� 1000���� ȭ�� ����϶�

default_random_engine dre{};
uniform_int_distribution uid{0,999'9999};

array<int, 1000'0000> a;

bool ��������(int a, int b) {
	return a < b;
}

bool ��������(int a, int b) {
	return a > b;
}

//--------
int main()
//--------
{
	// (*main)(); //�� �´� ǥ���

	for (int& val : a) {
		val = uid(dre);
	}


	bool (*���ı���)(int, int) = ��������;
	sort(a.begin(), a.end() , ���ı��� ); 
	//sort(a.end(), a.begin());

	for (int num : a | views::take(100) ) {  //   | : ��Ƽ�� ��    //�پ��� ���Ͱ� �ִ�
		print("{:8}", num);
	}

	//save("main.cpp");
	
	
}