// ------------------------------------------------------------
//  - 4 / 1 -
// ------------------------------------------------------------
// �߰���� 4/24 ��
// ���� 4/10 ��������
// ---------------------------------------
// callable types - ȣ�� ������ Ÿ��  --> ��� ȣ�� ���� Ÿ���� ��Ÿ�� �� �ִ� function 
// 1. �Լ�
// 2. �Լ� ������
// 3. ���� - �̸����� �Լ� (���α׷��Ӱ� �θ� ���� ���⶧���� �̸��� ����)
// 4. �Լ� ��ü - �Լ�ȣ�⿬���ڸ� �����ε��� Ŭ������ ���� ��ü(function object)
// 5. ����Լ� 
// ------------------------------------------------------------

#include <iostream>
#include<algorithm>
#include <fstream>
#include <array>
#include <ranges>
#include <print>

#include "save.h"
using namespace std;

class Dog {
public:
	void show() {
		println("{:10} - {:8}", num, name);
	}

	bool operator<(const Dog& other) const {
		return (name.length() < other.name.length());
	}

private:
	string name;  //3~50���� ������ ���� �ҹ���
	int num;   // ���� int ��

	friend ostream& operator<< (ostream& os, const Dog& dog) {
		return os << dog.num << " " << dog.name << " ";
	}

	friend istream& operator>> (istream& os, Dog& dog) {
		os >> dog.num;
		os >> dog.name;
		return os ;
	}

};

// ��Ȳ: dog ��ü 10������ ���� "Dog �ʸ�����" �� ����Ͽ���
// ������ ������ ���� ������.
// ofstream out("Dog �ʸ�����");
//�� dog ��ü��
// out>>dog; �� ���� ����Ͽ���

//����: Ʋ������ dog ��ü 10�������� ��ϵǾ���
// ����"Dog �ʸ�����"�� ���� ��� Dog ��ü�� �޸𸮿� �����϶�
//���� ������ ��ü�� ������ ȭ�鿡 ����ϰ� �������� ��°���� �����
//�޸𸮿� ������ Dog ��ü�� name���� ���� ������������ �����϶�
// �տ������� 5000���� ������ ȭ�鿡 ����϶�

array<Dog, 10'0000> a;

//--------
int main()
//--------
{
	ifstream in("Dog �ʸ�����");

	for (Dog & d :a) {
		in >> d;
	}

	sort(a.begin(), a.end(), [](Dog d1, Dog d2) { return d1 < d2; });

	for (Dog d : a | views::take(5000)) {
		d.show();
	}

	save("main.cpp");
}