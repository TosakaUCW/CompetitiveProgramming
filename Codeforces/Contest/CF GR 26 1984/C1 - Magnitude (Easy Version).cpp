#include <bits/stdc++.h>
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
const int N = 2e5;
const int P = 998244353;
void solve()
{
    int n = read(), c = 0;
    int min = 0, max = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        int a = min + x, b = max + x;
        min = std::min({a, b, abs(a), abs(b)});
        max = std::max({a, b, abs(a), abs(b)});
    }
    cout << max << '\n';   
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}