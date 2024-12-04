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

    string s;
    cin >> s;
    // s = " " + s;

    int now = 0;
    vector<int> sum;    

    for (int i = n - 1; i >= 0; i--) {
        sum.eb(now);
        if (s[i] == '1') now++;
        else now--;
    }

    // reverse(sum.begin(), sum.end());
    std::sort(sum.rbegin(), sum.rend());

    int ans = -1;

    int tot = 0;

    for (int i = 2; i <= n; i++) {
        if (i - 2 >= sum.size()) continue;

        tot += sum[i - 2];

        if (tot >= k) {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}