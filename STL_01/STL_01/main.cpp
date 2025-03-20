// ------------------------------------------------------------
//  - 3 / 18 -
// ------------------------------------------------------------
// 많은 개수의 자료를 처리하기 - 파일 입출력
//                             - 바이너리 모드와 저수준 입출력 
// ------------------------------------------------------------

#include <iostream>
#include <array>
#include <fstream>
#include <random>

#include "save.h"
using namespace std;

// 문제: 진짜 랜덤 파일에는 int 값 10만개가 있다
// int 10만개 전체를 메모리로 읽어 와라
// binary 모드로 열었고 write 값으로 int 를 기록하였다.
// 가장 큰 값과 작은 값을 찾아 화면에 출력하라

//--------
int main()
//--------
{
	ifstream in{ "진짜 랜덤.txt" ,ios::binary };
	if (not in) return 1213;

	array<int, 10'0000> a;

	/*
	int num;
	size_t cnt{};
	while (in.read((char*)&num, sizeof(int)))
		++cnt;
	cout << cnt << endl;
	*/

	in.read((char*)a.data(), a.size() * sizeof(int));
	//copy(istream_iterator<int>{in} , {}, a.begin());

	/*for (int num : a) {
		cout << num << endl;
	}*/


	//cout << *max_element(istream_iterator<int>{in}, {}) << endl;

	cout << *max_element(a.begin(),a.end()) << endl; // o(n)
	cout << *min_element(a.begin(),a.end()) << endl; // o(n)

	
	auto [min,max] = minmax_element(a.begin(), a.end()); // std::pair
	//구조화된 바인딩
	cout << *min << endl;
	cout << *max << endl;
	//cout << *pos.first << endl;
	//cout << *pos.second << endl;
	//save("main.cpp");
}