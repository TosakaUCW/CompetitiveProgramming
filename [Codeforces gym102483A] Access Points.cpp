#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ins insert
#define pb push_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
using std::map;
using std::priority_queue;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::swap;
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

const int N = 1e6 + 5;
const int P = 998244353;

int n, top, a[N], b[N];
pii stk[N];

double solve(int *a)
{
	// pii : {sum, len}
	top = 1;
	for (int i = 1; i <= n; i++)
	{
		pii now = {a[i], 1};
		// top.fi / top.se > now.fi / now.se
		while (top > 1 and stk[top].fi * now.se > now.fi * stk[top].se)
		{
			now.fi += stk[top].fi;
			now.se += stk[top].se;
			top--;
		}
		stk[++top] = now;
	}
	double res = 0;
	int idx = n;
	while (top > 1)
	{
		pii t = stk[top--];
		double avg = 1.0 * t.fi / t.se;
		for (int i = idx; i > idx - t.se; i--)
			res += 1.0 * (a[i] - avg) * (a[i] - avg);
		idx -= t.se;
	}
	return res;
}

void solve()
{
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read(), b[i] = read();
	printf("%.8f\n", solve(a) + solve(b));
}

signed main()
{
#ifndef ONLINE_JUDGE
	// freopen("my_input.in", "r", stdin);
#endif
	solve();
#ifndef ONLINE_JUDGE
	std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
	return 0;
}