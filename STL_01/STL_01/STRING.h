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
	STRING& operator=(const STRING&);
	STRING(const STRING& other);

	//copy assignment operator ������� �����ڸ� �ݵ�� �ڵ�

	size_t size() const;

private:
	size_t len;
	std::unique_ptr<char[]> p; //���簡 �ȵǴ� Ŭ����
	size_t id;      //���� �� �ο��Ǵ� ������

	static size_t gid;
	friend std::ostream& operator<<(std::ostream& os, const STRING& str);


};

