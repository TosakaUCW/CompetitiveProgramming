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
#define fi first
#define se second
template<class T> bool cmin(T &a, T b) { return (b < a) ? (a = b, true) : false; }
template<class T> bool cmax(T &a, T b) { return (a < b) ? (a = b, true) : false; }
using pii = pair<int, int>;
using tup = tuple<int, int, int>;
const int inf = 1e18;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    Fenwick(int n_ = 0) { init(n_); }
    void init(int n_) { n = n_; a.assign(n, T {}); }
    void set(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = max(a[i - 1], v);
        }
    }
    T qry(int x) {
        T ans {};
        for (int i = x; i > 0; i -= i & -i) {
            ans = max(ans, a[i - 1]);
        }
        return ans;
    }
};

void solve() {
    int n = read(), q = read();

    vector<int> a(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = read(), w[i] = read();
    }

    int m;
    vector<int> rk(n + 1);
    {
        vector v(a.begin() + 1, a.end());
        ranges::sort(v);
        v.erase(unique(v.begin(), v.end()), v.end());
        m = v.size();
        for (int i = 1; i <= n; i++) {
            rk[i] = ranges::lower_bound(v, a[i]) - v.begin() + 1;
        }    
    }
    // debug(rk);

    vector<int> f(n + 1);
    {
        Fenwick<int> bit(m + 1);
        for (int i = 1; i <= n; i++) {
            int r = rk[i];
            int res = bit.qry(r + 1);
            if (res == -inf) res = 0;
            f[i] = res + w[i];
            bit.set(r, f[i]);
        }
    }
    vector<int> g(n + 1);
    {
        Fenwick<int> bit(m + 1);
        for (int i = n; i >= 1; i--) {
            int r = m - rk[i] + 1;
            int res = bit.qry(r + 1);
            if (res == -inf) res = 0;
            g[i] = res + w[i];
            bit.set(r, g[i]);
        }
    }
    // debug(f);
    // debug(g);

    int N = n + 5;
    int B = sqrt(n) + 5;
    int M = n / B + 5;
    vector pre(M, vector(N, 0ll));
    vector suf(M, vector(N, 0ll));
    vector ans(M, vector(M, 0ll));
    auto blk = [&](int x) { return (x - 1) / B + 1; };
    auto lb = [&](int x) { return (x - 1) * B + 1; };
    auto rb = [&](int x) { return min(n, x * B); };

    int cntb = blk(n);
    for (int x = 1; x <= cntb; x++) {
        for (int i = 1; i <= rb(x); i++) {
            cmax(pre[x][a[i]], f[i]);
        }
        for (int i = lb(x); i <= n; i++) {
            cmax(suf[x][a[i]], g[i]);
        }
        for (int i = 2; i <= n; i++) {
            cmax(pre[x][i], pre[x][i - 1]);
        }
        for (int i = n - 1; i >= 1; i--) {
            cmax(suf[x][i], suf[x][i + 1]);
        }
    }

    for (int i = 0; i <= cntb; i++) {
        int res = pre[i][n];
        for (int j = cntb + 1; j >= i + 1; j--) {
            for (int k = lb(j); k <= rb(j); k++) {
                cmax(res, pre[i][a[k]] + g[k]);
            }
            ans[i][j] = res;
        }
    }

    while (q--) {
        int l = read(), r = read();
        int x = blk(l), y = blk(r);
        int res = ans[x - 1][y + 1];

        for (int i = lb(x); i < l; i++) {
            cmax(res, f[i] + suf[y + 1][a[i]]);
        }
        for (int i = r + 1; i <= rb(y); i++) {
            cmax(res, pre[x - 1][a[i]] + g[i]);
        }

        if (lb(x) < l and r < rb(y)) {
            vector<pii> v;
            for (int i = r + 1; i <= rb(y); i++) {
                v.eb(a[i], g[i]);
            }
            ranges::sort(v);
            for (int i = v.size() - 2; i >= 0; i--) {
                v[i].se = max(v[i].se, v[i + 1].se);
            }

            for (int i = lb(x); i <= l - 1; i++) {
                auto it = ranges::lower_bound(v, pii(a[i], 0));
                if (it == v.end()) continue;
                cmax(res, f[i] + it->se);
            }   
        }

        cout << res << '\n';
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}