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
    int n = read();
    int k = read();

    vector<int> a(n + 1);
    vector<int> b(65, -1);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        
    }

    int ans = 0;

    for (int t = 0; t <= k; t++) {
        bool f = 1;
        for (int i = 1; i < n; i++) {
            if ((a[i] ^ t) > (a[i + 1] ^ t)) {
                f = 0;
                break;
            }
        }

        if (f) {
            ans++;
        }
    }

    cout << ans << '\n';
}

/*
01000 = 2
01000 = 2
00100 = 4
00001 = 16

01101
01223

10001 = 17 = k

xxxx0 = 4
x0001 = 2
10001 = 1
*/

/*
11000 = 3
01000 = 2
10100 = 5
00001 = 16

11101
12334

10001 = 17 = k

xxxx0 = 2
x0001 = 1
10001 = 1
*/

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}