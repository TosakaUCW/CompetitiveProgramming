#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 2e5;
int n, m, now, ans, tot;
struct Node
{
    int cod;
    bool isleft;
} line[N + 5];

inline bool cmp(Node a, Node b)
{
    return a.cod < b.cod;
}

int main()
{
    scanf("%d%d", &n, &m);
    Rep(i, 1, n)
    {
        int x;
        char s;
        scanf("%d %c", &x, &s);
        if (s == 'L')
        {
            line[++tot] = (Node){now, false};
            line[++tot] = (Node){now -= x, true};
        }
        else
        {
            line[++tot] = (Node){now, true};
            line[++tot] = (Node){now += x, false};
        }
    }
    std::sort(line + 1, line + 1 + tot, cmp);
    now = line[1].isleft ? 1 : 0;
    Rep(i, 2, tot)
    {
        if (now >= m)
            ans += line[i].cod - line[i - 1].cod;
        now += line[i].isleft ? 1 : -1;
    }
    printf("%d", ans);
    return 0;
}