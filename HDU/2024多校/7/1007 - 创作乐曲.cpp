#include <bits/stdc++.h>
using i64 = long long;
#define int long long
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
using std::max, std::min;
const int N = 4e5 + 5;
#define mid (l + r >> 1)
int rt, c[N << 5], lc[N << 5], rc[N << 5], cnt;
void upd(int &p, int l, int r, int x, int val) {
    if (!p) p = ++cnt;
    c[p] = val;
    if (l == r) { return; }
    if (x <= mid) upd(lc[p], l, mid, x, val);
    else upd(rc[p], mid + 1, r, x, val);
}
int query(int p, int l, int r, int x, int y) {
    if (!p) return 0;
    if (x <= l and r <= y) return c[p];
    int res = 0;
    if (x <= mid) res = max(res, query(lc[p], l, mid, x, y));
    if (mid < y) res = max(res, query(rc[p], mid + 1, r, x, y));
    return res;
}

void solve() {
    int n = read(), m = read(), k = read();

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();

    vector<int> pre(n + 1), nxt(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = query(rt, 1, m, max(1LL, a[i] - k), a[i]);
        nxt[i] = query(rt, 1, m, a[i], min(m, a[i] + k));
        upd(rt, 1, m, a[i], i);
    }

    for (int q = read(); q--; ) {
        int L = read(), R = read();
        vector<int> dp(n + 1);
        int res = 0;
        for (int i = L; i <= R; i++) {
            dp[i] = 1;
            if (pre[i] >= L) dp[i] = max(dp[i], dp[pre[i]] + 1);
            if (nxt[i] >= L) dp[i] = max(dp[i], dp[nxt[i]] + 1);
            res = std::max(res, dp[i]);
        }
        cout << R - L + 1 - res << '\n';
    }

    for (int i = 0; i <= cnt; i++) lc[i] = rc[i] = c[i] = 0;
    rt = cnt = 0;
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}