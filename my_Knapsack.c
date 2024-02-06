#include <stdio.h>

#define SIZE 5
#define CAPACITY 20

int knapSack();
void inputValues();
void inputWeights();
void inputItems();
void printHelpMat();
void printArr();
void printChosenItems();

int main()
{
    int weights[SIZE], values[SIZE], isChosen[SIZE];
    char items[SIZE];
    printf("Enter items (chars): ");
    inputItems(items);
    printf("Enter values: ");
    inputValues(values);
    printf("Enter wights: ");
    inputWeights(weights);
    int ans = knapSack(weights, values, isChosen);
    printf("The maximum aggregated value is: %d\n", ans);
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

void inputItems(char items[])
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        scanf(" %c", &items[i]);
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

void printChosenItems(char items[], int selected_bool[])
{
    int i;
    for (i = 0; i<SIZE; i++)
    {
        if (selected_bool[i])
        {
            printf("%c ", items[i]);
        }
    }
    printf("\n");
}