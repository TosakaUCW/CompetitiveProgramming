#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

struct node {
    int dis, v, u;
    bool friend operator < (node a, node b) {
        return a.dis > b.dis;
    };
};

void solve() {
    int n = read(), k = read();
    vector<int> a(n);
    multiset<int> s;
    for (auto &x : a) {
        x = read() % k;
        s.ep(x);
    }

    priority_queue<node> q;

    auto x = *s.begin();
    s.erase(s.begin());

    auto get = [&](int x) -> int {
        auto it = s.lower_bound(k - x);
        return *(it == s.end() ? s.begin() : it);
    };

    auto y = get(x);
    q.ep((x + y) % k, y, x);

    int ans = 0;
    while (!s.empty()) {
        int y;
        auto [w, x, p] = q.top(); q.pop();

        if (!s.contains(x)) continue;

        s.extract(x);
        ans += w;

        y = get(p);
        q.ep((p + y) % k, y, p);

        y = get(x);
        q.ep((x + y) % k, y, x);
    }

    cout << ans << "\n";
}

signed main() {
    for (int T = read(); T--; solve());
    return 0;
}