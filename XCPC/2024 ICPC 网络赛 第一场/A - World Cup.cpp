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
    int a[32];
    for (int i = 0; i < 32; i++) {
        a[i] = read();
    }
    int cnt = 0;
    for (int i = 1; i < 32; i++) {
        if (a[i] < a[0]) {
            cnt++;
        }
    }

    int ans = 32;
    if (cnt >= 31) ans = 1;
    else if (cnt >= 27) ans = 2;
    else if (cnt >= 13) ans = 4;
    else if (cnt >= 6) ans = 8;
    else if (cnt >= 2) ans = 16;
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}