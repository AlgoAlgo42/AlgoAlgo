/**
 * @param {character[][]} grid
 * @return {number}
 */

const dfs = function (grid, i, j) {
	if (
		i < 0 ||
		j < 0 ||
		i > grid.length - 1 ||
		j > grid[0].length - 1 ||
		grid[i][j] === '0'
	) {
		return 0;
	}
	grid[i][j] = '0';
	dfs(grid, i - 1, j);
	dfs(grid, i + 1, j);
	dfs(grid, i, j - 1);
	dfs(grid, i, j + 1);
};

var numIslands = function (grid) {
	let islands = 0;

	const m = grid.length;
	grid.forEach((row, i) => {
		row.forEach((col, j) => {
			if (grid[i][j] === '1') {
				islands++;
				dfs(grid, i, j);
			}
		});
	});

	return islands;
};
