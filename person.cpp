#include "person.h"


// ��������� ����Ϊ��Ա����
Person::Person()
{
	// ���캯��
	cout << "person �Ĺ��캯������" << endl;
}
Person::Person(string cname)
{
	name = cname;
}
Person::Person(int cage)
{
	age = cage;
}
Person::Person(const Person& p)
{
	age = p.age;
}
Person::~Person()
{
	// ��������
	cout << "person ��������������" << endl;
}
void Person::showPerson()
{
	cout << name << endl;
}
void Person::setBankcard(long card)
{
	bankcard = card;
}
long Person::getBankcard()
{
	return bankcard;
}
