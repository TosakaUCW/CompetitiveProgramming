#include <stdio.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 20;
const int M = 20;
int n, m, row[N + 5], col[M + 5];

int main()
{
    scanf("%d%d\n", &n, &m);
    Rep(i, 1, n)
    {
        char in;
        scanf("%c", &in);
        if (in == '<')
            row[i] = 0;
        else
            row[i] = 1;
    }
    getchar();
    Rep(i, 1, m)
    {
        char in;
        scanf("%c", &in);
        if (in == '^')
            col[i] = 0;
        else
            col[i] = 1;
    }
    if ((row[1] == 1 and row[n] == 0 and col[1] == 0 and col[m] == 1) 
     or (row[1] == 0 and row[n] == 1 and col[1] == 1 and col[m] == 0))
        printf("YES");
    else
        printf("NO");
    return 0;
}