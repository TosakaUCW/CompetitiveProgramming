#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double ans = -1e18 - 7, t;
const double delta = 0.8375;
const int N = 20 + 5;

int n;
double L, R, a[N], ansx;

double calc_energy(double x)
{
    double res = 0;
    if (x < L or R < x)
        return -1e18 - 7;
    for (int i = n; i >= 0; i--)
        res += a[i] * pow(x, i);
    return res;
}

void simulate_anneal()
{
    double x = ansx;
    t = 2000;
    while (t > 1e-14)
    {
        double X = ansx + ((rand() << 1) - RAND_MAX) * t;
        double now = calc_energy(X);
        double Delta = now - ans;
        if (Delta > 0)
            x = X, ansx = x, ans = now;
        else if (exp(-Delta / t) * RAND_MAX > rand())
            x = X;
        t *= delta;
    }
}

int main()
{
    scanf("%d%lf%lf", &n, &L, &R);
    for (int i = n; i >= 0; i--)
        scanf("%lf", &a[i]);
    simulate_anneal();
    printf("%.5lf", ansx);
    return 0;
}