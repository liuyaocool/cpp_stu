#include "core1.h"


/*
	1 内存分区模型
		代码区：共享、只读
		全局区
		栈区：编译器自动分配释放 一般存放局部变量、函数参数
			注  不要返回局部变量地址，栈区的数据在函数结束后编译器自动释放
				第一次可以正确调用 因为编译器做了保留
				第二次数据就不再保留
		堆区：程序猿分配和释放 new在堆区开辟内存

*/
// 全局变量
int ga = 21;
int gb = 22;
// const 全局
const int cga = 41;
void testGlobal()
{
	// 非全局区：局部变量、局部常量
	int a = 10; 
	int b = 12;
	cout << "局部 变量a：" << (int)&a << endl;
	cout << "局部 变量b：" << (int)&b << endl;

	// 全局区: 全局变量、静态变量、全局常量
	cout << "全局 变量a：" << (int)&ga << endl;
	cout << "全局 变量b：" << (int)&gb << endl;

	static int sa = 31;
	static int sb = 32;
	cout << "静态 变量a：" << (int)&sa << endl;
	cout << "静态 变量b：" << (int)&sb << endl;
	
	cout << "const 全局 常量a：" << (int)&cga << endl;

	const int cla = 51;
	const int clb = 52;
	cout << "const 局部 常量a：" << (int)&cla << endl;
	cout << "const 局部 常量b：" << (int)&clb << endl;

	cout << "字符串 常量：" << (int)&"hello" << endl;
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
	// new 关键字开辟数据到堆区 返回的该数据类型的指针
	// 指针本质也是局部变量 放在栈上 指针保存的数据放在堆区
	int* p = new int(10);
	return p;
}
void testHeap()
{
	int* p = heapFunc();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	// 释放内存
	delete p;
	//cout << *p << endl; // 错误 内存已经被释放

	// 开辟数组
	int* arr = new int[10]; // 返回首地址 与直接定义数组一致
	arr[0] = 123;
	cout << arr[0] << endl;
	// 释放数组
	delete[] arr;

}

/*
	引用
	本质 指针常量
	引用：数据类型 &别名 = 原名
	引用必须初始化 初始化后不可改变
*/
// 引用做函数参数
void swapRelative(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
// 引用做函数返回值
int& retRelative01()
{
	// 不要返回局部变量的引用
	int a = 10;
	return a;
}
int& retRelative02()
{
	// 返回静态变量的引用
	static int a = 10;
	return a;
}
// 常量引用
void showConstRelative(const int& val)
{
	//val = 789;// const 防止误修改
	cout << "常量引用参数： " << val << endl;
}
void showConstRelative1(int& val)
{
	val = 456;
	cout << "修改常量引用参数： " << val << endl;

}
void testRelative()
{
	int a = 10;
	int &b = a; // → int* const b = a;  ---指针b保存a的地址
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << endl;
	 
	b = 100; // → *b = 100; 
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << endl;

	int c = 20;
	b = c; // 赋值操作 而不是更改引用
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

	// 引用做返回值 
	int& ret01 = retRelative01();
	cout << "swapRetRelative01: " << ret01 << endl;// 第一次结果正确 因为编译器做了保留
	cout << "swapRetRelative01: " << ret01 << endl;// 第二次结果错误 内存已经释放
	cout << endl;

	int& ret02 = retRelative02();
	cout << "swapRetRelative02: " << ret02 << endl;
	cout << "swapRetRelative02: " << ret02 << endl;
	cout << "swapRetRelative02: " << ret02 << endl;
	// 引用做返回值 可以作为左值
	retRelative02() = 1000; 
	cout << "swapRetRelative02: " << ret02 << endl;
	cout << "swapRetRelative02: " << ret02 << endl;
	cout << endl;


	// 常量引用
	const int& ref = 12; // → int temp = 12; const int& ref = temp;
	//ref = 20; // 只读 不可修改
	int aa = 123;
	showConstRelative(aa);
	cout << "aa: " << aa << endl;
	showConstRelative1(aa);
	cout << "aa: " << aa << endl;

}

