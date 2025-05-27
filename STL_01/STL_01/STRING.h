//-----------------------------------------------------
//STRING.h - std::string �� ������ Ŭ����
//           stl�� ������ ��� �鿩�� ���� ����
//											2025.4.8
// STRING�� �ݺ��� Ÿ���� �����			2025.5.15
// sort�� �䱸�ϴ� ���� �ݺ��� ����			2025.5.20
//-----------------------------------------------------

#pragma once

#include <iostream>
//#include <memory>

class STRING_Reverce_Iterator {
public:
	STRING_Reverce_Iterator(char* p) :p{ p } {};
	//ǥ�� �ݺ��ڰ� ���߾�� �� ����
	// ++, *, ==
	void operator++() { --p; };
	char operator*() const { return *(p - 1); };
	bool operator==(const STRING_Reverce_Iterator& rhs) const {
		return p == rhs.p;
	}
private:
	char* p;
};

class STRING_Iterator {
public:
	//ǥ�� �ݺ��ڰ� �Ƿ��� ���� 5���� Ÿ���� �����Ͽ��� �Ѵ�.
	using iterator_category = std::random_access_iterator_tag;
	using difference_type = std::ptrdiff_t; //�����ͳ����� ����
	using value_type = char;
	using pointer = char*;
	using reference = char&;

	STRING_Iterator(char* p) :p{p}{}
	//void operator++() { ++p; }
	
	STRING_Iterator& operator++() { ++p; return *this; }
	reference operator*() const { return *p; }
	bool operator==(const STRING_Iterator& rhs) const {return p == rhs.p;}
	
	//���� �߰�
	difference_type operator-(const STRING_Iterator& rhs) const { return p - rhs.p; }
	STRING_Iterator& operator--() { --p; return *this; }
	//bool operator<(const STRING_Iterator& rhs) const { return p < rhs.p; }
	//STRING_Iterator& operator+=(difference_type n) { p += n; return *this; }
	STRING_Iterator operator+(difference_type n) const { return STRING_Iterator(p + n); }
	STRING_Iterator operator-(difference_type n) const { return STRING_Iterator(p - n); }

	//�����ݺ��ڰ� �����ϴ� ������ �Ϻθ� �ڵ��Ͽ� sort�� �����ϵ���
	//ifference_type operator-(const STRING_Iterator& rhs) const { return p - rhs.p; }
	//char& operator*() const { return *p; }
	//STRING_Iterator operator--() { return --p; }
	//STRING_Iterator() = default;
	//STRING_Iterator operator+(difference_type n) const { return STRING_Iterator(p + n); }
	//�񱳿����ڴ� 6������ �ִ�. < <= == >= > != , <=>
	std::strong_ordering operator<=>(const STRING_Iterator& rhs) const { return p <=> rhs.p; } //operator==�� �����ϸ� ����
	//std::strong_ordering operator<=>(const STRING_Iterator& rhs) const = default;
	//STRING_Iterator operator-(difference_type n) const { return STRING_Iterator(p - n); }


private:
	char* p{};
};

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
	//STRING& operator+(STRING&);

	//���� �����ڵ�(relative ops) -�� 6��
	bool operator<(const STRING& rhs) const;   //2025.4.10
	bool operator==(const STRING& rhs) const;   //2025.4.22

	size_t size() const;
	//2025.5.15 ����Ÿ���� Ŭ������
	STRING_Iterator begin() const;
	STRING_Iterator end() const;
	//2025.5.13
	STRING_Reverce_Iterator rbegin()const;
	STRING_Reverce_Iterator rend()const;

	/*std::reverse_iterator<char*> rbegin() const;
	std::reverse_iterator<char*> rend() const;*/

private:
	size_t len;
	std::unique_ptr<char[]> p; //���簡 �ȵǴ� Ŭ����
	size_t id;      //���� �� �ο��Ǵ� ������

	static size_t gid;
	friend std::ostream& operator<<(std::ostream& os, const STRING& str);
	friend std::istream& operator>>(std::istream& in, STRING& str);


};


//�������� operator<() �� �⺻ ���Լ����ٸ� , set�� ���Լ��� �̿��Ͽ� ���ҵ��� ���Ļ��¸� �����Ѵ�.
//����� less<>�� �⺻ ���Լ��̴�.
//less�� Ư��ȭ �ؼ� STRING���� ����ȶ�����
//���� �����̳ʰ� �䱸�ϴ� �� �Լ��̴�		2025.5.22
template <>
struct std::less<STRING> { //���ø��� Ư��ȭ
	//������ ��
	bool operator()(const STRING& lhs, const STRING& rhs)const {
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	//less�� ����ϴ� ������ <=>���� �����ڸ� �����ε� ���� �� <�� �������� ���� �� �ֱ� ������
};

