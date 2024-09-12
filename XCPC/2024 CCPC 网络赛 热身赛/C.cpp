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

    vector<vector<std::pair<int, int>>> mp(n + 1);
    vector<int> r(n + 1);

    for (int i = 1; i <= n; i++) {
        int l = read(), b = read();
        mp[b].pb({l, i});
    }

    #define fi first
    #define se second

    for (int i = 0; i <= n; i++) {
        int R = 1e6 + 1;
        std::sort(mp[i].begin(), mp[i].end());

        for (int j = 0; j + 1 < mp[i].size(); j++) {
            if (mp[i][j].fi == mp[i][j + 1].fi) { puts("-1"); return; }
        }

        for (int j = mp[i].size() - 1; j >= 0; j--) {
            auto [l, id] = mp[i][j];

            if (i) {
                auto it = std::upper_bound(mp[i - 1].begin(), mp[i - 1].end(), 
                    std::pair<int, int>(l, n));

                if (it == mp[i - 1].begin()) { puts("-1"); return; }
                it--;
                if (it -> fi == l) {
                    R = min(R, r[it -> se]);
                } else {
                    R = min(R, r[it -> se] + 1);
                }
            }

            r[id] = --R;

            if (l > r[id]) { puts("-1"); return; }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << r[i] << '\n';
    }

}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}