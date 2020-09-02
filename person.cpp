#include "person.h"


// 添加作用域 声明为成员函数
//Person::Person()
//{
//	// 构造函数
//	cout << "person 的构造函数调用" << endl;
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
	// 析构函数
	cout << "person 的析构函数调用" << endl;
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
	cout << "静态函数调用" << endl;
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
	cout << "GoodGay获得Person："<< person->name << " "<< person->age << endl;
}

GoodGirl::GoodGirl()
{
	person = new Person("girl", 18);
}
void GoodGirl::visit()
{
	cout << "GoodGirl -> visit 获得Person：" << person->name << " " << person->age << endl;
}
void GoodGirl::novisit()
{
	cout << "GoodGirl -> novisit获得Person：" << person->name << endl;
}