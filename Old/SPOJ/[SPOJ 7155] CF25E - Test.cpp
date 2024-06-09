#include <stdio.h>
#include <string.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int INF = 2147483647;
const int StringSize = 1e5 + 5;

int f[4][4];

struct KnuthMorrisPratt
{
    int len[4], next[4][StringSize];
    char str[4][StringSize];
    bool init() { return (~scanf("%s%s%s", str[1] + 1, str[2] + 1, str[3] + 1)); }
    void get_next(int len, char *s, int index)
    {
        int p = 0;
        for (int i = 2; i <= len; i++)
        {
            while (p != 0 and s[p + 1] != s[i])
                p = next[index][p];
            if (s[p + 1] == s[i])
                p++;
            next[index][i] = p;
        }
    }
    int kmp(int len1, int len2, char *s1, char *s2, int index)
    {
        int p = 0;
        for (int i = 1; i <= len1; i++)
        {
            while (p != 0 and s2[p + 1] != s1[i])
                p = next[index][p];
            if (s2[p + 1] == s1[i])
                p++;
            if (p == len2)
                return -1;
        }
        return p;
    }
    void solve()
    {
        for (int i = 1; i <= 3; i++)
            len[i] = strlen(str[i] + 1);
        for (int i = 1; i <= 3; i++)
        {
            get_next(len[i], str[i], i);
            for (int j = 1; j <= 3; j++)
                if (i != j)
                    f[j][i] = kmp(len[j], len[i], str[j], str[i], i);
        }
        int ans = INF;
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                for (int k = 1; k <= 3; k++)
                {
                    if (i == j or j == k or i == k)
                        continue;
                    int tot = len[i] + len[j] + len[k] - f[i][j] - f[j][k];
                    if (f[i][j] >= 0 and f[j][k] >= 0)
                        ans = std::min(ans, tot);
                    else
                    {
                        if (f[i][j] < 0 and f[i][k] < 0)
                            ans = std::min(ans, len[i]);
                        else if (f[i][j] < 0)
                            ans = std::min(ans, tot + f[i][j] + f[j][k] - len[j] - f[i][k]);
                        if (f[j][k] < 0)
                            ans = std::min(ans, tot + f[j][k] - len[k]);
                    }
                }
        printf("%d\n", ans);
    }
} KMP;

int main()
{
    while (KMP.init())
        KMP.solve();
    return 0;
}