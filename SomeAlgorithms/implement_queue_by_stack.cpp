#include "implement_queue_by_stack.h"

std::stack<int> main_stack;
std::stack<int> helper_stack;

//��һ��item�����
void en_queue(int item)
{
	main_stack.push(item);
}

/************************************************************************/
/* ��ȡ��ǰ���Ԫ�أ����ҽ���pop��
/************************************************************************/
int pop_item()
{
	if (main_stack.empty() && helper_stack.empty())
	{
		puts("Queue is empty!\n");
		return INVALID_VALUE;
	}
	
	//������һ���Ľ���ʩ�����heper stackΪ�գ��ڽ���ѹջ����������ֱ��ȡhelper stack�е�ֵ��
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


	 //���Ա�����һ�β�����ջѹջ������
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
/* ��queue�����Ԫ�ض���ӡ����
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

	//���Ȱ�helper�е�Ԫ��ȫ����ӡ����
	while (!dup_helper.empty())
	{
		int item = dup_helper.top();
		printf("%d\t", item);
		dup_helper.pop();
	}
	
	//��main�е�Ԫ������ѹջ��helper��
	while (!dup_main.empty())
	{
		int item = dup_main.top();
		dup_main.pop();
		dup_helper.push(item);
	}

	//Ȼ���helper�е�����Ԫ�ش�ӡ����
	while (!dup_helper.empty())
	{
		int item = dup_helper.top();
		printf("%d\t", item);
		dup_helper.pop();
	}

	puts("\n***************************************************************************\n");
}

/************************************************************************/
/* ��ʼ�㷨
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