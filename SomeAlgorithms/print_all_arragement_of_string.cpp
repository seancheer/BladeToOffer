#include "print_all_arragement_of_string.h"

/************************************************************************/
/* 输入一个字符串，打印该字符串所有排列，如abc的排列为abc,acb,bac,bca,cab,cba
/* 思路：
/* 取第一个字符，剩余的字符视为其他，然后取剩余字符，分别和第一个字符进行交换，
/* 接着游标继续往前走，然后把剩余的字符继续当做其他字符，在分别和当前游标的字符
/* 进行交换。直到最后到结果打印即可
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
	//这里就不检查string里面值是否合法了
	//拷贝str，使其在堆里，那么久可以进行编辑了
	char* str_copy = (char*)malloc(len + 1);
	memset(str_copy, 0, len + 1);

	//strncpy在vs2017中会报错，所以这里手动复制吧
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
/* 内部递归进行打印
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
			//这里自己和自己交换的原因：如果不进行自己和自己交换，那么初始值将不能在自己原来的位置上，
			//那么会忽略掉很多排列
			char tmp = *cur;
			*cur = *p_begin;
			*p_begin = tmp;

			//注意，这里是p_begin + 1，继续把剩下的字符串按照该递归的逻辑进行处理
			print_string_internal(str, p_begin + 1);

			//restore string
			tmp = *cur;
			*cur = *p_begin;
			*p_begin = tmp;
		}
	}
}

/************************************************************************/
/* 以迭代的方式找出所有的排列，注意：输入的字符串必须保证是有序的，
/* 如果不是有序的需要先进行排序，这里就不进行排序操作了，输入者保证有序即可
/* 迭代的思路：即每次查找当前排序的下一个排序即可，查找方法如下，
/* 1 从尾部开始查找字符串的第一个递增对，如"dacb"从尾部开始的第一个递增对为"ac"，此时我们称a为替换点
/* 2 从尾部开始查找第一个比替换点大的值，该点必然存在（因为第一步找的是递增序列）
/* 3 替换第一步找到的替换点和第二步找到的点
/* 4 reverse替换点后面的部分
/* 5 继续第一步，直到第一步查找不到递增点为止。
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
/* 内部进行迭代打印的方式
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
/* 保证至少长度大于2
/************************************************************************/
bool print_iterator(char *str)
{
	char* replace_node_after = str + strlen(str);
	char* p_end = replace_node_after;
	char* replace_pos = replace_node_after - 1;

	//查找第一个自增的序列
	do
	{
		//找到了替换点
		if (*replace_pos < *replace_node_after)
		{
			//查找第一个比替换点大的数
			char* bigger_pos = find_bigger_from_end(str, replace_pos);
			swap(replace_pos, bigger_pos);
			reverse(replace_pos + 1, p_end);
			return true;
		}

		--replace_pos;
		--replace_node_after;
	} while (replace_pos >= str);

	//没有找到，说明此时是递减的，也就是最大的序列
	return false;
}

/************************************************************************/
/* 从end找一个比target大的字符
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
/* 翻转特定段的字符串                                                                     */
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
/* 算法入口
/************************************************************************/
void start_print_all_arragement()
{
	print_all_arragement_of_string("abc");
	print_arragement_iterator_in_order("abc");
	print_all_arragement_of_string("abcd");
	print_arragement_iterator_in_order("abcd");
}