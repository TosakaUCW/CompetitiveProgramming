#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

void solve()
{
	int a = read(), b = read();
	if (b == 1) puts("NO");
	else printf("YES %lld %lld %lld\n", a, a * b, a * b + a);
}

signed main()
{
	for (int T = read(); T--; solve());
	return 0;
}
