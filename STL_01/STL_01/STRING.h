//-----------------------------------------------------
//STRING.h - std::string 과 유사한 클래스
//           stl의 동작을 깊게 들여다 보기 위해
//											2025.4.8
// STRING의 반복자 타입을 만든다			2025.5.15
//-----------------------------------------------------

#pragma once

#include <iostream>
#include <memory>

class STRING_Reverce_Iterator {
public:
	STRING_Reverce_Iterator(char* p) :p{ p } {};
	//표준 반복자가 갖추어야 할 동작
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
	//표준 반복자가 되려면 다음 5가지 타입을 정의하여야 한다.
	using iterator_category = std::random_access_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = char;
	using pointer = char*;
	using reference = char&;

	STRING_Iterator(char* p) :p{p}{}
	//void operator++() { ++p; }
	
	STRING_Iterator& operator++() { ++p; return *this; }
	STRING_Iterator& operator--() { --p; return *this; }
	//STRING_Iterator operator++(int) { STRING_Iterator tmp = *this; ++p; return tmp; }
	reference operator*() const { return *p; }

	bool operator==(const STRING_Iterator& rhs) const {return p == rhs.p;}
	//bool operator!=(const STRING_Iterator& rhs) const { return p != rhs.p; }
	
	bool operator<(const STRING_Iterator& rhs) const { return p < rhs.p; }

	//STRING_Iterator& operator+=(difference_type n) { p += n; return *this; }
	STRING_Iterator operator+(difference_type n) const { return STRING_Iterator(p + n); }
	STRING_Iterator operator-(difference_type n) const { return STRING_Iterator(p - n); }
	difference_type operator-(const STRING_Iterator& rhs) const { return p - rhs.p; }

private:
	char* p;
};

//표준 std::string 과 유사한 동작을 하는 클래스
class STRING {
public:
	
	STRING();                         //2025.4.8
	~STRING();                //전혀 작성할 필요가 없는 함수 인데 관찰을 위해서 코딩하였다
	STRING(const char* s);

	//복사생성과 복사할당연산자
	STRING(const STRING& other);
	STRING& operator=(const STRING&);

	//이동생성과 이동할당연산자     //2025.4.8
	STRING(STRING&&);
	STRING& operator=(STRING&&);

	//관계 연산자들(relative ops) -총 6개
	bool operator<(const STRING& rhs) const;   //2025.4.10
	bool operator==(const STRING& rhs) const;   //2025.4.22

	size_t size() const;
	//2025.5.15 리턴타입을 클래스로
	STRING_Iterator begin() const;
	STRING_Iterator end() const;
	//2025.5.13
	STRING_Reverce_Iterator rbegin()const;
	STRING_Reverce_Iterator rend()const;

	/*std::reverse_iterator<char*> rbegin() const;
	std::reverse_iterator<char*> rend() const;*/

private:
	size_t len;
	std::unique_ptr<char[]> p; //복사가 안되는 클래스
	size_t id;      //생성 시 부여되는 고유값

	static size_t gid;
	friend std::ostream& operator<<(std::ostream& os, const STRING& str);
	friend std::istream& operator>>(std::istream& in, STRING& str);


};

