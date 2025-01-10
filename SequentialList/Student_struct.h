#include"total_header.h"
struct Student {
	int num;
	char name[20];
	char sex[10];
	int age;
};
//还要对这一特定的结构体具体地写一个比较两结构体是否相同的功能。在不同的数据结构中，有一个函数将使用这个比较函数，
//如线性表中的ifListIsEqual()里面是compare()，链表中的ifListIsEqual()里面也是compare()。
//要改变使用的数据元素定义，如将“学生”改为“老师”，写一个老师结构体的头文件并写好老师的compare函数，
//在ElemType.h中替换typedef Student ElemType;为typedef Teacher ElemType;即可。
Status compare(struct Student Student1, struct Student Student2)
{
	if (
	    Student1.num == Student2.num &&
	    strcmp(Student1.name, Student2.name)==0 &&
	    strcmp(Student1.sex,  Student2.sex)==0 &&
	    Student1.age == Student2.age) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
//具体地写一个输出功能。跟上面的原理是一样的。
void display(struct Student Student1)
{
	printf("学号：%d\t姓名：%s\t性别：%s\t年龄：%d\n", Student1.num, Student1.name, Student1.sex, Student1.age);
}
