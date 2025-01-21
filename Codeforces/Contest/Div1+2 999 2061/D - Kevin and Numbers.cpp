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
const int INF = 1e18;
void solve() {
    int n = read();
    int m = read();

    vector<int> a(n);
    for (auto &x : a) x = read();

    vector<int> b(m);
    for (auto &x : b) x = read();

    std::priority_queue<int> q;
    for (auto x : b) q.ep(x);

    std::map<int, int> mp;
    for (auto x : a) mp[x]++;

    bool f = 1;
    for (int i = 0; i < n + n - m; i++) {
        if (q.empty()) {
            f = 0;
            break;
        }

        int x = q.top(); q.pop();

        if (mp[x] == 0) {
            q.ep(x / 2);
            q.ep((x + 1) / 2);
        } else {
            mp[x]--;
        }
    }

    puts(f and q.empty() ? "Yes" : "No");
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
