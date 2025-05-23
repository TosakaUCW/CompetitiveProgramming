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
    vector<int> b(2 * n);
    for (auto &x : b) x = read();
    ranges::sort(b);

    vector<int> odd, even;
    for (int i = 0; i < n - 1; i++) {
        odd.eb(b[i]);
    }
    for (int i = n - 1; i < 2 * n; i++) {
        even.eb(b[i]);
    }

    int sumodd = accumulate(odd.begin(), odd.end(), 0ll);
    int sumeven = accumulate(even.begin(), even.end(), 0ll);
    odd.eb(sumeven - sumodd);
    int p = 0, q = 0;

    for (int i = 0; i < 2 * n + 1; i++) {
        if (i % 2 == 0) cout << even[p++] << ' ';
        else cout << odd[q++] << ' ';
    }
    puts("");
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
