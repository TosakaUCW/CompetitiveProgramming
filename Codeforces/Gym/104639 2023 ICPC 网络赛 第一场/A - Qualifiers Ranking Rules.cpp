#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
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
    int n = read(), m = read();

    using pii = std::pair<int, string>;
    #define fi first
    #define se second

    std::map<string, bool> mp;
    vector<string> a, b;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (mp[s]) continue;
        mp[s] = 1;
        a.eb(s);
    }

    mp.clear();
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        if (mp[s]) continue;
        mp[s] = 1;
        b.eb(s);
    }

    n = a.size();
    m = b.size();
    vector<string> res(n + m);

    for (int i = 0, j = 0, cnt = 0; cnt < n + m; ) {
        if (i < n) res[cnt++] = a[i], i++;
        if (j < m) res[cnt++] = b[j], j++;
    }

    mp.clear();
    for (auto s : res) {
        if (mp[s]) continue;
        mp[s] = 1;
        cout << s << '\n';
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}