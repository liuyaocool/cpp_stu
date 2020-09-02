#pragma once
#include <iostream>
using namespace std;

class Person;
class GoodGirl
{
public:
	GoodGirl();
	void visit();
	void novisit();
	Person * person;
};

class GoodGay
{
public:
	GoodGay();
	void visit();
	Person* person;
};

/*
	struct 默认权限 共有
	class 默认权限 私有

	成员变量和成员函数分开存储  --> siezof(对象) 可测试
		空对象 class A{} 编译器分配一个字节空间，为区分占内存位置，每个空对象有独一无二的内存地址
		只有非静态成员变量 属于类的对象上
		成员函数只产生一份实例
	this指针 --> 指针常量 指向不可修改
		解决名称冲突
		返回对象本身 *this
*/
class Person
{
	//访问权限 public protected(继承可访问) private
public:
	string name;
	static int staticint; // 静态变量
protected:
	string car;
private:
	int age;
	long bankcard;
public:
	//Person(); // 构造函数
	Person(string name); // 构造函数
	Person(int age); // 构造函数
	Person(const Person& p); // 拷贝构造函数
	// 析构函数 不能有参数 对象销毁前自动调用
	// 程序猿开辟的空间 如new 需要在析构函数中释放
	~Person();
	// 初始化列表赋初值
	Person(): name("Taylor"),car("兰博基尼"),age(19)
	{

	}
	Person(string cname, int cage) : name(cname), age(cage)
	{

	}
	void setBankcard(long card);
	long getBankcard();
	void showPerson();
	void showClassName();
	Person& getEntity();
	Person getEntityc(); // 调用拷贝构造函数
	// 静态函数
	static void staticFunc();

	mutable int ma; // 特殊变量 常函数中也可以修改
	//常函数
	// this → Person* const this; 指针值可以修改
	void constfunc() const // → const Person* const this; 指针值也不可以修改
	{
		//this->name = "李李"; 
		this->ma = 12;;
	}

	// 友元
	friend void goodGay(Person* p);
	friend class GoodGay;
	friend void GoodGirl::visit();
};

void goodGay(Person* p);
