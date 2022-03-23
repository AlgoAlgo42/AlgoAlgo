const input = require('fs')
	.readFileSync('/dev/stdin', 'utf8')
	// .readFileSync('./input.txt', 'utf8')
	.toString()
	.trim()
	.split('\n');

const [N, M] = input[0].split(' ').map(Number);
const map = new Array(N);
for (let i = 0; i < N; i++) {
	map[i] = input[i + 1].split('').map((val) => Number(val));
}

const init = function (N, M, map) {
	let maxSize = 1;
	debugger;
	map.forEach((row, rowIdx) => {
		if (rowIdx + maxSize > N) return false;
		row.forEach((col, colIdx) => {
			if (colIdx + maxSize > M) return false;
			for (let colIdx2 = M - 1; colIdx2 >= maxSize + colIdx; --colIdx2) {
				const sideLen = colIdx2 - colIdx;
				if (col !== row[colIdx2]) continue;
				if (rowIdx + sideLen >= N) continue;
				if (
					map[rowIdx + sideLen][colIdx] === col &&
					map[rowIdx + sideLen][colIdx2] === col
				) {
					maxSize = sideLen + 1;
					break;
				}
			}
		});
	});
	console.log(maxSize * maxSize);
};

init(N, M, map);
