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

    vector<vector<int>> vec(n + 1);
    for (int i = 1; i <= n; i++) {
        int L = read(), R = read();
        vec[L].eb(R);
    }

    for (int i = 1; i <= n; i++) {
        auto &a = vec[i];
        if (a.empty()) { puts("0"); return; }
        std::sort(a.begin(), a.end());

        int siz = a.size();
        for (int j = 0; j + 1 < siz; j++) {
            if (a[j] == a[j + 1]) { puts("0"); return; }
            vec[a[j] + 1].eb(a[j + 1]);
        }
    }

    puts("1");
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}