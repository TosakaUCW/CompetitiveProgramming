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
    int N = read(), m = read();


    int k = 0;
    while (N--) {
        int n = read();
        std::set<int> st;

        for (int i = 0; i <= n + 1; i++) {
            st.emplace(i);
        }

        for (int i = 0; i < n; i++) {
            int x = read();
            st.erase(x);
        }
        k = max(k, *++st.begin());
    }

    i64 ans = 0;

    if (k >= m) {
        ans = (m + 1) * k;
    } else {
        ans = k * k + (m + k) * (m - k + 1) / 2;
    }
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}