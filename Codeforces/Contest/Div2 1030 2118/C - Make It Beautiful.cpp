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
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int n = read();
    u64 k = read();

    vector<u64> a(n);
    for (auto &x : a) x = read();

    u64 ans = 0;
    for (auto x : a) ans += __builtin_popcountll(x);

    using Node = pair<u64,int>;
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    for (int i = 0; i < n; ++i) {
        int t = __builtin_ctzll(~a[i]);
        u64 cost = (t >= 63 ? k + 1 : (1ULL << t));
        pq.ep(cost, i);
    }

    while (!pq.empty() and pq.top().first <= k) {
        auto [cost, i] = pq.top(); pq.pop();
        k -= cost;
        ans += 1;
        a[i] += cost;

        int t = __builtin_ctzll(~a[i]);
        u64 ncost = (t >= 63 ? k + 1 : (1ULL << t));
        pq.ep(ncost, i);
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}