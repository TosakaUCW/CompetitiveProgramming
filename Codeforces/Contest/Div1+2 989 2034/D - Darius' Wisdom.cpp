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
    
    vector<int> a(n + 1);
    vector<int> cnt(3);

    std::set<int> s[3];

    for (int i = 1; i <= n; i++) {
        a[i] = read();
        s[a[i]].ep(i);
    }

    int p1 = s[0].size(), p2 = s[0].size() + s[1].size();

    vector<pii> ans;

    for (int i = n; i > p2; i--) {
        if (a[i] == 2) continue;
        if (a[i] == 0) {
            int j = *s[1].begin();

            ans.eb(i, j);
            swap(a[i], a[j]);

            s[0].erase(i);
            s[1].erase(j);
            s[0].ep(j);
            s[1].ep(i);
        }

        if (a[i] == 1) {
            int j = *s[2].begin();

            ans.eb(i, j);
            swap(a[i], a[j]);

            s[1].erase(i);
            s[2].erase(j);
            s[1].ep(j);
            s[2].ep(i);
        }
    }

    for (int i = p2; i > p1; i--) {
        if (a[i] == 1) continue;
        if (a[i] == 0) {
            int j = *s[1].begin();

            ans.eb(i, j);
            swap(a[i], a[j]);

            s[0].erase(i);
            s[1].erase(j);
            s[0].ep(j);
            s[1].ep(i);
        }
    }

    bool flag = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i + 1]) {
            flag = 0;
            break;
        }
    }

    assert(flag);
    assert(ans.size() <= n);


    // 1...cnt[0]
    // cnt[0]+1....cnt[0]+cnt[1]
    // cnt[0]+cnt[1]+1.....n

    // j = cnt[0] + 1;

    // puts("---------------");

    // for (int p = 1; p <= n; p++) {
    //     cout << a[p] << " \n"[p == n];
    // }

    cout << ans.size() << '\n';
    for (auto [i, j] : ans) {
        cout << i << " " << j << '\n';
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}