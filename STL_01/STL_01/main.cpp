//  - 3 / 11 -
//
// ------------------------------------------------------------------
// ���� ������ �ڷḦ ó�� -file�� �����ϰ� �о����
// ------------------------------------------------------------------

#include <iostream>
#include<algorithm>  //�����ִ� ����� �ڵ��ϸ� �ȵȴ�
#include "save.h"
#include <random>
#include<print>
#include <array> //stl ������ ����̹� �� �ϳ�

#include<fstream>
//#include<string>

using namespace std;  //�⺻������ ���� �� ��, ������� ���� �Ͽ� ���

// ����: "int 1000��.txt" ���� int �� 1000���� ����Ǿ� �ִ�
// ���� ū ����ã�ƶ�

default_random_engine dre{}; // andom_device{}() ���� �� ȣ��
uniform_int_distribution uid{0, 999'9999}; // ���ӿ��� ����� �� ���� / ��� ���� �����ϰ� �������� ���� //�ٸ� ������ �������� �ϴ°͵� ����  //������ ����� Ư���� ������ ����

//--------
int main()
//--------
{
	// �����迭�� ������ �� ����
	array<int, 1000> a; // int a[1000] ���� �ν� ����.
	vector<int> v;

	ifstream in{ "int 1000��.txt" };

	/*if (not in) {
		std::cout << "int 1000��.txt" << "�� �� �� �����ϴ�" << std::endl;
		exit(2025);
	}

	int num;
	int maxValue{ numeric_limits<int>::min() };
	while (in >> num) { 
		print("{:8}", num); 
		if (maxValue < num) maxValue = num;
	}

	cout << endl;
	cout << maxValue << endl;*/

	cout << *min_element(istream_iterator<int>{in}, {}) << endl;

	//save("main.cpp");
}