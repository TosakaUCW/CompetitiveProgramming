#include <bits/stdc++.h>

#define int long long

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::endl;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int T;
    // cin >> T;
    // for(;T--;solve());

    int n, m, k;
    cin >> n >> m >> k;

    if(m == 0) {
        if(n <= 26) {
            cout << "Yes" << endl;
            for(int i = 0;i < n;i ++) {
                for(int j = 0;j < k;j ++) {
                    cout << char(i + 'a');
                }
                cout << endl;
            }
        }else {
            cout << "No" << endl;
        }
        return 0;
    }
    if(m < k) {
        cout << "Yes" << endl;
        char s1 = 'b', s2 = 'c';
        for(int i = 0;i < n;i ++) {
            for(int j = 0;j < m - 1;j ++) {
                cout << "a";
            }
            for(int j = m - 1;j < k;j ++) {
                cout << ((j - m + 1) % 2 == 0 ? s1 : s2);
            }
            cout << endl;


            if (s2 == 'z') {
                s1++;
                s2 = s1 + 1;
            } else {
                s2 ++;
            }
        }
    }else {
        cout << "No" << endl;
    }
    return 0;
}