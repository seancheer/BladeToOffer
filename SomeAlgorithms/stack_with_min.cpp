#include "stack_with_min.h"
using namespace std;
stack<int> s;
stack<int> s_helper;

/************************************************************************/
/* ʵ��һ������min������stack��ʹ��pop��push��min��ʱ�临�ӶȾ�ΪO(1)
/* ˼·��ʹ��һ������ջ����ѹջ��ʱ�������Ӧ��valueС�ڵ���ջ������ôҲ����ջ�У�
/* ���򣬲������κδ�������ջ��ʱ��������ֳ���ֵ���ڸ���ջ������ôͬʱ����ջҲ��ջ��
/* �����ӿ��Ա�֤����ջ��ջ��ʼ������Сֵ��
/************************************************************************/

/************************************************************************/
/* push����
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
/* pop����
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
/* min����
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
/* destroy����
/************************************************************************/
int stack_with_min_destroy()
{
	s.empty();
	s_helper.empty();
	return 0;
}


/************************************************************************/
/* ��ʼ�㷨
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