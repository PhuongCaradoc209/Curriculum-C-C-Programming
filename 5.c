#include <stdio.h>

int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * factorial(n-1);
}

int main()
{
    int n;
    printf("Enter a integer: ");
    scanf("%d", &n);
    printf("P = %d", factorial(n));
}