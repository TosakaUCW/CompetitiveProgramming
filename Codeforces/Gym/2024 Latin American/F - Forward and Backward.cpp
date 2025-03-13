#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;

void solve() {
    int n = read();

    // vector<int> ans;
    std::map<int, int> ans;

    auto check = [&](int b) {
        if (b < 2 or b > n) return;
        if (ans.count(b)) return;

        vector<int> buk;
        for (int x = n; x; x /= b) {
            buk.eb(x % b);
        }

        auto nbuk = buk;
        ranges::reverse(nbuk);

        if (buk == nbuk) ans[b] = 1;
    };

    for (int d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            check(d - 1);
            check(n / d - 1);
        }
    }

    check(n - 1);

    for (int b = 2; b * b <= n + 1; b++) {
        check(b);
    }

    if (ans.empty()) cout << '*';
    for (auto [x, _] : ans) cout << x << ' ';
    cout << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}
