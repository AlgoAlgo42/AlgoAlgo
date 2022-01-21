class Solution:
    grid: list[list[str]]
    m: int
    n: int

    def numIslands(self, grid: list[list[str]]) -> int:
        self.grid = grid
        self.m = len(grid)
        self.n = len(grid[0])
        cnt = 0

        for i in range(0, self.m):
            for j in range(0, self.n):
                if grid[i][j] == "1":
                    cnt += 1
                    self.dfs(i,j)
        return cnt

    def dfs(self, i, j):
        if i < 0 or i >= self.m or j < 0 or j >= self.n or self.grid[i][j] == "0":
            return

        self.grid[i][j] = "0"
        self.dfs(i, j+1)
        self.dfs(i+1, j)
        self.dfs(i, j-1)
        self.dfs(i-1, j)