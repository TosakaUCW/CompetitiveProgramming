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

    int n = s.size();
    for (int i = 0; i + 1 < n; i++) {
        if (i - 1 < 0 or i + 1 >= n) continue;
        if (s[i - 1] == '1' and s[i] == '1' and s[i + 1] == '1') 
            s[i] = '0';
    }
    double ans = 0;
    s += '0';
    int cnt = 0;
    for (int i = 0; i <= n; i++) {
        if (s[i] == '0') {
            ans += pow(cnt, 0.5);
            // cout << cnt << '\n';
            cnt = 0;
        } else {
            cnt++;
        }
    }
    printf("%.10f", ans);
}    

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}