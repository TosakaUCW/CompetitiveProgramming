#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 5e5 + 5;

int n, x, ans;
int a[N];

bool judge()
{
	for (int i = 1; i < n; i++) if (a[i] > a[i + 1]) return false;
	return true;
}

void solve()
{
	n = read(), x = read(), ans = 0;
	for (int i = 1; i <= n; i++) a[i] = read();
	if (judge()) return printf("%d\n", ans), void();
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > x) std::swap(a[i], x), ans++;
		if (judge()) break;
	}
	printf("%d\n", judge() ? ans : -1);
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}

