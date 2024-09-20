#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
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
    auto dis = [&](double x1, double y1, double x2, double y2){
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); 
    };
    
    double xa = read(), ya = read();
    double xb = read(), yb = read();
    double xc = read(), yc = read();
    double xd = read(), yd = read();

    double r2 = dis(xc, yc, xd, yd) / 2;
    double x1 = (xa + xb) / 2, y1 = (ya + yb) / 2;
    double x2 = (xc + xd) / 2, y2 = (yc + yd) / 2;
    double ans = fabs(x1 - x2) + fabs(y1 - y2) - r2 * sqrt(2);
    printf("%.10lf\n",ans);
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}