#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read();
    string s;
    cin >> s;

    int ans = 0;
    char now = '0';
    for (auto ch : s) {
        if (ch != now) {
            ans++;
            now = ch;
        }
    }


    cout << ans << '\n';

    // vector<int> a(n);
    // for (auto &x : a) x = read();


}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
