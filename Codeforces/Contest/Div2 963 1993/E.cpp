#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::max, std::min;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}


void solve() {

    int n, m;
    std::cin >> n >> m;
    
    vector a(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
            a[i][m] ^= a[i][j];
            a[n][j] ^= a[i][j];
            a[n][m] ^= a[i][j];
        }
    }
    n++, m++;

    int ans = 1e9;

    vector cost(n, vector<int>(m));
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}