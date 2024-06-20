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
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 5e5 + 5;

int a[N], q[N], pre[N], f[N];

void solve()
{
    int n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    a[++n] = 0;
    for (int i = 1; i <= n; i++) pre[i] = 0;
    int m = read();
    for (int i = 1; i <= m; i++)
    {
        int l = read(), r = read();
        pre[r + 1] = std::max(pre[r + 1], l);
    }
    pre[1] = 0;
    for (int i = 2; i <= n; i++) pre[i] = std::max(pre[i], pre[i - 1]);
    int h = 1, t = 0;
    q[++t] = 0;
    for (int i = 1; i <= n; i++)
    {
        while (h <= t and q[h] < pre[i]) h++;
        f[i] = f[q[h]] + a[i];
        while (h <= t and f[q[t]] >= f[i]) t--;
        q[++t] = i;
    }
    cout << f[n] << '\n';
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