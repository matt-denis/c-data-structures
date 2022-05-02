#include <stdio.h>

/* Given an m x n matrix, print it's outer boundary */
void boundary(int, int n, int[][n]);

int main()
{
    int matrix[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    boundary(2, 5, matrix);

    return 0;
}

void boundary(int m, int n, int matrix[][n])
{
    int rowBound = m == 1 ? m : m - 1;
    int colBound = n == 1 ? 0 : 1;
    for (int col = 0; col < n - 1; col++) {
        printf("%d ", matrix[0][col]);
    }
    for (int row = 0; row < rowBound; row++) {
        printf("%d ", matrix[row][n - 1]);
    }
    if (m == 1) return;
    for (int col = n - 1; col >= colBound; col--) {
        printf("%d ", matrix[m - 1][col]);
    }
    if (n == 1) return;
    for (int row = m - 1; row > 0; row--) {
        printf("%d ", matrix[row][0]);
    }
}