#include <iostream>
using namespace std;
#include <string> // 使用c++ 风格字符串 必须引入头文件
#include "func.h"

// 宏常量
#define day 7

// 函数声明 提前告诉编译器函数存在 
// 可声明多次 但定义只一次
int add(int n1, int n2);
void mainHello();

int main()
{
	// 导入源码 https://blog.csdn.net/GoJawee/article/details/61209111?utm_source=blogxgwz7
	// 进度： https://www.bilibili.com/video/BV1et411b73Z?p=64

	//mainHello();

	//testPointer();

	testStruct();

	system("pause");
	return 0;

}

void mainHello()
{

	//变量 数据类型-分配合适内存空间
	int inta = 10; // 4字节
	short sa = 13; // 2字节
	long la = 14; // win-4字节 linux-4字节(32位)、8字节(64位)
	long long lla = 15; //8字节

	float fa = 1.23f; // 4字节 不加f 会认为1.23为double 然后再转为float 再赋值 多一布操作
	double da = 2.33; // 8字节
	float fa2 = 3e2; // 科学计数法 3 * 10^2
	float fa3 = 3e-2; // 3 * 0.1^2

	char cha = 'a'; // 1字节 对应ASCll编码--> (int)cha

	//字符串
	char stra[] = "asdfg"; // c 风格
	string stra2 = "zxcvb"; //c++ 风格

	bool boola = true; // 布尔类型 1-true 0-false 1字节 也可用int=0、1 判断真假

	cout << "hello a=" << inta << endl;
	cout << "short 占用空间=" << sizeof(short) << endl;
	cout << "long long 占用空间=" << sizeof(lla) << endl;
	cout << "float=" << fa << endl; // 默认显示6位有效数字

	//常量
	const int intb = 12;
	cout << "一周" << day << "天" << endl;

	//关键字

	//转译字符 \ 
	cout << "helo world\n";

	// 获得键盘输入
	int intc = 0;
	cout << "请输入int:" << endl;
	cin >> intc;
	char chc[] = "asdfg";
	cout << "请输入char[]:" << endl;
	cin >> chc;
	bool boolc = false;
	cout << "请输入boolc:" << endl;
	cin >> boolc; // 非0都为真=1

	// 运算符

	// 流程控制 if -- else if -- else

	// 三元运算符
	int a = 10;
	int b = 20;
	int c = 0;
	c = (a > b ? a : b);
	(a > b ? a : b) = 100; // c++ 中返回的是变量 可以继续赋值

	// switch case default break  -- 整型 字符型 效率高
	// while
	// do while 
	// for
	// break continue

	// goto
	if (true) goto FLAG;
	cout << "goto\n";
FLAG: // 标记名 冒号

	// 一维数组
	int intarr1[5];
	intarr1[0] = 10;
	int intarr2[5] = { 1,2,3,4,5 };
	int intarr3[] = { 6,7,8,9,10,11,12 };
	// 一维数组名的用途 → 
	// 数组名是常量 不能进行赋值
	cout << "intarr2 siez: " << sizeof(intarr3) << endl;
	cout << "intarr2 size：" << sizeof(intarr2) / sizeof(intarr2[0]) << endl;
	cout << "intarr2 first addr: " << intarr2 << endl;
	cout << "intarr2 first element addr: " << &intarr2[0] << endl;
	cout << "intarr2 second element addr: " << &intarr2[1] << endl;
	// 二维数组 → 数组类型 数组名 [行数] [列数]
	int intarr1_2D[2][3];
	intarr1_2D[0][0] = 15;
	int intarr2_2D[2][3] = { {1,2,3}, {4,5,6} };
	int intarr3_2D[2][3] = { 1,2,3, 4,5,6 };
	int intarr4_2D[][3] = { 1,2,3, 4,5,6 };
	// 二维数组名的用途 → 
	cout << "intarr2_2D siez: " << sizeof(intarr2_2D) << endl;
	cout << "intarr2_2D row1 size：" << sizeof(intarr2_2D[0]) << endl;
	cout << "intarr2_2D first addr: " << intarr2_2D << endl;
	cout << "intarr2_2D row1 first addr: " << intarr2_2D[0] << endl;
	cout << "intarr2_2D row2 first addr: " << intarr2_2D[1] << endl;
	cout << "intarr2_2D first element addr: " << &intarr2_2D[0][0] << endl;
	cout << "intarr2_2D second element addr: " << &intarr2_2D[0][1] << endl;

	//函数调用
	int sum = add(12, 25);
	swap(11, 22);



}


//函数定义
/**
 *	值传递 实参不会改变
 *	原理 形参重新分配内存，进行赋值
 */
int add(int n1, int n2)
{
	int sum = n1 + n2;
	cout << "sum = " << sum << endl;
	return sum;
}