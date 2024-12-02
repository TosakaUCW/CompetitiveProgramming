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
std::vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0), primes.clear();
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) minp[i] = i, primes.push_back(i);
        for (auto p : primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) break;
        }
    }
}

void solve() {
    int n = read();
    vector<vector<int>> g(1e6);
    for (int i = 1; i <= n; i++) {
        for (int x = read(); x != 1; ) {
            int p = minp[x];
            int c = 0;

            while (x % p == 0) {
                x /= p;
                c++;
            }

            g[p].eb(c);
        }
    }

    auto go = [&](vector<int> c, int p) -> Z {
        int m = c.size();
        if (m == 0) return Z(1);

        int sum = std::accumulate(c.begin(), c.end(), 0);
        vector<int> pow(sum + 1);
        pow[0] = 1;
        for (int i = 1; i <= sum; i++) {
            pow[i] = pow[i - 1] * p;
        }

        vector<Z> dp(2);
        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            vector<Z> ndp(2);
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= c[i]; k++) {
                    int nj = (j + k) % 2;
                    ndp[nj] += dp[j] * pow[(j + k) / 2];
                }
            }
            dp = std::move(ndp);
        }

        return dp[0];
    };

    Z ans = 1;
    for (auto p : primes) {
        ans *= go(g[p], p);
    }
    cout << ans << '\n';
}

signed main() {
    sieve(1e6);
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}