//  - 3 / 11 -
//
// ------------------------------------------------------------------
// ���� ������ �ڷḦ ó��
// ------------------------------------------------------------------

#include <iostream>
#include<algorithm>
#include "save.h"
#include <random>

using namespace std;  //�⺻������ ���� �� ��, ������� ���� �Ͽ� ���

//����: ���� int �� 1000���� ȭ�鿡 ����϶�

mt19937_64 dre;
uniform_int_distribution uid{0, 999'9999};

//--------
int main()
//--------
{
	for (int i = 0; i < 1000; ++i)
		cout << uid(dre) << " ";
	cout << endl;

	//save("main.cpp");
}