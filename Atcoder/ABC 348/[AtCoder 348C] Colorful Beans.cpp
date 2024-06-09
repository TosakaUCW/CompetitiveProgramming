#include <bits/stdc++.h>
// #define int long long
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
int n, m, a[N], b[N];
void solve()
{
    n = read();
    std::map<int, int> c;
    for (int i = 1; i <= n; i++)
    {
        a[i] = read(), b[i] = read();
        c[b[i]] = c[b[i]] == 0 ? a[i] : std::min(c[b[i]], a[i]);
    }
    std::vector<int> ans;
    for (int i = 1; i <= n; i++)
        ans.push_back(c[b[i]]);
    std::sort(ans.rbegin(), ans.rend());
    cout << ans[0];

}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}