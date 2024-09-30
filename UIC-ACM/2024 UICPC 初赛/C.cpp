#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr, std::cin, std::cout, std::string, std::vector;
using std::max, std::min, std::swap;
int read(int x = 0, bool f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read(), m = read();

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = read();
    }


    int ans = 0;
    
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int j = 0;

        for (int L = i, R = n - 1; L <= R; ) {
            int mid = L + R >> 1;
            if (a[mid] - a[i] + 1 <= m) {
                j = mid, L = mid + 1;
            } else {
                R = mid - 1;
            }
        }

        ans = max(ans, j - i + 1);
    }

    cout << ans;
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}