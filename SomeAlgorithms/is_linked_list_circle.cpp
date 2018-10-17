#include "is_linked_list_circle.h"
#include "find_middle_node_in_linked_list.h"
#define PREVIOUS_STEP 2
#define AFTER_STEP 1
/************************************************************************/
/* ����һ��ͷ��㣬�ж������ǲ��ǻ��Σ������������ͷβ��ӣ������ж��Ƿ�Ϊ����
/* ���˼·��
/* ָ������ָ�룬��һ��ÿ��ǰ��2�����ڶ���ÿ��ǰ��1������ȴ��ʼ����������ڵ�
/* ������������ô��˵���������ǻ�״��
/************************************************************************/

bool is_list_circle(LinkedList* header)
{
	if (NULL == header)
	{
		return false;
	}

	LinkedList* previous = header;
	LinkedList* after = header;

	while (true)
	{
		previous = forward_node(previous, PREVIOUS_STEP);
		if (NULL == previous)
		{
			return false;	 
		}

		after = forward_node(after, AFTER_STEP);
		if (after == previous)
		{
			return true;
		}
	}
}

/************************************************************************/
/* ��ʼ�㷨
/* ��ʼ�ж�һ������
/************************************************************************/
void start_tell_list_is_circle()
{
	LinkedList* header = init_linked_list(1);
	header->next = header;
	bool result = is_list_circle(header);
	BOOL_TO_STRING(result);
	//�ͷ�����ķ���Ŀǰ��֧�ֵ�������˫��������Ҫ֧���¡�
	empty_linked_list_with_tail(header,header);

	header = init_linked_list(1);
	result = is_list_circle(header);
	BOOL_TO_STRING(result);
	empty_linked_list_with_tail(header,header);

	header = init_linked_list(1);
	append_value(header, 2);
	append_value(header, 3);
	append_value(header, 4);
	LinkedList* tail = get_tail_of_list(header);
	result = is_list_circle(header);
	BOOL_TO_STRING(result);


	tail->next = header;
	result = is_list_circle(header);
	BOOL_TO_STRING(result);
	empty_linked_list_with_tail(header, tail);
}