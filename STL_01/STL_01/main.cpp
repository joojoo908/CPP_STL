//    3 / 06 

//save기능 작성
// 
// 컴파일환경
// vs 버전 - 17.3.0 이상
//release / x64, c++ 표준 - std::c++latest, stl검사 - 아니오

#include <iostream>
#include <string>
#include "save.h"

//--------
int main()
//--------
{
	std::cout << "2025 stl 시작" << '\n';

	save("main.cpp");
}