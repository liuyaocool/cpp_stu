#include "func.h"

void swap(int n1, int n2)
{

	cout << "����ǰ\n";
	cout << "n1 = " << n1 << endl;
	cout << "n2 = " << n2 << endl;

	int temp = n1;
	n1 = n2;
	n2 = temp;

	cout << "������\n";
	cout << "n1 = " << n1 << endl;
	cout << "n2 = " << n2 << endl;
};

void swap02(int* n1, int* n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void printArray(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
}


/*
	ָ��
*/
void testPointer()
{
	int a = 10;
	int b = 10;
	int c = 15;
	int* p;
	// ָ���¼����a�ĵ�ַ
	p = &a;

	cout << "a�ĵ�ַΪ = " << &a << endl;
	cout << "a��ָ�� = " << a << endl;
	// ʹ��ָ��
	// �����õķ�ʽ�ҵ�ָ����ڴ� �� ָ��ǰ��һ��*��
	*p = 1000; // �޸��ڴ�
	cout << "a = " << a << endl;
	cout << "*p = " << *p << endl;

	// ռ�ÿռ䣺��32λϵͳ�£� ����ָ�����Ͷ�ռ4���ֽڿռ� 64λ8��
	cout << "int* size: " << sizeof(p) << endl;
	cout << "int* size: " << sizeof(int*) << endl;
	cout << "float* size: " << sizeof(float*) << endl;
	cout << "double* size: " << sizeof(double*) << endl;
	cout << "char* size: " << sizeof(char*) << endl;

	// ��ָ�� 
	// 1��ָ���ڴ��б��Ϊ0�Ŀռ� 
	// 2�� ��ʼ��ָ�����
	int* p1 = NULL;
	// 3�����ܱ����� 0~255֮���ڴ���ϵͳռ�� û��Ȩ�޷���
	//*p = 100; // ����

	// Ұָ�� ָ�����ָ��Ƿ����ڴ�ռ�
	int* p2 = (int*)0x1100; // ����ַû������ ���ɱ�����
	//cout << *p2 << endl;

	// ======================== ���� && ָ�� =========================
	// ����ָ��
	const int* cip = &a;
	// ָ��ָ����Ը� 
	cip = &b;
	cip = &c;
	// ��ָ��ָ���ֵ���ܸ�
	//*cp = 15; //���лᱨ��

	// ָ�볣�� ָ���ܸ� ָ���ֵ�ܸ�
	int* const icp = &a;
	//icp = &b; // ���д���
	*icp = 20;

	// ������ָ��,�����γ��� ָ���ָ��ֵ�����ܸ�
	const int* const cicp = &a;

	// ======================== ���� && ָ�� =========================
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int* arrp = arr; // ָ��ָ���׵�ַ
	cout << "use point get array first element: " << *arrp << endl;
	arrp++; // ָ�����ƫ��4���ֽ�
	cout << "use point get array second element: " << *arrp << endl;
	printArray(arr, sizeof(arr) / sizeof(arr[0]));
	// ======================== ���� && ָ�� =========================
	cout << "a = " << a << endl;
	cout << "c = " << c << endl;
	swap02(&a, &c);
	cout << "a = " << a << endl;
	cout << "c = " << c << endl;

}
 void testStruct()
 {

 
 }