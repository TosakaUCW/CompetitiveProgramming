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

struct node {
    int x, k, tim;
    bool friend operator < (node i, node j) {
        return i.tim > j.tim;
    }
};

void solve() {
    int n = read();

    vector<int> t(n + 1);
    for (int i = 1; i <= n; i++) t[i] = read();

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read() * 2;

    vector<vector<int>> buk(n + 1);
    for (int i = 1; i <= n; i++) {
        buk[t[i]].eb(i);
    }

    auto sign = [&](int x) -> int {
        return x > 0 ? 1 : -1;
    };

    priority_queue<node> pq;
    for (int i = 1; i <= n; i++) {
        int tim = 0;
        int x = i, y = t[x], z = t[y];
        if (sign(a[y] - a[x]) == sign(a[z] - a[y])) {
            continue;
        } else {
            tim = abs(a[y] - a[x]) / 2;
        }

        // cout << "push: " << x << ' ' << y << ' ' << tim << "\n";
        pq.ep(x, 0, tim);

    }

    vector<int> stop(n + 1);
    vector<int> ans(n + 1);
    vector<int> cnt(n + 1);

    while (!pq.empty()) {
        auto [x, k, tim] = pq.top(); pq.pop();
        if (stop[x]) continue;
        if (cnt[x] != k) continue;

        // cout << "pop: " << x << ' ' << y << ' ' << tim << '\n';
        ans[x] = tim;
        stop[x] = 1;

        int y = t[x];
        a[x] += sign(a[y] - a[x]) * tim;

        for (auto t : buk[x]) {
            if (stop[t]) continue;
            cnt[t]++;
            pq.ep(t, 1, abs(a[x] - a[t]));
            // cout << "push: " << t << ' ' << x << ' ' << ntim << "\n";
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}