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

double eps = 1e-7;
const int inf = 1e9;

int p2[31], p5[14];

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    i64 g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}
// ax + b = 0 (mod m)
std::pair<i64, i64> sol(i64 a, i64 b, i64 m) {
    assert(m > 0);
    b *= -1;
    i64 x, y;
    i64 g = exgcd(a, m, x, y);
    if (g < 0) {
        g *= -1;
        x *= -1;
        y *= -1;
    }
    if (b % g != 0) {
        return {-1, -1};
    }
    x = x * (b / g) % (m / g);
    if (x < 0) {
        x += m / g;
    }
    return {x, m / g};
}

void solve() {
    int a; cin >> a;
    int b; cin >> b;

    int p = b;
    while (p % 2 == 0) p /= 2;
    while (p % 5 == 0) p /= 5;

    pii ans = {inf, inf};

    for (int x : p2) {
        for (int y : p5) {
            int d = p * x * y;

            if (d > 1'000'000'000) break;
            auto [c, g] = sol(b, a * d, p * p);

            // cout << c << ' ' << d << '\n';

            // cout << "bc = " << b * c;
            // cout << ", ad = " << a * d;
            // cout << ", p = " << p << '-';

            // cout << c << ' ' << d << '\n';

            if (c < ans.fi) ans = {c, d};
        }
    }

    cout << ans.fi << ' ' << ans.se << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    p2[0] = p5[0] = 1;
    for (int i = 1; i <= 30; i++) p2[i] = p2[i - 1] * 2LL;
    for (int i = 1; i <= 13; i++) p5[i] = p5[i - 1] * 5LL;

    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}
