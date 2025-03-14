#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
using tup = std::tuple<int, int, int>;
#define fi first
#define se second

int get1(int x, int y, int m = 0) {
    if (y % 2 == 0 and x % 2 == (y / 2) % 2) return 0;
    return 1;
}

int get2(int x, int y, int m = 0) {
    if ((x + 2 * y) % 4 == 0) return 0;
    return 1;
}

int getmex(const vector<int>& a) {
    std::unordered_set<int> s(a.begin(), a.end());
    int mex = 0;
    while (s.find(mex) != s.end()) {
        mex++;
    }
    return mex;
}

map<tup, int> mp;
int dfs(int x, int y, int m = 0) {
    if (x == 0 and y == 0 and m == 0) return 0;
    if (mp.count({x, y, m})) {
        return mp[{x, y, m}];
    }

    vector<int> s;
    const int dx[] = {+0, +0, +0, -1, -1, -1, -2, +1, +0, +1};
    const int dy[] = {-1, -2, -3, +1, -0, -1, +1, +0, +1, +1};
    for (int i = 0; i < 7; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nm = m;
        if (i > 6) nm--;
        if (nx < 0 or ny < 0 or nm < 0) continue;
        s.eb(dfs(nx, ny, nm));
    }

    mp[{x, y, m}] = getmex(s);
    return mp[{x, y, m}];
}

void solve() {
    int r, b, m;
    cin >> r >> b >> m；
    cout << (getwin(r, b, m) == 0 ? "Bob" : "Alice") << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    // int T; cin >> T;
    int T = 1;
    for (; T--; solve());
    // solve();
    return 0;
}
