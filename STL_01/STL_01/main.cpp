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
// ------------------------------------------------------------

#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <ranges>
#include <algorithm>
#include <fstream>

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
	//문제 : "main.cpp"의 단어를 list에 저장하라
	ifstream in{ "STRING.cpp" };
	if (!in) {
		return 1;
	}
	list<STRING> cont{ istream_iterator<STRING>{in} , {} };
	

	/*for (const STRING& ss : cont) {
		cout << ss << endl;
	}*/
	//문제 : 리스트에 있는 단어 중에서 길이가 5인 것만 화면에 출력하라

	copy_if(cont.begin(), cont.end(), ostream_iterator<STRING>{cout, "\n"}, [](const STRING& s) {return 5 == s.size(); }); //알고리즘은 predicate 으로 조건을 줄 수 있다.

	/*for (const STRING& ss : cont) {
		if(ss.size() == 5)
			cout << ss << endl;
	}*/
	
	//save("main.cpp");
}