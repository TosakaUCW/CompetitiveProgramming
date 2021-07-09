#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e7 + 5;

int n, ans, x;
int a[N];

void solve()
{
	n = read(), ans = 0, x = a[1] = read();
	for (int i = 2; i <= n; i++) a[i] = read(), x = std::min(x, a[i]);
	for (int i = 1; i <= n; i++) ans += a[i] > x;
	printf("%d\n", ans);
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}
