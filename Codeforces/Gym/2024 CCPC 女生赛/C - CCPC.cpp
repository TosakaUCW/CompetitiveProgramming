#include <bits/stdc++.h>
// using i64 = long long;
// #define int i64
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
    string s;
    cin >> s;

    int a = 0, b = 0;
    for (auto ch : s) {
        if (ch == 'C') a++;
        if (ch == 'P') b++;
    }
    if (a < 3 or b < 1) {
        puts("0");
        return;
    }
    cout << min((a - 1) / 2, b) << '\n';
}    

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}