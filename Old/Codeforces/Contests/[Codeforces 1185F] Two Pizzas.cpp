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

#define int long long

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n, m;
int a[N], b[N];
int cnt[N];

struct Node
{
    int val, idx;
} d1[N], d2[N], ans;

signed main()
{
    n = read(), m = read();
    memset(d1, 0x3f, sizeof d1), memset(d2, 0x3f, sizeof d2);
    for (int i = 1; i <= n; i++)
        for (int j = 1, k = read(), x; j <= k; j++)
            x = read(), a[i] |= 1LL << x;
    for (int i = 0; i < (1 << 10); i++)
        for (int j = 1; j <= n; j++)
            if ((a[j] & i) == a[j])
                cnt[i]++;
    for (int i = 1; i <= m; i++)
    {
        int val = read();
        for (int j = 1, k = read(), x; j <= k; j++)
            x = read(), b[i] |= 1LL << x;
        if (d1[b[i]].val > val)
            d2[b[i]] = d1[b[i]],
            d1[b[i]] = Node{val, i};
        else if (d2[b[i]].val > val)
            d2[b[i]] = Node{val, i};
    }
    int max_cnt = 0, min_cost = INF;
    for (int i = 0; i < (1 << 10); i++)
        for (int j = 0; j < (1 << 10); j++)
        {
            if (d1[i].val == INF or d1[j].val == INF)
                continue;
            if (i == j and d2[i].val == INF)
                continue;
            int kind = i | j, cnt = ::cnt[kind];
            if (cnt > max_cnt)
            {
                max_cnt = cnt;
                if (i == j)
                    ans = Node{d1[i].idx, d2[i].idx},
                    min_cost = d1[i].val + d2[j].val;
                else
                    ans = Node{d1[i].idx, d1[j].idx},
                    min_cost = d1[i].val + d1[j].val;
            }
            else if (cnt == max_cnt)
            {
                int now_cost;
                if (i == j)
                    now_cost = d1[i].val + d2[i].val;
                else
                    now_cost = d1[i].val + d1[j].val;
                if (now_cost < min_cost)
                {
                    min_cost = now_cost;
                    if (i == j)
                        ans = Node{d1[i].idx, d2[j].idx};
                    else
                        ans = Node{d1[i].idx, d1[j].idx};
                }
            }
        }
    return printf("%lld %lld", ans.val, ans.idx), 0;
}