#include "eight_queen.h"
/************************************************************************/
/* �����İ˻ʺ����⣺
/* ��8���ʺ󣬰����Ƿ���8*8�ķ������棬Ҫ��
/* 1 ��������������ͬ�л���ͬ��
/* 2 ��������������һ��б������
/* ���ʣ��ж����ְڷ�
/************************************************************************/


/************************************************************************/
/* ����˼·��
/* ��һ������Ϊ8��һλ�����ʾ8��queen�����꣬��ʼֵΪ0-7�������ӣ��κ�һ��queen
/* ������ͬһ�л���ͬһ�У�������ֻ��Ҫ���ͬһ��б�ߵ����⼴�ɣ�������е����м��ɡ�
/************************************************************************/
void solve_eight_queen()
{
	//�������ʼ��eight_queen
	int queem_map[QUEEN_SUM] = { 0,1,2,3,4,5,6,7 };
	int sum = 0;
	solve_eight_queen_internal(queem_map, 0, sum);
	printf("Eight queen sum:%d !\n", sum);
}

/************************************************************************/
/* �ݹ����ȫ�����з�����������
/************************************************************************/
void solve_eight_queen_internal(int queen_map[QUEEN_SUM], int index, int& sum)
{
	if (index == QUEEN_SUM && check_queen(queen_map))
	{
		++sum;
		return;
	}

	for (int i = index; i < QUEEN_SUM; ++i)
	{
		//ע�⣺��ȵ�Ҳ��Ҫ���н���������ᵼ��ԭʼλ�ñ��ų���
		swap(&queen_map[index], &queen_map[i]);
		solve_eight_queen_internal(queen_map, index + 1, sum);
		swap(&queen_map[i], &queen_map[index]);
	}
}


/************************************************************************/
/* ��鵱ǰ�������Ƿ���������
/************************************************************************/
bool check_queen(int queen_map[QUEEN_SUM])
{
	for (int i = 0; i < QUEEN_SUM; ++i)
	{
		for (int j = i + 1; j < QUEEN_SUM; ++j)
		{
			if (i - j == queen_map[i] - queen_map[j] || j - i == queen_map[i] - queen_map[j])
			{
				return false;
			}
		}
	}

	return true;
}

/************************************************************************/
/* �ⷨ2��ͨ����˷���ķ�ʽ���queen������
/************************************************************************/
void solve_eight_queen_backwards()
{
	int queen_map[QUEEN_SUM] = { 0,0,0,0,0,0,0 };
	int sum = 0;
	eight_queen_backwards_internal(queen_map, 0, sum);
	printf("sum(backwards):%d\n", sum);
}


void eight_queen_backwards_internal(int queen_map[QUEEN_SUM], int pos, int& sum)
{
	if (pos == QUEEN_SUM)
	{
		++sum;
		return;
	}

	for (int i = 0; i < QUEEN_SUM; ++i)
	{
		queen_map[pos] = i;
		if (check_queen_backwards(queen_map, pos))
		{
			eight_queen_backwards_internal(queen_map, pos + 1, sum);
		}
	}
}

/************************************************************************/
/* ���ڻ�˷����֤�˲�ͬ�У���������ֻ��Ҫ������Ƿ���ͬ�л���һ��б������
/************************************************************************/
bool check_queen_backwards(int queen_map[QUEEN_SUM], int pos)
{
	for (int i = 0; i < pos; ++i)
	{
		if (queen_map[pos] == queen_map[i] || abs(queen_map[pos] - queen_map[i]) == abs(pos - i))
		{
			return false;
		}
	}

	return true;
}

/************************************************************************/
/* ��ʼ�㷨
/************************************************************************/
void start_eight_queen()
{
	solve_eight_queen();
	solve_eight_queen_backwards();
}