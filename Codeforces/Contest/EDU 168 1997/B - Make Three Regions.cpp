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

    vector<string> s(2);
    cin >> s[0] >> s[1];

    int ans = 0;

    for (int k = 0; k < 2; k++) {
        for (int i = 1; i < n - 1; i++) {
            if (s[k][i] == '.' and s[k ^ 1][i] == '.'
                and s[k ^ 1][i - 1] == 'x' and s[k ^ 1][i + 1] == 'x'
                and s[k][i - 1] == '.' and s[k][i + 1] == '.') {
                ans++;
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}