//    3 / 06 

//save기능 작성
// 
// 컴파일환경
// vs 버전 - 17.3.0 이상
//release / x64, c++ 표준 - std::c++latest, stl검사 - 아니오

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

void save(std::string_view); //읽기 전용 

//--------
int main()
//--------
{
	std::cout << "2025 stl 시작" << '\n';

	//void save(const char*); //컴파일은 가능
	save("main.cpp");
}

void save(std::string_view fileName) {

	std::ifstream in{ fileName.data()}; //파일열기
	if ( not in ) {
		std::cout << fileName << "을 열 수 없습니다" << std::endl;
		exit(2025);
	}
	
	auto size = std::filesystem::file_size(fileName);
	std::cout << fileName << "-" << size << "바이트를 저장했습니다." << std::endl;


	std::ofstream out{ "2025 1학기 STL 강의저장.txt" , std::ios::app }; //검사 필요x , 파일이 깨졌을 때 자동으로 새로 만듬

	char c;
	in >> std::noskipws;
	while ( in >> c ) //고급 입출력 ,캐릭터 외를 모두 무시
		out << c;


}