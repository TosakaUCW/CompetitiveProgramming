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

const int N = 50 + 5;

int n, k;
int a[N], vis[N], pos[N];
int dp[N][N][2];
// dp[i][j][t]:
//   已经处理完 1..i 这些数
//   j 表示数字 i 在「后缀」部分的相对位置（第 j 个，j = 0 表示已固定到前缀）
//   t = 0 表示 i - 1 在 i 的左侧, t = 1 表示 i - 1 在 i 的右侧

int calc(int lim) {
    memset(dp, 0, sizeof dp);
    int len = 0;

    bool in1 = vis[1], in2 = vis[2];
    if (in1 and in2) {
        dp[2][0][ pos[1] < pos[2] ? 0 : 1 ] = 1;
    } else if (in1 and !in2) {
        len = 1;
        dp[2][1][0] = 1;
    } else if (!in1 and in2) {
        len = 1;
        dp[2][0][1] = 1;
    } else {
        len = 2;
        dp[2][1][1] = 1;
        dp[2][2][0] = 1;
    }

    auto add = [&](int &x, int v) {
        x += v;
        if (x > lim) x = lim;
    };

    for (int i = 2; i < n; i++) {
        if (vis[i + 1]) {
            if (vis[i]) {
                int t = (pos[i] < pos[i + 1] ? 0 : 1);
                dp[i + 1][0][t] = dp[i][0][t ^ 1];
            } else {
                for (int j = 1; j <= len; j++) {
                    add(dp[i + 1][0][1], dp[i][j][0]);
                }
            }
            continue;
        }

        for (int j = 0; j <= len; j++) {
            for (int t = 0; t < 2; t++) {
                if (!dp[i][j][t]) continue;

                int st, ed;
                if (t == 0) {
                    st = 1;
                    ed = j;
                } else {
                    st = j + 1;
                    ed = len + 1;
                }
                for (int nj = st; nj <= ed; nj++) {
                    add(dp[i + 1][nj][t ^ 1], dp[i][j][t]);
                }
            }
        }
        len++;
    }

    int res = 0;
    if (vis[n]) {
        add(res, dp[n][0][0] + dp[n][0][1]);
    } else {
        for (int i = 1; i <= len; i++) {
            add(res, dp[n][i][0] + dp[n][i][1]);
        }
    }
    return res;
}


void solve() {
    n = read();
    k = read();

    for (int p = 1; p < n; p++) {
        for (int v = 1; v <= n; v++) {
            if (vis[v]) continue;

            vis[v] = 1, pos[v] = p;

            for (int i = 1; i <= n; i++) {
                if (vis[i]) continue;
                pos[i] = p + 1;
            }

            bool ok = 1;
            for (int i = 2; i < n; i++) {
                if ((pos[i] - pos[i - 1]) * (pos[i] - pos[i + 1]) < 0) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) { vis[v] = 0; continue; }

            int cnt = calc(k);
            if (cnt >= k) { a[p] = v; break; } 

            k -= cnt;
            vis[v] = 0;
        }

        if (!a[p]) { cout << "-1\n"; return; }
    }

    for (int i = 1; i <= n; i++) if (!vis[i]) a[n] = i;
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}