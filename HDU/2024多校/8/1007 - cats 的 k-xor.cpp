#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::max, std::min;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    i64 a = read(), b = read(), c = read();

    if (a + b == c) {
        cout << "-1\n";
        return;
    }

    i64 ans = 0;
    i64 d = abs(a + b - c);

    for (i64 k = 1; k * k <= d; k++) {

        auto check = [&](int k) {
            if (k == 1) return;

            i64 ia = a, ib = b, ic = c;
            bool flag = 1;
            while (ia or ib or ic) {
                i64 ta = ia % k;
                i64 tb = ib % k;
                i64 tc = ic % k;
                ia /= k, ib /= k, ic /= k;
                if (tc != (ta + tb) % k) {
                    flag = 0;
                    break;
                }
            }
            if (flag) ans++;
        };

        check(k);
        if (k != d / k) check(d / k);
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}