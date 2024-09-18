#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
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

    vector<int> a(n + 2);
    a[0] = a[n + 1] = 2e9;
    for (int i = 1; i <= n; i++) a[i] = read();

    i64 ans = 0;

    vector<int> stk {0};
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() and a[stk.back()] < a[i]) {
            stk.pop_back();
        }
        ans += i - stk.back() - 1;
        stk.push_back(i);
    }

    stk = {n + 1};
    for (int i = n; i >= 1; i--) {
        while (!stk.empty() and a[stk.back()] < a[i]) {
            stk.pop_back();
        }
        if (a[stk.back()] != a[i]) ans += stk.back() - i - 1;
        stk.push_back(i);
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}