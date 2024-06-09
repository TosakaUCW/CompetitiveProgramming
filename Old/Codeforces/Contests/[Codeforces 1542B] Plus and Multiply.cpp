#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e9 + 5;

int a, b, n;

void solve()
{
	n = read(), a = read(), b = read();
	if (a == 1) return puts((n - 1) % b == 0 ? "Yes" : "No"), void();
	for (int x = 1; x <= n; x *= a)
		if (x % b == n % b)
			return puts("Yes"), void();
	puts("No");
}

signed main()
{
	for (int T = read(); T--; solve());
	return 0;
}
