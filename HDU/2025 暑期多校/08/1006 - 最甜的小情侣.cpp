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
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

const int N = 2e5 + 5;
int a[N];

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (l + r >> 1)

struct Info {
    int len;
    int dp[4][4];
} t[N << 3], tmp;
Info operator + (const Info &a, const Info &b) {
    Info c = tmp;
    c.len = a.len + b.len;
    for (int l1 = 0; l1 < 4; l1++) {
        for (int r1 = 0; r1 < 4; r1++) {
            for (int l2 = 0; r1 + l2 < 4; l2++) {
                for (int r2 = 0; r2 < 4; r2++) {

                    if (a.dp[l1][r1] < 0) continue;

                    int nl = l1 == a.len ? l1 + l2 : l1;
                    int nr = r2 == b.len ? r1 + r2 : r2;
                    c.dp[nl][nr] = max(c.dp[nl][nr], a.dp[l1][r1] + b.dp[l2][r2]);
                }
            }
        }
    }

    return c;
}
void build(int p, int l, int r) {
    if (l == r) {
        t[p] = tmp;
        t[p].len = 1;
        t[p].dp[0][0] = 0;
        t[p].dp[1][1] = a[l];
        return;
    }
    build(ls, l, mid), build(rs, mid + 1, r);
    t[p] = t[ls] + t[rs];
}
void modify(int p, int l, int r, int pos) {
    if (l == r) {
        t[p].dp[1][1] = a[l];
        return;
    }
    if (pos <= mid) modify(ls, l, mid, pos);
    else modify(rs, mid + 1, r, pos);
    t[p] = t[ls] + t[rs];
}
int getAns() {
    // return t[1].len;
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; i + j < 4; j++) {
            ans = max(ans, t[1].dp[i][j]);
        }
    }
    return ans;
}

void solve() {
    int n = read(), q = read();
    for (int i = 1; i <= n; i++) a[i] = read();

    build(1, 1, n);
    cout << getAns() << '\n';

    while (q--) {
        int x = read(), v = read();
        a[x] = v;
        modify(1, 1, n, x);
        cout << getAns() << '\n';
    }
}

signed main() {
    tmp.len = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tmp.dp[i][j] = -inf;
        }
    }
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}