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
    int k = read();

    vector<int> a(n + 1);
    vector<int> b(65, -1);
    // vector<int> c(65, -1);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        
    }

    for (int i = 1; i < n; i++) {
        for (int j = 60; j >= 0; j--) {
            int x = a[i] >> j & 1;
            int y = a[i + 1] >> j & 1;

            if (x != y) {
                int now = x;
                if (b[j] != -1 and b[j] != x) {
                    puts("0");
                    return;
                }
                b[j] = x;
                break;
            }
        }
    }

    // for (int i = 0; i < 60; i++) {
    //     b[i] = b[i] == -1 ? 2 : 1;
    //     cerr << b[i] << " ";
    // }

    // int ans = 1;

    // for (int i = 60; i >= 0; i--) {
    //     int x = k >> i & 1;
    //     if (x) {
    //         cout << "i: " << i << '\n';
    //         int res = 1;
    //         // i - b[i]
    //         if (i - 1 >= 0)
    //             res *= 1LL << (i - b[i - 1]);
    //         // cout << "res: " << res << '\n';
    //         ans += res;
    //     }
    // }

    vector dp(65, vector<int>(2, -1));

    auto dfs = [&](auto&& self, int now, bool f) -> int {
        if (now == -1) return 1;
        if (~dp[now][f]) return dp[now][f];

        int res = 0;
        int lim = f ? (k >> now & 1) : 1;
        for (int j = 0; j <= lim; j++) {
            if (b[now] == -1 or b[now] == j) {
                res += self(self, now - 1, f && (j == lim));
            }
        }

        dp[now][f] = res;
        return res;
    };

    int ans = dfs(dfs, 60, 1);
    
    cout << ans << '\n';
}

/*
01000 = 2
01000 = 2
00100 = 4
00001 = 16

12121

10001 = 17 = k

xxxx0 = 4
x0001 = 2
10001 = 1
*/

/*
11000 = 3
01000 = 2
10100 = 5
00001 = 16

22121

10001 = 17 = k

xxxx0 = 6
x0001 = 2
10001 = 1
*/

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}