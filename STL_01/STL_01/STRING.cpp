//-----------------------------------------------------
//STRING.cpp - std::string �� ������ Ŭ����
//           stl�� ǥ�� �����̳ʷμ� ���� �� �� �ֵ���
//                                          20254.8
//-----------------------------------------------------

#include <iostream>
#include <memory>
#include <print>

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

//�����ڵ�
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