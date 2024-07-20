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
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

i64 TEN(int x) { return x == 0 ? 1 : TEN(x - 1) * 10LL; }

void solve()
{
    i64 n = read() - 1;
    if (n == 0) return puts("0"), void();
    for (int d = 1; ; d++)
    {
        i64 x = (d + 1) / 2;
        if (n <= 9 * TEN(x - 1))
        {
            string s = std::to_string(TEN(x - 1) + n - 1);
            s.resize(d, ' ');
            for (int i = x; i < d; i++) s[i] = s[d - 1 - i];
            cout << s << '\n';
            return;
        }
        else
            n -= 9 * TEN(x - 1);
    }
    // cout << n << '\n';
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