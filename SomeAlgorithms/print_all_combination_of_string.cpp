#include "print_all_combination_of_string.h"

/************************************************************************/
/* 输入一个字符串，打印该字符串所有组合，如：abc的组合为：a,b,c,ab,ac,bc,abc，需要注意的是
/* ab和ba为同一个组合
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
/* 内部递归进行打印
/* 思路：假设当前组合的长度为m，字符串的长度为n
/* 1 选定第一个字符为目标，那么接下来可能有两种情况：
/*      将该字符作为组合的一部分，从剩下的n-1个字符中找出m - 1个字符来，拼成组合
/*      不将该字符作为组合的一部分，从剩下的n-1个字符中找出m个字符来，拼成组合
/* 2 递归进行上面的步骤即可
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
	//在剩下的字符中找出cur_len - 1个
	if (str_end - p_begin >= cur_len - 1)
	{
		print_combination_string_internal(str, p_begin + 1, cur_len - 1, str_len, vec);
	}

	//pop出来当前字符
	vec.pop_back();
	//在剩下的字符中找出cur_len个
	if (str_end - p_begin >= cur_len)
	{
		print_combination_string_internal(str, p_begin + 1, cur_len, str_len, vec);
	}
}

/************************************************************************/
/* 将vec中存入的组合都打印出来                                                                     */
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
/* 使用位运算计算出所有组合
/* 思路：
/* 对于任意长度的组合，假设长度为4，那么组合其实就是二进制的1-4（包含4）中打印对应位
/* 为1的字符。这是一个非常棒的思路
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
		//计算二进制是多少位，如果有lg（2为底），那么直接lg2，否则，用换底公式计算lg2
		int bit_sum = log10(i) / log10(2);
		int j = 0;
		int index = 0;
		bool flag = false;
		//判断i的哪一位为1，那么将其打印出来
		while (j <= bit_sum)
		{
			//发现某个位为1，打印字符串对应的位置
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
/* 算法入口
/************************************************************************/
void start_print_all_combination()
{
	print_all_combination_of_string("abcd");
	print_all_combination_in_bit("ab");
}