#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
using std::max, std::min;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;
struct Node {
    int ne[2], d;
    int tag_or, tag_xor;
} t[N * 31];
int cnt = 1;

int merge(int u, int v);
void pushdown(int p) {
    if (!t[p].d or !p) return;

    int dep = t[p].d - 1;

    if (t[p].tag_or >> dep & 1) {
        t[p].ne[1] = merge(t[p].ne[0], t[p].ne[1]);
        t[p].ne[0] = 0;
        t[p].tag_or ^= 1 << dep;
    }

    int lc = t[p].ne[0], rc = t[p].ne[1];
    t[lc].tag_or |= t[p].tag_or;
    t[rc].tag_or |= t[p].tag_or;
    t[lc].tag_xor &= ~t[p].tag_or;
    t[rc].tag_xor &= ~t[p].tag_or;
    t[p].tag_or = 0;

    if (t[p].tag_xor >> dep & 1) {
        std::swap(t[p].ne[0], t[p].ne[1]);
        t[p].tag_xor ^= 1 << dep;
    }

    lc = t[p].ne[0], rc = t[p].ne[1];
    t[lc].tag_xor ^= t[p].tag_xor;
    t[rc].tag_xor ^= t[p].tag_xor;
    t[p].tag_xor = 0;
}
int merge(int u, int v) {
    if (!u or !v) return u + v;
    pushdown(u), pushdown(v);
    t[u].ne[0] = merge(t[u].ne[0], t[v].ne[0]);
    t[u].ne[1] = merge(t[u].ne[1], t[v].ne[1]);
    return u;
}
void insert(int x) {
    int p = 1;
    for (int i = 30; i >= 0; i--) {
        int k = x >> i & 1;
        pushdown(p);
        if (!t[p].ne[k]) t[p].ne[k] = ++cnt, t[cnt].d = i;
        p = t[p].ne[k];
    }
}
int query(int x) {
    int p = 1, ans = 0;
    for (int i = 30; i >= 0; i--) {
        int k = x >> i & 1;
        pushdown(p);
        if (t[p].ne[!k]) {
            p = t[p].ne[!k];
            ans |= (1 << i);
        }
        else {
            p = t[p].ne[k];
        }
    }
    return ans;
}
void modify_or(int x) { t[1].tag_xor &= ~x; t[1].tag_or |= x; }
void modify_and(int x) { t[1].tag_xor |= ~x; t[1].tag_or |= ~x; }
void modify_xor(int x) { t[1].tag_xor ^= x; }

void solve() {
    int n = read(), m = read();
    for (int i = 0; i <= cnt; i++) {
        t[i].d = 0;
        t[i].ne[0] = t[i].ne[1] = t[i].tag_xor = t[i].tag_or = 0;
    }
    cnt = 1;
    t[1].d = 31;
    for (int i = 1; i <= n; i++) insert(read());
    for (int i = 1; i <= m; i++) {
        int opt = read(), x = read();
        if (opt == 1) insert(x);
        if (opt == 2) modify_or(x);
        if (opt == 3) modify_and(x);
        if (opt == 4) modify_xor(x);
        if (opt == 5) cout << query(x) << '\n';
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}