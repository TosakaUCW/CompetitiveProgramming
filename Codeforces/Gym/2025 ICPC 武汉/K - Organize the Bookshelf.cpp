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

void solve() {
    int n = read();

    vector<int> a(n), b(n);
    vector<vector<int>> pos(n);

    for (int i = 0; i < n; i++) {
        a[i] = read() - 1;
        pos[a[i]].eb(i);
    }
    for (int i = 0; i < n; i++) {
        b[i] = read() - 1;
        pos[b[i]].eb(i);
    }

    for (auto &p : pos) {
        if (p.size() & 1) { cout << "-1\n"; return; }
        ranges::sort(p, [&](int i, int j) {
            return i > j;
        });
    }

    int ans = 0;
    vector<pii> ops;

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            pos[a[i]].pop_back();
            pos[b[i]].pop_back();
            continue;
        }

        auto op = [&](int i, int j) -> void {
            ops.eb(i + 1, j + 1); 
            swap(a[i], b[j]);
            ans += abs(j - i);
        };

        int pa = pos[a[i]].end()[-2];
        int pb = pos[b[i]].end()[-2];

        if (pa <= pb) {
            if (b[pa] == a[i]) {
                op(i, i), op(i, pa);
            } else {
                op(i, i), op(pa, pa), op(i, pa);
            }
            pos[a[i]].pop_back();
            pos[a[i]].pop_back();
        } else {
            if (b[pb] == b[i]) {
                op(i, pb);
            } else {
                op(pb, pb), op(i, pb);
            }
            pos[b[i]].pop_back();
            pos[b[i]].pop_back();
        }
    }

    cout << ans << " " << ops.size() << "\n";
    for (auto [i, j] : ops) cout << i << " " << j << "\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}