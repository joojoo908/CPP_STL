// ------------------------------------------------------------
//  - 3 / 25 -
// ------------------------------------------------------------
// 동적(real-time(돌려봐야 알 수 있는)) 할당과 스마트 포인터 -
// RAII -자원의 생명주기를 객체의 생명주기와 일치시키는 프로그래밍 기법
// ------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <algorithm>

#include "save.h"
using namespace std;


//--------
int main()
//--------
{
	//문제 "main.cpp" 에 있는 소문자를 모두 대문자로 바꾸어 "메인 대문자.cpp"에 저장하라
	ifstream in{"main.cpp"};
	if (not in) {
		return 1;
	}
	ofstream out{ "메인 대문자.cpp" };

	/*char c{};
	in >> noskipws;
	while (in>>c) {
		c = toupper(c);
		out << c;
	}*/

	transform(istreambuf_iterator<char>{in}, {},
		ostreambuf_iterator<char>{out},
		[](char c) {return toupper(c); });
	

	//save("main.cpp");
	
	
}