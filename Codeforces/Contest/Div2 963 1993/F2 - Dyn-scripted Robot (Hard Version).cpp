#include <bits/stdc++.h>
using i64 = long long;
#define int long long

#define pb push_back
using std::max, std::min;
using std::cin, std::cout, std::string, std::vector;
i64 read(i64 x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    i64 g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}
// ax + b = 0 (mod m)
std::pair<i64, i64> sol(i64 a, i64 b, i64 m) {
    assert(m > 0);
    b *= -1;
    i64 x, y;
    i64 g = exgcd(a, m, x, y);
    if (g < 0) {
        g *= -1;
        x *= -1;
        y *= -1;
    }
    if (b % g != 0) {
        return {-1, -1};
    }
    x = x * (b / g) % (m / g);
    if (x < 0) {
        x += m / g;
    }
    return {x, m / g};
}

void solve() {
    i64 n = read(), k = read();
    i64 w = read(), h = read();

    w <<= 1, h <<= 1;
    string s; cin >> s;

    vector<std::pair<i64, i64>> buk;
    i64 x = 0, y = 0;
    for (auto c : s) {
        if (c == 'U') y++;
        if (c == 'D') y--;
        if (c == 'L') x--;
        if (c == 'R') x++;
        x = (x + w) % w;
        y = (y + h) % h;
        buk.emplace_back(x, y);
    }
    auto [dx, dy] = buk.back();

    i64 ans = 0;

    for (auto [x, y] : buk) {
        /*
        x + t dx = 0 (mod 2w)
        y + t dy = 0 (mod 2h)
        t = a1 (mod m1)
        t = a2 (mod m2)

        t = k * m1 + a1 = a2 (mod m2)
        k * m1 + a1 - a2 = 0 (mod m2)
        */
        auto [a1, m1] = sol(dx, x, w);
        auto [a2, m2] = sol(dy, y, h);

        if (a1 == -1 or a2 == -1) continue;

        auto [X, m] = sol(m1, a1 - a2, m2);
        if (X == -1) continue;

        m *= m1;
        X = (X * m1 + a1) % m;
        if (k > X) {
            ans += (k - 1 - X) / m + 1;
        }
    }
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}