#include <bits/stdc++.h>
using i64 = long long;
#define int long long
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve()
{
    int n = read(), m = read();
    vector<int> a(n + 1), b(n + 1), c(n + 1), d(n + 1), e(n + 1);
    for (int i = 1; i < n; i++)
        a[i] = read(), b[i] = read(), c[i] = read();
        
    for (int i = 1; i <= m; i++)
    {
        int l = read(), r = read();
        if (l > r) std::swap(l, r);
        d[l]++, d[r]--;
    }
    for (int i = 1; i <= n; i++)
        e[i] = e[i - 1] +  d[i];
    i64 ans = 0;
    for (int i = 1; i <= n; i++) 
    {
        // if (b[i] + c[i] * e[i] < c[i] * a[i])
        ans += std::min(b[i] + c[i] * e[i], e[i] * a[i]);
    }
    cout << ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("train2.in", "r", stdin);
#endif
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}