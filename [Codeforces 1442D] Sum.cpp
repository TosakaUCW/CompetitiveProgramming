#include <vector>
#include <stdio.h>
#include <algorithm>
#define int long long
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 3e3 + 5;

int n, k;
int s[N], c[N];
std::vector<int> a[N], f;
int ans;

void solve(int l, int r)
{
    // printf("%d %d\n", l, r);
    if (l == r)
    {
        for (int i = 0, res = 0; i < std::min(k, c[l]); i++)
            res += a[l][i], ans = std::max(ans, res + f[k - i - 1]);
        return;
    }
    int mid = (l + r) >> 1;
    std::vector tmp = f;
    for (int i = l; i <= mid; i++)
        for (int j = k; j >= c[i]; j--)
            f[j] = std::max(f[j], f[j - c[i]] + s[i]);
    solve(mid + 1, r);
    f = tmp;
    for (int i = mid + 1; i <= r; i++)
        for (int j = k; j >= c[i]; j--)
            f[j] = std::max(f[j], f[j - c[i]] + s[i]);
    solve(l, mid);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    n = read(), k = read(), f.resize(k + 100);
    for (int i = 1; i <= n; i++)
    {
        c[i] = read();
        for (int j = 0; j < c[i]; j++)
            a[i].emplace_back(read()), s[i] += a[i][j];
    }
    solve(1, n);
    printf("%lld\n", ans);
    return 0;
}