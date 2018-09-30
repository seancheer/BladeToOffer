#pragma once
#include "common.h"
#include "utils.h"
/************************************************************************/
/* 基本的数据结构：二叉树
/************************************************************************/

typedef struct S_Binary_Tree BinaryTree;

enum Node_Type {
	LEFT_NODE,
	RIGHT_NODE,
	ROOT_NODE
};

struct S_Binary_Tree {
	int value;
	BinaryTree* left_child;
	BinaryTree* right_child;
	Node_Type type;
};



const char* get_string_by_type(enum Node_Type& type);

BinaryTree* binary_tree_insert(BinaryTree* node, int value);

BinaryTree* binary_tree_init_header(int value);

BinaryTree* malloc_item(int value);

BinaryTree* binary_tree_remove(BinaryTree* node, int value);

BinaryTree* find_value(BinaryTree* node, int value);

BinaryTree* find_deepest_left(BinaryTree* node);

BinaryTree* find_deepest_right(BinaryTree* node);

void print_tree_hierachy(BinaryTree* node);