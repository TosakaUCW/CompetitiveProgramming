#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
// using namespace std::views;
// using namespace std::ranges;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
using std::ostream;
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

double eps = 1e-7;
const int inf = 1e9;
const int all = 1LL << 16;

int tot = 0;
std::vector<int> id;
std::vector<int> minp, primes;
void sieve(int n) {
    id.assign(n + 1, 0);
    minp.assign(n + 1, 0), primes.clear();
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i, primes.push_back(i);
            id[i] = tot++;
        }
        for (auto p : primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) break;
        }
    }
}

void solve() {
    int n; cin >> n;

    vector<vector<pii>> buk(tot);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pii t = {x, 0};
        for (int i = 0; i < 16; i++) {
            if (x % primes[i] != 0) continue;

            while (x % primes[i] == 0) x /= primes[i];
            t.se |= (1LL << i);
        }

        if (x > 1) {
            buk[id[x]].eb(t);
        } else {
            buk[0].eb(t);
        }
    }

    vector<Z> dp(all);
    dp[0] = 1;

    for (auto [x, S] : buk[0]) {
        auto ndp = dp;
        for (int mask = 0; mask < all; mask++) {
            ndp[mask | S] += dp[mask] * x;
        }
        dp = std::move(ndp);
    } 
    for (int i = 16; i < tot; i++) {

        if (buk[i].empty()) continue;

        vector<Z> f(all);
        Z coef = Z(primes[i] - 1) / Z(primes[i]);

        for (auto [x, S] : buk[i]) {
            auto nf = f;
            for (int mask = 0; mask < all; mask++) {
                nf[mask | S] += f[mask] * x;
                nf[mask | S] += dp[mask] * x * coef;
            }
            f = std::move(nf);
        }

        for (int mask = 0; mask < all; mask++) {
            dp[mask] += f[mask];
        }
    }


    Z ans = 0;
    for (int mask = 0; mask < all; mask++) {
        Z res = dp[mask];
        for (int i = 0; i < 16; i++) {
            if (mask >> i & 1) {
                res *= Z(primes[i] - 1) / Z(primes[i]);
            }
        }
        ans += res;
    }
    cout << ans << '\n';
}

signed main() {
    sieve(3000);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
