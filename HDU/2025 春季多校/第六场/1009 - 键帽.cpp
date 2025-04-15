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

void solve() {
    int n, k; cin >> n >> k;

    vector<Z> pw(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * 5;
    }
    vector<Z> dp(n + 1);
    vector<Z> sum(n + 1);

    dp[0] = 1;
    sum[0] = pw[n];

    for (int i = 1; i <= n; i++) {
        int l = i - k - 1;
        if (l > 0) {
            dp[i] = sum[i - 1] - sum[l - 1];
        } else {
            dp[i] = sum[i - 1];
        }
        dp[i] /= pw[n - i + 1];
        dp[i] *= Z(21);

        sum[i] = sum[i - 1] + dp[i] * pw[n - i];
    }
    Z ans = 0;
    for (int i = n; i >= n - k; i--) {
        ans += dp[i] * pw[n - i];
    }

    cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}