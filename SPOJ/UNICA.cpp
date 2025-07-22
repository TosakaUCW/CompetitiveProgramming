#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const ull INF = 4e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ull N;
    cin >> N;

    int id = 0;
    int idx[4][4];
    pair<int,int> info[10];
    for (int w = 0; w <= 3; ++w) {
        for (int d = 0; d <= w; ++d) {
            idx[w][d] = id;
            info[id] = {w, d};
            ++id;
        }
    }

    int nextA[10], nextB[10];
    for (int s = 0; s < 10; ++s) {
        auto [w, d] = info[s];
        // a
        if (d < w) {
            nextA[s] = idx[w][d+1];
        } else if (w < 3) {
            nextA[s] = idx[w+1][w+1];
        } else {
            nextA[s] = -1;
        }
        // b
        if (d > 0) { nextB[s] = idx[w][d-1]; 
        } else if (w < 3) {
            nextB[s] = idx[w+1][0];
        } else {
            nextB[s] = -1;
        }
    }

    const int MAXLEN = 70;
    ull ways[MAXLEN + 1][10] = {};
    for (int s = 0; s < 10; ++s) {
        ways[0][s] = 1;
    }

    for (int len = 1; len <= MAXLEN; ++len) {
        for (int s = 0; s < 10; ++s) {
            ull v = 0;
            if (nextA[s] != -1) { 
                v += ways[len-1][nextA[s]]; 
                if (v > INF) v = INF; 
            }
            if (nextB[s] != -1) { 
                v += ways[len-1][nextB[s]]; 
                if (v > INF) v = INF; 
            }
            ways[len][s] = v;
        }
    }

    ull cum = 0;
    int tar = 0;
    for (int len = 1; len <= MAXLEN; ++len) {
        ull cnt = ways[len][0];
        if (cum + cnt >= N) { tar = len; break; }
        cum += cnt;
    }
    ull K = N - cum;

    string ans;
    int state = 0;
    int rem = tar;
    while (rem--) {
        ull cntA = (nextA[state] == -1) ? 0 : ways[rem][nextA[state]];
        if (K <= cntA) {
            ans.push_back('a');
            state = nextA[state];
        } else {
            K -= cntA;
            ans.push_back('b');
            state = nextB[state];
        }
    }

    cout << ans << '\n';
    return 0;
}
