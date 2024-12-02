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
using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    int n = read();
    int k = read();

    // n 0 k 1
    vector<vector<int>> ans;

    auto fill = [&](std::set<vector<int>> forbid) {
        vector<int> p(n), q(n);
        std::iota(p.begin(), p.end(), 1);

        while (ans.size() < k) {
            for (int i = 0; i < n; i++) {
                q[i] = n + 1 - p[i];
            }

            if (p >= q) {
                break;
            }

            if (forbid.contains(p) or forbid.contains(q)) {
                // continue;
            } else {
                ans.eb(p);
                ans.eb(q);
            }

            std::next_permutation(p.begin(), p.end());
        }
    };

    auto go = [&]() -> bool {
        if ((n + 1) % 2 and k % 2) {
            return 0;
        }
        if (n == 1) {
            if (k == 1) {
                ans.eb(vector<int>(1, 1));
                return 1;
            }
            return 0;
        }

        if (k % 2 == 0) {
            fill({});
            return ans.size() == k;
        }
        // k is odd
        if (k == 1) {
            return 0;
        }

        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
            b[i] = (i + n / 2) % n + 1;
            c[i] = (n + 1) * 3 / 2 - a[i] - b[i];
        }

        std::set<vector<int>> forbid;
        forbid.ep(a);
        forbid.ep(b);
        forbid.ep(c);       
        ans.eb(a);
        ans.eb(b);
        ans.eb(c);
        fill(forbid);
        return ans.size() == k;
    };

    if (go()) {
        cout << "YES\n";
        for (auto x : ans) {
            for (auto y : x) {
                cout << y << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "NO\n";
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}