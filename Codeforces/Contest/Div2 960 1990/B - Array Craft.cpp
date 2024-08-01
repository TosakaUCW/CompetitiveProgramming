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
    int n = read(), x = read(), y = read();
    vector<int> a(n + 2, 1);
    for (int i = x + 1; i <= n; i++) a[i] = -a[i - 1];
    for (int i = y - 1; i >= 1; i--) a[i] = -a[i + 1];
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    puts("");
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