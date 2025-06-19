#include <bits/stdc++.h>
using i64 = long long;
using ull = unsigned long long;
using i128 = __int128;
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
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int n = read();
    int k = read();

    vector<int> a(n + 1), b(n + 1), c(n + 1);

    for (int i = 1; i <= n; i++) {
        a[i] = read();
        b[i] = 1;

        int x = a[i];
        while (x % 2 == 0) {
            b[i] *= 2;
            x /= 2;
        }
        c[i] = x;
    }

    vector<int> pre(n + 2), suf(n + 2);
    for (int i = 2; i <= n; i++) {
        if (c[i] != c[i - 1] or a[i] > a[i - 1]) {
            pre[i] = b[i - 1];
        } else {
            pre[i] = b[i - 1] - 2 * b[i] + 1;
        }
        pre[i] += pre[i - 1];
    }
    for (int i = n - 1; i >= 1; i--) {
        if (c[i] != c[i + 1] or a[i] > a[i + 1]) {
            suf[i] = b[i + 1];
        } else {
            suf[i] = b[i + 1] - 2 * b[i] + 1;
        }
        suf[i] += suf[i + 1];
    }

    for (int i = 1; i <= n; i++) {
        if (pre[i] + b[i] + suf[i] >= k) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}