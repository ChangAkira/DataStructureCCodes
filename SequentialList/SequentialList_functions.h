#include "total_header.h"
#include"Elemtype.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct {
	ElemType *elem;
	int length;
	int listsize;
} sqList;

void displayMember(ElemType e)
{
	display(e);
}

void displayList(sqList L)
{
	int temp;
	for (temp = 0; temp < L.length; temp++) {
		printf("第%d个数据元素\n",temp+1);
		display(L.elem[temp]);
	}
}


void initList(sqList *L)
{
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem) {
		exit(OVERFLOW);
	}
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
}

int listLength(sqList L)
{
	return L.length;
}

Status ifListIsEmpty(sqList L)
{
	if (L.length == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

Status ifMemberIsEqual(ElemType e1, ElemType e2)
{
	if (compare(e1, e2)) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

Status ifListIsEqual(sqList L1, sqList L2)
{
	if (L1.length != L2.length) {
		return FALSE;
	}
	else {
		int temp;
		for (temp = 0; temp < L1.length; temp++) {
			if (!ifMemberIsEqual(L1.elem[temp], L2.elem[temp])) {
				return FALSE;
			}
		}
		return TRUE;
	}


}

Status listInsertMember(sqList *L, int ip, ElemType newMember)
{
	ElemType* newbase;
	int temp;
	if (ip < 1 || ip > L->length + 1) {
		return ERROR;
	}
	if (L->length >= L->listsize) {
		newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) {
			exit (OVERFLOW);
		}
		L->elem = newbase;
		L->listsize = L->listsize + LISTINCREMENT;
	}
		for (temp = L->length ; temp >= ip; temp--) { //如果ip为3，那么最后一步是
			//第四个元素等于第三个元素。但下标从0开始，也就是elem[3]=elem[2]
			L->elem[temp] = L->elem[temp - 1];
		}
		L->elem[ip - 1] = newMember;
		L->length++;
		return OK;

}

Status listDeleteMember(sqList *L, int ip, ElemType *getIt)
{
	int temp;
	if (ip < 1 || ip > L->length + 1) {
		return ERROR;
	}
	*getIt = L->elem[ip - 1];
	for (temp = ip - 1; temp < L->length - 1; temp++) { //elem下标从0开始。如果ip为3，删除elem[2],elem[2]=elem[3]...
		//最后一步是elem[总长度-2]=[总长度-1]
		L->elem[temp] = L->elem[temp + 1];
	}
	L->length--;
	return OK;
}

Status getElem(sqList L, int ip, ElemType *getIt)
{
	if (ip < 1 || ip > L.length + 1) {
		return ERROR;
	}
	*getIt = L.elem[ip - 1];
	return OK;
}



int locateElem(sqList L, ElemType member)
{
	if (ifListIsEmpty(L)) {
		return ERROR;
	}
	int temp;
	for (temp = 0; temp < L.length; temp++) {
		if (ifMemberIsEqual(L.elem[temp], member)) {
			return temp+1;
		}
	}
	return -1;
}
