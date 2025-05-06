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
using pii = pair<int, int>;
const int inf = 1e18;

string S(int x) {
    string s = to_string(x) + to_string(x + 1);
    ranges::sort(s);
    return s;
}
int getnum(string s) {
    int p = 0;
    while (s[p] == '0') p++;
    swap(s[0], s[p]);
    return stoll(s);
}

vector<int> res;
vector<pair<string, int>> cand;

void dfs(string s, bool flag) {
    if (*max_element(s.begin(), s.end()) > '0') {
        int x = getnum(s);
        cand.eb(S(x), x);
    }
    if (s.size() < 9) {
        if (flag) {
            dfs(s + "9", true);
        } else {
            for (char c = '0'; c <= '9'; c++) {
                dfs(s + c, c < s.back());
            }
        }
    }
}   

void solve() {
    int n = read();
    int ans = ranges::upper_bound(res, n) - res.begin();
    cout << ans << '\n';
}

signed main() {
    for (char c = '0'; c <= '9'; c++) {
        dfs(string(1, c), false);
    }
    ranges::sort(cand);
    for (int i = 0; i < cand.size(); i++) {
        if (i == 0 or cand[i].first != cand[i - 1].first) {
            res.eb(cand[i].second);
        }
    }
    ranges::sort(res);
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}