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
    int n = read(), k = read();
    string s;
    cin >> s;

    s = " " + s + s;

    if (n <= 6) {
        puts("0");
        return;
    }

    int ans = 0;
    string t = "nanjing";

    vector<int> a(2 * n + 1);

    for (int i = 1; i <= 2 * n; i++) {
        bool f = 1;
        for (int j = i; j <= i + 6 and j <= 2 * n; j++) {
            if (s[j] != t[j - i]) {
                f = 0;
                break;
            }
        }

        if (f) {
            a[i]++;
        }
    }


    for (int i = 1; i <= 2 * n; i++) {
        a[i] += a[i - 1];
    }
    for (int i = 1; i + n - 1 - 6 <= n + min(n, k) - 6; i++) {
        ans = max(ans, a[i + n - 1 - 6] - a[i - 1]);
    }
    cout << ans << "\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}