// ------------------------------------------------------------
//  - 3 / 25 -
// ------------------------------------------------------------
// 동적(REAL-TIME(돌려봐야 알 수 있는)) 할당과 스마트 포인터 -
// RAII -자원의 생명주기를 객체의 생명주기와 일치시키는 프로그래밍 기법
// ------------------------------------------------------------



#INCLUDE <IOSTREAM>
#INCLUDE <FSTREAM>
#INCLUDE <ALGORITHM>

#INCLUDE "SAVE.H"
USING NAMESPACE STD;


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

	/*CHAR C{};
	IN >> NOSKIPWS;
	WHILE (IN>>C) {
		C =TOUPPER(C);
		OUT << C;
	}*/

	TRANSFORM(ISTREAMBUF_ITERATOR<CHAR>{IN}, {},
		OSTREAMBUF_ITERATOR<CHAR>{OUT},
		[](CHAR C) {RETURN TOUPPER(C); });
	

	SAVE("MAIN.CPP");
	
	
}