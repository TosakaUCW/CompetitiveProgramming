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
    int a = read(), b = read();

    if (2 * a < b) {
        cout << "0\n";
    } else {
        cout << min(a, a - (b - a)) << '\n';
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}