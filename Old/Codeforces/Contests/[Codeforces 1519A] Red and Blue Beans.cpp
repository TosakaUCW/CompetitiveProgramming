#include <stdio.h>
#include <algorithm>
#include <math.h>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

void solve()
{
	int r = read(), b = read(), d = read();
	puts(abs(b - r) > std::min(b, r) * d ? "NO" : "YES");
}

signed main()
{
	for (int T = read(); T--; solve());
	return 0;
}
