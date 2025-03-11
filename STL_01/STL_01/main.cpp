//  - 3 / 11 -
//
// ------------------------------------------------------------------
// 많은 개수의 자료를 처리
// ------------------------------------------------------------------

#include <iostream>
#include<algorithm>
#include "save.h"
#include <random>

using namespace std;  //기본적으로 하지 말 것, 팀원들과 상의 하에 사용

//문제: 랜덤 int 값 1000개를 화면에 출력하라

mt19937_64 dre;
uniform_int_distribution uid{0, 999'9999};

//--------
int main()
//--------
{
	for (int i = 0; i < 1000; ++i)
		cout << uid(dre) << " ";
	cout << endl;

	//save("main.cpp");
}