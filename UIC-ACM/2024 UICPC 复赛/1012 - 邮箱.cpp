#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int inf = 1e9;

void solve() {
    string s;
    cin >> s;
    bool f = 0;
    for (auto ch : s) {
        if (ch == '(') {
            f = 1;
        }
        if (ch == ')') {
            f = 0;
            cout << '@';
            continue;
        }

        if (f) continue;

        cout << ch;
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}