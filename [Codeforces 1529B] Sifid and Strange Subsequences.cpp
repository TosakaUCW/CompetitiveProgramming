#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e6 + 5;

int n, a[N];

void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	std::sort(a + 1, a + 1 + n);
	int max = 0, ans = n;
	for (int i = 1; i <= n; i++)
		if (a[i] > 0) { max = a[i], ans = i - 1; break; }
	int flag = max > 0;
	for (int i = 2; i <= ans; i++)
		if (a[i] - a[i - 1] < max) { flag = 0; break; }
	printf("%d\n", ans + flag);
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}
