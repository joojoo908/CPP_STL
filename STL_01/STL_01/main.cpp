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

	/*friend ostream& operator<<(std::ostream& os, const Dog& dog) {
		os.write((char*)&dog, sizeof(Dog));
		return os;
	}*/

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		os << dog.id << "  " <<dog.name << endl;
		return os;
	}

	friend std::istream& operator>>(std::istream& os, const Dog& dog) {
		os.read((char*)&dog, sizeof(Dog));
		return os;
	}

};

int Dog::sid{};

// 문제 : dog 객체 10만개를 binary 모드로 연 file "Dog 10만마리" 에 저장하였다
// 출력 연산자 << 를 사용하여 저장하였다 
// 함수는 다음과 같다
/*friend ostream& operator<<(std::ostream& os, const Dog& dog) {
		os.write((char*)&dog, sizeof(Dog));
		return os;
	}*/

//c++ file           I/O
//binary           저수준 (read,write 함수)
//text (0a->0d)    고수준 (>>  ,<<  )  
//파일은 랜덤 억세스가 가능하도록 할 수도 있다 
 
array<Dog, 10'0000 > dogs;

//--------
int main()
//--------
{ // main은 여기서 연다


	ifstream in{ "Dog 10만마리" , ios::binary };

	/*for (int i = 0; i < 10'0000; ++i) {
		Dog dog;
		in << dog;
	}*/

	/*vector<Dog> v;
	Dog dog;
	while (in.read((char*)&dog, sizeof(dog)))
		v.push_back(dog);

	for (Dog dog : v) {
		dog.show();
	}*/

	//한번에 메모리에 읽어오게 하라
	/*Dog dog;
	for (int i = 0; i < 10; ++i) {
		in >> dog;
		cout << dog << endl;
	}*/
	
	in.read((char*)dogs.data(), sizeof(dogs));
	for (const Dog& dog : dogs) {
		cout << dog << endl;
	}

	save("main.cpp");
}