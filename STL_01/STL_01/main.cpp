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
// int 10���� ��ü�� �޸𸮷� �о� �Ͷ�
// binary ���� ������ write ������ int �� ����Ͽ���.
// ���� ū ���� ���� ���� ã�� ȭ�鿡 ����϶�

//--------
int main()
//--------
{
	ifstream in{ "��¥ ����.txt" ,ios::binary };
	if (not in) return 1213;

	array<int, 10'0000> a;

	/*
	int num;
	size_t cnt{};
	while (in.read((char*)&num, sizeof(int)))
		++cnt;
	cout << cnt << endl;
	*/

	in.read((char*)a.data(), a.size() * sizeof(int));
	//copy(istream_iterator<int>{in} , {}, a.begin());

	/*for (int num : a) {
		cout << num << endl;
	}*/


	//cout << *max_element(istream_iterator<int>{in}, {}) << endl;

	cout << *max_element(a.begin(),a.end()) << endl; // o(n)
	cout << *min_element(a.begin(),a.end()) << endl; // o(n)

	
	auto [min,max] = minmax_element(a.begin(), a.end()); // std::pair
	//����ȭ�� ���ε�
	cout << *min << endl;
	cout << *max << endl;
	//cout << *pos.first << endl;
	//cout << *pos.second << endl;
	//save("main.cpp");
}