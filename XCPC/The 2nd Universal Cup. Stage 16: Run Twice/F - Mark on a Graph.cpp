#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define fi first
#define se second
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
template <class T> bool cmin(T &a, T b) { return (b < a) ? (a = b, true) : false; }
template <class T> bool cmax(T &a, T b) { return (a < b) ? (a = b, true) : false; }
using pii = pair<int, int>;
using tup = tuple<int, int, int>;
const int inf = 1e18;
const double eps = 1e-9;

void solve() {
    int n = read();
    int m = read();

    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1);
    for (int i = 1; i <= m; i++) {
        int u = read();
        int v = read();
        deg[u]++;
        deg[v]++;
        adj[u].eb(v), adj[v].eb(u);
    }
    int p1 = 1, p2 = 2;
    if (deg[p1] < deg[p2]) swap(p1, p2);
    for (int i = 3; i <= n; i++) {
        if (deg[i] > deg[p1]) {
            p2 = p1;
            p1 = i;
        } else if (deg[i] > deg[p2]) {
            p2 = i;
        }
    }

    if (deg[p1] >= deg[p2] + 5) {
        cout << "ok" << endl;
        return;
    }

    cout << "mark" << endl;
    map<int, int> buk;
    for (int v : adj[p1]) buk[v] = 1;
    int cnt = 0;

    vector<int> p;
    for (int i = 1; i <= n; i++) {
        if (i == p1 or buk[i]) continue;
        p.eb(i);
        // cout << p1 << ' ' << i << endl;
        // cnt++;
        // if (cnt == 5) break;
    }

    int k = min<int>(5, p.size());
    cout << k << endl;
    ranges::sort(p, [&](int i, int j) {
        return deg[i] < deg[j];
    });
    for (int i = 0; i < k; i++) {
        cout << p1 << ' ' << p[i] << endl;
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    // string s; cin >> s;
    // if (s == "first") {
    //     for (int T = read(); T--; solve1());
    //     // solve1();
    // } else {
    //     for (int T = read(); T--; solve2());
    // }
    solve();
    return 0;
}