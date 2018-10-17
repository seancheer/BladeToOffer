#pragma once
#include "linked_list.h"
/************************************************************************/
/* 给定一个头结点，返回链表中间的节点：
/* 1 如果个数为奇数，那么返回中间的节点
/* 2 如果个数为偶数，返回最中间两个节点中任意的一个
/************************************************************************/

LinkedList* find_middle_node_in_list(LinkedList* header);

LinkedList* forward_node(LinkedList* pos, int step);

void start_find_middle_node_in_list();
