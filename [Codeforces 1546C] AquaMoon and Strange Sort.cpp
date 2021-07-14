#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e5 + 5;

int n, a[N], b[N][2];

void solve()
{
	memset(b, 0, sizeof b);
	n = read();
	for (int i = 1; i <= n; i++) 
		a[i] = read(), ++b[a[i]][i & 1];
	std::sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		if (!b[a[i]][i & 1])
		{
			puts("NO");
			return;
		}
		--b[a[i]][i & 1];
	}
	puts("YES");
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}
