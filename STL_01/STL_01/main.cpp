// ------------------------------------------------------------
//  - 5 / 20 -
// ------------------------------------------------------------
// 6월 19일 목요일 - 15주 2일 - 기말
// ------------------------------------------------------------
// 반복자를 사용한 알고리즘 함수 작성
// find
// find_if
// copy
// ------------------------------------------------------------

#include <iostream>

#include <algorithm>

#include "STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;           //관찰하고 싶으면 true 로

template<class T, class V>
T my_find(T b, T e, V v) {
	while (b != e) {
		if (*b == v)return b;
		++b;
	}
	return e;
}

template<class T, class Pred>
T my_find_if(T b, T e, Pred callable) {
	for (; b != e; ++b) {
		if (callable(*b))return b;
	}
	return b;
}

template<class T, class D>
void my_copy(T b, T e, D d) {
	while (b != e) {
		*d = *b;
		++b;
		++d;
	}
}


int main()
//--------
{
	STRING s{ "2025 5 20" };
	//문제 : s를 화면에 copy
	my_copy(s.begin(), s.end(), ostream_iterator<char>{cout});

	//save("main.cpp");
}