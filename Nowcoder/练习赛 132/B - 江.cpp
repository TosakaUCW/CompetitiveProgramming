#include <bits/stdc++.h>
// using i64 = long long;
// #define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int inf = 1e9;

void solve() {
    int n = read();
    int m = read();
    int k = read();

    vector<int> a;
    std::unordered_map<int, bool> vis;
    for (int i = 1; i <= n; i++) {
        int x = read();
        if (vis[x]) continue;
        vis[x] = 1;
        a.eb(x);
    }

    std::sort(a.begin(), a.end());
    n = a.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int res = i;
        for (int L = i, R = n - 1; L <= R; ) {
            int mid = L + R >> 1;
            // cerr << mid << '\n';
            if (a[mid] - a[i] + 1 <= mid - i + 1 + k) {
                res = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        // cerr << "i: " << i << " res: " << res << '\n';
        ans = max(ans, min(m, res - i + 1 + k));
    }
    for (int i = n - 1; i >= 0; i--) {
        int res = i;
        for (int L = 0, R = i; L <= R; ) {
            int mid = L + R >> 1;
            // cerr << mid << '\n';
            if (a[i] - a[mid] + 1 <= i - mid + 1 + k) {
                res = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        // cerr << "i: " << i << " res: " << res << '\n';
        ans = max(ans, min(m, i - res + 1 + k));
    }

    cout << ans << '\n';
}

// 1 2 3 5

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}