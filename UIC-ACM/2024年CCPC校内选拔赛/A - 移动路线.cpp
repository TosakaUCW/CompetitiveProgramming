#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
i64 read(i64 x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

struct Point {
    double x, y;
};

void solve() {
    string s; cin >> s;

    vector<Point> p;

    double x = 0, y = 0;
    for (auto ch : s) {
        if (ch == 'E') x++;
        if (ch == 'W') x--;
        if (ch == 'N') y++;
        if (ch == 'S') y--;
        p.push_back({x, y});
    }
    p.push_back({0, 0});
    int n = s.size();

    auto go = [&]() {
        if (n < 3) return 0.0;
        double s = p[0].y * (p[n - 1].x - p[1].x);
        p[n] = p[0];
        for(int i = 1; i < n; ++ i)
            s += p[i].y * (p[i - 1].x - p[i + 1].x);
        return s * 0.5;
    };

    puts(go() > 0 ? "CCW" : "CW");
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}