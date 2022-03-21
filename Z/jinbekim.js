const input = require('fs')
	.readFileSync('/dev/stdin', 'utf8')
	.toString()
	.trim()
	.split(' ')
	.map(Number);

let [N, r, c] = input;

function isInRangePowerOf2(num) {
	let x = 0;
	while (num > Math.pow(2, x)) x++;
	return x;
}

function init() {
	if (N < 0 || N > 15) throw new Error('N is out of range');
	if (r < 0 || c < 0) throw new Error('r or c is negative');
	if (r > Math.pow(2, N) || c > Math.pow(2, N))
		throw new Error('r or c is out of range');
	r += 1;
	c += 1;
	let r_power = isInRangePowerOf2(r);
	let c_power = isInRangePowerOf2(c);
	let answer = 0;
	// console.log(r_power, c_power);
	while (r_power > 0) {
		answer += Math.pow(2, r_power - 1) * Math.pow(2, r_power - 1) * 2;
		r -= Math.pow(2, r_power - 1);
		r_power = isInRangePowerOf2(r);
		// console.log(r, r_power, 'p', answer);
	}
	while (c_power > 0) {
		answer += Math.pow(2, c_power - 1) * Math.pow(2, c_power - 1);
		c -= Math.pow(2, c_power - 1);
		c_power = isInRangePowerOf2(c);
		// console.log(c, c_power, 'c', answer);
	}
	console.log(answer);
}

init();
