#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define judge

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 5e5 + 5;
const int len[] = {3,10,25,56,119,246,501,1012,2035,4082,8177,16368,32751,65518,131053,262124,524267,1048554,2097129,4194280,8388583,16777190,33554405,67108836,134217699,268435426,536870881,1073741792};
// tot lne[27]

int n, idx;

char go(int x, int n, int i)
{
	if (i == 0) return x == 1 ? 'm' : 'o';
	int l = (n - 3 - i) / 2, r = n - l + 1;
	if (x == l + 1) return 'm';
	if (l + 1 < x and x < r) return 'o';
	if (x <= l) return go(x, l, i - 1);
	else return go(x - r + 1, l, i - 1);
}

int main()
{
#ifdef judge
	freopen("moo.in", "r", stdin);
	freopen("moo.out", "w", stdout);
#endif
	n = read();
	for (int i = 0; i <= 27; i++)
	{
		idx = i;
		if (len[i] > n) break;
	}
	return printf("%c", go(n, len[idx], idx)), 0;
}
/*
11

o
*/
