#pragma once
#include "linked_list.h"
/************************************************************************/
/* ����һ��ͷ��㣬���������м�Ľڵ㣺
/* 1 �������Ϊ��������ô�����м�Ľڵ�
/* 2 �������Ϊż�����������м������ڵ��������һ��
/************************************************************************/

LinkedList* find_middle_node_in_list(LinkedList* header);

LinkedList* forward_node(LinkedList* pos, int step);

void start_find_middle_node_in_list();
