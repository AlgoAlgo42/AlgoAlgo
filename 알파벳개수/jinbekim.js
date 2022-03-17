let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim();

const alphaArr = new Array(26).fill(0);
const lowAAscii = 97;
for (let char of input) {
	const idx = char.charCodeAt(0) - lowAAscii;
	if (!alphaArr[idx]) {
		alphaArr[idx] = 1;
	} else {
		alphaArr[idx] += 1;
	}
}

console.log(...alphaArr);
