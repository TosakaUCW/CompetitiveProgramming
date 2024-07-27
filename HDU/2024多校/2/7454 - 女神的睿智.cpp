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
    string s; cin >> s;
    if (s[0] == s[4]) return cout << s[0] << '\n', void();
    int num0 = 0, num1 = 0;
    for (int i = 0; i < 8; i++)
        num0 += (s[i] == s[0]), num1 += (s[i] == s[4]);

    if (num0 == num1) cout << "N\n";
    else if (num0 > num1) cout << s[0] << '\n';
    else cout << s[4] << '\n';
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