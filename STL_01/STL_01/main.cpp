// ------------------------------------------------------------
//  - 4 / 17 -
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

#include "STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;           //관찰하고 싶으면 true 로

//벡터가 어떻게 free-store 메모리를 관리하는지  알아본다 
//--------
int main()
//--------
{
	관찰 = 1;
	vector<STRING> v;
	v.emplace_back("1"); //벡터에서 자체적으로 생성
	v.emplace_back(STRING{"123"}); //이렇게 쓰지 마라
		
	관찰 = 0;
	
	save("main.cpp");
}