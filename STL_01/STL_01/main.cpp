//  - 3 / 11 -
//
// ------------------------------------------------------------------
// save ���� �и� / template ���� 
// ------------------------------------------------------------------

/*
	1. char*(���ڿ�) -> ���� �پ string �� ��� -> string_view �� �̿�
	2. T* -> unique_ptr<T> , shard_ptr<T> = ���� �����
	3. T[n] -> array<T,n>

	����: main�� �������� �ʰ� �ǵ���� ����ǰ� ����

	����: c++���� change�� ��� ������ �ϳ� - ans) ���� ->�ҽ��ڵ带 �ڵ�����
	->c++ template �� �ӵ��� �� ��������(���� ����ϰ� �Ƹ��ٿ� ���)


	�Լ� ���� �� �̸��� �����. -> ���Ӹͱ۸� : �����Ϸ��� ��ü������ �Լ��� �̸��� ����� 
		�� �̸��� ���� �Լ��� �����δ� ���� �̸��� �ٸ���


	Generic Programming �� ���� template
*/

#include <iostream>
#include<algorithm>
#include "save.h"

using namespace std;  //�⺻������ ���� �� ��, ������� ���� �Ͽ� ���


//template <class T> ���ø��� ����� ���Ǹ� �и��ϸ� �ʴ´�
//��谡 
template <typename T>
void change(T& Num1, T& Num2) 
{
	T num{ Num1 }; // ���� �����ڴ� ������� �Լ� �̹Ƿ� �����Ϸ��� ���� ���ش� / a=b -> a.operator =(b)����� �Լ�
	Num1 = Num2, Num2 = num;
}

void change(int& Num1, int& Num2)
{
	cout << "�̰� �Ҹ���" << endl;
	int num{ Num1 };
	Num1 = Num2, Num2 = num;
}



class Dog { // Ŭ������ �������� ���� �����ϴ�, Concrete, Abstract(�߻�), 
public:
	Dog() = default;
	Dog(int a) : num(a){}
	/*operator int() { // �̷� �ڵ��� ���� ���� (���װ� �ٲ�� �ִٸ� �����Ϸ��� �� �ڵ����� �ٲپ� ������)
		return num;
	}*/
private:
	int num{};

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) { // ��� �Լ��� �� �� ����. /�� �Լ� �������� ����� ���̴�
		//os << dog.num;
		return os << dog.num;
	}
};

//--------
int main()
//--------
{
	{
		Dog a{ 1 }, b{ 2 };

		change(a, b);

		cout << a << " , " << b << endl; //�ǵ�: 2,1 ���
	}

	{
		int a{ 1 }, b{ 2 };

		change(a, b);

		cout << a << " , " << b << endl; //�ǵ�: 2,1 ���
	}

	save("main.cpp");
}