#include <stdio.h>
#include <algorithm>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < '0' or ch > '9')
		f = ch == '-', ch = getchar();
	while ('0' <= ch and ch <= '9')
		x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

const int N = 2e3 + 5;

int n, a[N];

int main()
{
	for (int T = read(); T--; puts(""))
	{
		n = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		for (int i = 1; i <= n; i++) if (a[i] & 1) printf("%d ", a[i]);
		for (int i = 1; i <= n; i++) if (!(a[i] & 1)) printf("%d ", a[i]);
	}
	return 0;
}
