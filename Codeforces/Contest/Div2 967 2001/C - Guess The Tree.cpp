#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap;
using std::cin, std::cout, std::string, std::vector;

void solve() {
    int n;
    cin >> n;

    auto query = [&](int x, int y) {
        cout << "? " << x << ' ' << y << std::endl;
        int res; cin >> res;
        return res;
    };
    
    vector<std::pair<int, int>> e;
    for (int i = 2; i <= n; i++) {
        int p = 1;
        int res = query(i, p);
        while (res != i) {
            p = res;
            res = query(i, p);
        }
        e.eb(i, p);
    }
    
    cout << "! ";
    for (auto [x, y] : e) {
        cout << x << ' ' << y << ' ';
    }
    cout << std::endl;
}

signed main() {
    int T; cin >> T;
    for ( ; T--; solve());
    // solve();
    return 0;
}