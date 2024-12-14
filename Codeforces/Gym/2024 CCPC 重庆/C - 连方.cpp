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
const int inf = 1000;

void solve() {
    int n; cin >> n;
    
    string s, t;
    cin >> s >> t;

    vector<string> a(7);

    a[0] = s;
    a[1] = s;
    a[2].assign(n, '.');
    a[3].assign(n, '.');
    a[4].assign(n, '.');
    a[5] = t;
    a[6] = t;
    for (auto &ch : a[1]) ch = (ch == '.' ? '#' : '.');
    for (auto &ch : a[5]) ch = (ch == '.' ? '#' : '.');

    int cnt1 = 0, cnt2 = 0;
    for (auto ch : s) cnt1 += ch == '#';
    for (auto ch : t) cnt2 += ch == '#';

    if (cnt1 == n and cnt2 == n) {
        cout << "Yes\n";
        for (int i = 0; i < 7; i++) {
            a[i].assign(n, '#');
            cout << a[i] << '\n';
        }
        return;
    }

    if (max(cnt1, cnt2) == n and cnt1 != cnt2) {
        cout << "No\n";
        return;
    }

    int l = -1, r = -1;

    for (int i = 0; i < n and l == -1; i++) {
        if (a[1][i] == '#') continue;
        if (i - 1 >= 0 and a[1][i - 1] == '#') l = i;
        if (i + 1 < n and a[1][i + 1] == '#') l = i;
    }
    for (int i = 0; i < n and r == -1; i++) {
        if (a[5][i] == '#') continue;
        if (i - 1 >= 0 and a[5][i - 1] == '#') r = i;
        if (i + 1 < n and a[5][i + 1] == '#') r = i;
    }
    a[2][l] = a[4][r] = '#';

    if (l > r) swap(l, r);
    if (l == r or l + 1 == r) {
        a[3][l] = '#';
    } else {
        for (int i = l + 1; i < r; i++) {
            a[3][i] = '#';
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < 7; i++) {
        cout << a[i] << '\n';
    }
    // cerr << "----\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}
