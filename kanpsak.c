#include <stdio.h>
int knapsack(int[], int[], int, int);
int main()
{
    int v[21], w[21], i, j, n, W;

    printf("no of objects: ");
    scanf("%d", &n);
    printf("\ncapacity of knapsack: ");
    scanf("%d", &W);
    for (i = 1; i <= n; i++)
    {
        printf("\nEnter weight and value :\n");
        scanf("%d", &w[i]);
        scanf("%d", &v[i]);
    }
    knapsack(w, v, n, W);
}
int knapsack(int w[], int v[], int n, int W)
{
    int k[21][21], i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                k[i][j] = 0;
            }
            else if (j < w[i])
            {
                k[i][j] = k[i - 1][j];
            }
            else
            {
                if (k[i - 1][j] > k[i - 1][j - w[i]] + v[i])
                {
                    k[i][j] = k[i - 1][j];
                }
                else
                {
                    k[i][j] = k[i - 1][j - w[i]] + v[i];
                }
            }
        }
    }
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            printf("  %d", k[i][j]);
        }
        printf("\n");
    }
    printf(" maximum capacity is %d", k[n][W]);
}
