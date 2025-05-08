// ------------------------------------------------------------
//  - 5 / 08 -
// ------------------------------------------------------------
// 6월 19일 목요일 - 15주 2일 - 기말
// ------------------------------------------------------------
// class STRING - STL 정식 컨테이너처럼 동작하는 자료구조
// 
// STL 컨테이너들이란란 Containers are objects that store other objects.
// 클래스로 만든 객체,다른 오브젝트를 저장할 수 있는 오브젝트
// array<T,N>
// vector<T>	- dynamic(run-time) array , 원소에 엑세스 하는 시간이 O(1)
// deque<T>		
// list<T>		- node 기반 / 아무데서나 insert/delete 동작이 O(1)
// forward_list<T> - [Note 1 : It is intended that forward_list have zero space or time overhead 
//				 relative to a hand-written C-style singly linked list. 
//				Features that would conflict with that goal have been omitted.— end note]
// 
// span - 모든 contiguous 자료구조를 대표하는 자료구조
// function -  모든 callable 을 표현
// ------------------------------------------------------------

#include <iostream>
#include <span>
#include <vector>
#include <deque>
#include <string>

#include "STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;           //관찰하고 싶으면 true 로

//f 는 거꾸로 출력하는 함수
void f(span<char> s)
{
	for (auto i = s.rbegin(); i != s.rend(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
}

int main()
//--------
{
	string s{ "hello world" };
	f(s);
	
	//save("main.cpp");
}