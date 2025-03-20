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

	/*friend ostream& operator<<(std::ostream& os, const Dog& dog) {
		os.write((char*)&dog, sizeof(Dog));
		return os;
	}*/

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		os << dog.id << "  " <<dog.name << endl;
		return os;
	}

	friend std::istream& operator>>(std::istream& os, const Dog& dog) {
		os.read((char*)&dog, sizeof(Dog));
		return os;
	}

};

int Dog::sid{};

// ���� : dog ��ü 10������ binary ���� �� file "Dog 10������" �� �����Ͽ���
// ��� ������ << �� ����Ͽ� �����Ͽ��� 
// �Լ��� ������ ����
/*friend ostream& operator<<(std::ostream& os, const Dog& dog) {
		os.write((char*)&dog, sizeof(Dog));
		return os;
	}*/

//c++ file           I/O
//binary           ������ (read,write �Լ�)
//text (0a->0d)    ����� (>>  ,<<  )  
//������ ���� �＼���� �����ϵ��� �� ���� �ִ� 
 
array<Dog, 10'0000 > dogs;

//--------
int main()
//--------
{ // main�� ���⼭ ����


	ifstream in{ "Dog 10������" , ios::binary };

	/*for (int i = 0; i < 10'0000; ++i) {
		Dog dog;
		in << dog;
	}*/

	/*vector<Dog> v;
	Dog dog;
	while (in.read((char*)&dog, sizeof(dog)))
		v.push_back(dog);

	for (Dog dog : v) {
		dog.show();
	}*/

	//�ѹ��� �޸𸮿� �о���� �϶�
	/*Dog dog;
	for (int i = 0; i < 10; ++i) {
		in >> dog;
		cout << dog << endl;
	}*/
	
	in.read((char*)dogs.data(), sizeof(dogs));
	for (const Dog& dog : dogs) {
		cout << dog << endl;
	}

	save("main.cpp");
}