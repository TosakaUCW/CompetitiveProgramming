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

    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        a[i].fi = read();
    }
    for (int i = 0; i < n; i++) {
        a[i].se = read();
    }
    
    ranges::sort(a, [&](auto i, auto j) {
        return i.se > j.se;
    });
    // debug(a);

    int n1 = n / 2; // [0, n1)
    int n2 = n - n1; // [n1, n)

    vector<vector<pii>> buk(n2 + 1);

    int all2 = 1 << n2;
    for (int s = 0; s < all2; s++) {
        int tot = 0;
        int A = 0;
        int B = 0;
        for (int i = n2 - 1; i >= 0; i--) {
            if (s >> i & 1) {
                tot++;
                A += a[i + n1].fi;
                B += a[i + n1].se * (tot - 1);
            }
        }
        buk[tot].eb(A, B);
        // cerr << tot << " " << A << " " << B << '\n';
    }

    vector<vector<int>> premx(n2 + 1);
    for (int i = 0; i <= n2; i++) {
        if (buk[i].empty()) continue;

        ranges::sort(buk[i], [&](auto i, auto j) {
            return i.fi < j.fi;
        });
        int siz = buk[i].size();
        premx[i].assign(siz, 0ll);
        premx[i][0] = buk[i][0].se;
        for (int j = 1; j < siz; j++) {
            premx[i][j] = max(premx[i][j - 1], buk[i][j].se);
        }
    }

    int ans = 0;

    int all1 = 1 << n1;
    for (int s = 0; s < all1; s++) {
        int tot = 0;
        int A = 0, B = 0;
        for (int i = n1 - 1; i >= 0; i--) {
            if (s >> i & 1) {
                A += a[i].fi;
            }
        }

        if (A > m) continue;

        int rem = m - A;
        for (int i = 0; i <= n2; i++) {
            int tot = i;

            int pos = -1;
            for (int L = 0, R = buk[i].size() - 1; L <= R; ) {
                int mid = L + R >> 1;
                if (buk[i][mid].fi <= rem) {
                    pos = mid, L = mid + 1;
                } else {
                    R = mid - 1;
                }
            }

            if (pos == -1) continue;
            int res = premx[i][pos];

            for (int i = n1 - 1; i >= 0; i--) {
                if (s >> i & 1) {
                    tot++;
                    res += a[i].se * (tot - 1);
                }
            }

            cmax(ans, res);
            // debug(res);
        }
    }

    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}