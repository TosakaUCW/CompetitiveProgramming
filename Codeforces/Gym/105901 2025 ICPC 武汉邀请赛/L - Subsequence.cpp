#include <bits/stdc++.h>
using i64 = long long;
using ull = unsigned long long;
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
using pii = pair<int, int>;
const int inf = 1e9;

void solve() {
    int n = read();

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }

    int ans = 0;

    auto b = a;
    sort(b.begin() + 1, b.end());

    // cerr << b << '\n';

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {

            int k = -1;
            int need = b[j] * 2 - b[i];
            for (int L = 1, R = n; L <= R; ) {
                int mid = L + R >> 1;
                if (b[mid] <= need) k = mid, L = mid + 1;
                else R = mid - 1;
            }

            if (k == -1 or b[k] != need) continue;

            // cerr << i << ' ' << j << ' ' << k << '\n';

            int x = j - i;
            int y = k - j + 1;

            // cout << mn << ' ' << md << ' ' << mx << '\n';

            // odd
            int t = min(x, y - 1);
            ans = max(ans, 2 * t + 1);

            // cout << 2 * t + 1 << ' ';

            // even
            t = min(x, y - 2);
            ans = max(ans, 2 * t + 2);

            
            // cout << 2 * t + 2 << '\n';
        }
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}