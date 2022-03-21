const input = require('fs')
	.readFileSync('/dev/stdin', 'utf8')
	.toString()
	.trim()
	.split(' ')
	.map(Number);

let [N, r, c] = input;

function init(N, r, c) {
	if (N < 1) return 0;
	const half = Math.pow(2, N - 1);
	let squares = (r >= half) * 2 + (c >= half) * 1;
	if (r >= half) r -= half;
	if (c >= half) c -= half;
	const result = half * half * squares;
	return result + init(N - 1, r, c);
}

console.log(init(N, r, c));
