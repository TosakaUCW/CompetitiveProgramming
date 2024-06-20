#include <bits/stdc++.h>
#define int long long
using pii = std::pair<int, int>;
using std::vector, std::cout, std::cin;
#define fi first
#define se second
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
void solve()
{
    int n = read(), ans = 0;
    vector<pii> a(n);
    for (auto &[x, y] : a) x = read(), y = read();
    std::sort(a.begin(), a.end());
    for (int i = 0, j = n - 1; i < j; )
    {
        int k = std::min(a[i].se, a[j].se);
        ans += (a[j].fi - a[i].fi) * k;
        a[i].se -= k, a[j].se -= k;
        if (!a[i].se) i++;
        if (!a[j].se) j--;
    }
    cout << ans << '\n';
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}