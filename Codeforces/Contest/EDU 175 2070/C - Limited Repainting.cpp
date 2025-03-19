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
using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    int n = read();
    int k = read();

    string s; cin >> s;

    vector<int> a(n);
    for (auto &x : a) x = read();
    vector<int> p(n);
    ranges::iota(p, 0ll);
    ranges::sort(p, [&](int x, int y) {
        return a[x] < a[y];
    });

    auto judge = [&](int lim) -> bool {
        int cnt = 0;
        int las = -2;

        for (int i = 0; i < n; i++) {
            if (a[i] <= lim) {
                if (las == i - 1) las = i;
            } else {
                if (s[i] == 'B') {
                    if (las != i - 1) cnt++;
                    las = i;
                }
            }
        }
        return cnt <= k;
    };

    int ans = -1;
    for (int L = 0, R = n - 1; L <= R; ) {
        int mid = L + R >> 1;
        if (judge(a[p[mid]])) ans = a[p[mid]], R = mid - 1;
        else L = mid + 1;
    }
    if (judge(0)) ans = 0;
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
