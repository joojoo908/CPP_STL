//-----------------------------------------------------
//STRING.h - std::string �� ������ Ŭ����
//           stl�� ������ ��� �鿩�� ���� ����
//                                        2025.4.8
//-----------------------------------------------------

#pragma once

#include <iostream>
#include <memory>

//ǥ�� std::string �� ������ ������ �ϴ� Ŭ����
class STRING {
public:
	
	STRING();                         //2025.4.8
	~STRING();                //���� �ۼ��� �ʿ䰡 ���� �Լ� �ε� ������ ���ؼ� �ڵ��Ͽ���
	STRING(const char* s);

	//��������� �����Ҵ翬����
	STRING(const STRING& other);
	STRING& operator=(const STRING&);

	//�̵������� �̵��Ҵ翬����     //2025.4.8
	STRING(STRING&&);
	STRING& operator=(STRING&&);

	//���� �����ڵ�(relative ops) -�� 6��
	bool operator<(const STRING& rhs) const;   //2025.4.10
	bool operator==(const STRING& rhs) const;   //2025.4.22

	size_t size() const;
	//2025.5.8
	char* begin();
	char* end();

private:
	size_t len;
	std::unique_ptr<char[]> p; //���簡 �ȵǴ� Ŭ����
	size_t id;      //���� �� �ο��Ǵ� ������

	static size_t gid;
	friend std::ostream& operator<<(std::ostream& os, const STRING& str);
	friend std::istream& operator>>(std::istream& in, STRING& str);


};

