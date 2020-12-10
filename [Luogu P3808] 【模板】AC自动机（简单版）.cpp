#include <stdio.h>
#include <string.h>
#include <queue>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e6 + 5;

int n;
char s[N];

struct Aho_Corasick_Automaton
{
    int num_node;
    int ch[N][27], fail[N], last[N], val[N];
    void clear()
    {
        num_node = 0;
        memset(ch, 0, sizeof ch);
        memset(fail, 0, sizeof fail);
        memset(last, 0, sizeof last);
        memset(val, 0, sizeof val);
    }
    void insert(char *s)
    {
        int u = 0, len = strlen(s);
        Rep(i, 0, len - 1)
        {
            int c = s[i] - 'a' + 1;
            if (!ch[u][c])
                ch[u][c] = ++num_node;
            u = ch[u][c];
        }
        val[u]++;
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
    int count(char *s)
    {
        int res = 0;
        int u = 0, len = strlen(s);
        Rep(i, 0, len - 1)
        {
            int c = s[i] - 'a' + 1;
            u = ch[u][c];
            if (val[u])
            {
                res += val[u];
                val[u] = 0;
            }
            int v = u;
            while (last[v])
            {
                v = last[v];
                if (val[v])
                {
                    res += val[v];
                    val[v] = 0;
                }
            }
        }
        return res;
    }
} AC;

int main()
{
    scanf("%d", &n);
    AC.clear();
    Rep(i, 1, n)
    {
        scanf("%s", s);
        AC.insert(s);
    }
    AC.get_fail();
    scanf("%s", s);
    printf("%d", AC.count(s));
    return 0;
}