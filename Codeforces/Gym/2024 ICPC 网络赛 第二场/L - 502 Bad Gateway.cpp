#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap;
using std::cerr, std::cin, std::cout, std::string, std::vector;
int read(int x = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return x;
}

void solve() {
    int T = read(); 

    int res = 0;
    for (int L = 0, R = T; L <= R; ) {
        int mid = (L + R) / 2LL;
        if (mid * mid <= 2LL * T) res = mid, L = mid + 1;
        else R = mid - 1;
    }

    int x = res, y = res + 1;
    int p1 = (2LL * T + x * x - x) * (y);
    int p2 = (2LL * T + y * y - y) * (x);
    if (p1 > p2) std::swap(x, y);

    int up = 2 * T + x * x - x;
    int down = 2 * x;

    int g = std::__gcd(up, down);
    up /= g, down /= g;
    std::cout << up << " " << down << "\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}