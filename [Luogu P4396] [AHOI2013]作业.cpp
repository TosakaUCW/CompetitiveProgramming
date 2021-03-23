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

const int N = 1e5 + 5;

int n, m, len;
int a[N], bel[N];
int buk[N], cnt[N], tot[N];

struct Node
{
    int L, R, a, b, idx;
    void input(int i) { L = read(), R = read(), a = read(), b = read(), idx = i; }
    bool friend operator<(Node a, Node b) { return bel[a.L] != bel[b.L] ? bel[a.L] < bel[b.L] : a.R < b.R; }
} query[N], ans[N];

void inc(int x)
{
    cnt[bel[x]]++;
    if (++buk[x] == 1)
        tot[bel[x]]++;
}

void dec(int x)
{
    cnt[bel[x]]--;
    if (--buk[x] == 0)
        tot[bel[x]]--;
}

void getans(int a, int b, int idx)
{
#define x ans[idx].a
#define y ans[idx].b
    for (int i = a; i <= std::min(b, bel[a] * len); i++)
        if (buk[i])
            x += buk[i], y++;
    if (bel[a] != bel[b])
        for (int i = (bel[b] - 1) * len + 1; i <= b; i++)
            if (buk[i])
                x += buk[i], y++;
    for (int i = bel[a] + 1; i <= bel[b] - 1; i++)
        x += cnt[i], y += tot[i];
}

int main()
{
    n = read(), m = read(), len = sqrt(n);
    for (int i = 1; i <= n; i++)
        a[i] = read(), bel[i] = (i - 1) / len + 1;
    for (int i = 1; i <= m; i++)
        query[i].input(i);
    std::sort(query + 1, query + 1 + m);
    for (int i = 1, L = 1, R = 0; i <= m; i++)
    {
        while (R < query[i].R)
            inc(a[++R]);
        while (R > query[i].R)
            dec(a[R--]);
        while (L > query[i].L)
            inc(a[--L]);
        while (L < query[i].L)
            dec(a[L++]);
        getans(query[i].a, query[i].b, query[i].idx);
    }
    for (int i = 1; i <= m; i++)
        printf("%d %d\n", ans[i].a, ans[i].b);
    return 0;
}