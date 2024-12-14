#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
using std::max;
using std::min;
using std::swap;
using std::cin;
using std::cout;
using std::string;
using std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
// using namespace std;
using std::ostream;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

const int inf = 1e18;
const int N = 3e2 + 5;

const int dx[] = {-1, +0, +1, +0};
const int dy[] = {+0, -1, +0, +1};

void solve() {
    int n = read();
    string s;
    cin >> s;
    
    int x = 0, y = 0;
    int dir = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') dir = (dir + 1) % 4;
        if (s[i] == 'R') dir = (dir + 3) % 4;
        x += dx[dir], y += dy[dir];

        // cout << x << ' ' << y << '\n';
    }

    // cout << "----------------\n";

    int edx = x, edy = y;
    // cout << edx << ' ' << edy << '\n';

    vector<int> dpx(n + 1);
    vector<int> dpy(n + 1);
    // dpx[n] = edx, dpy[n] = edy;
    for (int i = n - 1; i >= 0; i--) {
        x -= dx[dir], y -= dy[dir];
        if (s[i] == 'L') dir = (dir + 3) % 4;
        if (s[i] == 'R') dir = (dir + 1) % 4;
        

        // cout << x << ' ' << y << " -- ";

        dpx[i] = edx - x;
        dpy[i] = edy - y;

        // cout << dpx[i] << ' ' << dpy[i] << '\n';
    }

    // cout << "----------------\n";

    std::map<pii, int> mp;

    x = 0, y = 0, dir = 0;
    for (int i = 0; i < n; i++) {

        if (s[i] == 'F') {
            int ndir, nx, ny;

            ndir = (dir + 1) % 4;
            nx = x + dx[ndir] - dpy[i + 1];
            ny = y + dy[ndir] + dpx[i + 1];
            mp[{nx, ny}] = 1;

            // cout << i << " " << nx << " " << ny << '\n';
            
            ndir = (dir + 3) % 4;
            nx = x + dx[ndir] + dpy[i + 1];
            ny = y + dy[ndir] - dpx[i + 1];
            mp[{nx, ny}] = 1;

            // cout << i << " " << nx << " " << ny << '\n';
        }
        if (s[i] == 'L') {
            int ndir, nx, ny;

            ndir = (dir) % 4;
            nx = x + dx[ndir] + dpy[i + 1];
            ny = y + dy[ndir] - dpx[i + 1];
            mp[{nx, ny}] = 1;

            // cout << i << " " << nx << " " << ny << '\n';
            
            ndir = (dir + 3) % 4;
            nx = x + dx[ndir] - dpx[i + 1];
            ny = y + dy[ndir] - dpy[i + 1];
            mp[{nx, ny}] = 1;

            // cout << i << " " << nx << " " << ny << '\n';
        }
        if (s[i] == 'R') {
            int ndir, nx, ny;

            ndir = (dir + 1) % 4;
            nx = x + dx[ndir] - dpx[i + 1];
            ny = y + dy[ndir] - dpy[i + 1];
            mp[{nx, ny}] = 1;

            // cout << i << " " << nx << " " << ny << '\n';
            
            ndir = (dir) % 4;
            nx = x + dx[ndir] - dpy[i + 1];
            ny = y + dy[ndir] + dpx[i + 1];
            mp[{nx, ny}] = 1;

            // cout << i << " " << nx << " " << ny << '\n';
        }

        if (s[i] == 'L') dir = (dir + 1) % 4;
        if (s[i] == 'R') dir = (dir + 3) % 4;
        x += dx[dir], y += dy[dir];

        // cout << x << ' ' << y << '\n';
    }
    // mp[{edx, edy}] = 1;

    // cout << "----------------\n";

    // for (auto [p, _] : mp) {
    //     auto [x, y] = p;
    //     cout << x << ' ' << y << '\n';
    // }

    cout << mp.size();

    // cout
}
/*
L:
-1 0 -> 0 -1
0 -1 -> 1 0

*/

signed main() {
    // sieve(5000);
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}