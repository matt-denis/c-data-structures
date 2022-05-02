#include<stdio.h>

void snake(int, int n, int[][n]);


int main()
{
    int matrix[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    snake(4, 4, matrix);
}

void snake(int m, int n, int matrix[][n])
{
    int col = -1;
    for (int row = 0; row < m; row++) {
        for (++col ; col < n; col++) {
            printf("%d ", matrix[row][col]);
        }
        if (++row >= m) break;
        for (--col ; col >= 0; col--) {
            printf("%d ", matrix[row][col]);
        }
    }
}