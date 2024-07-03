#include <bits/stdc++.h>
using i64 = long long;
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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();
    i64 ans = 0;
    vector<int> b;
    
    b.pb(0);
    for (int i = 2; i <= n; i++)
        if (a[i] < a[i - 1])
            b.pb(a[i - 1] - a[i]), a[i] = a[i - 1];
    std::sort(b.begin(), b.end());
    
    int m = b.size();
    
    for (int i = 1; i < m; i++)
        ans += 1LL * (m - i + 1) * (b[i] - b[i - 1]);
    
    cout << ans << '\n';
}

// 1 2 3 4 5

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}