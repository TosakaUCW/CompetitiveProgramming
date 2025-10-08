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
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int n = read();
    int m = read();

    vector<int> a(n), b(n);
    for (auto &x : a) x = read();
    for (auto &x : b) x = read();

    int L = 1;
    for (auto x : a) L = lcm(L, x);

    int N = L * n;
    
    vector safe(L, vector(n, 1ll));
    for (int x = 0; x < L; x++) {
        for (int t = 0; t < n; t++) {
            int i = (t - 1 + n) % n;
            if (x % a[i] == b[i]) {
                safe[x][t] = 0;
            }
        }
    }

    vector f(N, -1ll), cost(N, 0ll);
    auto get = [&](int id) -> void {
        if (f[id] != -1) return;

        int x = id / n;
        int r = id % n;

        for (int w = 0; w < n; w++) {
            int ok = 1;
            for (int k = 1; k <= w; k++) {
                int t = (r + k) % n;
                if (!safe[x][t]) { ok = 0; break; }
            }
            if (!ok) continue;

            int nx = (x + 1) % L;
            int nr = (r + w + 1) % n;
            int nid = nx * n + nr;
            if (safe[nx][nr]) {
                f[id] = nid;
                cost[id] = w + 1;
                return;
            }

        }

        f[id] = -2;
    };

    vector sum(N, 0ll), d(N, -1ll);
    int id = 0, tot = 0, step = 0;
    int cur = id;

    while (step < m and d[cur] == -1) {
        d[cur] = step;
        sum[cur] = tot;

        get(cur);
        if (f[cur] == -2) { cout << "-1\n"; return; }

        tot += cost[cur];
        cur = f[cur];
        step++;
    }

    if (step == m) { 
        cout << tot << '\n';
    } else {
        int clen = step - d[cur];
        int ccost = tot - sum[cur];
        int need = m - d[cur];
        int ans = sum[cur] + need / clen * ccost;
        for (int i = 0; i < need % clen; i++) {
            get(cur);
            ans += cost[cur];
            cur = f[cur];
        }
        cout << ans << '\n';
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}