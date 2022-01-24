class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m = len(matrix)
        n = len(matrix[0])
        row = set()
        col = set()
        for i in range(0, m):
            for j in range(0, n):
                if (matrix[i][j] == 0):
                    row.add(i)
                    col.add(j)

        row = list(row)
        col = list(col)
        for i in row:
            for j in range(0, n):
                matrix[i][j] = 0		
        for j in col:
            for i in range(0, m):
                matrix[i][j]  = 0
        return matrix