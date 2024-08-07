#include <bits/stdc++.h>
#define int long long
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
void solve() {
    int n = read(), k = read(), P = read();

    vector<i64> pw(k + 1);
    pw[0] = 1;
    for (int i = 1; i <= k; i++) pw[i] = pw[i - 1] * 3;

    vector<i64> dp(pw[k]);
    vector<int> vis(pw[k]);
    dp[0] = 1 % P, vis[0] = 1;

    auto print = [&](int x) {
        for (int j = k - 1; ~j; j--)
            putchar((x / pw[j]) % 3 + 'A');
    };

    for (int i = 2; i <= n + 1; i++) {
        string a; cin >> a;

        auto opt = [&](int x) {
            int t = 0;
            for (int j = 0; j < k; j++) {
                int cur = (x / pw[k - 1 - j]) % 3;
                if (a[j] == '+') cur = (cur + 1) % 3;
                if (a[j] == '-') cur = (cur - 1 + 3) % 3;
                t = t * 3 + cur;
            }
            return t;
        };

        vector<i64> ndp = dp;

        for (int j = 0; j < pw[k]; j++) {
            if (!vis[j] or vis[j] == i) continue;
            int s = opt(j);
            // print(j); cout << "->"; print(s); cout << '\n';
            if (!vis[s]) vis[s] = i;
            (ndp[s] += dp[j]) %= P;
        }
        dp = ndp;
    }

    for (int i = 0; i < pw[k]; i++) {
        if (!vis[i]) continue;
        print(i);
        cout << ' ' << dp[i] << '\n';
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}