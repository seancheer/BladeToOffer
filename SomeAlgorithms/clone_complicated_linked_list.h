#pragma once
#include "linked_list.h"
#include "utils.h"
/************************************************************************/
/* ���Ƹ����������������nextָ���⣬������һ��siblingָ�룬��ָ��ָ��
/* �����е�����ڵ㣬Ҳ����NULL
/************************************************************************/

/************************************************************************/
/* �����¡Ŀ������������һ��clone�������ṹ
/************************************************************************/
LinkedList* clone_complicated_linked_list(LinkedList* your_list);

void double_list(LinkedList* your_list);

void adjust_sibling(LinkedList* your_list);

LinkedList* get_copiedlist_and_restore_originlist(LinkedList* your_list);

/************************************************************************/
/* ��ʼ�㷨
/************************************************************************/
void start_clone_complicated_list();
