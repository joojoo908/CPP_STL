// ------------------------------------------------------------
//  - 4 / 3 -
// ------------------------------------------------------------
// 중간고사 4/24 목
// 과제 4/10 과제설명
// ---------------------------------------
// class STRING - STL 정식 컨테이너처럼 동작하는 자료구조
// ------------------------------------------------------------

/*
oop -> 특정 타입을위한 코딩
generic -> 타입과 관련없는 코딩
*/

#include <iostream>
#include <memory>

#include "save.h"
using namespace std;

//표준 std::string 과 유사한 동작을 하는 클래스
class STRING {
public:

	//디폴트를 반드시 코딩

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

	//copy assignment operator 복사생산 연산자를 반드시 코딩

	size_t size() const { return len; };

private:
	size_t len;
	unique_ptr<char[]> p; //복사가 안되는 클래스

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
	STRING s{ "std::string과 유사한 클래스" };

	STRING t = s;

	cout << s << endl;
	cout << t << endl;

	//save("main.cpp");
}