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
#include <algorithm>
#include <chrono>

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
	
	std::cout << fileName << "-" << std::filesystem::file_size(fileName) << "바이트를 저장했습니다." << std::endl;


	std::ofstream out{ "2025 1학기 STL 강의저장.txt" , std::ios::app }; //검사 필요x , 파일이 깨졌을 때 자동으로 새로 만듬

	//저장시간 파일에 기록
	auto now = std::chrono::system_clock::now(); //time_point를 얻는다
	/*using namespace std::chrono_literals;
	std::cout << now+ 9h << std::endl;*/

	auto utc = std::chrono::system_clock::to_time_t(now); //utc시간으로 변경한다
	auto lt = std::localtime(&utc);  //지역시간으로 변경
	auto old = out.imbue(std::locale("ko_KR"));  //out지역을 한국으로

	out << '\n' << '\n';
	out << "======================================" << '\n';
	out << "저장한 시간: " << std::put_time(lt, "%c %A") << '\n';
	out << "======================================" << '\n';
	out << '\n';

	out.imbue(old);
	std::copy(std::istreambuf_iterator{ in }, {}, std::ostreambuf_iterator{ out }); //효율적 한줄로 처리 가능
	


}