#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr, std::cin, std::cout, std::string, std::vector;
using std::max, std::min, std::swap;
int read(int x = 0, bool f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;
const int INF = 1e18;

struct SGT {
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (l + r >> 1)
    int mx[N << 2];

    void build(int p, int l, int r) {
        if (l == r) { mx[p] = l == 1 ? 0 : -INF; return; }

        build(ls, l, mid), build(rs, mid + 1, r);
        mx[p] = max(mx[ls], mx[rs]);
    }

    void upd(int p, int l, int r, int pos, int val) {
        if (l == r) {
            mx[p] = max(mx[p], val);
            return;
        }

        if (pos <= mid) upd(ls, l, mid, pos, val);
        else upd(rs, mid + 1, r, pos, val);

        mx[p] = max(mx[ls], mx[rs]);
    }

    int qry(int p, int l, int r, int ql, int qr) {
        if (ql <= l and r <= qr) return mx[p];

        int res = -INF;

        if (ql <= mid) res = max(res, qry(ls, l, mid, ql, qr));
        if (mid < qr) res = max(res, qry(rs, mid + 1, r, ql, qr));

        return res;
    }
} lsg, rsg;

void solve() {
    int n = read(), c = read();

    lsg.build(1, 1, n);
    rsg.build(1, 1, n);

    int ans = 0;
    for (int m = read(); m--; ) {
        int t = read(), p = read();

        int dp1 = lsg.qry(1, 1, n, 1, t) - c * (t - 1);
        int dp2 = rsg.qry(1, 1, n, t, n) + c * (t - 1);

        int dp = max(dp1, dp2) + p;
        ans = max(ans, dp);

        lsg.upd(1, 1, n, t, dp + c * (t - 1));
        rsg.upd(1, 1, n, t, dp - c * (t - 1));
    }
    cout << ans;
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}