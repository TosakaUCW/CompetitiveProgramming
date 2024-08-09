#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
i64 read(i64 x = 0, int f = 0, char ch = getchar()) {
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

const int N = 1e2 + 5;

int n, m;

struct Mat {
    Z a[N][N];
    void clear() { memset(a, 0, sizeof a); }
    Mat() { clear(); }
    Mat friend operator * (Mat A, Mat B) {
        Mat C; C.clear();
        for (int i = 1; i <= n + 1; i++)
            for (int j = 1; j <= n + 1; j++)
                for (int k = 1; k <= n + 1; k++)
                    C.a[i][j] += A.a[i][k] * B.a[k][j];
        return C;
    }
} W, O, O1, O2;
Mat qpow(Mat x, i64 y) {
    Mat res; res.clear();
    for (int i = 1; i <= n + 1; i++) res.a[i][i] = 1;
    for (; y; x = x * x, y >>= 1)
        if (y & 1) res = res * x;
    return res;
}
Z work(i64 x) {
    Mat p = qpow(W, x / n);
    Z res = p.a[1][n + 1];
    p = p * O;
    for (int i = 1; i <= x % n; i++)
        res += p.a[1][i];
    return res;
}

void solve() {
    n = read(), m = read();
    i64 L = read(), R = read();
    O.clear(), O1.clear(), O2.clear(), W.clear();

    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        if (v <= n) O1.a[u][v] = w;
        else O2.a[u][v - n] = w;
    }

    for (int i = 1; i <= n; i++) O.a[i][i] = 1;

    for (int i = n; i >= 1; i--)
        for (int j = i; j <= n; j++)
            for (int k = j; k <= n; k++)
                O.a[i][k] += O.a[i][j] * O1.a[j][k];
    O.a[n + 1][n + 1] = 1;

    for (int i = 1; i <= n + 1; i++) O2.a[i][n + 1] = 1;

    W = O * O2;

    Z ans = work(R) - work(L - 1);
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}