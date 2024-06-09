#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <math.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 5e5 + 5;
const int M = 5e5 + 5;

int n, m, size, res;
int a[N], b[N], bel[N], ans[N];
int buk[N];

struct Node
{
    int l, r, id;
    bool friend operator<(Node a, Node b) { return bel[a.l] == bel[b.l] ? a.r < b.r : a.l < b.l; }
} q[M];

void update(int i, int val)
{
    if (val == 1)
    {
        if (buk[a[i]] == 2)
            res--;
        ++buk[a[i]];
        if (buk[a[i]] == 2)
            res++;
    }
    else
    {
        if (buk[a[i]] == 2)
            res--;
        --buk[a[i]];
        if (buk[a[i]] == 2)
            res++;
    }
}

void go()
{
    memcpy(b, a, sizeof a), std::sort(b + 1, b + 1 + n);
    int nn = std::unique(b + 1, b + 1 + n) - b - 1;
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + 1 + nn, a[i]) - b;
}

int main()
{
    freopen("poklon.in", "r", stdin), freopen("poklon.out", "w", stdout);
    n = read(), m = read(), size = sqrt(n);
    for (int i = 1; i <= n; i++)
        a[i] = read(), bel[i] = (i - 1) / size + 1;
    for (int i = 1; i <= m; i++)
        q[i].l = read(), q[i].r = read(), q[i].id = i;
    std::sort(q + 1, q + 1 + m), go();
    for (int i = 1, L = 1, R = 0; i <= m; ans[q[i++].id] = res)
    {
        while (q[i].l < L)
            update(--L, 1);
        while (R < q[i].r)
            update(++R, 1);
        while (L < q[i].l)
            update(L++, -1);
        while (q[i].r < R)
            update(R--, -1);
    }
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}