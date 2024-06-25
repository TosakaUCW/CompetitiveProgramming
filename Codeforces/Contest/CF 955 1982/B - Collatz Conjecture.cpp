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
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int go(int x, int y, int k)
{
    int m = y - (x % y);
    if (k < m) return x + k;
    k -= m, x += m;
    if (x == y) return (k % (y - 1)) + 1;
    for (; x % y == 0; x /= y);
    return go(x, y, k);
}

void solve() 
{ 
    int x = read(), y = read(), k = read();
    cout << go(x, y, k) << '\n'; 
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