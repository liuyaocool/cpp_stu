#pragma once
#include <iostream>
using namespace std;


/*
	struct Ĭ��Ȩ�� ����
	class Ĭ��Ȩ�� ˽��
*/
class Person
{
	//����Ȩ�� public protected(�̳пɷ���) private
public:
	string name;
protected:
	string car;
private:
	int age;
	long bankcard;
public:
	Person(); // ���캯��
	Person(string name); // ���캯��
	Person(int age); // ���캯��
	Person(const Person& p); // �������캯��
	// �������� �����в��� ��������ǰ�Զ�����
	// ����Գ���ٵĿռ� ��new ��Ҫ�������������ͷ�
	~Person();
	void showPerson();
	void setBankcard(long card);
	long getBankcard();
};
