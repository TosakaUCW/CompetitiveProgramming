#include <bits/stdc++.h>
using i64 = long long;
using ull = unsigned long long;
// #define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
// const int inf = 1e18;
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
    int m = read();

    vector a(n + 1, vector(m + 1, 0));
    vector<vector<pii>> pos(n * m + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = read();
            pos[a[i][j]].eb(i, j);
        }
    }

    vector f(n + 1, vector(m + 1, Z(0)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i - 1][j] + f[i][j - 1];
            if (i == 1 and j == 1) f[i][j] = 1;
        }
    }

    auto calc1 = [&](int col) -> Z  {
        vector g(n + 1, vector(m + 1, vector(2, Z(0))));
        g[1][1][a[1][1] == col] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 and j == 1) continue;

                g[i][j][0] = g[i - 1][j][0] + g[i][j - 1][0];
                g[i][j][1] = g[i - 1][j][1] + g[i][j - 1][1];
                if (a[i][j] == col) {
                    g[i][j][1] += g[i][j][0];
                    g[i][j][0] = 0;
                }
            }
        }

        return g[n][m][1];
    };

    f[0][0] = 1;
    vector h(n + 1, vector(m + 1, Z(0)));
    auto calc2 = [&](int col) -> Z  {
        ranges::sort(pos[col]);
        Z res = 0;

        for (int i = 0; i < pos[col].size(); i++) {
            auto [x, y] = pos[col][i];
            Z s = f[x][y];

            for (int j = i - 1; j >= 0; j--) {
                auto [xx, yy] = pos[col][j];
                if (xx > x or yy > y) continue;

                s -= h[xx][yy] * f[x - xx + 1][y - yy + 1];
            }
            res += s * f[n - x + 1][m - y + 1];
            h[x][y] = s;
        }

        return res;
    };

    Z ans = 0;
    const int B = 330;
    for (int i = 1; i <= n * m; i++) {
        if (pos[i].empty()) continue;
        if (pos[i].size() >= B) {
            ans += calc1(i);
        } else {
            ans += calc2(i);
        }
    }
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}