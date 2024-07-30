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
    int n = read(), k = read();
    i64 ans = 1;
    for (int i = 0; i < k; i++)
    {
        int res = 0;
        for (auto a : {0, 1}) {
            for (auto b : {0, 1}) {
                for (auto c : {0, 1}) {
                    for (auto d : {0, 1}) {
                        int x = ((a & b) ^ c) | d;
                        int y = n >> i & 1;
                        if (x == y) {
                            res++;
                        }
                    }
                }
            }
        }
        ans *= res;
    }
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}