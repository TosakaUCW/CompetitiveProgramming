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

const int N = 1e6 + 5;
Z pw[N];

Z calc(int n) {
    Z res = power(Z(4), n + 1);
    res -= 4;
    res /= 3;
    return res;
}

void solve() {
    string s, t; cin >> s >> t;
    int k = read();

    int n = s.size(), m = t.size();
    ranges::reverse(s);
    ranges::reverse(t);
    while (n < m) n++, s += "0";
    while (n > m) m++, t += "0";

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) {
            p[i] = 0;
        } else {
            p[i] = 1;
        }
    }

    if (n & 1) n++, p.push_back(0);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] == 0) {
            cnt++;
        } else {
            break;
        }
    }
    if (cnt != n and cnt / 2 + 1 < k) {
        cout << "-1\n";
        return;
    }

    Z res = calc(k - 1);
    // debug(res);

    for (int i = 0; i < n; i += 2) {
        if (p[i] == 1 and p[i + 1] == 0) res += pw[i / 2];
        if (p[i] == 1 and p[i + 1] == 1) res += 2 * pw[i / 2];
        if (p[i] == 0 and p[i + 1] == 1) res += 3 * pw[i / 2];
    }
    // debug(p);
    cout << res << '\n';
}

signed main() {
    pw[0] = 1;
    for (int i = 1; i < N; i++) pw[i] = pw[i - 1] * 4;
    for (int i = 1; i < N; i++) pw[i] += pw[i - 1];
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}