#include <bits/stdc++.h>
using i64 = long long;
#define int i64
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
    int n = read();

    vector<int> d(n + 1);
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        u--, v--;
        d[u]++, d[v]++;
    }

    string s; cin >> s;

    int cntq = 0;
    vector<int> cnt(2);
    for (int i = 1; i < n; i++) {

        if (d[i] > 1) continue;
        if (s[i] == '?') cntq++;
        else cnt[s[i] - '0']++;
    }

    int ans = -1;
    if (s[0] != '?') {
        ans = cnt[(s[0] - '0') ^ 1] + (cntq + 1) / 2;
    } else {
        ans = max(cnt[0], cnt[1]) + cntq / 2;
        if ((std::count(s.begin(), s.end(), '?') - cntq) % 2 == 0 and cnt[0] == cnt[1]) {
            ans = max(ans, cnt[0] + (cntq + 1) / 2);
        }
    }
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}