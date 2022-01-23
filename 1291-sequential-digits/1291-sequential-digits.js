/**
 * @param {number} low
 * @param {number} high
 * @return {number[]}
 */


var sequentialDigits = function (low, high) {
	const base = '123456789';
	const result = [];

	for (let j = 0; j <= 9; ++j) {
		for (let i = 0; i <= 9-j; ++i) {
			const num = Number(base.slice(i, i + j));
			if (num >= low && num <= high) result.push(num);
		}
	}
	return result;
};