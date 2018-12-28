// luogu-judger-enable-o2
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int LenT = 1e6 + 5;
const int NS = 150 + 5;
const int LenS = 70 + 5;
const int N = 150 * 70 + 5;

int n, cnt[N];
char s[NS][LenS], t[LenT];

struct Aho_Corasick_Automaton
{
    int num_node;
    int ch[N][27], fail[N], last[N], val[N];
    void clear()
    {
        num_node = 0;
        memset(ch, 0, sizeof ch);
        memset(cnt, 0, sizeof cnt);
        memset(fail, 0, sizeof fail);
        memset(last, 0, sizeof last);
        memset(val, 0, sizeof val);
    }
    void insert(char *s, int index)
    {
        int u = 0, len = strlen(s);
        Rep(i, 0, len - 1)
        {
            int c = s[i] - 'a' + 1;
            if (!ch[u][c])
                ch[u][c] = ++num_node;
            u = ch[u][c];
        }
        val[u] = index;
    }
    void get_fail()
    {
        std::queue<int> Q;
        Q.push(0);
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            int k = fail[u];
            Rep(c, 1, 26)
            {
                int v = ch[u][c];
                if (!v)
                {
                    ch[u][c] = ch[k][c];
                    continue;
                }
                fail[v] = u ? ch[k][c] : 0;
                last[v] = val[fail[v]] ? fail[v] : last[fail[v]];
                Q.push(v);
            }
        }
    }
    void query(char *t)
    {
        int res = 0;
        int u = 0, len = strlen(t);
        Rep(i, 0, len - 1)
        {
            int c = t[i] - 'a' + 1;
            u = ch[u][c];
            if (val[u])
                cnt[val[u]]++;
            int v = u;
            while (last[v])
            {
                v = last[v];
                if (val[v])
                    cnt[val[v]]++;
            }
        }
        Rep(i, 1, n)
            res = std::max(res, cnt[i]);
        printf("%d\n", res);
        Rep(i, 1, n)
        {
            if (cnt[i] == res)
                printf("%s\n", s[i]);
        }
    }
} AC;

int main()
{
    while (scanf("%d", &n) and n)
    {
        AC.clear();
        Rep(i, 1, n)
        {
            scanf("%s", s[i]);
            AC.insert(s[i], i);
        }
        AC.get_fail();
        scanf("%s", t);
        AC.query(t);
    }
    return 0;
}