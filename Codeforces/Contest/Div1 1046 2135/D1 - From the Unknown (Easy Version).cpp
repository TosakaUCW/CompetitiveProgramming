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
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int N = 1e5;
const int inf = 1e18;
/*
n, k1

(k1 - 1) * w + 1 <= n <= k1 * w
k1 * w - w + 1 <= n <= k1 * w
n / k1 <= w <= (n - 1) / (k1 - 1)

(k2 - 1) * w + 1 <= n <= k2 * w
n / k2 <= w <= (n - 1) / (k2 - 1)
*/

int ask(const auto &a) {
    cout << "? " << a.size();
    for (int x : a) cout << " " << x;
    cout << endl;
    int res; cin >> res; return res;
}

void solve() {
    const int n1 = 1e5;
    int r1 = ask(vector(n1, 1));

    if (r1 == 1) {
        cout << "! 100000\n";
        return;
    }

    int L = (n1 + r1 - 1) / r1;
    int R = (n1 + r1 - 2) / (r1 - 1) - 1;

    if (L == R) {
        cout << "! " << L << '\n';
        return;
    }

    vector<int> qry;
    for (int i = 1; i <= R - L; i++) {
        qry.eb(L); qry.eb(i);
    }

    int r2 = ask(qry);

    int ans = 2 * R - L - r2;

    cout << "! " << ans << endl;
}

signed main() {
    // freopen("D.in", "r", stdin);
    // freopen("D.out", "w", stdout);
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}