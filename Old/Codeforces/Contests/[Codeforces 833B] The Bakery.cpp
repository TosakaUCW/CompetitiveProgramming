#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 3.5e4 + 5;
const int K = 50 + 5;

int n, k, ans;
int a[N], last[N];
int f[N][K];

struct Segment_Tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
    int max[N << 2], tag[N << 2];
    void push_up(int p) { max[p] = std::max(max[ls], max[rs]); }
    void push_down(int p)
    {
        if (tag[p])
        {
            max[ls] += tag[p], max[rs] += tag[p];
            tag[ls] += tag[p], tag[rs] += tag[p];
            tag[p] = 0;
        }
    }
    void modify(int p, int l, int r, int x, int y, int val)
    {
        if (l == x and r == y)
            return max[p] += val, tag[p] += val, void();
        push_down(p);
        if (x <= mid)
            modify(ls, l, mid, x, std::min(mid, y), val);
        if (mid < y)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y, val);
        push_up(p);
    }
    int query(int p, int l, int r, int x, int y)
    {
        if (l == x and r == y)
            return max[p];
        push_down(p);
        int res = 0;
        if (x <= mid)
            res = std::max(res, query(ls, l, mid, x, std::min(mid, y)));
        if (mid < y)
            res = std::max(res, query(rs, mid + 1, r, std::max(mid + 1, x), y));
        return res;
    }
} t[K];

int main()
{
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; last[a[i]] = i, i++)
        for (int j = 1; j <= k; j++)
        {
            t[j - 1].modify(1, 0, n, last[a[i]], i - 1, 1);
            f[i][j] = t[j - 1].query(1, 0, n, 0, i - 1);
            t[j].modify(1, 0, n, i, i, f[i][j]);
        }
    return printf("%d", f[n][k]), 0;
}