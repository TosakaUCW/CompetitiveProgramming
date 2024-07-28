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

using std::endl;
void solve() 
{
    int n, m;
    cin >> n >> m;
    vector<int> col(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1, u, v; i <= m; i++)
        u = read(), v = read(), g[u].pb(v), g[v].pb(u);
        
    vector<int> p1, p2;
    bool bipart = 1;
    std::function<void(int, int)> dfs = [&](int u, int c)
    {
        col[u] = c;
        if (c == 1) p1.pb(u);
        else p2.pb(u);
        
        for (int v : g[u])
        {
            if (col[v] == col[u]) bipart = 0;
            if (!col[v]) dfs(v, 3 - c);
        }
    };
    dfs(1, 1);
    // for (int i = 1; i <= n; i++) if 

    if (bipart)
    {
        cout << "Bob" << endl;
        for (int i = 1; i <= n; i++)
        {
            int a, b; cin >> a >> b;
            if (a > b) std::swap(a, b);
            if (a == 1)
            {
                if (p1.empty())
                {
                    cout << p2.back() << ' ' << b << endl;
                    p2.pop_back();
                }
                else
                {
                    cout << p1.back() << ' ' << a << endl;
                    p1.pop_back();
                }
            }
            else if (b == 3)
            {
                if (p2.empty())
                {
                    cout << p1.back() << ' ' << a << endl;
                    p1.pop_back();
                }
                else
                {
                    cout << p2.back() << ' ' << b << endl;
                    p2.pop_back();
                }
            }
        }
    }
    else
    {
        cout << "Alice" << endl;
        for (int i = 1, a; i <= n; i++) 
        {
            cout << "1 2" << endl;
            cin >> a >> a;
        }
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}