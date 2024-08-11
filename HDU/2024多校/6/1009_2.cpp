#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
#define eb emplace_back
using std::cin, std::cout, std::string, std::vector, std::cerr;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const i64 INF = 2.1e9;

struct event {
    i64 t, type, x, y;
};

void solve() {
    int n = read(), m = read();
    std::vector<event> q;
    for (int i = 1; i <= n; i++) {
        int t = read(), l = read(), r = read();
        q.eb(t, 1, l, r);
    }
    for (int i = 1; i <= m; i++) {
        int t = read();
        q.eb(t, 0);
    }
    std::sort(q.begin(), q.end(), [](event a, event b) { return a.t == b.t ? a.type < b.type : a.t < b.t; });

    using pii = std::pair<int, int>;
    #define fi first
    #define se second

    auto cmp1 = [](pii a, pii b) { return a.se < b.se; };
    auto cmp2 = [](pii a, pii b) { return a.se - a.fi != b.se - b.fi ? a.se - a.fi < b.se - b.fi : a.se < b.se; };
    std::multiset<pii, decltype(cmp1)> st1(cmp1);
    std::multiset<pii, decltype(cmp2)> st2(cmp2);

    int D = 0;
    i64 sc = 2 * INF;
    st1.emplace(1, INF);
    st1.emplace(-INF, -1);
    st2.emplace(1, INF);
    st2.emplace(-INF, -1);

    auto Run = [&](int dt) {
        D += dt;
        sc -= dt * 2 * st1.size();

        auto over = [&](auto x) -> bool {
            return x->se - x->fi + 1 <= 2 * D;
        };

        while (!st2.empty() and over(st2.begin())) {
            auto [l, r] = *st2.begin();
            sc -= r - l + 1 - 2 * D;
            st2.erase(st2.begin());
            st1.erase(st1.find({l, r}));
        }
    };

    for (auto [t, ty, x, y] : q) {
        Run(t - D);

        if (ty) exseg(x, y);
        else {
            auto k = prev(st1.end());
            i64 c = prev(st1.end())->se - st1.begin()->fi + 1 - 2 * D;
            cout << c - sc << " ";
        }
    }
}

/*
*/

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}