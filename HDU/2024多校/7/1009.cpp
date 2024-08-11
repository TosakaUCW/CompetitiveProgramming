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
    int n = read(), k = read();

    vector<int> ind(n + 1), tim(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        int opt = read();
        if (opt == 0) {
            tim[i] = read();
        }
        else {
            int t = read();
            for (int j = 1; j <= t; j++) {
                g[read()].pb(i);
            }
        }
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}