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
    int n = read();
    if (n % 2 == 0) { puts("-1"); return; }
    vector<int> a(n + 1);
    int mid = n / 2 + 1;
    a[mid] = 1;
    int x = 2;
    for (int L = mid, R = mid; L >= 1 and R <= n; ) {
        a[++R] = x++;
        a[--L] = x++;
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}