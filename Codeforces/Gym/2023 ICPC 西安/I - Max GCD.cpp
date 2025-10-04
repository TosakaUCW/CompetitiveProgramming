#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
// #define int i64
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
// const int inf = 1e18;

const int N = 150000 + 5;
const int M = 1000000 + 5;
namespace DS {
    int n, bel[N], blo, L[N], R[N], a[N], b[N];
    void init(int _n) {
        n = _n;
        blo = sqrt(n);
        for (int i = 1; i <= n; i++) {
            bel[i] = (i - 1) / blo + 1;
            if (!L[bel[i]]) {
                L[bel[i]] = i;
            }
            R[bel[i]] = i;
        }
    }
    void update(int x, int y) {
        a[x] = max(a[x], y);
        b[bel[x]] = max(b[bel[x]], y);
    }
    int query(int x) {
        int ans = 0;
        for (int i = x; i <= R[bel[x]]; i++) ans = max(ans, a[i]);
        for (int i = bel[x] + 1; i <= bel[n]; i++) ans = max(ans, b[i]);
        return ans;
    }
}

vector<vector<int>> fac(M + 1);

void solve() {
    int n = read();
    int m = read();

    vector<int> a(n + 1);
    vector<vector<int>> pos(M + 1);

    for (int i = 1; i <= n; i++) {
        a[i] = read();
        for (auto x : fac[a[i]]) {
            pos[x].eb(i);
        }
    }

    vector<vector<pii>> qry(n + 1);
    for (int i = 1; i <= m; i++) {
        int l = read(), r = read();
        if (r - l <= 1) continue;
        qry[r].eb(l, i);
    }

    DS::init(n);

    vector<vector<pii>> cand(n + 1);
    for (int d = 1; d <= M; d++) {
        vector<int> b;
        for (int i : pos[d]) b.eb(i);
        for (int i = 0; i + 1 < b.size(); i++) {
            int need = b[i + 1] * 2 - b[i];
            auto it = ranges::lower_bound(b, need);
            if (it == b.end()) continue;
            cand[*it].eb(b[i], d);
        }
    }

    vector<int> ans(n + 1);
    for (int r = 1; r <= n; r++) {
        for (auto [l, d] : cand[r]) {
            DS::update(l, d);
        }
        for (auto [l, id] : qry[r]) {
            ans[id] = DS::query(l);
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }
}

signed main() {
    for (int i = 1; i <= M; i++) {
        for (int j = i; j <= M; j += i) {
            fac[j].eb(i);            
        }
    }
    solve();
    return 0;
}