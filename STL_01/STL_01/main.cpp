// ==================================================================
//  - 3 / 18 -
// ------------------------------------------------------------------
// 정렬
// ------------------------------------------------------------------

#include <iostream>
#include<algorithm>  //여기있는 기능을 코딩하면 안된다
#include "save.h"
#include <random>
#include<print>
#include <array> //stl 시퀸스 드라이버 중 하나
#include<ranges> //최신정렬

#include<fstream>
//#include<string>

using namespace std;  //기본적으로 하지 말 것, 팀원들과 상의 하에 사용

default_random_engine dre{}; 
uniform_int_distribution uid{0, 999'9999}; 

// 파일 "int 1000개.txt" 에는 int 값 1000개가 text 모드로 기록되어 있다.
//메모리로 읽어 와라, 읽어온 값을 화면에 출력하라 

//--------
int main()
//--------
{
	
	array<int, 1000> a{10}; //첫 값만 초기화  //array<int, 1000> a 와 int a[1000]는 메모리 상 같다  
	// 특징 빈틈없이 물리적으로 연속되어 있다.(continuous (시간의 연속성) ,contiguous (공간의 연속성)) ->stl의 필수
	a.fill(10); // 모든 값 초기화 

	// 랜덤 억세싱 -> 둘 다 동일한 시간에 엑세스 한다

	ifstream in{ "int 1000개.txt" };

	copy(istream_iterator<int>{in} /*고급입력(int가 아니거나 형식에 맞지 않는다면 중간에 읽기 동작을 정지함(고급 입력은 좋은것이 아님))*/, {}, a.begin());

	/*int i = 0;
	while (in >> a[i++]);*/

	cout << *max_element( a.begin(), a.end() ) <<endl;
	//표준 반복자

	//cout << *max_element(a.begin(), a.end()) << endl; //과거의 정렬
	ranges::sort(a); //기본 오름차순 정렬 // 최신의 정렬
	for (int num : a)
		print("{:8}", num);

	save("main.cpp");
}