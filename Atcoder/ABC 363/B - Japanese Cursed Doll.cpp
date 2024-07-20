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
    int n = read(), t = read(), p = read();
    vector<int> a(n + 1), b;
    int cnt = 0;
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= t) cnt++;
        else b.pb(a[i]);
    }
    std::sort(b.rbegin(), b.rend());
    p -= cnt;
    if (p <= 0) return puts("0"), void();
    int ans = 0;
    for (int x : b)
    {
        ans = t - x;
        p--;
        if (p == 0) break;
    }
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}