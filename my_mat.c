#include <stdio.h>
#include "my_mat.h"


void inputMat(int mat[SIZE][SIZE])
{
    int i, j;
    for (i=0; i<SIZE; i++)
    {
        for (j = 0; j<SIZE; j++)
        {
                scanf("%d", &mat[i][j]);
        }
    }
}

void updateDistMat(int distMat[SIZE][SIZE], int graph[SIZE][SIZE])
{
    /* First initialize to weight graph*/
    int i,j,k;
    for (i=0; i<SIZE; i++)
    {
        for (j=0; j<SIZE; j++)
        {
            if (graph[i][j])
            {
                distMat[i][j] = graph[i][j];
            } else
            {
                distMat[i][j] = INF;
            }
        }
    }
    
    for (i=0; i<SIZE; i++)
    {
        distMat[i][i] = 0;
    }

    for ( k= 0; k <SIZE; k++)
    {
        for (i = 0; i<SIZE; i++)
        {
            for (j=0; j < SIZE; j++)
            {
                if (distMat[i][j] > distMat[i][k] + distMat[k][j])
                {
                    distMat[i][j] = distMat[i][k] + distMat[k][j];
                }
            }
        }
    }
    

}
