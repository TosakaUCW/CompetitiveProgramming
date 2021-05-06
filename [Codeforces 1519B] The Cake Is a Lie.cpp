#include <stdio.h>
#include <algorithm>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

void solve()
{
	int n = read(), m = read(), k = read();
	puts(n * m - 1 == k ? "YES" : "NO");
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}
