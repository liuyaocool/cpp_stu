#include "person.h"


// ��������� ����Ϊ��Ա����
//Person::Person()
//{
//	// ���캯��
//	cout << "person �Ĺ��캯������" << endl;
//}
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
	if (NULL == this) {
		return;
	}
	cout << name << endl;
}
void Person::showClassName()
{
	cout << "claeename: Person" << endl;
}
void Person::setBankcard(long card)
{
	this->bankcard = card;
}
long Person::getBankcard()
{
	return this->bankcard;
}
void Person::staticFunc()
{
	cout << "��̬��������" << endl;
}
Person& Person::getEntity()
{
	return *this;
}
Person Person::getEntityc()
{
	 return *this;
}

GoodGay::GoodGay()
{
	person = new Person;
}
void GoodGay::visit()
{
	cout << "GoodGay���Person��"<< person->name << " "<< person->age << endl;
}

GoodGirl::GoodGirl()
{
	person = new Person("girl", 18);
}
void GoodGirl::visit()
{
	cout << "GoodGirl -> visit ���Person��" << person->name << " " << person->age << endl;
}
void GoodGirl::novisit()
{
	cout << "GoodGirl -> novisit���Person��" << person->name << endl;
}