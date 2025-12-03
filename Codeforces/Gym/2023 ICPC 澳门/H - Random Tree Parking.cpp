#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr, std::ostream;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

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
struct Comb {
    int n;
    std::vector<Z> _fac, _invfac, _inv;
    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() { init(n); }
    void init(int m) {
        m = std::min<i64>(m, Z::getMod() - 1);
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);
        for (int i = n + 1; i <= m; i++) _fac[i] = _fac[i - 1] * i;
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) _invfac[i - 1] = _invfac[i] * i, _inv[i] = _invfac[i] * _fac[i - 1];
        n = m;
    }
    Z fac(int m) { if (m > n) init(2 * m); return _fac[m]; }
    Z invfac(int m) { if (m > n) init(2 * m); return _invfac[m]; }
    Z inv(int m) { if (m > n) init(2 * m); return _inv[m]; }
    Z binom(int n, int m) { if (n < m || m < 0) return 0; return fac(n) * invfac(m) * invfac(n - m); }
} comb;

void solve() {
    int n; cin >> n;
    
    vector<int> dep(n + 1);
    dep[1] = 1;
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        dep[i] = dep[x] + 1;
        g[x].eb(i);
    }

    vector<int> siz(n + 1);
    vector<vector<Z>> dp(n + 1);
    for (int u = n; u; u--) {
        dp[u].assign(dep[u] + 1, 1);
        // dp[u] = vector<Z>(dep[u] + 1, 1);
        for (int v : g[u]) {

            vector<Z> ndp(dep[u] + 1);
            for (int i = 0; i <= dep[u]; i++) {
                for (int j = 0; i + j <= dep[u]; j++) {
                    ndp[i + j] += dp[u][i] * dp[v][j]
                                * comb.binom(siz[u] + siz[v] + i + j, siz[u] + i);
                }
            }
            dp[u] = std::move(ndp);
            siz[u] += siz[v];
        }

        siz[u]++;
        for (int i = 0; i < dep[u]; i++) {
            dp[u][i] = dp[u][i + 1];
        }
    }
    cout << dp[1][0];
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}