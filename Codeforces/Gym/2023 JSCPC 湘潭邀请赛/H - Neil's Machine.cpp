#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap;
using std::array;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n;
    cin >> n;

    vector<char> a(n + 1);
    vector<char> b(n + 1);

    vector<int> da(n + 1);
    vector<int> db(n + 1);

    for (int i = 1; i <= n; i++) {
        // a[i] = read();
        cin >> a[i];
        da[i] = (a[i] - a[i - 1] + 26) % 26;
    }

    for (int i = 1; i <= n; i++) {
        // b[i] = read();
        cin >> b[i];
        db[i] = (b[i] - b[i - 1] + 26) % 26;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (da[i] != db[i]) {
            ans++;
        }
    }

    cout << ans << "\n";
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}