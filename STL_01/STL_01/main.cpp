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

	질문: c++에선 change를 몇개나 만들어야 하나 - ans) 무한 ->소스코드를 자동생성
	->c++ template 은 속도가 더 빨라진다(아주 우아하고 아름다운 기능)


	함수 생성 시 이름을 만든다. -> 네임맹글링 : 컴파일러가 자체적으로 함수의 이름을 만든다 
		즉 이름이 같은 함수도 실제로는 서로 이름이 다르다


	Generic Programming 을 위한 template
*/

#include <iostream>
#include<algorithm>
#include "save.h"

using namespace std;  //기본적으로 하지 말 것, 팀원들과 상의 하에 사용


//template <class T> 탬플릿은 선언과 정의를 분리하면 않는다
//기계가 
template <typename T>
void change(T& Num1, T& Num2) 
{
	T num{ Num1 }; // 복사 생성자는 스페셜한 함수 이므로 컴파일럴가 생성 해준다 / a=b -> a.operator =(b)스페셜 함수
	Num1 = Num2, Num2 = num;
}

void change(int& Num1, int& Num2)
{
	cout << "이게 불린다" << endl;
	int num{ Num1 };
	Num1 = Num2, Num2 = num;
}



class Dog { // 클래스는 세가지로 구분 가능하다, Concrete, Abstract(추상), 
public:
	Dog() = default;
	Dog(int a) : num(a){}
	/*operator int() { // 이런 코딩은 하지 마라 (도그가 바뀔수 있다면 컴파일러가 늘 자동으로 바꾸어 버린다)
		return num;
	}*/
private:
	int num{};

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) { // 멤버 함수가 될 수 없다. /이 함수 내에서만 사용할 것이다
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

		cout << a << " , " << b << endl; //의도: 2,1 출력
	}

	{
		int a{ 1 }, b{ 2 };

		change(a, b);

		cout << a << " , " << b << endl; //의도: 2,1 출력
	}

	save("main.cpp");
}