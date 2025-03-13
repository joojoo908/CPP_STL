//  - 3 / 11 -
//
// ------------------------------------------------------------------
// 많은 개수의 자료를 처리
// ------------------------------------------------------------------

#include <iostream>
#include<algorithm>  //여기있는 기능을 코딩하면 안된다
#include "save.h"
#include <random>
#include<print>
#include <array> //stl 시퀸스 드라이버 중 하나

using namespace std;  //기본적으로 하지 말 것, 팀원들과 상의 하에 사용

// 문제: 랜덤 int 값 1000개를 메모리에 저장하라  / 출력 데이터는 8칸에 맞춰서
// 저장된 값 중에서 가장 큰 값을 화면에 출력하라

default_random_engine dre{}; // andom_device{}() 생성 후 호출
//mt19937_64 dre{random_device{}()};  //  랜덤한 값 뽑아내기 //{초기값 사용 }
uniform_int_distribution uid{0, 999'9999}; // 게임에서 사용할 일 없음 / 모든 수가 균일하게 나오도록 세팅 //다른 분포를 가지도록 하는것도 가능  //엔진의 결과를 특정한 분포로 가공

//--------
int main()
//--------
{
	// rand()  //0~32768  //과거의 랜덤
	//print("{:>80}", uid(dre)); //출력 하겠다   정력기호 <(왼쪽정렬) ^(캐럿:가운데 정렬) >


	// 안전배열이 나오게 된 이유
	array<int, 1000> a; // int a[1000] 보다 훨신 났다.

	vector<int> numbers;
	for (int i = 0; i < 1000; ++i) {
		a[i] = uid(dre);
		//numbers.push_back(uid(dre));
	}
	//-----------------------------------------
	//헛짓거리
	int max_value = numeric_limits<int>::min();
	for (int num : numbers) {
		if (max_value < num)
			max_value = num;
	}
	cout << max_value << endl;
	//-----------------------------------------
	cout << endl;
	/*for (int num : a) {
		print("{:8}", num);
	}*/

	// auto 가장 큰 값의 위치 = max_element(a.begin(), a.end());
	// *가장큰 값의 위치 =  주소값
	cout << *max_element(a.begin(), a.end()) << endl;

	//save("main.cpp");
}