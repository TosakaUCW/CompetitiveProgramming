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

const int N = 1e6 + 5;
const int X = 2;
const int P = 1e9 + 7;

int n, m, k = 1;
int min[N << 2], sum[N << 2], pow[N];

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (l + r >> 1)
typedef std::pair<int, int> pii;
#define fi first
#define se second

void pushup(int p)
{
	min[p] = std::min(min[ls], min[rs]),
	sum[p] = (sum[ls] + sum[rs]) % P;
}

void modify(int pos, int val, int p = 1, int l = 1, int r = k)
{
	if (l == r)
		return min[p] = val, sum[p] = pow[val], void();
	if (pos <= mid) modify(pos, val, ls, l, mid);
	else modify(pos, val, rs, mid + 1, r);
	pushup(p);
}

pii query(int x, int y, int p = 1, int l = 1, int r = k)
{
	if (x == l and y == r)
		return pii(min[p], sum[p]);
	if (y <= mid) return query(x, y, ls, l, mid);
	else if (x >= mid + 1) return query(x, y, rs, mid + 1, r);
	else
	{
		pii a = query(x, mid, ls, l, mid),
			b = query(mid + 1, y, rs, mid + 1, r);
		a.fi = std::min(a.fi, b.fi),
		a.se = (a.se + b.se) % P;
		return a;
	}
}

int main()
{
	n = read(), m = read();
	pow[0] = 1;
	for (int i = 1; i < N; i++)
		pow[i] = 1LL * pow[i - 1] * X % P;
	while (k < n) k <<= 1;
	for (int i = k; i < k + n; i++)
		min[i] = read(), sum[i] = pow[min[i]];
	for (int i = k - 1; i >= 1; i--) pushup(i);
	for (int i = 1; i <= m; i++)
	{
		int opt = read(), x, y, L1, R1, L2, R2;
		if (opt == 0) x = read(), y = read(), modify(x, y);
		else
		{
			L1 = read(), R1 = read(), L2 = read(), R2 = read();
			pii a = query(L1, R1), b = query(L2, R2);
			if (a.fi > b.fi) std::swap(a, b);
			if (1LL * a.se * pow[b.fi - a.fi] % P == b.se)
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}
