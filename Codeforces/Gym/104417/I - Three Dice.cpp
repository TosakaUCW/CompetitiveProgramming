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
    int A = read(), B = read();

    for (int i = 1; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            for (int k = j; k <= 6; k++) {
                int x = 0, y = 0;
                if (i == 1 or i == 4) x += i;
                else y += i;
                if (j == 1 or j == 4) x += j;
                else y += j;
                if (k == 1 or k == 4) x += k;
                else y += k;

                if (x == A and y == B) {
                    puts("Yes");
                    return;
                }
            }
        }
    }

    puts("No");
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}