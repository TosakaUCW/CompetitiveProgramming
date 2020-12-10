#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <complex>

typedef std::complex<double> E;

const int N = 3e6 + 5;
const double Pi = acos(-1);

int n, m, limit = 1;
int L, R[N];
E A[N], B[N];

void Fast_Fourier_Transform(E *A, int type)
{
    for (int i = 0; i < limit; i++)
        if (i < R[i])
            std::swap(A[i], A[R[i]]);
    for (int i = 1; i < limit; i <<= 1)
    {
        E Wn(cos(Pi / i), type * sin(Pi / i));
        for (int j = 0, p = i << 1; j < limit; j += p)
        {
            E w(1, 0);
            for (int k = 0; k < i; k++, w *= Wn)
            {
                E x = A[j + k], y = w * A[i + j + k];
                A[j + k] = x + y, A[i + j + k] = x - y;
            }
        }
    }
}

int main()
{

    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
        scanf("%lf", &A[i]);
    for (int i = 0; i <= m; i++)
        scanf("%lf", &B[i]);
    while (limit <= n + m)
        limit <<= 1, L++;
    for (int i = 0; i < limit; i++)
        R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
    Fast_Fourier_Transform(A, 1);
    Fast_Fourier_Transform(B, 1);
    for (int i = 0; i <= limit; i++)
        A[i] *= B[i];
    Fast_Fourier_Transform(A, -1);
    for (int i = 0; i <= n + m; i++)
        printf("%d ", (int)(A[i].real() / limit + 0.5));
    return 0;
}