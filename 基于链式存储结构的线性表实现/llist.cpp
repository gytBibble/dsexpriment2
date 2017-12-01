#include"llist.h"
void main(void) {
	LinkList L=NULL;
	int op = 1;
	char filename[40];
	while (op) {
		system("cls");	
		
		printf("\n\n");
		printf("      Menu for Linear Table On Link Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. IntiaList       7. LocateElem\n");
		printf("    	  2. DestroyList     8. PriorElem\n");
		printf("    	  3. ClearList       9. NextElem \n");
		printf("    	  4. ListEmpty       10. ListInsert\n");
		printf("    	  5. ListLength      11. ListDelete\n");
		printf("    	  6. GetElem         12. ListTrabverse\n");
		printf("    	  13. SavaData       14. LoadData\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    ��ѡ����Ĳ���[0~14]:");
		scanf("%d", &op);
		switch (op) {
		case 1:
			if (IntiaList(L) == OK) printf("���Ա��ʼ���ɹ���\n");
			else printf("���Ա��ʼ��ʧ�ܣ�\n");
			getchar(); getchar();
			break;
		case 2:
			if (L!= NULL)
			{
				if (DestroyList(L) == OK) printf("���Ա����ٳɹ���\n");
				else printf("���Ա�����ʧ�ܣ�\n");
			}
			else printf("�ñ����ڣ�\n");
			getchar(); getchar();
			break;
		case 3:
			if (L!= NULL)
			{
				if (ClearList(L) == OK) printf("���Ա���ճɹ���\n");
				else printf("���Ա����ʧ�ܣ�\n");
			}
			else printf("�ñ����ڣ�\n");
			getchar(); getchar();
			break;
		case 4:
			if (L!= NULL)
			{
				if (ListEmpty(L) == TRUE) printf("�ñ�Ϊ�ձ�\n");
				else printf("�ñ�Ϊ�գ�\n");
			}
			else printf("�ñ����ڣ�\n");
			getchar(); getchar();
			break;
		case 5:
			if (L!= NULL)
			{
				int i = 0;
				i = ListLength(L);
				printf("�ñ�ĳ���Ϊ %d\n", i);
			}
			else printf("�ñ����ڣ�\n");
			getchar(); getchar();
			break;
		case 6:
			if (L!= NULL)
			{
				int i = 0;
				ElemType e = 0;
				printf("����������֪���ڼ���Ԫ�ص�ֵ��\n");
				scanf_s("%d", &i);
				if (GetElem(L, i, e) == OK) printf("�ñ��е�%d��Ԫ��Ϊ%d!\n", i, e);
				else printf("������󣬸ñ�û�е�%d��Ԫ�أ�\n", i);
			}
			else printf("�ñ����ڣ�\n");
			getchar(); getchar();
			break;
		case 7:
			if (L!= NULL)
			{
				ElemType x = 0;
				printf("������������ҵ�Ԫ�أ�\n");
				scanf_s("%d", &x);
				int i = LocateElem(L, x);
				if (i != 0) printf("��Ԫ�ش��ڣ����ڸñ���Ϊ��%dλ��\n", i);
				else printf("��Ԫ���ڴ˱��в����ڣ�\n");
			}
			else printf("�ñ����ڣ�\n");
			getchar(); getchar();
			break;
		case 8:
			if (L != NULL)
			{
				ElemType pre_e = 0, cur_e = 0;
				printf("����������Ҫ���ǰ����Ԫ�أ�\n");
				scanf_s("%d", &cur_e);
				if (PriorElem(L, cur_e, pre_e) == OK) printf("ǰ��Ԫ��Ϊ%d\n", pre_e);
				else printf("����������������룡\n");
			}
			else printf("�ñ����ڣ�\n");
			getchar(); getchar();
			break;
		case 9:
			if (L != NULL)
			{
				ElemType cur_e = 0, next_e = 0;
				printf("����������Ҫ��ú�̵�Ԫ�أ�\n");
				scanf_s("%d", &cur_e);
				if (NextElem(L, cur_e, next_e) == OK) printf("���Ԫ��Ϊ%d\n", next_e);
				else printf("����������������룡\n");
			}
			else printf("�ñ����ڣ�\n");
			getchar(); getchar();
			break;
		case 10:
			if (L != NULL)
			{
				int i = 0;
				ElemType e = 0;
				printf("����������Ҫ����Ԫ�ص�λ�ã�\n");
				scanf_s("%d", &i);
				printf("����������Ҫ�����Ԫ�أ�\n");
				scanf_s("%d", &e);
				if (ListInsert(L, i, e) == OK) printf("����ɹ���\n");
				else printf("����ʧ�ܣ�\n");
			}
			else printf("�ñ����ڣ�\n");
			getchar(); getchar();
			break;
		case 11:
			if (L != NULL)
			{
				if (ListLength(L) != 0) {
					int i = 0;
					ElemType e = 0;
					printf("����������Ҫɾ����Ԫ�ص�λ�ã�\n");
					scanf_s("%d", &i);
					if (ListDelete(L, i, e) == OK) printf("ɾ���ɹ�����ɾ����Ԫ��Ϊ%d��\n", e);
					else printf("ɾ��ʧ�ܣ�\n");
				}
				else printf("�ñ�Ϊ�ձ�\n");
			}
			else printf("�ñ����ڣ�\n");
			getchar(); getchar();
			break;
		case 12:
			if (L != NULL)
			{
				if (!ListTrabverse(L)) printf("���Ա��ǿձ�\n");
			}
			else printf("�ñ����ڣ�\n");
			getchar(); getchar();
			break;
		case 13:
			printf("�������ļ�����\n");
			scanf("%s", filename);
			if (Save_data(L,filename) == OK)printf("�ļ����ݱ���ɹ���\n");
			else printf("�ļ����ݱ���ʧ�ܣ�\n");
			getchar(); getchar();
			break;
		case 14:
			printf("�������ļ�����\n");
			scanf("%s", filename);
			if (Load_data(L,filename) == OK)printf("�ļ����ݼ��سɹ���\n");
			else printf("�ļ����ݼ���ʧ�ܣ�\n");
			getchar(); getchar();
			break;
		case 0:
			break;
		}//end of switch

	}//end of while
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()
status IntiaList(LinkList& L)
{
	L = (LinkList)malloc(sizeof(LNode));
	if (!L) return ERROR;//�ڴ����ʧ�ܣ�
	L->next = NULL;
	return OK;
}
status DestroyList(LinkList & L)
{//�ͷ����н����ڴ�
	LinkList P, Tmp;
	P = L;
	while (P!=NULL)
	{//����ͷű���ڴ�
		Tmp = P->next;
		free(P);
		P = Tmp;
	}
	return OK;
}
status ClearList(LinkList &L)
{//�ͷų���ͷ���֮�����н����ڴ棬��ʹ��ͷָ���
	LinkList P, Tmp;
	P = L->next;
	L->next = NULL;
	while (P != NULL)
	{//����ͷű���ڴ�
		Tmp = P->next;
		free(P);
		P = Tmp;
	}
	return OK;
}
status ListEmpty(LinkList L)
{
	if (L->next == NULL) return OK;
	return ERROR;
}
int ListLength(LinkList L)
{
	int n = 0;//������
	LinkList p;
	p = L->next;
	while (p!=NULL)
	{
		p = p->next;
		n++;
	}
	return n;
}
status GetElem(LinkList L, int i, ElemType & e)
{
	//LΪ��ͷ�ڵ�ĵ������ͷָ��
	//����i��Ԫ�ش���ʱ����ֵ����e������Ok�����򷵻�ERROR
	int j;
	LinkList p;
	p = L->next; j = 1;        //��ʼ����pָ���һ����㣬jΪ������
	while (p&&j<i)             //˳ָ�������ң�ֱ��Pָ���i��Ԫ�ػ�pΪ��
	{
		p = p->next;
		++j;
	}
	if (!p || j > i) return ERROR;  //��i��Ԫ�ز�����
	e = p->data;
	return OK;
}
status LocateElem(LinkList L, ElemType e)
{//����e�������е�λ��
	int n = 1;//������
	LinkList p;
	p = L->next;
	while (p!=NULL && p->data!= e)
	{
		++n;
		p = p->next;
	}
	if (n == 0 || n > ListLength(L)) return ERROR;
	return n;
}
status PriorElem(LinkList L, ElemType cur_e, ElemType & pre_e)
{
	int i=0;
	LinkList p;
	i = LocateElem(L,cur_e);
	p = L->next;
	if (i == 0 || i == 1) return ERROR;//��Ԫ�ز��ڴ˱��л�Ϊ��һ��Ԫ��
	for (int j = 0; j < i-2; j++)
	{
		p = p->next;
	}
	pre_e = p->data;
	return OK;
}
status NextElem(LinkList L, ElemType cur_e, ElemType & next_e)
{
	int i = 0;
	LinkList p;
	i = LocateElem(L, cur_e);
	p = L->next;
	if (i == 0 || i == ListLength(L)) return ERROR;//��Ԫ�ز��ڴ˱��л�Ϊ���һ��Ԫ��
	for (int j = 0; j < i; j++)p = p->next;
	next_e = p->data;
	return OK;
}
status ListInsert(LinkList & L, int i, ElemType e)
{
	//�ڴ�ͷ���ĵ�����L�е�i��Ԫ��֮ǰ����Ԫ��e
	int j;
	LinkList p,s;
	p = L; j = 0;
	while (p&&j<i-1)//Ѱ�ҵ�i-1�����
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return ERROR;//iС��1����ڱ���1
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e; s->next = p->next; p->next = s;//����L��
	return OK;
}
status ListDelete(LinkList & L, int i, ElemType & e)
{
	//�ڴ�ͷ���ĵ�����L��,ɾ����i��Ԫ�أ�����e����ɾ��Ԫ��
	int j;
	LinkList p,q;
	p = L; j = 0;
	while (p->next&&j<i-1)//Ѱ�ҵ�i����㣬����pָ����ǰ��
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1) return ERROR;//ɾ��λ�ò�����
	q = p->next; p->next = q->next;
	e = q->data;
	free(q);
	return OK;
}
status ListTrabverse(LinkList L)
{
	int i;
	LinkList p;
	p = L->next;
	printf("\n-------------------- all elements ------------------------------\n");
	for (i = 0; i < ListLength(L); i++)
	{
		printf("%d ", p->data);
		p=p->next;
	}
	printf("\n------------------------- end ----------------------------------\n");
	return OK;
}
status Load_data(LinkList &L, char *filename)
{
	int length = 0;
	FILE *fp;
	LinkList p,q;
	q = L;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("File open error!\n ");
		return ERROR;
	}
	fscanf(fp, "%d", &length);
	for (int i = 0; i < length; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		p->next = NULL;
		q->next = p;
		fscanf(fp, "%d", &p->data);
		q = p;
	}
	fclose(fp);
	return TRUE;
}
status Save_data(LinkList L, char *filename) {
	FILE *fp;
	LinkList p;
	p = L->next;
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("File open error!\n ");
		return ERROR;
	}
	fprintf(fp, "%d", ListLength(L));
	for (int i = 0; i < ListLength(L); i++)
	{
		fprintf(fp, "\t%d", p->data);
		p = p->next;
	}
	fclose(fp);
	return OK;
}

status MakeEmpty(LinkList *l)
{
	for (int i = 0; i < 100; i++)
	{
		l[i] = NULL;
	}
	return OK;
}
LinkList ChangeList(LinkList *lists_l, int i)
{

}