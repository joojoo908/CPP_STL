// ------------------------------------------------------------
//  - 3 / 18 -
// ------------------------------------------------------------
// ���� ������ �ڷḦ ó���ϱ� - ���� �����
//                             - ���̳ʸ� ���� ������ ����� 
// ------------------------------------------------------------

#include <iostream>
#include <array>
#include <fstream>
#include <random>

#include "save.h"
using namespace std;

// ����: ��¥ ���� ���Ͽ��� int �� 10������ �ִ�
// binary ���� ������ write ������ int �� ����Ͽ���.
// ���� ū ���� ���� ���� ã�� ȭ�鿡 ����϶�

//--------
int main()
//--------
{
	ifstream in{ "��¥ ����.txt" ,ios::binary };
	array<int, 10'0000> a;
	copy(istream_iterator<int>{in} , {}, a.begin());

	/*for (int num : a) {
		cout << num << endl;
	}*/


	//cout << *max_element(istream_iterator<int>{in}, {}) << endl;

	cout << *max_element(a.begin(),a.end()) << endl;
	cout << *min_element(a.begin(),a.end()) << endl;

	//save("main.cpp");
}