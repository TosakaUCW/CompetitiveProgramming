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
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }

    std::multiset<pii> s;
    for (int i = 1; i <= n; i++) {
        s.ep(a[i], i);
    }

    vector<int> ans;
    std::priority_queue<int> q;

    ans.eb(0);
    int now = 0;
    while (!s.empty()) {
        auto it = s.begin();
        int val = it->fi;
        int pos = it->se;

        if (pos <= now or (!q.empty() and val > -q.top())) {
            q.ep(-(val + 1));
        } else {
            now = pos;
            ans.pb(val);
        }
        
        s.erase(it);
    }

    while (!q.empty()) {
        int x = -q.top();
        q.pop();

        ans.eb(x);
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }

}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}