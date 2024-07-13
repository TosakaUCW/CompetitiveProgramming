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

const int N = 5e6 + 5;
const int P = 1e9 + 7;

void solve()
{
    int n = read();
    std::priority_queue<int> q;
    i64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        if (x == -1) ans += q.top(), q.pop();
        else q.push(x);
    }
    cout << ans;
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