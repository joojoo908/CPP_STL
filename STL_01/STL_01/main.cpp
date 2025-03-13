//  - 3 / 11 -
//
// ------------------------------------------------------------------
// 많은 개수의 자료를 처리 -file에 저장하고 읽어오기
// ------------------------------------------------------------------

#include <iostream>
#include<algorithm>  //여기있는 기능을 코딩하면 안된다
#include "save.h"
#include <random>
#include<print>
#include <array> //stl 시퀸스 드라이버 중 하나

#include<fstream>
//#include<string>

using namespace std;  //기본적으로 하지 말 것, 팀원들과 상의 하에 사용

// 문제: "int 1000개.txt" 에는 int 값 1000개가 저장되어 있다
// 가장 큰 값을찾아라

default_random_engine dre{}; // andom_device{}() 생성 후 호출
uniform_int_distribution uid{0, 999'9999}; // 게임에서 사용할 일 없음 / 모든 수가 균일하게 나오도록 세팅 //다른 분포를 가지도록 하는것도 가능  //엔진의 결과를 특정한 분포로 가공

//--------
int main()
//--------
{
	// 안전배열이 나오게 된 이유
	array<int, 1000> a; // int a[1000] 보다 훨신 났다.
	vector<int> v;

	ifstream in{ "int 1000개.txt" };

	/*if (not in) {
		std::cout << "int 1000개.txt" << "을 열 수 없습니다" << std::endl;
		exit(2025);
	}

	int num;
	int maxValue{ numeric_limits<int>::min() };
	while (in >> num) { 
		print("{:8}", num); 
		if (maxValue < num) maxValue = num;
	}

	cout << endl;
	cout << maxValue << endl;*/

	cout << *min_element(istream_iterator<int>{in}, {}) << endl;

	//save("main.cpp");
}