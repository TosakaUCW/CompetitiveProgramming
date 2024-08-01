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

std::vector<int> minp, primes;
void sieve(int n)
{
    minp.assign(n + 1, 0), primes.clear();
    for (int i = 2; i <= n; i++)
    {
        if (minp[i] == 0) minp[i] = i, primes.push_back(i);
        for (auto p : primes)
        {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) break;
        }
    }
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

const int N = 1e6 + 5;
int las[N];

void solve()
{
    int n = read(), k = read(), m = 2 * n - 1;
    vector<int> a(2 * m + 1), tmp;
    
    // 2n - 1 - n + 1 = n
    for (int i = 1; i <= n; i++) a[n + i - 1] = read();
    for (int i = 1; i <= n; i++) a[i - 1] = a[n + i - 1];
    
    i64 ans = 0;
    DSU dsu(m + 1);
    
    for (int i = 1; i <= m; i++) ans += a[i] == 1 ? n - abs(n - i) : 1;
    
    for (int i = 1; i <= m; i++)
    {
        for (int x = a[i]; x > 1; )
        {
            int p = minp[x];
            if (las[p] and i - las[p] <= k)  ans -= dsu.merge(i, las[p]);
            las[p] = i, tmp.pb(p);
            while (minp[x] == p) x /= p;
        }
    }
    for (auto p : tmp) las[p] = 0;
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    sieve(1e6);
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}

/*
1 4 4 4
4 1 4 4
4 4 1 4
4 4 4 1
*/