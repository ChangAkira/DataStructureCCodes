#include "SequentialList_functions.h"
int main()
{
	sqList Class1_students_info;
	ElemType eleme;
	initList(&Class1_students_info);
	displayList(Class1_students_info);
	ElemType students[] = {
		{123, "����", "��", 22},
		{342, "����", "��", 21},
		{421, "����", "Ů", 21},
		{647, "����", "��", 22},
		{553, "����", "Ů", 23}
	};
	
	for (int temp = 0; temp < 5; temp++) {
		listInsertMember(&Class1_students_info, temp + 1, students[temp]);
	}
	displayList(Class1_students_info);
	listDeleteMember(&Class1_students_info,2,&eleme);
	displayMember(eleme);
	displayList(Class1_students_info);	
	locateElem(Class1_students_info,eleme);
	ElemType eleme2={647, "����", "��", 22};
	printf("%d",locateElem(Class1_students_info,eleme2));

	return 0;
}
