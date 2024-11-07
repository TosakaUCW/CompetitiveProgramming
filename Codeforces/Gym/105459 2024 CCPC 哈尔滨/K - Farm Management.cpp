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

struct Node {
    int w, l, r;
    friend bool operator < (Node a, Node b) {
        if (a.w != b.w) return a.w > b.w;
        if (a.l != b.l) return a.l < b.l;
        return a.r > b.r;
    }
};

void solve() {
    int n = read(), m = read();

    vector<Node> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i].w = read();
        a[i].l = read();
        a[i].r = read();
    }

    std::sort(a.begin() + 1, a.end());

    int ans = 0;

    int tim = 0;
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        tim += a[i].l;
        tot += a[i].l * a[i].w;
    }

    vector<int> sum(n + 1);
    vector<int> sumw(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i].r - a[i].l;
        sumw[i] = sumw[i - 1] + (a[i].r - a[i].l) * a[i].w;
    }

    for (int i = 1; i <= n; i++) {
        int res = tot - a[i].l * a[i].w;

        int rem = max(0LL, m - tim + a[i].l);

        int pos = 0;
        for (int l = 1, r = i - 1; l <= r; ) {
            int mid = l + r >> 1;
            if (sum[mid] <= rem) {
                pos = mid, l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        // cout << pos << " ";
        // cout << rem << " ";
        // cout << res << " ";
        // cout << " | ";

        res += sumw[pos];
        rem -= sum[pos];
        pos++;
        res += rem * a[pos].w;

        // cout << i << " ";
        // cout << pos << " ";
        // cout << rem << " ";
        // cout << res << " ";
        // cout << '\n';

        ans = max(ans, res);
    }

    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}