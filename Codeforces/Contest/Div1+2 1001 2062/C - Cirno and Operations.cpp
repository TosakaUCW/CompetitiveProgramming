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

void solve() {
    int n = read();
    vector<int> a(n);
    for (auto &x : a) x = read();

    if (n == 1) {
        cout << a[0] << '\n';
        return;
    }
    
    int ans = accumulate(a.begin(), a.end(), 0ll);

    while (!a.empty()) {
        int m = a.size();
        vector<int> na;
        for (int i = 1; i < m; i++) na.eb(a[i] - a[i - 1]);
        int sum = accumulate(na.begin(), na.end(), 0ll);

        ans = max(ans, abs(sum));
        a = na;
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
