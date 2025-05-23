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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }

    int ans = 0;
    int now = 0;
    int need = 1;

    for (int i = 1; i <= n; i++) {
        now += a[i];
        while (now > need * need) need += 2;

        if (now == need * need) {
            need += 2;
            ans++;
        }
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}