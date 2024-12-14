#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
using std::ostream;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

struct Node {
    int pos, val;
    bool friend operator < (Node a, Node b) {
        return a.val < b.val;
    }
};

void solve() {
    int n; cin >> n;
    vector a(n, vector<int>(n));
    vector b(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '-') {
                b[i][j] = 1;
                a[i][j] = -1;
            } else {
                b[i][j] = 0;
                a[i][j] = 1;
            }
        }
    }

    vector<int> row(n);
    for (int &x : row) cin >> x;
    vector<int> col(n);
    for (int &x : col) cin >> x;

    for (int i = 0; i < n; i++) {
        // cerr << a[i] << '\n';
        for (int j = 0; j < n; j++) {
            row[i] += (a[i][j] == -1);
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            col[j] += (a[i][j] == -1);
        }
    }

    // cerr << "---------\n";
    // cerr << row << '\n';
    // cerr << col << '\n';
    // cerr << "---------\n";

    std::priority_queue<Node> q;
    for (int j = 0; j < n; j++) {
        if (col[j]) {
            q.ep(j, col[j]);    
        }
    }

    for (int i = 0; i < n; i++) {
        vector<int> t;

        while (!q.empty() and row[i] > 0) {
            auto [j, _] = q.top();
            q.pop();

            b[i][j] ^= 1;
            row[i]--;
            col[j]--;

            if (col[j]) t.eb(j);
        }

        for (auto j : t) {
            q.ep(j, col[j]);
        }
    }

    for (int j = 0; j < n; j++) {
        if (row[j] != 0 or col[j] != 0) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j];
        }
        cout << "\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}