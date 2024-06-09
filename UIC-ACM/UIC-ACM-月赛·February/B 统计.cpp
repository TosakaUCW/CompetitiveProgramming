#include <bits/stdc++.h>
#define int long long
#define pb push_back
using std::cin, std::cout, std::string;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 2e5 + 5;
const int INF = 1 << 30;
// const long long INF = 1LL << 60;
int n, q, a[N], lft[N], rgt[N], bel[N];
void solve()
{
    n = read(), q = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) lft[i] = a[i] == a[i - 1] ? lft[i - 1] : i;
    for (int i = n; i >= 1; i--) rgt[i] = a[i] == a[i + 1] ? rgt[i + 1] : i;
    int nodecnt = 0;
    for (int i = 1; i <= n; i++) bel[i] = nodecnt, nodecnt += (rgt[i] == i);
    // for (int i = 1; i <= n; i++) cout << bel[i] << ' ';
    // puts("-------");
    // for (int i = 1; i <= n; i++)
    for (int l, r; q; q--)
    {
        l = read(), r = read();
        cout << bel[r] - bel[l] + 1 << '\n';
        // cout << q << '\n';
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}