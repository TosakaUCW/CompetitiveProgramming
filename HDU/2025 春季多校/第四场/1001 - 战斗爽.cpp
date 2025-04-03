#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

struct node {
    int t, hp, atk, idx;
    node (int _t, int _hp, int _atk, int _idx) : 
        t(_t),
        hp(_hp),
        atk(_atk),
        idx(_idx) {}
    bool friend operator < (node a, node b) {
        if (a.hp != b.hp) return a.hp > b.hp;
        if (a.atk != b.atk) return a.atk > b.atk;
        return a.idx > b.idx;
    }
};
struct Node {
    int idx, val;
    Node (int _idx, int _val) : 
        idx(_idx),
        val(_val) {}
    bool friend operator < (Node a, Node b) {
        if (a.val != b.val) return a.val < b.val;
        return a.idx < b.idx;
    }
};

void solve() {
    int n, atk, k, hp;
    cin >> n >> atk >> k >> hp;

    int ans = 0;
    // int cnt = 0;
    vector<int> vis(n + 1);
    priority_queue<node> q1;
    priority_queue<Node> q2;

    vector<int> a(n + 1), h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> h[i];
        q1.ep(0, h[i], a[i], i);
        q2.ep(i, a[i]);
    }

    // cout << q2.top().idx << '\n';
    while (hp > 0) {
        auto [et, ehp, eatk, eid] = q1.top();
        q1.pop();
        if (et == 0) {
            ehp -= atk;
        } else {
            ehp -= atk / 2;
        }

        if (ehp <= 0) {
            ans++;
            vis[eid] = 1;
            // cout << "defeat: " << eid << '\n';
        } 

        if (et != k - 1 and ehp > 0) {
            q1.ep(et + 1, ehp, eatk, eid);
        }

        if (ans == n) break;

        while (!q2.empty() and vis[q2.top().idx]) q2.pop();
        if (!q2.empty()) hp -= q2.top().val;
    }

    cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}
