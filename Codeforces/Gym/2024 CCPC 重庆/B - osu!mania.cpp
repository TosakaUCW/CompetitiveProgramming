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

void solve() {
    double ppmax, a, b, c, d, e, f;
    cin >> ppmax >> a >> b >> c >> d >> e >> f;

    double pp = 0;
    pp = (320.0 * a + 300.0 * b + 200.0 * c + 100.0 * d + 50.0 * e) / (320.0 * (a + b + c + d + e + f)) - 0.8;
    // if (pp < 0 - eps) pp = 0;
    pp = max(pp, 0.0);
    pp *= 5.0 * ppmax;
    // pp = round(pp);
    // cout << pp << '\n';
    // pp = round(pp);
    int ppans = int(pp + 0.5 + eps);

    double acc = 0;
    acc += 300 * a;
    acc += 300 * b;
    acc += 200 * c;
    acc += 100 * d;
    acc += 50 * e;
    acc /= 300.0 * (a + b + c + d + e + f);

    acc *= 100.0;

    printf("%.2f%% %d\n", acc, ppans);

    // cout << acc << ' ' << ppans << '\n';
}

signed main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}