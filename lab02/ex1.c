#include <stdio.h>

#define MAX_SIZE 100

int printSmallestLine(int matrix[MAX_SIZE][MAX_SIZE], int size)
{
    int i, j, minElem = matrix[0][0], minIndex = 0;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (matrix[i][j] < minElem)
            {
                minElem = matrix[i][j];
                minIndex = i;
            }
        }
    }

    return minIndex + 1;
}

int main()
{
  int matrix[MAX_SIZE][MAX_SIZE];
  int size, i, j;

  printf("\nMatrix Order: ");
  scanf("%d", &size);

  printf("\nMatrix Elements:\n");
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
      {
        printf("Element a%d,%d: ", i, j);
        scanf("%d", &matrix[i][j]);
      }
  }

  printf("\nThe line containing the smallest element is the line: %d", printSmallestLine(matrix, size));

    return 0;
}
