#include <bits/stdc++.h>
using i64 = long long;
#define int i64
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
using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    int n = read();
    
    string s;
    cin >> s;

    std::map<char, int> mp;
    for (auto ch : s) {
        mp[ch]++;
    }

    char mx = s[0];
    for (auto ch : s) {
        if (mp[ch] > mp[mx]) {
            mx = ch;
        }
    }
    char mn = s[0];
    for (auto ch : s) {
        if (mp[ch] < mp[mn] or mn == mx) {
            mn = ch;
        }
    }

    for (auto &ch : s) {
        if (ch == mn and ch != mx) {
            ch = mx;
            break;
        }
    }

    cout << s << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}