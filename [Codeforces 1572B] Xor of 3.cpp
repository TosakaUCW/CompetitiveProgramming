#include <bits/stdc++.h>
// #define int long long
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
const int INF = 2147483647;

int n, a[N], pre[N], nxt[N];
vector<int> ans;

#define sum(i) (a[i] ^ a[i + 1] ^ a[i + 2])
#define check(i, x, y, z) (a[i] == x and a[i + 1] == y and a[i + 2] == z)

void solve()
{
	n = read(), ans.clear();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	if (a[1] == 1)
	{
		int i = 1;
		for (; 1; i += 2)
		{
			if (i + 2 > n)
				return puts("NO"), void();
			if ((a[i + 1] ^ a[i + 2]) == 1)
				break;
		}
		for (; i >= 1; i -= 2)
			ans.pb(i), a[i] = a[i + 1] = a[i + 2] = sum(i);
	}
	for (int i = 2; i <= n - 2; i++)
	{
		if (a[i] == 0)
			continue;
		if (check(i, 1, 1, 1))
			ans.pb(i - 1), a[i] = a[i + 1] = 0;
		else if (check(i, 1, 0, 1))
			ans.pb(i), a[i] = a[i + 2] = 0;
		else if (check(i, 1, 1, 0))
			ans.pb(i), a[i] = a[i + 1] = 0;
		else if (check(i, 1, 0, 0))
			ans.pb(i), ans.pb(i - 1), a[i] = 0, a[i + 2] = 1;
	}
	if (sum(n - 2))
		return puts("NO"), void();
	if (!check(n - 2, 0, 0, 0))
		ans.pb(n - 2);
	printf("YES\n%d", ans.size());
	if (ans.size())
		puts("");
	for (auto x : ans)
		printf("%d ", x);
	puts("");
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
#endif
	for (int T = read(); T--; solve())
		;
	return 0;
}
/*
可以发现对于最左边的一个 1，我们可以通过操作将他往后挪，最后规约到 (n - 2, n]
发现当我们把 a[1] 变为 0 后，该操作一定可以实现
*/