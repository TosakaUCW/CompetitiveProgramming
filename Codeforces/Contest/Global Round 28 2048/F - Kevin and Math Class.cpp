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
const int K = 61;
int ceil_div(int x, int y) { return x / y + (x % y != 0); }
void solve() {
    int n = read();
    
    vector<int> a(n), b(n);
    for (auto &x : a) x = read();
    for (auto &x : b) x = read();

    vector<int> lc(n, n), rc(n, n);
    vector<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() and b[i] < b[stk.back()]) {
            rc[stk.back()] = lc[i];
            lc[i] = stk.back();
            stk.pop_back();
        }
        stk.eb(i);
    }
    while (stk.size() > 1) {
        int x = stk.back();
        stk.pop_back();
        rc[stk.back()] = x;
    }


    vector<std::array<int, K>> dp(n + 1);
    auto dfs = [&](this auto &&self, int x, int l, int r) {
        if (x == n) return;
        self(lc[x], l, x);
        self(rc[x], x + 1, r);
        auto &L = dp[lc[x]];
        auto &R = dp[rc[x]];
        auto &f = dp[x];
        int i = 0, j = 0;
        f[0] = std::max({L[0], R[0], a[x]});
        while (i + j + 1 < K) {
            if (L[i] > R[j]) {
                i++;
            } else {
                j++;
            }
            f[i + j] = max({L[i], R[j], a[x]});
        }
        for (int i = 1; i < K; i++) {
            f[i] = min(f[i], ceil_div(f[i - 1], b[x]));
        }
    };
    dfs(stk[0], 0, n);

    auto &f = dp[stk[0]];
    int ans = std::find(f.begin(), f.end(), 1) - f.begin();
    cout << ans << "\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
