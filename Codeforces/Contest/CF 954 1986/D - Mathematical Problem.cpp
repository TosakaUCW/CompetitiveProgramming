#include <bits/stdc++.h>
using i64 = long long;
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

const int N = 2e5 + 5;

void solve()
{
    int n = read(), ans = 1e9;
    string s; cin >> s;
    if (n == 2) return cout << (s[0] - '0') * 10 + s[1] - '0' << "\n", void();
    for (int i = 0; i < n; i++)
        if (s[i] == '0' and (i + 2 < n or i >= 2))
            return cout << "0\n", void();
    for (int j = 1; j < n; j++)
    {
        int res = 0;
        for (int k = 0; k < n; k++)
            if (k + 1 == j)
            {
                if ((s[k] - '0') * 10 + s[j] - '0' != 1)
                    res += (s[k] - '0') * 10 + s[j] - '0';
                k++;
            }
            else
            {
                if (s[k] != '1')
                    res += s[k] - '0';
            }
        ans = std::min(std::max(res, 1), ans);
    }
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