#include "print_first_char_occur_1.h"
/************************************************************************/
/* 打印第一个字符串中第一个只出现一次的字符，比如"abaccdeft",其中'b'是第一个只出现一次的
/* 字符
/************************************************************************/

/************************************************************************/
/* 由于字符串只有a-z，创建一个哈希表，然后统计每个字符出现的次数，在从头遍历字符串
/* 发现出现次数为1的打印即可，这里不使用map，因为char类型为1个字节，因此，创建一个
/* 256的数组即可，每个字符的ascii码作为下标即可
/************************************************************************/
void print_first_char(const char* str)
{
	if (NULL == str || strlen(str) == 0)
	{
		puts("Invalid para!");
		return;
	}

	int char_counter[256];
	memset(char_counter, 0, sizeof(int) * 256);
	const char* tmp = str;
	while (*tmp != '\0')
	{
		++char_counter[*tmp];
		++tmp;
	}

	puts("***************************************************************************");
	for (tmp = str; *tmp != '\0'; ++tmp)
	{
		if (char_counter[*tmp] == 1)
		{
			printf("First char that occur 1:%c\n", *tmp);
			break;
		}
	}
	puts("***************************************************************************");
}


void start_print_first_char()
{
	const char* str = "abaccdeft";
	print_first_char(str);
}
