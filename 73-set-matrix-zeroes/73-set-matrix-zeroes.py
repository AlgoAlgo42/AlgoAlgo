class Solution:
    def setZeroes(self, matrix):
        # Frist Part: index of The Frist Value 0 in findIndex list
        findIndex = []
        for i, ivalue in enumerate (matrix):
            for j, jvalue in enumerate (ivalue):
                if jvalue == 0:
                    findIndex.append([i, j])
        # Second Part: change 1 to 0 in matrix
        m = len(matrix)
        n = len(matrix[0])
        for value in findIndex:
            x, y = value
            for row in range(m):
                for col in range(n):
                    if x == row:
                        matrix[row][col] = 0
                    if y == col:
                        matrix[row][col] = 0