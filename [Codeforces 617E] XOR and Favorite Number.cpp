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

#define int long long

const int N = 1e6 + 5;

int n, m, k, len, res;
int bel[N], cnt[N << 1];
int sum[N], ans[N];

struct Node
{
    int L, R, idx;
    bool friend operator<(Node a, Node b) { return bel[a.L] != bel[b.L] ? a.L < b.L : (bel[a.L] & 1 ? a.R < b.R : a.R > b.R); }
} q[N];

void add(int p) { res += cnt[sum[p] ^ k], cnt[sum[p]]++; }

void del(int p) { cnt[sum[p]]--, res -= cnt[sum[p] ^ k]; }

signed main()
{
    n = read(), m = read(), k = read(), len = sqrt(n);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] ^ read(), bel[i] = (i - 1) / len + 1;
    for (int i = 1; i <= m; i++)
        q[i].L = read() - 1, q[i].R = read(), q[i].idx = i;
    std::sort(q + 1, q + 1 + m);
    for (int L = 1, R = 0, i = 1; i <= m; ans[q[i++].idx] = res)
    {
        while (q[i].L < L)
            add(--L);
        while (q[i].R > R)
            add(++R);
        while (q[i].L > L)
            del(L++);
        while (q[i].R < R)
            del(R--);
    }
    for (int i = 1; i <= m; i++)
        printf("%lld\n", ans[i]);
    return 0;
}