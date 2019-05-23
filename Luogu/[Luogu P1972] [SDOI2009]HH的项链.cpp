#include <math.h>
#include <stdio.h>
#include <algorithm>

const int N = 5e5 + 5;
const int M = 5e5 + 5;
const int K = 1e6 + 5;

int n, m, k, res;
int a[N], ans[M], cnt[K], belong[N];
int L = 1, R;
int size;

struct Node
{
    int l, r, id;
    bool friend operator<(Node a, Node b)
    {
        if (belong[a.l] == belong[b.l])
        {
            if (belong[a.l] & 1)
                return a.r < b.r;
            return a.r > b.r;
        }
        return belong[a.l] < belong[b.l];
    }
} query[M];

inline int read()
{
    int res = 0;
    char c = getchar();
    while (c < '0' or c > '9')
        c = getchar();

    while (c >= '0' and c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res;
}

inline void write(int x)
{
    if (x < 0)
    {
        putchar('-');
        write(-x);
        return;
    }
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}

inline void update(int i, int opt)
{
    if (opt == 1)
        res += (++cnt[a[i]] == 1);
    else
        res -= (--cnt[a[i]] == 0);
}

int main()
{
    n = read();
    size = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        belong[i] = (i - 1) / size + 1;
    }
    m = read();
    for (int i = 1; i <= m; i++)
        query[i].l = read(), query[i].r = read(), query[i].id = i;
    std::sort(query + 1, query + 1 + m);
    for (int i = 1; i <= m; i++)
    {
        while (query[i].l < L)
            update(--L, 1);
        while (R < query[i].r)
            update(++R, 1);
        while (L < query[i].l)
            update(L++, -1);
        while (query[i].r < R)
            update(R--, -1);
        ans[query[i].id] = res;
    }
    for (int i = 1; i <= m; i++)
        write(ans[i]), puts("");
    return 0;
}