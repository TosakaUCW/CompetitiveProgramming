#include <math.h>
#include <stdio.h>
#include <algorithm>

#define int long long

const int N = 5e4 + 5;
const int M = 5e4 + 5;

int n, m;
int a[N];
int res, cnt[N], belong[N];
int L = 1, R;
int size;

struct Node
{
    int l, r, id;
    bool friend operator<(Node a, Node b)
    {
        if (belong[a.l] == belong[b.l])
            return a.r < b.r;
        return a.l < b.l;
    }
} query[M];

struct Ans
{
    int a, b;
} ans[M];

void update(int i, int num)
{
    if (num == 1)
        res += 2 * (++cnt[a[i]]) - 1;
    else
        res -= 2 * (--cnt[a[i]]) + 1;
}

signed main()
{
    scanf("%lld%lld", &n, &m);
    size = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        belong[i] = (i - 1) / size + 1;
    }
    for (int i = 1; i <= m; i++)
        scanf("%lld%lld", &query[i].l, &query[i].r), query[i].id = i;
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
        if (query[i].l == query[i].r)
        {
            ans[query[i].id].a = 0, ans[query[i].id].b = 1;
            continue;
        }
        int x = res - (query[i].r - query[i].l + 1);
        int y = (query[i].r - query[i].l + 1) * (query[i].r - query[i].l);
        int tmp = std::__gcd(x, y);
        x /= tmp, y /= tmp;
        ans[query[i].id].a = x, ans[query[i].id].b = y;
    }
    for (int i = 1; i <= m; i++)
        printf("%lld/%lld\n", ans[i].a, ans[i].b);
    return 0;
}