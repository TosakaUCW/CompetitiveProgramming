#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
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
    constexpr i64 norm(i64 x) const { while (x < 0) x += getMod(); while (x >= getMod()) x -= getMod(); return x; }
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
    int n; cin >> n;
    vector<int> f(n + 1), g(n + 1);

    int t = 499122177; // Z(2).inv()
    assert(t == Z(2).inv());

    for (int i = 0; i <= n; i++) {
        if (i >= 4) {
            f[i] = (g[i - 1] + g[i - 4]) % P * t % P;
            // 错误的暴力：已经取模的不能比大小
            g[i] = max(f[i - 1], f[i - 4]);
        } else if (i >= 1) {
            f[i] = (g[i - 1] + 1ll) % P * t % P;
            g[i] = f[i - 1];
        } else {
            f[i] = 1ll;
            g[i] = 0ll;
        }
        cout << i << ' ' << f[i] << ' ' << g[i] << '\n';
    }
}

void solve2() {
    int n; cin >> n;
    vector<double> f(n + 1), g(n + 1);

    for (int i = 0; i <= n; i++) {
        if (i >= 4) {
            f[i] = 0.5 * (g[i - 1] + g[i - 4]);
            g[i] = max(f[i - 1], f[i - 4]);
        } else if (i >= 1) {
            f[i] = 0.5 * (g[i - 1] + 1);
            g[i] = f[i - 1];
        } else {
            f[i] = 1;
            g[i] = 0;
        }
        cout << fixed << setprecision(15);
        cout << i << ' ' << f[i] << ' ' << g[i] << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    // int T; cin >> T;
    // for (; T--; solve());
    // solve();
    solve2();
    return 0;
}