#include <stdio.h>
#include <algorithm>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int ans[] = {1000000000 + 7, 1000000000 + 9};

int main()
{
	for (int T = read(); T--; )
	{
		int n = read(), a = 1e9 + 5, b = 0;
		for (int i = 1, x; i <= n; i++)
		{
			x = read();
			if (x < a) a = x, b = i;
		}
		printf("%d\n", n - 1);
		for (int i = 1, now = 1; i <= n; i++, now ^= 1)
			if (i ^ b)
				printf("%d %d %d %d\n", i, b, ans[now], a);
	}
	return 0;
}
