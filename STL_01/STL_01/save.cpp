#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <chrono> 
//#include <string>

#include "save.h"

void save(std::string_view fileName) {

	std::ifstream in{ fileName.data() }; //���Ͽ���
	if (not in) {
		std::cout << fileName << "�� �� �� �����ϴ�" << std::endl;
		exit(2025);
	}


	std::string WriteFile{ "2025 1�б� STL 5���� ��������.txt" };
	std::ofstream out{ WriteFile , std::ios::app }; //�˻� �ʿ�x , ������ ������ �� �ڵ����� ���� ����

	std::cout << WriteFile << " �� " << fileName << " - " 
		<< std::filesystem::file_size(fileName) << " ����Ʈ�� �����߽��ϴ�." << std::endl;

	//����ð� ���Ͽ� ���
	auto now = std::chrono::system_clock::now(); //time_point�� ��´�

	auto utc = std::chrono::system_clock::to_time_t(now); //utc�ð����� �����Ѵ�
	auto lt = std::localtime(&utc);  //�����ð����� ����
	auto old = out.imbue(std::locale("ko_KR"));  //out������ �ѱ�����
	out << '\n' << '\n';
	out << "======================================" << '\n';
	out << "������ �ð�: " << std::put_time(lt, "%c %A") << '\n';
	out << "======================================" << '\n';
	out << '\n';
	out.imbue(old);

	std::copy(std::istreambuf_iterator{ in }, {}, std::ostreambuf_iterator{ out }); //ȿ���� ���ٷ� ó�� ����

}