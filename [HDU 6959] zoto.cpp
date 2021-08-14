#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e5 + 5;
const int siz = 317;

int bel[N], L[N], R[N], si;
int n, m, a[N], ans[N], buk[N], sum[siz + 5];

struct Node
{
    int l, r, x, y, id;
    void input(int i) { l = read(), x = read(), r = read(), y = read(), id = i;}
    bool friend operator < (Node a, Node b) { return a.l / si != b.l / si ? a.l < b.l : a.r < b.r; }
} q[N];

void update(int x, int opt)
{
    if (opt == +1 and buk[x] == 0) sum[bel[x]]++;
    if (opt == -1 and buk[x] == 1) sum[bel[x]]--;
    buk[x] += opt;
}

int que(int n)
{
	if (n < 0) return 0;
	int res = 0;
	for (int i = 1; i < bel[n]; i++) res += sum[i];
	for (int i = L[n]; i <= n; i++) res += (buk[i] > 0);
	return res;
}

void solve()
{
	memset(buk, 0, sizeof buk), memset(sum, 0, sizeof sum);
	n = read(), m = read(), si = sqrt(n);
	for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= m; i++) q[i].input(i);
    std::sort(q + 1, q + 1 + m);
    for (int i = 1, L = 1, R = 0; i <= m; i++)
    {
        while (q[i].l < L) update(a[--L], +1); while (R < q[i].r) update(a[++R], +1);
		while (L < q[i].l) update(a[L++], -1); while (q[i].r < R) update(a[R--], -1);
        ans[q[i].id] = que(q[i].y) - que(q[i].x - 1);
    }
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}

int main()
{
	for (int i = 0; i <= 100000; i++) bel[i] = i / siz + 1, L[i] = (bel[i] - 1) * siz, R[i] = bel[i] * siz - 1;
	for (int T = read(); T--; solve());
	return 0;
}

