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
#define fi first
#define se second
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
template <class T> bool cmin(T &a, T b) { return (b < a) ? (a = b, true) : false; }
template <class T> bool cmax(T &a, T b) { return (a < b) ? (a = b, true) : false; }
using pii = pair<int, int>;
using tup = tuple<int, int, int>;
const int inf = 1e18;
const double eps = 1e-9;

map<string, int> vis;
map<int, string> res;
void prepare() {
    vector<int> a(8);
    int yy = 1923;

    for (a[0] = 0; a[0] <= 1; a[0]++) {
        for (a[1] = 0; a[1] <= 1; a[1]++) {
            for (a[2] = 0; a[2] <= 1; a[2]++) {
                for (a[3] = 0; a[3] <= 1; a[3]++) {
                    for (a[4] = 0; a[4] <= 1; a[4]++) {
                        for (a[5] = 0; a[5] <= 1; a[5]++) {
                            for (a[6] = 0; a[6] <= 1; a[6]++) {
                                for (a[7] = 0; a[7] <= 1; a[7]++) {
                                    string s;
                                    for (int x : a) s += char(x + '0');

                                    // auto t = ranges::reverse(s);
                                    auto t = s;
                                    ranges::reverse(t);
                                    if (vis[s] > 0 or vis[t] > 0) {
                                        continue;
                                    }
                                    vis[s] = yy;
                                    vis[t] = yy;
                                    res[yy] = s;
                                    yy++;
                                }
                            }
                        }   
                    }
                }
            }
        }
    }
}

void solve1() {
    int x = read();
    cout << res[x] << '\n';
}
void solve2() {
    string s; cin >> s;
    cout << vis[s] << '\n';
}

signed main() {
    prepare();
    string s; cin >> s;
    if (s == "write") solve1();
    else solve2();
    // solve();
    return 0;
}