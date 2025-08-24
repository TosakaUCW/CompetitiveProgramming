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

void solve() {
    int X = read();
    int Y = read();
    int P = read();
    int Q = read();

    vector dp(X + 1, vector(Y + 1, vector(2, -1)));
    dp[X][Y][0] = 0;

    queue<tuple<int, int, int>> q;
    q.emplace(X, Y, 0);

    while (!q.empty()) {
        auto [x, y, pos] = q.front();
        q.pop();

        if (x == 0) {
            cout << dp[x][y][pos] << '\n';
            return;
        }

        int npos = pos ^ 1;

        if (pos == 0) {
            for (int i = 0; i <= min(P, x); i++) {
                for (int j = 0; j <= min(P - i, y); j++) {
                    int nx = x - i;
                    int ny = y - j;
                    if (nx > 0 and ny > nx + Q) continue;
                    if (dp[nx][ny][npos] != -1) continue;

                    dp[nx][ny][npos] = dp[x][y][pos] + 1;
                    q.emplace(nx, ny, npos);
                }
            }
        } else {
            for (int i = 0; i <= min(P, X - x); i++) {
                for (int j = 0; j <= min(P - i, Y - y); j++) {
                    int nx = x + i;
                    int ny = y + j;
                    if (X - x - i > 0 and Y - y - j > X - x - i + Q) continue;
                    if (dp[nx][ny][npos] != -1) continue;

                    dp[nx][ny][npos] = dp[x][y][pos] + 1;
                    q.emplace(nx, ny, npos);
                }
            }
        }
    }
    
    cout << -1 << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}