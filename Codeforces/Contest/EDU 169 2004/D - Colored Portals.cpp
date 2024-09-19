#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const std::string color = "BGRY";

int id(int x, int y) {
    if (x > y) swap(x, y);
    return y * (y - 1) / 2 + x;
}

void solve() {
    int n = read(), q = read();
    
    vector<std::array<int, 2>> c(n + 2);
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        
        for (int j = 0; j < 2; j++) {
            c[i][j] = color.find(s[j]);
        }
    }

    vector<std::array<int, 6>> pre(n + 1), nxt(n + 1);

    for (int i = 1; i <= n; i++) {
        if (i == 1) pre[i].fill(0);
        else pre[i] = pre[i - 1];
        pre[i][id(c[i][0], c[i][1])] = i;
    }
    for (int i = n; i >= 1; i--) {
        if (i == n) nxt[i].fill(n + 1);
        else nxt[i] = nxt[i + 1];
        nxt[i][id(c[i][0], c[i][1])] = i;
    }

    for (int i = 0; i < q; i++) {
        int x = read(), y = read();
        int ans = 1e9;
        if (x > y) swap(x, y);
        for (auto a : c[x]) {
            for (auto b : c[y]) {
                if (a == b) ans = y - x;
                else {
                    int w = id(a, b);
                    for (auto z : {nxt[x][w], pre[y][w]}) {
                        if (1 <= z and z <= n) {
                            ans = min(ans, abs(x - z) + abs(y - z));
                        }
                    }
                }
            }
        }

        cout << (ans == 1e9 ? -1 : ans) << "\n";
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}