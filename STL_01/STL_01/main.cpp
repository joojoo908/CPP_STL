// ------------------------------------------------------------
//  - 4 / 10 -
// ------------------------------------------------------------
// �߰����(30) 4/24 ��
// ����(30) 4/10 ��������
// ------------------------------------------------------------
// class STRING - STL ���� �����̳�ó�� �����ϴ� �ڷᱸ��
// ------------------------------------------------------------

/*
oop -> Ư�� Ÿ�������� �ڵ�
generic -> Ÿ�԰� ���þ��� �ڵ�
*/

#include <iostream>
#include <array>
#include <algorithm>
#include <fstream>
#include "STRING.h"

#include "save.h"
using namespace std;

extern bool ����;             //�����ϰ� ������ true ��

//����: "main.cpp"�� �ִ� �ܾ�(�������� �и��� char�� ����)�� ��� �޸𸮿� �����϶�
//�ܾ 50���� �д´�
// �ܾ ���̱��� ������������ �����϶�
//������ �ܾ ��� ����϶�

array<STRING, 50 > words;

//--------
int main()
//--------
{
	STRING s;
	//string s;

	//���� = 1;
	ifstream in{ "main.cpp" };
	if (not in)
		return 0;

	for (STRING& word : words) {
		in >> word;
	}
	for (const STRING& word : words) {
		cout << word << endl;
	}
	//for (const auto& word : words) cout << word << " (" << word.size() << ")\n";

	/*sort(words.begin(), words.end(), [](const STRING& lhs, const STRING& rhs){
		return lhs.size() < rhs.size(); });*/
	std::sort(words.begin(), words.end());   //�⺻���� -> , �Ǵ� lese{} �̿�

	for (const STRING& word : words) {
		cout << word <<endl;
	}

	

	//save("main.cpp");
	//save("STRING.cpp");
}