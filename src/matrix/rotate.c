#include <stdio.h>

/* rotate a given matrix by 90 degrees anti-clockwise */
void rotate(int n, int[][n]);
void rotate_transpose(int n, int[][n]);
void transpose_square(int n, int[][n]);
void reverse_col(int col, int n, int[][n]);
void display(int, int n, int[][n]);

int main()
{
    printf("\n");
    int matrix[5][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                        21, 22, 23, 24, 25};
    rotate(5, matrix);
    display(5, 5, matrix);
    printf("\n=================================\n=================================\n\n\n");
    int matrix2[5][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                        21, 22, 23, 24, 25};

    rotate_transpose(5, matrix2);
    display(5, 5, matrix2);

    return 0;
}

void rotate(int n, int matrix[][n])
{
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        for (int idx = lo; idx < hi; idx++) {
            int row = lo, col = idx;
            int nextElement = matrix[row][col];
            do {
                int nextRow = n - col - 1;
                int nextCol = row;
                int out = matrix[nextRow][nextCol];
                matrix[nextRow][nextCol] = nextElement;
                nextElement = out;
                row = nextRow;
                col = nextCol;

            } while (row != lo || col != idx);
        }
        lo++, hi--;
    }
}

void rotate_transpose(int n, int matrix[][n])
{
    transpose_square(n, matrix);
    for (int col = 0; col < n; col++) {
        reverse_col(col, n, matrix);
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

void reverse_col(int col, int n, int matrix[][n])
{
    for (int lo = 0, hi = n - 1; lo < hi; lo++, hi--) {
        int tmp = matrix[lo][col];
        matrix[lo][col] = matrix[hi][col];
        matrix[hi][col] = tmp;
    }
}

void display(int m, int n, int matrix[][n])
{
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            printf("%2d   ", matrix[row][col]);
        }
        printf("\n\n");
    }
}