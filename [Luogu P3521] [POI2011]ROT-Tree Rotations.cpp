#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;

int n, cnt1, cnt2, ans, node;
int ls[N * 25], rs[N * 25], siz[N * 25];

#define mid ((l + r) >> 1)

void newnode(int &p, int l, int r, int val)
{
    if (!p) p = ++node;
    siz[p]++;
    if (l == r) return;
    if (val <= mid) newnode(ls[p], l, mid, val);
    else newnode(rs[p], mid + 1, r, val);
}

void merge(int &x, int y)
{
    if (!x or !y) return x += y, void();
    siz[x] += siz[y];
    cnt1 += siz[rs[x]] * siz[ls[y]];
    cnt2 += siz[ls[x]] * siz[rs[y]];
    merge(ls[x], ls[y]), merge(rs[x], rs[y]);
}

int dfs()
{
    int x = read(), pos = 0;
    if (x) newnode(pos, 1, n, x); 
    else
    {
        int ls = dfs(), rs = dfs();
        cnt1 = cnt2 = 0;
        pos = ls, merge(pos, rs);
        ans += std::min(cnt1, cnt2);
    }
    return pos;
}

signed main() { return n = read(), dfs(), printf("%lld", ans), 0; }
