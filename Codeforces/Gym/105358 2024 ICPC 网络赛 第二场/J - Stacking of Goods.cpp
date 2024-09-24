#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap;
using std::cerr, std::cin, std::cout, std::string, std::vector;
int read(int x = 0, bool f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

struct Node {
    int w, v, c;
    bool friend operator < (Node a, Node b) {
        return a.w * b.c < b.w * a.c;
    }
};

void solve() {
    int n = read();

    vector<Node> a(n);
    for (int i = 0; i < n; i++) {
        a[i].w = read();
        a[i].v = read();
        a[i].c = read();
    }

    std::sort(a.begin(), a.end());

    i64 ans = 0;
    i64 sum = 0;
    for (int i = 0; i < n; i++) sum += a[i].w, ans += a[i].v;

    i64 tot = 0;
    for (int i = 0; i < n; i++) {
        ans -= a[i].c * sum;

        tot += a[i].w;
        ans += a[i].c * tot;
    }
    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}