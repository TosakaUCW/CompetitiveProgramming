#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;
int n, m, S, ans = 1LL << 62;
int w[N], v[N];
int l[N], r[N];
int c[N], s[N];

int judge(int W, int res = 0)
{
    for (int i = 1; i <= std::max(n, m); i++)
        c[i] = s[i] = 0;
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + v[i] * (w[i] >= W),
        c[i] = c[i - 1] + (w[i] >= W);
    for (int i = 1; i <= m; i++)
        res += (c[r[i]] - c[l[i] - 1]) * (s[r[i]] - s[l[i] - 1]);
    ans = std::min(ans, llabs(res - S));
    return res > S;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    n = read(), m = read(), S = read();
    for (int i = 1; i <= n; i++) 
        w[i] = read(), v[i] = read();
    for (int i = 1; i <= m; i++) 
        l[i] = read(), r[i] = read();
    for (int L = 0, R = 1e6 + 5; L <= R; )
    {
        int mid = (L + R) >> 1;
        if (judge(mid)) L = mid + 1;
        else R = mid - 1;
    }
    printf("%lld", ans);
    return 0;
}