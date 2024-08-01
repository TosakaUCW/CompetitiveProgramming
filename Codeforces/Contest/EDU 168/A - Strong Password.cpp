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
    string s;
    cin >> s;

    int n = s.size();
    bool f = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 and s[i] == s[i - 1]) {
            cout << s.substr(0, i);

            char ch = s[i] + 1;
            if (ch == 'z' + 1) ch = 'a';
            cout << ch;
            
            cout << s.substr(i, n) << '\n';

            return;
        }
    }

    char ch = s[0] + 1;
    if (ch == 'z' + 1) ch = 'a';
    cout << ch << s << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}