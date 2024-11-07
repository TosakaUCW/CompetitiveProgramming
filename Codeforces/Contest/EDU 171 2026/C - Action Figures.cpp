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

void solve() {
    int n = read();

    string s;
    cin >> s;

    s = '#' + s;
    int ans = 0;

    std::queue<int> q;
    for (int i = n; i >= 1; i--) {
        if (s[i] == '0') {
            ans += i;
            if (!q.empty()) {
                q.pop();
            }
        } else {
            q.ep(i);
        }
    }

    int m = q.size() / 2;
    while (m--) q.pop();

    while (!q.empty()) {
        ans += q.front();
        q.pop();
    }
 
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    return 0;
}