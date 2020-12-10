// luogu-judger-enable-o2
#include <stdio.h>
#include <string.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int StringSize = 1e6 + 5;

struct KnuthMorrisPratt
{
    int len1, len2, next[StringSize];
    char s1[StringSize], s2[StringSize];
    void init() { scanf("%s%s", s1, s2); }
    void get_next()
    {
        int t1 = 0, t2 = -1;
        next[0] = -1;
        while (t1 < len2)
        {
            if (t2 == -1 or s2[t1] == s2[t2])
                next[++t1] = ++t2;
            else
                t2 = next[t2];
        }
    }
    void print_next()
    {
        Rep(i, 1, len2)
            printf("%d ", next[i]);
    }
    void kmp()
    {
        len1 = strlen(s1);
        len2 = strlen(s2);
        get_next();
        int t1 = 0, t2 = 0;
        while (t1 < len1)
        {
            if (t2 == -1 or s1[t1] == s2[t2])
                ++t1, ++t2;
            else
                t2 = next[t2];
            if (t2 == len2)
            {
                printf("%d\n", t1 - len2 + 1);
                t2 = next[t2];
            }
        }
    }
} KMP;

int main()
{
    KMP.init();
    KMP.kmp();
    KMP.print_next();
    return 0;
}