#include <stdio.h>
int main()
{
    int i, j, n, k, temp;
    printf("Enter size of the array\n ");
    scanf("%d", &n);
    int a[n];
    printf("Enter element\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\nprinting sorted elements...\n");
    for (k = 1; k < n; k++)
    {
        temp = a[k];
        j = k - 1;
        while (j >= 0 && temp <= a[j])
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
