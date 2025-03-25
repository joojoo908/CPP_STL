// ------------------------------------------------------------
//  - 3 / 25 -
// ------------------------------------------------------------
// ����(real-time(�������� �� �� �ִ�)) �Ҵ�� ����Ʈ ������ -
// RAII -�ڿ��� �����ֱ⸦ ��ü�� �����ֱ�� ��ġ��Ű�� ���α׷��� ���
// ------------------------------------------------------------



#include <iostream>
#include <vector>
#include <numeric>
#include <memory>
#include <fstream>
#include <string>

#include "save.h"
using namespace std;


class Dog {
public:
	Dog() { cout << "�۸�" << endl; }
	~Dog() { cout << "dead" << endl; }
};

class ����Ʈ {
	Dog* p;
public:
	����Ʈ() {}
	����Ʈ(Dog* p) : p{ p } {}   // RAII �ڿ��� ���� �ֱ⸦ ��ü�� ���� �ֱ�� ��ġ��Ų��
	~����Ʈ() {
		delete p;
		cout << "���ܰ� �߻��ϴ��� ������ü�� �ݵ�� �Ҹ���� �����Ѵ� (stack unwinding)" << endl;
		//���� ����ε� - ������ ������ ���鼭 ������� �����͸� �Ҹ��Ų��
	}
};

void f() 
{
	//�ڵ鷯�� �����Ҷ��� ����Ѵ� (�ڹٿ� ���� ��쿣 �������� �)
	unique_ptr<Dog[]> p = make_unique<Dog[]>(3);  // ǥ�� ����Ʈ ������ = �����Ҵ� -> ������ ����
	
	//���ܹ߻�
	//throw 123;

	cout << "�� ������ ��µ��� �ʴ´�" << endl;

}



//--------
int main()
//--------
{
	//���� "main.cpp" �� �ִ� �ҹ��ڸ� ��� �빮�ڷ� �ٲپ� "���� �빮��.cpp"�� �����϶�
	ifstream in{"main.cpp"};
	if (not in) {
		return 1;
	}
	ofstream out{ "���� �빮��.cpp" };

	char c{};
	in >> noskipws;
	while (in>>c) {
		if (islower(c))
			c =toupper(c);
		out << c;
	}

	save("main.cpp");
	
	
}