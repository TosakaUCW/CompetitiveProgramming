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

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (l + r >> 1)

void solve() {
    int n = read();
    int k = read();
    int all = 1 << n;
    vector<int> a(all + 1);
    for (int i = 1; i <= all; i++) a[i] = read();
    vector<int> pos(all + 1);
    for (int i = 1; i <= all; i++) pos[a[i]] = i;

    vector<int> sum(all << 2), ans(all + 1);
    

    for (int i = 1; i <= all; i++) {
        int x = pos[i];
        vector<int> v;

        auto get = [&](this auto&& get, int p, int l, int r) -> void {
            ++sum[p];
            v.eb(sum[p]);

            if (l == r) return;
            if (x <= mid) get(ls, l, mid);
            else get(rs, mid + 1, r);
        };
        get(1, 1, all);

        ranges::reverse(v);

        int res = n;
        for (int j = 0; j < v.size(); j++) {
            int t = 1 << j;
            if (t <= i and t - v[j] <= k) continue;
            res = j - 1;
            break;
        }
        ans[x] = res;
    }
    
    for (int i = 1; i <= all; i++) {
        cout << ans[i] << " \n"[i == all];
    }
}

signed main() {
    solve();
    return 0;
}