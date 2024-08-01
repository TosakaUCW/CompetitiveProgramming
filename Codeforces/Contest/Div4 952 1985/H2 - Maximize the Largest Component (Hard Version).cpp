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
        
        
    std::vector<int> cntr(n), cntc(m);
    std::vector<int> minx(N, n), maxx(N, -1), miny(N, m), maxy(N, -1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '.') cntr[i]++, cntc[j]++;
            else
            {
                int u = dsu.find(i * m + j);
                minx[u] = std::min(minx[u], std::max(0, i - 1));
                miny[u] = std::min(miny[u], std::max(0, j - 1));
                maxx[u] = std::max(maxx[u], std::min(n - 1, i + 1));
                maxy[u] = std::max(maxy[u], std::min(m - 1, j + 1));
            }
    
    std::vector f(n, std::vector<int>(m));
    
    auto add = [&](int x1, int y1, int x2, int y2, int k)
    {
        f[x1][y1] += k;
        if (y2 + 1 < m) f[x1][y2 + 1] -= k;
        if (x2 + 1 < n) f[x2 + 1][y1] -= k;
        if (x2 + 1 < n and y2 + 1 < m) f[x2 + 1][y2 + 1] += k;
    };
    
    for (int i = 0; i < N; i++)
        if (dsu.find(i) == i and s[i / m][i % m] == '#')
        {
            int k = dsu.size(i);
            add(minx[i], 0, maxx[i], m - 1, k);
            add(0, miny[i], n - 1, maxy[i], k);
            add(minx[i], miny[i], maxx[i], maxy[i], -k);
        }
        
    for (int i = 0; i < n; i++)
        for (int j = 1; j < m; j++)
            f[i][j] += f[i][j - 1];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            f[i][j] += f[i - 1][j];
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = std::max(ans, f[i][j] + cntr[i] + cntc[j] - (s[i][j] == '.'));
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