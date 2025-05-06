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
template<class T>
struct Frac {
    T num, den;
    Frac(T num_, T den_) : num(num_), den(den_) { if (den < 0) den = -den, num = -num; }
    Frac() : Frac(0, 1) {}
    Frac(T num_) : Frac(num_, 1) {}
    explicit operator double() const { return 1. * num / den; }
    Frac &operator+=(const Frac &rhs) { num = num * rhs.den + rhs.num * den, den *= rhs.den; return *this; }
    Frac &operator-=(const Frac &rhs) { num = num * rhs.den - rhs.num * den, den *= rhs.den; return *this; }
    Frac &operator*=(const Frac &rhs) { num *= rhs.num, den *= rhs.den; return *this; }
    Frac &operator/=(const Frac &rhs) {
        num *= rhs.den, den *= rhs.num;
        if (den < 0) num = -num, den = -den;
        return *this;
    }
    friend Frac operator+(Frac lhs, const Frac &rhs) { return lhs += rhs; }
    friend Frac operator-(Frac lhs, const Frac &rhs) { return lhs -= rhs; }
    friend Frac operator*(Frac lhs, const Frac &rhs) { return lhs *= rhs; }
    friend Frac operator/(Frac lhs, const Frac &rhs) { return lhs /= rhs; }
    friend Frac operator-(const Frac &a) { return Frac(-a.num, a.den); }
    friend bool operator==(const Frac &lhs, const Frac &rhs) { return lhs.num * rhs.den == rhs.num * lhs.den; }
    friend bool operator!=(const Frac &lhs, const Frac &rhs) { return lhs.num * rhs.den != rhs.num * lhs.den; }
    friend bool operator<(const Frac &lhs, const Frac &rhs) { return lhs.num * rhs.den < rhs.num * lhs.den; }
    friend bool operator>(const Frac &lhs, const Frac &rhs) { return lhs.num * rhs.den > rhs.num * lhs.den; }
    friend bool operator<=(const Frac &lhs, const Frac &rhs) { return lhs.num * rhs.den <= rhs.num * lhs.den; }
    friend bool operator>=(const Frac &lhs, const Frac &rhs) { return lhs.num * rhs.den >= rhs.num * lhs.den; }
    friend std::ostream &operator<<(std::ostream &os, Frac x) {
        T g = std::gcd(x.num, x.den);
        if (x.den == g) return os << x.num / g;
        else return os << x.num / g << "/" << x.den / g;
    }
};
using F = Frac<i64>;

void solve() {
    int n, m;
    cin >> n >> m;

    map<F, int> mp;

    F now = 0;

    for (int i = 0; i < n; i++) {
        int p, q;
        cin >> p >> q;

        F t(p, q);

        int g = std::gcd(now.num, now.den);
        now.num /= g, now.den /= g;

        mp[now] = 1;

        now += t;
        if (i == 0) now = t;
    }

    int ans = 0;

    now = 0;
    for (int i = 0; i < m; i++) {
        int p, q;
        cin >> p >> q;

        F t(p, q);

        int g = std::gcd(now.num, now.den);
        now.num /= g, now.den /= g;

        if (mp[now] == 1) ans++;

        now += t;
        if (i == 0) now = t;
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