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
	
	//vector와 deque 이 얼마 만큼 인트를 담을 수 있는지 알아보자

	{
		vector<Test>	v;
		//cout << "촤대개수 - " << v.max_size() << endl;
		try{
			/*while (1) {
				v.emplace_back();
			}*/
		}
		catch (...) {
			cout << "벡터가 담을 수 있는 int 수" << v.size(); // 27310
		}
	}

	{
		deque<Test>	d;
		//cout << "촤대개수 - " << d.max_size() << endl;
		try {
			/*while (1) {
				d.emplace_back();
			}*/
		}
		catch (...) {
			cout << "덱 담을 수 있는 int 수" << d.size(); // 46998
		}
	}
	
	save("main.cpp");
}