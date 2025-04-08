// ------------------------------------------------------------
//  - 4 / 8 -
// ------------------------------------------------------------
// 중간고사(30) 4/24 목
// 과제(30) 4/10 과제설명
// ------------------------------------------------------------
// class STRING - STL 정식 컨테이너처럼 동작하는 자료구조
// ------------------------------------------------------------

/*
oop -> 특정 타입을위한 코딩
generic -> 타입과 관련없는 코딩
*/

#include <iostream>
#include<array>
#include <memory>
#include<algorithm>
#include "STRING.h"

#include "save.h"
using namespace std;

extern bool 관찰;                  //관찰하고 싶으면 true 로

//--------
int main()
//--------
{
	array<STRING, 5> a{ "1" ,"333" , "55555" , "22" , "4444" };

	//문제 a를 글자 길이 기준 오름차순으로 정렬하시오

	관찰 = 1;
	sort(a.begin(), a.end(), [](const STRING& a, const STRING& b) {return a.size() > b.size(); });
	관찰 = 0;
	for (const STRING& s : a) {
		cout << s << endl;
	}
	
	save("main.cpp");
}