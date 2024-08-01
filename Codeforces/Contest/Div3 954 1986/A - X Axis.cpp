#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;

int x[5];

void solve()
{
    for (int i = 1; i <= 3; i++) x[i] = read();
    std::sort(x + 1, x + 4);
    int ans = 1e9;
    for (int i = x[1]; i <= x[3]; i++)
        ans = std::min(ans, abs(i - x[1]) + abs(i - x[2]) + abs(i - x[3]));
    cout << ans << "\n";
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