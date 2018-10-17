#include "stack_with_min.h"
using namespace std;
stack<int> s;
stack<int> s_helper;

/************************************************************************/
/* 实现一个带有min方法的stack，使得pop，push，min的时间复杂度均为O(1)
/* 思路：使用一个辅助栈，当压栈的时候，如果对应的value小于等于栈顶，那么也放在栈中，
/* 否则，不进行任何处理。当出栈的时候，如果发现出的值等于辅助栈顶，那么同时辅助栈也出栈，
/* 这样子可以保证辅助栈的栈顶始终是最小值。
/************************************************************************/

/************************************************************************/
/* push方法
/************************************************************************/
void stack_with_min_push(int value)
{
	s.push(value);
	if (s_helper.empty())
	{
		s_helper.push(value);
		return;
	}
	

	int cur_min = s_helper.top();
	if (value <= cur_min)
	{
		s_helper.push(value);
	}
}

/************************************************************************/
/*
/* pop方法
/************************************************************************/
int stack_with_min_pop()
{
	if (s.empty())
	{
		puts("Stack is Empty!");
		return -1;
	}

	int pop_value = s.top();
	int cur_min = s_helper.top();
	if (pop_value == cur_min)
	{
		s_helper.pop();
	}

	s.pop();
	return pop_value;
}

/************************************************************************/
/* min方法
/************************************************************************/
int stack_with_min_min()
{
	if (s.empty())
	{
		puts("Stack is empty!");
		return -1;
	}

	return s_helper.top();
}


/************************************************************************/
/* destroy方法
/************************************************************************/
int stack_with_min_destroy()
{
	s.empty();
	s_helper.empty();
	return 0;
}


/************************************************************************/
/* 开始算法
/************************************************************************/
void start_test_stack_with_min()
{
	int arr[] = { 3,4,1 };
	for (int i = 0; i < 3; ++i)
	{
		stack_with_min_push(arr[i]);
	}

	int min_value = stack_with_min_min();
	printf("Current min value:%d!\n", min_value);
	stack_with_min_pop();
	min_value = stack_with_min_min();
	printf("Current min value:%d!\n", min_value);

	stack_with_min_pop();
	min_value = stack_with_min_min();
	printf("Current min value:%d!\n", min_value);
	stack_with_min_destroy();
}