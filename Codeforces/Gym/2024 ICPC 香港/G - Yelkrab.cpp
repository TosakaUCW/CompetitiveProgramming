#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
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

const int N = 1e6 + 5;
vector<int> fac[N];
struct node_t {
    int out[26];
    int64_t size;
} nod[N];

void solve() {
    int n = read();

    int ans = 0;
    int sum = 0;

    vector<string> a(n);
    for (auto &s : a) {
        cin >> s;
        sum += s.size();
    }

    int cnt = 0;
    memset(nod + cnt, 0, sizeof (node_t));

    vector<int> res(sum + 1, 0);

    for (int i = 0; i < n; i++) {
        auto s = a[i];
        int cur = 0;
        for (auto ch : s) {
            int u = ch - 'a';
            if (!nod[cur].out[u]) {
                nod[cur].out[u] = ++cnt;
                memset(nod + cnt, 0, sizeof (node_t));
            }
            cur = nod[cur].out[u];
            int t = ++nod[cur].size;
            for (auto d : fac[t]) {
                ans ^= res[d] * d;
                res[d]++;
                ans ^= res[d] * d;
            }
        }
        std::cout << ans << " \n"[i == n - 1];
    } 
}

signed main() {
    for (int i = 1; i <= 1000000; i++)
        for(int j = i; j <= 1000000; j += i)
            fac[j].eb(i);
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
