#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
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

void solve()
{
    i64 h = read(), n = read();
    vector<i64> a(n), c(n);
    for (auto &x : a) x = read();
    for (auto &x : c) x = read();
    auto check = [&](i64 x) -> bool
    {
        i128 s = 0;
	    for(int i = 0; i < n; i++)
		    s += a[i] * __int128((x - 1) / c[i] + 1);
    	return s >= h;
    };
    i64 l = 0, r = 1e12;
    while (l + 1 < r)
    {
        i64 m = l + r >> 1;
        if (check(m)) r = m;
        else l = m;
    }
    cout << r << '\n';
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