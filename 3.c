#include <stdio.h>

int main()
{
    int a, b;
    
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);

    int temp = a;
    a = b;
    b = temp;
    
    printf("After swap:\na = %d\nb = %d", a, b);
}