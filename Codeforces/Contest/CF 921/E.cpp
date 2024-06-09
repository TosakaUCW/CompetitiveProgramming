#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
const int M = 1005;
int T, n, k, m;
int pre[M]['z' + 5];
int flag['z' + 5][27];
int ill['z' + 5][27];
string s;
int main()
{
    /* freopen("out.txt", "w", stdout); */
    cin >> T;
    while (T--)
    {
        cin >> n >> k >> m >> s;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < k; j++)
                pre[i][j + 'a'] = 0;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
                flag['a' + i][j] = 0;
        }
        pre[0][s[0]] = 1;
        for (int i = 1; i < m; i++)
            for (int j = 0; j < k; j++)
                if (j + 'a' == s[i])
                    pre[i][j + 'a'] = pre[i - 1][j + 'a'] + 1;
                else
                    pre[i][j + 'a'] = pre[i - 1][j + 'a'];
        int lcnt['z' + 5], rcnt['z' + 5];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (i == 0)
                    lcnt[j + 'a'] = 0;
                else
                    lcnt[j + 'a'] = pre[i - 1][j + 'a'];
                if (i == m - 1)
                    rcnt[j + 'a'] = 0;
                else
                    rcnt[j + 'a'] = pre[m - 1][j + 'a'] - pre[i][j + 'a'];
            }
            /* cout << "--\n";
            for (int j = 0; j < k; j++)
                cout << lcnt[j + 'a'] << " " << rcnt[j + 'a'] << "\n"; */
            for (int j = 0; j < n; j++)
            {
                bool f = 1;
                for (int c = 0; c < k; c++)
                {
                    if ((lcnt[c + 'a'] < j || rcnt[c + 'a'] < n - 1 - j) && !flag[s[i]][j])
                        f = 0, ill[s[i]][j] = c + 'a';
                }
                flag[s[i]][j] |= f;
            }
        }
        bool f = 1;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
                if (!flag['a' + i][j])
                {
                    f = 0;
                    puts("NO");
                    for (int d = 1; d <= j; d++)
                        putchar(ill['a' + i][j]);
                    cout << (char)('a' + i);
                    for (int d = 1; d <= n - 1 - j; d++)
                        putchar(ill['a' + i][j]);
                    cout << "\n";
                    break;
                }
            if (!f)
                break;
        }
        if (f)
            cout << "YES\n";
    }
    return 0;
}