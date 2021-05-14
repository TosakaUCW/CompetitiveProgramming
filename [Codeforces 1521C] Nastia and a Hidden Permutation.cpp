#include <stdio.h>
#include <algorithm>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e4 + 5;

int a[N];

void solve()
{
#define query(opt, i, j, x) printf("? %d %d %d %d\n", opt, i, j, x), fflush(stdout) 
	int n = read(), p = 0;
	for (int i = 1, x, y; i < n; i += 2)
	{
		query(2, i, i + 1, 1);
		if ((x = read()) <= 2)
		{
			query(1, i, i + 1, 1);
			if ((y = read()) == 1) { p = i + 1; break; }
			query(1, i + 1, i, 1);
			if ((y = read()) == 1) { p = i; break; }

		}
	}
	if (!p) p = n;
	a[p] = 1;
	for (int i = p - 1; i; i--) query(1, p, i, n - 1), a[i] = read();
	for (int i = p + 1; i <= n; i++) query(1, p, i, n - 1), a[i] = read();
	printf("! ");
	for (int i = 1; i <= n; i++) printf("%d ", a[i]), fflush(stdout);
	puts(""), fflush(stdout);
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}
