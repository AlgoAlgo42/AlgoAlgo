class Solution:
	grid: list[list[str]]
	m: int
	n: int

	def dfs(self, i, j):
		if i < 0 or i >= self.m or j < 0 or j >= self.n or self.grid[i][j] == "0":
			return
		
		self.grid[i][j] = "0"
		self.dfs(i, j+1)
		self.dfs(i+1, j)
		self.dfs(i, j-1)
		self.dfs(i-1, j)

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
    
    -------------------------------------------------------------------------------
    DFS에 익숙치 않아서 무작정 구현하려다 실패하여, 다른 분이 구현하신 것을 참고하여 풀었습니다.
    for문을 돌려 모든 값을 탐색하여 "1"을 발견했을 때 cnt를 증가시킵니다.
    그 후 그와 연결된 모든 "1"을 찾아서 0으로 바꾸고 계속해서 탐색하는 방식입니다.
