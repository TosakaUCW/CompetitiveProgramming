#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read();

    string s; cin >> s;

    vector<int> cnt(26);
    for (auto c : s) cnt[c - 'a']++;

    std::priority_queue<std::pair<int, int>> q;

    for (int i = 0; i < 26; i++) {
        if (!cnt[i]) continue;
        q.push({cnt[i], i});
    } 

    string ans;

    while (!q.empty()) {
        auto [x, i] = q.top();
        q.pop();
        ans.pb('a' + i);

        if (!q.empty()) {
            auto [y, j] = q.top();
            q.pop();
            ans.pb('a' + j);

            y--;
            if (y) q.push({y, j});
        }

        x--;
        if (x) q.push({x, i});
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}