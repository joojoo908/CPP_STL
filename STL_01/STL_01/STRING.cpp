//-----------------------------------------------------
//STRING.cpp - std::string �� ������ Ŭ����
//           stl�� ǥ�� �����̳ʷμ� ���� �� �� �ֵ���
//                                          20254.8
//-----------------------------------------------------

#include <iostream>
#include <memory>
#include <print>
#include <algorithm>

#include"STRING.h"

bool ����{ false };

STRING::STRING()
	: id{ ++gid }, len{ 0 }
{
	if (����) {
		std::println("[{:8}] - {:<20} �ڿ���:{:<6} �ּ�:{:>16}, �ڿ��� �ּ�:{:>16}",
			id, "default ������", len, (void*)this, (void*)p.get());
	}
}

STRING::~STRING()
{
	if (����) {
		std::println("[{:8}] - {:<20} �ڿ���:{:<6} �ּ�:{:>16}, �ڿ��� �ּ�:{:>16}",
			id, "�Ҹ���", len, (void*)this, (void*)p.get());
	}
}

STRING::STRING(const char* s)
	: id{ ++gid }, len{ strlen(s) }
{
	p.reset();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), s, len);

	if (����) {
		std::println("[{:8}] - {:<20} �ڿ���:{:<6} �ּ�:{:>16}, �ڿ��� �ּ�:{:>16}",
			id, "������(char*)", len, (void*)this, (void*)p.get());
	}
}

//��������� �����Ҵ翬����
STRING::STRING(const STRING& other)
	: id{ ++gid }, len{ other.len }
{
	p.reset();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (����) {
		std::println("[{:8}] - {:<20} �ڿ���:{:<6} �ּ�:{:>16}, �ڿ��� �ּ�:{:>16}",
			id, "���� ������", len, (void*)this, (void*)p.get());
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

	if (����) {
		std::println("[{:8}] - {:<20} �ڿ���:{:<6} �ּ�:{:>16}, �ڿ��� �ּ�:{:>16}",
			id, "�����Ҵ翬����", len, (void*)this, (void*)p.get());
	}

	return *this;
}

//�̵������� �̵��Ҵ翬���� 
STRING::STRING(STRING&& other)
	:id{ ++gid }, len{ other.len }
{
	p.reset(other.p.release());
	other.len = 0;

	//*this = other;

	//other.p.release(); //�ʿ������ ������ ���� // ��ȿ��

	if (����) {
		std::println("[{:8}] - {:<20} �ڿ���:{:<6} �ּ�:{:>16}, �ڿ��� �ּ�:{:>16}",
			id, "�̵� ������", len, (void*)this, (void*)p.get());
	}
}

STRING& STRING::operator=(STRING&& other)
{
	if (this == &other)
		return *this;

	len = other.len;
	p.reset(other.p.release());
	other.len = 0;

	if (����) {
		std::println("[{:8}] - {:<20} �ڿ���:{:<6} �ּ�:{:>16}, �ڿ��� �ּ�:{:>16}",
			id, "�̵� operator=", len, (void*)this, (void*)p.get());
	}
	return *this;
}

//���� �����ڵ�(relative ops) -�� 6��
bool STRING::operator<(const STRING& rhs) const
{
	return len < rhs.len;
}
bool STRING::operator==(const STRING& rhs) const
{
	//lexicographical compair
	/*
	if (len != rhs.len) return 0;

	for (int i = 0; i < len; ++i) {
		if (p[i] != rhs.p[i]) return 0;
	}
	return 1;
	*/
	return std::equal(p.get(), p.get() + len, rhs.p.get(), rhs.p.get() + len);
}

size_t STRING::size() const
{
	return len;
}

char* STRING::begin() const
{
	return &p[0];
}

char* STRING::end() const
{
	return p.get() + len;
}

STRING_Reverce_Iterator STRING::rbegin() const
{
	return p.get() + len;
}

STRING_Reverce_Iterator STRING::rend() const
{
	return &p[0]-1;
}

//std::reverse_iterator<char*> STRING::rbegin() const
//{
//	return std::reverse_iterator<char*>(end());
//}
//
//std::reverse_iterator<char*> STRING::rend() const
//{
//	return std::reverse_iterator<char*>(begin());
//}

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