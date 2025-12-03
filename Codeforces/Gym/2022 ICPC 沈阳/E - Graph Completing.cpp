#include <bits/stdc++.h>
using i64 = long long;
#define int i64
using std::cerr;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

using pii = std::pair<int, int>;
struct EBCC {
    int n, cur, cnt;
    vector<vector<int>> adj;
    vector<int> stk, dfn, low, bel;
    EBCC() {}
    EBCC(int n) { init(n); }
    void init(int n) {
        this->n = n;
        adj.assign(n, {}), dfn.assign(n, -1);
        low.resize(n), bel.assign(n, -1);
        stk.clear(), cur = cnt = 0;
    }
    void addEdge(int u, int v) { adj[u].push_back(v), adj[v].push_back(u); }
    void dfs(int x, int p) {
        dfn[x] = low[x] = cur++, stk.push_back(x);
        for (auto y : adj[x]) {
            if (y == p) continue;
            if (dfn[y] == -1)
                dfs(y, x), low[x] = std::min(low[x], low[y]);
            else if (bel[y] == -1)
                low[x] = std::min(low[x], dfn[y]);
        }
        if (dfn[x] == low[x]) {
            int y;
            do { y = stk.back(), bel[y] = cnt, stk.pop_back(); } while (y != x);
            cnt++;
        }
    }
    std::vector<int> work() { return dfs(0, -1), bel; }
    struct Graph {
        int n;
        vector<pii> edges;
        vector<int> siz, cnte;
    };
    Graph compress() {
        Graph g; g.n = cnt;
        g.siz.resize(cnt), g.cnte.resize(cnt);
        for (int i = 0; i < n; i++) {
            g.siz[bel[i]]++;
            for (auto j : adj[i]) {
                if (bel[i] < bel[j]) g.edges.emplace_back(bel[i], bel[j]);
                else if (i < j and bel[i] == bel[j]) g.cnte[bel[i]]++;
            }
        }
        return g;
    }
};

template <class T>
constexpr T power(T a, i64 b) { T res {1}; for (; b; b /= 2, a *= a) if (b % 2) res *= a; return res; }
constexpr i64 mul(i64 a, i64 b, i64 p) { i64 res = a * b - (i64)(1.L * a * b / p) * p; res %= p; if (res < 0) res += p; return res; }
template <i64 P>
struct MInt {
    i64 x;
    constexpr MInt() : x {0} {}
    constexpr MInt(i64 x) : x {norm(x % getMod())} {}
    static i64 Mod;
    constexpr static i64 getMod() { return P > 0 ? P : Mod; }
    constexpr static void setMod(i64 Mod_) { Mod = Mod_; }
    constexpr i64 norm(i64 x) const { if (x < 0) x += getMod(); if (x >= getMod()) x -= getMod(); return x; }
    constexpr i64 val() const { return x; }
    constexpr MInt operator-() const { MInt res; res.x = norm(getMod() - x); return res; }
    constexpr MInt inv() const { return power(*this, getMod() - 2); }
    constexpr MInt &operator*=(MInt rhs) & { if (getMod() < (1ULL << 31)) x = x * rhs.x % int(getMod()); else x = mul(x, rhs.x, getMod()); return *this; }
    constexpr MInt &operator+=(MInt rhs) & { x = norm(x + rhs.x); return *this; }
    constexpr MInt &operator-=(MInt rhs) & { x = norm(x - rhs.x); return *this; }
    constexpr MInt &operator/=(MInt rhs) & { return *this *= rhs.inv(); }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) { MInt res = lhs; res *= rhs; return res; }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) { MInt res = lhs; res += rhs; return res; }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) { MInt res = lhs; res -= rhs; return res; }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) { MInt res = lhs; res /= rhs; return res; }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) { i64 v; is >> v; a = MInt(v); return is; }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) { return os << a.val(); }
    friend constexpr bool operator==(MInt lhs, MInt rhs) { return lhs.val() == rhs.val(); }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) { return lhs.val() != rhs.val(); }
    friend constexpr bool operator<(MInt lhs, MInt rhs) { return lhs.val() < rhs.val(); }
};
template <>
i64 MInt<0>::Mod = 998244353;
constexpr int P = 998244353;
using Z = MInt<P>;

void solve() {
    int n = read(), m = read();

    EBCC g(n);
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        u--, v--;
        g.addEdge(u, v);
    }
    g.work();
    auto G = g.compress();

    vector<Z> pw(n + 1), comp(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * 2;
    }
    comp[0] = 1;
    for (int i = 1; i <= n; i++) {
        comp[i] = comp[i - 1] * pw[n];
    }

    int N = n;
    n = G.n;

    auto pow2 = [&](int b) {
        return pw[b % N] * comp[b / N];
    };

    vector<vector<int>> adj(n);
    for (auto [x, y] : G.edges) {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector dp(n, vector<Z>(N + 1));
    vector<int> siz(n);
    std::function<void(int, int)> dfs = [&](int u, int fa) {
        siz[u] = G.siz[u];
        dp[u][siz[u]] = pow2(siz[u] * (siz[u] - 1) / 2 - G.cnte[u]);

        for (auto v : adj[u]) {
            if (v == fa) continue;
            dfs(v, u);

            vector<Z> ndp(N + 1);
            for (int i = 1; i <= siz[u]; i++) {
                for (int j = 1; j <= siz[v]; j++) {
                    ndp[i + j] += dp[u][i] * dp[v][j] * pow2(i * j - 1);
                    ndp[i] -= dp[u][i] * dp[v][j];
                }
            }

            dp[u] = std::move(ndp);
            siz[u] += siz[v];
        }
    };
    dfs(0, -1);

    Z ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += dp[0][i];
    }

    cout << ans << "\n";
}

signed main() {
    solve();
    return 0;
}