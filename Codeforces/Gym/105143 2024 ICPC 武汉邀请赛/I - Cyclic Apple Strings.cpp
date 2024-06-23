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
const int N = 1e6 + 5;
// const int INF = 1e18;
int n, m;

void solve()
{
    string s;
    cin >> s;
    std::reverse(s.begin(), s.end());
    // for (auto ch : s) cout << ch;
    int flag = 0, ans = 0;
    char las = '1';
    for (auto ch : s)
    {
        if (!flag and ch == '1') continue;
        if (ch == '0') flag = 1;
        if (ch == '1' and las == '0') ans++;
        las = ch;
    }
    cout << ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("B.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}