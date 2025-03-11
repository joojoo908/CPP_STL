//  - 3 / 11 -
//
// ------------------------------------------------------------------
// save 파일 분리 / template 복습 
// ------------------------------------------------------------------

/*
	1. char*(문자열) -> 더욱 뛰어난 string 을 사용 -> string_view 를 이용
	2. T* -> unique_ptr<T> , shard_ptr<T> = 많이 사용함
	3. T[n] -> array<T,n>

	문제: main을 수정하지 않고 의도대로 실행되게 하자
*/

#include <iostream>
#include "save.h"
using namespace std;  //기본적으로 하지 말 것, 팀원들과 상의 하에 사용

class Dog {
private:
	int n;
public:
	Dog(int a) {
		n=a;
	}
	friend std::ostream& operator<<(std::ostream& os, const Dog& point) {
		os << point.n;
		return os;
	}

};

template <typename T>
void change(T& Num1, T& Num2)
{
	T num{ Num1 };
	Num1 = Num2, Num2 = num;
}

//--------
int main()
//--------
{
	{
		Dog a{ 1 }, b{ 2 };

		change(a, b);

		cout << a << " , " << b << endl; //의도: 2,1 출력
	}

	{
		int a{ 1 }, b{ 2 };

		change(a, b);

		cout << a << " , " << b << endl; //의도: 2,1 출력
	}

	//save("main.cpp");
}