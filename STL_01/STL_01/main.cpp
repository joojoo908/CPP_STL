// ------------------------------------------------------------
//  - 4 / 3 -
// ------------------------------------------------------------
// �߰���� 4/24 ��
// ���� 4/10 ��������
// ---------------------------------------
// class STRING - STL ���� �����̳�ó�� �����ϴ� �ڷᱸ��
// ------------------------------------------------------------

/*
oop -> Ư�� Ÿ�������� �ڵ�
generic -> Ÿ�԰� ���þ��� �ڵ�
*/

#include <iostream>
#include <memory>

#include "save.h"
using namespace std;

//ǥ�� std::string �� ������ ������ �ϴ� Ŭ����
class STRING {
public:

	//����Ʈ�� �ݵ�� �ڵ�

	STRING(const char* s) : len{ strlen(s) } {
		p.reset();
		p= make_unique<char[]>(len);
		memcpy(p.get(), s, len);
	}

	STRING(const STRING& other) : len{ other.len } {
		p.reset();
		p = make_unique<char[]>(len);
		memcpy(p.get(), other.p.get(), len);
	};

	//copy assignment operator ������� �����ڸ� �ݵ�� �ڵ�

	size_t size() const { return len; };

private:
	size_t len;
	unique_ptr<char[]> p; //���簡 �ȵǴ� Ŭ����

	friend ostream& operator<<(ostream& os, const STRING& str) {
		for (int i = 0; i < str.len; ++i) {
			os << str.p[i];
		}
		return os;
	}
};



//--------
int main()
//--------
{
	STRING s{ "std::string�� ������ Ŭ����" };

	STRING t = s;

	cout << s << endl;
	cout << t << endl;

	//save("main.cpp");
}