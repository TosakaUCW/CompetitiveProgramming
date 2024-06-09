#include <stdio.h>
#include <algorithm>
#include <math.h>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < '0' or ch > '9')
		f = ch == '-', ch = getchar();
	while ('0' <= ch and ch <= '9')
		x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

signed main()
{
	for (int T = read(); T--;)
	{
		int n = read(), f = 0;
		for (int i = 1, x, y; i <= n; i++)
			x = read(), y = sqrt(x), f |= y * y != x;
		puts(f ? "YES" : "NO");
	}
	return 0;
}
