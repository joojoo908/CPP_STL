// ------------------------------------------------------------
//  - 3 / 25 -
// ------------------------------------------------------------
// ����(REAL-TIME(�������� �� �� �ִ�)) �Ҵ�� ����Ʈ ������ -
// RAII -�ڿ��� �����ֱ⸦ ��ü�� �����ֱ�� ��ġ��Ű�� ���α׷��� ���
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
	//���� "MAIN.CPP" �� �ִ� �ҹ��ڸ� ��� �빮�ڷ� �ٲپ� "���� �빮��.CPP"�� �����϶�
	IFSTREAM IN{"MAIN.CPP"};
	IF (NOT IN) {
		RETURN 1;
	}
	OFSTREAM OUT{ "���� �빮��.CPP" };

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