#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 2e5 + 5;
const double rps = 1e-7;
int n, idx[N];
double st[N], ed[N];
bool judge(double x)
{
    double l = st[idx[1]];
    for (int i = 2; i <= n; i++)
    {
        if (l + x > ed[idx[i]]) return 0;
        l += x, l = std::max(l, st[idx[i]]);
    }
    return 1;
}
void solve()
{
    for (int i = 1; i <= n; i++)
        st[i] = read(), ed[i] = read(), idx[i] = i;
    double ans = 0;
    do
    {
        double l = 0, r = 1e9;
        while (r - l > rps)
        {
            double mid = (l + r) / 2;
            if (judge(mid)) l = mid;
            else r = mid;
        }
        ans = std::max(ans, r);
    } while (std::next_permutation(idx + 1, idx + 1 + n));
    ans *= 60;
    printf("%d:%02d\n", (int) ans / 60, (int)(fmod(ans, 60) + 0.5));
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int cas = 1; std::cin >> n and n; cas++) printf("Case %d: ", cas), solve();
    return 0;
}