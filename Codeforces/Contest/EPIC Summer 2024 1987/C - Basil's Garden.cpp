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
    vector<i64> f(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();
    int ans = a[n];
    for (int i = n - 1; i >= 1; i--) ans = std::max(ans + 1, a[i]);
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
3 1 3 1

1 1 1 0

1 1 1 0

1 1 0 0

1 0 0 0

0 0 0 0
*/