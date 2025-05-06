#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }

void solve() {
    int n, m;
    cin >> n >> m;
    vector blk(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        int Ri;
        cin >> Ri;
        while (Ri--) {
            int x;
            cin >> x;
            blk[i][x - 1] = true;
        }
    }

    vector  dist(n, vector<int>(m, 0));
    queue<pair<int,int>> q;
    
    for (int i = 0; i < n; i++) {
        if (!blk[i][0]) {
            dist[i][0] = 1;  
            q.emplace(i, 0);
        }
    }
    
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    int ans = -1;
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        
        if (j == m - 1) {
            ans = dist[i][j];
            break;
        }
        
        for (int d = 0; d < 4; d++) {
            int nx = i + dx[d];
            int ny = j + dy[d];
            if (nx >= 0 and nx < n and ny >= 0 and ny < m
                and !blk[nx][ny]
                and dist[nx][ny] == 0) {
                dist[nx][ny] = dist[i][j] + 1;
                q.emplace(nx, ny);
            }
        }
    }
    
    cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    
    return 0;
}