// ------------------------------------------------------------
//  - 4 / 15 -
// ------------------------------------------------------------
// 중간고사(30) 4/24 목
// 과제(30) 4/10 과제설명
// ------------------------------------------------------------
// class STRING - STL 정식 컨테이너처럼 동작하는 자료구조
// 
// STL 컨테이너들이란란 Containers are objects that store other objects.
// 클래스로 만든 객체,다른 오브젝트를 저장할 수 있는 오브젝트
// array<T,N>
// ------------------------------------------------------------

#include <iostream>
#include<vector>
#include<array>

#include "STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;           //관찰하고 싶으면 true 로

vector<int> v{ 1,2,3 };

//--------
int main()
//--------
{

	/*vector<int>* v = new vector<int>{ 1,2,3 }; //프리스토어
	cout << "v의 크기 - " << sizeof *v << endl;
	cout << "v의 주소 - " << addressof( *v) << endl;
	cout << "v의 타입 - " << typeid(*v).name() << endl;*/

	vector<int> v { 1, 2, 3 };

	v.push_back(4);

	for (int num : v) {
		cout << num << endl;
	}
	

	save("main.cpp");
	//save("STRING.cpp");
}