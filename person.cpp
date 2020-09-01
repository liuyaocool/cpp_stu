#include "person.h"


// 添加作用域 声明为成员函数
Person::Person()
{
	// 构造函数
	cout << "person 的构造函数调用" << endl;
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
	// 析构函数
	cout << "person 的析构函数调用" << endl;
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
