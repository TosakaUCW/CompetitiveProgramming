#include <bits/stdc++.h>
using i64 = long long;
#define int i64
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
void solve() {
    int n = read();
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }

    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }

    vector<int> val(n + 1);
    for (int i = 1; i <= n; i++) {
        val[i] = val[i - 1] + (a[i] > 0);
    }

    int m = sum[n];
    if (m % 3 != 0) {
        puts("0");
        return;
    }

    m /= 3;

    vector<int> X, Y;

    for (int i = 1; i <= n; i++) {
        if (sum[i] == m) X.eb(i);
        if (sum[i] == 2 * m) Y.eb(i);
    }

    int ans = 0;
    int nn = Y.size() - 1;
    for (auto x : X) {

        if (val[x] <= 0) continue;

        int resL = 0;
        for (int l = 0, r = nn; l <= r; ) {
            int mid = l + r >> 1;
            if (Y[mid] > x and val[Y[mid]] - val[x] > 0) {
                resL = mid, r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        int resR = resL;
        for (int l = resL, r = nn; l <= r; ) {
            int mid = l + r >> 1;
            if (mid >= resL and val[n] - val[Y[mid]]  > 0) {
                resR = mid, l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        ans += resR - resL + 1;
    }

    cout << ans;
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}