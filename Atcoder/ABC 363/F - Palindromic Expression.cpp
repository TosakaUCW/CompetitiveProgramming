#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
i64 read(i64 x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

std::map<i64, string> vis;
using std::to_string;

i64 rev(i64 x)
{
    string s = to_string(x);
    reverse(s.begin(), s.end());
    return stoll(s);
}

string f(i64 x)
{
    if (vis.count(x)) return vis[x];
    if (to_string(x).find('0') == string::npos && x == rev(x)) return to_string(x);
    for (i64 i = 2; i * i <= x; i++)
    {
        if (to_string(i).find('0') != string::npos) continue;
        if (x % i == 0 && (x / i) % rev(i) == 0)
        {
            string tmp = f(x / i / rev(i));
            if (tmp != "")
            {
                string ret = to_string(i) + "*" + tmp + "*" + to_string(rev(i));
                vis[x] = ret;
                return ret;
            }
        }
    }
    return "";
}

void solve()
{
    i64 n = read();
    string ans = f(n);
    cout << (ans == "" ? "-1" : ans) << '\n';
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