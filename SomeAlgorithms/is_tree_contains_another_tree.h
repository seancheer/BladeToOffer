#pragma once
#include "binary_tree.h"
/************************************************************************/
/* �ж�һ�����Ƿ�Ϊ����һ�������ӽṹ
/************************************************************************/
bool is_tree_contains_another(BinaryTree* tree_a, BinaryTree* tree_b);

bool is_tree_contains_another_internal(BinaryTree* tree_a, BinaryTree* tree_b);

bool is_tree_a_contains_tree_b(BinaryTree* tree_a, BinaryTree* tree_b);

/************************************************************************/
/* �㷨���
/************************************************************************/
void start_is_tree_contains_another();