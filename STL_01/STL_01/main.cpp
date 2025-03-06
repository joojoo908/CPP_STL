//    3 / 06 

//save��� �ۼ�
// 
// ������ȯ��
// vs ���� - 17.3.0 �̻�
//release / x64, c++ ǥ�� - std::c++latest, stl�˻� - �ƴϿ�

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <algorithm>
#include <chrono>

void save(std::string_view); //�б� ���� 

//--------
int main()
//--------
{
	std::cout << "2025 stl ����" << '\n';

	//void save(const char*); //�������� ����
	save("main.cpp");
}

void save(std::string_view fileName) {

	std::ifstream in{ fileName.data()}; //���Ͽ���
	if ( not in ) {
		std::cout << fileName << "�� �� �� �����ϴ�" << std::endl;
		exit(2025);
	}
	
	std::cout << fileName << "-" << std::filesystem::file_size(fileName) << "����Ʈ�� �����߽��ϴ�." << std::endl;


	std::ofstream out{ "2025 1�б� STL ��������.txt" , std::ios::app }; //�˻� �ʿ�x , ������ ������ �� �ڵ����� ���� ����

	//����ð� ���Ͽ� ���
	auto now = std::chrono::system_clock::now(); //time_point�� ��´�
	/*using namespace std::chrono_literals;
	std::cout << now+ 9h << std::endl;*/

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