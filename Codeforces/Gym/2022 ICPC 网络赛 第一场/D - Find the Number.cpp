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
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

int a[500], num = 0;
vector<int> ans;

void dfs(int p) {   
    // debug(p);
    if (p > 30) {
        if (num) return;

        int res = 0;
        for (int i = 1, bas = 1; i <= 30; i++, bas *= 2) {
            if (a[i]) res += bas;
        }
        ans.eb(res);
        return;
    }

    if (num) {
        num--;
        a[p] = 1, dfs(p + 1);
        num++;
    }

    a[p] = 0, dfs(p + 1);
}

void solve() {
    int L = read();
    int R = read();

    int x = ranges::lower_bound(ans, L) - ans.begin();

    if (x >= ans.size() or ans[x] > R) {
        cout << "-1\n";
        return;
    }

    cout << ans[x] << '\n';
}

signed main() {
    for (int i = 1; i <= 16; i++) {
        for (int j = 1; j <= i; j++) a[j] = 0;
        a[i + 1] = 1; num = i - 1;
        dfs(i + 2);
    }

    ranges::sort(ans);
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    // debug(ans.size());

    for (int T = read(); T--; solve());
    // solve();
    return 0;
}