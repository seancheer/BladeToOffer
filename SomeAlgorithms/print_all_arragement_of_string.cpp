#include "print_all_arragement_of_string.h"

/************************************************************************/
/* ����һ���ַ�������ӡ���ַ����������У���abc������Ϊabc,acb,bac,bca,cab,cba
/* ˼·��
/* ȡ��һ���ַ���ʣ����ַ���Ϊ������Ȼ��ȡʣ���ַ����ֱ�͵�һ���ַ����н�����
/* �����α������ǰ�ߣ�Ȼ���ʣ����ַ��������������ַ����ڷֱ�͵�ǰ�α���ַ�
/* ���н�����ֱ����󵽽����ӡ����
/************************************************************************/

void print_all_arragement_of_string(const char* str)
{
	if (NULL == str)
	{
		puts("Param Error!");
		return;
	}

	size_t len = strlen(str);
	if (len == 0)
	{
		puts("Param Error!");
		return;
	}
	//����Ͳ����string����ֵ�Ƿ�Ϸ���
	//����str��ʹ���ڶ����ô�ÿ��Խ��б༭��
	char* str_copy = (char*)malloc(len + 1);
	memset(str_copy, 0, len + 1);

	//strncpy��vs2017�лᱨ�����������ֶ����ư�
	for (int i = 0; i <= len; ++i)
	{
		str_copy[i] = str[i];
	}

	puts("*********************************************************************");
	print_string_internal(str_copy, str_copy);
	puts("\n*********************************************************************");
	free(str_copy);
}

/************************************************************************/
/* �ڲ��ݹ���д�ӡ
/************************************************************************/
void print_string_internal(char* str, char* p_begin)
{
	if (*p_begin == '\0')
	{
		printf("%s\t", str);
	}
	else
	{
		for (char* cur = p_begin; *cur != '\0'; ++cur)
		{
			//�����Լ����Լ�������ԭ������������Լ����Լ���������ô��ʼֵ���������Լ�ԭ����λ���ϣ�
			//��ô����Ե��ܶ�����
			char tmp = *cur;
			*cur = *p_begin;
			*p_begin = tmp;

			//ע�⣬������p_begin + 1��������ʣ�µ��ַ������ոõݹ���߼����д���
			print_string_internal(str, p_begin + 1);

			//restore string
			tmp = *cur;
			*cur = *p_begin;
			*p_begin = tmp;
		}
	}
}

/************************************************************************/
/* �Ե����ķ�ʽ�ҳ����е����У�ע�⣺������ַ������뱣֤������ģ�
/* ��������������Ҫ�Ƚ�����������Ͳ�������������ˣ������߱�֤���򼴿�
/* ������˼·����ÿ�β��ҵ�ǰ�������һ�����򼴿ɣ����ҷ������£�
/* 1 ��β����ʼ�����ַ����ĵ�һ�������ԣ���"dacb"��β����ʼ�ĵ�һ��������Ϊ"ac"����ʱ���ǳ�aΪ�滻��
/* 2 ��β����ʼ���ҵ�һ�����滻����ֵ���õ��Ȼ���ڣ���Ϊ��һ���ҵ��ǵ������У�
/* 3 �滻��һ���ҵ����滻��͵ڶ����ҵ��ĵ�
/* 4 reverse�滻�����Ĳ���
/* 5 ������һ����ֱ����һ�����Ҳ���������Ϊֹ��
/************************************************************************/
void print_arragement_iterator_in_order(const char* str)
{
	if (NULL == str)
	{
		puts("Invalid para!");
		return;
	}

	int len = strlen(str);
	if (len == 0)
	{
		puts("Invalid para!");
		return;
	}

	if (len == 1)
	{
		printf("%s\n", str);
		return;
	}

	char* str_copy = (char*)malloc(len + 1);
	memset(str_copy, 0, len + 1);
	for (int i = 0; i < len; ++i)
	{
		str_copy[i] = str[i];
	}

	print_iterator_internal(str_copy);
	free(str_copy);
}

/************************************************************************/
/* �ڲ����е�����ӡ�ķ�ʽ
/************************************************************************/
void print_iterator_internal(char *str)
{
	puts("\n******************************************************************");
	do 
	{
		printf("%s \t", str);
	} while (print_iterator(str));

	puts("\n******************************************************************");
}

/************************************************************************/
/* ��֤���ٳ��ȴ���2
/************************************************************************/
bool print_iterator(char *str)
{
	char* replace_node_after = str + strlen(str);
	char* p_end = replace_node_after;
	char* replace_pos = replace_node_after - 1;

	//���ҵ�һ������������
	do
	{
		//�ҵ����滻��
		if (*replace_pos < *replace_node_after)
		{
			//���ҵ�һ�����滻������
			char* bigger_pos = find_bigger_from_end(str, replace_pos);
			swap(replace_pos, bigger_pos);
			reverse(replace_pos + 1, p_end);
			return true;
		}

		--replace_pos;
		--replace_node_after;
	} while (replace_pos >= str);

	//û���ҵ���˵����ʱ�ǵݼ��ģ�Ҳ������������
	return false;
}

/************************************************************************/
/* ��end��һ����target����ַ�
/************************************************************************/
char* find_bigger_from_end(char* str, char* target)
{
	char* p_end = str + strlen(str);
	while (*p_end <= *target)
	{
		--p_end;
	}

	return p_end;
}

/************************************************************************/
/* ��ת�ض��ε��ַ���                                                                     */
/************************************************************************/
void reverse_str(char* start, char* end)
{
	while (start != end)
	{
		swap(start, end);
		++start;
		--end;
	}
}

/************************************************************************/
/* �㷨���
/************************************************************************/
void start_print_all_arragement()
{
	print_all_arragement_of_string("abc");
	print_arragement_iterator_in_order("abc");
	print_all_arragement_of_string("abcd");
	print_arragement_iterator_in_order("abcd");
}