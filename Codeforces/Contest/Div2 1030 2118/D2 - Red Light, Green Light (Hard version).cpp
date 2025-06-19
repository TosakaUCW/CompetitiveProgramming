#include <bits/stdc++.h>
using i64 = long long;
using ull = unsigned long long;
using i128 = __int128;
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
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

struct Node { int p, d, S, U; };

void solve() {
    int n = read();
    int k = read();

    vector<Node> a(n);
    for (auto &x : a) x.p = read();
    for (auto &x : a) x.d = read();

    map<int, vector<int>> bukR, bukL;
    // bukR.reserve(n * 2);
    // bukL.reserve(n * 2);

    for (int i = 0; i < n; ++i) {
        auto &[p, d, S, U] = a[i];
        S = (p % k - d + k) % k;
        U = (p % k + d) % k;
        bukR[S].eb(i);
        bukL[U].eb(i);
    }

    vector<int> nxt(2 * n, -1);

    for (auto &[_, v] : bukR) {
        for (int t = 0; t + 1 < v.size(); ++t) {
            int i = v[t], j = v[t + 1];
            nxt[2 * i + 1] = 2 * j;
        }
    }
    for (auto &[_, v] : bukL) {
        for (int t = 1; t < v.size(); ++t) {
            int i = v[t], j = v[t - 1];
            nxt[2 * i] = 2 * j + 1;
        }
    }

    vector<int> out(2 * n);
    vector<vector<int>> g(2 * n);
    queue<int> q;
    for (int i = 0; i < 2 * n; i++) {
        if (nxt[i] == -1) {
            out[i] = 1;
            q.ep(i);
        } else {
            g[nxt[i]].eb(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            out[v] = 1;
            q.ep(v);
        }
    }

    map<int, vector<pii>> vec;
    for (int i = 0; i < n; i++) {
        auto &[p, d, S, U] = a[i];
        vec[S].eb(p, i);
    }

    for (int q = read(); q--; ) {
        int x = read();

        if (!vec.contains(x % k))  { cout << "YES\n"; continue; }
        
        const auto &v = vec[x % k];
        auto it = ranges::lower_bound(v, pii(x, 0));
        if (it == v.end())  { cout << "YES\n"; continue; }

        int i = it->second;
        if (out[2 * i]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}