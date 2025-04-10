// ------------------------------------------------------------
//  - 4 / 10 -
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
#include <array>
#include <algorithm>
#include <fstream>
#include "STRING.h"

#include "save.h"
using namespace std;

extern bool 관찰;             //관찰하고 싶으면 true 로

//문제: "main.cpp"에 있는 단어(공백으로 분리된 char의 집합)를 모두 메모리에 저장하라
//단어를 50개만 읽는다
// 단어를 길이기준 오름차순으로 정렬하라
//정렬한 단어를 모두 출력하라

array<STRING, 50 > words;

//--------
int main()
//--------
{
	STRING s;
	//string s;

	//관찰 = 1;
	ifstream in{ "main.cpp" };
	if (not in)
		return 0;

	for (STRING& word : words) {
		in >> word;
	}
	for (const STRING& word : words) {
		cout << word << endl;
	}
	//for (const auto& word : words) cout << word << " (" << word.size() << ")\n";

	/*sort(words.begin(), words.end(), [](const STRING& lhs, const STRING& rhs){
		return lhs.size() < rhs.size(); });*/
	std::sort(words.begin(), words.end());   //기본정렬 -> , 또는 lese{} 이용

	for (const STRING& word : words) {
		cout << word <<endl;
	}

	

	//save("main.cpp");
	//save("STRING.cpp");
}