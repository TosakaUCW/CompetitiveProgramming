#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
#define pb push_back
using std::max, std::min;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read();
    int f = 0;
    vector<int> a(n + 1), vis(n + 2);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        vis[a[i]]++;
        f |= vis[a[i]] == 2;
    }
    for (int i = 1; i <= n; i++) read();
    puts(f ? "shuishui" : "sha7dow");
}

signed main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}