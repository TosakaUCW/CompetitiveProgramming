#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
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
using pii = std::pair<double, double>;
#define fi first
#define se second

void solve() {
    int n = read(), m = read(), k = read();
    vector<std::priority_queue<int>> q(n + 1);
    for (int i = 1; i <= n * m; i++) {
        int val = read();
        int row = (val - 1) / m + 1;
        // cout << row << ' ';
        q[row].ep(i);
    }
    int ans = n * m;
    for (int row = 1; row <= n; row++) {
        int res = q[row].top();
        q[row].pop();

        int nk = k;
        while (nk > 0 and !q[row].empty()) {
            res = q[row].top();
            q[row].pop();
            nk--;
        }
        res = max(res, m);
        ans = min(ans, res);
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
