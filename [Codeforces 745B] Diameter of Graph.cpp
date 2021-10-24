#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57)
		f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57)
		x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

void solve()
{
	int n = read(), m = read(), k = read() - 1;
	if (n == 1 and !m)
		puts(k > 0 ? "YES" : "NO");
	else if (n == 2 and m == 1)
		puts(k > 1 ? "YES" : "NO");
	else if (n - 1 == m)
		puts(k > 2 ? "YES" : "NO");
	else if (n - 1 > m or n * (n - 1) / 2 < m)
		puts("NO");
	else if (n * (n - 1) / 2 == m)
		puts(k > 1 ? "YES" : "NO");
	else
		puts(k > 2 ? "YES" : "NO");
}

signed main()
{
	for (int T = read(); T--; solve())
		;
	return 0;
}
