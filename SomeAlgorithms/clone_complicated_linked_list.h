#pragma once
#include "linked_list.h"
#include "utils.h"
/************************************************************************/
/* 复制复杂链表，即链表除了next指针外，还包括一个sibling指针，该指针指向
/* 链表中的任意节点，也包括NULL
/************************************************************************/

/************************************************************************/
/* 负责克隆目标链表，并返回一个clone后的链表结构
/************************************************************************/
LinkedList* clone_complicated_linked_list(LinkedList* your_list);

void double_list(LinkedList* your_list);

void adjust_sibling(LinkedList* your_list);

LinkedList* get_copiedlist_and_restore_originlist(LinkedList* your_list);

/************************************************************************/
/* 开始算法
/************************************************************************/
void start_clone_complicated_list();
