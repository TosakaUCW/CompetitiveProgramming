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

const int N = 2e5 + 5;

void solve()
{
    int n = read();
    vector<int> a(n + 1), b(n + 1);
    
    i64 ans = 0;
    
    for (int i = 1; i <= n; i++) a[i] = read();
    
    for (int t = 0; t < 2; t++)
    {
        vector<int> cnt(n + 1);
        int mx = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += a[i];
            cnt[a[i]]++;
            if (cnt[a[i]] >= 2) mx = std::max(mx, a[i]);
            a[i] = mx;
        }
    }
    
    for (int i = 1; i <= n; i++) ans += 1LL * (n - i + 1) * a[i];
    cout << ans << '\n';
}
/*
2 1 1 2

0 0 1 2
0 0 0 0
*/

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}