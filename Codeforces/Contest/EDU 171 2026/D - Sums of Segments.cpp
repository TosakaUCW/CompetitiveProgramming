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
        // siz[i] = n - i + 1;
    }

    vector<int> suma(n + 1);
    for (int i = 1; i <= n; i++) {
        suma[i] = suma[i - 1] + a[i];
    }

    vector<int> sum2a(n + 1);
    for (int i = 1; i <= n; i++) {
        sum2a[i] = sum2a[i - 1] + suma[i];
    }

    vector<int> block_sum(n + 1);
    block_sum[1] = sum2a[n];
    for (int i = 2; i <= n; i++) {
        block_sum[i] = block_sum[i - 1] - a[i - 1];
        block_sum[i] -= (n - i + 1) * (a[i - 1]);
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << block_sum[i] << '\n';
    // }

    for (int i = 1; i <= n; i++) {
        block_sum[i] += block_sum[i - 1];
    }

    auto get = [&](int x) {
        int res = 0;

        int p = 0;
        for (int l = 1, r = n; l <= r; ) {
            int mid = l + r >> 1;
            if ((n + n - mid + 1) * mid / 2 < x) {
                p = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        res += block_sum[p];

        x -= (n + n - p + 1) * p / 2;
        res += sum2a[x + p] - sum2a[p] - suma[p] * x;
        return res;
    };

    for (int q = read(); q--; ) {
        int l = read(), r = read();
        cout << get(r) - get(l - 1) << '\n';
        // cout << get(r) << '\n';
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}
/*
sum b[l] ~ b[r] = sumb[r] - sumb[l]

*/