#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
// using namespace std::views;
// using namespace std::ranges;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
using std::ostream;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    int n = read();
    int m = read();
    vector<int> a(n + 1);
    vector<int> b(m + 1);
    for (int i = 1; i <= n; i++) a[i] = read();
    std::sort(a.begin() + 2, a.end());
    for (int i = 1; i <= m; i++) b[i] = read();
    std::sort(b.begin() + 1, b.end());

    int cnt = 0;
    int le = 0, ri = -1;
    for (int i = 1; i <= m; i++) {
        if (b[i] <= a[1] or b[i] > a[n]) {
            cnt++;
        } else {
            if (le == 0) {
                le = i;
            }
            ri = i;
        }
    }

    vector<int> c(m + 1);
    for (int i = le; i <= ri; i++) {
        for (int L = 2, R = n; L <= R; ) {
            int mid = L + R >> 1;
            if (a[mid] >= b[i]) {
                c[i] = n - mid + 1;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
    }

    for (int k = 1; k <= m; k++) {
        int tot = m / k;
        int tcnt = cnt;

        int ans = 0;
        int l = le, r = ri;

        for (int i = 1; i <= tot; i++) {
            int need = k;
            int rk = 1;
            
            int tmp = min(tcnt, need);
            tcnt -= tmp, need -= tmp;

            tmp = min(need, r - l + 1);
            r -= tmp, need -= tmp;
            if (r + 1 <= m) rk = 1 + c[r + 1];
            ans += rk;
        }

        cout << ans << " \n"[k == m];
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
