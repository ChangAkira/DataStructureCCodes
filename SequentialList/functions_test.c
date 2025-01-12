#include "SequentialList_functions.h"
int main()
{
	struct sqList Class1_students_info;
	initList(&Class1_students_info);
	struct sqList Class1_students_info2;
	initList(&Class1_students_info2);
	ElemType eleme;
	displayList(Class1_students_info);
	ElemType students[] = {
		{123, "张三", "男", 22},
		{342, "李四", "男", 21},
		{421, "王五", "女", 21},
		{647, "赵六", "男", 22},
		{553, "七七", "女", 23}
	};
	
	for (int temp = 0; temp < 5; temp++) {
		listInsertMember(&Class1_students_info, temp + 1, students[temp]);
		listInsertMember(&Class1_students_info2, temp + 1, students[temp]);
	}
	displayList(Class1_students_info);
	listDeleteMember(&Class1_students_info,2,&eleme);
	displayMember(eleme);
	displayList(Class1_students_info);	
	locateElem(Class1_students_info,eleme);
	ElemType eleme2={647, "赵六", "男", 22};
	printf("%d\n",locateElem(Class1_students_info,eleme2));
	printf("%d",ifListIsEqual(Class1_students_info,Class1_students_info2));
	printf("%d",ifListIsEqual(Class1_students_info,Class1_students_info));
	return 0;
}
