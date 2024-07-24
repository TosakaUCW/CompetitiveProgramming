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

const double eps = 1e-7;

void solve()
{
    i64 n = read();
    
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();
    
    for (int i = 1; i <= n; i++) if (a[i] < a[i - 1] and a[i] == 1) return puts("-1"), void();
    
    vector<i64> c(n + 1);
    for (int i = 1; i < n; i++)
    {
        c[i + 1] = std::ceil(c[i] + log2(log(a[i]) / log(a[i + 1])));
        c[i + 1] = std::max(c[i + 1], 0LL);
    }
    
    i64 ans = 0;
    for (int i = 1; i <= n; i++) ans += c[i];
    // for (int i = 1; i <= n; i++) cout << c[i] << ' ';
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}

/*

2^x loga[i] <= 2^y logb[i]

*/