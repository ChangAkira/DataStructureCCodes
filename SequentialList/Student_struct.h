#include"total_header.h"
struct Student {
	int num;
	char name[20];
	char sex[10];
	int age;
};
//��Ҫ����һ�ض��Ľṹ������дһ���Ƚ����ṹ���Ƿ���ͬ�Ĺ��ܡ��ڲ�ͬ�����ݽṹ�У���һ��������ʹ������ȽϺ�����
//�����Ա��е�ifListIsEqual()������compare()�������е�ifListIsEqual()����Ҳ��compare()��
//Ҫ�ı�ʹ�õ�����Ԫ�ض��壬�罫��ѧ������Ϊ����ʦ����дһ����ʦ�ṹ���ͷ�ļ���д����ʦ��compare������
//��ElemType.h���滻typedef Student ElemType;Ϊtypedef Teacher ElemType;���ɡ�
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
//�����дһ��������ܡ��������ԭ����һ���ġ�
void display(struct Student Student1)
{
	printf("ѧ�ţ�%d\t������%s\t�Ա�%s\t���䣺%d\n", Student1.num, Student1.name, Student1.sex, Student1.age);
}
