#pragma once
#include <iostream>
using namespace std;


/*
	struct 默认权限 共有
	class 默认权限 私有
*/
class Person
{
	//访问权限 public protected(继承可访问) private
public:
	string name;
protected:
	string car;
private:
	int age;
	long bankcard;
public:
	Person(); // 构造函数
	Person(string name); // 构造函数
	Person(int age); // 构造函数
	Person(const Person& p); // 拷贝构造函数
	// 析构函数 不能有参数 对象销毁前自动调用
	// 程序猿开辟的空间 如new 需要在析构函数中释放
	~Person();
	void showPerson();
	void setBankcard(long card);
	long getBankcard();
};
