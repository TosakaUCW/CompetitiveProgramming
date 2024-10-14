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
    
    std::map<int, int> cnt;

    for (auto ch : s) {
        if ('a' <= ch and ch <= 'z') {
            cnt[ch - 'a']++;
        }
        if ('A' <= ch and ch <= 'Z') {
            cnt[ch - 'A']++;
        }
    }

    for (int k = 256; k > 0; k--) {
        for (int x = 0; x < 26; x++) {
            if (cnt[x] == k) {
                cout << char(x + 'A') << ' ' << k << '\n';
            }
        }
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}