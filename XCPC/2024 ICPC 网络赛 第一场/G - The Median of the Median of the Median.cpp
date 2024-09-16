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

void solve() {
    int n = read();

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();

    vector<vector<int>> b(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        std::priority_queue<int> G, L;
        for (int j = i; j <= n; j++) {
            
            if (G.empty() or a[j] <= G.top()) {
                G.push(a[j]);
            } else {
                L.push(-a[j]);
            }

            if (G.size() > (j - i + 2) / 2) {
                L.push(-G.top());
                G.pop();
            } else if (G.size() < (j - i + 2) / 2) {
                G.push(-L.top());
                L.pop();
            }

            b[i][j] = G.top();
        }
    }

    auto judge = [&](int lim) {
        vector<vector<int>> c(n + 2, vector<int>(n + 2));

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                int k = 1;
                if (b[i][j] < lim) k = -1;

                c[1][j] += k;
                c[i + 1][j] -= k;
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                c[i][j] += c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];

                if (i > j) continue;

                if (c[i][j] >= 1) res++;
                else res--;
            }
        }
        return res >= 1;
    };

    int res = 0;
    for (int L = 1, R = 1e9; L <= R; ) {
        int mid = L + R >> 1;
        if (judge(mid)) res = mid, L = mid + 1;
        else R = mid - 1;
    }
    cout << res;
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}