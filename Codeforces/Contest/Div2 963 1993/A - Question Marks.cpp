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

    string s; 
    cin >> s;

    std::sort(s.begin(), s.end());

    int tot = 0;

    vector<int> cnt(4);

    for (int i = 0; i < 4 * n; i++) {
        if (s[i] == '?') tot++;
        else cnt[s[i] - 'A']++;
    }

    int ans = 0;

    for (int i = 0; i < 4; i++) {
        cnt[i] = std::min(cnt[i], n);
        ans += cnt[i];
    }

    cout << ans << '\n';

}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}