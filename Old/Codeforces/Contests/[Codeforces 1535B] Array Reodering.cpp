#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 2e3 + 5;

int n, ans;
int a[N], b[N], c, d;

void solve()
{
	n = read(), ans = c = d = 0;
	for (int i = 1; i <= n; i++)
	{
		int x = read();
		if (x & 1) a[++c] = x;
		else b[++d] = x;
	}
	for (int i = 1; i <= c; i++) b[++d] = a[i];
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (std::__gcd(b[i], 2 * b[j]) > 1)
				ans++;
	printf("%d\n", ans);
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}

