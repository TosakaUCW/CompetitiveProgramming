#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 1e3 + 5;
const int M = 5 + 1;
const int INF = 0x7f7f7f7f7f7f7f7f;

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

int T, n, ans, b[N];

struct Node
{
    int come, next, tot, idx[M], val[M];
    bool is_read[M];
} a[N];

signed main()
{
    freopen("reading.in", "r", stdin), freopen("reading.out", "w", stdout);
    for (; scanf("%lld%lld", &T, &n) != EOF; printf("%lld\n", ans), ans = 0, memset(b, 0, sizeof b))
    {
        for (int i = 1; i <= n; i++)
        {
            a[i].next = a[i].come = read(), a[i].tot = read(), memset(a[i].is_read, 0, sizeof a[i].is_read);
            for (int j = 1; j <= a[i].tot; j++)
                a[i].idx[j] = read(), a[i].val[j] = read();
        }
        for (int i = 0; i <= T - 1; i++)
            for (int j = 1; j <= n; j++)
                if (a[j].next <= i)
                {
                    bool flag = false;
                    for (int k = 1; k <= a[j].tot; k++)
                        if (b[a[j].idx[k]] <= i and !a[j].is_read[k])
                        {
                            a[j].is_read[k] = flag = true;
                            b[a[j].idx[k]] = a[j].next = i + a[j].val[k];
                            ++ans;
                            break;
                        }
                    if (!flag)
                    {
                        int min = INF, x = 0;
                        for (int k = 1; k <= a[j].tot; k++)
                            if (min > b[a[j].idx[k]] and !a[j].is_read[k])
                                min = b[a[j].idx[k]], x = k;
                        if (min < T)
                        {
                            a[j].is_read[x] = true;
                            b[a[j].idx[x]] += a[j].val[x];
                            a[j].next = b[a[j].idx[x]];
                            ++ans;
                        }
                    }
                }
    }
    return 0;
}