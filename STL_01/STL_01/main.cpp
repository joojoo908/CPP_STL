// ==================================================================
//  - 3 / 18 -
// ------------------------------------------------------------------
// ����
// ------------------------------------------------------------------

#include <iostream>
#include<algorithm>  //�����ִ� ����� �ڵ��ϸ� �ȵȴ�
#include "save.h"
#include <random>
#include<print>
#include <array> //stl ������ ����̹� �� �ϳ�
#include<ranges> //�ֽ�����

#include<fstream>
//#include<string>

using namespace std;  //�⺻������ ���� �� ��, ������� ���� �Ͽ� ���

default_random_engine dre{}; 
uniform_int_distribution uid{0, 999'9999}; 

// ���� "int 1000��.txt" ���� int �� 1000���� text ���� ��ϵǾ� �ִ�.
//�޸𸮷� �о� �Ͷ�, �о�� ���� ȭ�鿡 ����϶� 

//--------
int main()
//--------
{
	
	array<int, 1000> a{10}; //ù ���� �ʱ�ȭ  //array<int, 1000> a �� int a[1000]�� �޸� �� ����  
	// Ư¡ ��ƴ���� ���������� ���ӵǾ� �ִ�.(continuous (�ð��� ���Ӽ�) ,contiguous (������ ���Ӽ�)) ->stl�� �ʼ�
	a.fill(10); // ��� �� �ʱ�ȭ 

	// ���� �＼�� -> �� �� ������ �ð��� ������ �Ѵ�

	ifstream in{ "int 1000��.txt" };

	copy(istream_iterator<int>{in} /*����Է�(int�� �ƴϰų� ���Ŀ� ���� �ʴ´ٸ� �߰��� �б� ������ ������(��� �Է��� �������� �ƴ�))*/, {}, a.begin());

	/*int i = 0;
	while (in >> a[i++]);*/

	cout << *max_element( a.begin(), a.end() ) <<endl;
	//ǥ�� �ݺ���

	//cout << *max_element(a.begin(), a.end()) << endl; //������ ����
	ranges::sort(a); //�⺻ �������� ���� // �ֽ��� ����
	for (int num : a)
		print("{:8}", num);

	save("main.cpp");
}