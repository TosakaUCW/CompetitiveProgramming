#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < '0' or ch > '9')
		f = ch == '-', ch = getchar();
	while ('0' <= ch and ch <= '9')
		x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

const int N = 5e4 + 5;
const int INF = 2147483647;

#define get(x) (std::lower_bound(b + 1, b + 1 + nn, x) - b)

int n, m, nn;
int a[N], b[N << 1];

#define lowbit(x) (x & -x)
#define sum(p) (t[p].sum)
#define ls(p) (t[p].ls)
#define rs(p) (t[p].rs)
#define mid ((l + r) >> 1)
struct Seg_Node { int sum, ls, rs; } t[N * 100];
int rt[N], tot;
int lef[N], rig[N], tot1, tot2;
void pushup(int p) { sum(p) = sum(ls(p)) + sum(rs(p)); }
void modify(int &p, int l, int r, int x, int k)
{
	if (!p) p = ++tot;
	if (l == r) return sum(p) += k, void();
	if (x <= mid) modify(ls(p), l, mid, x, k);
	else modify(rs(p), mid + 1, r, x, k);
	pushup(p);
}
void add(int p, int k) 
{ 
	for (int i = p; i <= n; i += lowbit(i))
		modify(rt[i], 1, nn, a[p], k);
}
int query_num(int l, int r, int k)
{
	if (l == r) return l;
	int res = 0;
	for (int i = 1; i <= tot1; i++) res += sum(ls(lef[i]));
	for (int i = 1; i <= tot2; i++) res -= sum(ls(rig[i]));
	for (int i = 1; i <= tot1; i++) lef[i] = k <= res ? ls(lef[i]) : rs(lef[i]);
	for (int i = 1; i <= tot2; i++) rig[i] = k <= res ? ls(rig[i]) : rs(rig[i]);
	return k <= res ? query_num(l, mid, k) : query_num(mid + 1, r, k - res);
}
int find_num(int l, int r, int k)
{
	tot1 = tot2 = 0;
	for (int i = r; i; i -= lowbit(i))
		lef[++tot1] = rt[i];
	for (int i = l - 1; i; i -= lowbit(i))
		rig[++tot2] = rt[i];
	return query_num(1, nn, k);
}
int query_rank(int l, int r, int k)
{
	if (l == r) return 0;
	int res = 0;
	if (k <= mid)
	{
		for (int i = 1; i <= tot1; i++) lef[i] = ls(lef[i]);
		for (int i = 1; i <= tot2; i++) rig[i] = ls(rig[i]);
		return query_rank(l, mid, k);
	}
	{
		for (int i = 1; i <= tot1; i++) 
			res += sum(ls(lef[i])), lef[i] = rs(lef[i]);
		for (int i = 1; i <= tot2; i++)
			res -= sum(ls(rig[i])), rig[i] = rs(rig[i]);
		return res + query_rank(mid + 1, r, k);
	}
}
int find_rank(int l, int r, int k)
{
	tot1 = tot2 = 0;
	for (int i = r; i; i -= lowbit(i))
		lef[++tot1] = rt[i];
	for (int i = l - 1; i; i -= lowbit(i))
		rig[++tot2] = rt[i];
	return query_rank(1, nn, k) + 1;
}
int find_pre(int l, int r, int k)
{
	int rank = find_rank(l, r, k) - 1;
	return rank ? find_num(l, r, rank) : 0;
}
int find_next(int l, int r, int k)
{
	if (k == nn) return nn + 1;
	int rank = find_rank(l, r, k + 1);
	return rank == r - l + 2 ? nn + 1 : find_num(l, r, rank);
}

struct Query
{ 
	int opt, l, r, k;
	void input()
	{
		opt = read(), l = read(), r= read();
		if (opt != 3) k = read();
		else b[++nn] = r;
		if (opt == 4 or opt == 5) b[++nn] = k;
	}
	void operate()
	{
		if (opt == 1) printf("%d\n", find_rank(l, r, get(k)));
		if (opt == 2) printf("%d\n", b[find_num(l, r, k)]);
		if (opt == 3) add(l, -1), a[l] = get(r), add(l, 1);
		if (opt == 4) printf("%d\n", b[find_pre(l, r, get(k))]);
		if (opt == 5) printf("%d\n", b[find_next(l, r, get(k))]);
	}
} q[N];

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = b[++nn] = read();
	for (int i = 1; i <= m; i++) q[i].input();
	std::sort(b + 1, b + 1 + nn);
	nn = std::unique(b + 1, b + 1 + nn) - b - 1;
	for (int i = 1; i <= n; i++)
		a[i] = get(a[i]), add(i, 1);
	b[0] = -INF, b[nn + 1] = INF;
	for (int i = 1; i <= m; i++) q[i].operate();
	return 0;
}
