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

const int N = 100 + 5;

int n, m, ans;
int a[N];

int main()
{
#ifdef judge
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
#endif
	n = read(), m = read(), ans;
	for (int i = 1; i <= n; i++) a[i] = read();
	std::sort(a + 1, a + 1 + n);
	for (int i = 1; i < n; i++)
	{
		int mid = a[i] + a[i + 1];
		bool flag = true;
		for (int k = 1; i - k + 1 >= 1 and i + k <= n; k++)
			flag &= mid == a[i + k] + a[i - k + 1];
		ans += flag;
	}
	for (int i = 2; i < n; i++)
	{
		int mid = a[i] + a[i];
		bool flag = true;
		for (int k = 1; i - k >= 1 and i + k <= n; k++)
			flag &= mid == a[i + k] + a[i - k];
		ans += flag;
	}
	return printf("%d", ans), 0;
}
/*
5 10
0 10 6 2 4

4
*/
