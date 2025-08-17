#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

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
i64 MInt<0>::Mod = 1e9 + 7;
constexpr int P = 1e9 + 7;
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

Z g(int n, int m, int x) {
    Z res = 0;
    int upper = m / (x + 1);
    for (int t = 0; t <= upper; t++) {
        int coef = t & 1 ? -1 : 1;
        res += coef * comb.binom(n, t) * comb.binom(m + n - 1 - t * (x + 1), n - 1);
    }
    return res;
}

void solve() {
    int n = read(), m = read();
    Z ans = 0;

    for (int x = 0; x <= m; x++) {
        Z g1 = g(n - 1, m - x, x);
        Z g2 = g(n - 2, m - x - x, x);

        // sum of maximums
        ans += x * g1;
        ans += Z(x) * (n - 1) * g2;

        // sum of a_1
        ans -= Z(m - x) / Z(n - 1) * g1;

        // sum of right after maximums
        ans -= (m - 2 * x) * g2;
        ans -= x * g2;
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}