#include <bits/stdc++.h>
using i64 = long long;
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
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second
struct Node { char op1; int x1; char op2; int x2; };

void solve() {
    int n = read();
    vector<Node> opt(n);
    for (auto &[op1, x1, op2, x2] : opt) {
        cin >> op1 >> x1 >> op2 >> x2;
    }
    array<int, 3> dp {1, 1, 0};

    ranges::reverse(opt);

    for (auto [op1, x1, op2, x2] : opt) {
        int a1, b1;
        if (op1 == 'x'){
            a1 = x1 - 1;
            b1 = 0;
        } else {
            a1 = 0;
            b1 = x1;
        }
        int a2, b2;
        if (op2 == 'x'){
            a2 = x2 - 1;
            b2 = 0;
        } else {
            a2 = 0;
            b2 = x2;
        }
        
        int tot = b1 + b2;
        
        array<int, 3> ndp;
        if (dp[0] >= dp[1]){
            ndp[0] = dp[0] * (1 + a1);
            ndp[1] = dp[1] + dp[0] * a2;
            ndp[2] = dp[0] * tot + dp[2];
        } else {
            ndp[0] = dp[0] + dp[1] * a1;
            ndp[1] = dp[1] * (1 + a2);
            ndp[2] = dp[1] * tot + dp[2];
        }
        dp = ndp;
    }

    int ans = dp[0] + dp[1] + dp[2];
    cout << ans << "\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
