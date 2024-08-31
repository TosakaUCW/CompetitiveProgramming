#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read();
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = read();
    }

    std::sort(a.begin(), a.end());

    cout << a[n / 2] << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}