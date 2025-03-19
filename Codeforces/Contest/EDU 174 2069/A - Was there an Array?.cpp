#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
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

struct DSU {
    std::vector<int> f, siz;
    DSU() {}
    DSU(int n) { init(n); }
    void init(int n) { f.resize(n), std::iota(f.begin(), f.end(), 0), siz.assign(n, 1); }
    int find(int x) { while (x != f[x]) x = f[x] = f[f[x]]; return x; }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        siz[x] += siz[y], f[y] = x;
        return true;
    }
    int size(int x) { return siz[find(x)]; }
};


void solve() {
    int n = read();

    DSU dsu(n);

    vector<int> a(n);
    for (int i = 1; i + 1 < n; i++) a[i] = read();

    for (int i = 1; i + 1 < n; i++) {
        if (a[i] == 1) {
            dsu.merge(i, i - 1);
            dsu.merge(i, i + 1);
        }
    }

    for (int i = 1; i + 1 < n; i++) {
        if (a[i] == 1) {
            if (dsu.same(i, i - 1) and dsu.same(i, i + 1)) {
                continue;
            } else {
                puts("NO");
                return;
            }
        } else {
            if (dsu.same(i, i - 1) and dsu.same(i, i + 1)) {
                puts("NO");
                return;
            } else {
                continue;
            }
        }
    }

    // cerr << b << '\n';

    puts("YES");
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
