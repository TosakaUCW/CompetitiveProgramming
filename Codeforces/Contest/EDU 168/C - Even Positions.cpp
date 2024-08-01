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
    string s; cin >> s;
    vector<int> stk;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (stk.empty()) {
                stk.pb(i);
            }
            else {
                ans += i - stk.back();
                stk.pop_back();
            }
        }
        else {
            if (s[i] == '(') {
                stk.pb(i);
            }
            else {
                ans += i - stk.back();
                stk.pop_back();
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