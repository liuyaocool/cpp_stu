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

	swap(11, 22);

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

// �ṹ��
void testStruct()
{
	struct Student s1;
	s1.name = "����";
	s1.age = 18;
	s1.score = 59;

	cout << s1.name << " " << s1.age << " " << s1.score << endl;

	struct Student s2 = { "����", 19, 59.5 }; // ��˳��ֵ
	cout << s2.name << " " << s2.age << " " << s2.score << endl;

	struct Student sarr1[3];
	sarr1[0] = { "������", 19, 59.5 };
	// ������                                                        

	struct Student sarr2[3] = {
		{ "��������", 19, 59.5 },
		{ "��˼˼˼", 19, 59.5 },
		{ "��������", 19, 59.5 },
	};

	cout << sarr1[0].name << " " << sarr1[0].age << " " << sarr1[0].score << endl;

	// ========================================= �ṹ��ָ�� ===============================================
	struct Student* ps1 = &s1;
	// ָ�� ���ʽṹ������
	cout << ps1 ->name << " " << ps1->age << " " << ps1 -> score << endl;

	// ========================================= �ṹ�� Ƕ�� ===============================================
	struct Teacher t1;
	t1.name = "����";
	t1.age = 49;
	t1.stu.name = "����";
	cout << t1.name << " " << t1.age << " " << t1.stu.name << endl;

	// ========================================= �ṹ�� ��Ϊ�������� ===============================================
	printStudent(s1); // ֵ���� Ϊ����һ�� ��Ȼ�����޸Ľṹ���е�����
	printStudentp(&s2); // ��ַ���ݲ��Ḵ��һ�� �ɽ�ʡ�ڴ�
	printStudents(sarr2, sizeof(sarr2) / sizeof(sarr2[0]));

	// ========================================= const ===============================================
	printStudentc(&s2);






}


void printStudent(struct Student s1)
{
	cout << "��ͨ �ṹ�������" << s1.name << " " << s1.age << " " << s1.score << endl;
}

void printStudentp(struct Student* ps1)
{
	cout << "ָ�� �ṹ�������" << ps1->name << " " << ps1->age << " " << ps1->score << endl;
}

void printStudentc(const struct Student* ps1)
{
	cout << "constָ�� �ṹ�������" << ps1->name << " " << ps1->age << " " << ps1->score << endl;
}

void printStudents(struct Student s1[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "���� �ṹ�������" << s1[i].name << " " << s1[i].age << " " << s1[i].score << endl;
	}
};