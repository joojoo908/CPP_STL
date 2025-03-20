// ------------------------------------------------------------
//  - 3 / 18 -
// ------------------------------------------------------------
// 많은 개수의 자료를 처리하기 - 파일 입출력
//                             - 바이너리 모드와 저수준 입출력 
// ------------------------------------------------------------

#include <iostream>
#include<random>
#include <print>
#include <fstream>
#include <array>
#include <vector>

#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution<int> uid{ 'a','z' };

class Dog { //class는 여기서 연다
public:
	Dog() {
		id = ++sid;
		for (int i = 0; i < 15; ++i) {
			name += uid(dre);
		}
	}

	void show() const {
		println("[{:8}] - {}", id, name); // {} 사이에 띄워쓰기 하면 터짐
	}

private:
	string name;
	int id;

	static int sid; //엑세스는 로칼(지역변수) , 라이프 타임은 글로벌(전역)
};

int Dog::sid{};

// 문제 : dog 객체 10만개를 binary 모드로 연 file "Dog 10만마리" 에 저장하였다
// 저장은 파일의 write함수를 사용하여 객체 메모리 전체를 그대로 저장하였다
// 파일에 있는 객체 전체를 메모리로 읽어와라
// naim과 id 를 화면에 출력하라



//--------
int main()
//--------
{ // main은 여기서 연다


	ifstream in{ "Dog 10만마리" , ios::binary };

	vector<Dog> v;

	array<Dog, 10'0000 > dogs;
	in.read((char*)dogs.data(), sizeof(Dog) * dogs.size());
	Dog dog;
	while (in.read((char*)&dog, sizeof(dog)))
		v.push_back(dog);
	
	
	//dog 생성
	//for (int i = -0; i < 10'0000; ++i) {
	//	Dog dog;
	//	out.write((char*)&dog, sizeof(dog)); //&dog 어드레스 오브 도그
	//}


	for (Dog dog:v) {
		dog.show();
	}
	
	//save("main.cpp");
}