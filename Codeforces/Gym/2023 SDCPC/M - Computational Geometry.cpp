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
    int n = read(), k = read();

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        x[i] = read();
        y[i] = read();
    }

    auto area = [&](int a, int b, int c) {
        int x1 = x[b] - x[a];
        int y1 = y[b] - y[a];
        int x2 = x[c] - x[a];
        int y2 = y[c] - y[a];
        return x1 * y2 - x2 * y1;
    };

    int sum = 0;
    for (int i = 2; i <= k; i++) {
        sum += area(0, i - 1, i);
    }

    i64 ans = 0;

    for (int a = k + 1, b = 0; b < n; b++) {
        int c = (b + k) % n;
        int nb = (b + 1) % n;
        int nc = (c + 1) % n;

        int S = area(a, b, c);

        while (a != b) {
            int na = (a + 1) % n;
            if (na == b) break;
            int nS = area(na, b, c);
            if (nS < S) break;
            S = nS, a = na; 
        }

        ans = max(ans, S + sum);

        sum -= area(b, nb, c);
        sum += area(nb, c, nc);

        if (a == c) a = (a + 1) % n;
    }
    printf("%.12lf\n", ans / 2.0);
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}