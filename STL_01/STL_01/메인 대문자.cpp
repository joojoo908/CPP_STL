// ------------------------------------------------------------
//  - 3 / 25 -
// ------------------------------------------------------------
// 동적(REAL-TIME(돌려봐야 알 수 있는)) 할당과 스마트 포인터 -
// RAII -자원의 생명주기를 객체의 생명주기와 일치시키는 프로그래밍 기법
// ------------------------------------------------------------



#INCLUDE <IOSTREAM>
#INCLUDE <VECTOR>
#INCLUDE <NUMERIC>
#INCLUDE <MEMORY>
#INCLUDE <FSTREAM>
#INCLUDE <STRING>

#INCLUDE "SAVE.H"
USING NAMESPACE STD;


CLASS DOG {
PUBLIC:
	DOG() { COUT << "멍멍" << ENDL; }
	~DOG() { COUT << "DEAD" << ENDL; }
};

CLASS 스마트 {
	DOG* P;
PUBLIC:
	스마트() {}
	스마트(DOG* P) : P{ P } {}   // RAII 자원의 생명 주기를 객체의 생성 주기와 일치시킨다
	~스마트() {
		DELETE P;
		COUT << "예외가 발생하더라도 지역객체는 반드시 소멸됨을 보장한다 (STACK UNWINDING)" << ENDL;
		//스택 언와인딩 - 스택을 되집어 가면서 만들어진 데이터를 소멸시킨다
	}
};

VOID F() 
{
	//핸들러가 존재할때만 사용한다 (자바와 같은 경우엔 쓰레기차 운영)
	UNIQUE_PTR<DOG[]> P = MAKE_UNIQUE<DOG[]>(3);  // 표준 스마트 포인터 = 동적할당 -> 여러개 생성
	
	//예외발생
	//THROW 123;

	COUT << "이 문장은 출력되지 않는다" << ENDL;

}



//--------
INT MAIN()
//--------
{
	//문제 "MAIN.CPP" 에 있는 소문자를 모두 대문자로 바꾸어 "메인 대문자.CPP"에 저장하라
	IFSTREAM IN{"MAIN.CPP"};
	IF (NOT IN) {
		RETURN 1;
	}
	OFSTREAM OUT{ "메인 대문자.CPP" };

	CHAR C{};
	IN >> NOSKIPWS;
	WHILE (IN>>C) {
		IF (ISLOWER(C))
			C =TOUPPER(C);
		OUT << C;
	}

	SAVE("MAIN.CPP");
	
	
}