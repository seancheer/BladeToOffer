#include "implement_queue_by_stack.h"

std::stack<int> main_stack;
std::stack<int> helper_stack;

//将一个item入队列
void en_queue(int item)
{
	main_stack.push(item);
}

/************************************************************************/
/* 获取最前面的元素，并且将其pop掉
/************************************************************************/
int pop_item()
{
	if (main_stack.empty() && helper_stack.empty())
	{
		puts("Queue is empty!\n");
		return INVALID_VALUE;
	}
	
	//这里做一个改进措施，如果heper stack为空，在进行压栈操作，否则直接取helper stack中的值。
	if (helper_stack .empty())
	{
		while (!main_stack.empty())
		{
			int top = main_stack.top();
			helper_stack.push(top);
			main_stack.pop();
		}
	}

	int value_to_ret = helper_stack.top();
	helper_stack.pop();


	 //可以避免这一次操作出栈压栈操作。
	/*
	while (!helper_stack.empty())
	{
		int top = helper_stack.top();
		main_stack.push(top);
		helper_stack.pop();
	}
	*/

	return value_to_ret;
}


/************************************************************************/
/* 把queue里面的元素都打印出来
/************************************************************************/
void print_queue()
{
	if (main_stack.empty() && helper_stack.empty())
	{
		puts("Queue is empty!\n");
		return;
	}

	std::stack<int> dup_helper = helper_stack;
	std::stack<int> dup_main = main_stack;
	puts("\n***************************************************************************\n");

	//首先把helper中的元素全部打印出来
	while (!dup_helper.empty())
	{
		int item = dup_helper.top();
		printf("%d\t", item);
		dup_helper.pop();
	}
	
	//把main中的元素重新压栈到helper中
	while (!dup_main.empty())
	{
		int item = dup_main.top();
		dup_main.pop();
		dup_helper.push(item);
	}

	//然后把helper中的所有元素打印出来
	while (!dup_helper.empty())
	{
		int item = dup_helper.top();
		printf("%d\t", item);
		dup_helper.pop();
	}

	puts("\n***************************************************************************\n");
}

/************************************************************************/
/* 开始算法
/************************************************************************/
void start_test_queue()
{
	en_queue(2);
	en_queue(3);
	en_queue(4);
	en_queue(5);
	en_queue(6);
	puts("origin: ");
	print_queue();
	pop_item();
	puts("\nAfter pop: ");
	print_queue();

	en_queue(7);
	puts("\nAfter enQueue 7: ");
	print_queue();
	pop_item();
	pop_item();
	pop_item();
	puts("\nAfter pop 3 times: ");
	print_queue();


}