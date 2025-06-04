#include <bits/stdc++.h>
using i64 = long long;
using ull = unsigned long long;
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
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int n = read();
    int m = read();
    int A = read();
    int B = read();

    vector<int> a(n);
    vector<vector<int>> buk(1 << m);
    for (int i = 0; i < n; i++) {
        auto &x = a[i];
        string s; cin >> s;
        for(int j = 0; j < m; j++) {
            x |= (s[j] - '0') << j;
        }
        buk[x].eb(i + 1);
    }

    auto getcw = [&](int s) -> pii {
        int cnt = __builtin_popcountll(s);
        int w = 0;
        for (int j = 1; j <= m; j++) {
            if (s >> (j - 1) & 1) w += j;
        }
        return pii(cnt, w);
    };

    vector<int> siz(1 << m);
    vector<vector<int>> sum(1 << m);
    for (int s = 0; s < (1 << m); s++) {
        siz[s] = buk[s].size();
        sum[s].assign(siz[s] + 1, 0);
        for (int i = 1; i <= siz[s]; i++) {
            sum[s][i] = sum[s][i - 1] + buk[s][i - 1];
        }
    }

    int ans = -4e18;
    for (int s1 = 0; s1 < (1 << m); s1++) {

        int res = 0;
        for (int s2 = 0; s2 < (1 << m); s2++) {

            int s = s1 ^ s2;
            int sz = siz[s2];
            if (sz == 0) continue;

            auto [cnt, w] = getcw(s);

            auto getSum = [&](int l, int r) -> int { 
                return sum[s2][r] - sum[s2][l - 1]; 
            };
            auto calc = [&](int i, int op) -> int {
                if (op == 1) {
                    return A * i * (m - cnt) + B * ((m + 1) * m / 2 - w);                
                } else {
                    return A * i * cnt + B * w;
                }
            };
            auto getType = [&](int i) -> bool { 
                return calc(i, 1) > calc(i, 0);
            };
            
            int type = getType(buk[s2][0]);
            int k = 0;
            for (int L = 0, R = sz - 1; L <= R; ) {
                int mid = L + R >> 1;
                int pos = buk[s2][mid];
                if (getType(pos) == type) k = mid, L = mid + 1;
                else R = mid - 1;
            }

            k++;

            if (type) {
                // for (int i = 0; i <= k; i++) res += calc(buk[s2][i], 1);
                // for (int i = k + 1; i < sz; i++) res += calc(buk[s2][i], 0);
                res += A * getSum(k + 1, sz) * cnt + B * w * (sz - k);
                res += A * getSum(1, k) * (m - cnt) + B * ((m + 1) * m / 2ll - w) * (k);
            } else {
                // for (int i = 0; i <= k; i++) res += calc(buk[s2][i], 0);
                // for (int i = k + 1; i < sz; i++) res += calc(buk[s2][i], 1);
                res += A * getSum(1, k) * cnt + B * w * k;
                res += A * getSum(k + 1, sz) * (m - cnt) + B * ((m + 1) * m / 2ll - w) * (sz - k);
            }
            // for (auto x : buk[s2]) res += calc(x, getType(x));
        }
        ans = max(ans, res);
    }

    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}