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
    int n = read();
    int k = read();

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }

    std::sort(a.begin() + 1, a.end());

    int cur = 0;
    int p = 0;

    for (int i = 1; i <= n; i++) {
        if (cur + (n - i + 1) * (a[i] - a[i - 1]) >= k) {
            p += k - cur;
            break;
        }
        p += (n - i + 1) * (a[i] - a[i - 1]) + 1;
        cur += (n - i + 1) * (a[i] - a[i - 1]);
    }

    cout << p << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}