#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int P = 1e9 + 7;

void solve()
{
	int n = read();
	int ans = 1;
	for (int i = 3; i <= n * 2; i++) ans = ans * i % P;
	printf("%lld\n", ans);
}

signed main()
{
	for (int T = read(); T--; solve());
	return 0;
}

