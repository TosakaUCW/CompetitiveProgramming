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
	int ans = 1;
	for (int n = read(); n > 1; n >>= 1, ans <<= 1);
	printf("%d\n", ans - 1);
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}
