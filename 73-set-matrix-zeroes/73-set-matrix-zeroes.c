void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int row_clear = 0;
    int col_clear = 0;
    
    for (int j = 0; j < *matrixColSize; ++j) {
        if (matrix[0][j] == 0)
            col_clear = 1;
    }
    for (int i = 0; i < matrixSize; ++i) {
        if (matrix[i][0] == 0)
            row_clear = 1;
    }
    for (int j = 0; j < matrixSize; ++j) {
        for (int i = 0; i < *matrixColSize; ++i) {
            if (matrix[j][i] == 0)
            {
                matrix[j][0] = 0;
                matrix[0][i] = 0;
            }
        }
    }
    for (int i = 1; i < matrixSize; i++) {
        for (int j = 1; j < *matrixColSize; j++) {
            if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    if (col_clear) {
        for (int j = 0; j < *matrixColSize; ++j) {
            matrix[0][j] = 0;
        }
    }
    if (row_clear) {
        for (int i = 0; i < matrixSize; ++i) {
            matrix[i][0] = 0;
        }
    }
}