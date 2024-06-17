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
    string s, t;
    cin >> s >> t;
    s = " " + s, t = " " + t;
    auto check = [&](int i, int l, int r)
    {
        if (s[i] == '1')
            return true;
        if ((i - 1 < l or t[i - 1] == '0') and (i - 2 < l or s[i - 2] == '1'))
            return false;
        if (i + 1 <= r and t[i + 1] == '1')
            return true;
        return i + 2 <= r and s[i + 2] == '0';
    };
    vector<int> p(n + 1);
    for (int i = 0; i <= n; i++) 
        p[i] = p[i - 1] + check(i, 1, n);
    for (int q = read(); q--; )
    {
        int l = read(), r = read(), ans = 0;
        if (r - l <= 4) 
            for (int i = l; i <= r; i++) ans += check(i, l, r);
        else
        {
            ans = p[r - 2] - p[l + 1];
            for (int i : {l, l + 1, r - 1, r})
                ans += check(i, l, r);
        }
        cout << ans << '\n';
    }
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