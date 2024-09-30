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
    int n = read();

    if (n < 0) { puts("-1"); return; }
    if (n == 0) { puts("0"); return; }

    for (int i = 1; i <= 100; i++) {
        int x = 1;

        for (int j = 1; j <= i; j++) {
            x = x * i;
            if (x > n) {
                break;
            }
        }

        if (x == n) {
            cout << i;
            return;
        }
    }

    puts("-1");
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}