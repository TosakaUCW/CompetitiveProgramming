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
    int N = read(), m = read();

    vector<vector<int>> g(2 * N);
    vector<int> d(2 * N), w(2 * N), val(2 * N);


    int idx = 0, k = 0;
    std::map<int, int> mp;

    while (N--) {
        int n = read();
        std::set<int> st;

        for (int i = 0; i <= n + 3; i++) {
            st.emplace(i);
        }

        for (int i = 0; i < n; i++) {
            int x = read();
            st.erase(x);
        }
        k = max(k, *st.begin());

        int p1 = *st.begin(), p2 = *++st.begin();
        int x = 0, y = 0;

        if (mp.count(p1)) {
            x = mp[p1];
        } else {
            x = mp[p1] = idx++;
            val[x] = p1;
        }

        if (mp.count(p2)) {
            y = mp[p2];
        } else {
            y = mp[p2] = idx++;
            val[y] = p2;
        }

        g[y].eb(x), d[x]++;
    }

    std::queue<int> q;
    vector<int> vec;

    for (int i = 0; i < idx; i++) {
        if (!d[i]) {
            q.ep(i);
        }
        if (d[i] > 1) vec.eb(i);
    }

    while (!q.empty()) {
        int x = q.front(); q.pop();

        w[x] = max(w[x], val[x]);

        for (int y : g[x]) {
            w[y] = max(w[y], w[x]);
            if (!--d[y]) q.ep(y);
        }
    }

    for (int i : vec) k = max(k, w[i]);

    vector<int> id(idx);
    std::iota(id.begin(), id.end(), 0);
    std::sort(id.begin(), id.end(), [&](int i, int j) {
         return val[i] < val[j]; 
    });


    i64 ans = 0;
    int las = 0;

    auto sum = [&](int l, int r) {
        if (l > r) return 0LL;
        return 1LL * (l + r) * (r - l + 1) / 2;
    };

    for (int x : id) {
        if (val[x] > m) break;

        int l = las, r = val[x] - 1;

        ans += max(0LL, min(k, r) - l + 1) * k + sum(max(l, k + 1), r);
        ans += max(k, w[x]);

        las = val[x] + 1;
    }

    int l = las, r = m;
    ans += max(0LL, min(k, r) - l + 1) * k + sum(max(l, k + 1), r);

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}