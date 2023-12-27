#include<stdio.h>

int main()
{
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    if (a>b)
        printf("%d is the larger number", a);
    else if (b>a)   
    {
        printf("%d is the larger number", b);
    }
    else
    {
        printf("They are equal");
    }
    return 0;
}