#include <stdio.h>
#include "my_mat.h"

int main()
{
    char option;
    int matrix[10][10];
    do {
    printf("Enter an option:");
    scanf(" %c", &option);
    switch (option)
    {
    case 'A':
        inputMat(matrix);
        break;
    case 'D':
        break;
    default:
        printf("You need to enter A/B/C/D!\n");
    } 
    } while (option != 'D');
    return 0;
}

