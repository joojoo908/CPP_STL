//-----------------------------------------------------
//STRING.h - std::string 과 유사한 클래스
//           stl의 동작을 깊게 들여다 보기 위해
//                                        2025.4.8
//-----------------------------------------------------

#pragma once

#include <iostream>
#include <memory>

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

	//연산자들
	bool operator<(const STRING& other) const;   //2025.4.10

	size_t size() const;

private:
	size_t len;
	std::unique_ptr<char[]> p; //복사가 안되는 클래스
	size_t id;      //생성 시 부여되는 고유값

	static size_t gid;
	friend std::ostream& operator<<(std::ostream& os, const STRING& str);
	friend std::istream& operator>>(std::istream& in, STRING& str);


};

