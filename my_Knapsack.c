#include <stdio.h>

#define SIZE 6
#define CAPACITY 15

int knapSack();
void inputValues();
void inputWeights();
void printHelpMat();
void printArr();

int main()
{
    int w[SIZE] = {9,6,3,4,5,2};
    int v[SIZE] = {4,8,7,1,2,10};
    int s[SIZE];
    int maxVal = knapSack(w, v, s);
    printf("%d\n", maxVal);
    return 0;
}

int knapSack (int weights[], int values[] , int selected_bool[])
{
    int row = SIZE +1, col = CAPACITY + 1;
    int mat[row][col], i, j;
    for (i = 0; i < SIZE; i++)
    {
        selected_bool[i] = 0;
    }
    for (i = 0; i < col; i++)
    {
        mat[0][i] = 0;
    }
    for (i = 0; i < row; i++)
    {
        mat[i][0] = 0;
    }
    for (i = 1; i < row; i++)
    {
        for (j = 1; j < col; j++)
        {
            int iNotChosen = mat[i-1][j];
            int iIsChosen = (j - weights[i-1] >= 0) ? values[i-1] + mat[i-1][j - weights[i-1]] : 0;
            if (iIsChosen > iNotChosen)
            {
                mat[i][j] = iIsChosen;
            } else
            {
                mat[i][j] = iNotChosen;
            }
        }
    }
    int w = CAPACITY;
    for (i = SIZE; i > 0; i--)
    {
        int wasAdded = (mat[i][w] != mat[i-1][w]);
        if (wasAdded)
        {
            selected_bool[i-1] = 1;
            w = w - weights[i-1];
        }
    }
    printHelpMat(mat);
    printArr(selected_bool, SIZE);
    return mat[row-1][col-1];
}

void inputWeights(int weights[])
{
    int i;
    for (i=0;i < SIZE; i++)
    {
        scanf("%d", &weights[i]);
    }
}

void inputValues(int values[])
{
    int i;
    for (i=0;i < SIZE; i++)
    {
        scanf("%d", &values[i]);
    }
}

void printHelpMat(int mat[SIZE+1][CAPACITY+1])
{
    int i, j;
    for (i = 0; i<SIZE+1; i++)
    {
        printf("[");
        for (j = 0; j<CAPACITY+1; j++)
        {
            printf("%d, ", mat[i][j]);
        }
        printf("]\n");
    }
}

void printArr(int arr[], int length)
{
    printf("[");
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("]\n");
}