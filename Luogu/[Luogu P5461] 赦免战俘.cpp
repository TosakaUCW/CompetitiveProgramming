#include <math.h>
#include <stdio.h>

int n;
int a[1025][1025];

void search(int x1, int y1, int x2, int y2)
{
    if (x1 == x2 and y1 == y2)
    {
        a[x1][y1] = 1;
        return;
    }
    int x = x1 + x2;
    int y = y1 + y2;
    //printf("%d %d %d %d\n",x1,y1,x2,y2);
    search(x / 2 + 1, y1, x2, y / 2);
    search(x1, y / 2 + 1, x / 2, y2);
    search(x / 2 + 1, y / 2 + 1, x2, y2);
}

int main()
{
    scanf("%d", &n);
    n = pow(2, n);
    //printf("%d\n",n);
    search(1, 1, n, n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}