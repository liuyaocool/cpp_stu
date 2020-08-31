#pragma once
#include <iostream>
#include <string> // ʹ��c++ ����ַ��� ��������ͷ�ļ�
using namespace std;

// �곣��
#define day 7

// struct �ؼ��ֿ���ʡ��
struct Student
{
	string name;
	int age;
	double score;

};
struct Teacher
{
	int code;
	string name;
	int age;
	struct Student stu;

};

void swap(int n1, int n2);

void mainHello();

void testPointer();

void swap02(int* n1, int* n2);

void printArray(int* arr, int len);

void testStruct();

void printStudent(struct Student s1);

void printStudentp(struct Student* ps1);

void printStudentc(const struct Student* ps1);

void printStudents(struct Student s1[], int len);