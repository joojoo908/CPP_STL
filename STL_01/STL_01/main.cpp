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
	vector<int> v{ 1,2,3,4,5 };
	////문제: v에서 3을 제거하라
	//
	////문제 : v에서 홀수를 제거하라

	////auto/*vector<int>::iterator*/ new_end = remove(v.begin(), v.end(), [](int n) {return n & 1; }); //프러드킷
	v.erase(remove(v.begin(), v.end(), [](int n) {return n & 1; }), v.end());

	//erase_if(v, [](int n) {return n & 1; });

	for (int num : v) {
		cout << num << endl;
	}
	cout << endl;

	/*
	vector<STRING> v{ "1","22","333","4444","55555" };

	//문제 : v에서 333을 제거하라
	erase(v, "333");

	for (const STRING& s : v) {
		cout << s << endl;
	}*/

	//save("main.cpp");
}
