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
const int N = 2e3 + 5;
void solve()
{
    int n = read(), m = read();
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<std::bitset<2000>>> cnt(m, vector<std::bitset<2000>>(1000));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = read() - 1, cnt[j][a[i][j]][i] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        std::bitset<2000> s{};
        for (int j = 0; j < m; j++)
            s ^= cnt[j][a[i][j]];
        s[i] = 0;
        ans += s.count();
    }
    cout << ans / 2;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("F.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}