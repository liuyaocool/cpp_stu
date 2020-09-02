#include "core1.h"
#include "person.h"


/*
	1 �ڴ����ģ��
		������������ֻ��
		ȫ����
		ջ�����������Զ������ͷ� һ���žֲ���������������
			ע  ��Ҫ���ؾֲ�������ַ��ջ���������ں���������������Զ��ͷ�
				��һ�ο�����ȷ���� ��Ϊ���������˱���
				�ڶ������ݾͲ��ٱ���
		����������Գ������ͷ� new�ڶ��������ڴ�

*/
// ȫ�ֱ���
int ga = 21;
int gb = 22;
// const ȫ��
const int cga = 41;
void testGlobal()
{
	// ��ȫ�������ֲ��������ֲ�����
	int a = 10; 
	int b = 12;
	cout << "�ֲ� ����a��" << (int)&a << endl;
	cout << "�ֲ� ����b��" << (int)&b << endl;

	// ȫ����: ȫ�ֱ�������̬������ȫ�ֳ���
	cout << "ȫ�� ����a��" << (int)&ga << endl;
	cout << "ȫ�� ����b��" << (int)&gb << endl;

	static int sa = 31;
	static int sb = 32;
	cout << "��̬ ����a��" << (int)&sa << endl;
	cout << "��̬ ����b��" << (int)&sb << endl;
	
	cout << "const ȫ�� ����a��" << (int)&cga << endl;

	const int cla = 51;
	const int clb = 52;
	cout << "const �ֲ� ����a��" << (int)&cla << endl;
	cout << "const �ֲ� ����b��" << (int)&clb << endl;

	cout << "�ַ��� ������" << (int)&"hello" << endl;
}


int* stackFunc()
{
	int p = 10;
	return &p;
}
void testStack()
{
	int* p = stackFunc();
	cout << *p << endl;
	cout << *p << endl;
};
int* heapFunc() 
{
	// new �ؼ��ֿ������ݵ����� ���صĸ��������͵�ָ��
	// ָ�뱾��Ҳ�Ǿֲ����� ����ջ�� ָ�뱣������ݷ��ڶ���
	int* p = new int(10);
	return p;
}
void testHeap()
{
	int* p = heapFunc();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	// �ͷ��ڴ�
	delete p;
	//cout << *p << endl; // ���� �ڴ��Ѿ����ͷ�

	// ��������
	int* arr = new int[10]; // �����׵�ַ ��ֱ�Ӷ�������һ��
	arr[0] = 123;
	cout << arr[0] << endl;
	// �ͷ�����
	delete[] arr;

}

