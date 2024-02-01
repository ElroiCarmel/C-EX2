#include <stdio.h>
#define MAT_SIZE 10

void inputMat(int mat[MAT_SIZE][MAT_SIZE])
{
    int i, j;
    for (i=0; i<MAT_SIZE; i++)
    {
        for (j = 0; j<=i; j++)
        {
            if (i == j)
            {
                mat[i][j]= 0;
            }
            else
            {
                printf("Enter the wighted value edge of {%d, %d} ", i, j);
                scanf("%d", &mat[i][j]);
                mat[j][i] = mat[i][j];
            }
        }
    }
}