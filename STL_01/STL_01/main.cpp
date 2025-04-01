// ------------------------------------------------------------
//  - 4 / 1 -
// ------------------------------------------------------------
// 중간고사 4/24 목
// 과제 4/10 과제설명
// ---------------------------------------
// callable types - 호출 가능한 타입  --> 모든 호출 가능 타입을 나타낼 수 있는 function 
// 1. 함수
// 2. 함수 포인터
// 3. 람다 - 이름없는 함수 (프로그래머가 부를 일이 없기때문에 이름이 없다)
// 4. 함수 객체 - 함수호출연산자를 오버로딩한 클래스로 만든 객체(function object)
// 5. 멤버함수 
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
	string name;  //3~50글자 사이의 랜덤 소문자
	int num;   // 랜덤 int 값

	friend ostream& operator<< (ostream& os, const Dog& dog) {
		return os << dog.num << " " << dog.name << " ";
	}

	friend istream& operator>> (istream& os, Dog& dog) {
		os >> dog.num;
		os >> dog.name;
		return os ;
	}

};

// 상황: dog 객체 10만개를 파일 "Dog 십만마리" 에 기록하였다
// 파일은 다음과 같이 열었다.
// ofstream out("Dog 십만마리");
//각 dog 객체는
// out>>dog; 와 같이 기록하였다

//문제: 틀림없이 dog 객체 10만마리가 기록되었다
// 파일"Dog 십만마리"를 열어 모든 Dog 객체를 메모리에 저장하라
//제일 마지막 객체의 정보를 화면에 출력하고 답지에도 출력결과를 적어라
//메모리에 저장한 Dog 객체르 name길이 기준 오름차순으로 정렬하라
// 앞에서부터 5000개의 정보를 화면에 출력하라

array<Dog, 10'0000> a;

//--------
int main()
//--------
{
	ifstream in("Dog 십만마리");

	for (Dog & d :a) {
		in >> d;
	}

	sort(a.begin(), a.end(), [](Dog d1, Dog d2) { return d1 < d2; });

	for (Dog d : a | views::take(5000)) {
		d.show();
	}

	save("main.cpp");
}