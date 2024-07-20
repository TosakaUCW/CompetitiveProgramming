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
    int n = read(), k = read();
    string s; cin >> s;
    std::sort(s.begin(), s.end());
    // vector<char> s;
    // for (auto ch : t) s.pb(ch);
    int ans = 0;
    do
    {
        bool f = 1;
        for (int i = 0; i + k - 1 < n; i++)
        {
            int L = i, R = i + k - 1;
            bool flag = 1;
            for (int j = 0; j < k; j++)
            {
                if (s[L + j] != s[R - j]) flag = 0;
            }
            if (flag) f = 0;
        }
        if (f) ans++;
        // for (auto ch : s) cout << ch;
        // puts("");
        // cout << s << '\n';
    } while (std::next_permutation(s.begin(), s.end()));
    cout << ans << '\n';
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