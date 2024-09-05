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
    int n = read(), c = read(), k = read();
    string s; cin >> s;

    std::vector<int> f(1 << c);

    vector<int> cnt(c);
    for (int i = 0; i < k; i++) {
        cnt[s[i] - 'A']++;
    }

    for (int l = 0, r = k - 1; r < n; l++, r++) {

        int j = 0;
        for (int i = 0; i < c; i++) {
            if (cnt[i]) {
                j |= (1 << i);
            }
        }
        f[j] = 1;

        if (r + 1 < n) {
            --cnt[s[l] - 'A'], ++ cnt[s[r + 1] - 'A'];
        }
    }

    f[1 << (s.back() - 'A')] = 1;

    int ans = c;
    for (int i = 0; i < (1 << c); i++) {
        int cnt = 0;
        for (int j = 0; j < c; j++) {
            if (i >> j & 1) {
                f[i] |= f[i ^ (1 << j)];
            } else {
                cnt++;
            }
        }

        if (!f[i]) {
            ans = min(ans, cnt);
        }
    }

    cout << ans << '\n';

}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}