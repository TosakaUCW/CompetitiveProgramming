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
    int n = read(), d = read();
    int ans = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
 
    for (int i = 1; i <= n; i++) {
        int L = a[i], R = a[i] + d;
 
        int res = 0;
        for (int j = 1; j < n; j++) {
            int x = a[j];
            int y = a[j + 1];
            x = max(x, L);
            x = min(x, R);
            y = max(y, L);
            y = min(y, R);
            res += abs(x - y);
        }
 
        ans = max(ans, res);
    }
 
    for (int i = 1; i <= n; i++) {
        int L = a[i] - d, R = a[i];
 
        int res = 0;
        for (int j = 1; j < n; j++) {
            int x = a[j];
            int y = a[j + 1];
            x = max(x, L);
            x = min(x, R);
            y = max(y, L);
            y = min(y, R);
            res += abs(x - y);
        }
 
        ans = max(ans, res);
    }
    
    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}