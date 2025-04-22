// ------------------------------------------------------------
//  - 4 / 22 -
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
#include <list>
#include<algorithm>

#include "STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;           //관찰하고 싶으면 true 로

//벡터가 어떻게 free-store 메모리를 관리하는지  알아본다 
//--------
int main()
//--------
{
	/*
	vector<STRING> v;
	v.reserve(10);
	v.emplace_back("1");
	v.emplace_back("22");
	v.emplace_back("4444");
	v.emplace_back("55555");
	//v.assign({ "1","22","4444","55555" });

	// 문제 v의 22와  4444 사이에 333을 삽입하라
	관찰 = 1;
	v.insert(v.begin() + 2, "333"); //제공하지만 절대하면 안됨
	v.emplace(v.begin() + 2, "333"); //아까보단 나음
	관찰 = 0;
	*/
	
	
	list<STRING> v{ "1","22","333","4444","55555" };
	//리스트는 공간예약이 필요없다

	
	//문제 : v에서 333을 제거하라
	v.remove("333");
	//v.erase(remove(v.begin(),v.end(),"333"),v.end()); //리스트에서는 이러면 안된다

	관찰 = 1;
	v.emplace(++++v.begin(), "333");
	관찰 = 0;

	for (const STRING& s : v) {
		cout << s << endl;
	}

	//save("main.cpp");
}
