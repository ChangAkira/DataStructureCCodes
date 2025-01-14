#include "ChainList_functions.h"
int main()
{
	struct chainListNode Class1_students_info;
	initList(&Class1_students_info);
	struct chainListNode Class1_students_info2;
	initList(&Class1_students_info2);
	ElemType eleme;
	int len1 = listLength(Class1_students_info);
	int len2 = listLength(Class1_students_info);
	displayList(Class1_students_info);
	ElemType students[] = {
		{123, "张三", "男", 22},
		{342, "李四", "男", 21},
		{421, "王五", "女", 21},
		{647, "赵六", "男", 22},
		{553, "七七", "女", 23}
	};
	for (int temp = 0; temp < 5; temp++) {
		listInsertMember(&Class1_students_info, temp + 1, students[temp], &len1);
		listInsertMember(&Class1_students_info2, temp + 1, students[temp], &len2);
	}
	displayList(Class1_students_info);
	listDeleteMember(&Class1_students_info, 2, &eleme, &len1);
	displayMember(eleme);
	displayList(Class1_students_info);
	locateElem(Class1_students_info, eleme, &len1);
	ElemType eleme2 = {647, "赵六", "男", 22};
	printf("%d\n", locateElem(Class1_students_info, eleme2, &len1));
	listDeleteMember(&Class1_students_info, len1, &eleme, &len1);          //与顺序表不同，这里我们删一下最后一个元素，看会不会出现访问空指针造成的错误
	displayList(Class1_students_info);
	printf("%d", ifListIsEqual(Class1_students_info, Class1_students_info2, &len1, &len2));
	printf("%d", ifListIsEqual(Class1_students_info, Class1_students_info, &len1, &len1));

	return 0;
}
