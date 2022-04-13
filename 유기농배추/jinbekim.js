const input = require('fs')
	.readFileSync('/dev/stdin')
	.toString()
	.trim()
	.split('\n');

const T = input[0];
const dx = [0, 0, 1, -1];
const dy = [1, -1, 0, 0];
let answer = '';

function init() {
	let cycle = 0;
	let offset = 1;
	while (cycle++ < T) {
		/**
		 * input setting
		 */
		const [M, N, k] = input[offset].split(' ').map(Number);
		const farm = Array.from({ length: N }, (v) => new Array(M).fill(false));
		for (let i = 1; i <= k; ++i) {
			const [x, y] = input[offset + i].split(' ').map(Number);
			farm[y][x] = true;
		}
		/**
		 * problem solving
		 */
		const visited = Array.from({ length: N }, (v) => new Array(M).fill(false));
		const stack = [];
		let count = 0;
		for (let i = 0; i < N; ++i) {
			for (let j = 0; j < M; ++j) {
				if (farm[i][j] && !visited[i][j]) stack.push([i, j]);
				else continue;
				count++;
				while (stack.length) {
					const [y, x] = stack.pop();
					for (let z = 0; z < 4; ++z) {
						const nx = x + dx[z];
						const ny = y + dy[z];
						if (
							ny >= 0 &&
							ny < N &&
							nx >= 0 &&
							nx < M &&
							!visited[ny][nx] &&
							farm[ny][nx]
						) {
							stack.push([ny, nx]);
							visited[ny][nx] = true;
						}
					}
				}
			}
		}
		answer += '\n' + count;
		offset += k + 1;
	}
}
init();
console.log(answer);
