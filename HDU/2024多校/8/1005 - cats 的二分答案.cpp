#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::max, std::min;
using std::cin, std::cout, std::string, std::vector;
i64 read(i64 x = 0, i64 f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

std::unordered_map<i64, i64> mp[62];

i64 go(i64 r, i64 d) {
    if (r == 0) return 0;
    if ((1LL << d) > r) return r;
    if (mp[d][r]) return mp[d][r];

    i64 mid = (1 + r) / 2;

    mp[d][r] = 1 + go(r - mid, d);
    if (d >= 1) mp[d][r] += go(mid - 1, d - 1);

    return mp[d][r];
}

void solve() {
    i64 l = read(), r = read(), k = read();
    if (k > 60) cout << r - l + 1 << '\n';
    else cout << go(r - l + 1, k) << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}