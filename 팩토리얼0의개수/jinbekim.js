const input = require('fs')
	.readFileSync('/dev/stdin', 'utf8')
	.toString()
	.trim()
	.split('\n')
	.map(Number);

const N = input[0];

function init() {
	let result = 0;
	for (let i = 1; i <= N; i++) {
		let tmp = i;
		while (tmp % 5 === 0) {
			tmp /= 5;
			result += 1;
		}
	}
	console.log(result);
}

init();
