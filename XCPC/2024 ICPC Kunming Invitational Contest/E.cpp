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
const int N = 3e5 + 5;
int n, k, m;
int a[N], pre[N], suf[N];
void solve()
{
    n = read(), k = read();
    using std::__gcd;
    for (int i = 1; i <= n; i++) a[i] = read();
    vector<int> pos;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = __gcd(pre[i - 1], a[i]);
        if (pre[i] ^ pre[i - 1]) pos.pb(i);
    }
    suf[n + 1] = 0;
    for (int i = n; i >= 1; i--) suf[i] = __gcd(suf[i + 1], a[i]);
    int ans = 0;
    for (auto l : pos)
    {
        int cum = pre[l - 1];
        for (int r = l; r <= n; r++)
        {
            cum = __gcd(cum, a[r] + k);
            ans = std::max(ans, __gcd(cum, suf[r + 1]));
        }
    }
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("E.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}