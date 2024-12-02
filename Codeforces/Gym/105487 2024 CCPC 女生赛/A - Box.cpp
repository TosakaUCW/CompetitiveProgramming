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
    int z0 = read();
    int h = read();
    int u0 = read();
    int v0 = read();
    int u1 = read();
    int v1 = read();

    // u0 v0 z0
    // u1 v1 z0
    // u0 v1 z0
    // u1 v0 z0
    if (u0 > u1) {
        swap(u0, u1);
    }
    if (v0 > v1) {
        swap(v0, v1);
    }

    for (int q = read(); q--; ) {
        int x = read();
        int y = read();
        int z = read();

        if (x < u0 or x > u1 or y < v0 or y > v1 or z > z0 + h or z < z0) {
            puts("NO");
        } else {
            puts("YES");
        }
    }    
}    

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}