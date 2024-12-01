#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;

struct SGT {
    #define ls (p << 1)
    #define rs (p << 1 | 1)
    #define mid (l + r >> 1)
    int mx[N << 2], tag[N << 2];

    void pushup(int p) {
        mx[p] = max(mx[ls], mx[rs]);
    }
    void pushdown(int p) {
        if (tag[p] == 0) return;
        mx[ls] = max(mx[ls], tag[p]);
        mx[rs] = max(mx[rs], tag[p]);
        tag[ls] = max(tag[ls], tag[p]);
        tag[rs] = max(tag[rs], tag[p]);
        tag[p] = 0;
    }

    int qry(int p, int l, int r, int ql, int qr) {
        if (ql <= l and r <= qr) {
            return mx[p];
        }
        int res = 0;
        pushdown(p);
        if (ql <= mid) res = max(res, qry(ls, l, mid, ql, qr));
        if (mid < qr) res = max(res, qry(rs, mid + 1, r, ql, qr));
        pushup(p);
        return res;
    }
    void upd(int p, int l, int r, int ql, int qr, int x) {
        if (ql <= l and r <= qr) {
            mx[p] = max(mx[p], x);
            tag[p] = max(tag[p], x);
            return;
        }
        pushdown(p);
        if (ql <= mid) upd(ls, l, mid, ql, qr, x);
        if (mid < qr) upd(rs, mid + 1, r, ql, qr, x);
        pushup(p);
    }
} sgt;

void solve() {
    int h = read();
    int w = read();
    int n = read();

    using tup = std::tuple<int, int, int>;
    vector<vector<tup>> a(h + 1);

    for (int i = 1; i <= n; i++) {
        int r = h - read() + 1;
        int c = read();
        int l = read();

        // cerr << r << " " << c << " " << c + l - 1 << '\n';
        a[r].eb(c, c + l - 1, i);
    }

    vector<int> ans(n + 1);
    for (int i = 1; i <= h; i++) {
        for (auto [l, r, idx] : a[i]) {
            // cout << i << " " << sgt.qry(1, 1, w, l, r);
            ans[idx] = sgt.qry(1, 1, w, l, r) + 1;
            sgt.upd(1, 1, w, l, r, ans[idx]);

            // cout << " " << ans[idx] << '\n';
        }
    }

    for (int i = 1; i <= n; i++) {
        // cout << ans[i] << "\n";
        cout << h - ans[i] + 1 << "\n";
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}