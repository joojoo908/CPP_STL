// ------------------------------------------------------------
//  - 3 / 27 -
// ------------------------------------------------------------
// callable types - ȣ�� ������ Ÿ��
// 1. �Լ�
// 2. �Լ� ������
// 3. ���� - �̸����� �Լ� (���α׷��Ӱ� �θ� ���� ���⶧���� �̸��� ����)
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

// ���� ���� int 1000������ �޸𸮿� �����϶�
// stl�� sort�� �̿��Ͽ� �����϶�
// ���İ���� �տ������� 1000���� ȭ�� ����϶�

default_random_engine dre{};
uniform_int_distribution uid{0,999'9999};

array<int, 1000'0000> a;

bool ��������(int a, int b) {
	return a < b;
}

//--------
int main()
//--------
{
	// (*main)(); //�� �´� ǥ���


	{
		for (int& val : a) {
			val = uid(dre);
		}

		auto b = chrono::high_resolution_clock::now(); //�����ġ ����
		sort(a.begin(), a.end(), ��������);
		auto end = chrono::high_resolution_clock::now();//�����ġ ��

		cout << "�ɸ��ð� - " << end - b << endl;
		cout << "�ɸ��ð�(��) - " << chrono::duration_cast<chrono::seconds>(end - b) << endl;
	}

	{
		for (int& val : a) {
			val = uid(dre);
		}

		auto b = chrono::high_resolution_clock::now(); //�����ġ ����
		sort(a.begin(), a.end(), [](int a, int b) {return a < b; }); //����: �̸����� �Լ� 
		auto end = chrono::high_resolution_clock::now(); //�����ġ ��

		cout << "�ɸ��ð� - " << end - b << endl;
		cout << "�ɸ��ð�(��) - " << chrono::duration_cast<chrono::seconds>(end - b) << endl;
	}

	//save("main.cpp");
	
	
}