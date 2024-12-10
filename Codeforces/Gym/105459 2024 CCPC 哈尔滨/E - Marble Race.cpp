#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
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
i64 MInt<0>::Mod = 1e9 + 7;
constexpr int P = 1e9 + 7;
using Z = MInt<P>;

using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    int n = read(), m = read();

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        x[i] = -read();
    }
    vector<int> v(m);
    for (int i = 0; i < m; i++) {
        v[i] = read();
    }

    vector<pii> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            t.eb(i, j);
        }
    }
    std::sort(t.begin(), t.end(), [&](pii a, pii b) {
        return x[a.fi] * v[b.se] < x[b.fi] * v[a.se];
    });

    Z ans = 0;
    Z invN = Z(n).inv();
    vector<Z> d(m + 1);
    vector<Z> f(m + 1);
    f[0] = power(Z(n), m);

    auto ins = [&](Z x) {
        Z y = n - x;
        for (int i = m; i >= 1; i--) {
            f[i] = f[i] * y + f[i - 1] * x;
        }
        f[0] *= y;
    };
    auto del = [&](Z x) {
        Z y = Z(n - x).inv();
        f[0] *= y;
        for (int i = 1; i <= m; i++) {
            f[i] = (f[i] - f[i - 1] * x) * y;
        }
    };

    for (auto [i, j] : t) {
        del(d[j]);
        ans += f[m / 2] * invN * x[i] / v[j];
        d[j] += 1;
        ins(d[j]);
    }

    ans *= power(invN, m - 1);

    cout << ans << '\n';
}

signed main() {
    
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}