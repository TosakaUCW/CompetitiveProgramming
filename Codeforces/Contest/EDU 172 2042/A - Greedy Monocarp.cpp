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
using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    int n = read();
    int k = read();

    int tot = 0;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
    }

    if (sum < k) {
        cout << k - sum << '\n';
        return;
    }

    std::sort(a.begin() + 1, a.end());

    int i;

    for (i = n; i >= 1; i--) {
        if (tot + a[i] <= k) {
            tot += a[i];
        } else {
            break;
        }
    }

    cout << k - tot << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}