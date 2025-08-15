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

struct Point { int x, y; };
struct Node { Point p; bool f; };
Point operator-(const Point& a, const Point& b) {
    return {a.x - b.x, a.y - b.y};
}
int sign(int val) {
    if (val > 0) return 1; // left
    if (val < 0) return -1; // right
    return 0;
}
i128 cross(auto a, auto b) {
    return (i128)a.x * b.y - (i128)a.y * b.x;
}

void solve() {
    int n = read();
    vector<Point> p(n);
    for (auto &[x, y] : p) x = read(), y = read();

    vector<Point> a;
    for (int i = 0; i < n; i++) {
        auto pre = p[(i + n - 1) % n];
        auto cur = p[i];
        auto nex = p[(i + 1) % n];
        if (cross(cur - pre, nex - cur) != 0) {
            a.eb(cur);
        }
    }

    int k = a.size();

    i128 sum = 0;
    for (int i = 0; i < k; i++) {
        auto p1 = a[i];
        auto p2 = a[(i + 1) % k];
        sum += cross(p1, p2);
    }

    vector<Node> ans;
    for (int i = 0; i < k; i++) {
        auto pre = a[(i + k - 1) % k];
        auto cur = a[i];
        auto nex = a[(i + 1) % k];
        int sig = cross(cur - pre, nex - cur);
        
        bool f;
        if (sum > 0) {
            f = (sig > 0);
        } else {
            f = (sig < 0);
        }
        
        ans.eb(cur, f);
    }
    
    ranges::sort(ans, [](auto a, auto b) {
        if (a.p.x != b.p.x) return a.p.x < b.p.x;
        return a.p.y < b.p.y;
    });
    cout << k << "\n";
    for (const auto& [p, f] : ans) {
        auto [x, y] = p;
        cout << x << " " << y << " " << (f ? "YES" : "NO") << "\n";
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}