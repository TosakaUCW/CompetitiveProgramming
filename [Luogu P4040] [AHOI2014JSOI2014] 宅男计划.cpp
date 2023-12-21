#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e2 + 5;
int m, f, n;
std::pair<int, int> a[N];
#define fi first
#define se second

int calc(int X)
{
    int M = m - X * f, t = 0, ans = 0;
    if (M <= 0)
        return 0;
    for (int i = 1; i <= n; i++)
        if (a[i].se > t)
        {
            int d = a[i].se - t;
            if (1.0 * a[i].fi * X * d <= M)
                ans += X * d, M -= a[i].fi * X * d;
            else
            {
                ans += M / a[i].fi;
                break;
            }
            t = a[i].se;
        }
    return ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    m = read(), f = read(), n = read();
    for (int i = 1; i <= n; i++)
        a[i].fi = read(), a[i].se = read() + 1;
    std::sort(a + 1, a + 1 + n);
    int l = 0, r = m / f + 1;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (calc(mid - 1) >= calc(mid + 1))
            r = mid;
        else
            l = mid;
    }
    printf("%lld\n", std::max(calc(l), calc(r)));
    return 0;
}