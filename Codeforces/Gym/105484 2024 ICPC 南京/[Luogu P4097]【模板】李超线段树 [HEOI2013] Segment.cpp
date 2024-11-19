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
const int mod1 = 39989;
const int mod2 = 1e9;
const int N = 1e6 + 5;
const double eps = 1e-9;

#define mid (l + r >> 1)
#define ls (p << 1)
#define rs (p << 1 | 1)

int cmp(double x, double y) {
    if (x - y > eps) return 1;
    if (y - x > eps) return -1;
    return 0;
}

struct Node {
    double k, b;
} p[N];

int s[N << 4], cnt;

double calc(int id, int d) { return p[id].b + p[id].k * d; }

void add(int x0, int y0, int x1, int y1) {
    cnt++;
    if (x0 == x1) {
        p[cnt].k = 0;
        p[cnt].b = max(y0, y1);
    } else {
        p[cnt].k = 1.0 * (y1 - y0) / (x1 - x0);
        p[cnt].b = y0 - p[cnt].k * x0;
    }
}

void upd(int p, int l, int r, int u) {
    int &v = s[p];

    int f = cmp(calc(u, mid), calc(v, mid));

    if (f == 1 or (!f and u < v)) {
        swap(u, v);
    }

    int fl = cmp(calc(u, l), calc(v, l));
    int fr = cmp(calc(u, r), calc(v, r));

    if (fl == 1 or (!fl and u < v)) upd(ls, l, mid, u);
    if (fr == 1 or (!fr and u < v)) upd(rs, mid + 1, r, u);
}

void update(int p, int l, int r, int ql, int qr, int u) {
    if (ql <= l and r <= qr) {
        upd(p, l, r, u);
        return;
    }
    if (ql <= mid) update(ls, l, mid, ql, qr, u);
    if (mid < qr) update(rs, mid + 1, r, ql, qr, u);
}

using pii = std::pair<double, int>;
#define fi first
#define se second
pii pmax(pii a, pii b) {
    if (cmp(a.fi, b.fi) == 1) {
        return a;
    } else if (cmp(a.fi, b.fi) == -1) {
        return b;
    } else {
        return a.se < b.se ? a : b;
    }
}
pii query(int p, int l, int r, int d) {
    if (d < l or r < d) return {0, 0};
    double res = calc(s[p], d);
    if (l == r) return {res, s[p]};
    return pmax({res, s[p]}, pmax(query(ls, l, mid, d), query(rs, mid + 1, r, d)));
}

void solve() {
    int lasans = 0;
    for (int n = read(); n--; ) {
        int opt = read();


        if (opt == 1) {
            int x0 = read(), y0 = read();
            int x1 = read(), y1 = read();

            x0 = (x0 + lasans - 1 + mod1) % mod1 + 1;
            x1 = (x1 + lasans - 1 + mod1) % mod1 + 1;
            y0 = (y0 + lasans - 1 + mod2) % mod2 + 1;
            y1 = (y1 + lasans - 1 + mod2) % mod2 + 1;

            // cerr << x0 << y0 << x1 << y1 << '\n';

            if (x0 > x1) {
                swap(x0, x1);
                swap(y0, y1);
            }

            add(x0, y0, x1, y1);
            update(1, 1, mod1, x0, x1, cnt);
        } else {
            int x = read();

            x = (x + lasans - 1 + mod1) % mod1 + 1;
            // cerr << x << "\n";

            lasans = query(1, 1, mod1, x).second;
            cout << lasans << '\n';
        }
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}