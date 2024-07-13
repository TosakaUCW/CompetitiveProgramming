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
    string s, t; cin >> s >> t;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != t[i])
        {
            if (s[i + 1] == '0')
                s[i + 1] = '1';
            else
                s[i + 1] = '0';
        }
    }
    if (s[n - 1] == t[n - 1]) puts("YES");
    else puts("NO");
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