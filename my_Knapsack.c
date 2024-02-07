#include <stdio.h>

#define SIZE 5
#define CAPACITY 20

int knapSack();
void inputValues();
void inputWeights();
void inputItems();
void printChosenItems();

int main()
{
    int weights[SIZE], values[SIZE], isChosen[SIZE], i;
    char items[SIZE];
    for (i = 0; i < SIZE; i++)
    {
        scanf(" %c", &items[i]);
        scanf("%d%d", &values[i], &weights[i]);
    }
    int mp = knapSack(weights, values, isChosen);
    printf("Maximum profit: %d\n", mp);
    printf("Selected items:");
    printChosenItems(items, isChosen);
    
    return 0;
}

int knapSack(int weights[], int values[] , int selected_bool[])
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

void inputItems(char items[])
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        scanf(" %c", &items[i]);
    }
}

void printChosenItems(char items[], int selected_bool[])
{
    int i;
    for (i = 0; i<SIZE; i++)
    {
        if (selected_bool[i])
        {
            printf(" %c", items[i]);
        }
    }
}