#include <stdio.h>

void transpose(int m, int n, int[m][n], int[n][m]);
void transpose_square(int n, int[][n]);
void display(int m, int n, int[][n]);

int main()
{
    int matrix[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    transpose_square(3, matrix);
    display(3, 3, matrix);

    return 0;
}


void transpose(int m, int n, int matrix[m][n], int t[n][m])
{
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            t[col][row] = matrix[row][col];
        }
    }
}

void transpose_square(int n, int matrix[][n])
{
    for (int row = 0; row < n - 1; row++) {
        for (int col = row + 1; col < n; col++) {
            int tmp = matrix[row][col];
            matrix[row][col] = matrix[col][row];
            matrix[col][row] = tmp;
        }
    }
}

void display(int m, int n, int matrix[][n])
{
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }
}