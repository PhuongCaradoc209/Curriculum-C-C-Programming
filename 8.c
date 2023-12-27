#include <stdio.h>

int countDigit(int n)
{
    int count = 0;
    while (n > 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}

int main()
{
    int n;
    printf("Enter a integer: ");
    scanf("%d", &n);
    printf("The number of digits: %d", countDigit(n));
}