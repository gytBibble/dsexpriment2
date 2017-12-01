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
		printf("    请选择你的操作[0~14]:");
		scanf("%d", &op);
		switch (op) {
		case 1:
			if (IntiaList(L) == OK) printf("线性表初始化成功！\n");
			else printf("线性表初始化失败！\n");
			getchar(); getchar();
			break;
		case 2:
			if (L!= NULL)
			{
				if (DestroyList(L) == OK) printf("线性表销毁成功！\n");
				else printf("线性表销毁失败！\n");
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 3:
			if (L!= NULL)
			{
				if (ClearList(L) == OK) printf("线性表清空成功！\n");
				else printf("线性表清空失败！\n");
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 4:
			if (L!= NULL)
			{
				if (ListEmpty(L) == TRUE) printf("该表为空表！\n");
				else printf("该表不为空！\n");
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 5:
			if (L!= NULL)
			{
				int i = 0;
				i = ListLength(L);
				printf("该表的长度为 %d\n", i);
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 6:
			if (L!= NULL)
			{
				int i = 0;
				ElemType e = 0;
				printf("请输入你想知道第几个元素的值：\n");
				scanf_s("%d", &i);
				if (GetElem(L, i, e) == OK) printf("该表中第%d个元素为%d!\n", i, e);
				else printf("输入错误，该表没有第%d个元素！\n", i);
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 7:
			if (L!= NULL)
			{
				ElemType x = 0;
				printf("请输入你想查找的元素：\n");
				scanf_s("%d", &x);
				int i = LocateElem(L, x);
				if (i != 0) printf("该元素存在，且在该表中为第%d位！\n", i);
				else printf("该元素在此表中不存在！\n");
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 8:
			if (L != NULL)
			{
				ElemType pre_e = 0, cur_e = 0;
				printf("请输入你想要获得前驱的元素：\n");
				scanf_s("%d", &cur_e);
				if (PriorElem(L, cur_e, pre_e) == OK) printf("前驱元素为%d\n", pre_e);
				else printf("输入错误，请重新输入！\n");
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 9:
			if (L != NULL)
			{
				ElemType cur_e = 0, next_e = 0;
				printf("请输入你想要获得后继的元素：\n");
				scanf_s("%d", &cur_e);
				if (NextElem(L, cur_e, next_e) == OK) printf("后继元素为%d\n", next_e);
				else printf("输入错误，请重新输入！\n");
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 10:
			if (L != NULL)
			{
				int i = 0;
				ElemType e = 0;
				printf("请输入你想要插入元素的位置：\n");
				scanf_s("%d", &i);
				printf("请输入你想要插入的元素：\n");
				scanf_s("%d", &e);
				if (ListInsert(L, i, e) == OK) printf("插入成功！\n");
				else printf("插入失败！\n");
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 11:
			if (L != NULL)
			{
				if (ListLength(L) != 0) {
					int i = 0;
					ElemType e = 0;
					printf("请输入你想要删除的元素的位置：\n");
					scanf_s("%d", &i);
					if (ListDelete(L, i, e) == OK) printf("删除成功，且删除的元素为%d！\n", e);
					else printf("删除失败！\n");
				}
				else printf("该表为空表！\n");
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 12:
			if (L != NULL)
			{
				if (!ListTrabverse(L)) printf("线性表是空表！\n");
			}
			else printf("该表不存在！\n");
			getchar(); getchar();
			break;
		case 13:
			printf("请输入文件名：\n");
			scanf("%s", filename);
			if (Save_data(L,filename) == OK)printf("文件数据保存成功！\n");
			else printf("文件数据保存失败！\n");
			getchar(); getchar();
			break;
		case 14:
			printf("请输入文件名：\n");
			scanf("%s", filename);
			if (Load_data(L,filename) == OK)printf("文件数据加载成功！\n");
			else printf("文件数据加载失败！\n");
			getchar(); getchar();
			break;
		case 0:
			break;
		}//end of switch

	}//end of while
	printf("欢迎下次再使用本系统！\n");
}//end of main()
status IntiaList(LinkList& L)
{
	L = (LinkList)malloc(sizeof(LNode));
	if (!L) return ERROR;//内存分配失败；
	L->next = NULL;
	return OK;
}
status DestroyList(LinkList & L)
{//释放所有结点的内存
	LinkList P, Tmp;
	P = L;
	while (P!=NULL)
	{//逐个释放表的内存
		Tmp = P->next;
		free(P);
		P = Tmp;
	}
	return OK;
}
status ClearList(LinkList &L)
{//释放除表头结点之外所有结点的内存，并使表头指向空
	LinkList P, Tmp;
	P = L->next;
	L->next = NULL;
	while (P != NULL)
	{//逐个释放表的内存
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
	int n = 0;//计数器
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
	//L为带头节点的单链表的头指针
	//当第i个元素存在时，其值赋给e并返回Ok，否则返回ERROR
	int j;
	LinkList p;
	p = L->next; j = 1;        //初始化，p指向第一个结点，j为计数器
	while (p&&j<i)             //顺指针向后查找，直到P指向第i个元素或p为空
	{
		p = p->next;
		++j;
	}
	if (!p || j > i) return ERROR;  //第i个元素不存在
	e = p->data;
	return OK;
}
status LocateElem(LinkList L, ElemType e)
{//返回e在链表中的位置
	int n = 1;//计数器
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
	if (i == 0 || i == 1) return ERROR;//该元素不在此表中或为第一个元素
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
	if (i == 0 || i == ListLength(L)) return ERROR;//该元素不在此表中或为最后一个元素
	for (int j = 0; j < i; j++)p = p->next;
	next_e = p->data;
	return OK;
}
status ListInsert(LinkList & L, int i, ElemType e)
{
	//在带头结点的单链表L中第i个元素之前插入元素e
	int j;
	LinkList p,s;
	p = L; j = 0;
	while (p&&j<i-1)//寻找第i-1个结点
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return ERROR;//i小于1或大于表长加1
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e; s->next = p->next; p->next = s;//插入L中
	return OK;
}
status ListDelete(LinkList & L, int i, ElemType & e)
{
	//在带头结点的单链表L中,删除第i个元素，并用e返回删除元素
	int j;
	LinkList p,q;
	p = L; j = 0;
	while (p->next&&j<i-1)//寻找第i个结点，并令p指向其前驱
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1) return ERROR;//删除位置不合理
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