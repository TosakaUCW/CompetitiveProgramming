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
    int h = read();

    for (int i = 1; i <= n; i++) {
        int x = read();
        int y = read();
        int z = read();

        if (z <= h) z = h + h - z;

        int g = std::gcd(x, y);
        g = std::gcd(g, z);
        cout << x / g << " " << y / g << " " << z / g << "\n";
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}