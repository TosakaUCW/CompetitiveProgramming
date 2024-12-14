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
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' or t[i] == '1') {
            continue;
        } else {
            cout << "0";
            return;
        }
    }
    cout << "1";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // int T; cin >> T;
    // for (; T--; solve());
    solve();
    return 0;
}
