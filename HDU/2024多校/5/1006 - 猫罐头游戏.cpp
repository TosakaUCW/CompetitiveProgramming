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
    vector<int> a(3);
    for (int i = 0; i < 3; i++) a[i] = read();
    while (a[0] % 2 == 0 and a[1] % 2 == 0 and a[2] % 2 == 0)
        a[0] /= 2, a[1] /= 2, a[2] /= 2;
    if (a[0] % 2 == 1 and a[1] % 2 == 1 and a[2] % 2 == 1)
        puts("NO");
    else 
        puts("YES");
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}