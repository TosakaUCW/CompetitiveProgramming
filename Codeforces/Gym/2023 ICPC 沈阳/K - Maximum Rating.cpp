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
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e9 + 5;

const int N = 1e6 + 5;

int idx;
struct Node {
    int ls, rs, sum, cnt;
} t[N << 4];

#define ls t[p].ls
#define rs t[p].rs
#define mid (l + r >> 1)
void pushup(int p) {
    t[p].sum = t[ls].sum + t[rs].sum;
    t[p].cnt = t[ls].cnt + t[rs].cnt;
}
void modify(int &p, int l, int r, int pos, int num) {
    if (!p) p = ++idx;
    if (l == r) { 
        t[p].sum += pos * num; 
        t[p].cnt += num; 
        return;
    }
    if (pos <= mid) modify(ls, l, mid, pos, num);
    else modify(rs, mid + 1, r, pos, num);
    pushup(p);
}
int query(int p, int l, int r, int sum) {
    if (l == r) {
        return sum <= 0 ? 0 : (sum + l - 1) / l;
    }
    if (t[rs].sum >= sum) {
        return query(rs, mid + 1, r, sum);
    } else {
        return query(ls, l, mid, sum - t[rs].sum) + t[rs].cnt;
    }
}

void solve() {
    int n = read(), q = read();

    int sum = 0, rt = 0;

    vector<int> a(n);
    for (auto &x : a) {
        x = read();
        if (x > 0) modify(rt, 1, inf, x, +1);
        sum += x;
    }
    while (q--) {
        int x = read() - 1, v = read();

        if (a[x] > 0) modify(rt, 1, inf, a[x], -1);
        if (v > 0) modify(rt, 1, inf, v, +1);

        sum += v - a[x];
        a[x] = v;

        int res = t[1].cnt - query(rt, 1, inf, sum) + 1;
        cout << res << '\n';
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}