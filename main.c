#include <stdio.h>
#include "my_mat.h"

int main()
{
    char option;
    int matrix[10][10];
    int dist[10][10];
    do {
    printf("Enter an option:");
    scanf(" %c", &option);
    switch (option)
    {
    case 'A':
        inputMat(matrix);
        updateDistMat(dist, matrix);
        break;
    case 'B':
        int a,b;
        printf("Enter the vertices: ");
        scanf("%d%d", &a, &b);
        if (dist[a][b])
        {
            printf("True\n");
        } else
        {
            printf("False\n");
        }
        break;
    default:
        printf("You need to enter A/B/C/D!\n");
    } 
    } while (option != 'D');
    return 0;
}

