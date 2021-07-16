#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 3e5 + 5;

int n, m, a[N], b[N], c[N];

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) 
	{
		a[i] = read();
		if (!c[a[i]]) c[a[i]] = i;
	}
	for (int i = 1; i <= m; i++) b[i] = read();
	for (int i = 1; i <= m; i++)
	{
		int x = b[i];
		printf("%d ", c[x]);
		for (int j = 1; j <= 50; j++)
			if (c[j] < c[x]) 
				c[j]++; 
		c[x] = 1;
	}
	return 0;
}

