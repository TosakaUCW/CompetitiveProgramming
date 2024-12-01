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

void solve() {
    int n = read();
    int m = read();

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    vector<int> b(m + 1);
    for (int i = 1; i <= m; i++) {
        b[i] = read();
    }

    using pii = std::pair<int, int>;
    #define fi first
    #define se second
    std::priority_queue<pii> q;
    for (int i = 1; i <= m; i++) {
        q.ep(b[i], i);
    }

    vector<int> c(m + 1, -1);
    // cout << q.size() << '\n';

    for (int i = 1; i <= n; i++) {
        while (!q.empty() and q.top().fi >= a[i]) {
            // cout << q.top().fi << " " << q.top().se << '\n';
            c[q.top().se] = i;
            // q.pop();
            q.pop();
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << c[i] << '\n';
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}