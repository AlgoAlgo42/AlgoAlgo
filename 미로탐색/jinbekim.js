const input = require('fs')
	.readFileSync('/dev/stdin')
	.toString()
	.trim()
	.split('\n');

const [n, m] = input[0].split(' ').map(Number);
// const map = new Array(n).fill(0).map(() => new Array(m).fill(0));
const map = Array.from({ length: n }, (_, row) =>
	Array.from({ length: m }, (_, col) => (input[row + 1][col] === '1' ? 1 : 0))
);

function init() {
	const queue = [];
	const visited = Array.from({ length: n }, () =>
		Array.from({ length: m }, () => false)
	);
	const dx = [0, 0, 1, -1];
	const dy = [1, -1, 0, 0];
	queue.push([0, 0]);
	visited[0][0] = 1;
	while (queue.length) {
		const [x, y] = queue.shift();
		for (let i = 0; i < 4; i++) {
			const nx = x + dx[i];
			const ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] >= 1 && visited[nx][ny] === 0) {
				visited[nx][ny] = true;
				map[nx][ny] = map[x][y] + 1;
				queue.push([nx, ny]);
			}
		}
	}
	console.log(map[n - 1][m - 1]);
}

init();
