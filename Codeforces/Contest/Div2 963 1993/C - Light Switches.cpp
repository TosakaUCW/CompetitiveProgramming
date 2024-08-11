#include <bits/stdc++.h>
using i64 = long long;
#define int long long

#define pb push_back
using std::max, std::min;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read(), k = read();
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();

    int t = *std::max_element(a.begin() + 1, a.end());

    for (int i = 1; i <= n; i++) {
        if ((t - a[i]) % (2 * k) >= k) {
            t += 2 * k - (t - a[i]) % (2 * k);
        }
    }

    for (int i = 1; i <= n; i++) {
        if ((t - a[i]) % (2 * k) >= k) {
            t = -1;
            break;
        }
    }

    cout << t << '\n';

}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}