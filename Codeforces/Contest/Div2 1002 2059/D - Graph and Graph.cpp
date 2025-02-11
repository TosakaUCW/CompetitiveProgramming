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
const int inf = 1e18;
struct Node {
    int d, u, v;
    bool friend operator< (Node a, Node b) {
        return a.d > b.d;
    }
};

void solve() {
    int n = read();
    int s1 = read() - 1;
    int s2 = read() - 1;

    int m1 = read();
    vector<vector<int>> g1(n);
    for (int i = 0; i < m1; i++) {
        int u = read() - 1, v = read() - 1;
        g1[u].eb(v), g1[v].eb(u);
    }
    int m2 = read();
    vector<vector<int>> g2(n);
    for (int i = 0; i < m2; i++) {
        int u = read() - 1, v = read() - 1;
        g2[u].eb(v), g2[v].eb(u);
    }

    vector<int> good(n);
    for (int i = 0; i < n; i++) {
        set<int> s(g1[i].begin(), g1[i].end());
        for (int x : g2[i]) {
            if (s.count(x)) {
                good[i] = 1;
                break;
            }
        }
    }

    int ans = -1;
    vector dis(n, vector(n, inf));
    dis[s1][s2] = 0;
    std::priority_queue<Node> q; q.ep(0, s1, s2);
    while (!q.empty()) {
        auto [d, u, v] = q.top(); q.pop();
        if (d != dis[u][v]) continue;
        if (u == v and good[u]) {
            ans = d;
            break;
        } 

        for (int nu : g1[u]) {
            for (int nv : g2[v]) {
                int nd = d + abs(nu - nv);
                if (nd < dis[nu][nv]) {
                    dis[nu][nv] = nd;
                    q.ep(nd, nu, nv);
                }
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
