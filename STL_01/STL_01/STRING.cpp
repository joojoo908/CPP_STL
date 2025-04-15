//-----------------------------------------------------
//STRING.cpp - std::string 과 유사한 클래스
//           stl의 표준 컨테이너로서 동작 할 수 있도록
//                                          20254.8
//-----------------------------------------------------

#include <iostream>
#include <memory>
#include <print>

#include"STRING.h"

bool 관찰{ false };

STRING::STRING()
	: id{ ++gid }, len{ 0 }
{
	if (관찰) {
		std::println("[{:8}] - {:<20} 자원수:{:<6} 주소:{:>16}, 자원의 주소:{:>16}",
			id, "default 생성자", len, (void*)this, (void*)p.get());
	}
}

STRING::~STRING()
{
	if (관찰) {
		std::println("[{:8}] - {:<20} 자원수:{:<6} 주소:{:>16}, 자원의 주소:{:>16}",
			id, "소멸자", len, (void*)this, (void*)p.get());
	}
}

STRING::STRING(const char* s)
	: id{ ++gid }, len{ strlen(s) }
{
	p.reset();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), s, len);

	if (관찰) {
		std::println("[{:8}] - {:<20} 자원수:{:<6} 주소:{:>16}, 자원의 주소:{:>16}",
			id, "생성자(char*)", len, (void*)this, (void*)p.get());
	}
}

//복사생성과 복사할당연산자
STRING::STRING(const STRING& other)
	: id{ ++gid }, len{ other.len }
{
	p.reset();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (관찰) {
		std::println("[{:8}] - {:<20} 자원수:{:<6} 주소:{:>16}, 자원의 주소:{:>16}",
			id, "복사 생성자", len, (void*)this, (void*)p.get());
	}
}

STRING& STRING::operator=(const STRING& other)
{
	if (this == &other)
		return *this;

	len = other.len;
	p.release();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (관찰) {
		std::println("[{:8}] - {:<20} 자원수:{:<6} 주소:{:>16}, 자원의 주소:{:>16}",
			id, "복사할당연산자", len, (void*)this, (void*)p.get());
	}

	return *this;
}

//이동생성과 이동할당연산자 
STRING::STRING(STRING&& other)
	:id{ ++gid }, len{ other.len }
{
	p.reset(other.p.release());
	other.len = 0;

	//*this = other;

	//other.p.release(); //필요없지만 안전을 위해 // 무효과

	if (관찰) {
		std::println("[{:8}] - {:<20} 자원수:{:<6} 주소:{:>16}, 자원의 주소:{:>16}",
			id, "이동 생성자", len, (void*)this, (void*)p.get());
	}
}

STRING& STRING::operator=(STRING&& other)
{
	if (this == &other)
		return *this;

	len = other.len;
	p.reset(other.p.release());
	other.len = 0;

	if (관찰) {
		std::println("[{:8}] - {:<20} 자원수:{:<6} 주소:{:>16}, 자원의 주소:{:>16}",
			id, "이동 operator=", len, (void*)this, (void*)p.get());
	}
	return *this;
}

//연산자들
bool STRING::operator<(const STRING& other) const
{
	return len < other.len;
}

size_t STRING::size() const
{
	return len;
}

std::ostream& operator<<(std::ostream& os, const STRING& str)
{
	for (int i = 0; i < str.len; ++i) {
		os << str.p[i];
	}
	return os;
}

std::istream& operator>>(std::istream& is, STRING& str)
{
	std::string s;
	is >> s;

	str.p.release();
	str.p = std::make_unique<char[]>(s.size());
	str.len = s.size();
	memcpy(str.p.get(), s.data(), str.len);

	return is;
}

size_t STRING::gid{ 0 };