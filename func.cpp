#include "func.h"

void swap(int n1, int n2)
{

	cout << "交换前\n";
	cout << "n1 = " << n1 << endl;
	cout << "n2 = " << n2 << endl;

	int temp = n1;
	n1 = n2;
	n2 = temp;

	cout << "交换后\n";
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
	指针
*/
void testPointer()
{
	int a = 10;
	int b = 10;
	int c = 15;
	int* p;
	// 指针记录变量a的地址
	p = &a;

	cout << "a的地址为 = " << &a << endl;
	cout << "a的指针 = " << a << endl;
	// 使用指针
	// 解引用的方式找到指向的内存 → 指针前加一个*号
	*p = 1000; // 修改内存
	cout << "a = " << a << endl;
	cout << "*p = " << *p << endl;

	// 占用空间：在32位系统下， 所有指针类型都占4个字节空间 64位8个
	cout << "int* size: " << sizeof(p) << endl;
	cout << "int* size: " << sizeof(int*) << endl;
	cout << "float* size: " << sizeof(float*) << endl;
	cout << "double* size: " << sizeof(double*) << endl;
	cout << "char* size: " << sizeof(char*) << endl;

	// 空指针 
	// 1：指向内存中编号为0的空间 
	// 2： 初始化指针变量
	int* p1 = NULL;
	// 3：不能被访问 0~255之间内存是系统占用 没有权限访问
	//*p = 100; // 报错

	// 野指针 指针变量指向非法的内存空间
	int* p2 = (int*)0x1100; // 这块地址没有申请 不可被访问
	//cout << *p2 << endl;

	// ======================== 常量 && 指针 =========================
	// 常量指针
	const int* cip = &a;
	// 指针指向可以改 
	cip = &b;
	cip = &c;
	// 但指针指向的值不能改
	//*cp = 15; //此行会报错

	// 指针常量 指向不能改 指向的值能改
	int* const icp = &a;
	//icp = &b; // 此行错误
	*icp = 20;

	// 即修饰指针,又修饰常量 指向和指向值都不能改
	const int* const cicp = &a;

	// ======================== 数组 && 指针 =========================
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int* arrp = arr; // 指针指向首地址
	cout << "use point get array first element: " << *arrp << endl;
	arrp++; // 指针向后偏移4个字节
	cout << "use point get array second element: " << *arrp << endl;
	printArray(arr, sizeof(arr) / sizeof(arr[0]));
	// ======================== 函数 && 指针 =========================
	cout << "a = " << a << endl;
	cout << "c = " << c << endl;
	swap02(&a, &c);
	cout << "a = " << a << endl;
	cout << "c = " << c << endl;

}
 void testStruct()
 {

 
 }