#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    int x = (n + 1) / 2;
    int ans = (m - x) * 2 + 1;
    cout << ans << '\n';
}

int main() {
    int T;
    for (cin >> T; T--; solve());
    return 0;
}