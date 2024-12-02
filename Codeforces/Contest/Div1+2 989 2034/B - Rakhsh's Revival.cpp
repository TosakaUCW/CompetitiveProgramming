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
    int m = read();
    int k = read();

    string s;
    cin >> s;

    int ans = 0;

    for (int i = 0; i < n; ) {
        if (s[i] == '1') { i++; continue; }
        int j = i;
        int cnt = 0;
        while (s[j] == '0' and j < n) {
            cnt++;
            if (cnt == m) {
                cnt = 0;
                j += k;
                ans++;
                break;
            }
            j++;
        }
        i = (j == i) ? i + 1 : j;

        // cout << i << '\n';
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}