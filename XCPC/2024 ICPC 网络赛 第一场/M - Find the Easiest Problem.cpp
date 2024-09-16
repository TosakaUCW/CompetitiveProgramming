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
    std::set<std::string> st[26];
    for (int i = 1; i <= n; i++) {
        std::string s, sta;
        char t;
        cin >> s >> t >> sta;
        bool f = (sta == "accepted");
        if (f == 0) continue;
        st[t - 'A'].insert(s);
    }

    int res = 0;
    for (int i = 0; i < 26; i++) {
        if (st[i].size() > st[res].size()) res = i;
    }

    cout << char(res + 'A') << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}