#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
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

    using pii = std::pair<int, int>;
    #define fi first
    #define se second

    vector<pii> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i].fi = read();
    }
    for (int i = 1; i <= n; i++) {
        a[i].se = read();
    }
    std::sort(a.begin() + 1, a.end());

    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i].se;
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << a[i].fi << " \n"[i == n];
    // }
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i].se << " \n"[i == n];
    // }
    // for (int i = 1; i <= n; i++) {
    //     cout << sum[i] << " \n"[i == n];
    // }

    for (int q = read(); q--; ) {
        int ql = read(), qr = read();

        int L = 0;
        for (int l = 1, r = n; l <= r; ) {
            int mid = l + r >> 1;
            if (a[mid].fi < ql) {
                L = mid, l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        int R = 0;
        for (int l = 1, r = n; l <= r; ) {
            int mid = l + r >> 1;
            if (a[mid].fi <= qr) {
                R = mid, l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        // cout << L << ' ' << R << " : ";
        cout << sum[R] - sum[L] << '\n';
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}