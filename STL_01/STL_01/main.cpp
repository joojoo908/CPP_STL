// ------------------------------------------------------------
//  - 3 / 25 -
// ------------------------------------------------------------
// ����(real-time(�������� �� �� �ִ�)) �Ҵ�� ����Ʈ ������ -
// RAII -�ڿ��� �����ֱ⸦ ��ü�� �����ֱ�� ��ġ��Ű�� ���α׷��� ���
// ------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <algorithm>

#include "save.h"
using namespace std;


//--------
int main()
//--------
{
	//���� "main.cpp" �� �ִ� �ҹ��ڸ� ��� �빮�ڷ� �ٲپ� "���� �빮��.cpp"�� �����϶�
	ifstream in{"main.cpp"};
	if (not in) {
		return 1;
	}
	ofstream out{ "���� �빮��.cpp" };

	/*char c{};
	in >> noskipws;
	while (in>>c) {
		c = toupper(c);
		out << c;
	}*/

	transform(istreambuf_iterator<char>{in}, {},
		ostreambuf_iterator<char>{out},
		[](char c) {return toupper(c); });
	

	//save("main.cpp");
	
	
}