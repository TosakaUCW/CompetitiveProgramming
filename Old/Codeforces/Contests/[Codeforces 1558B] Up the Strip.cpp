#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ins insert
#define pb emplace_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
using std::map;
using std::priority_queue;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;
int read(int x = 0, bool f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57)
		f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57)
		x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}
int pow(int x, int k, int P, int res = 1)
{
	for (; k; k >>= 1, x = x * x % P)
		if (k & 1)
			res = res * x % P;
	return res;
}

const int N = 4e6 + 5;

int n, P, f[N], g[N];

void solve()
{
	n = read(), P = read();
	f[n] = g[n] = 1;
	for (int i = n - 1; i; i--)
	{
		f[i] = g[i + 1] % P;
		for (int j = 2; j * i <= n; j++)
		{
			int L = j * i, R = std::min(n, j * (i + 1) - 1);
			f[i] = (f[i] + g[L] - g[R + 1] + P) % P;
		}
		g[i] = (g[i + 1] + f[i] + P) % P;
	}
	printf("%lld", f[1]);
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("my_input.in", "r", stdin);
#endif
	solve();
	return 0;
}