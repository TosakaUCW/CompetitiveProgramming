#include <stdio.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <math.h>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 2e5 + 5;
int n, q;
int a[N], f[N][25], g[N], las[N];

std::unordered_map<int, int> map;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), las[i] = map[a[i]], map[a[i]] = i;
    for (int i = 1; i <= n; i++) g[i] = std::max(g[i - 1], las[i] + 1);
    for (int i = 1; i <= n; i++) f[i][0] = i - g[i] + 1;
    for (int j = 1; j <= 23; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = std::max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    while (q--)
    {
        int ql = read() + 1, qr = read() + 1, pos = qr;
        for (int l = ql, r = qr; l <= r; )
        {
            int mid = l + r >> 1;
            if (g[mid] >= ql) pos = mid, r = mid - 1;
            else l = mid + 1;
        }
        int k = log2(qr - pos + 1);
        int res = std::max(f[pos][k], f[qr - (1 << k) + 1][k]);
        printf("%d\n", g[pos] < ql ? pos - ql + 1 : std::max(res, pos - ql));
    }
    // for (int i = 1; i <= n; i++) printf("%d ", f[i]);
    return 0;
}
/*
f[i]以i结尾的最大长度，g[i]开头
g[i] = max(g[i - 1], las[i] + 1)
f[i] = i - g[i] + 1
g[i]单增，i belong [l, r], find min pos that g[pos]>=L -> 二分
对于[pos, R], find max(f[i])
对于[L, pos), g[pos] < L -> max_len = pos - L
*/