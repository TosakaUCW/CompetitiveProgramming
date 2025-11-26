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
#define fi first
#define se second
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
template <class T> bool cmin(T &a, T b) { return (b < a) ? (a = b, true) : false; }
template <class T> bool cmax(T &a, T b) { return (a < b) ? (a = b, true) : false; }
using pii = pair<int, int>;
using tup = tuple<int, int, int>;
const int inf = 1e18;
const double eps = 1e-9;

vector<int> a;
// #define DEBUG

const int B = 30;
const int all = (1 << B) - 1;

int ask(int c) {
    int res = 0;
#ifdef DEBUG
    for (auto x : a) cmax(res, x ^ c);
#else
    cout << "? " << c << endl;
    cin >> res;
#endif
    return res ^ c;
}
int askmx(int mask, int len) {
    auto s = (1 << (B - len)) - 1;
    auto c = all;
    c &= ~mask & (~s);
    return ask(c);
}

int askmn(int mask, int len) {
    auto s = (1 << (B - len)) - 1;
    auto c = all;
    c &= (~mask | s);
    return ask(c);
}

void solve() {
    int n; cin >> n;

#ifdef DEBUG
    a.resize(n);
    for(auto &x : a) cin >> x;
#endif

    int mx = askmx(0, 0);
    int mn = askmn(0, 0);
    set<int> s;
    s.ep(mx), s.ep(mn);

    [&](this auto&& self, int l, int r) -> void {
        int len = __builtin_clz(l ^ r) - 1;
        if (len == B) return;
        // cerr << "dfs(" << l << ' ' << r << " " << len << ")\n";

        if (s.size() == n) return;
        int nr = askmx(l, len);
        if (nr != l) {
            s.ep(nr);
            self(l, nr);
        }

        if (s.size() == n) return;
        int nl = askmn(r, len);
        if (nl != r) {
            s.ep(nl);
            self(nl, r);
        }
    } (mn, mx);


    cout << "! ";
    for (int x : s) cout << x << " ";
    cout << endl;
}

signed main() {
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}