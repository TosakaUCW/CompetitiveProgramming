#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap;
using std::array;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read(), m = read();

    string s;
    cin >> s;

    int p = 16;

    int len = s.size();
    while (len < 2 * m) {

        int m = len / 2;

        s = s.substr(0, m) + s + s.substr(m);
        len *= 2;

        for (int i = len - m; i < len; i++) {
            s[i] = s[i] == 'z' ? 'a' : s[i] + 1;
        }
        // cout << s << "\n";

        p = (p + 25) % 26;
    }

    s = s.substr(len - m);
    for (auto &ch : s) {
        int t = ch - 'a';
        t = (t + p) % 26;
        ch = 'a' + t;
    }

    cout << s;
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}