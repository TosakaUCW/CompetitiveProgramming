#include <bits/stdc++.h>
using i64 = long long;
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
    int n = read();
    int m = read();
    int q = read();

    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
        }
    }

    vector b(q, vector(n, vector<int>(m)));
    for (int k = 0; k < q; k++) {
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                b[k][i][j] = s[j] - '0';
            }
        } 
    }

    // for (int x = 0; x < n; x++) {
    //     for (int y = 0; y < m; y++) {
    //         cout << a[x][y] << " \n"[y == m - 1];
    //     }
    // }

    int ans = 1e9;
    int sta = -1;

    for (int s = 0; s < (1 << q); s++) {
        auto mp = a;
        bool f = 1;
        int res = 0;

        for (int i = 0; i < q; i++) {
            if (s >> i & 1) {
                res++;
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        if (b[i][x][y] == 0) continue;

                        if (mp[x][y] == 1) {
                            f = 0;
                            break;
                        }
                        if (mp[x][y] == 0) {
                            mp[x][y] = 2;
                        }
                    }
                }
            }
        }

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (mp[x][y] == 0) {
                    f = 0;
                    break;
                }
            }
        }

        if (f) {
            if (res < ans) {
                ans = res;
                sta = s;

            }
        }
    }

    if (sta == -1) {
        puts("-1");
        return;
    }

    cout << ans << "\n";
    for (int i = 0; i < q; i++) {
        if (sta >> i & 1) {
            cout << (i + 1) << " \n"[i == q - 1];
        }
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}