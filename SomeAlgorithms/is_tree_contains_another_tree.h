#pragma once
#include "binary_tree.h"
/************************************************************************/
/* 判断一个树是否为另外一个树的子结构
/************************************************************************/
bool is_tree_contains_another(BinaryTree* tree_a, BinaryTree* tree_b);

bool is_tree_contains_another_internal(BinaryTree* tree_a, BinaryTree* tree_b);

bool is_tree_a_contains_tree_b(BinaryTree* tree_a, BinaryTree* tree_b);

/************************************************************************/
/* 算法入口
/************************************************************************/
void start_is_tree_contains_another();