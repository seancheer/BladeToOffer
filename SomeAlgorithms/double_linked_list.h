#pragma once
/************************************************************************/
/* 算法中的用到的链表
/************************************************************************/
#include "common.h"
typedef struct S_MY_DOUBLE_LINKED_LIST DoubleLinkedList;

struct S_MY_DOUBLE_LINKED_LIST
{
	int value;
	DoubleLinkedList *next;
	DoubleLinkedList *parent;
};

/************************************************************************/
/* 初始化一个链表
/************************************************************************/
DoubleLinkedList* double_list_init(int header);

/************************************************************************/
/* 在链表末尾增加一个
/************************************************************************/
void double_list_append_value(DoubleLinkedList* header, int value);

/************************************************************************/
/* 根据value malloc一个节点
/************************************************************************/
DoubleLinkedList* double_list_malloc(int value);

/************************************************************************/
/* 清空一个链表
/************************************************************************/
void double_list_empty(DoubleLinkedList* header);


/************************************************************************/
/* 获取最后一个节点
/************************************************************************/
DoubleLinkedList* double_list_get_last_node(DoubleLinkedList* header);

/************************************************************************/
/* 获取指定index的节点
/************************************************************************/
DoubleLinkedList* double_list_get_node_by_index(DoubleLinkedList* header, int index);


/************************************************************************/
/* 从头到尾打印双向链表
/************************************************************************/
void double_list_print(DoubleLinkedList* header);

