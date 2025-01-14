//����ֻ�е���������ͷ�ڵ㲻�������ݡ��α����ᵽͷ�ڵ�����Դ�һ������ĳ��ȣ�����ʵ��Ҫ�����ǵ�elemTypeҲ������һ�����֣���˲�ʵ�á�

#include"total_header.h"
#include"ElemType.h"

struct chainListNode {                          //��˳���ͬ�������У��ṹ�嶨�����һ���ڵ㣬��˳����ж�����ǵ�һ��Ԫ�ص�λ�ã��������Ԫ����˳�����еģ���ʵ�������Ϊ˳����еĽṹ�岿�־��Ƕ�����������
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
			printf("��%d������Ԫ��\n", temp);
			display(N.data);
			N = *(N.nextNode);
			temp++;
		}
		printf("��%d������Ԫ��\n", temp);
		display(N.data);
	}

}

void initList(struct chainListNode *N) 			//���ﴫ��Ĳ�����һ���ڵ㣨��ʵ����ͷ�ڵ㣩��ָ��
{
	struct chainListNode *T = (struct chainListNode*)malloc(sizeof(struct chainListNode));
	if (!T) {
		exit(OVERFLOW);
	}
	T->nextNode = NULL;
	*N = *T;
}



int listLength(struct chainListNode N)           //�������Ȳ���Ҫ�������ڲ��������޸ģ���˲���Ҫ��ָ���ȥ������Ҳ��һ���ģ��������ͷ�ڵ㡣
{
	int len = 0;
	while (N.nextNode != NULL) {
		N = *(N.nextNode);
		len++;
	}
	return len;
}

Status ifListIsEmpty(struct chainListNode N)    ////�󡭡�������Ҫ�������ڲ��������޸ģ���˲���Ҫ��ָ���ȥ������Ҳ��һ���ģ��������ͷ�ڵ㡣
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
				if (temp != *len1) {       //��ֹ���ʿ�ָ��
					N1 = *(N1.nextNode);
					N2 = *(N2.nextNode);
				}

			}
		}
		return TRUE;
	}
}

Status listInsertMember(struct chainListNode *N, int ip, ElemType newMember, int *len)    //����ǽ�len = listLength(N)��Ϊ�������룬�����ж�ip�Ƿ�Ϸ�ʱ����Ҫ����һ��len��Ҳ���Ǳ���һ������������ʱ�临�Ӷȡ��α��ϵ�������ֱ����ip��Ӧ�Ľڵ㣬�Ҳ����Ļ���Ϊ���ǷǷ��ģ�����дͬ�����Ա���Ϊ���󳤶ȶ�����һ��������д�����Ƚ��鷳�������������ڴ���len������˳�������Ӻ�ɾ��Ԫ�ص�ʱ��len��Ӧ�ı䣬��ֹ����������lenֵ���Ǿɵ�ֵ�Ĵ���
{
	if (ip < 1 || ip > *len + 1) {
		return ERROR;
	}
	int temp;
	struct chainListNode* N_new_prior = N;                         //�²���ڵ����һ���ڵ�ĵ�ַ�����������������������Ҫ�ӵ�һ���ڵ㿪ʼ�������ܵõ���
	struct chainListNode* N_new_next;

	struct chainListNode* N_new = (struct chainListNode*)malloc(sizeof(struct chainListNode));  //N_new���½ڵ��ָ��
	N_new->data = newMember;
	for (temp = 0; temp < ip - 1; temp++) {                           //����Ҫ�Լ���ͼ��⡣��������Ҫ�������е�����λ�ò���һ��Ԫ�أ���һ��temp=0�����������õ�N���ָ���Ӧ�Ľڵ㣨ͷ�ڵ㣩��nextNode��ָ�룬����һ���ڵ����ڵĵ�ַ����ע��ͷ�ڵ����ǲ��洢���ݵģ����ǿ��԰�������0�Žڵ㣩Ȼ��temp=1������ѭ���������õ���һ���ڵ��nextNodeָ�룬���ڶ����ڵ�����λ�á�����Ҫ�ڵ������ڵ㴦����һ���ڵ㣨������½ڵ��Ϊ���ţ�ԭ�������ű���ĺţ���Ҫ�޸ĵľ���ԭ���ĵڶ����ڵ��nextNodeָ�룬��˴�ʱ����ѭ��������ipΪ3ʱ��tempȡֵΪ0~1����temp<ip-1
		N_new_prior = N_new_prior->nextNode;
	}
	N_new_next = N_new_prior->nextNode;        //�����õ�ԭ�������Žڵ�λ�ã���ԭ���Ķ��Žڵ��nextNodeָ�롣
	N_new_prior->nextNode = N_new;                               //���ڿ�ʼ���в���
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
	struct chainListNode* N_del_prior = N;                         //Ҫɾ���Ľڵ����һ���ڵ�ĵ�ַ�����������������������Ҫ�ӵ�һ���ڵ㿪ʼ�������ܵõ���
	struct chainListNode* N_del_next;
	for (temp = 0; temp < ip - 1; temp++) {                           //������Ĳ��뺯�����ƣ���ͼ��⡣
		N_del_prior = N_del_prior->nextNode;
	}
	*getIt = (N_del_prior->nextNode)->data;                    //N_del_prior����һ���ڵ��data��ֵ��getItָ��Ľ�����
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
	N = *(N.nextNode);                   //ͷ�ڵ�Ͳ����ˣ��ӵ�һ���ڵ㿪ʼ
	for (temp = 1; temp <= *len; temp++) {
		if (ifMemberIsEqual(N.data, member)) {
			return temp;
		}
		else {
			if (temp != *len) {
				N = *(N.nextNode);           //��ֹ���ʿ�ָ��
			}
		}
	}
	return -1;
}
