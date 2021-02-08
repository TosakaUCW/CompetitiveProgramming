#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;

int n, m, ans;
int a[N];

struct seg_tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
    int tot[N];
    std::vector<int> split[N << 2];
    bool val[N << 2];
    void push_up(int p) { val[p] = val[ls] & val[rs]; }
    void init(int p, int l, int r, int x, int y, int idx)
    {
        if (l == x and r == y)
            return tot[idx]++, split[p].push_back(idx), void();
        if (x <= mid)
            init(ls, l, mid, x, std::min(mid, y), idx);
        if (mid < y)
            init(rs, mid + 1, r, std::max(mid + 1, x), y, idx);
    }
    void modify(int p, int l, int r, int pos)
    {
        if (l != r)
        {
            if (pos <= mid)
                modify(ls, l, mid, pos);
            else
                modify(rs, mid + 1, r, pos);
            push_up(p);
        }
        else if (!(--a[pos]))
            val[p] = true;
        if (val[p])
            for (auto i : split[p])
                if (!(--tot[i]))
                    ++ans;
    }
} T;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1, L, R; i <= m; i++)
        L = read(), R = read(), T.init(1, 1, n, L, R, i);
    for (int q = read(), last = 0, pos; q--; printf("%d\n", last = ans))
        pos = (read() + last - 1) % n + 1, T.modify(1, 1, n, pos);
    return 0;
}