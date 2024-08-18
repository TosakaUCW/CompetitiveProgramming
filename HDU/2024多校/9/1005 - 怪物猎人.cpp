#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::max, std::min;
using std::cin, std::cout, std::string, std::vector;

void solve() {
    // i64 k = read(), x = read(), y = read();
    i64 k, x, y;
    cin >> k >> x >> y;
    
    i64 L = (k + x - 1) / x;
    i64 R = (k + y - 1) / y;

    if (L != R) {
        cout << "Yes\nYes\n";
    }
    else {
        if (L % 2 == 1) {
            cout << "Yes\nNo\n";
        }
        else {
            cout << "No\nYes\n";
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}