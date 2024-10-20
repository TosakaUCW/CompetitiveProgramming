#include <bits/stdc++.h>
using i64 = long long;
#define int i64
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
    int cnt[N << 2];
    int sum[N << 2][4];
    #define ls (p << 1)
    #define rs (p << 1 | 1)
    #define mid (l + r >> 1)
    void pushup(int p) {
        cnt[p] = cnt[ls] + cnt[rs];
        sum[p][0] = sum[p][1] = sum[p][2] = sum[p][3] = 0;
        for (int i = 0; i < 4; i++) {
            sum[p][i] += sum[ls][i];
            sum[p][(cnt[ls] + i) % 4] += sum[rs][i];
        }
    }

    void upd(int p, int l, int r, int pos, int val) {
        if (l == r) {
            if (val > 0) sum[p][cnt[p] % 4] += pos;
            else sum[p][(cnt[p] - 1) % 4] -= pos;

            cnt[p] += val;
            return;
        }

        if (pos <= mid) upd(ls, l, mid, pos, val);
        else upd(rs, mid + 1, r, pos, val);
        pushup(p);
    }
    void upd(int pos, int val) {
        upd(1, -1e5, 1e5, pos, val);
    }
    int qry(int p = 1) {
        int res = sum[ls][0] + sum[ls][3];

        if (cnt[ls] * 2 % 4 == 0) {
            res += sum[rs][0] + sum[rs][2];
        } else {
            res += sum[rs][1] + sum[rs][3];
        }

        return res;
    }

} seg;

void solve() {
    int n = read(), m = read();

    int sumb = 0;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = read(), b[i] = read();

        seg.upd(a[i] - b[i], 1);
        sumb += b[i];
    }

    cout << sumb + seg.qry() << '\n';
    for (int i = 1; i <= m; i++) {
        int t = read(), x = read(), y = read();

        sumb -= b[t], sumb += y;
        seg.upd(a[t] - b[t], -1);
        a[t] = x, b[t] = y;
        seg.upd(a[t] - b[t], 1);
        cout << sumb + seg.qry() << '\n';
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}