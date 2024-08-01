#include <bits/stdc++.h>
// #define int long long
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
const int N = 1e6 + 5;
// const int INF = 1e18;
void solve()
{
    int n = read(), ans = 1e9;
    vector<int> a(n);
    for (auto &x : a) x = read();
    for (int i = 1; i < n; i++)
        ans = std::min(ans, std::max(a[i], a[i - 1]));
    cout << ans - 1 << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("E.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}