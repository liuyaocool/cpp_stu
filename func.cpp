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

	swap(11, 22);

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

// 结构体
void testStruct()
{
	struct Student s1;
	s1.name = "张三";
	s1.age = 18;
	s1.score = 59;

	cout << s1.name << " " << s1.age << " " << s1.score << endl;

	struct Student s2 = { "李四", 19, 59.5 }; // 按顺序赋值
	cout << s2.name << " " << s2.age << " " << s2.score << endl;

	struct Student sarr1[3];
	sarr1[0] = { "张三三", 19, 59.5 };
	// 。。。                                                        

	struct Student sarr2[3] = {
		{ "张三三三", 19, 59.5 },
		{ "李思思思", 19, 59.5 },
		{ "王五五五", 19, 59.5 },
	};

	cout << sarr1[0].name << " " << sarr1[0].age << " " << sarr1[0].score << endl;

	// ========================================= 结构体指针 ===============================================
	struct Student* ps1 = &s1;
	// 指针 访问结构体属性
	cout << ps1 ->name << " " << ps1->age << " " << ps1 -> score << endl;

	// ========================================= 结构体 嵌套 ===============================================
	struct Teacher t1;
	t1.name = "老王";
	t1.age = 49;
	t1.stu.name = "张四";
	cout << t1.name << " " << t1.age << " " << t1.stu.name << endl;

	// ========================================= 结构体 作为函数参数 ===============================================
	printStudent(s1); // 值传递 为复制一份 仍然不会修改结构体中的内容
	printStudentp(&s2); // 地址传递不会复制一份 可节省内存
	printStudents(sarr2, sizeof(sarr2) / sizeof(sarr2[0]));

	// ========================================= const ===============================================
	printStudentc(&s2);






}


void printStudent(struct Student s1)
{
	cout << "普通 结构体参数：" << s1.name << " " << s1.age << " " << s1.score << endl;
}

void printStudentp(struct Student* ps1)
{
	cout << "指针 结构体参数：" << ps1->name << " " << ps1->age << " " << ps1->score << endl;
}

void printStudentc(const struct Student* ps1)
{
	cout << "const指针 结构体参数：" << ps1->name << " " << ps1->age << " " << ps1->score << endl;
}

void printStudents(struct Student s1[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "数组 结构体参数：" << s1[i].name << " " << s1[i].age << " " << s1[i].score << endl;
	}
};