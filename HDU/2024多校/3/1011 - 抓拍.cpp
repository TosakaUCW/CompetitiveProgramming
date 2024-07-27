#include <cstdio>
#include <iostream>
typedef long long ll;
const int N = 200010;
const ll inf = 1LL << 60;
int n, i;
ll l, r, mid, ans, x[N], y[N], a[N], b[N];
inline void umin(ll &a, ll b) { a > b ? (a = b) : 0; }
inline void umax(ll &a, ll b) { a < b ? (a = b) : 0; }
ll cal(ll t)
{
    ll xl = inf, xr = -inf, yl = inf, yr = -inf, tmp;
    for (int i = 1; i <= n; i++)
    {
        tmp = x[i] + a[i] * t;
        umin(xl, tmp), umax(xr, tmp);
        tmp = y[i] + b[i] * t;
        umin(yl, tmp), umax(yr, tmp);
    }
    xr -= xl, yr -= yl;
    // umax(xr, yr);
    return 2 * (xr + yr);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        std::cin >> x[i] >> y[i] >> ch;
        if (ch == 'N') a[i] = 0, b[i] = 1;
        if (ch == 'S') a[i] = 0, b[i] = -1;
        if (ch == 'W') a[i] = -1, b[i] = 0;
        if (ch == 'E') a[i] = 1, b[i] = 0;
    }
    l = 0, r = 3e9;
    while (l <= r)
    {
        // std::cout << mid << '\n';
        mid = (l + r) >> 1;
        if (cal(mid) <= cal(mid + 1))
            r = (ans = mid) - 1;
        else
            l = mid + 1;
    }
    printf("%lld", cal(ans));
    return 0;
}