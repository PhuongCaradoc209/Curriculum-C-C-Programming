#include <stdio.h>

int main()
{
    int a, b, c;
    int max, min;
    int sum = 0, product = 1;
    float avr;

    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);
    max = a;
    min = a;
    if (a > b)
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }

    if (c > max)
    {
        max = c;
    }
    else if (c < min)
    {
        min = c;
    }

    sum = a + b + c;
    product = a * b * c;
    avr = (float)sum / 3;

    printf("Max: %d\nMin: %d", max, min);
    printf("\nSum = %d\nProduct = %d", sum, product);
    printf("\nAvr = %.2f", avr);
}