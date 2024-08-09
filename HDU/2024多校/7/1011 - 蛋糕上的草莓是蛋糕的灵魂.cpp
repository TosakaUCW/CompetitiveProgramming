#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;

using i128 = __int128;

i128 read(i128 x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
std::ostream &operator<<(std::ostream &os, i128 n) {
    std::string s;
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

void solve() {
    i128 x = read(), y = read();
    i128 ox = x, oy = y;
    if (x % y != 0) {
        i128 g = std::__gcd(x * 2LL, y);
        y /= g;
        x = x * y * 2LL;
    }
    cout << oy << ' ' << (x / oy) << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}