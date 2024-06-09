#include <bits/stdc++.h>
// #define int long long
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
int n, m, a[N], ind[N];
std::vector<int> g[N];
bool toposort()
{
    int cnt = 0; std::queue<int> Q;
    for (int i = 1; i <= n; i++) if (!ind[i]) Q.push(i);
    for (int u; !Q.empty(); )
    {
        u = Q.front(), Q.pop(), cnt++;
        for (auto v : g[u]) if (!--ind[v]) Q.push(v);
    }
    return cnt == n;
}
void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++) g[i].clear(), ind[i] = 0;
    while(m--)
    {
        for (int i = 1; i <= n; i++) a[i] = read();
        for (int i = 2; i < n; i++) g[a[i]].pb(a[i + 1]), ind[a[i + 1]]++;
    }
    puts(toposort() ? "YES" : "NO");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("F.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}