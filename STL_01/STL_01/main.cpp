// ------------------------------------------------------------
//  - 4 / 8 -
// ------------------------------------------------------------
// �߰����(30) 4/24 ��
// ����(30) 4/10 ��������
// ------------------------------------------------------------
// class STRING - STL ���� �����̳�ó�� �����ϴ� �ڷᱸ��
// ------------------------------------------------------------

/*
oop -> Ư�� Ÿ�������� �ڵ�
generic -> Ÿ�԰� ���þ��� �ڵ�
*/

#include <iostream>
#include<array>
#include <memory>
#include<algorithm>
#include "STRING.h"

#include "save.h"
using namespace std;

extern bool ����;                  //�����ϰ� ������ true ��

//--------
int main()
//--------
{
	array<STRING, 5> a{ "1" ,"333" , "55555" , "22" , "4444" };

	//���� a�� ���� ���� ���� ������������ �����Ͻÿ�

	���� = 1;
	sort(a.begin(), a.end(), [](const STRING& a, const STRING& b) {return a.size() > b.size(); });
	���� = 0;
	for (const STRING& s : a) {
		cout << s << endl;
	}
	
	save("main.cpp");
}