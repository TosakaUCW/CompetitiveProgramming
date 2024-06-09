#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

#define int long long

const int N = 2e5 + 5;

int n;
int a[N];

void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read(), sum += a[i];
	int x = sum / n;
	int y = sum % x;
	printf("%lld\n", y * (n - y)); 
}

signed main()
{
	for (int T = read(); T--; solve());
	return 0;
}
