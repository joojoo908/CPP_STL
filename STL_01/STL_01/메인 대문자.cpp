// ------------------------------------------------------------
//  - 3 / 25 -
// ------------------------------------------------------------
// ����(REAL-TIME(�������� �� �� �ִ�)) �Ҵ�� ����Ʈ ������ -
// RAII -�ڿ��� �����ֱ⸦ ��ü�� �����ֱ�� ��ġ��Ű�� ���α׷��� ���
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
	DOG() { COUT << "�۸�" << ENDL; }
	~DOG() { COUT << "DEAD" << ENDL; }
};

CLASS ����Ʈ {
	DOG* P;
PUBLIC:
	����Ʈ() {}
	����Ʈ(DOG* P) : P{ P } {}   // RAII �ڿ��� ���� �ֱ⸦ ��ü�� ���� �ֱ�� ��ġ��Ų��
	~����Ʈ() {
		DELETE P;
		COUT << "���ܰ� �߻��ϴ��� ������ü�� �ݵ�� �Ҹ���� �����Ѵ� (STACK UNWINDING)" << ENDL;
		//���� ����ε� - ������ ������ ���鼭 ������� �����͸� �Ҹ��Ų��
	}
};

VOID F() 
{
	//�ڵ鷯�� �����Ҷ��� ����Ѵ� (�ڹٿ� ���� ��쿣 �������� �)
	UNIQUE_PTR<DOG[]> P = MAKE_UNIQUE<DOG[]>(3);  // ǥ�� ����Ʈ ������ = �����Ҵ� -> ������ ����
	
	//���ܹ߻�
	//THROW 123;

	COUT << "�� ������ ��µ��� �ʴ´�" << ENDL;

}



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

	CHAR C{};
	IN >> NOSKIPWS;
	WHILE (IN>>C) {
		IF (ISLOWER(C))
			C =TOUPPER(C);
		OUT << C;
	}

	SAVE("MAIN.CPP");
	
	
}