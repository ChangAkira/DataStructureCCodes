#include "total_header.h"
#include"Elemtype.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
struct sqList {
	ElemType *elem;
	int length;
	int listsize;
};

void displayMember(ElemType e)
{
	display(e);
}

void displayList(struct sqList L)
{
	int temp;
	for (temp = 0; temp < L.length; temp++) {
		printf("��%d������Ԫ��\n", temp + 1);
		display(L.elem[temp]);
	}
}


void initList(struct sqList *L)
{
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem) {
		exit(OVERFLOW);
	}
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
}

int listLength(struct sqList L)
{
	return L.length;
}

Status ifListIsEmpty(struct sqList L)
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

Status ifListIsEqual(struct sqList L1, struct sqList L2)
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

Status listInsertMember(struct sqList *L, int ip, ElemType newMember)
{
	if (ip < 1 || ip > L->length + 1) {
		return ERROR;
	}
	ElemType* newbase;
	int temp;

	if (L->length >= L->listsize) {
		newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) {
			exit (OVERFLOW);
		}
		L->elem = newbase;
		L->listsize = L->listsize + LISTINCREMENT;
	}
	for (temp = L->length ; temp >= ip; temp--) { //���ipΪ3����ô���һ����
		//���ĸ�Ԫ�ص��ڵ�����Ԫ�ء����±��0��ʼ��Ҳ����elem[3]=elem[2]
		L->elem[temp] = L->elem[temp - 1];
	}
	L->elem[ip - 1] = newMember;
	L->length++;
	return OK;

}

Status listDeleteMember(struct sqList *L, int ip, ElemType *getIt)
{
	if (ip < 1 || ip > L->length + 1) {
		return ERROR;
	}
	int temp;

	*getIt = L->elem[ip - 1];
	for (temp = ip - 1; temp < L->length - 1; temp++) { //elem�±��0��ʼ�����ipΪ3��ɾ��elem[2],elem[2]=elem[3]...
		//���һ����elem[�ܳ���-2]=[�ܳ���-1]
		L->elem[temp] = L->elem[temp + 1];
	}
	L->length--;
	return OK;
}

Status getElem(struct sqList L, int ip, ElemType *getIt)
{
	if (ip < 1 || ip > L.length + 1) {
		return ERROR;
	}
	*getIt = L.elem[ip - 1];
	return OK;
}



int locateElem(struct sqList L, ElemType member)
{
	if (ifListIsEmpty(L)) {
		return ERROR;
	}
	int temp;
	for (temp = 0; temp < L.length; temp++) {
		if (ifMemberIsEqual(L.elem[temp], member)) {
			return temp + 1;
		}
	}
	return -1;
}
