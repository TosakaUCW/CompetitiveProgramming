#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    i64 n = read(), x = read(), k = read();
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();
    std::priority_queue<i64> s;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        s.push(a[i]);
        while (!s.empty() and k and x <= a[i]) {
            k--;
            x += s.top();
            s.pop();
        }
        x -= a[i];
        if (x <= 0) {
            break;
        }
        ans = i;
    }
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}