#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector, std::cerr;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
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
    int n = read();

    vector<int> val(n + 1), idx(n + 1);
    vector<vector<int>> g(n + 1);

    for (int i = 1; i <= n; i++) {
        val[i] = read();
        idx[val[i]] = i;
    }
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        g[u].pb(v), g[v].pb(u);
    }

    vector<Z> dp(n + 1);
    vector<int> fa(n + 1), vis(n + 1);
    auto dfs = [&](auto self, int u, int f) -> void {
        dp[u] = 1, fa[u] = f;
        for (int v : g[u]) {
            if (v == f) continue;
            self(self, v, u);
            dp[u] *= (dp[v] + 1);
        }
    };

    int rt = idx[0];
    dfs(dfs, rt, 0);

    Z ans = dp[rt], now = ans;
    vis[rt] = 1;

    for (int i = 1; i < n; i++) {
        int u = idx[i];
        if (!vis[u]) {
            vector<int> stk;
            int v = u;
            do {
                stk.pb(v);
                v = fa[v];
            } while (!vis[v]);
            for (int x : stk) {
                vis[x] = 1;
                now /= (dp[x] + 1);
                now *= dp[x];
            }
        }
        ans += now;
    }
    cout << ans << '\n';
}

/*
*/

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}