#include <stdio.h>

int power(int x, int y)
{
    int result = 1;
    for (int i = 0; i < y; i++)
    {
        result *= x;
    }
    return result;
}

int main()
{
    int x, y;
    printf("Enter two integer (x^y): ");
    scanf("%d%d", &x, &y);
    printf("%d^%d = %d", x, y, power(x, y));
}