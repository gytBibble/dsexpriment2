#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100   //线性表存储空间的初始分配量
#define LISTINCREMENT  10    //线性表存储空间的分配增量

typedef int status;
typedef int ElemType; //数据元素类型定义
typedef struct LNode{  //顺序表（链式结构）的定义
	ElemType data; 
	struct LNode *next;
}LNode,*LinkList;

LinkList lists_l[100];

/*12个基本功能*/
status IntiaList(LinkList& L);
status DestroyList(LinkList & L);
status ClearList(LinkList &L);
status ListEmpty(LinkList L);
int ListLength(LinkList L);
status GetElem(LinkList L, int i, ElemType & e);
status LocateElem(LinkList L, ElemType e);
status PriorElem(LinkList L, ElemType cur_e, ElemType & pre_e);
status NextElem(LinkList L, ElemType cur_e, ElemType & next_e);
status ListInsert(LinkList & L, int i, ElemType e);
status ListDelete(LinkList & L, int i, ElemType & e);
status ListTrabverse(LinkList L);
/*文件保存、加载函数*/
status Load_data(LinkList &L,char *filename);
status Save_data(LinkList L,char *filename);
/*多表操作函数*/
status MakeEmpty(LinkList *l);
LinkList ChangeList(LinkList *lists_l, int i);
