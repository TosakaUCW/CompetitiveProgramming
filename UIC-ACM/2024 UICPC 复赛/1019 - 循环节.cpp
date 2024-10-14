#include <bits/stdc++.h>
using i64 = long long;
#define int i64
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

void solve() {
    int n = read();

    vector<int> nxt(n + 1);
    for (int i = 1; i <= n; i++) {
        nxt[i] = i - read();
    }

    vector<int> vis(26), a(n + 1);

    for (int i = 2; i <= n; i++) {
        int j = nxt[i - 1];
        while (j and j + 1 != nxt[i]) {
            vis[a[j + 1]] = i;
            j = nxt[j];
        }

        if (j + 1 == nxt[i]) {
            a[i] = a[j + 1];
        } else {
            vis[a[1]] = i;
            for (int k = 0; k < 26; k++) {
                if (vis[k] != i) {
                    a[i] = k;
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << char('a' + a[i]);
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}