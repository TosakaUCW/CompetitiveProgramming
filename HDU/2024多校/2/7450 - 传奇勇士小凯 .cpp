/*
HDU
*/
#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin;
using std::cout;
using std::string;
using std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve()
{
    int n = read();
    vector<int> p(n + 1);
    vector<vector<int>> g(n + 1);
    
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), g[u].pb(v), g[v].pb(u);
        
    for (int i = 1; i <= n; i++) p[i] = read();
    
    vector<i64> f(n + 1);
	const i64 D = 360360;
    std::function<void(int, int)> dfs = [&](int u, int fa)
    {
        for (int v : g[u])
        {
            if (v == fa) continue;
            dfs(v, u);
            f[u] = std::max(f[u], f[v]);
        }
        f[u] += D / p[u] * 15;
    };
    
    dfs(1, 0);
	i64 A = f[1], B = D;
	i64 gcd = std::__gcd(A, B);
	cout << A / gcd << '/' << B / gcd << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}
/*
HDU
*/