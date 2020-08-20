#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double ansx, ansy;
double ans = 1e18, t;
const double delta = 0.92;

struct node
{
    int x, y, w;
} a[1010];
int n, sx, sy;

double calc_energy(double x, double y)
{
    double rt = 0;
    for (int i = 1; i <= n; i++)
    {
        double deltax = x - a[i].x, deltay = y - a[i].y;
        rt += sqrt(deltax * deltax + deltay * deltay) * a[i].w;
    }
    return rt;
}

void simulate_anneal()
{
    double x = ansx, y = ansy;
    t = 2000;
    while (t > 1e-14)
    {
        double X = x + ((rand() << 1) - RAND_MAX) * t;
        double Y = y + ((rand() << 1) - RAND_MAX) * t;
        double now = calc_energy(X, Y);
        double Delta = now - ans;
        if (Delta < 0)
        {
            x = X, y = Y;
            ansx = x, ansy = y, ans = now;
        }
        else if (exp(-Delta / t) * RAND_MAX > rand())
            x = X, y = Y;
        t *= delta;
    }
}

void Solve()
{
    ansx = (double)sx / n, ansy = (double)sy / n;
    simulate_anneal();
    simulate_anneal();
    simulate_anneal();
}

int main()
{
    srand(233333333333);
    srand(rand()), srand(rand());
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].w);
        sx += a[i].x, sy += a[i].y;
    }
    Solve();
    printf("%.3f %.3f", ansx, ansy);
    return 0;
}