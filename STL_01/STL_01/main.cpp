// ------------------------------------------------------------
//  - 3 / 18 -
// ------------------------------------------------------------
// ���� ������ �ڷḦ ó���ϱ� - ���� �����
//                             - ���̳ʸ� ���� ������ ����� 
// ------------------------------------------------------------

#include <iostream>
#include<random>
#include <print>
#include <fstream>
#include <array>
#include <vector>

#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution<int> uid{ 'a','z' };

class Dog { //class�� ���⼭ ����
public:
	Dog() {
		id = ++sid;
		for (int i = 0; i < 15; ++i) {
			name += uid(dre);
		}
	}

	void show() const {
		println("[{:8}] - {}", id, name); // {} ���̿� ������� �ϸ� ����
	}

private:
	string name;
	int id;

	static int sid; //�������� ��Į(��������) , ������ Ÿ���� �۷ι�(����)
};

int Dog::sid{};

// ���� : dog ��ü 10������ binary ���� �� file "Dog 10������" �� �����Ͽ���
// ������ ������ write�Լ��� ����Ͽ� ��ü �޸� ��ü�� �״�� �����Ͽ���
// ���Ͽ� �ִ� ��ü ��ü�� �޸𸮷� �о�Ͷ�
// naim�� id �� ȭ�鿡 ����϶�



//--------
int main()
//--------
{ // main�� ���⼭ ����


	ifstream in{ "Dog 10������" , ios::binary };

	vector<Dog> v;

	array<Dog, 10'0000 > dogs;
	in.read((char*)dogs.data(), sizeof(Dog) * dogs.size());
	Dog dog;
	while (in.read((char*)&dog, sizeof(dog)))
		v.push_back(dog);
	
	
	//dog ����
	//for (int i = -0; i < 10'0000; ++i) {
	//	Dog dog;
	//	out.write((char*)&dog, sizeof(dog)); //&dog ��巹�� ���� ����
	//}


	for (Dog dog:v) {
		dog.show();
	}
	
	//save("main.cpp");
}