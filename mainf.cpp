#include <iostream>
using namespace std;
#include <string> // ʹ��c++ ����ַ��� ��������ͷ�ļ�
#include "func.h"

// �곣��
#define day 7

// �������� ��ǰ���߱������������� 
// ��������� ������ֻһ��
int add(int n1, int n2);
void mainHello();

int main()
{
	// ���ȣ� https://www.bilibili.com/video/BV1et411b73Z?p=64

	//mainHello();

	//testPointer();

	testStruct();

	system("pause");
	return 0;

}

void mainHello()
{

	//���� ��������-��������ڴ�ռ�
	int inta = 10; // 4�ֽ�
	short sa = 13; // 2�ֽ�
	long la = 14; // win-4�ֽ� linux-4�ֽ�(32λ)��8�ֽ�(64λ)
	long long lla = 15; //8�ֽ�

	float fa = 1.23f; // 4�ֽ� ����f ����Ϊ1.23Ϊdouble Ȼ����תΪfloat �ٸ�ֵ ��һ������
	double da = 2.33; // 8�ֽ�
	float fa2 = 3e2; // ��ѧ������ 3 * 10^2
	float fa3 = 3e-2; // 3 * 0.1^2

	char cha = 'a'; // 1�ֽ� ��ӦASCll����--> (int)cha

	//�ַ���
	char stra[] = "asdfg"; // c ���
	string stra2 = "zxcvb"; //c++ ���

	bool boola = true; // �������� 1-true 0-false 1�ֽ� Ҳ����int=0��1 �ж����

	cout << "hello a=" << inta << endl;
	cout << "short ռ�ÿռ�=" << sizeof(short) << endl;
	cout << "long long ռ�ÿռ�=" << sizeof(lla) << endl;
	cout << "float=" << fa << endl; // Ĭ����ʾ6λ��Ч����

	//����
	const int intb = 12;
	cout << "һ��" << day << "��" << endl;

	//�ؼ���

	//ת���ַ� \ 
	cout << "helo world\n";

	// ��ü�������
	int intc = 0;
	cout << "������int:" << endl;
	cin >> intc;
	char chc[] = "asdfg";
	cout << "������char[]:" << endl;
	cin >> chc;
	bool boolc = false;
	cout << "������boolc:" << endl;
	cin >> boolc; // ��0��Ϊ��=1

	// �����

	// ���̿��� if -- else if -- else

	// ��Ԫ�����
	int a = 10;
	int b = 20;
	int c = 0;
	c = (a > b ? a : b);
	(a > b ? a : b) = 100; // c++ �з��ص��Ǳ��� ���Լ�����ֵ

	// switch case default break  -- ���� �ַ��� Ч�ʸ�
	// while
	// do while 
	// for
	// break continue

	// goto
	if (true) goto FLAG;
	cout << "goto\n";
FLAG: // ����� ð��

	// һά����
	int intarr1[5];
	intarr1[0] = 10;
	int intarr2[5] = { 1,2,3,4,5 };
	int intarr3[] = { 6,7,8,9,10,11,12 };
	// һά����������; �� 
	// �������ǳ��� ���ܽ��и�ֵ
	cout << "intarr2 siez: " << sizeof(intarr3) << endl;
	cout << "intarr2 size��" << sizeof(intarr2) / sizeof(intarr2[0]) << endl;
	cout << "intarr2 first addr: " << intarr2 << endl;
	cout << "intarr2 first element addr: " << &intarr2[0] << endl;
	cout << "intarr2 second element addr: " << &intarr2[1] << endl;
	// ��ά���� �� �������� ������ [����] [����]
	int intarr1_2D[2][3];
	intarr1_2D[0][0] = 15;
	int intarr2_2D[2][3] = { {1,2,3}, {4,5,6} };
	int intarr3_2D[2][3] = { 1,2,3, 4,5,6 };
	int intarr4_2D[][3] = { 1,2,3, 4,5,6 };
	// ��ά����������; �� 
	cout << "intarr2_2D siez: " << sizeof(intarr2_2D) << endl;
	cout << "intarr2_2D row1 size��" << sizeof(intarr2_2D[0]) << endl;
	cout << "intarr2_2D first addr: " << intarr2_2D << endl;
	cout << "intarr2_2D row1 first addr: " << intarr2_2D[0] << endl;
	cout << "intarr2_2D row2 first addr: " << intarr2_2D[1] << endl;
	cout << "intarr2_2D first element addr: " << &intarr2_2D[0][0] << endl;
	cout << "intarr2_2D second element addr: " << &intarr2_2D[0][1] << endl;

	//��������
	int sum = add(12, 25);
	swap(11, 22);

	

}


//��������
/**
 *	ֵ���� ʵ�β���ı�
 *	ԭ�� �β����·����ڴ棬���и�ֵ
 */
int add(int n1, int n2)
{
	int sum = n1 + n2;
	cout << "sum = " << sum << endl;
	return sum;
}