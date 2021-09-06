#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

void solve()
{
	int n = read(), res = read();
	for (int i = 2; i <= n; i++) res = res & read();
	printf("%d\n", res);
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}

