#include <bits/stdc++.h>
// #define int long long
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

const int N = 1e5 + 5;
const int P = 998244353;

#define in(x) (x.fi = read(), x.se = read())

int n;
pii st, ed, a[N];
std::map<pii, bool> ma;

pii operator+(pii A, pii B) { return {A.fi + B.fi, A.se + B.se}; }
pii operator-(pii A, pii B) { return {A.fi - B.fi, A.se - B.se}; }

bool judge(pii A, pii B)
{
	if (!A.fi and !A.se or ma[A])
		return 1;
	for (int i = 1; i <= n; i++)
	{
		pii pos = B + a[i];
		if (pos.fi < 1 or pos.fi > n or pos.se < 1 or pos.se > n)
			continue;
		if (ma[A - a[i]])
			return 1;
	}
	return 0;
}

void solve()
{
	n = read(), in(st), in(ed);
	for (int i = 1; i <= n; i++)
		in(a[i]), ma[a[i]] = 1;
	if (judge(ed - st, st))
		return puts("Alice wins"), void();
	for (int T = 500; T--;)
	{
		pii pos = {rand() % n + 1, rand() % n + 1};
		if (!judge(pos - ed, ed))
			return printf("tie %d %d\n", pos.fi, pos.se), void();
	}
	puts("Bob wins");
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("my_input.in", "r", stdin);
#endif
	srand(time(0));
	solve();
#ifndef ONLINE_JUDGE
	std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
	return 0;
}