/*
	����
	���� ָ�볣��
	���ã��������� &���� = ԭ��
	���ñ����ʼ�� ��ʼ���󲻿ɸı�
*/
// ��������������
void swapRelative(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
// ��������������ֵ
int& retRelative01()
{
	// ��Ҫ���ؾֲ�����������
	int a = 10;
	return a;
}
int& retRelative02()
{
	// ���ؾ�̬����������
	static int a = 10;
	return a;
}
// ��������
void showConstRelative(const int& val)
{
	//val = 789;// const ��ֹ���޸�
	cout << "�������ò����� " << val << endl;
}
void showConstRelative1(int& val)
{
	val = 456;
	cout << "�޸ĳ������ò����� " << val << endl;

}
void testRelative()
{
	int a = 10;
	int &b = a; // �� int* const b = a;  ---ָ��b����a�ĵ�ַ
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << endl;
	 
	b = 100; // �� *b = 100; 
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << endl;

	int c = 20;
	b = c; // ��ֵ���� �����Ǹ�������
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << endl;

	c = 30;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	cout << endl;

	int ar = 10;
	int br = 20;
	swapRelative(ar, br);
	cout << "ar: " << ar << endl;
	cout << "br: " << br<< endl;
	cout << endl;

	// ����������ֵ 
	int& ret01 = retRelative01();
	cout << "swapRetRelative01: " << ret01 << endl;// ��һ�ν����ȷ ��Ϊ���������˱���
	cout << "swapRetRelative01: " << ret01 << endl;// �ڶ��ν������ �ڴ��Ѿ��ͷ�
	cout << endl;

	int& ret02 = retRelative02();
	cout << "swapRetRelative02: " << ret02 << endl;
	cout << "swapRetRelative02: " << ret02 << endl;
	cout << "swapRetRelative02: " << ret02 << endl;
	// ����������ֵ ������Ϊ��ֵ
	retRelative02() = 1000; 
	cout << "swapRetRelative02: " << ret02 << endl;
	cout << "swapRetRelative02: " << ret02 << endl;
	cout << endl;


	// ��������
	const int& ref = 12; // �� int temp = 12; const int& ref = temp;
	//ref = 20; // ֻ�� �����޸�
	int aa = 123;
	showConstRelative(aa);
	cout << "aa: " << aa << endl;
	showConstRelative1(aa);
	cout << "aa: " << aa << endl;

}


/*
	����������Ĭ�ϲ��� ���������������
	������ʵ����ֻ����һ��λ�ü�Ĭ�ϲ���
*/
void funcDefParam(int a, int b = 10, int c = 20);
// ռλ���� ռλ����Ҳ������Ĭ��ֵ
void funcSeatParam(int a, int /* = 10 */ )
{
	cout << "funcSeatParam: " << a << endl;
};
void testDefParam()
{
	// ����Ĭ�ϲ�������
	funcDefParam(20, 30, 40);
	funcDefParam(20, 30);
	funcDefParam(20);
	funcSeatParam(3, 6);
};
void funcDefParam(int a, int b, int c)
{
	int s = a + b + c;
	cout << "funcDefParam: " << s << endl;
};


/*
	�������� ��������ͬ
	����
		ͬһ��������
		������ͬ
		�������͡�������˳��ͬ
		����ֵ����Ϊ��������
	�� 
		������Ϊ��������
		Ĭ�ϲ���

*/
void funcRepeat()
{
	cout << "���� funcRepeat()" << endl;
}
void funcRepeat(double a)
{
	cout << "���� funcRepeat(double a)" << endl;
}
void funcRepeat2(int& a) // �� int& a = ����;���Ϸ���\ int& a = 10; (���Ϸ�)
{
	cout << "���� funcRepeat(int& a)" << endl;
}
void funcRepeat2(const int& a) // �� const int& a = 10; (�Ϸ�) const-������������ʱ�ڴ�ռ�
{
	cout << "���� funcRepeat(const int& a)" << endl;
}
void testFuncRepeat()
{
	int a = 12;
	funcRepeat2(a);
	funcRepeat2(10); 
}

// ================================================== �� ===================================
void funcPersonParam(Person p) { // �������ÿ������캯��

}
Person funcPersonRet() {
	Person p = Person("�������ض���");
	return p;// ���ÿ������캯��
}
void testClass()
{
	Person p1; // ��ջ�ϵ����� ����ִ����� �Զ��ͷ�
	p1.name = "����";
	p1.showPerson();

	// ���ŷ� ����Ĭ�Ϲ��� ��Ҫ��()
	Person p2(); // ����Ϊ�Ǻ�������
	Person p3("����");
	p3.showPerson();

	//��ʾ��
	Person p4 = Person("����");
	Person("����"); // �������� ��ִ�н����� ��������
	//Person(p3); // �� Person p3;  ���ظ�����

	//��ʽת����
	//Person p5 = "�ŷ�";
	Person p6 = 28; // �� Person p6 = Person(28);

	// ֵ���� ��������ÿ������캯��
	funcPersonParam(p4);
	Person pret = funcPersonRet();

	// ���þ�̬��Ա
	p1.staticFunc();
	Person::staticFunc();

	// ��ָ����Է��ʳ�Ա���� ��ע��showPerson����ʵ��
	Person* p7 = NULL;
	p7->showClassName();
	p7->showPerson();

	// ������
	const Person cp1;
	//cp1.name = "ccc"; // ��ͨ���� �����޸�
	cp1.ma = 23; // ������� ���޸�
	//cp1.showClassName(); // ���ܵ�����ͨ���� ��Ϊ��ͨ���������޸���ͨ����
	cp1.constfunc();

	// ��Ԫ ���Է���˽������
	Person p8("��Ԫ", 18);
	// ȫ�ֺ�������Ԫ
	goodGay(&p8);
	// ������Ԫ
	GoodGay gg;
	gg.visit();
	// ��Ա��������Ԫ
	GoodGirl girl;
	girl.visit();
	girl.novisit();
}
void goodGay(Person* p)
{
	cout << p->name << " " << p->age << "��" << endl;
}

// ================================================== ��������� ===================================
class Yunsuan
{
public:
	
	int a;
	int b;
	int* c; // ���ݿ��ٵ�����
	~Yunsuan() 
	{
		if (this->c != NULL) {
			delete c;
			c = NULL;
		}
	}
	Yunsuan() {}
	Yunsuan(int ca, int cb, int cc):a(ca),b(cb) {
		c = new int(cc);
	}
	// ��Ա��������+��  --y1 + y2; // �� y1.operator+(y2);
	/*Yunsuan operator+(Yunsuan& yun)
	{
		Yunsuan temp;
		temp.a = this->a + yun.a;
		temp.b = this->b + yun.b;
		return temp;
	}*/
	// ����++ 
	// ++Yunsuan
	Yunsuan& operator++() // Ϊ��++��++Yunsun�� �˴���������
	{
		this->b++;
		return *this;
	}
	// Yunsuan++
	Yunsuan operator++(int) // intռλ���� ����ǰ�ú��� ���ص���ֵ
	{
		Yunsuan temp = *this; // �ȼ�¼��ǰ���
		this->b++; // ִ��++����
		return temp; // ���ز���ǰ���
	}
	// ���� ��ֵ�� =
	Yunsuan& operator=(Yunsuan& yun)
	{
		// �������ṩ��ǳ���� =��ֵ������Ϊǳ�����������Ǹ�ֵָ�� 
		// ����������ָ����ͬ�� ָ��ͬһ���ڴ� ���ͷ�cʱ������ظ��ͷŵĴ���
		//c = yun.c;
		// ��������� �������ڶ����� ���ͷŸɾ� �����
		if (c != NULL)
		{
			delete c;
			c = NULL;
		}
		c = new int(*yun.c); // ���
		return *this;
	}
	// ��ϵ����� == != ������
	bool operator==(Yunsuan& yun)
	{
		if (this->a != yun.a || this->b != yun.b)
		{
			return false;
		}
		return true;
	}
	// ����������������� () �ֳƷº���
	void operator()(string str)
	{
		cout << str << endl;
	}
	int operator()(int a, int b)
	{
		return a + b;
	}

	void show()
	{
		cout << "a: " << a << "  b: " << b << "  c: " << c << endl;
	}
};
// ȫ�ֺ�������+�� 
Yunsuan operator+(Yunsuan& y1, Yunsuan& y2)
{
	Yunsuan temp;
	temp.a = y1.a + y2.a;
	temp.b = y1.b + y2.b;
	return temp;
}
// ����<< ��Ա���� ֻ��ʵ�� p<<cout      -- ��ʽ���˼��
ostream& operator<<(ostream& cout, Yunsuan yun) // Yunsuan& yun
{
	yun.show();
	return cout;
}
void testYunSuanFu()
{
	Yunsuan y1(11, 22, 18);
	Yunsuan y2(33, 44, 19);
	
	Yunsuan y3 = y1 + y2;

	cout << "y1+y2" << y3 << " " << endl;
	cout << ++y3 << endl;
	cout << "++yun " << y3 << endl;
	cout << y3++ << endl;
	cout << "yun++ " << y3 << endl;

	Yunsuan y4(55, 66, 17);
	//y2 = y1;
	y4 = y2 = y1; // ��Ҫ��������

	Yunsuan y5(12, 23, 45);
	Yunsuan y6(12, 33, 46);
	if (y5 == y6) 
	{
		cout << "y5 == y6" << endl;
	}
	else
	{
		cout << "y5 != y6" << endl;
	}

	y1("���أ���--> �º�������");
	cout << "���أ���--> operator()(int a, int b) <-- 12, 13" << y1(12, 13) << endl;

	//������������
	Yunsuan(1,2,3)("���أ���--> ������������");
};














