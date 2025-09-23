#include <stdio.h>

int main()
{
    int r, c, count = 0;
    printf("Enter the row and column: ");
    scanf("%d %d", &r, &c);

    int sprs[r][c];
    printf("Enter the elements: \n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &sprs[i][j]);
            if (sprs[i][j] != 0)
                count++;
        }
    }

    // Step 1: Convert to 3-tuple
    int trip[count + 1][3];
    trip[0][0] = r;
    trip[0][1] = c;
    trip[0][2] = count;

    int k = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (sprs[i][j] != 0)
            {
                trip[k][0] = i;
                trip[k][1] = j;
                trip[k][2] = sprs[i][j];
                k++;
            }
        }
    }

    printf("\n3-Tuple representation:\n");
    for (int i = 0; i <= count; i++)
        printf("%d %d %d\n", trip[i][0], trip[i][1], trip[i][2]);

    // Step 2: Transpose
    int transpose[count + 1][3];
    transpose[0][0] = c;
    transpose[0][1] = r;
    transpose[0][2] = count;

    k = 1;
    for (int i = 0; i < trip[0][1]; i++) // loop over columns
    {
        for (int j = 1; j <= trip[0][2]; j++) // loop over nonzero elements
        {
            if (trip[j][1] == i)
            {
                transpose[k][0] = trip[j][1];
                transpose[k][1] = trip[j][0];
                transpose[k][2] = trip[j][2];
                k++;
            }
        }
    }

    printf("\nTranspose in 3-Tuple representation:\n");
    for (int i = 0; i <= count; i++)
        printf("%d %d %d\n", transpose[i][0], transpose[i][1], transpose[i][2]);

    return 0;
}
