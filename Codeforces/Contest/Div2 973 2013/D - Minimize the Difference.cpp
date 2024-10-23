#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap;
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

    auto checkmx = [&](int x) {
        auto b = a;
        for (int i = 1; i <= n - 1; i++) {
            if (b[i] > x) {
                b[i + 1] += b[i] - x;
            }
        }
        return b[n] <= x;
    };

    auto checkmn = [&](int x) {
        auto b = a;
        for (int i = n; i >= 2; i--) {
            if (b[i] < x) {
                b[i - 1] -= x - b[i];
            }
        }
        return b[1] >= x;
    };

    int mx = 0;
    for (int l = 1, r = 1e12; l <= r; ) {
        int mid = l + r >> 1ll;
        if (checkmx(mid)) mx = mid, r = mid - 1;
        else l = mid + 1;
    }

    int mn = 0;
    for (int l = 1, r = 1e12; l <= r; ) {
        int mid = l + r >> 1ll;
        if (checkmn(mid)) mn = mid, l = mid + 1;
        else r = mid - 1;
    }

    cout << mx - mn << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}