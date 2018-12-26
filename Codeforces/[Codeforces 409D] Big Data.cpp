#include <stdio.h>

const char s[] = "1001010111001010";

int main()
{
    int n;
    scanf("%d", &n);
    printf("%c", s[n - 1]);
    return 0;
}