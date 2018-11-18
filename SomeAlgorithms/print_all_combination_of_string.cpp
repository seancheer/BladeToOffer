#include "print_all_combination_of_string.h"

/************************************************************************/
/* ����һ���ַ�������ӡ���ַ���������ϣ��磺abc�����Ϊ��a,b,c,ab,ac,bc,abc����Ҫע�����
/* ab��baΪͬһ�����
/************************************************************************/

void print_all_combination_of_string(const char* str)
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

	int cur_len = 1;
	while (cur_len <= len)
	{
		std::vector<char> vec;
		print_combination_string_internal(str_copy, str_copy, cur_len, len, vec);
		++cur_len;
	}
	puts("\n*********************************************************************");
	free(str_copy);
}

/************************************************************************/
/* �ڲ��ݹ���д�ӡ
/* ˼·�����赱ǰ��ϵĳ���Ϊm���ַ����ĳ���Ϊn
/* 1 ѡ����һ���ַ�ΪĿ�꣬��ô���������������������
/*      �����ַ���Ϊ��ϵ�һ���֣���ʣ�µ�n-1���ַ����ҳ�m - 1���ַ�����ƴ�����
/*      �������ַ���Ϊ��ϵ�һ���֣���ʣ�µ�n-1���ַ����ҳ�m���ַ�����ƴ�����
/* 2 �ݹ��������Ĳ��輴��
/************************************************************************/
void print_combination_string_internal(char* str, char* p_begin, int cur_len, int str_len, std::vector<char>& vec)
{
	if (cur_len < 0 || cur_len > str_len || *p_begin == '\0')
	{
		return;
	}

	vec.emplace_back(*p_begin);
	if (cur_len - 1 == 0)
	{
		print_combination(vec);
	}

	char* str_end = str + str_len;
	//��ʣ�µ��ַ����ҳ�cur_len - 1��
	if (str_end - p_begin >= cur_len - 1)
	{
		print_combination_string_internal(str, p_begin + 1, cur_len - 1, str_len, vec);
	}

	//pop������ǰ�ַ�
	vec.pop_back();
	//��ʣ�µ��ַ����ҳ�cur_len��
	if (str_end - p_begin >= cur_len)
	{
		print_combination_string_internal(str, p_begin + 1, cur_len, str_len, vec);
	}
}

/************************************************************************/
/* ��vec�д������϶���ӡ����                                                                     */
/************************************************************************/
void print_combination(std::vector<char>& vec)
{
	if (vec.empty())
	{
		return;
	}

	int size = vec.size();
	for (int i = 0; i < size; ++i)
	{
		printf("%c", vec[i]);
	}

	printf("\t");
}

/************************************************************************/
/* ʹ��λ���������������
/* ˼·��
/* �������ⳤ�ȵ���ϣ����賤��Ϊ4����ô�����ʵ���Ƕ����Ƶ�1-4������4���д�ӡ��Ӧλ
/* Ϊ1���ַ�������һ���ǳ�����˼·
/************************************************************************/
void print_all_combination_in_bit(const char* str)
{
	if (NULL == str)
	{
		puts("Invalid para!");
		return;
	}

	int len = strlen(str);
	if (0 == len)
	{
		puts("Invalid para!");
		return;
	}

	for (int i = 1; i <= (1 << len); ++i)
	{
		//����������Ƕ���λ�������lg��2Ϊ�ף�����ôֱ��lg2�������û��׹�ʽ����lg2
		int bit_sum = log10(i) / log10(2);
		int j = 0;
		int index = 0;
		bool flag = false;
		//�ж�i����һλΪ1����ô�����ӡ����
		while (j <= bit_sum)
		{
			//����ĳ��λΪ1����ӡ�ַ�����Ӧ��λ��
			if (i & (1 << j))
			{
				flag = true;
				printf("%c", str[index]);
			}
			++index;
			++j;
		}

		printf("\t");
	}
	puts("");
}

/************************************************************************/
/* �㷨���
/************************************************************************/
void start_print_all_combination()
{
	print_all_combination_of_string("abcd");
	print_all_combination_in_bit("ab");
}