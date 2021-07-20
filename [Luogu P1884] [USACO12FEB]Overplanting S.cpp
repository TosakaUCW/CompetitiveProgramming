#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

#define judge

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 4000 + 5;

int n, cnt, maxn, ans;
int raw[N], c[N];

struct Node
{
	int x, y1, y2, opt;
	bool friend operator < (Node a, Node b) { return a.x == b.x ? a.opt > b.opt : a.x < b.x; }
} line[N];

struct SGT
{
	#define ls (p << 1)
	#define rs (p << 1| 1)
	#define mid ((l + r) >> 1)
	int cnt[N << 2], len[N << 2];
	void push(int p, int l, int r) { len[p] = cnt[p] >= 1 ? raw[r + 1] - raw[l] : len[p] = len[ls] + len[rs]; }
	void add(int p, int l, int r, int x, int y, int val)
	{
		if (x == l and r == y) return cnt[p] += val, push(p, l, r), void();
		if (x <= mid) add(ls, l, mid, x, std::min(mid, y), val);
		if (mid < y) add(rs, mid + 1, r, std::max(mid + 1, x), y, val);
		push(p, l, r);
	}
} t;

signed main()
{
#ifdef judge
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);
#endif
	n = read();
	for (int i = 1; i <= n; i++)
	{
		int x1 = read(), y2 = read(), x2 = read(), y1 = read();
		if (x2 < x1) std::swap(x1, x2);
		if (y1 > y2) std::swap(y1, y2);
		line[i * 2 - 1] = {x1, y1, y2, 1};
		line[i * 2] = {x2, y1, y2, -1};
		raw[++cnt] = y1, raw[++cnt] = y2;
	}
	std::sort(raw + 1, raw + 1 + cnt);
	cnt = std::unique(raw + 1, raw + 1 + cnt) - raw - 1;
	for (int i = 1; i <= 2 * n; i++)
	{
		int pos1 = std::lower_bound(raw + 1, raw + 1 + cnt, line[i].y1) - raw;
		int pos2 = std::lower_bound(raw + 1, raw + 1 + cnt, line[i].y2) - raw;
		line[i].y1 = pos1, line[i].y2 = pos2;
	}
	std::sort(line + 1, line + 1 + 2 * n);
	for (int i = 1; i <= 2 * n; i++)
	{
		t.add(1, 1, cnt, line[i].y1, line[i].y2 - 1, line[i].opt);
		ans += t.len[1] * (line[i + 1].x - line[i].x);
	}
	return printf("%lld", ans), 0;
}
/*
2
0 5 4 1
2 4 6 2

20
*/
