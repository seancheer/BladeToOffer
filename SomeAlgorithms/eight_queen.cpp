#include "eight_queen.h"
/************************************************************************/
/* 著名的八皇后问题：
/* 有8个皇后，把她们放在8*8的方格里面，要求：
/* 1 任意两个不能再同行或者同列
/* 2 任意两个不能再一条斜线上面
/* 求问，有多少种摆法
/************************************************************************/


/************************************************************************/
/* 解题思路：
/* 用一个容量为8的一位数组表示8个queen的坐标，初始值为0-7，这样子，任何一个queen
/* 都不会同一行或者同一列，接下来只需要解决同一个斜线的问题即可，求出所有的排列即可。
/************************************************************************/
void solve_eight_queen()
{
	//用数组初始化eight_queen
	int queem_map[QUEEN_SUM] = { 0,1,2,3,4,5,6,7 };
	int sum = 0;
	solve_eight_queen_internal(queem_map, 0, sum);
	printf("Eight queen sum:%d !\n", sum);
}

/************************************************************************/
/* 递归求解全排列中符合条件的项
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
		//注意：相等的也需要进行交换，否则会导致原始位置被排除掉
		swap(&queen_map[index], &queen_map[i]);
		solve_eight_queen_internal(queen_map, index + 1, sum);
		swap(&queen_map[i], &queen_map[index]);
	}
}


/************************************************************************/
/* 检查当前的排列是否满足条件
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
/* 解法2：通过回朔法的方式解决queen的问题
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
/* 由于回朔法保证了不同行，所以这里只需要检测下是否处于同列或者一条斜线上面
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
/* 开始算法
/************************************************************************/
void start_eight_queen()
{
	solve_eight_queen();
	solve_eight_queen_backwards();
}