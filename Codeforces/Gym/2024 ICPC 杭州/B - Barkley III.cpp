#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
// using namespace std::views;
// using namespace std::ranges;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
using std::ostream;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

const int N = 1e6 + 5;
const int INF = (1ULL << 63) - 1LL;

pii t[N << 2];
int tag[N << 2];
int n, q;
int a[N];

pii operator + (pii a, pii b) {
    pii res;
    res.fi = a.fi & b.fi;
    res.se = (a.se & b.fi) | (a.fi & b.se);
    return res;
}
void change(int p, int l, int r, int val) {
    t[p].fi &= val;
    tag[p] &= val;
    if (l == r) t[p].se = INF ^ t[p].fi;
    else t[p].se &= val;
}

struct SegTree {
    #define ls (p << 1)
    #define rs (p << 1 | 1)
    #define mid (l + r >> 1)
    void pushup(int p) {
        t[p] = t[ls] + t[rs];
    }
    void pushdown(int p, int l, int r) {
        if (tag[p] == INF) return;
        change(ls, l, mid, tag[p]);
        change(rs, mid + 1, r, tag[p]);
        tag[p] = INF;
    }
    void build(int p, int l, int r) {
        tag[p] = INF;
        if (l == r) {
            t[p] = {a[l], INF ^ a[l]};
            return;
        }
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pushup(p);
    }
    void update(int p, int l, int r, int ql, int qr, int val, int type) {
        if (ql <= l and r <= qr) {
            // cerr << "update range: " << l << ' ' << r << ' ' << t[p] << '\n';
            
            if (type == 1) {
                t[p] = {val, INF ^ val};
            } else {
                change(p, l, r, val);
            }

            // cerr << "update range: " << l << ' ' << r << ' ' << t[p] << '\n';
            return;
        }

        pushdown(p, l, r);
        if (ql <= mid) update(ls, l, mid, ql, qr, val, type);
        if (mid < qr) update(rs, mid + 1, r, ql, qr, val, type);
        pushup(p);
    }
    pii query(int p, int l, int r, int ql, int qr) {
        if (ql > qr) return {INF, 0};
        if (ql <= l and r <= qr) {
            // cerr << "query: " << l << ' ' << r << ' ' << t[p] << '\n';
            return t[p];
        }
        pushdown(p, l, r);
        pii res = {INF, 0};
        if (ql <= mid) res = res + query(ls, l, mid, ql, qr);
        if (mid < qr) res = res + query(rs, mid + 1, r, ql, qr);

        // cerr << "query: " << l << ' ' << r << ' ' << res << '\n';

        return res;
    }
    int find(int p, int l, int r, int ql, int qr, int k) {
        // cerr << "find: " << l << ' ' << r << ' '
         // << ql << ' ' << qr << ' ' << k << '\n';

        if (ql <= l and r <= qr) {

            if (! (t[p].se >> k & 1)) return 0;
            if (l == r) return l;

            pushdown(p, l, r);
            if (t[ls].se >> k & 1) return find(ls, l, mid, ql, qr, k);
            return find(rs, mid + 1, r, ql, qr, k);
        }
        pushdown(p, l, r);
        int res = 0;
        if (ql <= mid) res = find(ls, l, mid, ql, qr, k);
        if (mid < qr and !res) res = find(rs, mid + 1, r, ql, qr, k);
        return res;
    }
} seg;

void solve() {
    n = read();
    q = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    seg.build(1, 1, n);
    while (q--) {
        int opt = read();
        if (opt == 1) {
            int l = read();
            int r = read();
            int x = read();
            seg.update(1, 1, n, l, r, x, 0);
        }
        if (opt == 2) {
            int s = read();
            int x = read();
            seg.update(1, 1, n, s, s, x, 1);
        }
        if (opt == 3) {
            int l = read();
            int r = read();
            pii res = seg.query(1, 1, n, l, r);

            // cerr << "tres: ";
            // cerr << res << '\n';

            if (res.se) {
                int pos = 63 - __builtin_clzll(res.se);
                pos = seg.find(1, 1, n, l, r, pos);
                // cerr << "pos: " << pos << '\n';
                res = seg.query(1, 1, n, l, pos - 1)
                    + seg.query(1, 1, n, pos + 1, r);
            }
            
            // cerr << "-----ans: ";
            cout << res.fi << '\n';
        }
    }
}
/*
0011
1000
0111
0110
0111


0000
0011
*/

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}
