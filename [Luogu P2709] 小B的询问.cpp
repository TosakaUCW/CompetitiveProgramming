#include <math.h>
#include <stdio.h>
#include <algorithm>

const int N = 5e4 + 5;
const int M = 5e4 + 5;
const int K = 5e4 + 5;

int n, m, k, res;
int a[N], ans[M], cnt[K];
int L = 1, R;
int size;

struct Node
{
    int l, r, id;
    bool friend operator<(Node a, Node b)
    {
        if (a.l / size != b.l / size)
            return a.l < b.l;
        return a.r < b.r;
    }
} query[M];

void update(int i, int num)
{
    if (num == 1)
        res += 2 * (++cnt[a[i]]) - 1;
    else
        res -= 2 * (--cnt[a[i]]) + 1;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    size = sqrt(n);
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &query[i].l, &query[i].r), query[i].id = i;
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
        printf("%d\n", ans[i]);
    return 0;
}