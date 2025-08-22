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
const int inf = 1e18;

void solve() {
    int n = read();
    int i0 = read();
    int t0 = read();

    vector<int> l(n + 1), r(n + 1, -1);
    l[0] = r[0] = t0;
    for (int i = 0; i < n; i++) {
        int il = read(), ir = read();
        int tl = read(), tr = read();

        for (int j = i; j >= 0; j--) {
            if (i0 + j < il or i0 + j > ir) continue;

            int L = max(l[j], tl);
            int R = min(r[j], tr);
            if (L > R) continue;

            r[j] = max(r[j], R + 1);
            if (r[j + 1] < l[j + 1]) {
                l[j + 1] = L;
                r[j + 1] = R;
            } else {
                l[j + 1] = min(l[j + 1], L);
                r[j + 1] = max(r[j + 1], R);
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= n; j++) {
        if (l[j] <= r[j]) {
            ans = max(ans, j + r[j] - t0);
        }
    }

    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}