#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter a integer: ");
    scanf("%d", &n);
    int i = 1, s = 0;
    while (i <= n)
    {
        s += pow(i, 2);
        i++;
    }
    printf("S = %d", s);
}