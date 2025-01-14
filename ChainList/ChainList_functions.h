//这里只有单链表，并且头节点不保存数据。课本上提到头节点里可以存一个链表的长度，但其实这要求我们的elemType也必须是一个数字，因此不实用。

#include"total_header.h"
#include"ElemType.h"

struct chainListNode {                          //与顺序表不同，链表中，结构体定义的是一个节点，而顺序表中定义的是第一个元素的位置，而后面的元素是顺序排列的，其实可以理解为顺序表中的结构体部分就是定义了整个表
	ElemType data;
	struct chainListNode *nextNode;
};

void displayMember(ElemType e)
{
	display(e);
}

void displayList(struct chainListNode N)
{
	if (N.nextNode == NULL) {

	}
	else {
		int temp = 1;
		N = *(N.nextNode);
		while (N.nextNode != NULL) {
			printf("第%d个数据元素\n", temp);
			display(N.data);
			N = *(N.nextNode);
			temp++;
		}
		printf("第%d个数据元素\n", temp);
		display(N.data);
	}

}

void initList(struct chainListNode *N) 			//这里传入的参数是一个节点（其实就是头节点）的指针
{
	struct chainListNode *T = (struct chainListNode*)malloc(sizeof(struct chainListNode));
	if (!T) {
		exit(OVERFLOW);
	}
	T->nextNode = NULL;
	*N = *T;
}



int listLength(struct chainListNode N)           //求链表长度不需要对链表内部数据做修改，因此不需要传指针进去。这里也是一样的，传入的是头节点。
{
	int len = 0;
	while (N.nextNode != NULL) {
		N = *(N.nextNode);
		len++;
	}
	return len;
}

Status ifListIsEmpty(struct chainListNode N)    ////求………不需要对链表内部数据做修改，因此不需要传指针进去。这里也是一样的，传入的是头节点。
{
	if (N.nextNode == NULL) {
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

Status ifListIsEqual(struct chainListNode N1, struct chainListNode N2, int *len1, int *len2)
{
	if (N1.nextNode == NULL && N2.nextNode == NULL) {
		return TRUE;
	}
	if (*len1 != *len2) {
		return FALSE;
	}
	else {
		int temp;
		N1 = *(N1.nextNode);
		N2 = *(N2.nextNode);
		for (temp = 1; temp < *len1 + 1; temp++) {
			if (!ifMemberIsEqual(N1.data, N2.data)) {
				return FALSE;
			}
			else {
				if (temp != *len1) {       //防止访问空指针
					N1 = *(N1.nextNode);
					N2 = *(N2.nextNode);
				}

			}
		}
		return TRUE;
	}
}

Status listInsertMember(struct chainListNode *N, int ip, ElemType newMember, int *len)    //最好是将len = listLength(N)作为参数传入，否则判断ip是否合法时还需要计算一次len，也就是遍历一遍链表，增加了时间复杂度。课本上的做法是直接找ip对应的节点，找不到的话认为它是非法的，这样写同样可以避免为了求长度而遍历一遍链表，但写起来比较麻烦。并且我们现在传入len，可以顺便在增加和删除元素的时候将len对应改变，防止了主程序中len值还是旧的值的错误。
{
	if (ip < 1 || ip > *len + 1) {
		return ERROR;
	}
	int temp;
	struct chainListNode* N_new_prior = N;                         //新插入节点的上一个节点的地址。由于链表的特征，我们需要从第一个节点开始遍历才能得到它
	struct chainListNode* N_new_next;

	struct chainListNode* N_new = (struct chainListNode*)malloc(sizeof(struct chainListNode));  //N_new是新节点的指针
	N_new->data = newMember;
	for (temp = 0; temp < ip - 1; temp++) {                           //这里要自己画图理解。假设我们要在链表中第三个位置插入一个元素，第一次temp=0进来，我们拿到N这个指针对应的节点（头节点）的nextNode的指针，即第一个节点所在的地址。（注意头节点中是不存储数据的，我们可以把它当作0号节点）然后temp=1，进入循环，我们拿到第一个节点的nextNode指针，即第二个节点所在位置。我们要在第三个节点处插入一个节点（插入的新节点变为三号，原来的三号变成四号），要修改的就是原来的第二个节点的nextNode指针，因此此时跳出循环。所以ip为3时，temp取值为0~1，即temp<ip-1
		N_new_prior = N_new_prior->nextNode;
	}
	N_new_next = N_new_prior->nextNode;        //接着拿到原来的三号节点位置，即原来的二号节点的nextNode指针。
	N_new_prior->nextNode = N_new;                               //现在开始进行插入
	N_new->nextNode = N_new_next;
	*len = *len + 1;
	return OK;
}

Status listDeleteMember(struct chainListNode *N, int ip, ElemType *getIt, int *len)
{
	if (ip < 1 || ip > *len) {
		return ERROR;
	}
	int temp;
	struct chainListNode* N_del_prior = N;                         //要删除的节点的上一个节点的地址。由于链表的特征，我们需要从第一个节点开始遍历才能得到它
	struct chainListNode* N_del_next;
	for (temp = 0; temp < ip - 1; temp++) {                           //跟上面的插入函数类似，画图理解。
		N_del_prior = N_del_prior->nextNode;
	}
	*getIt = (N_del_prior->nextNode)->data;                    //N_del_prior的下一个节点的data赋值给getIt指针的解引用
	N_del_next = N_del_prior->nextNode->nextNode;
	free(N_del_prior->nextNode);
	N_del_prior->nextNode = N_del_next;

	*len = *len - 1;
	return OK;
}

Status getElem(struct chainListNode N, int ip, ElemType *getIt, int *len)
{
	if (ip < 1 || ip > *len) {
		return ERROR;
	}
	int temp;
	for (temp = 0; temp < ip; temp++) {
		N = *(N.nextNode);
	}
	*getIt = N.data;
	return OK;
}

int locateElem(struct chainListNode N, ElemType member, int *len)
{
	if (ifListIsEmpty(N)) {
		return ERROR;
	}
	int temp;
	N = *(N.nextNode);                   //头节点就不看了，从第一个节点开始
	for (temp = 1; temp <= *len; temp++) {
		if (ifMemberIsEqual(N.data, member)) {
			return temp;
		}
		else {
			if (temp != *len) {
				N = *(N.nextNode);           //防止访问空指针
			}
		}
	}
	return -1;
}
