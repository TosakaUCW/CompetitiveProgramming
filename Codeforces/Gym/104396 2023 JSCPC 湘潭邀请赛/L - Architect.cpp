#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
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
    int W = read(), H = read(), L = read();

    int n = read();
    vector<std::array<int, 6>> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            a[i][j] = read();
        }
    }

    i128 V = (i128)W * H * L;
    for (auto c : a) {
        i128 v = (i128)(c[3] - c[0]) * (c[4] - c[1]) * (c[5] - c[2]);
        V -= v;
    }

    if (V) {
        puts("No");
        return;
    }

    std::map<std::array<int, 3>, int> f;

    a.push_back({0, 0, 0, W, H, L});

    for (auto c : a) {
        for (int x : {c[0], c[3]}) {
            for (int y : {c[1], c[4]}) {
                for (int z : {c[2], c[5]}) {
                    ++f[{x, y, z}];
                }
            }
        }
    }

    for (auto [x, y] : f) {
        if (y & 1) {
            puts("No");
            return;
        }
    }

    puts("Yes");
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}