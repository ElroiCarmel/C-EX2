#include <stdio.h>
#include "my_mat.h"

int main()
{
    char option;
    int matrix[SIZE][SIZE];
    int dist[SIZE][SIZE];
    do {
    scanf(" %c", &option);
    switch (option)
    {
    case 'A':
        inputMat(matrix);
        updateDistMat(dist, matrix);
        break;
    case 'B':
        int a,b;
        scanf("%d%d", &a, &b);
        if (dist[a][b] > 0 && dist[a][b] < INF)
        {
            printf("True\n");
        } else
        {
            printf("False\n");
        }
        break;
    case 'C':
        int u, v;
        scanf("%d%d", &u, &v);
        if (dist[u][v] > 0 && dist[u][v] < INF)
        {
            printf("%d\n", dist[u][v]);
        } else
        {
            printf("-1\n");
        }
        break;
    } 
    } while (option != 'D');
    return 0;
}

