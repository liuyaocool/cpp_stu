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
	struct Ĭ��Ȩ�� ����
	class Ĭ��Ȩ�� ˽��

	��Ա�����ͳ�Ա�����ֿ��洢  --> siezof(����) �ɲ���
		�ն��� class A{} ����������һ���ֽڿռ䣬Ϊ����ռ�ڴ�λ�ã�ÿ���ն����ж�һ�޶����ڴ��ַ
		ֻ�зǾ�̬��Ա���� ������Ķ�����
		��Ա����ֻ����һ��ʵ��
	thisָ�� --> ָ�볣�� ָ�򲻿��޸�
		������Ƴ�ͻ
		���ض����� *this
*/
class Person
{
	//����Ȩ�� public protected(�̳пɷ���) private
public:
	string name;
	static int staticint; // ��̬����
protected:
	string car;
private:
	int age;
	long bankcard;
public:
	//Person(); // ���캯��
	Person(string name); // ���캯��
	Person(int age); // ���캯��
	Person(const Person& p); // �������캯��
	// �������� �����в��� ��������ǰ�Զ�����
	// ����Գ���ٵĿռ� ��new ��Ҫ�������������ͷ�
	~Person();
	// ��ʼ���б���ֵ
	Person(): name("Taylor"),car("��������"),age(19)
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
	Person getEntityc(); // ���ÿ������캯��
	// ��̬����
	static void staticFunc();

	mutable int ma; // ������� ��������Ҳ�����޸�
	//������
	// this �� Person* const this; ָ��ֵ�����޸�
	void constfunc() const // �� const Person* const this; ָ��ֵҲ�������޸�
	{
		//this->name = "����"; 
		this->ma = 12;;
	}

	// ��Ԫ
	friend void goodGay(Person* p);
	friend class GoodGay;
	friend void GoodGirl::visit();
};

void goodGay(Person* p);
