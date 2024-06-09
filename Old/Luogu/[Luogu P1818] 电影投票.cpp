#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <math.h>

#define ld long double
#define ll long long

ld a, b;
ll n;

int main()
{
    while (std::cin >> a >> b >> n)
    {
        if (a <= b)
            puts("0");
        else
        {
            a += (ld)0.04999999999999;
            b += (ld)0.04999999999999;
            a = std::min((ld)10.0, a);
            b = std::min((ld)10.0, b);
            ll tmp = a * n;
            ld res = ((ld)(b * n - tmp) / ((ld)1 - b));
            std::cout << (ll)ceil(res) << '\n';
        }
    }
    return 0;
}