// ------------------------------------------------------------
//  - 5 / 22 -
// ------------------------------------------------------------
// 6월 19일 목요일 - 15주 2일 - 기말
// ------------------------------------------------------------
// 반복자를 사용한 알고리즘 함수 작성
// find
// find_if
// copy
// ------------------------------------------------------------

#include <iostream>

#include <vector>
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
		*d = *b; //-> back_inserter는 반복자 어뎁터(써진것은 같지만 실제로는 다른 일을 함 다른 예-역방향 반복자)
		++b;
		++d;
	}
}


int main()
//--------
{
	STRING s{ "1234567890" };
	vector<char> v;
	
	//문제 : s의 내용을 my_copy를 이용해 vector에 옮겨라
	copy(s.begin(), s.end(), back_inserter(v));
	//inserter는 매우 특별한 반복자

	for (char c : v) {
		cout << c;
	}

	save("main.cpp");
}