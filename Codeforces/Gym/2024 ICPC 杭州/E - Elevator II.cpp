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
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    int n = read(), f = read();
    vector<pii> a(n);
    int tot = 0;
    for (auto &[l, r] : a) {
        l = read(), r = read();
        tot += r - l;
    }

    vector<int> p(n);
    std::ranges::iota(p, 0);

    std::ranges::sort(p, [&](int x, int y) {
        return a[x].fi < a[y].fi;
    });

    vector<int> ans, tans;

    for (int i : p) {
        auto [l, r] = a[i];
        if (r > f) {
            ans.eb(i);
            tot += max(0LL, l - f);
            f = r;
        } else {
            tans.eb(i);
        }
    }

    std::ranges::reverse(tans);
    // ans = std::ranges::merge(ans, tans, ans.begin());
    cout << tot << '\n';
    for (auto x : ans) {
        cout << x + 1 << ' ';
    }
    for (auto x : tans) {
        cout << x + 1 << ' ';
    }
    puts("");
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
