#include <bits/stdc++.h>
using i64 = long long;
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
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second
 
struct Fenwick {
    int n;
    vector<int> tree;
    Fenwick(int n): n(n), tree(n + 1, 0) {}
    void update(int i, int delta) {
        for (; i <= n; i += i & -i)
            tree[i] += delta;
    }
    int query(int i) {
        int s = 0;
        for (; i; i -= i & -i)
            s += tree[i];
        return s;
    }
    int lower_bound(int target) {
        int idx = 0;
        for (int bit = 1 << 18; bit; bit >>= 1) {
            if (idx + bit <= n and tree[idx+bit] < target) {
                target -= tree[idx+bit];
                idx += bit;
            }
        }
        return idx + 1;
    }
};
 
struct Node {
    int L, R, cand;
};
struct Evt {
    int x, cand, type;
};

void solve() {
    int n = read();
    int q = read();

    vector<int> w(n);
    for (auto &x : w) x = read();

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = w[n - i];
    }
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] ^ a[i];
    }

    const int BITS = 30;
    vector<Node> nodes;
    for (int i = 1; i <= n; i++) {
        for (int b = 0; b < BITS; b++) {
            if ((a[i] >> b) & 1) {
                int t = ((sum[i - 1] ^ a[i]) >> (b + 1)) << (b + 1);
                int L = t | (((sum[i - 1] >> b) & 1) << b);
                int R = L | ((1 << b) - 1);
                nodes.eb(L, R, i);
            }
        }
    }

    ranges::sort(nodes, [](auto a, auto b) {
        if (a.cand == b.cand) return a.L < b.L;
        return a.cand < b.cand;
    });
    vector<Node> rnod;
    for (int i = 0; i < nodes.size(); ) {
        auto [Lcur, Rcur, cand] = nodes[i];

        int j = i+1;
        while (j < nodes.size() and nodes[j].cand == cand) {
            if (nodes[j].L <= Rcur + 1)
                Rcur = max(Rcur, nodes[j].R);
            else {
                rnod.eb(Lcur, Rcur, cand);
                Lcur = nodes[j].L;
                Rcur = nodes[j].R;
            }
            j++;
        }
        rnod.eb(Lcur, Rcur, cand);
        i = j;
    }

    vector<Evt> evt;
    for (auto &[L, R, cand] : rnod) {
        evt.eb(L, cand, 1);
        if (R + 1 <= (1 << BITS) - 1)
            evt.eb(R + 1, cand, -1);
    }

    ranges::sort(evt, [](auto a, auto b) {
        if (a.x != b.x) return a.x < b.x;
        return a.type > b.type;
    });

    vector<pii> qry;
    for (int i = 0; i < q; i++) {
        int x = read();
        qry.eb(x, i);
    }

    vector<int> coords;
    for (auto [x, _, __] : evt) coords.eb(x);
    for (auto [x, y] : qry) coords.eb(x);
    ranges::sort(coords);
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    auto comp = [&](int x) -> int {
        return ranges::lower_bound(coords, x) - coords.begin();
    };

    for (auto &[x, _, __] : evt) x = comp(x);

    auto nqry = qry;
    for (auto &[x, y] : nqry) x = comp(x);
    ranges::sort(nqry);

    Fenwick bit(n);
    
    vector<int> res(q);

    int p = 0, evn = evt.size();
    for (auto &[x, i] : nqry) {

        for (; p < evn; p++) {
            if (evt[p].x > x) break;
            bit.update(evt[p].cand, evt[p].type);
        }

        if (bit.query(n) < 1) {
            res[i] = n;
        } else {
            int t = bit.lower_bound(1);
            if (t > n) res[i] = n;
            else res[i] = t - 1;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << res[i] << " \n"[i == q - 1];
    }
}
 
signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
