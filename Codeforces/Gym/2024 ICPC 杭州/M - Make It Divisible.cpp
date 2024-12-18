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
    int n = read();
    int k = read();
    vector<int> a(n);
    for (auto &x : a) x = read();

    vector<pii> b(n);

    vector<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() and a[stk.back()] > a[i]) {
            stk.pop_back();
        }
        if (!stk.empty()) {
            b[i].fi = stk.back() + 1;
        } else {
            b[i].fi = 0;
        }
        stk.eb(i);
    }

    stk.clear();
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() and a[stk.back()] > a[i]) {
            stk.pop_back();
        }
        if (!stk.empty()) {
            b[i].se = stk.back() - 1;
        } else {
            b[i].se = n - 1;
        }
        stk.eb(i);
    }


    int g = 0;
    for (int i = 1; i < n; i++) {
        g = std::gcd(g, a[i] - a[i - 1]);
    }

    int cnt = 0;
    int sum = 0;

    int mn = *std::min_element(a.begin(), a.end());

    auto check = [&](int tar) {
        int t = tar - mn;

        if (t < 1 or t > k) return;
        for (int i = 0; i < n; i++) {
            int d = a[i] + t;
            for (int j = b[i].fi; j <= b[i].se; j++) {
                if ((a[j] + t) % d != 0) {
                    return;
                }
            }
        }
        sum += t, cnt++;
    };

    if (g == 0) {
        cnt = k;
        sum = (1LL + k) * k / 2LL;
        cout << cnt << ' ' << sum << '\n';
        return;
    }

    for (int i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            check(i);
            if (g / i != i) {
                check(g / i);
            }
        }
    }

    cout << cnt << ' ' << sum << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
