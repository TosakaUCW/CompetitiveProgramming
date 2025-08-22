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

const int K = 2500;

void solve() {
    int n = read();
    int k = read();

    string s; cin >> s;

    vector dp(n + 1, vector(n + 1, vector(n + 1, bitset<K + 1>{})));

    for (int i = 0; i <= n; i++) {
        dp[0][0][i][0] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '?' or s[i] == 'N') {
            for (int N = 0; N <= i; N++) {
                for (int C = 0; C <= n - i; C++) {
                    dp[i + 1][N + 1][C] |= dp[i][N][C];
                }
            }
        }
        if (s[i] == '?' or s[i] == 'A') {
            for (int N = 0; N <= i; N++) {
                for (int C = 0; C <= n - i; C++) {
                    dp[i + 1][N][C] |= dp[i][N][C] << (N * C);
                }
            }
        }
        if (s[i] == '?' or s[i] == 'C') {
            for (int N = 0; N <= i; N++) {
                for (int C = 1; C <= n - i; C++) {
                    dp[i + 1][N][C - 1] |= dp[i][N][C];
                }
            }
        }
        if (s[i] == '?' or (s[i] != 'N' and s[i] != 'A' and s[i] != 'C')) {
            for (int N = 0; N <= i; N++) {
                for (int C = 0; C <= n - i; C++) {
                    dp[i + 1][N][C] |= dp[i][N][C];
                }
            }
        }
    }


    int N = -1;
    for (int i = 0; i <= n; i++) {
        if (dp[n][i][0][k]) {
            N = i;
        }
    }

    if (N == -1) { cout << "-1\n"; return; }

    int C = 0;
    for (int i = n - 1; i >= 0; i--) {
        if ((s[i] == '?' or s[i] == 'N') and N > 0 and dp[i][N - 1][C][k]) {
            s[i] = 'N';
            N--;
        } else if ((s[i] == '?' or s[i] == 'A') and k >= N * C and dp[i][N][C][k - N * C]) {
            s[i] = 'A';
            k -= N * C; 
        } else if ((s[i] == '?' or s[i] == 'C') and dp[i][N][C + 1][k]) {
            s[i] = 'C';
            C++;
        } else if (s[i] == '?') {
            s[i] = 'Z';
        }
    }

    cout << s << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}