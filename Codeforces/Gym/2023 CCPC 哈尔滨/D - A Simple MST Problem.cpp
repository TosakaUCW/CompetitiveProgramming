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

struct Node {
    int cur, dis;
    bool friend operator < (Node a, Node b) {
        return a.dis > b.dis;
    }
};

std::vector<int> minp, primes;
vector<vector<int>> facs;
vector<int> w, rad;
void sieve(int n) {
    minp.assign(n + 1, 0), primes.clear();
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) minp[i] = i, primes.push_back(i);
        for (auto p : primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) break;
        }
    }

    facs.assign(n + 1, {});
    for (auto p : primes) {
        for (int j = p; j <= n; j += p) {
            facs[j].eb(p);
        }
    }

    w.assign(n + 1, 0);
    rad.assign(n + 1, 1LL);
    for (int i = 1; i <= n; i++) {
        w[i] = facs[i].size();
        for (int t : facs[i]) rad[i] *= t;
    }
}

void solve() {
    int L = read(), R = read();
    if (*ranges::lower_bound(primes, L) <= R) {
        vector<int> vis(R + 1);
        int ans = 0;
        for (int i = L; i <= R; i++) {
            if (vis[rad[i]]) {
                ans += w[i];
            } else {
                vis[rad[i]] = 1;
            }
        }
        int f = 1;
        for (int i = 1; i <= R; i++) {
            if (!vis[i]) continue;

            if (w[i] <= 1 and f) {
                f = 0;
            } else {
                ans += w[i] + 1;
            }

            for (int j = 2 * i; j <= R; j += i) {
                if (vis[j]) ans += w[j], vis[j] = 0;
            }
        }
        cout << ans << '\n';
    } else {

        auto dis = [&](int u, int v) {
            int res = w[u];
            for (auto p : facs[v]) if (rad[u] % p != 0) res++;
            return res;
        };
        
        int ans = 0;

        priority_queue<Node> pq;
        for (int i = L + 1; i <= R; i++) {
            pq.ep(i, dis(L, i));
        }

        vector<int> vis(R + 1);
        vis[L] = 1;

        for (int i = 1; i < R - L + 1; i++) {
            while (vis[pq.top().cur]) pq.pop();
            auto [u, d] = pq.top(); pq.pop();

            ans += d;
            vis[u] = 1;

            for (int v = L; v <= R; v++) {
                if (vis[v]) continue;
                pq.ep(v, dis(u, v));
            }
        }
        cout << ans << '\n';
    }
}

signed main() {
    sieve(1000000);
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}