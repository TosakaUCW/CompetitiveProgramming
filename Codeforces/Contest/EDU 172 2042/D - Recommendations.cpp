#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
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

struct Node {
    int l, r, id;
};

void solve() {
    int n = read();
    vector<Node> a(n + 1);
    for (int i = 1;  i <= n; i++) {
        a[i].l = read();
        a[i].r = read();
        a[i].id = i;
    }

    vector<int> ans(n + 1);
    std::set<int> s;

    std::sort(a.begin() + 1, a.end(), [&](auto a, auto b) {
        if (a.l == b.l) return a.r > b.r;
        return a.l < b.l;
    });
    for (int i = 1; i <= n; i++) {
        auto [l, r, id] = a[i];
        if (i + 1 <= n and a[i + 1].l == l and a[i + 1].r == r) {

        } else {
            auto it = s.lower_bound(r);
            if (it != s.end()) {
                ans[id] += *it - r;
            }
        }
        s.ep(r);
    }

    s.clear();

    std::sort(a.begin() + 1, a.end(), [&](auto a, auto b) {
        if (a.r == b.r) return a.l < b.l;
        return a.r > b.r;
    });
    for (int i = 1; i <= n; i++) {
        auto [l, r, id] = a[i];

        if (i + 1 <= n and a[i + 1].l == l and a[i + 1].r == r) {

        } else {
            auto it = s.upper_bound(l);
            if (it != s.begin()) {
                it--;
                ans[id] += l - *it;
            }
        }
        s.ep(l);
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}