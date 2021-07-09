#include <stdio.h>
#include <memory.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 4e4 + 5;
const int K = 1e2 + 5;
const int INF = 1LL << 60;

int n, k, a[N], b[N], f[N][K];

struct sgt
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
	int min[N << 2], tag[N << 2];
	void pushup(int p) { min[p] = std::min(min[ls], min[rs]); }
	void pushdown(int p, int l, int r)
	{
		if (!tag[p]) return; 
		min[ls] += tag[p], min[rs] += tag[p];
		tag[ls] += tag[p], tag[rs] += tag[p];
		tag[p] = 0;
	}
	void build(int p, int l, int r, int j)
	{
		tag[p] = 0;
		if (l == r) return min[p] = f[l][j - 1], void();
		build(ls, l, mid, j), build(rs, mid + 1, r, j), pushup(p);
	}
	void add(int p, int l, int r, int x, int y, int k)
	{
		if (l == x and r == y) return min[p] += k, tag[p] += k, void();
		pushdown(p, l, r);
		if (x <= mid) add(ls, l, mid, x, std::min(mid, y), k);
		if (mid < y) add(rs, mid + 1, r, std::max(mid + 1, x), y, k);
		pushup(p);
	}
	int query(int p, int l, int r, int x, int y)
	{
		if (l == x and r == y) return min[p];
		int res = INF; pushdown(p, l, r);
		if (x <= mid) res = std::min(res, query(ls, l, mid, x, std::min(mid, y)));
		if (mid < y) res = std::min(res, query(rs, mid + 1, r, std::max(mid + 1, x), y));
		return res;
	}
} t;

signed main()
{
	n = read(), k = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++)
	{
		f[i][1] = f[i - 1][1];
		if (b[a[i]]) f[i][1] += i - b[a[i]];
		b[a[i]] = i;
	}
	for (int j = 2; j <= k; j++)
	{
		t.build(1, 1, n, j);
		for (int i = 1; i <= n; i++)
		{
			if (b[a[i]] < i and b[a[i]] > 1) t.add(1, 1, n, 1, b[a[i]] - 1, i - b[a[i]]);
			b[a[i]] = i;
			if (i >= j)	f[i][j] = t.query(1, 1, n, 1, i - 1);
			else f[i][j] = INF;
		}
	}
	return printf("%lld", f[n][k]), 0;
}
