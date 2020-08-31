#include "core1.h"


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

