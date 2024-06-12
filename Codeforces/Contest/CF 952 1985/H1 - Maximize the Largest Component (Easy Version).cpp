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

struct DSU 
{
    std::vector<int> f, siz;
    DSU() {}
    DSU(int n) { init(n); }
    void init(int n) { f.resize(n), std::iota(f.begin(), f.end(), 0), siz.assign(n, 1); }
    int find(int x) { while (x != f[x]) x = f[x] = f[f[x]]; return x; }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) 
    {
        x = find(x), y = find(y);
        if (x == y) return false;
        siz[x] += siz[y], f[y] = x;
        return true;
    }
    int size(int x) { return siz[find(x)]; }
};

const int N = 2e5;

void solve()
{
    int n = read(), m = read();
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    
    const int N = n * m;
    DSU dsu(N);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i + 1 < n and s[i][j] == '#' and s[i + 1][j] == '#')
                dsu.merge(i * m + j, (i + 1) * m + j);
            if (j + 1 < m and s[i][j] == '#' and s[i][j + 1] == '#')
                dsu.merge(i * m + j, i * m + j + 1);
        }
        
    vector<int> vis(N, -1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int res = 0;
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '.') res++;
            for (int k = std::max(0, i - 1); k <= std::min(i + 1, n - 1); k++)
                if (s[k][j] == '#')
                {
                    int u = dsu.find(k * m + j);
                    if (vis[u] != i) vis[u] = i, res += dsu.size(u);
                }
        }
        ans = std::max(ans, res);
    }
    
    vis.assign(N, -1);
    for (int j = 0; j < m; j++)
    {
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i][j] == '.') res++;
            for (int k = std::max(0, j - 1); k <= std::min(j + 1, m - 1); k++)
                if (s[i][k] == '#')
                {
                    int u = dsu.find(i * m + k);
                    if (vis[u] != j) vis[u] = j, res += dsu.size(u);
                }
        }
        ans = std::max(ans, res);
    }
    
    cout << ans << '\n';
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