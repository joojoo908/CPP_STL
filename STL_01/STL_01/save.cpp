#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <chrono> 
//#include <string>

#include "save.h"

void save(std::string_view fileName) {

	std::ifstream in{ fileName.data() }; //파일열기
	if (not in) {
		std::cout << fileName << "을 열 수 없습니다" << std::endl;
		exit(2025);
	}


	std::string WriteFile{ "2025 1학기 STL 5주차 강의저장.txt" };
	std::ofstream out{ WriteFile , std::ios::app }; //검사 필요x , 파일이 깨졌을 때 자동으로 새로 만듬

	std::cout << WriteFile << " 에 " << fileName << " - " 
		<< std::filesystem::file_size(fileName) << " 바이트를 저장했습니다." << std::endl;

	//저장시간 파일에 기록
	auto now = std::chrono::system_clock::now(); //time_point를 얻는다

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