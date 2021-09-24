#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e7 + 5;

int n, stk[N], top;
int val[N], ls[N], rs[N];

signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) val[i] = read();
	for (int i = 1; i <= n; i++)
	{
		int k = top;
		while (top and val[stk[k]] > val[i]) k--;
		if (k) rs[stk[k]] = i;
		if (k < top) ls[i] = stk[k + 1];
		stk[++k] = i, top = k;
	}
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) a ^= i * (ls[i] + 1);
	for (int i = 1; i <= n; i++) b ^= i * (rs[i] + 1);
	return printf("%lld %lld", a, b), 0;
}
