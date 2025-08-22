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
    string s[3];
    for (int i = 0; i < 3; i++) cin >> s[i];

    const string t = "ogrc";
    vector<string> ans;


    auto work = [&](int x, int k) {
        ans.eb(t.substr(x, 1) + char(k + '0'));
        if (x < 3) {
            rotate(s[x].begin(), s[x].end() - k, s[x].end());
        } else {
            for (int i = 0; i < 3; i++) {
                string u;
                for (int j = 0; j < 3; j++) {
                    u += s[j][i];
                }
                rotate(u.begin(), u.begin() + k, u.end());
                for (int j = 0; j < 3; j++) {
                    s[j][i] = u[j];
                }
            }
        }
    };

    while (1) {
        bool flag = 1;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 10; j++) {
                if (s[i][j] == t[i]) continue;

                flag = 0;
                if (j != 0) work(i, 10 - j);
                int i1 = t.find(s[i][0]);
                int j1 = 0;
                while (s[i1][j1] == t[i1]) j1++;

                if (j1 != 3) work(i1, (3 - j1 + 10) % 10);
                work(3, (i - i1 + 3) % 3);
                work(i1, 9);
                work(3, (i1 - i + 3) % 3);
            }
        }

        if (flag) break;
    }

    cout << ans.size() << '\n';
    for (auto s : ans) cout << s << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}