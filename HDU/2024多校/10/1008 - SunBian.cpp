#include <bits/stdc++.h>
using i64 = long long;
#define int long long
#define pb push_back
using std::max, std::min;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}


void solve() {
    int n = read(), k = read();

    if (k == 1) {
        cout << (n % 2 ? "A" : "B");
    } else if (k == n) {
        cout << "A";
    } else {
        cout << "B";
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}