// ------------------------------------------------------------
//  - 4 / 29 -
// ------------------------------------------------------------
// 중간고사(30) 4/24 목
// 과제(30) 4/10 과제설명
// ------------------------------------------------------------
// class STRING - STL 정식 컨테이너처럼 동작하는 자료구조
// 
// STL 컨테이너들이란란 Containers are objects that store other objects.
// 클래스로 만든 객체,다른 오브젝트를 저장할 수 있는 오브젝트
// array<T,N>
// vector<T>	- dynamic(run-time) array , 원소에 엑세스 하는 시간이 O(1)
// deque<T>		
// list<T>		- node 기반 / 아무데서나 insert/delete 동작이 O(1)
// ------------------------------------------------------------

#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <ranges>
#include <algorithm>

#include "STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;           //관찰하고 싶으면 true 로

class Test {
	char x[1000000];
};

int main()
//--------
{
	list<int> cont{ 1,3,5,7,9,2,4,6,8,10 };

	//리스트의 원소를 오름차순으로 정렬 후 출력
	
	//list<int>::iterator beg = cont.begin(); //이터레이터는 반복자,포인터와 유사한 역할
	auto beg = cont.begin();
	++beg; // =beg.operator++();
	for (auto i = beg; i != cont.end(); ++i) {
		cout << *i << endl;
	}
	cout << endl;

	cont.sort();
	//sort(cont);

	for (auto i = cont.begin(); i != cont.end(); ++i) {
		cout << *i << endl;
	}
	
	//save("main.cpp");
}