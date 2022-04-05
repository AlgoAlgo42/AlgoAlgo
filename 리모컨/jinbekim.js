const input = require('fs')
	.readFileSync('/dev/stdin', 'utf8')
	.toString()
	.trim()
	.split('\n');

const channelTo = +input[0];
let channelFrom = 100;
const brokenButtonCount = +input[1];
const workingButtons = [];
if (brokenButtonCount) {
	const brokenButtons = Array.from(input[2].split(' ')).map(Number);
	const tmp = new Array(10).fill(0).map((v, i) => i);
	tmp.forEach((val) => {
		if (!brokenButtons.includes(val)) {
			workingButtons.push(val);
		}
	});
}
answer = Math.abs(channelTo - channelFrom);

function init(tmpNumber, count) {
	if (count > 6) return;
	if (count) {
		answer = Math.min(answer, count + Math.abs(channelTo - tmpNumber));
	}
	workingButtons.forEach((val) => {
		init(tmpNumber * 10 + val, count + 1);
	});
}

init(0, 0);

console.log(answer);
